#
# Copyright (C) 2003 Marcelo E. Magallon <mmagallo@debian.org>
# Copyright (C) 2003 Milan Ikits <milan.ikits@ieee.org>
#
# This program is distributed under the terms and conditions of the GNU
# General Public License Version 2 as published by the Free Software
# Foundation or, at your option, any later version.

GLEW_MAJOR = 1
GLEW_MINOR = 1
GLEW_MICRO = 2
GLEW_VERSION = $(GLEW_MAJOR).$(GLEW_MINOR).$(GLEW_MICRO)

SHELL = bash
REGISTRY = registry
REGISTRY_URL =  http://oss.sgi.com/projects/ogl-sample/registry/
BIN = bin
SRC = src
CORE = core
EXT = extensions
BLACKLIST = blacklist

PARSE_SPEC = parse_spec.pl

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
	sed -i -e '7s/\<ATI_/GL_ATI_/' $(REGISTRY)/ATI/texture_env_combine3.txt
	touch $@

$(EXT)/.dummy: $(REGISTRY)/.dummy
	rm -rf $(EXT)
	$(BIN)/update_ext.sh $(EXT) $(REGISTRY) $(BLACKLIST)
	find $(CORE) -maxdepth 1 -type f | grep -v VERSION | xargs cp --target-directory=$(EXT)
	touch $@

$(I.DEST)/glew.h: $(EXT)/.dummy
	test -d $(I.DEST) || mkdir -p $(I.DEST)
	cp -f $(SRC)/glew_pre.h $@
	$(BIN)/make_header.pl GLAPIENTRY $(CORE)/GL_VERSION* >> $@
	mv $@ tmp; grep -v 'PFNGLBLENDCOLORPROC' tmp | \
	grep -v 'PFNGLBLENDEQUATIONPROC' | grep -v 'glBlendColor' | \
	grep -v 'glBlendEquation' > $@; rm tmp;
	$(BIN)/make_header.pl GLAPIENTRY $(EXT)/GL_* >> $@
	cat $(SRC)/glew_post.h >> $@

$(I.DEST)/wglew.h: $(EXT)/.dummy
	cp -f $(SRC)/wglew_pre.h $@
	$(BIN)/make_header.pl WINAPI $(EXT)/WGL_* >> $@
	cat $(SRC)/wglew_post.h >> $@

$(I.DEST)/glxew.h: $(EXT)/.dummy
	cp -f $(SRC)/glxew_pre.h $@
	$(BIN)/make_header.pl '' $(CORE)/GLX_VERSION* >> $@
	$(BIN)/make_header.pl '' $(EXT)/GLX_* >> $@
	cat $(SRC)/glxew_post.h >> $@
	$(BIN)/fix_OML_sync_control.sh $@

$(S.DEST)/glew.c: $(EXT)/.dummy
	cp -f $(SRC)/glew_pre.c $@
	$(BIN)/make_init.pl $(CORE)/GL_VERSION* >> $@
	mv $@ tmp; grep -v 'PFNGLBLENDCOLORPROC' tmp | \
	grep -v 'PFNGLBLENDEQUATIONPROC' | grep -v 'glBlendColor' | \
	grep -v 'glBlendEquation' > $@; rm tmp;
	$(BIN)/make_init.pl $(EXT)/GL_* >> $@
	echo -e "#ifdef _WIN32\n" >> $@
	$(BIN)/make_init.pl $(EXT)/WGL_* >> $@
	echo -e "#else /* _UNIX */\n\n" >> $@
	cat $(SRC)/glew_init_glx.c >> $@
	$(BIN)/make_init.pl $(CORE)/GLX_VERSION* >> $@
	$(BIN)/make_init.pl $(EXT)/GLX_* >> $@
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
	sed -i -e "s/GLEW_VERSION_STRING/$(GLEW_MAJOR)\.$(GLEW_MINOR)\.$(GLEW_MICRO)/g" $@

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
