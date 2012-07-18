#!gmake
## The OpenGL Extension Wrangler Library
## Copyright (C) 2002-2008, Milan Ikits <milan ikits[]ieee org>
## Copyright (C) 2002-2008, Marcelo E. Magallon <mmagallo[]debian org>
## Copyright (C) 2002, Lev Povalahev
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

include config/version

SHELL = /bin/sh
SYSTEM ?= $(shell config/config.guess | cut -d - -f 3 | sed -e 's/[0-9\.]//g;')
SYSTEM.SUPPORTED = $(shell test -f config/Makefile.$(SYSTEM) && echo 1)

ifeq ($(SYSTEM.SUPPORTED), 1)
include config/Makefile.$(SYSTEM)
else
$(error "Platform '$(SYSTEM)' not supported")
endif

GLEW_DEST ?= /usr
BINDIR    ?= $(GLEW_DEST)/bin
LIBDIR    ?= $(GLEW_DEST)/lib
INCDIR    ?= $(GLEW_DEST)/include/GL

TARDIR = ../glew-$(GLEW_VERSION)
TARBALL = ../glew-$(GLEW_VERSION).tar.gz

DIST_DIR     = glew-$(GLEW_VERSION)
DIST_WIN32   = glew-$(GLEW_VERSION)-win32.zip
DIST_SRC_ZIP = glew-$(GLEW_VERSION).zip
DIST_SRC_TGZ = glew-$(GLEW_VERSION).tgz

# To disable stripping of binaries either:
#   - use STRIP= on gmake command-line
#   - edit this makefile to set STRIP to the empty string
#
# To disable symlinks:
#   - use LN= on gmake command-line

AR      ?= ar
INSTALL ?= install
STRIP   ?= strip
RM      ?= rm -f
LN      ?= ln -sf

ifeq ($(MAKECMDGOALS), debug)
OPT = -g
else
OPT = $(POPT)
endif
INCLUDE = -Iinclude
CFLAGS = $(OPT) $(WARN) $(INCLUDE) $(CFLAGS.EXTRA)

all debug: glew.lib glew.lib.mx glew.bin

# GLEW shared and static libraries

LIB.LDFLAGS        := $(LDFLAGS.EXTRA) $(LDFLAGS.GL)
LIB.LIBS           := $(GL_LDFLAGS)

LIB.SRCS           := src/glew.c
LIB.SRCS.NAMES     := $(notdir $(LIB.SRCS))

LIB.OBJS           := $(addprefix tmp/$(SYSTEM)/default/static/,$(LIB.SRCS.NAMES))
LIB.OBJS           := $(LIB.OBJS:.c=.o)
LIB.SOBJS          := $(addprefix tmp/$(SYSTEM)/default/shared/,$(LIB.SRCS.NAMES))
LIB.SOBJS          := $(LIB.SOBJS:.c=.o)

LIB.OBJS.MX        := $(addprefix tmp/$(SYSTEM)/mx/static/,$(LIB.SRCS.NAMES))
LIB.OBJS.MX        := $(LIB.OBJS.MX:.c=.o)
LIB.SOBJS.MX       := $(addprefix tmp/$(SYSTEM)/mx/shared/,$(LIB.SRCS.NAMES))
LIB.SOBJS.MX       := $(LIB.SOBJS.MX:.c=.o)

glew.lib: lib lib/$(LIB.SHARED) lib/$(LIB.STATIC) glew.pc

lib:
	mkdir lib

lib/$(LIB.STATIC): $(LIB.OBJS)
	$(AR) cr $@ $^
ifneq ($(STRIP),)
	$(STRIP) -x $@
endif

lib/$(LIB.SHARED): $(LIB.SOBJS)
	$(LD) $(LDFLAGS.SO) -o $@ $^ $(LIB.LDFLAGS) $(LIB.LIBS)
ifneq ($(LN),)
	$(LN) $(LIB.SHARED) lib/$(LIB.SONAME)
	$(LN) $(LIB.SHARED) lib/$(LIB.DEVLNK)
