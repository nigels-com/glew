#
# Copyright (C) 2003 Marcelo E. Magallon <mmagallo@debian.org>
# Copyright (C) 2003 Milan Ikits <milan.ikits@ieee.org>
#
# This program is distributed under the terms and conditions of the GNU
# General Public License Version 2 as published by the Free Software
# Foundation or, at your option, any later version.

sed -i -e 's/#ifndef GLX_OML_sync_control/#if !defined(GLX_OML_sync_control) \&\& defined(__STDC_VERSION__) \&\& (__STDC_VERSION__ >= 199901L)\n#include <inttypes.h>/' $1
sed -i -e 's/#ifdef GLX_OML_sync_control/#if defined(GLX_OML_sync_control) \&\& defined(__STDC_VERSION__) \&\& (__STDC_VERSION__ >= 199901L)\n#include <inttypes.h>/' $1
