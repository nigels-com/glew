#!gmake
## The OpenGL Extension Wrangler Library
## Copyright (C) 2004, 2003, 2002, Milan Ikits <milan ikits[at]ieee org>
## Copyright (C) 2004, 2003, 2002, Marcelo E. Magallon <mmagallo[at]debian org>
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

GLEW_DEST ?= /usr

GLEW_MAJOR = 1
GLEW_MINOR = 2
GLEW_MICRO = 1
GLEW_VERSION = $(GLEW_MAJOR).$(GLEW_MINOR).$(GLEW_MICRO)

TARDIR = ../glew-$(GLEW_VERSION)
TARBALL = ../glew_$(GLEW_VERSION).tar.gz

SHELL = /bin/sh
SYSTEM = $(strip $(shell uname -s))

# ----------------------------------------------------------------------------
# Cygwin
# ----------------------------------------------------------------------------
ifeq ($(patsubst CYGWIN%,CYGWIN,$(SYSTEM)), CYGWIN)
NAME = glew32
CC = gcc -mno-cygwin
LD = ld
CFLAGS.EXTRA = -DGLEW_STATIC
LDFLAGS.SO = -shared -soname $(LIB.SONAME)
LDFLAGS.GL = -lglu32 -lopengl32 -lgdi32 -luser32 -lkernel32
LDFLAGS.EXTRA =
WARN = -Wall -W
POPT = -O2
BIN.SUFFIX = .exe
LIB.SONAME = lib$(NAME).so.$(GLEW_MAJOR)
LIB.DEVLNK = lib$(NAME).so
LIB.SHARED = lib$(NAME).so.$(GLEW_VERSION)
LIB.STATIC = lib$(NAME).a

else
# ----------------------------------------------------------------------------
# Mingw32
# ----------------------------------------------------------------------------
ifeq ($(patsubst MINGW32%,MINGW32,$(SYSTEM)), MINGW32)
NAME = glew32
CC = gcc
# use gcc for linking, with ld it does not work
LD = gcc
CFLAGS.EXTRA =
CFLAGS.SO = -DGLEW_BUILD
#LDFLAGS.SO = -shared -soname $(LIB.SONAME) --out-implib lib/$(LIB.DEVLNK)
LDFLAGS.SO = -shared -Wl,-soname,$(LIB.SONAME) -Wl,--out-implib,lib/$(LIB.DEVLNK)
LDFLAGS.GL = -lglu32 -lopengl32 -lgdi32 -luser32 -lkernel32
LDFLAGS.EXTRA = -L/mingw/lib
WARN = -Wall -W
POPT = -O2
BIN.SUFFIX = .exe
LIB.SONAME = $(NAME).dll
LIB.DEVLNK = lib$(NAME).dll.a    # for mingw this is the dll import lib
LIB.SHARED = $(NAME).dll
LIB.STATIC = lib$(NAME).a     # the static lib will be broken (see CFLAGS.SO)

else
# ----------------------------------------------------------------------------
# Linux
# ----------------------------------------------------------------------------
ifeq ($(patsubst Linux%,Linux,$(SYSTEM)), Linux)
NAME = GLEW
CC = cc
LD = ld
CFLAGS.EXTRA = 
LDFLAGS.SO = -shared -soname $(LIB.SONAME)
LDFLAGS.EXTRA = -L/usr/X11R6/lib
LDFLAGS.GL = -lXmu -lXi -lGLU -lGL -lXext -lX11
NAME = GLEW
WARN = -Wall -W
POPT = -O2
BIN.SUFFIX =
LIB.SONAME = lib$(NAME).so.$(GLEW_MAJOR)
LIB.DEVLNK = lib$(NAME).so
LIB.SHARED = lib$(NAME).so.$(GLEW_VERSION)
LIB.STATIC = lib$(NAME).a

else
# ----------------------------------------------------------------------------
# Irix
# ----------------------------------------------------------------------------
ifeq ($(patsubst IRIX%,IRIX,$(SYSTEM)), IRIX)
NAME = GLEW
CC = cc
LD = ld
ABI = -64# -n32
CC += $(ABI)
LD += $(ABI)
CFLAGS.EXTRA =
LDFLAGS.SO = -shared -soname $(LIB.SONAME)
LDFLAGS.EXTRA =
LDFLAGS.GL = -lGL -lXext -lX11
NAME = GLEW
WARN = -fullwarn -woff 1110,1498
POPT = -O2
BIN.SUFFIX =
LIB.SONAME = lib$(NAME).so.$(GLEW_MAJOR)
LIB.DEVLNK = lib$(NAME).so
LIB.SHARED = lib$(NAME).so.$(GLEW_VERSION)
LIB.STATIC = lib$(NAME).a

