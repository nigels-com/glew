#!/usr/bin/perl
##
## Copyright (C) 2004, 2003 Marcelo E. Magallon <mmagallo[at]debian org>
## Copyright (C) 2004, 2003 Milan Ikits <milan ikits[at]ieee org>
##
## This program is distributed under the terms and conditions of the GNU
## General Public License Version 2 as published by the Free Software
## Foundation or, at your option, any later version.

use strict;
use warnings;

do 'bin/make.pl';

# function pointer declaration
sub make_pfn_decl($%)
{
    return "GLEW_EXPORT PFN" . (uc $_[0]) . "PROC " . prefixname($_[0]) . ";";
}

my @extlist = ();
my %extensions = ();

our $type = shift;

if (@ARGV)
{
    @extlist = @ARGV;
} else {
    local $/;
    @extlist = split "\n", (<>);
}

print "/* ------------------------------------------------------------------------- */\n\n";
print "#ifdef GLEW_MX\n";
print "#define GLEW_EXPORT\n";
print "#else\n";
print "#define GLEW_EXPORT GLEWAPI\n";
print "#endif /* GLEW_MX */\n\n";
print "#if defined(GLEW_MX) && defined(_WIN32)\n";
print "struct " . $type . "EWContextStruct\n{\n";
print "#endif /* GLEW_MX */\n";

foreach my $ext (sort @extlist)
{
    my ($extname, $exturl, $types, $tokens, $functions, $exacts) = parse_ext($ext);
    output_decls($functions, \&make_pfn_decl);
}

print "\n#if defined(GLEW_MX) && !defined(_WIN32)\n";
print "struct " . $type . "EWContextStruct\n{\n";
print "#endif /* GLEW_MX */\n\n";

foreach my $ext (sort @extlist)
{
    my ($extname, $exturl, $types, $tokens, $functions, $exacts) = parse_ext($ext);
    my $extvar = $extname;
    $extvar =~ s/GL(X*)_/GL$1EW_/;
    print "GLEW_EXPORT GLboolean " . prefix_varname($extvar) . ";\n";
}

print "\n#ifdef GLEW_MX\n";
print "}; /* " . $type . "EWContextStruct */\n";
print "#endif /* GLEW_MX */\n\n";
