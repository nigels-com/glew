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

CC = \cc
LD = \ld
INSTALL = \install
RM = \rm -f
OPT = -O2
INCLUDE = -Iinclude
CFLAGS = $(OPT) $(INCLUDE)

LIB = lib/libGLEW.so
LIB.SRCS = src/glew.c
LIB.OBJS = $(LIB.SRCS:.c=.o)
LIB.LIBS =

BIN = bin/glewinfo
BIN.SRCS = src/glewinfo.c
BIN.OBJS = $(BIN.SRCS:.c=.o)
BIN.LIBS = -Llib -L/usr/X11R6/lib -lglut -lGLEW -lGL -lXmu -lX11

all: $(LIB) $(BIN)

$(LIB): $(LIB.OBJS)
	$(LD) -shared -o $@ $^ $(LIB.LIBS)

$(BIN): $(BIN.SRCS)
	$(CC) $(CFLAGS) -o $@ $^ $(BIN.LIBS)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

install: all
	$(INSTALL) -d -m 755 $(GLEW_TARGET)/include/GL
	$(INSTALL) -m 644 include/GL/glew.h include/GL/glxew.h $(GLEW_TARGET)/include/GL
	$(INSTALL) -d -m 755 $(GLEW_TARGET)/lib
	$(INSTALL) -s -m 755 lib/libGLEW.so $(GLEW_TARGET)/lib
	$(INSTALL) -d -m 755 $(GLEW_TARGET)/bin
	$(INSTALL) -s -m 755 lib/glewinfo $(GLEW_TARGET)/bin

uninstall:
	$(RM) $(GLEW_TARGET)/include/GL/glew.h $(GLEW_TARGET)/include/GL/glxew.h
	$(RM) $(GLEW_TARGET)/lib/libGLEW.so
	$(RM) $(GLEW_TARGET)/bin/glewinfo

clean:
	$(RM) $(LIB.OBJS) $(LIB) $(BIN.OBJS) $(BIN)
