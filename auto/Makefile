##
## Copyright (C) 2004, 2003 Marcelo E. Magallon <mmagallo[at]debian org>
## Copyright (C) 2004, 2003 Milan Ikits <milan ikits[at]ieee org>
##
## This program is distributed under the terms and conditions of the GNU
## General Public License Version 2 as published by the Free Software
## Foundation or, at your option, any later version.

GLEW_MAJOR = 1
GLEW_MINOR = 2
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

PARSE_SPEC = parse_spec.pl
SYSTEM = $(strip $(shell uname -s))

TOP = ..
I.DEST = $(TOP)/include/GL
S.DEST = $(TOP)/src
D.DEST = $(TOP)/doc

TARGETS = $(I.DEST)/glew.h $(I.DEST)/wglew.h $(I.DEST)/glxew.h $(S.DEST)/glew.c $(S.DEST)/glewinfo.c \
	$(D.DEST)/glew.html $(D.DEST)/wglew.html $(D.DEST)/glxew.html

all: $(TARGETS)

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
	cp -f $(SRC)/glew_pre.h $@
	$(BIN)/make_header.pl GLAPIENTRY GL $(CORE)/GL_VERSION* >> $@
	$(BIN)/make_header.pl GLAPIENTRY GL $(EXT)/GL_* >> $@
	echo -e "/* ------------------------------------------------------------------------- */\n\n#ifdef GLEW_MX\n#define GLEW_EXPORT\n#else\n#define GLEW_EXPORT GLEWAPI\n#endif /* GLEW_MX */\n\n#if defined(GLEW_MX) && defined(_WIN32)\nstruct GLEWContextStruct\n{\n#endif /* GLEW_MX */" >> $@
	$(BIN)/make_struct_fun.pl GLEW_EXPORT $(CORE)/GL_VERSION* $(EXT)/GL_* >> $@
	echo -e "\n#if defined(GLEW_MX) && !defined(_WIN32)\nstruct GLEWContextStruct\n{\n#endif /* GLEW_MX */\n" >> $@
	$(BIN)/make_struct_var.pl GLEW_EXPORT $(CORE)/GL_VERSION* $(EXT)/GL_* >> $@
	echo -e "\n#ifdef GLEW_MX\n}; /* GLEWContextStruct */\n#endif /* GLEW_MX */\n" >> $@
	perl -e 's/GLEW_EXPORT GLboolean __GLEW_VERSION_1_2;/GLEW_EXPORT GLboolean __GLEW_VERSION_1_1;\nGLEW_EXPORT GLboolean __GLEW_VERSION_1_2;/' -pi $@
	rm -f $@.bak
	cat $(SRC)/glew_post.h >> $@

$(I.DEST)/wglew.h: $(EXT)/.dummy
	cp -f $(SRC)/wglew_pre.h $@
	$(BIN)/make_header.pl WINAPI WGL $(EXT)/WGL_* >> $@
	echo -e "/* ------------------------------------------------------------------------- */\n\n#ifdef GLEW_MX\n#define WGLEW_EXPORT\n#else\n#define WGLEW_EXPORT GLEWAPI\n#endif /* GLEW_MX */\n\n#ifdef GLEW_MX\nstruct WGLEWContextStruct\n{\n#endif /* GLEW_MX */" >> $@
	$(BIN)/make_struct_fun.pl WGLEW_EXPORT $(EXT)/WGL_* >> $@
	$(BIN)/make_struct_var.pl WGLEW_EXPORT $(EXT)/WGL_* >> $@
	echo -e "\n#ifdef GLEW_MX\n}; /* WGLEWContextStruct */\n#endif /* GLEW_MX */\n" >> $@
	cat $(SRC)/wglew_post.h >> $@

$(I.DEST)/glxew.h: $(EXT)/.dummy
	cp -f $(SRC)/glxew_pre.h $@
	$(BIN)/make_header.pl '' GLX $(CORE)/GLX_VERSION* >> $@
	$(BIN)/make_header.pl '' GLX $(EXT)/GLX_* >> $@
	echo -e "/* ------------------------------------------------------------------------- */\n\n#ifdef GLEW_MX\n#define GLXEW_EXPORT\n#else\n#define GLXEW_EXPORT extern\n#endif /* GLEW_MX */" >> $@
	$(BIN)/make_struct_fun.pl GLXEW_EXPORT $(CORE)/GLX_VERSION* $(EXT)/GLX_* >> $@
	echo -e "\n#if defined(GLEW_MX)\nstruct GLXEWContextStruct\n{\n#endif /* GLEW_MX */\n" >> $@
	$(BIN)/make_struct_var.pl GLXEW_EXPORT $(CORE)/GLX_VERSION* $(EXT)/GLX_* >> $@
	echo -e "\n#ifdef GLEW_MX\n}; /* GLXEWContextStruct */\n#endif /* GLEW_MX */\n" >> $@
	perl -e 's/GLXEW_EXPORT GLboolean __GLXEW_VERSION_1_2;/GLXEW_EXPORT GLboolean __GLXEW_VERSION_1_0;\nGLXEW_EXPORT GLboolean __GLXEW_VERSION_1_1;\nGLXEW_EXPORT GLboolean __GLXEW_VERSION_1_2;/' -pi $@
	cat $(SRC)/glxew_post.h >> $@
	$(BIN)/fix_OML_sync_control.sh $@

