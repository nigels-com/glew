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

#include <stdio.h>
#include <string.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/wglew.h>
#include <GL/glxew.h>

static FILE* f;

static void glewPrintExt (const GLubyte* name, GLint defined)
{
  unsigned int i;
  fprintf(f, "\n%s:", name);
  for (i=0; i<62-strlen((const char*)name); i++) fprintf(f, " ");
  fprintf(f, "%s\n", defined ? "OK" : "MISSING");
  for (i=0; i<strlen((const char*)name)+1; i++) fprintf(f, "-");
  fprintf(f, "\n");
  fflush(f);
}

static void glewInfoFunc (const GLubyte* name, GLint undefined)
{
  unsigned int i;
  fprintf(f, "  %s:", name);
  for (i=0; i<60-strlen((const char*)name); i++) fprintf(f, " ");
  fprintf(f, "%s\n", undefined ? "MISSING" : "OK");
  fflush(f);
}

/* ----------------------------- GL_VERSION_1_1 ---------------------------- */

#ifdef GL_VERSION_1_1

static void _glewInfo_GL_VERSION_1_1 (void)
{
  glewPrintExt("GL_VERSION_1_1", GLEW_VERSION_1_1);
}

#endif /* GL_VERSION_1_1 */

