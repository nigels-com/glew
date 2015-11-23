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

my @extlist = ();
my %extensions = ();

our $type = shift;

if (@ARGV)
{
    @extlist = @ARGV;

    print "%struct-type\n";
    print "%compare-lengths\n";
    print "%define initializer-suffix ,NULL\n";
    print "%7bit\n";
    print "struct initflag { const char *name; GLboolean *flag; };\n";
    print "%%\n";

    foreach my $ext (sort @extlist)
    {
	my ($extname, $exturl, $extstring, $types, $tokens, $functions, $exacts) = parse_ext($ext);

	my $extvar = $extname;
	$extvar =~ s/GL(X*)_/GL$1EW_/;
	my $prefix = $extvar;
	$prefix =~ s/_.*//;
	print $extname . ", " . $prefix . "_GET_REF(__" . $extvar . ")\n";
    }
}
