## Copyright (C) 2004, 2003 Marcelo E. Magallon <mmagallo[at]debian org>
## Copyright (C) 2004, 2003 Milan Ikits <milan ikits[at]ieee org>
##
## This program is distributed under the terms and conditions of the GNU
## General Public License Version 2 as published by the Free Software
## Foundation or, at your option, any later version.

GLEW_MAJOR = 1
GLEW_MINOR = 3
GLEW_MICRO = 0
GLEW_VERSION = $(GLEW_MAJOR).$(GLEW_MINOR).$(GLEW_MICRO)

SHELL = bash
REGISTRY = registry
REGISTRY_URL = http://oss.sgi.com/projects/ogl-sample/registry/
BIN = bin
SRC = src
CORE = core
EXT = extensions
BLACKLIST = blacklist

GL_CORE_SPEC := $(CORE)/GL_VERSION*
GLX_CORE_SPEC := $(CORE)/GLX_VERSION*
ifeq (custom,$(MAKECMDGOALS))
#GL_CORE_SPEC := $(shell grep GL_VERSION custom.txt | sed -e 's/\(.*\)/$(CORE)\/\1/g;')
GL_EXT_SPEC := $(shell grep "^[ \t]*GL_" custom.txt | grep -v GL_VERSION | sed -e 's/\(.*\)/$(EXT)\/\1/g;')
WGL_EXT_SPEC := $(shell grep "^[ \t]*WGL_" custom.txt | sed -e 's/\(.*\)/$(EXT)\/\1/g;')
#GLX_CORE_SPEC := $(shell grep GLX_VERSION custom.txt | sed -e 's/\(.*\)/$(CORE)\/\1/g;')
GLX_EXT_SPEC := $(shell grep "^[ \t]*GLX_" custom.txt | grep -v GLX_VERSION | sed -e 's/\(.*\)/$(EXT)\/\1/g;')
else
GL_EXT_SPEC := $(EXT)/GL_*
WGL_EXT_SPEC := $(EXT)/WGL_*
GLX_EXT_SPEC := $(EXT)/GLX_*
endif

PARSE_SPEC = parse_spec.pl
SYSTEM = $(strip $(shell uname -s))

TOP = ..
I.DEST = $(TOP)/include/GL
S.DEST = $(TOP)/src
D.DEST = $(TOP)/doc

TARGETS = $(I.DEST)/glew.h $(I.DEST)/wglew.h $(I.DEST)/glxew.h $(S.DEST)/glew_gl.c $(S.DEST)/glew_str.c $(S.DEST)/glew_wgl.c $(S.DEST)/glew_glx.c $(S.DEST)/glewinfo.c \
	$(D.DEST)/glew.html $(D.DEST)/wglew.html $(D.DEST)/glxew.html

all custom: $(TARGETS)

registry: $(REGISTRY)/.dummy
ext: $(EXT)/.dummy

$(REGISTRY)/.dummy: $(BIN)/update_registry.sh
	$(BIN)/update_registry.sh $(REGISTRY) $(REGISTRY_URL)
	head -6 $(REGISTRY)/ATI/texture_env_combine3.txt > tmp
	tail +7 $(REGISTRY)/ATI/texture_env_combine3.txt | \
	perl -e 's/ATI\_/GL\_ATI\_/g;' -p >> tmp
	mv -f tmp $(REGISTRY)/ATI/texture_env_combine3.txt
	touch $@

$(EXT)/.dummy: $(REGISTRY)/.dummy
	rm -rf $(EXT)
	$(BIN)/update_ext.sh $(EXT) $(REGISTRY) $(BLACKLIST)
ifeq ($(patsubst Darwin%,Darwin,$(SYSTEM)), Darwin)
	find $(CORE) -maxdepth 1 -type f | grep -v VERSION | grep -v "~" | \
	xargs -J % cp % $(EXT)
else
	find $(CORE) -maxdepth 1 -type f | grep -v VERSION | grep -v "~" | \
	xargs cp --target-directory=$(EXT)
endif
	touch $@

