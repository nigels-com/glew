#!/usr/bin/perl
#
# Copyright (C) 2003 Marcelo E. Magallon <mmagallo@debian.org>
# Copyright (C) 2003 Milan Ikits <milan.ikits@ieee.org>
#
# This program is distributed under the terms and conditions of the GNU
# General Public License Version 2 as published by the Free Software
# Foundation or, at your option, any later version.

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
    return "typedef $_[1] $_[0];"
}

# function pointer type declaration
sub make_pfn_type($%)
{
    our $api;
    return join(' ', "typedef", $_[1]->{rtype},
        "($api * PFN" . (uc $_[0]) . "PROC)",
        "(" . $_[1]->{parms} . ")") . ";";
}

# function name alias
sub make_pfn_alias($%)
{
    return join(" ", "#define", $_[0], prefixname($_[0]))
}

# function pointer declaration
sub make_pfn_decl($%)
{
    return "GLEWAPI PFN" . (uc $_[0]) . "PROC " . prefixname($_[0]) . ";";
}

my @extlist = ();
my %extensions = ();

our $api = shift;

if (@ARGV)
{
    @extlist = @ARGV;
} else {
    local $/;
    @extlist = split "\n", (<>);
}

foreach my $ext (sort @extlist)
{
    my ($extname, $exturl, $types, $tokens, $functions, $exacts) = parse_ext($ext);

    make_separator($extname);
    print "#ifndef $extname\n#define $extname 1\n";
    output_tokens($tokens, \&make_define);
    output_types($types, \&make_type);
    output_exacts($exacts, \&make_exact);
    output_decls($functions, \&make_pfn_type);
    output_decls($functions, \&make_pfn_decl);
    output_decls($functions, \&make_pfn_alias);

    my $extvar = $extname;
    $extvar =~ s/GL(X*)_/GL$1EW_/;
    print "\nGLEWAPI GLboolean $extvar;\n\n";
    print "#endif /* $extname */\n\n";
}