endif
ifneq ($(STRIP),)
	$(STRIP) -x $@
endif

tmp/$(SYSTEM)/default/static/glew.o: src/glew.c include/GL/glew.h include/GL/wglew.h include/GL/glxew.h
	@mkdir -p $(dir $@)
	$(CC) -DGLEW_NO_GLU -DGLEW_STATIC $(CFLAGS) $(CFLAGS.SO) -o $@ -c $<

tmp/$(SYSTEM)/default/shared/glew.o: src/glew.c include/GL/glew.h include/GL/wglew.h include/GL/glxew.h
	@mkdir -p $(dir $@)
	$(CC) -DGLEW_NO_GLU $(CFLAGS) $(PICFLAG) $(CFLAGS.SO) -o $@ -c $<

glew.pc: glew.pc.in
	sed \
		-e "s|@prefix@|$(GLEW_DEST)|g" \
		-e "s|@libdir@|$(LIBDIR)|g" \
		-e "s|@exec_prefix@|$(BINDIR)|g" \
		-e "s|@includedir@|$(INCDIR)|g" \
		-e "s|@version@|$(GLEW_VERSION)|g" \
		-e "s|@cflags@||g" \
		-e "s|@libname@|GLEW|g" \
		< $< > $@

# GLEW MX static and shared libraries

glew.lib.mx:  lib lib/$(LIB.SHARED.MX) lib/$(LIB.STATIC.MX) glewmx.pc

lib/$(LIB.STATIC.MX): $(LIB.OBJS.MX)
	$(AR) cr $@ $^

lib/$(LIB.SHARED.MX): $(LIB.SOBJS.MX)
	$(LD) $(LDFLAGS.SO.MX) -o $@ $^ $(LIB.LDFLAGS) $(LIB.LIBS)
ifneq ($(LN),)
	$(LN) $(LIB.SHARED.MX) lib/$(LIB.SONAME.MX)
	$(LN) $(LIB.SHARED.MX) lib/$(LIB.DEVLNK.MX)
endif
ifneq ($(STRIP),)
	$(STRIP) -x $@
endif

tmp/$(SYSTEM)/mx/static/glew.o: src/glew.c include/GL/glew.h include/GL/wglew.h include/GL/glxew.h
	@mkdir -p $(dir $@)
	$(CC) -DGLEW_NO_GLU -DGLEW_MX -DGLEW_STATIC $(CFLAGS) $(CFLAGS.SO) -o $@ -c $<

tmp/$(SYSTEM)/mx/shared/glew.o: src/glew.c include/GL/glew.h include/GL/wglew.h include/GL/glxew.h
	@mkdir -p $(dir $@)
	$(CC) -DGLEW_NO_GLU -DGLEW_MX $(CFLAGS) $(PICFLAG) $(CFLAGS.SO) -o $@ -c $<

glewmx.pc: glew.pc.in
	sed \
		-e "s|@prefix@|$(GLEW_DEST)|g" \
		-e "s|@libdir@|$(LIBDIR)|g" \
		-e "s|@exec_prefix@|$(BINDIR)|g" \
		-e "s|@includedir@|$(INCDIR)|g" \
		-e "s|@version@|$(GLEW_VERSION)|g" \
		-e "s|@cflags@|-DGLEW_MX|g" \
		-e "s|@libname@|GLEWmx|g" \
		< $< > $@

# GLEW utility programs

BIN.LIBS = -Llib $(LDFLAGS.DYNAMIC) -l$(NAME) $(LDFLAGS.EXTRA) $(LDFLAGS.GL)

GLEWINFO.BIN       := glewinfo$(BIN.SUFFIX)
GLEWINFO.BIN.SRC   := src/glewinfo.c
GLEWINFO.BIN.OBJ   := $(addprefix tmp/$(SYSTEM)/default/shared/,$(notdir $(GLEWINFO.BIN.SRC)))
GLEWINFO.BIN.OBJ   := $(GLEWINFO.BIN.OBJ:.c=.o)