$(S.DEST)/glew.c: $(EXT)/.dummy
	cp -f $(SRC)/glew_pre.c $@
	$(BIN)/make_def.pl GL $(CORE)/GL_VERSION* $(EXT)/GL_* >> $@
	echo -e "\n#endif /* !_WIN32 || !GLEW_MX */\n" >> $@
	echo -e "#if defined(_WIN32) && !defined(GLEW_MX)" >> $@
	$(BIN)/make_def.pl WGL $(EXT)/WGL_* >> $@
	echo -e "\n#endif /* _WIN32 && !GLEW_MX */\n" >> $@
	echo -e "#if !(defined(_WIN32) || (defined(__APPLE__) && !defined(GLEW_APPLE_GLX)))" >> $@
	$(BIN)/make_def.pl GLX $(CORE)/GLX_VERSION* $(EXT)/GLX_* >> $@
	echo -e "\n#endif /* !_WIN32 */\n" >> $@
	$(BIN)/make_init.pl GL $(CORE)/GL_VERSION* >> $@
	$(BIN)/make_init.pl GL $(EXT)/GL_* >> $@
	echo -e "#ifdef _WIN32\n" >> $@
	$(BIN)/make_init.pl WGL $(EXT)/WGL_* >> $@
	echo -e "#else /* _UNIX */\n\n" >> $@
	$(BIN)/make_init.pl GLX $(CORE)/GLX_VERSION* >> $@
	$(BIN)/make_init.pl GLX $(EXT)/GLX_* >> $@
	echo -e "#endif /* _WIN32 */\n" >> $@

	cat $(SRC)/glew_gl.c >> $@
	$(BIN)/make_list.pl $(CORE)/GL_VERSION* | grep -v '\"GL_VERSION' >> $@
	$(BIN)/make_list.pl $(EXT)/GL_* >> $@
	cat $(SRC)/glew_wgl.c >> $@
	$(BIN)/make_list.pl $(EXT)/WGL_* >> $@
	cat $(SRC)/glew_glx.c >> $@
	$(BIN)/make_list.pl $(CORE)/GLX_VERSION_1_3 | grep -v '\"GLX_VERSION' >> $@
	$(BIN)/make_list.pl $(EXT)/GLX_* >> $@
	cat $(SRC)/glew_post.c >> $@
	$(BIN)/fix_OML_sync_control.sh $@
	perl -e "s/GLEW_VERSION_STRING/$(GLEW_MAJOR)\.$(GLEW_MINOR)\.$(GLEW_MICRO)/g" -pi $@
	rm -f $@.bak

$(S.DEST)/glewinfo.c: $(EXT)/.dummy
	cp -f $(SRC)/glewinfo_pre.c $@
	$(BIN)/make_info.pl $(CORE)/GL_VERSION* >> $@
	$(BIN)/make_info.pl $(EXT)/GL_* >> $@
	echo -e "#ifdef _WIN32\n" >> $@
	$(BIN)/make_info.pl $(EXT)/WGL_* >> $@
	echo -e "#else /* _UNIX */\n" >> $@
	$(BIN)/make_info.pl $(CORE)/GLX_VERSION* >> $@
	$(BIN)/make_info.pl $(EXT)/GLX_* >> $@
	echo -e "#endif /* _WIN32 */\n" >> $@

	cat $(SRC)/glewinfo_gl.c >> $@
	$(BIN)/make_info_list.pl $(CORE)/GL_VERSION* >> $@
	$(BIN)/make_info_list.pl $(EXT)/GL_* >> $@
	cat $(SRC)/glewinfo_wgl.c >> $@
	$(BIN)/make_info_list.pl $(EXT)/WGL_* >> $@
	cat $(SRC)/glewinfo_glx.c >> $@
	$(BIN)/make_info_list.pl $(CORE)/GLX_VERSION* >> $@
	$(BIN)/make_info_list.pl $(EXT)/GLX_* >> $@
	cat $(SRC)/glewinfo_post.c >> $@
	$(BIN)/fix_OML_sync_control.sh $@

$(D.DEST)/glew.html: $(EXT)/.dummy
	cp -f $(SRC)/glew_pre.html $@
	$(BIN)/make_html.pl $(EXT)/GL_* >> $@
	cat $(SRC)/glew_post.html >> $@

$(D.DEST)/wglew.html: $(EXT)/.dummy
	cp -f $(SRC)/wglew_pre.html $@
	$(BIN)/make_html.pl $(EXT)/WGL_* >> $@
	cat $(SRC)/glew_post.html >> $@

$(D.DEST)/glxew.html: $(EXT)/.dummy
	cp -f $(SRC)/glxew_pre.html $@
	$(BIN)/make_html.pl $(EXT)/GLX_* >> $@
	cat $(SRC)/glew_post.html >> $@

clean:
	rm -rf $(TARGETS)
	rm -rf $(EXT)

clobber: clean
	rm -rf $(REGISTRY)
