##
## Copyright (C) 2004, 2003 Marcelo E. Magallon <mmagallo[at]debian org>
## Copyright (C) 2004, 2003 Milan Ikits <milan ikits[at]ieee org>
##
## This program is distributed under the terms and conditions of the GNU
## General Public License Version 2 as published by the Free Software
## Foundation or, at your option, any later version.

perl -e 's/#ifndef GLX_OML_sync_control/#if !defined(GLX_OML_sync_control) \&\& defined(__STDC_VERSION__) \&\& (__STDC_VERSION__ >= 199901L)\n#include <inttypes.h>/;' -pi $1
perl -e 's/#ifdef GLX_OML_sync_control/#if defined(GLX_OML_sync_control) \&\& defined(__STDC_VERSION__) \&\& (__STDC_VERSION__ >= 199901L)\n#include <inttypes.h>/;' -pi $1
perl -e 's/(GLEW_EXPORT PFNGLXGETMSCRATEOMLPROC __glewXGetMscRateOML;)/#ifdef GLX_OML_sync_control\n\1/' -pi $1
perl -e 's/(GLEW_EXPORT PFNGLXWAITFORSBCOMLPROC __glewXWaitForSbcOML;)/\1\n#endif/' -pi $1
perl -e 's/(GLEW_EXPORT GLboolean __GLXEW_OML_sync_control;)/#ifdef GLX_OML_sync_control\n\1\n#endif/' -pi $1
rm -f $1.bak