else
# ----------------------------------------------------------------------------
# Darwin
# ----------------------------------------------------------------------------
ifeq ($(patsubst Darwin%,Darwin,$(SYSTEM)), Darwin)
NAME = GLEW
CC = cc
LD = cc
CFLAGS.EXTRA = -no-cpp-precomp -dynamic -fno-common
LDFLAGS.SO = -dynamiclib -install_name $(GLEW_DEST)/lib/$(LIB.SHARED)
LDFLAGS.EXTRA =
ifneq (undefined, $(origin GLEW_APPLE_GLX))
CFLAGS.EXTRA += -I/usr/X11R6/include -D'GLEW_APPLE_GLX'
LDFLAGS.GL = -L/usr/X11R6/lib -lXmu -lXi -lGLU -lGL -lXext -lX11
else
LDFLAGS.GL = -framework AGL -framework OpenGL
endif
NAME = GLEW
BIN.SUFFIX =
WARN = -Wall -W
POPT = -O2
LIB.SONAME = lib$(NAME).$(GLEW_MAJOR).dylib
LIB.DEVLNK = lib$(NAME).dylib
LIB.SHARED = lib$(NAME).$(GLEW_VERSION).dylib
LIB.STATIC = lib$(NAME).a

else
# ----------------------------------------------------------------------------
# Solaris
# ----------------------------------------------------------------------------
ifeq ($(patsubst SunOS%,SunOS,$(SYSTEM)), SunOS)
NAME = GLEW
CC = cc
LD = ld
CFLAGS.EXTRA = -I/usr/openwin/include
LDFLAGS.SO = -shared
LDFLAGS.EXTRA = -L/usr/openwin/lib
LDFLAGS.GL = -lXmu -lXi -lGLU -lGL -lXext -lX11
NAME = GLEW
BIN.SUFFIX =
POPT = -xO2
LIB.SONAME = lib$(NAME).so.$(GLEW_MAJOR)
LIB.DEVLNK = lib$(NAME).so
LIB.SHARED = lib$(NAME).so.$(GLEW_VERSION)
LIB.STATIC = lib$(NAME).a
else
# ----------------------------------------------------------------------------
$(error "Platform '$(SYSTEM)' not supported")
endif
endif
endif
endif
endif
endif

AR = ar
INSTALL = install
RM = rm -f
LN = ln -sf
ifeq ($(MAKECMDGOALS), debug)
OPT = -g
STRIP =
else
OPT = $(POPT)
STRIP = -s
endif
INCLUDE = -Iinclude
CFLAGS = $(OPT) $(WARN) $(INCLUDE) $(CFLAGS.EXTRA)

LIB.SRCS = src/glew.c
LIB.OBJS = $(LIB.SRCS:.c=.o)
LIB.LDFLAGS = $(LDFLAGS.EXTRA) $(LDFLAGS.GL)
LIB.LIBS = $(GL_LDFLAGS)

BIN = glewinfo$(BIN.SUFFIX)
BIN.SRCS = src/glewinfo.c
BIN.OBJS = $(BIN.SRCS:.c=.o)
BIN.LIBS = -Llib -l$(NAME) $(LDFLAGS.EXTRA) $(LDFLAGS.GL)

all debug: lib/$(LIB.SHARED) lib/$(LIB.STATIC) bin/$(BIN)

lib:
	mkdir lib

lib/$(LIB.STATIC): $(LIB.OBJS)
	$(AR) cr $@ $^

lib/$(LIB.SHARED): $(LIB.OBJS)
	$(LD) $(LDFLAGS.SO) -o $@ $^ $(LIB.LDFLAGS) $(LIB.LIBS)
ifeq ($(patsubst MINGW32%,MINGW32,$(SYSTEM)), MINGW32)
else
	$(LN) $(LIB.SHARED) lib/$(LIB.SONAME)
	$(LN) $(LIB.SHARED) lib/$(LIB.DEVLNK)
endif

bin/$(BIN): $(BIN.SRCS)
	$(CC) $(CFLAGS) -o $@ $^ $(BIN.LIBS)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

src/glew.o: src/glew.c include/GL/glew.h include/GL/wglew.h include/GL/glxew.h
	$(CC) $(CFLAGS) $(CFLAGS.SO) -o $@ -c $<

