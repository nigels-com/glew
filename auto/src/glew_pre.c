/*
** The OpenGL Extension Wrangler Library
** Copyright (C) 2004, 2003, 2002, Milan Ikits <milan ikits[at]ieee org>
** Copyright (C) 2004, 2003, 2002, Marcelo E. Magallon <mmagallo[at]debian org>
** Copyright (C) 2002, Lev Povalahev
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
#if defined(_WIN32)
#  include <GL/wglew.h>
#elif !defined(__APPLE__) || defined(GLEW_APPLE_GLX)
#  include <GL/glxew.h>
#endif

#if defined(_WIN32)
#  define glewGetProcAddress(name) wglGetProcAddress((LPCSTR)name)
#else
#  if defined(__APPLE__)
#    define glewGetProcAddress(name) NSGLGetProcAddress(name)
#  else
#    if defined(__sgi) || defined(__sun)
#      define glewGetProcAddress(name) dlGetProcAddress(name)
#    else /* __linux */
#      define glewGetProcAddress(name) (*glXGetProcAddressARB)(name)
#    endif
#  endif
#endif

#if defined(__APPLE__)
#include <mach-o/dyld.h>
#include <stdlib.h>
#include <string.h>

static void *NSGLGetProcAddress (const GLubyte *name)
{
  NSSymbol symbol;
  char *symbolName;
  /* prepend a '_' for the Unix C symbol mangling convention */
  symbolName = malloc(strlen((const char *)name) + 2);
  strcpy(symbolName+1, (const char *)name);
  symbolName[0] = '_';
  symbol = NULL;
  if (NSIsSymbolNameDefined(symbolName))
    symbol = NSLookupAndBindSymbol(symbolName);
  free(symbolName);
  return symbol ? NSAddressOfSymbol(symbol) : NULL;
}
#endif /* __APPLE__ */

#if defined(__sgi) || defined (__sun)
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

static void *dlGetProcAddress (const GLubyte* name)
{
  static void *h = NULL;
  static void *gpa;

  if (h == NULL)
  {
    if ((h = dlopen(NULL, RTLD_LAZY | RTLD_LOCAL)) == NULL) return NULL;
    gpa = dlsym(h, "glXGetProcAddress");
  }

  if (gpa != NULL)
    return ((void *(*)(const GLubyte *))gpa)(name);
  else
    return dlsym(h, (const char *)name);
}
#endif /* __sgi || __sun */

#ifdef GLEW_MX
#define glewGetContext() ctx
#define wglewGetContext() ctx
#define glxewGetContext() ctx
#ifdef _WIN32
#define GLEW_CONTEXT_ARG_DEF_INIT GLEWContext* ctx
#define WGLEW_CONTEXT_ARG_DEF_INIT WGLEWContext* ctx
#define GLXEW_CONTEXT_ARG_DEF_INIT GLXEWContext* ctx
#define GLEW_CONTEXT_ARG_VAR_INIT ctx
#else
#define GLEW_CONTEXT_ARG_DEF_INIT void
#define WGLEW_CONTEXT_ARG_DEF_INIT void
#define GLXEW_CONTEXT_ARG_DEF_INIT void
#define GLEW_CONTEXT_ARG_VAR_INIT
#endif
#define GLEW_CONTEXT_ARG_DEF_LIST GLEWContext* ctx
#define WGLEW_CONTEXT_ARG_DEF_LIST WGLEWContext* ctx
#define GLXEW_CONTEXT_ARG_DEF_LIST GLXEWContext* ctx
#else
#define GLEW_CONTEXT_ARG_DEF_INIT void
#define WGLEW_CONTEXT_ARG_DEF_INIT void
#define GLXEW_CONTEXT_ARG_DEF_INIT void
#define GLEW_CONTEXT_ARG_DEF_LIST void
#define WGLEW_CONTEXT_ARG_DEF_LIST void
#define GLXEW_CONTEXT_ARG_DEF_LIST void
#define GLEW_CONTEXT_ARG_VAR_INIT
#endif

#if !defined(_WIN32) || !defined(GLEW_MX)

GLboolean __GLEW_VERSION_1_1 = GL_FALSE;
GLboolean __GLXEW_VERSION_1_0 = GL_FALSE;
GLboolean __GLXEW_VERSION_1_1 = GL_FALSE;

