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

my @extlist = ();
my %extensions = ();

our $export = shift;

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
    my $extvar = $extname;
    $extvar =~ s/GL(X*)_/GL$1EW_/;
    print $export . " GLboolean " . prefix_varname($extvar) . ";\n";
}