VISUALINFO.BIN     := visualinfo$(BIN.SUFFIX)
VISUALINFO.BIN.SRC := src/visualinfo.c
VISUALINFO.BIN.OBJ := $(addprefix tmp/$(SYSTEM)/default/shared/,$(notdir $(VISUALINFO.BIN.SRC)))
VISUALINFO.BIN.OBJ := $(VISUALINFO.BIN.OBJ:.c=.o)

glew.bin: glew.lib bin bin/$(GLEWINFO.BIN) bin/$(VISUALINFO.BIN) 

bin:
	mkdir bin

bin/$(GLEWINFO.BIN): $(GLEWINFO.BIN.OBJ) lib/$(LIB.SHARED)
	$(CC) $(CFLAGS) -o $@ $(GLEWINFO.BIN.OBJ) $(BIN.LIBS)
ifneq ($(STRIP),)
	$(STRIP) -x $@
endif

bin/$(VISUALINFO.BIN): $(VISUALINFO.BIN.OBJ) lib/$(LIB.SHARED)
	$(CC) $(CFLAGS) -o $@ $(VISUALINFO.BIN.OBJ) $(BIN.LIBS)
ifneq ($(STRIP),)
	$(STRIP) -x $@
endif

$(GLEWINFO.BIN.OBJ): $(GLEWINFO.BIN.SRC) include/GL/glew.h include/GL/wglew.h include/GL/glxew.h
	@mkdir -p $(dir $@)
	$(CC) -DGLEW_NO_GLU $(CFLAGS) $(CFLAGS.SO) -o $@ -c $<

$(VISUALINFO.BIN.OBJ): $(VISUALINFO.BIN.SRC) include/GL/glew.h include/GL/wglew.h include/GL/glxew.h
	@mkdir -p $(dir $@)
	$(CC) -DGLEW_NO_GLU $(CFLAGS) $(CFLAGS.SO) -o $@ -c $<

# Install targets

install.all: install install.mx install.bin

install:     install.include install.lib install.pkgconfig

install.mx:  install.include install.lib.mx install.pkgconfig.mx

install.lib: glew.lib
	$(INSTALL) -d -m 0755 $(LIBDIR)
# runtime
ifeq ($(filter-out mingw% cygwin,$(SYSTEM)),)
	$(INSTALL) -d -m 0755 $(BINDIR)
	$(INSTALL) -m 0755 lib/$(LIB.SHARED) $(BINDIR)/
else
	$(INSTALL) -m 0644 lib/$(LIB.SHARED) $(LIBDIR)/
endif
ifneq ($(LN),)
	$(LN) $(LIB.SHARED) $(LIBDIR)/$(LIB.SONAME)
endif

# development files
ifeq ($(filter-out mingw% cygwin,$(SYSTEM)),)
	$(INSTALL) -m 0644 lib/$(LIB.DEVLNK) $(LIBDIR)/
endif
ifneq ($(LN),)
	$(LN) $(LIB.SHARED) $(LIBDIR)/$(LIB.DEVLNK)
endif
	$(INSTALL) -m 0644 lib/$(LIB.STATIC) $(LIBDIR)/

install.lib.mx: glew.lib.mx
	$(INSTALL) -d -m 0755 $(LIBDIR)
# runtime
ifeq ($(filter-out mingw% cygwin,$(SYSTEM)),)
	$(INSTALL) -d -m 0755 $(BINDIR)
	$(INSTALL) -m 0755 lib/$(LIB.SHARED.MX) $(BINDIR)/
else
	$(INSTALL) -m 0644 lib/$(LIB.SHARED.MX) $(LIBDIR)/
endif
ifneq ($(LN),)
	$(LN) $(LIB.SHARED.MX) $(LIBDIR)/$(LIB.SONAME.MX)
