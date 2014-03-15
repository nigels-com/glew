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
    our $type;
    my $parms = $_[1]->{parms};
    
    #trim off any whitespace
    $parms =~ s/^\s+|\s+$//g;
    
    #fix up parm identifiers for macro
    my $fixed_up_parms = "";
    my $fixed_up_calllist = "";
    
    #if the parm list is void, nothing to substitute
    if($parms ne "void")
    {
        #split parms
        my @split_parms = split(/,/,$parms);
       
        my $num_parms = @split_parms;
       
        my $i = 0;
       
        foreach(@split_parms)
        {
            my $temp = $_;
         
            #trim off any whitespace
            $temp =~ s/^\s+|\s+$//g;
         
            #get the parm name, store it, and strip it off
            my $parm_name = "";
            
            if($temp =~ /([a-zA-Z_]+[0-9a-zA-Z_]*)$/)
            {
                $parm_name = $1;
                $temp = substr($temp,0,length($temp) - length($parm_name));
            }
            
            #remove any remaining whitespace
            $temp =~ s/\s+//g;
            
            #replace pointer * with P
            $temp =~ s/\s*\*\s*/P/g;
            
            #remove brackets
            $temp =~ s/\[|\]//g;

            #add to parmlist...handling cases where no parm name is specified            
            if($parm_name eq "")
            {
                $fixed_up_calllist .= "(" . $temp . "__parm" . $i . ")";
                $fixed_up_parms .= $temp . "__parm" . $i;
            }
            elsif($temp eq "")
            {
                $fixed_up_calllist .= "(" . $parm_name . "__parm" . $i . ")";
                $fixed_up_parms .= $parm_name . "__parm" . $i;
            }
            else
            {
                $fixed_up_calllist .= "(" . $temp . "__" . $parm_name . ")";
                $fixed_up_parms .= $temp . "__" . $parm_name;
            }
            
            if($i != $num_parms - 1)
            {
                $fixed_up_parms .= ", ";
                $fixed_up_calllist .= ", ";
            }
            
            $i += 1;
        }
    }
    
    return join(" ", 
                #to get the function pointer for assignment/testing
                "#define", 
                $_[0] . "FP", 
                $type . "EW_GET_FUN(" . prefixname($_[0]) . ")",
                #to call the function naturally
                "\n#define", 
                $_[0] . "(" . $fixed_up_parms . ")", 
                $type . "EW_GET_FUN(" . prefixname($_[0]) . ")(" . $fixed_up_calllist . ")");
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
