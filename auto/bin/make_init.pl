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

#-------------------------------------------------------------------------------

# function pointer definition
sub make_pfn_def_init($%)
{
    #my $name = prefixname($_[0]);
    my $condition = "";
    if ($_[1]{deleted}) {
	my $needop = 0;

	for my $tok (split(/\s+/, $_[1]{deleted})) {
	    if ($tok eq "~") {
		# ignore
	    } elsif ($tok eq '&&') {
		$condition .= ' && ';
		$needop = 0;
	    } elsif ($tok eq '||') {
		$condition .= ') || (';
		$needop = 0;
	    } else {
		if ($needop) {
		    $condition .= ' && ';
		}
		if ($tok =~ /^!/) {
		    $condition .= '!';
		    $tok =~ s/^!//;
		}
		if ($tok =~ /^\d/) {
		    # GL Version
		    $tok =~ s/[.]/_/g;
		    $condition .= "GLEW_VERSION_${tok}";
		} elsif ($tok eq "core") {
		    $condition .= "(context_profile & GL_CONTEXT_CORE_PROFILE_BIT)";
		} elsif ($tok eq "forward") {
		    $condition .= "(context_flags & GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT)";
		}
		$needop = 1;
	    }
	}
	$condition = "if( !(($condition)) ) ";
    }
    return "  ${condition}r = ((" . $_[0] . " = (PFN" . (uc $_[0]) . "PROC)glewGetProcAddress((const GLubyte*)\"" . $_[0] . "\")) == NULL) || r;";
}

#-------------------------------------------------------------------------------

my @extlist = ();
my %extensions = ();

our $type = shift;

if (@ARGV)
{
    @extlist = @ARGV;

	foreach my $ext (sort @extlist)
	{
		my ($extname, $exturl, $extstring, $types, $tokens, $functions, $exacts) = 
			parse_ext($ext);

		#make_separator($extname);
		my $extvar = $extname;
		my $extvardef = $extname;
		$extvar =~ s/GL(X*)_/GL$1EW_/;
		if (keys %$functions)
		{
			print "#ifdef $extname\n\n";
			print "static GLboolean _glewInit_$extname (" . $type . 
				"EW_CONTEXT_ARG_DEF_INIT)\n{\n  GLboolean r = GL_FALSE;\n";
			print "#ifdef GLEW_MX\n  (void)ctx;\n#endif\n  (void)context_profile;\n  (void)context_flags;\n";
			output_decls($functions, \&make_pfn_def_init);
			print "\n  return r;\n}\n\n";
			print "#endif /* $extname */\n\n";
		}
	}
}
