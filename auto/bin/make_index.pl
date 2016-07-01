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

##
## Make Index
##
## Output sorted array of extension strings for indexing into extension
## enable/disable flags.  This provides a way to convert an extension string
## into an integer index.
##

my @extlist = ();

if (@ARGV)
{
	@extlist = @ARGV;

	foreach my $ext (sort @extlist)
	{
		my ($extname, $exturl, $extstring, $reuse, $types, $tokens, $functions, $exacts) = 
			parse_ext($ext);

		print "#ifdef $extname\n";
		print "  \"$extname\",\n";
		print "#endif\n";
	}
}
