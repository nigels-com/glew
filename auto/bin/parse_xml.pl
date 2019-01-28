#!/usr/bin/perl

use strict;
use XML::LibXML;

sub findChildren
{
	my @result = ();

	my $len = @{$_[1]};
	my $nodeName = ${$_[1]}[0];

	if (1 == $len)
	{
		foreach my $i ($_[0]->getChildNodes())
		{
			if (XML_ELEMENT_NODE == $i->nodeType())
			{
				if ($nodeName eq $i->nodeName())
				{
					push @result, $i;
				}
			}
		}
	}
	else
	{
		$len--;
		my @sub_path = @{$_[1]}[1..$len];

		foreach my $i ($_[0]->getChildNodes())
		{
			if (XML_ELEMENT_NODE == $i->nodeType())
			{
				if ($nodeName eq $i->nodeName())
				{
					my @sub_result = findChildren($i, \@sub_path);
					my $pos = @result;
					splice @result, $pos, 0, @sub_result;
				}
			}
		}
	}
	return @result;
}

sub findData
{
	my @result = ();
	my @nodes = findChildren($_[0], \@{$_[1]});

	foreach my $i (@nodes)
	{
		push @result, $i->textContent();
	}

	return @result;
}

sub findParams
{
	my @name = ('name');
	my @nodes = findData($_[0], \@name);

	my $n = $nodes[0];
	my $t = '';

	foreach my $i ($_[0]->getChildNodes())
	{
		if (XML_TEXT_NODE == $i->nodeType())
		{
			$t .= $i->textContent();
		}

		if ((XML_ELEMENT_NODE == $i->nodeType()) and ('ptype' eq $i->nodeName()))
		{
			$t .= $i->firstChild()->textContent();
		}
	}

	my %ret = ();
	$ret{$t} = $n;
	return %ret;
}

sub findEnums
{
	my @enum = ('registry', 'enums', 'enum');
	my @nodes = findChildren($_[0], \@enum);
	my %ret = ();

	foreach my $i (@nodes)
	{
		my $n = $i->getAttribute('name');
		my $v = $i->getAttribute('value');
		$ret{$n} = $v;
	}

	return %ret;
}

sub findCommands
{
	my @command = ('registry', 'commands', 'command');
	my @proto = ('proto');
	my @param = ('param');
	my @nodes = findChildren($_[0], \@command);
	my %ret = ();

	foreach my $i (@nodes)
	{
		my @sub_nodes = findChildren($i, \@proto);
		my %r_n = findParams($sub_nodes[0]);

		my @p = ();
		@sub_nodes = findChildren($i, \@param);

		foreach my $j (@sub_nodes)
		{
			my %params = findParams($j);
			push @p, \%params;
		}

		@sub_nodes = keys %r_n;
		my $r = $sub_nodes[0];

		@sub_nodes = values %r_n;
		my $n = $sub_nodes[0];

		$ret{$n} = {$r, \@p};
	}

	return %ret;
}

sub findFeaturesExtensions
{
	my @enum = ('require', 'enum');
	my @command = ('require', 'command');
	my @nodes = findChildren($_[0], \@{$_[1]});
	my %ret = ();

	foreach my $i (@nodes)
	{
		my $n = $i->getAttribute('name');
		my @e = ();
		my @c = ();

		my @sub_nodes = findChildren($i, \@enum);

		foreach my $j (@sub_nodes)
		{
			my $value = $j->getAttribute('name');
			push @e, $value;
		}

		@sub_nodes = findChildren($i, \@command);

		foreach my $j (@sub_nodes)
		{
			my $value = $j->getAttribute('name');
			push @c, $value;
		}

		my @sub_ret = (\@e, \@c);
		$ret{$n} = \@sub_ret;
	}

	return %ret;
}

sub findFeatures
{
	my @feature = ('registry', 'feature');
	return findFeaturesExtensions($_[0], \@feature);
}

sub findExtensions
{
	my @extension = ('registry', 'extensions', 'extension');
	return findFeaturesExtensions($_[0], \@extension);
}

sub findApi
{
	my $dom = $_[0];
	my %enums = findEnums($dom);
	my %commands = findCommands($dom);
	my %features = findFeatures($dom);
	my %extensions = findExtensions($dom);

	return (\%enums, \%commands, \%features, \%extensions);
}

