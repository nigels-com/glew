## The OpenGL Extension Wrangler Library
## Copyright (C) 2002 Milan Ikits
##
## This library is free software; you can redistribute it and/or
## modify it under the terms of the GNU Lesser General Public
## License as published by the Free Software Foundation; either
## version 2.1 of the License, or (at your option) any later version.
##
## This library is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
## Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public
## License along with this library; if not, write to the Free Software
## Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

GLEW_TARGET ?= /usr
GLEW_VERSION = 1.0.5

SYSTEM = $(strip $(shell uname -s))

ifeq ($(patsubst CYGWIN%,CYGWIN,$(SYSTEM)), CYGWIN)
CC = \gcc-2 -mno-cygwin
LD = \gcc-2 -mno-cygwin
NAME = glew32
DEFINE = -D'GLEW_STATIC'
else
ifeq ($(patsubst Linux%,Linux,$(SYSTEM)), Linux)
CC = \gcc
LD = \ld
NAME = GLEW
else
$(error "Platform '$(SYSTEM)' not supported")
endif
endif

AR = \ar
INSTALL = \install
RM = \rm -f
LN = \ln -s
ifeq ($(MAKECMDGOALS), debug)
OPT = -g
else
OPT = -O3 -fomit-frame-pointer
endif
INCLUDE = -Iinclude
CFLAGS = $(OPT) $(INCLUDE) $(DEFINE)

LIB.A = lib$(NAME).a
LIB.SO = lib$(NAME).so.$(GLEW_VERSION)
LIB.SO.LNK = lib$(NAME).so
LIB.SRCS = src/glew.c
LIB.OBJS = $(LIB.SRCS:.c=.o)

BIN = glewinfo
BIN.SRCS = src/glewinfo.c
BIN.OBJS = $(BIN.SRCS:.c=.o)
BIN.LIBS = -Llib -L/usr/X11R6/lib -lglut -l$(NAME) -lGLU -lGL -lXmu -lX11

all: lib/$(LIB.A) bin/$(BIN)

lib/$(LIB.A): $(LIB.OBJS)
	$(AR) cr $@ $^

lib/$(LIB.SO): $(LIB.OBJS)
	$(LD) -shared -o $@ $^
	$(LN) $(LIB) lib/$(LIB.LNK)

bin/$(BIN): $(BIN.SRCS)
	$(CC) $(CFLAGS) -o $@ $^ $(BIN.LIBS)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

install: all
	$(INSTALL) -d -m 755 $(GLEW_TARGET)/include/GL
	$(INSTALL) -m 644 include/GL/glew.h include/GL/glxew.h $(GLEW_TARGET)/include/GL
	$(INSTALL) -d -m 755 $(GLEW_TARGET)/lib
	$(INSTALL) -s -m 755 lib/$(LIB.SO) $(GLEW_TARGET)/lib
	$(LN) $(GLEW_TARGET)/lib/$(LIB.SO) $(GLEW_TARGET)/lib/$(LIB.SO.LNK)
	$(INSTALL) -d -m 755 $(GLEW_TARGET)/bin
	$(INSTALL) -s -m 755 bin/$(BIN) $(GLEW_TARGET)/bin

uninstall:
	$(RM) $(GLEW_TARGET)/include/GL/glew.h $(GLEW_TARGET)/include/GL/glxew.h
	$(RM) $(GLEW_TARGET)/lib/$(LIB.SO.LNK) $(GLEW_TARGET)/lib/$(LIB.SO)
	$(RM) $(GLEW_TARGET)/bin/$(BIN)

clean:
	$(RM) $(LIB.OBJS) lib/$(LIB.A) lib/$(LIB.SO) lib/$(LIB.SO.LNK) \
	$(BIN.OBJS) bin/$(BIN)