$(I.DEST)/glew.h: $(EXT)/.dummy
	test -d $(I.DEST) || mkdir -p $(I.DEST)
	cp -f $(SRC)/glew_head.h $@
	$(BIN)/make_header.pl GLAPIENTRY GL $(GL_CORE_SPEC) >> $@
	$(BIN)/make_header.pl GLAPIENTRY GL $(GL_EXT_SPEC) >> $@
	echo -e "/* ------------------------------------------------------------------------- */\n\n#if defined(GLEW_MX) && defined(_WIN32)\n#define GLEW_FUN_EXPORT\n#else\n#define GLEW_FUN_EXPORT GLEWAPI\n#endif /* GLEW_MX */\n" >> $@
	echo -e "#if defined(GLEW_MX)\n#define GLEW_VAR_EXPORT\n#else\n#define GLEW_VAR_EXPORT GLEWAPI\n#endif /* GLEW_MX */\n" >> $@
	echo -e "#if defined(GLEW_MX) && defined(_WIN32)\nstruct GLEWContextStruct\n{\n#endif /* GLEW_MX */" >> $@
	$(BIN)/make_struct_fun.pl GLEW_FUN_EXPORT $(GL_CORE_SPEC) $(GL_EXT_SPEC) >> $@
	echo -e "\n#if defined(GLEW_MX) && !defined(_WIN32)\nstruct GLEWContextStruct\n{\n#endif /* GLEW_MX */\n" >> $@
	$(BIN)/make_struct_var.pl GLEW_VAR_EXPORT $(GL_CORE_SPEC) $(GL_EXT_SPEC) >> $@
	echo -e "\n#ifdef GLEW_MX\n}; /* GLEWContextStruct */\n#endif /* GLEW_MX */\n" >> $@
	perl -e 's/GLEW_VAR_EXPORT GLboolean __GLEW_VERSION_1_2;/GLEW_VAR_EXPORT GLboolean __GLEW_VERSION_1_1;\nGLEW_VAR_EXPORT GLboolean __GLEW_VERSION_1_2;/' -pi $@
	rm -f $@.bak
	cat $(SRC)/glew_tail.h >> $@

$(I.DEST)/wglew.h: $(EXT)/.dummy
	cp -f $(SRC)/wglew_head.h $@
	$(BIN)/make_header.pl WINAPI WGL $(WGL_EXT_SPEC) >> $@
	echo -e "/* ------------------------------------------------------------------------- */\n\n#ifdef GLEW_MX\n#define WGLEW_EXPORT\n#else\n#define WGLEW_EXPORT GLEWAPI\n#endif /* GLEW_MX */\n\n#ifdef GLEW_MX\nstruct WGLEWContextStruct\n{\n#endif /* GLEW_MX */" >> $@
	$(BIN)/make_struct_fun.pl WGLEW_EXPORT $(WGL_EXT_SPEC) >> $@
	$(BIN)/make_struct_var.pl WGLEW_EXPORT $(WGL_EXT_SPEC) >> $@
	echo -e "\n#ifdef GLEW_MX\n}; /* WGLEWContextStruct */\n#endif /* GLEW_MX */\n" >> $@
	cat $(SRC)/wglew_tail.h >> $@

$(I.DEST)/glxew.h: $(EXT)/.dummy
	cp -f $(SRC)/glxew_head.h $@
	$(BIN)/make_header.pl '' GLX $(GLX_CORE_SPEC) >> $@
	$(BIN)/make_header.pl '' GLX $(GLX_EXT_SPEC) >> $@
	echo -e "/* ------------------------------------------------------------------------- */\n\n#ifdef GLEW_MX\n#define GLXEW_EXPORT\n#else\n#define GLXEW_EXPORT extern\n#endif /* GLEW_MX */" >> $@
	$(BIN)/make_struct_fun.pl extern $(GLX_CORE_SPEC) $(GLX_EXT_SPEC) >> $@
	echo -e "\n#if defined(GLEW_MX)\nstruct GLXEWContextStruct\n{\n#endif /* GLEW_MX */\n" >> $@
	$(BIN)/make_struct_var.pl GLXEW_EXPORT $(GLX_CORE_SPEC) $(GLX_EXT_SPEC) >> $@
	echo -e "\n#ifdef GLEW_MX\n}; /* GLXEWContextStruct */\n#endif /* GLEW_MX */\n" >> $@
	perl -e 's/GLXEW_EXPORT GLboolean __GLXEW_VERSION_1_2;/GLXEW_EXPORT GLboolean __GLXEW_VERSION_1_0;\nGLXEW_EXPORT GLboolean __GLXEW_VERSION_1_1;\nGLXEW_EXPORT GLboolean __GLXEW_VERSION_1_2;/' -pi $@
	cat $(SRC)/glxew_tail.h >> $@
	$(BIN)/fix_OML_sync_control.sh $@

