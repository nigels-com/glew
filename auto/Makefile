## The OpenGL Extension Wrangler Library
## Copyright (C) 2003, 2002, Milan Ikits <milan.ikits@ieee.org>
## Copyright (C) 2003, 2002, Marcelo E. Magallon <mmagallo@debian.org>
## Copyright (C) 2002, Lev Povalahev <levp@gmx.net>
## All rights reserved.
## 
## Redistribution and use in source and binary forms, with or without 
## modification, are permitted provided that the following conditions are met:
## 
## * Redistributions of source code must retain the above copyright notice, 
##   this list of conditions and the following disclaimer.
## * Redistributions in binary form must reproduce the above copyright notice, 
##   this list of conditions and the following disclaimer in the documentation 
##   and/or other materials provided with the distribution.
## * The name of the author may be used to endorse or promote products 
##   derived from this software without specific prior written permission.
##
## THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
## AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
## IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
## ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
## LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
## CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
## SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
## INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
## CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
## ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
## THE POSSIBILITY OF SUCH DAMAGE.

SHELL := bash
REGISTRY := registry
BIN := bin
SRC := src
CORE := core
EXT := extensions
BLACKLIST := blacklist

PARSE_SPEC := parse_spec.pl

TOP := ..
I.DEST := $(TOP)/include/GL
S.DEST := $(TOP)/src

TARGETS = $(I.DEST)/glew.h $(I.DEST)/wglew.h $(I.DEST)/glxew.h $(S.DEST)/glew.c $(S.DEST)/glewinfo.c

all: $(TARGETS)

ext: $(EXT)/.dummy

$(REGISTRY)/.dummy: $(BIN)/update_registry.sh
	$(BIN)/update_registry.sh $(REGISTRY)
	touch $@

$(EXT)/.dummy: $(REGISTRY)/.dummy
	test -d $(EXT) || mkdir $(EXT)
	$(BIN)/update_ext.sh $(EXT) $(REGISTRY) $(BLACKLIST)
	ls -1 $(CORE)/* | grep -v VERSION | xargs cp --target-directory=$(EXT)
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

clean:
	rm -rf $(TARGETS)
	rm -rf $(EXT)

clobber: clean
	rm -rf $(REGISTRY)