install: all
# directories
	$(INSTALL) -d -m 0755 $(GLEW_DEST)/bin
	$(INSTALL) -d -m 0755 $(GLEW_DEST)/include/GL
	$(INSTALL) -d -m 0755 $(GLEW_DEST)/lib
# runtime
ifeq ($(patsubst MINGW32%,MINGW32,$(SYSTEM)), MINGW32)
	$(INSTALL) $(STRIP) -m 0644 lib/$(LIB.SHARED) $(GLEW_DEST)/bin/
else
  ifeq ($(patsubst Darwin%,Darwin,$(SYSTEM)), Darwin)
	strip -x lib/$(LIB.SHARED)
	$(INSTALL) -m 0644 lib/$(LIB.SHARED) $(GLEW_DEST)/lib/
	$(LN) $(LIB.SHARED) $(GLEW_DEST)/lib/$(LIB.SONAME)
  else
	$(INSTALL) $(STRIP) -m 0644 lib/$(LIB.SHARED) $(GLEW_DEST)/lib/
	$(LN) $(LIB.SHARED) $(GLEW_DEST)/lib/$(LIB.SONAME)
  endif
endif
# development files
	$(INSTALL) -m 0644 include/GL/wglew.h $(GLEW_DEST)/include/GL
	$(INSTALL) -m 0644 include/GL/glew.h $(GLEW_DEST)/include/GL
	$(INSTALL) -m 0644 include/GL/glxew.h $(GLEW_DEST)/include/GL
ifeq ($(patsubst MINGW32%,MINGW32,$(SYSTEM)), MINGW32)
	$(INSTALL) -m 0644 lib/$(LIB.DEVLNK) $(GLEW_DEST)/lib/
else
  ifeq ($(patsubst Darwin%,Darwin,$(SYSTEM)), Darwin)
	strip -x lib/$(LIB.STATIC)
	$(INSTALL) -m 0644 lib/$(LIB.STATIC) $(GLEW_DEST)/lib/
	$(LN) $(LIB.SHARED) $(GLEW_DEST)/lib/$(LIB.DEVLNK)
  else
	$(INSTALL) $(STRIP) -m 0644 lib/$(LIB.STATIC) $(GLEW_DEST)/lib/
	$(LN) $(LIB.SHARED) $(GLEW_DEST)/lib/$(LIB.DEVLNK)
  endif
endif
# utilities
	$(INSTALL) -s -m 0755 bin/$(BIN) $(GLEW_DEST)/bin/

uninstall:
	$(RM) $(GLEW_DEST)/include/GL/wglew.h
	$(RM) $(GLEW_DEST)/include/GL/glew.h
	$(RM) $(GLEW_DEST)/include/GL/glxew.h
	$(RM) $(GLEW_DEST)/lib/$(LIB.DEVLNK)
ifeq ($(patsubst MINGW32%,MINGW32,$(SYSTEM)), MINGW32)
	$(RM) $(GLEW_DEST)/bin/$(LIB.SHARED)
else
	$(RM) $(GLEW_DEST)/lib/$(LIB.SONAME)
	$(RM) $(GLEW_DEST)/lib/$(LIB.SHARED)
	$(RM) $(GLEW_DEST)/lib/$(LIB.STATIC)
endif
	$(RM) $(GLEW_DEST)/bin/$(BIN)

clean:
	$(RM) $(LIB.OBJS)
	$(RM) lib/$(LIB.STATIC) lib/$(LIB.SHARED) lib/$(LIB.DEVLNK) lib/$(LIB.SONAME) $(LIB.STATIC)
	$(RM) $(BIN.OBJS) bin/$(BIN)
# Compiler droppings
	$(RM) so_locations

distclean: clean
	find . -name \*~ | xargs $(RM)
	find . -name .\*.sw\? | xargs $(RM)

tardist:
	$(RM) -r $(TARDIR)
	mkdir $(TARDIR)
	cp -a . $(TARDIR)
	find $(TARDIR) -name CVS -o -name .cvsignore | xargs $(RM) -r
	$(MAKE) -C $(TARDIR) distclean
	$(MAKE) -C $(TARDIR)
	$(MAKE) -C $(TARDIR) distclean
	$(RM) -r $(TARDIR)/auto/registry
	env GZIP=-9 tar -C `dirname $(TARDIR)` -cvzf $(TARBALL) `basename $(TARDIR)`

extensions:
	$(MAKE) -C auto

.PHONY: clean distclean tardist