endif
# development files
ifeq ($(filter-out mingw% cygwin,$(SYSTEM)),)
	$(INSTALL) -m 0644 lib/$(LIB.DEVLNK.MX) $(LIBDIR)/
endif
ifneq ($(LN),)
	$(LN) $(LIB.SHARED.MX) $(LIBDIR)/$(LIB.DEVLNK.MX)
endif
	$(INSTALL) -m 0644 lib/$(LIB.STATIC.MX) $(LIBDIR)/

install.bin: glew.bin
	$(INSTALL) -d -m 0755 $(BINDIR)
	$(INSTALL) -s -m 0755 bin/$(GLEWINFO.BIN) bin/$(VISUALINFO.BIN) $(BINDIR)/

install.include:
	$(INSTALL) -d -m 0755 $(INCDIR)
	$(INSTALL) -m 0644 include/GL/wglew.h $(INCDIR)/
	$(INSTALL) -m 0644 include/GL/glew.h $(INCDIR)/
	$(INSTALL) -m 0644 include/GL/glxew.h $(INCDIR)/

install.pkgconfig: glew.pc
	$(INSTALL) -d -m 0755 $(LIBDIR)
	$(INSTALL) -d -m 0755 $(LIBDIR)/pkgconfig
	$(INSTALL) -m 0644 glew.pc $(LIBDIR)/pkgconfig/

install.pkgconfig.mx: glewmx.pc
	$(INSTALL) -d -m 0755 $(LIBDIR)
	$(INSTALL) -d -m 0755 $(LIBDIR)/pkgconfig
	$(INSTALL) -m 0644 glewmx.pc $(LIBDIR)/pkgconfig/

uninstall:
	$(RM) $(INCDIR)/wglew.h
	$(RM) $(INCDIR)/glew.h
	$(RM) $(INCDIR)/glxew.h
	$(RM) $(LIBDIR)/$(LIB.DEVLNK) $(LIBDIR)/$(LIB.DEVLNK.MX)
ifeq ($(filter-out mingw% cygwin,$(SYSTEM)),)
	$(RM) $(BINDIR)/$(LIB.SHARED) $(BINDIR)/$(LIB.SHARED.MX)
else
	$(RM) $(LIBDIR)/$(LIB.SONAME) $(LIBDIR)/$(LIB.SONAME.MX)
	$(RM) $(LIBDIR)/$(LIB.SHARED) $(LIBDIR)/$(LIB.SHARED.MX)
endif
	$(RM) $(LIBDIR)/$(LIB.STATIC) $(LIBDIR)/$(LIB.STATIC.MX)
	$(RM) $(BINDIR)/$(GLEWINFO.BIN) $(BINDIR)/$(VISUALINFO.BIN)

clean:
	$(RM) -r tmp/
	$(RM) -r lib/
	$(RM) -r bin/
	$(RM) glew.pc glewmx.pc

distclean: clean
	find . -name \*~ | xargs $(RM)
	find . -name .\*.sw\? | xargs $(RM)

# Distributions

