#!/bin/bash
#
# Copyright (C) 2003 Marcelo E. Magallon <mmagallo@debian.org>
# Copyright (C) 2003 Milan Ikits <milan.ikits@ieee.org>
#
# This program is distributed under the terms and conditions of the GNU
# General Public License Version 2 as published by the Free Software
# Foundation or, at your option, any later version.

set -e

if [ ! -d $1 ] ; then
    mkdir $1
    find $2 -name doc -type d -prune -o -name \*.txt -print | \
	grep -v -f $3 | sort | bin/parse_spec.pl $1
# fix GL_NV_texture_compression_vtc
    grep -v EXT $1/GL_NV_texture_compression_vtc > tmp; \
	mv tmp $1/GL_NV_texture_compression_vtc
# remove duplicates from GL_ARB_vertex_program and GL_ARB_fragment_program
    grep -v -f $1/GL_ARB_vertex_program $1/GL_ARB_fragment_program > tmp; \
	mv tmp $1/GL_ARB_fragment_program
# remove duplicates from GLX_EXT_visual_rating and GLX_EXT_visual_info
    grep -v -f $1/GLX_EXT_visual_info $1/GLX_EXT_visual_rating > tmp; \
	mv tmp $1/GLX_EXT_visual_rating
# fix GL_NV_occlusion_query and GL_HP_occlusion_test
    grep -v '_HP' $1/GL_NV_occlusion_query > tmp; \
	mv tmp $1/GL_NV_occlusion_query
    sed -i -e's/OCCLUSION_TEST_HP.*/OCCLUSION_TEST_HP 0x8165/' \
	$1/GL_HP_occlusion_test
    sed -i -e's/OCCLUSION_TEST_RESULT_HP.*/OCCLUSION_TEST_RESULT_HP 0x8166/' \
	$1/GL_HP_occlusion_test
# fix WGL_ATI_pixel_format_float
    echo -e "\tGL_RGBA_FLOAT_MODE_ATI 0x8820" >> $1/WGL_ATI_pixel_format_float
    echo -e "\tGL_COLOR_CLEAR_UNCLAMPED_VALUE_ATI 0x8835" >> $1/WGL_ATI_pixel_format_float
# add typedefs to GL_ARB_vertex_buffer_object
    echo -e "\ttypedef int GLsizeiptrARB" >> $1/GL_ARB_vertex_buffer_object
    echo -e "\ttypedef int GLintptrARB" >> $1/GL_ARB_vertex_buffer_object
# add typedefs to GLX_EXT_import_context
    echo -e "\ttypedef XID GLXContextID" >> $1/GLX_EXT_import_context
# add tokens to GLX_OML_swap_method
    echo -e "\tGLX_SWAP_EXCHANGE_OML 0x8061" >> $1/GLX_OML_swap_method
    echo -e "\tGLX_SWAP_COPY_OML 0x8062" >> $1/GLX_OML_swap_method
    echo -e "\tGLX_SWAP_UNDEFINED_OML 0x8063" >> $1/GLX_OML_swap_method
# add typedefs to GLX_SGIX_fbconfig
    echo -e "\ttypedef XID GLXFBConfigIDSGIX" >> $1/GLX_SGIX_fbconfig
    echo -e "\ttypedef struct __GLXFBConfigRec *GLXFBConfigSGIX" >> $1/GLX_SGIX_fbconfig
# add typedefs to GLX_SGIX_pbuffer
    echo -e "\ttypedef XID GLXPbufferSGIX" >> $1/GLX_SGIX_pbuffer
    echo -e "\ttypedef struct { int type; unsigned long serial; Bool send_event; Display *display; GLXDrawable drawable; int event_type; int draw_type; unsigned int mask; int x, y; int width, height; int count; } GLXBufferClobberEventSGIX" >> $1/GLX_SGIX_pbuffer
# add typedef to GL_NV_half_float
    echo -e "\ttypedef unsigned short GLhalf" >> $1/GL_NV_half_float
# add handle to WGL_ARB_pbuffer
    echo -e "\tDECLARE_HANDLE(HPBUFFERARB);" >> $1/WGL_ARB_pbuffer
# add handle to WGL_EXT_pbuffer
    echo -e "\tDECLARE_HANDLE(HPBUFFEREXT);" >> $1/WGL_EXT_pbuffer
# get rid of GL_SUN_multi_draw_arrays
    rm -f $1/GL_SUN_multi_draw_arrays
fi
