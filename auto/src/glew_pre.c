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
#include <GL/wglew.h>
#include <GL/glxew.h>

#ifdef _WIN32
#  define glewGetProcAddress(name) wglGetProcAddress(name)
#else
#  ifdef GLEW_NEEDS_CUSTOM_GET_PROCADDRESS
#    define glewGetProcAddress(name) __dlopenGetProcAddress(name)
#  else
#    define glewGetProcAddress(name) (*glXGetProcAddressARB)(name)
#  endif /* GLEW_NEEDS_CUSTOM_GET_PROCADDRESS */
#endif /* _WIN32 */

#ifdef GLEW_NEEDS_CUSTOM_GET_PROCADDRESS
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

static void* __dlopenGetProcAddress (const GLubyte *procName)
{
  static void *h = NULL;
  static void *gpa;

  if (!h)
  {
    if (!(h = dlopen(NULL, RTLD_LAZY | RTLD_LOCAL))) return NULL;
    gpa = dlsym(h, "glXGetProcAddress");
  }

  if (gpa != NULL)
    return ((void* (*)(const GLubyte*))gpa)(procName);
  else
    return dlsym(h, (const char *)procName);
}
#endif /* GLEW_NEEDS_CUSTOM_GET_PROCADDRESS */

/* ----------------------------- GL_VERSION_1_1 ---------------------------- */

#ifdef GL_VERSION_1_1

GLboolean GLEW_VERSION_1_1 = GL_FALSE;

#endif /* GL_VERSION_1_1 */