dist-win32:
	$(RM) -r $(TARDIR)
	mkdir -p $(TARDIR)
	mkdir -p $(TARDIR)/bin
	mkdir -p $(TARDIR)/lib
	cp -a include $(TARDIR)
	cp -a doc $(TARDIR)
	cp -a *.txt $(TARDIR)
	cp -a lib/glew32.lib     $(TARDIR)/lib
	cp -a lib/glew32s.lib    $(TARDIR)/lib
	cp -a lib/glew32mx.lib   $(TARDIR)/lib
	cp -a lib/glew32mxs.lib  $(TARDIR)/lib
	cp -a bin/glew32.dll     $(TARDIR)/bin
	cp -a bin/glew32mx.dll   $(TARDIR)/bin
	cp -a bin/glewinfo.exe   $(TARDIR)/bin
	cp -a bin/visualinfo.exe $(TARDIR)/bin
	find $(TARDIR) -name CVS -o -name .cvsignore | xargs $(RM) -r
	find $(TARDIR) -name .svn | xargs $(RM) -r
	find $(TARDIR) -name "*.patch" | xargs $(RM) -r
	unix2dos $(TARDIR)/include/GL/*.h
	unix2dos $(TARDIR)/doc/*.txt
	unix2dos $(TARDIR)/doc/*.html
	unix2dos $(TARDIR)/*.txt
	rm -f ../$(DIST_WIN32)
	cd .. && zip -rv9 $(DIST_WIN32) $(DIST_DIR)

dist-src:
	$(RM) -r $(TARDIR)
	mkdir -p $(TARDIR)
	mkdir -p $(TARDIR)/bin
	mkdir -p $(TARDIR)/lib
	cp -a auto $(TARDIR)
	$(RM) -Rf $(TARDIR)/auto/registry
	cp -a build $(TARDIR)
	cp -a config $(TARDIR)
	cp -a src $(TARDIR)
	cp -a doc $(TARDIR)
	cp -a include $(TARDIR)
	cp -a *.txt $(TARDIR)
	cp -a Makefile $(TARDIR)
	cp -a glew.pc.in $(TARDIR)
	find $(TARDIR) -name '*.o' | xargs $(RM) -r
	find $(TARDIR) -name '*~' | xargs $(RM) -r
	find $(TARDIR) -name CVS -o -name .cvsignore | xargs $(RM) -r
	find $(TARDIR) -name .svn | xargs $(RM) -r
	find $(TARDIR) -name "*.patch" | xargs $(RM) -r
	unix2dos $(TARDIR)/Makefile
	unix2dos $(TARDIR)/config/*
	unix2dos $(TARDIR)/auto/core/*
	unix2dos $(TARDIR)/auto/extensions/*
	find $(TARDIR) -name '*.h' | xargs unix2dos
	find $(TARDIR) -name '*.c' | xargs unix2dos
	find $(TARDIR) -name '*.txt' | xargs unix2dos
	find $(TARDIR) -name '*.html' | xargs unix2dos
	find $(TARDIR) -name '*.css' | xargs unix2dos
	find $(TARDIR) -name '*.sh' | xargs unix2dos
	find $(TARDIR) -name '*.pl' | xargs unix2dos
	find $(TARDIR) -name 'Makefile' | xargs unix2dos
	find $(TARDIR) -name '*.in' | xargs unix2dos
	find $(TARDIR) -name '*.pm' | xargs unix2dos
	find $(TARDIR) -name '*.rc' | xargs unix2dos
	rm -f ../$(DIST_SRC_ZIP)
	cd .. && zip -rv9 $(DIST_SRC_ZIP) $(DIST_DIR)
	dos2unix $(TARDIR)/Makefile
	dos2unix $(TARDIR)/config/*
	dos2unix $(TARDIR)/auto/core/*
	dos2unix $(TARDIR)/auto/extensions/*
	find $(TARDIR) -name '*.h' | xargs dos2unix
	find $(TARDIR) -name '*.c' | xargs dos2unix
	find $(TARDIR) -name '*.txt' | xargs dos2unix
	find $(TARDIR) -name '*.html' | xargs dos2unix
	find $(TARDIR) -name '*.css' | xargs dos2unix
	find $(TARDIR) -name '*.sh' | xargs dos2unix
	find $(TARDIR) -name '*.pl' | xargs dos2unix
	find $(TARDIR) -name 'Makefile' | xargs dos2unix
	find $(TARDIR) -name '*.in' | xargs dos2unix
	find $(TARDIR) -name '*.pm' | xargs dos2unix
	find $(TARDIR) -name '*.rc' | xargs dos2unix
	cd .. && env GZIP=-9 tar cvzf $(DIST_SRC_TGZ) $(DIST_DIR)

extensions:
	$(MAKE) -C auto

.PHONY: clean distclean tardist dist-win32 dist-src
