sed -i -e 's/#ifndef GLX_OML_sync_control/#if !defined(GLX_OML_sync_control) \&\& defined(__STDC_VERSION__) \&\& (__STDC_VERSION__ >= 199901L)\n#include <inttypes.h>/' $1
sed -i -e 's/#ifdef GLX_OML_sync_control/#if defined(GLX_OML_sync_control) \&\& defined(__STDC_VERSION__) \&\& (__STDC_VERSION__ >= 199901L)\n#include <inttypes.h>/' $1