$(S.DEST)/glew_gl.c: $(EXT)/.dummy
	cp -f $(SRC)/glew_gl_head.c $@
	$(BIN)/make_def_fun.pl GL $(GL_CORE_SPEC) >> $@
	$(BIN)/make_def_fun.pl GL $(GL_EXT_SPEC) >> $@
	cat $(SRC)/glew_gl_fun.c >> $@
	$(BIN)/make_def_var.pl GL $(GL_CORE_SPEC) >> $@
	$(BIN)/make_def_var.pl GL $(GL_EXT_SPEC) >> $@
	cat $(SRC)/glew_gl_var.c >> $@
	$(BIN)/make_init.pl GL $(GL_CORE_SPEC) >> $@
	$(BIN)/make_init.pl GL $(GL_EXT_SPEC) >> $@
	cat $(SRC)/glew_gl_init.c >> $@
	$(BIN)/make_list.pl $(GL_CORE_SPEC) | grep -v '\"GL_VERSION' >> $@
	$(BIN)/make_list.pl $(GL_EXT_SPEC) >> $@
	cat $(SRC)/glew_gl_tail.c >> $@
	perl -e "s/GLEW_VERSION_STRING/$(GLEW_MAJOR)\.$(GLEW_MINOR)\.$(GLEW_MICRO)/g" -pi $@
	perl -e "s/GLEW_ARB_vertex_shader = !_glewInit_GL_ARB_vertex_shader\(GLEW_CONTEXT_ARG_VAR_INIT\);/{ GLEW_ARB_vertex_shader = !_glewInit_GL_ARB_vertex_shader(GLEW_CONTEXT_ARG_VAR_INIT); _glewInit_GL_ARB_vertex_program(GLEW_CONTEXT_ARG_VAR_INIT); }/g" -pi $@
	rm -f $@.bak

$(S.DEST)/glew_wgl.c: $(EXT)/.dummy
	cp -f $(SRC)/glew_wgl_head.c $@
	$(BIN)/make_def_fun.pl WGL $(WGL_EXT_SPEC) >> $@
	$(BIN)/make_def_var.pl WGL $(WGL_EXT_SPEC) >> $@
	cat $(SRC)/glew_wgl_var.c >> $@
	$(BIN)/make_init.pl WGL $(WGL_EXT_SPEC) >> $@
	cat $(SRC)/glew_wgl_init.c >> $@
	$(BIN)/make_list.pl $(WGL_EXT_SPEC) >> $@
	cat $(SRC)/glew_wgl_tail.c >> $@
	rm -f $@.bak

$(S.DEST)/glew_glx.c: $(EXT)/.dummy
	cp -f $(SRC)/glew_glx_head.c $@
	$(BIN)/make_def_fun.pl GLX $(GLX_CORE_SPEC) >> $@
	$(BIN)/make_def_fun.pl GLX $(GLX_EXT_SPEC) >> $@
	cat $(SRC)/glew_glx_fun.c >> $@
	$(BIN)/make_def_var.pl GLX $(GLX_CORE_SPEC) >> $@
	$(BIN)/make_def_var.pl GLX $(GLX_EXT_SPEC) >> $@
	cat $(SRC)/glew_glx_var.c >> $@
	$(BIN)/make_init.pl GLX $(GLX_CORE_SPEC) >> $@
	$(BIN)/make_init.pl GLX $(GLX_EXT_SPEC) >> $@
	cat $(SRC)/glew_glx_init.c >> $@
	$(BIN)/make_list.pl $(CORE)/GLX_VERSION_1_3 | grep -v '\"GLX_VERSION' >> $@
	$(BIN)/make_list.pl $(GLX_EXT_SPEC) >> $@
	cat $(SRC)/glew_glx_tail.c >> $@
	$(BIN)/fix_OML_sync_control.sh $@
	rm -f $@.bak

