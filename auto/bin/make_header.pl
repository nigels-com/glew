#!/usr/bin/perl
##
## Copyright (C) 2002-2008, Marcelo E. Magallon <mmagallo[]debian org>
## Copyright (C) 2002-2008, Milan Ikits <milan ikits[]ieee org>
##
## This program is distributed under the terms and conditions of the GNU
## General Public License Version 2 as published by the Free Software
## Foundation or, at your option, any later version.

use strict;
use warnings;

do 'bin/make.pl';

# token
sub make_define($$)
{
    return "#define $_[0] $_[1]"
}

# type declaration
sub make_type($$)
{
    return "@_;"
}

sub make_condition($)
{
    my $condition = "";
    my $needop = 0;

    for my $tok (split(/\s+/, $_[0])) {
	if ($tok eq "~") {
	    # ignore
	} elsif ($tok eq '&&') {
	    $condition .= ' && ';
	    $needop = 0;
	} elsif ($tok eq '||') {
	    $condition .= ") || (";
	    $needop = 0;
	} else {
	    if ($needop) {
		$condition .= ' && ';
	    }
	    if ($tok =~ /^\d/) {
		# GL Version
		$tok =~ s/[.]/_/g;
		$condition .= "GL_VERSION_${tok}";
	    } elsif ($tok eq "core") {
		$condition .= " 0 ";
	    } elsif ($tok eq "forward") {
		$condition .= " 0 ";
	    }
	    $needop = 1;
	}
    }

    # optimize expression
    $condition = "(" . $condition . ")";
    $condition =~ s/[(][^)]* 0 [^)]*[)]/ 0 /g;
    $condition =~ s/\|\|\s*0\s*//g;
    $condition =~ s/\s*0\s*\|\|//g;
    $condition =~ s/\s+0\s+/ 0 /g;

    if ($condition eq " 0 ") {
	return "1";
    } else {
	return "!($condition)";
    }
}

# function pointer type declaration
sub make_pfn_type($%)
{
    our $api;
    my $prefix = "";
    my $suffix = "";

    if ($_[1]->{deleted})
    {
	$prefix = "#if " . make_condition($_[1]->{deleted}) . "\n";
	if ($prefix eq "#if 1\n") {
	    $prefix = ""; # if optimized away
	} else {
	    $suffix = "\n#endif";
	}
    }
    return $prefix . join(' ', "typedef", $_[1]->{rtype},
        "($api * PFN" . (uc $_[0]) . "PROC)",
        "(" . $_[1]->{parms} . ")") . ";" . $suffix;
}

# function name alias
sub make_pfn_alias($%)
{
    our $type;
    my $prefix = "";
    my $suffix = "";

    if ($_[1]->{deleted})
    {
	$prefix = "#if " . make_condition($_[1]->{deleted}) . "\n";
	if ($prefix eq "#if 1\n") {
	    $prefix = ""; # if optimized away
	} else {
	    $suffix = "\n#endif";
	}
    }
    return $prefix . join(" ", "#define", $_[0], $type . "EW_GET_FUN(" . prefixname($_[0]) . ")") . $suffix;
}

my @extlist = ();
my %extensions = ();

our $api = shift;
our $type = shift;

if (@ARGV)
{
    @extlist = @ARGV;

	foreach my $ext (sort @extlist)
	{
		my ($extname, $exturl, $extstring, $types, $tokens, $functions, $exacts) = parse_ext($ext);

		make_separator($extname);
		print "#ifndef $extname\n#define $extname 1\n";
		output_tokens($tokens, \&make_define);
		output_types($types, \&make_type);
		output_exacts($exacts, \&make_exact);
		output_decls($functions, \&make_pfn_type);
		output_decls($functions, \&make_pfn_alias);

		my $extvar = $extname;
		$extvar =~ s/GL(X*)_/GL$1EW_/;
		
		print "\n#define $extvar " . $type . "EW_GET_VAR(" . prefix_varname($extvar) . ")\n";
		print "\n#endif /* $extname */\n\n";
	}
}
