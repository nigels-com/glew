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

#---------------------------------------------------------------------------------------

my @extlist = ();
my %extensions = ();
my $group = "";
my $cur_group = "";

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
    $cur_group = $extname;
    $cur_group =~ s/^(?:W?)GL(?:X?)_([A-Z0-9]+?)_.*$/$1/;
    $extname =~ s/^(?:W?)GL(?:X?)_(.*)$/$1/;
    if ($cur_group ne $group)
    {
	$group = $cur_group;
	print "<br>\n";
    }
    if ($exturl)
    {
	print "<a href=\"$exturl\">$extname</a><br>\n";
    }
    else
    {
	print "$extname<br>\n";
    }
}