$(S.DEST)/glew_str.c: $(EXT)/.dummy
	cp -f $(SRC)/glew_str_head.c $@
	$(BIN)/make_str.pl $(GL_CORE_SPEC) $(GL_EXT_SPEC) >> $@
	cat $(SRC)/glew_str_wgl.c >> $@
	$(BIN)/make_str.pl $(WGL_EXT_SPEC) >> $@
	cat $(SRC)/glew_str_glx.c >> $@
	$(BIN)/make_str.pl $(GLX_CORE_SPEC) $(GLX_EXT_SPEC) >> $@
	cat $(SRC)/glew_str_tail.c >> $@
#	$(BIN)/fix_OML_sync_control.sh $@
#	perl -e "s/GLEW_VERSION_STRING/$(GLEW_MAJOR)\.$(GLEW_MINOR)\.$(GLEW_MICRO)/g" -pi $@
#	perl -e "s/GLEW_ARB_vertex_shader = !_glewInit_GL_ARB_vertex_shader\(GLEW_CONTEXT_ARG_VAR_INIT\);/{ GLEW_ARB_vertex_shader = !_glewInit_GL_ARB_vertex_shader(GLEW_CONTEXT_ARG_VAR_INIT); _glewInit_GL_ARB_vertex_program(GLEW_CONTEXT_ARG_VAR_INIT); }/g" -pi $@
	rm -f $@.bak


$(S.DEST)/glewinfo.c: $(EXT)/.dummy
	cp -f $(SRC)/glewinfo_head.c $@
	$(BIN)/make_info.pl $(GL_CORE_SPEC) >> $@
	$(BIN)/make_info.pl $(GL_EXT_SPEC) >> $@
	echo -e "#ifdef _WIN32\n" >> $@
	$(BIN)/make_info.pl $(WGL_EXT_SPEC) >> $@
	echo -e "#else /* _UNIX */\n" >> $@
	$(BIN)/make_info.pl $(GLX_CORE_SPEC) >> $@
	$(BIN)/make_info.pl $(GLX_EXT_SPEC) >> $@
	echo -e "#endif /* _WIN32 */\n" >> $@

	cat $(SRC)/glewinfo_gl.c >> $@
	$(BIN)/make_info_list.pl $(GL_CORE_SPEC) >> $@
	$(BIN)/make_info_list.pl $(GL_EXT_SPEC) >> $@
	cat $(SRC)/glewinfo_wgl.c >> $@
	$(BIN)/make_info_list.pl $(WGL_EXT_SPEC) >> $@
	cat $(SRC)/glewinfo_glx.c >> $@
	$(BIN)/make_info_list.pl $(GLX_CORE_SPEC) >> $@
	$(BIN)/make_info_list.pl $(GLX_EXT_SPEC) >> $@
	cat $(SRC)/glewinfo_tail.c >> $@
	$(BIN)/fix_OML_sync_control.sh $@

$(D.DEST)/glew.html: $(EXT)/.dummy
	cp -f $(SRC)/glew_head.html $@
	$(BIN)/make_html.pl $(GL_EXT_SPEC) >> $@
	cat $(SRC)/glew_tail.html >> $@

$(D.DEST)/wglew.html: $(EXT)/.dummy
	cp -f $(SRC)/wglew_head.html $@
	$(BIN)/make_html.pl $(WGL_EXT_SPEC) >> $@
	cat $(SRC)/glew_tail.html >> $@

$(D.DEST)/glxew.html: $(EXT)/.dummy
	cp -f $(SRC)/glxew_head.html $@
	$(BIN)/make_html.pl $(GLX_EXT_SPEC) >> $@
	cat $(SRC)/glew_tail.html >> $@

clean:
	rm -rf $(TARGETS)
	rm -rf $(EXT)

clobber: clean
	rm -rf $(REGISTRY)
