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

my $curexttype = "";

foreach my $ext (sort @extlist)
{
	my ($extname, $exturl, $types, $tokens, $functions, $exacts) = parse_ext($ext);
	my $exttype = $extname;
	$exttype =~ s/(W*?)GL(X*?)_(.*?_)(.*)/$3/;
	my $extrem = $extname;
	$extrem =~ s/(W*?)GL(X*?)_(.*?_)(.*)/$4/;
    my $extvar = $extname;
    $extvar =~ s/(W*)GL(X*)_/$1GL$2EW_/;
	if(!($exttype =~ $curexttype))
	{
		if(length($curexttype) > 0)
		{
			print "    }\n";
		}
		print "    if (_glewStrSame2(&pos, &len, (const GLubyte*)\"$exttype\", " . length($exttype) . "))\n";
		print "    {\n";
		$curexttype = $exttype;
	}
	print "      if (_glewStrSame3(pos, len, (const GLubyte*)\"$extrem\", ". length($extrem) . "))\n";
	print "        return $extvar;\n";
}

print "    }\n";