sub writeExtension
{
	my $f = $_[0];
	my $name = $_[1];
	my @extensions = @{$_[2]};
	my %enums = %{$_[3]};
	my %commands = %{$_[4]};

	print {$f} "$name\n";
	print {$f} "https://www.khronos.org/registry/egl/specs/eglspec.1.5.pdf\n";

	if ($name =~ m/_VERSION_/)
	{
		print {$f} "\n";
	}
	else
	{
		print {$f} "$name\n";
	}

	print {$f} "\n";
	my %enums_ = ();

	foreach my $j (@extensions)
	{
		my @arr = @{$j};
		my $j_ = $arr[0];
		@arr = @{$j_};

		foreach my $j__ (@arr)
		{
			my $enum = $enums{$j__};
			$enums_{$j__} = $enum;
		}
	}

	my %added_enums_ = ();

	foreach my $j (sort values %enums_)
	{
		my $v = $enums_{$j};

		foreach my $j_ (keys %enums_)
		{
			if ((not $added_enums_{$j_}) and ($j eq $enums{$j_}))
			{
				$added_enums_{$j_} = $j;
				print {$f} "\t$j_ $j\n";
			}
		}
	}

	my %commands_ = ();

	foreach my $j (@extensions)
	{
		my @arr = @{$j};
		my $j_ = $arr[1];
		@arr = @{$j_};

		foreach my $j__ (@arr)
		{
			my $command = $commands{$j__};
			$commands_{$j__} = $command;
		}
	}

	foreach my $j (sort keys %commands_)
	{
		my $value = $commands_{$j};
		my %value_ = %{$value};
		my @return_value = keys %value_;
		my $return_value_ = $return_value[0];

		my @params = values %value_;
		my $params_ = $params[0];
		my @params__ = @{$params_};

		my $str_params = '';

		foreach my $j_ (@params__)
		{
			my @types = keys %{$j_};
			my @names = values %{$j_};

			my $type = $types[0];
			my $name = $names[0];

			$str_params .= $type . ' ' . $name . ', ';
		}

		if (0 == length($str_params))
		{
			$str_params = ' void ';
		}
		else
		{
			$str_params = substr($str_params, 0, -2);
		}

		my $full_command = "\t$return_value_ $j ($str_params)\n";
		print ${f} "$full_command";
	}

	return 1;
}

if (@ARGV)
{
	my $filename = '';
	my $options_core = '';
	my $options_extensions = '';
	my $fill_core = 0;
	my $fill_extensions = 0;

	foreach my $argument (@ARGV)
	{
		if ($argument =~  m/^--core/)
		{
			$fill_core = 1;
		}
		elsif ($argument =~  m/^--extensions/)
		{
			$fill_extensions = 1;
		}
		elsif (0 == length($options_core) and 0 != $fill_core)
		{
			$options_core = $argument;
			$fill_core = 0;
		}
		elsif (0 == length($options_extensions) and 0 != $fill_extensions)
		{
			$options_extensions = $argument;
			$fill_extensions = 0;
		}
		elsif (0 == length($filename))
		{
			$filename = $argument;
		}
	}

	my $dom = XML::LibXML->load_xml(location => $filename);
	my @api = findApi($dom);

	my $enums_count = keys %{$api[0]};
	my $commands_count = keys %{$api[1]};
	my $features_count = keys %{$api[2]};
	my $extensions_count = keys %{$api[3]};

	print("Found $enums_count enums, $commands_count commands, $features_count features and $extensions_count extensions.\n");

	my %enums = %{$api[0]};
	my %commands = %{$api[1]};

	if (0 != length($options_core))
	{
		foreach my $feature (sort keys %{$api[2]})
		{
			my %values_ = %{$api[2]};
			my @values__ = $values_{$feature};
			my $file_path = $options_core . '/' . $feature;
			open(my $f, '>', $file_path); # or continue;
			writeExtension($f, $feature, \@values__, \%enums, \%commands);
			close($f);
			# print("$file_path\n");
		}
	}

	if (0 != length($options_extensions))
	{
		foreach my $ext (sort keys %{$api[3]})
		{
			my %values_ = %{$api[3]};
			my @values__ = $values_{$ext};
			my $file_path = $options_extensions . '/' . $ext;
			open(my $f, '>', $file_path); # or continue;
			writeExtension($f, $ext, \@values__, \%enums, \%commands);
			close($f);
			# print("$file_path\n");
		}
	}
}
