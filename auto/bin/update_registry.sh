#!/bin/sh
##
## Copyright (C) 2004, 2003 Marcelo E. Magallon <mmagallo[at]debian org>
## Copyright (C) 2004, 2003 Milan Ikits <milan ikits[at]ieee org>
##
## This program is distributed under the terms and conditions of the GNU
## General Public License Version 2 as published by the Free Software
## Foundation or, at your option, any later version.

set -e

if [ ! -d $1 ] ; then
    mkdir $1
fi
cd $1

wget                                                    \
    --mirror                                            \
    --no-parent                                         \
    --no-host-directories                               \
    --cut-dirs=3                                        \
    --accept=txt,html                                   \
    $2

