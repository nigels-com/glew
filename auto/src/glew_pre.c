/*
** The OpenGL Extension Wrangler Library
** Copyright (C) 2003, 2002, Milan Ikits <milan.ikits@ieee.org>
** Copyright (C) 2003, 2002, Marcelo E. Magallon <mmagallo@debian.org>
** Copyright (C) 2002, Lev Povalahev <levp@gmx.net>
** All rights reserved.
** 
** Redistribution and use in source and binary forms, with or without 
** modification, are permitted provided that the following conditions are met:
** 
** * Redistributions of source code must retain the above copyright notice, 
**   this list of conditions and the following disclaimer.
** * Redistributions in binary form must reproduce the above copyright notice, 
**   this list of conditions and the following disclaimer in the documentation 
**   and/or other materials provided with the distribution.
** * The name of the author may be used to endorse or promote products 
**   derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
** ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
** LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
** CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
** SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
** INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
** CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
** THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <GL/glew.h>
#ifdef _WIN32
#include <GL/wglew.h>
#else
#include <GL/glxew.h>
#endif

#ifdef _WIN32
#  define glewGetProcAddress(name) wglGetProcAddress(name)
#else
#  ifdef __APPLE__
#    define glewGetProcAddress(name) NSGLGetProcAddress(name)
#  else
#    ifdef __sgi
#      define glewGetProcAddress(name) dlGetProcAddress(name)
#    else /* __linux */
#      define glewGetProcAddress(name) (*glXGetProcAddressARB)(name)
#    endif
#  endif
#endif

#ifdef __APPLE__
#include <mach-o/dyld.h>
#include <stdlib.h>
#include <string.h>

static void* NSGLGetProcAddress (const char* name)
{
  NSSymbol symbol;
  char* symbolName;
  /* prepend a '_' for the Unix C symbol mangling convention */
  symbolName = malloc(strlen(name) + 2);
  strcpy(symbolName+1, name);
  symbolName[0] = '_';
  symbol = NULL;
  if (NSIsSymbolNameDefined(symbolName))
    symbol = NSLookupAndBindSymbol(symbolName);
  free(symbolName);
  return symbol ? NSAddressOfSymbol(symbol) : NULL;
}
#endif /* __APPLE__ */

#ifdef __sgi
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

static void* dlGetProcAddress (const char* name)
{
  static void* h = NULL;
  static void *gpa;

  if (h == NULL)
  {
    if ((h = dlopen(NULL, RTLD_LAZY | RTLD_LOCAL)) == NULL) return NULL;
    gpa = dlsym(h, "glXGetProcAddress");
  }

  if (gpa != NULL)
    return ((void* (*)(const GLubyte*))gpa)(procName);
  else
    return dlsym(h, name);
}
#endif /* __sgi */

/* ----------------------------- GL_VERSION_1_1 ---------------------------- */

#ifdef GL_VERSION_1_1

GLboolean GLEW_VERSION_1_1 = GL_FALSE;

#endif /* GL_VERSION_1_1 */

