/*
** License Applicability. Except to the extent portions of this file are
** made subject to an alternative license as permitted in the SGI Free
** Software License B, Version 1.1 (the "License"), the contents of this
** file are subject only to the provisions of the License. You may not use
** this file except in compliance with the License. You may obtain a copy
** of the License at Silicon Graphics, Inc., attn: Legal Services, 1600
** Amphitheatre Parkway, Mountain View, CA 94043-1351, or at:
** 
** http://oss.sgi.com/projects/FreeB
** 
** Note that, as provided in the License, the Software is distributed on an
** "AS IS" basis, with ALL EXPRESS AND IMPLIED WARRANTIES AND CONDITIONS
** DISCLAIMED, INCLUDING, WITHOUT LIMITATION, ANY IMPLIED WARRANTIES AND
** CONDITIONS OF MERCHANTABILITY, SATISFACTORY QUALITY, FITNESS FOR A
** PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
** 
** Original Code. The Original Code is: OpenGL Sample Implementation,
** Version 1.2.1, released January 26, 2000, developed by Silicon Graphics,
** Inc. The Original Code is Copyright (c) 1991-2000 Silicon Graphics, Inc.
** Copyright in any portions created by third parties is as indicated
** elsewhere herein. All Rights Reserved.
** 
** Additional Notice Provisions: This software was created using the
** OpenGL(R) version 1.2.1 Sample Implementation published by SGI, but has
** not been independently verified as being compliant with the OpenGL(R)
** version 1.2.1 Specification.
*/

/*
** The contents of this file are subject to the GLX Public License Version 1.0
** (the "License"). You may not use this file except in compliance with the
** License. You may obtain a copy of the License at Silicon Graphics, Inc.,
** attn: Legal Services, 2011 N. Shoreline Blvd., Mountain View, CA 94043
** or at http://www.sgi.com/software/opensource/glx/license.html.
**
** Software distributed under the License is distributed on an "AS IS"
** basis. ALL WARRANTIES ARE DISCLAIMED, INCLUDING, WITHOUT LIMITATION, ANY
** IMPLIED WARRANTIES OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR
** PURPOSE OR OF NON- INFRINGEMENT. See the License for the specific
** language governing rights and limitations under the License.
**
** The Original Software is GLX version 1.2 source code, released February,
** 1999. The developer of the Original Software is Silicon Graphics, Inc.
** Those portions of the Subject Software created by Silicon Graphics, Inc.
** are Copyright (c) 1991-9 Silicon Graphics, Inc. All Rights Reserved.
*/

/*
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

/*
** The OpenGL Extension Wrangler Library
** Copyright (C) 2002 Milan Ikits
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 2.1 of the License, or (at your option) any later version.
**
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Lesser General Public License for more details.
**
** You should have received a copy of the GNU Lesser General Public
** License along with this library; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include <GL/glew.h>
#include <GL/wglew.h>
#include <GL/glxew.h>

#ifdef _WIN32
#define glewGetProcAddress(name) wglGetProcAddress(name)
#else
#define glewGetProcAddress(name) (*glXGetProcAddressARB)(name)
#endif

/* ------------------------------ OpenGL 1.2 ------------------------------ */

#ifdef GL_VERSION_1_2
PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D = NULL;
PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements = NULL;
PFNGLTEXIMAGE3DPROC glTexImage3D = NULL;
PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D = NULL;

static GLboolean _glewInit_12 ()
{
  GLboolean r = GL_FALSE;
  r = r || (glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)glewGetProcAddress("glCopyTexSubImage3D")) == NULL;
  r = r || (glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)glewGetProcAddress("glDrawRangeElements")) == NULL;
  r = r || (glTexImage3D = (PFNGLTEXIMAGE3DPROC)glewGetProcAddress("glTexImage3D")) == NULL;
  r = r || (glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)glewGetProcAddress("glTexSubImage3D")) == NULL;
  return r;
}
#endif /* GL_VERSION_1_2 */

/* ------------------------------ OpenGL 1.3 ------------------------------ */

#ifdef GL_VERSION_1_3
PFNGLACTIVETEXTUREPROC glActiveTexture = NULL;
PFNGLCLIENTACTIVETEXTUREPROC glClientActiveTexture = NULL;
PFNGLMULTITEXCOORD1DPROC glMultiTexCoord1d = NULL;
PFNGLMULTITEXCOORD1DVPROC glMultiTexCoord1dv = NULL;
PFNGLMULTITEXCOORD1FPROC glMultiTexCoord1f = NULL;
PFNGLMULTITEXCOORD1FVPROC glMultiTexCoord1fv = NULL;
PFNGLMULTITEXCOORD1IPROC glMultiTexCoord1i = NULL;
PFNGLMULTITEXCOORD1IVPROC glMultiTexCoord1iv = NULL;
PFNGLMULTITEXCOORD1SPROC glMultiTexCoord1s = NULL;
PFNGLMULTITEXCOORD1SVPROC glMultiTexCoord1sv = NULL;
PFNGLMULTITEXCOORD2DPROC glMultiTexCoord2d = NULL;
PFNGLMULTITEXCOORD2DVPROC glMultiTexCoord2dv = NULL;
PFNGLMULTITEXCOORD2FPROC glMultiTexCoord2f = NULL;
PFNGLMULTITEXCOORD2FVPROC glMultiTexCoord2fv = NULL;
PFNGLMULTITEXCOORD2IPROC glMultiTexCoord2i = NULL;
PFNGLMULTITEXCOORD2IVPROC glMultiTexCoord2iv = NULL;
PFNGLMULTITEXCOORD2SPROC glMultiTexCoord2s = NULL;
PFNGLMULTITEXCOORD2SVPROC glMultiTexCoord2sv = NULL;
PFNGLMULTITEXCOORD3DPROC glMultiTexCoord3d = NULL;
PFNGLMULTITEXCOORD3DVPROC glMultiTexCoord3dv = NULL;
PFNGLMULTITEXCOORD3FPROC glMultiTexCoord3f = NULL;
PFNGLMULTITEXCOORD3FVPROC glMultiTexCoord3fv = NULL;
PFNGLMULTITEXCOORD3IPROC glMultiTexCoord3i = NULL;
PFNGLMULTITEXCOORD3IVPROC glMultiTexCoord3iv = NULL;
PFNGLMULTITEXCOORD3SPROC glMultiTexCoord3s = NULL;
PFNGLMULTITEXCOORD3SVPROC glMultiTexCoord3sv = NULL;
PFNGLMULTITEXCOORD4DPROC glMultiTexCoord4d = NULL;
PFNGLMULTITEXCOORD4DVPROC glMultiTexCoord4dv = NULL;
PFNGLMULTITEXCOORD4FPROC glMultiTexCoord4f = NULL;
PFNGLMULTITEXCOORD4FVPROC glMultiTexCoord4fv = NULL;
PFNGLMULTITEXCOORD4IPROC glMultiTexCoord4i = NULL;
PFNGLMULTITEXCOORD4IVPROC glMultiTexCoord4iv = NULL;
PFNGLMULTITEXCOORD4SPROC glMultiTexCoord4s = NULL;
PFNGLMULTITEXCOORD4SVPROC glMultiTexCoord4sv = NULL;
PFNGLLOADTRANSPOSEMATRIXFPROC glLoadTransposeMatrixf = NULL;
PFNGLLOADTRANSPOSEMATRIXDPROC glLoadTransposeMatrixd = NULL;
PFNGLMULTTRANSPOSEMATRIXFPROC glMultTransposeMatrixf = NULL;
PFNGLMULTTRANSPOSEMATRIXDPROC glMultTransposeMatrixd = NULL;
PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D = NULL;
PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D = NULL;
PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D = NULL;
PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage = NULL;
PFNGLSAMPLECOVERAGEPROC glSampleCoverage = NULL;

static GLboolean _glewInit_13 ()
{
  GLboolean r = GL_FALSE;
  r = r || (glActiveTexture = (PFNGLACTIVETEXTUREPROC)glewGetProcAddress("glActiveTexture")) == NULL;
  r = r || (glClientActiveTexture = (PFNGLCLIENTACTIVETEXTUREPROC)glewGetProcAddress("glClientActiveTexture")) == NULL;
  r = r || (glMultiTexCoord1d = (PFNGLMULTITEXCOORD1DPROC)glewGetProcAddress("glMultiTexCoord1d")) == NULL;
  r = r || (glMultiTexCoord1dv = (PFNGLMULTITEXCOORD1DVPROC)glewGetProcAddress("glMultiTexCoord1dv")) == NULL;
  r = r || (glMultiTexCoord1f = (PFNGLMULTITEXCOORD1FPROC)glewGetProcAddress("glMultiTexCoord1f")) == NULL;
  r = r || (glMultiTexCoord1fv = (PFNGLMULTITEXCOORD1FVPROC)glewGetProcAddress("glMultiTexCoord1fv")) == NULL;
  r = r || (glMultiTexCoord1i = (PFNGLMULTITEXCOORD1IPROC)glewGetProcAddress("glMultiTexCoord1i")) == NULL;
  r = r || (glMultiTexCoord1iv = (PFNGLMULTITEXCOORD1IVPROC)glewGetProcAddress("glMultiTexCoord1iv")) == NULL;
  r = r || (glMultiTexCoord1s = (PFNGLMULTITEXCOORD1SPROC)glewGetProcAddress("glMultiTexCoord1s")) == NULL;
  r = r || (glMultiTexCoord1sv = (PFNGLMULTITEXCOORD1SVPROC)glewGetProcAddress("glMultiTexCoord1sv")) == NULL;
  r = r || (glMultiTexCoord2d = (PFNGLMULTITEXCOORD2DPROC)glewGetProcAddress("glMultiTexCoord2d")) == NULL;
  r = r || (glMultiTexCoord2dv = (PFNGLMULTITEXCOORD2DVPROC)glewGetProcAddress("glMultiTexCoord2dv")) == NULL;
  r = r || (glMultiTexCoord2f = (PFNGLMULTITEXCOORD2FPROC)glewGetProcAddress("glMultiTexCoord2f")) == NULL;
  r = r || (glMultiTexCoord2fv = (PFNGLMULTITEXCOORD2FVPROC)glewGetProcAddress("glMultiTexCoord2fv")) == NULL;
  r = r || (glMultiTexCoord2i = (PFNGLMULTITEXCOORD2IPROC)glewGetProcAddress("glMultiTexCoord2i")) == NULL;
  r = r || (glMultiTexCoord2iv = (PFNGLMULTITEXCOORD2IVPROC)glewGetProcAddress("glMultiTexCoord2iv")) == NULL;
  r = r || (glMultiTexCoord2s = (PFNGLMULTITEXCOORD2SPROC)glewGetProcAddress("glMultiTexCoord2s")) == NULL;
  r = r || (glMultiTexCoord2sv = (PFNGLMULTITEXCOORD2SVPROC)glewGetProcAddress("glMultiTexCoord2sv")) == NULL;
  r = r || (glMultiTexCoord3d = (PFNGLMULTITEXCOORD3DPROC)glewGetProcAddress("glMultiTexCoord3d")) == NULL;
  r = r || (glMultiTexCoord3dv = (PFNGLMULTITEXCOORD3DVPROC)glewGetProcAddress("glMultiTexCoord3dv")) == NULL;
  r = r || (glMultiTexCoord3f = (PFNGLMULTITEXCOORD3FPROC)glewGetProcAddress("glMultiTexCoord3f")) == NULL;
  r = r || (glMultiTexCoord3fv = (PFNGLMULTITEXCOORD3FVPROC)glewGetProcAddress("glMultiTexCoord3fv")) == NULL;
  r = r || (glMultiTexCoord3i = (PFNGLMULTITEXCOORD3IPROC)glewGetProcAddress("glMultiTexCoord3i")) == NULL;
  r = r || (glMultiTexCoord3iv = (PFNGLMULTITEXCOORD3IVPROC)glewGetProcAddress("glMultiTexCoord3iv")) == NULL;
  r = r || (glMultiTexCoord3s = (PFNGLMULTITEXCOORD3SPROC)glewGetProcAddress("glMultiTexCoord3s")) == NULL;
  r = r || (glMultiTexCoord3sv = (PFNGLMULTITEXCOORD3SVPROC)glewGetProcAddress("glMultiTexCoord3sv")) == NULL;
  r = r || (glMultiTexCoord4d = (PFNGLMULTITEXCOORD4DPROC)glewGetProcAddress("glMultiTexCoord4d")) == NULL;
  r = r || (glMultiTexCoord4dv = (PFNGLMULTITEXCOORD4DVPROC)glewGetProcAddress("glMultiTexCoord4dv")) == NULL;
  r = r || (glMultiTexCoord4f = (PFNGLMULTITEXCOORD4FPROC)glewGetProcAddress("glMultiTexCoord4f")) == NULL;
  r = r || (glMultiTexCoord4fv = (PFNGLMULTITEXCOORD4FVPROC)glewGetProcAddress("glMultiTexCoord4fv")) == NULL;
  r = r || (glMultiTexCoord4i = (PFNGLMULTITEXCOORD4IPROC)glewGetProcAddress("glMultiTexCoord4i")) == NULL;
  r = r || (glMultiTexCoord4iv = (PFNGLMULTITEXCOORD4IVPROC)glewGetProcAddress("glMultiTexCoord4iv")) == NULL;
  r = r || (glMultiTexCoord4s = (PFNGLMULTITEXCOORD4SPROC)glewGetProcAddress("glMultiTexCoord4s")) == NULL;
  r = r || (glMultiTexCoord4sv = (PFNGLMULTITEXCOORD4SVPROC)glewGetProcAddress("glMultiTexCoord4sv")) == NULL;
  r = r || (glLoadTransposeMatrixf = (PFNGLLOADTRANSPOSEMATRIXFPROC)glewGetProcAddress("glLoadTransposeMatrixf")) == NULL;
  r = r || (glLoadTransposeMatrixd = (PFNGLLOADTRANSPOSEMATRIXDPROC)glewGetProcAddress("glLoadTransposeMatrixd")) == NULL;
  r = r || (glMultTransposeMatrixf = (PFNGLMULTTRANSPOSEMATRIXFPROC)glewGetProcAddress("glMultTransposeMatrixf")) == NULL;
  r = r || (glMultTransposeMatrixd = (PFNGLMULTTRANSPOSEMATRIXDPROC)glewGetProcAddress("glMultTransposeMatrixd")) == NULL;
  r = r || (glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)glewGetProcAddress("glCompressedTexImage3D")) == NULL;
  r = r || (glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)glewGetProcAddress("glCompressedTexImage2D")) == NULL;
  r = r || (glCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)glewGetProcAddress("glCompressedTexImage1D")) == NULL;
  r = r || (glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)glewGetProcAddress("glCompressedTexSubImage3D")) == NULL;
  r = r || (glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)glewGetProcAddress("glCompressedTexSubImage2D")) == NULL;
  r = r || (glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)glewGetProcAddress("glCompressedTexSubImage1D")) == NULL;
  r = r || (glGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)glewGetProcAddress("glGetCompressedTexImage")) == NULL;
  r = r || (glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)glewGetProcAddress("glSampleCoverage")) == NULL;
  return r;
}
#endif /* GL_VERSION_1_3 */

/* ------------------------------ OpenGL 1.4 ------------------------------ */

#ifdef GL_VERSION_1_4
#ifndef GL_ARB_imaging
PFNGLBLENDCOLORPROC glBlendColor = NULL;
PFNGLBLENDEQUATIONPROC glBlendEquation = NULL;
#endif /* GL_ARB_imaging */
PFNGLFOGCOORDFPROC glFogCoordf = NULL;
PFNGLFOGCOORDFVPROC glFogCoordfv = NULL;
PFNGLFOGCOORDDPROC glFogCoordd = NULL;
PFNGLFOGCOORDDVPROC glFogCoorddv = NULL;
PFNGLFOGCOORDPOINTERPROC glFogCoordPointer = NULL;
PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays = NULL;
PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements = NULL;
PFNGLPOINTPARAMETERFPROC glPointParameterf = NULL;
PFNGLPOINTPARAMETERFVPROC glPointParameterfv = NULL;
PFNGLSECONDARYCOLOR3BPROC glSecondaryColor3b = NULL;
PFNGLSECONDARYCOLOR3BVPROC glSecondaryColor3bv = NULL;
PFNGLSECONDARYCOLOR3DPROC glSecondaryColor3d = NULL;
PFNGLSECONDARYCOLOR3DVPROC glSecondaryColor3dv = NULL;
PFNGLSECONDARYCOLOR3FPROC glSecondaryColor3f = NULL;
PFNGLSECONDARYCOLOR3FVPROC glSecondaryColor3fv = NULL;
PFNGLSECONDARYCOLOR3IPROC glSecondaryColor3i = NULL;
PFNGLSECONDARYCOLOR3IVPROC glSecondaryColor3iv = NULL;
PFNGLSECONDARYCOLOR3SPROC glSecondaryColor3s = NULL;
PFNGLSECONDARYCOLOR3SVPROC glSecondaryColor3sv = NULL;
PFNGLSECONDARYCOLOR3UBPROC glSecondaryColor3ub = NULL;
PFNGLSECONDARYCOLOR3UBVPROC glSecondaryColor3ubv = NULL;
PFNGLSECONDARYCOLOR3UIPROC glSecondaryColor3ui = NULL;
PFNGLSECONDARYCOLOR3UIVPROC glSecondaryColor3uiv = NULL;
PFNGLSECONDARYCOLOR3USPROC glSecondaryColor3us = NULL;
PFNGLSECONDARYCOLOR3USVPROC glSecondaryColor3usv = NULL;
PFNGLSECONDARYCOLORPOINTERPROC glSecondaryColorPointer = NULL;
PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate = NULL;
PFNGLWINDOWPOS2DPROC glWindowPos2d = NULL;
PFNGLWINDOWPOS2FPROC glWindowPos2f = NULL;
PFNGLWINDOWPOS2IPROC glWindowPos2i = NULL;
PFNGLWINDOWPOS2SPROC glWindowPos2s = NULL;
PFNGLWINDOWPOS2DVPROC glWindowPos2dv = NULL;
PFNGLWINDOWPOS2FVPROC glWindowPos2fv = NULL;
PFNGLWINDOWPOS2IVPROC glWindowPos2iv = NULL;
PFNGLWINDOWPOS2SVPROC glWindowPos2sv = NULL;
PFNGLWINDOWPOS3DPROC glWindowPos3d = NULL;
PFNGLWINDOWPOS3FPROC glWindowPos3f = NULL;
PFNGLWINDOWPOS3IPROC glWindowPos3i = NULL;
PFNGLWINDOWPOS3SPROC glWindowPos3s = NULL;
PFNGLWINDOWPOS3DVPROC glWindowPos3dv = NULL;
PFNGLWINDOWPOS3FVPROC glWindowPos3fv = NULL;
PFNGLWINDOWPOS3IVPROC glWindowPos3iv = NULL;
PFNGLWINDOWPOS3SVPROC glWindowPos3sv = NULL;

static GLboolean _glewInit_14 ()
{
  GLboolean r = GL_FALSE;
#ifndef GL_ARB_imaging
  r = r || (glBlendColor = (PFNGLBLENDCOLORPROC)glewGetProcAddress("glBlendColor")) == NULL;
  r = r || (glBlendEquation = (PFNGLBLENDEQUATIONPROC)glewGetProcAddress("glBlendEquation")) == NULL;
#endif /* GL_ARB_imaging */
  r = r || (glFogCoordf = (PFNGLFOGCOORDFPROC)glewGetProcAddress("glFogCoordf")) == NULL;
  r = r || (glFogCoordfv = (PFNGLFOGCOORDFVPROC)glewGetProcAddress("glFogCoordfv")) == NULL;
  r = r || (glFogCoordd = (PFNGLFOGCOORDDPROC)glewGetProcAddress("glFogCoordd")) == NULL;
  r = r || (glFogCoorddv = (PFNGLFOGCOORDDVPROC)glewGetProcAddress("glFogCoorddv")) == NULL;
  r = r || (glFogCoordPointer = (PFNGLFOGCOORDPOINTERPROC)glewGetProcAddress("glFogCoordPointer")) == NULL;
  r = r || (glMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC)glewGetProcAddress("glMultiDrawArrays")) == NULL;
  r = r || (glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC)glewGetProcAddress("glMultiDrawElements")) == NULL;
  r = r || (glPointParameterf = (PFNGLPOINTPARAMETERFPROC)glewGetProcAddress("glPointParameterf")) == NULL;
  r = r || (glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC)glewGetProcAddress("glPointParameterfv")) == NULL;
  r = r || (glSecondaryColor3b = (PFNGLSECONDARYCOLOR3BPROC)glewGetProcAddress("glSecondaryColor3b")) == NULL;
  r = r || (glSecondaryColor3bv = (PFNGLSECONDARYCOLOR3BVPROC)glewGetProcAddress("glSecondaryColor3bv")) == NULL;
  r = r || (glSecondaryColor3d = (PFNGLSECONDARYCOLOR3DPROC)glewGetProcAddress("glSecondaryColor3d")) == NULL;
  r = r || (glSecondaryColor3dv = (PFNGLSECONDARYCOLOR3DVPROC)glewGetProcAddress("glSecondaryColor3dv")) == NULL;
  r = r || (glSecondaryColor3f = (PFNGLSECONDARYCOLOR3FPROC)glewGetProcAddress("glSecondaryColor3f")) == NULL;
  r = r || (glSecondaryColor3fv = (PFNGLSECONDARYCOLOR3FVPROC)glewGetProcAddress("glSecondaryColor3fv")) == NULL;
  r = r || (glSecondaryColor3i = (PFNGLSECONDARYCOLOR3IPROC)glewGetProcAddress("glSecondaryColor3i")) == NULL;
  r = r || (glSecondaryColor3iv = (PFNGLSECONDARYCOLOR3IVPROC)glewGetProcAddress("glSecondaryColor3iv")) == NULL;
  r = r || (glSecondaryColor3s = (PFNGLSECONDARYCOLOR3SPROC)glewGetProcAddress("glSecondaryColor3s")) == NULL;
  r = r || (glSecondaryColor3sv = (PFNGLSECONDARYCOLOR3SVPROC)glewGetProcAddress("glSecondaryColor3sv")) == NULL;
  r = r || (glSecondaryColor3ub = (PFNGLSECONDARYCOLOR3UBPROC)glewGetProcAddress("glSecondaryColor3ub")) == NULL;
  r = r || (glSecondaryColor3ubv = (PFNGLSECONDARYCOLOR3UBVPROC)glewGetProcAddress("glSecondaryColor3ubv")) == NULL;
  r = r || (glSecondaryColor3ui = (PFNGLSECONDARYCOLOR3UIPROC)glewGetProcAddress("glSecondaryColor3ui")) == NULL;
  r = r || (glSecondaryColor3uiv = (PFNGLSECONDARYCOLOR3UIVPROC)glewGetProcAddress("glSecondaryColor3uiv")) == NULL;
  r = r || (glSecondaryColor3us = (PFNGLSECONDARYCOLOR3USPROC)glewGetProcAddress("glSecondaryColor3us")) == NULL;
  r = r || (glSecondaryColor3usv = (PFNGLSECONDARYCOLOR3USVPROC)glewGetProcAddress("glSecondaryColor3usv")) == NULL;
  r = r || (glSecondaryColorPointer = (PFNGLSECONDARYCOLORPOINTERPROC)glewGetProcAddress("glSecondaryColorPointer")) == NULL;
  r = r || (glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)glewGetProcAddress("glBlendFuncSeparate")) == NULL;
  r = r || (glWindowPos2d = (PFNGLWINDOWPOS2DPROC)glewGetProcAddress("glWindowPos2d")) == NULL;
  r = r || (glWindowPos2f = (PFNGLWINDOWPOS2FPROC)glewGetProcAddress("glWindowPos2f")) == NULL;
  r = r || (glWindowPos2i = (PFNGLWINDOWPOS2IPROC)glewGetProcAddress("glWindowPos2i")) == NULL;
  r = r || (glWindowPos2s = (PFNGLWINDOWPOS2SPROC)glewGetProcAddress("glWindowPos2s")) == NULL;
  r = r || (glWindowPos2dv = (PFNGLWINDOWPOS2DVPROC)glewGetProcAddress("glWindowPos2dv")) == NULL;
  r = r || (glWindowPos2fv = (PFNGLWINDOWPOS2FVPROC)glewGetProcAddress("glWindowPos2fv")) == NULL;
  r = r || (glWindowPos2iv = (PFNGLWINDOWPOS2IVPROC)glewGetProcAddress("glWindowPos2iv")) == NULL;
  r = r || (glWindowPos2sv = (PFNGLWINDOWPOS2SVPROC)glewGetProcAddress("glWindowPos2sv")) == NULL;
  r = r || (glWindowPos3d = (PFNGLWINDOWPOS3DPROC)glewGetProcAddress("glWindowPos3d")) == NULL;
  r = r || (glWindowPos3f = (PFNGLWINDOWPOS3FPROC)glewGetProcAddress("glWindowPos3f")) == NULL;
  r = r || (glWindowPos3i = (PFNGLWINDOWPOS3IPROC)glewGetProcAddress("glWindowPos3i")) == NULL;
  r = r || (glWindowPos3s = (PFNGLWINDOWPOS3SPROC)glewGetProcAddress("glWindowPos3s")) == NULL;
  r = r || (glWindowPos3dv = (PFNGLWINDOWPOS3DVPROC)glewGetProcAddress("glWindowPos3dv")) == NULL;
  r = r || (glWindowPos3fv = (PFNGLWINDOWPOS3FVPROC)glewGetProcAddress("glWindowPos3fv")) == NULL;
  r = r || (glWindowPos3iv = (PFNGLWINDOWPOS3IVPROC)glewGetProcAddress("glWindowPos3iv")) == NULL;
  r = r || (glWindowPos3sv = (PFNGLWINDOWPOS3SVPROC)glewGetProcAddress("glWindowPos3sv")) == NULL;
  return r;
}
#endif /* GL_VERSION_1_4 */

/* ------------------------------ ARB_imaging ----------------------------- */

#ifdef GL_ARB_imaging
PFNGLBLENDCOLORPROC glBlendColor = NULL;
PFNGLBLENDEQUATIONPROC glBlendEquation = NULL;
PFNGLCOLORTABLEPROC glColorTable = NULL;
PFNGLCOLORTABLEPARAMETERFVPROC glColorTableParameterfv = NULL;
PFNGLCOLORTABLEPARAMETERIVPROC glColorTableParameteriv = NULL;
PFNGLCOPYCOLORTABLEPROC glCopyColorTable = NULL;
PFNGLGETCOLORTABLEPROC glGetColorTable = NULL;
PFNGLGETCOLORTABLEPARAMETERFVPROC glGetColorTableParameterfv = NULL;
PFNGLGETCOLORTABLEPARAMETERIVPROC glGetColorTableParameteriv = NULL;
PFNGLCOLORSUBTABLEPROC glColorSubTable = NULL;
PFNGLCOPYCOLORSUBTABLEPROC glCopyColorSubTable = NULL;
PFNGLCONVOLUTIONFILTER1DPROC glConvolutionFilter1D = NULL;
PFNGLCONVOLUTIONFILTER2DPROC glConvolutionFilter2D = NULL;
PFNGLCONVOLUTIONPARAMETERFPROC glConvolutionParameterf = NULL;
PFNGLCONVOLUTIONPARAMETERFVPROC glConvolutionParameterfv = NULL;
PFNGLCONVOLUTIONPARAMETERIPROC glConvolutionParameteri = NULL;
PFNGLCONVOLUTIONPARAMETERIVPROC glConvolutionParameteriv = NULL;
PFNGLCOPYCONVOLUTIONFILTER1DPROC glCopyConvolutionFilter1D = NULL;
PFNGLCOPYCONVOLUTIONFILTER2DPROC glCopyConvolutionFilter2D = NULL;
PFNGLGETCONVOLUTIONFILTERPROC glGetConvolutionFilter = NULL;
PFNGLGETCONVOLUTIONPARAMETERFVPROC glGetConvolutionParameterfv = NULL;
PFNGLGETCONVOLUTIONPARAMETERIVPROC glGetConvolutionParameteriv = NULL;
PFNGLGETSEPARABLEFILTERPROC glGetSeparableFilter = NULL;
PFNGLSEPARABLEFILTER2DPROC glSeparableFilter2D = NULL;
PFNGLGETHISTOGRAMPROC glGetHistogram = NULL;
PFNGLGETHISTOGRAMPARAMETERFVPROC glGetHistogramParameterfv = NULL;
PFNGLGETHISTOGRAMPARAMETERIVPROC glGetHistogramParameteriv = NULL;
PFNGLGETMINMAXPROC glGetMinmax = NULL;
PFNGLGETMINMAXPARAMETERFVPROC glGetMinmaxParameterfv = NULL;
PFNGLGETMINMAXPARAMETERIVPROC glGetMinmaxParameteriv = NULL;
PFNGLHISTOGRAMPROC glHistogram = NULL;
PFNGLMINMAXPROC glMinmax = NULL;
PFNGLRESETHISTOGRAMPROC glResetHistogram = NULL;
PFNGLRESETMINMAXPROC glResetMinmax = NULL;

static GLboolean _glewInit_ARB_imaging ()
{
  GLboolean r = GL_FALSE;
  r = r || (glBlendColor = (PFNGLBLENDCOLORPROC)glewGetProcAddress("glBlendColor")) == NULL;
  r = r || (glBlendEquation = (PFNGLBLENDEQUATIONPROC)glewGetProcAddress("glBlendEquation")) == NULL;
  r = r || (glColorTable = (PFNGLCOLORTABLEPROC)glewGetProcAddress("glColorTable")) == NULL;
  r = r || (glColorTableParameterfv = (PFNGLCOLORTABLEPARAMETERFVPROC)glewGetProcAddress("glColorTableParameterfv")) == NULL;
  r = r || (glColorTableParameteriv = (PFNGLCOLORTABLEPARAMETERIVPROC)glewGetProcAddress("glColorTableParameteriv")) == NULL;
  r = r || (glCopyColorTable = (PFNGLCOPYCOLORTABLEPROC)glewGetProcAddress("glCopyColorTable")) == NULL;
  r = r || (glGetColorTable = (PFNGLGETCOLORTABLEPROC)glewGetProcAddress("glGetColorTable")) == NULL;
  r = r || (glGetColorTableParameterfv = (PFNGLGETCOLORTABLEPARAMETERFVPROC)glewGetProcAddress("glGetColorTableParameterfv")) == NULL;
  r = r || (glGetColorTableParameteriv = (PFNGLGETCOLORTABLEPARAMETERIVPROC)glewGetProcAddress("glGetColorTableParameteriv")) == NULL;
  r = r || (glColorSubTable = (PFNGLCOLORSUBTABLEPROC)glewGetProcAddress("glColorSubTable")) == NULL;
  r = r || (glCopyColorSubTable = (PFNGLCOPYCOLORSUBTABLEPROC)glewGetProcAddress("glCopyColorSubTable")) == NULL;
  r = r || (glConvolutionFilter1D = (PFNGLCONVOLUTIONFILTER1DPROC)glewGetProcAddress("glConvolutionFilter1D")) == NULL;
  r = r || (glConvolutionFilter2D = (PFNGLCONVOLUTIONFILTER2DPROC)glewGetProcAddress("glConvolutionFilter2D")) == NULL;
  r = r || (glConvolutionParameterf = (PFNGLCONVOLUTIONPARAMETERFPROC)glewGetProcAddress("glConvolutionParameterf")) == NULL;
  r = r || (glConvolutionParameterfv = (PFNGLCONVOLUTIONPARAMETERFVPROC)glewGetProcAddress("glConvolutionParameterfv")) == NULL;
  r = r || (glConvolutionParameteri = (PFNGLCONVOLUTIONPARAMETERIPROC)glewGetProcAddress("glConvolutionParameteri")) == NULL;
  r = r || (glConvolutionParameteriv = (PFNGLCONVOLUTIONPARAMETERIVPROC)glewGetProcAddress("glConvolutionParameteriv")) == NULL;
  r = r || (glCopyConvolutionFilter1D = (PFNGLCOPYCONVOLUTIONFILTER1DPROC)glewGetProcAddress("glCopyConvolutionFilter1D")) == NULL;
  r = r || (glCopyConvolutionFilter2D = (PFNGLCOPYCONVOLUTIONFILTER2DPROC)glewGetProcAddress("glCopyConvolutionFilter2D")) == NULL;
  r = r || (glGetConvolutionFilter = (PFNGLGETCONVOLUTIONFILTERPROC)glewGetProcAddress("glGetConvolutionFilter")) == NULL;
  r = r || (glGetConvolutionParameterfv = (PFNGLGETCONVOLUTIONPARAMETERFVPROC)glewGetProcAddress("glGetConvolutionParameterfv")) == NULL;
  r = r || (glGetConvolutionParameteriv = (PFNGLGETCONVOLUTIONPARAMETERIVPROC)glewGetProcAddress("glGetConvolutionParameteriv")) == NULL;
  r = r || (glGetSeparableFilter = (PFNGLGETSEPARABLEFILTERPROC)glewGetProcAddress("glGetSeparableFilter")) == NULL;
  r = r || (glSeparableFilter2D = (PFNGLSEPARABLEFILTER2DPROC)glewGetProcAddress("glSeparableFilter2D")) == NULL;
  r = r || (glGetHistogram = (PFNGLGETHISTOGRAMPROC)glewGetProcAddress("glGetHistogram")) == NULL;
  r = r || (glGetHistogramParameterfv = (PFNGLGETHISTOGRAMPARAMETERFVPROC)glewGetProcAddress("glGetHistogramParameterfv")) == NULL;
  r = r || (glGetHistogramParameteriv = (PFNGLGETHISTOGRAMPARAMETERIVPROC)glewGetProcAddress("glGetHistogramParameteriv")) == NULL;
  r = r || (glGetMinmax = (PFNGLGETMINMAXPROC)glewGetProcAddress("glGetMinmax")) == NULL;
  r = r || (glGetMinmaxParameterfv = (PFNGLGETMINMAXPARAMETERFVPROC)glewGetProcAddress("glGetMinmaxParameterfv")) == NULL;
  r = r || (glGetMinmaxParameteriv = (PFNGLGETMINMAXPARAMETERIVPROC)glewGetProcAddress("glGetMinmaxParameteriv")) == NULL;
  r = r || (glHistogram = (PFNGLHISTOGRAMPROC)glewGetProcAddress("glHistogram")) == NULL;
  r = r || (glMinmax = (PFNGLMINMAXPROC)glewGetProcAddress("glMinmax")) == NULL;
  r = r || (glResetHistogram = (PFNGLRESETHISTOGRAMPROC)glewGetProcAddress("glResetHistogram")) == NULL;
  r = r || (glResetMinmax = (PFNGLRESETMINMAXPROC)glewGetProcAddress("glResetMinmax")) == NULL;
  return r;
}
#endif /* GL_ARB_imaging */

/* -------------------------- ARB_matrix_palette -------------------------- */

#ifdef GL_ARB_matrix_palette
PFNGLCURRENTPALETTEMATRIXARBPROC glCurrentPaletteMatrixARB = NULL;
PFNGLMATRIXINDEXUBVARBPROC glMatrixIndexubvARB = NULL;
PFNGLMATRIXINDEXUSVARBPROC glMatrixIndexusvARB = NULL;
PFNGLMATRIXINDEXUIVARBPROC glMatrixIndexuivARB = NULL;
PFNGLMATRIXINDEXPOINTERARBPROC glMatrixIndexPointerARB = NULL;

static GLboolean _glewInit_ARB_matrix_palette ()
{
  GLboolean r = GL_FALSE;
  r = r || (glCurrentPaletteMatrixARB = (PFNGLCURRENTPALETTEMATRIXARBPROC)glewGetProcAddress("glCurrentPaletteMatrixARB")) == NULL;
  r = r || (glMatrixIndexubvARB = (PFNGLMATRIXINDEXUBVARBPROC)glewGetProcAddress("glMatrixIndexubvARB")) == NULL;
  r = r || (glMatrixIndexusvARB = (PFNGLMATRIXINDEXUSVARBPROC)glewGetProcAddress("glMatrixIndexusvARB")) == NULL;
  r = r || (glMatrixIndexuivARB = (PFNGLMATRIXINDEXUIVARBPROC)glewGetProcAddress("glMatrixIndexuivARB")) == NULL;
  r = r || (glMatrixIndexPointerARB = (PFNGLMATRIXINDEXPOINTERARBPROC)glewGetProcAddress("glMatrixIndexPointerARB")) == NULL;
  return r;
}
#endif /* GL_ARB_matrix_palette */

/* ---------------------------- ARB_multisample --------------------------- */

#ifdef GL_ARB_multisample
PFNGLSAMPLECOVERAGEARBPROC glSampleCoverageARB = NULL;

static GLboolean _glewInit_ARB_multisample ()
{
  GLboolean r = GL_FALSE;
  r = r || (glSampleCoverageARB = (PFNGLSAMPLECOVERAGEARBPROC)glewGetProcAddress("glSampleCoverageARB")) == NULL;
  return r;
}
#endif /* GL_ARB_multisample */

/* --------------------------- ARB_multitexture --------------------------- */

#ifdef GL_ARB_multitexture
PFNGLACTIVETEXTUREARBPROC glActiveTextureARB = NULL;
PFNGLCLIENTACTIVETEXTUREARBPROC glClientActiveTextureARB = NULL;
PFNGLMULTITEXCOORD1DARBPROC glMultiTexCoord1dARB = NULL;
PFNGLMULTITEXCOORD1DVARBPROC glMultiTexCoord1dvARB = NULL;
PFNGLMULTITEXCOORD1FARBPROC glMultiTexCoord1fARB = NULL;
PFNGLMULTITEXCOORD1FVARBPROC glMultiTexCoord1fvARB = NULL;
PFNGLMULTITEXCOORD1IARBPROC glMultiTexCoord1iARB = NULL;
PFNGLMULTITEXCOORD1IVARBPROC glMultiTexCoord1ivARB = NULL;
PFNGLMULTITEXCOORD1SARBPROC glMultiTexCoord1sARB = NULL;
PFNGLMULTITEXCOORD1SVARBPROC glMultiTexCoord1svARB = NULL;
PFNGLMULTITEXCOORD2DARBPROC glMultiTexCoord2dARB = NULL;
PFNGLMULTITEXCOORD2DVARBPROC glMultiTexCoord2dvARB = NULL;
PFNGLMULTITEXCOORD2FARBPROC glMultiTexCoord2fARB = NULL;
PFNGLMULTITEXCOORD2FVARBPROC glMultiTexCoord2fvARB = NULL;
PFNGLMULTITEXCOORD2IARBPROC glMultiTexCoord2iARB = NULL;
PFNGLMULTITEXCOORD2IVARBPROC glMultiTexCoord2ivARB = NULL;
PFNGLMULTITEXCOORD2SARBPROC glMultiTexCoord2sARB = NULL;
PFNGLMULTITEXCOORD2SVARBPROC glMultiTexCoord2svARB = NULL;
PFNGLMULTITEXCOORD3DARBPROC glMultiTexCoord3dARB = NULL;
PFNGLMULTITEXCOORD3DVARBPROC glMultiTexCoord3dvARB = NULL;
PFNGLMULTITEXCOORD3FARBPROC glMultiTexCoord3fARB = NULL;
PFNGLMULTITEXCOORD3FVARBPROC glMultiTexCoord3fvARB = NULL;
PFNGLMULTITEXCOORD3IARBPROC glMultiTexCoord3iARB = NULL;
PFNGLMULTITEXCOORD3IVARBPROC glMultiTexCoord3ivARB = NULL;
PFNGLMULTITEXCOORD3SARBPROC glMultiTexCoord3sARB = NULL;
PFNGLMULTITEXCOORD3SVARBPROC glMultiTexCoord3svARB = NULL;
PFNGLMULTITEXCOORD4DARBPROC glMultiTexCoord4dARB = NULL;
PFNGLMULTITEXCOORD4DVARBPROC glMultiTexCoord4dvARB = NULL;
PFNGLMULTITEXCOORD4FARBPROC glMultiTexCoord4fARB = NULL;
PFNGLMULTITEXCOORD4FVARBPROC glMultiTexCoord4fvARB = NULL;
PFNGLMULTITEXCOORD4IARBPROC glMultiTexCoord4iARB = NULL;
PFNGLMULTITEXCOORD4IVARBPROC glMultiTexCoord4ivARB = NULL;
PFNGLMULTITEXCOORD4SARBPROC glMultiTexCoord4sARB = NULL;
PFNGLMULTITEXCOORD4SVARBPROC glMultiTexCoord4svARB = NULL;

static GLboolean _glewInit_ARB_multitexture ()
{
  GLboolean r = GL_FALSE;
  r = r || (glActiveTextureARB = (PFNGLACTIVETEXTUREARBPROC)glewGetProcAddress("glActiveTextureARB")) == NULL;
  r = r || (glClientActiveTextureARB = (PFNGLCLIENTACTIVETEXTUREARBPROC)glewGetProcAddress("glClientActiveTextureARB")) == NULL;
  r = r || (glMultiTexCoord1dARB = (PFNGLMULTITEXCOORD1DARBPROC)glewGetProcAddress("glMultiTexCoord1dARB")) == NULL;
  r = r || (glMultiTexCoord1dvARB = (PFNGLMULTITEXCOORD1DVARBPROC)glewGetProcAddress("glMultiTexCoord1dvARB")) == NULL;
  r = r || (glMultiTexCoord1fARB = (PFNGLMULTITEXCOORD1FARBPROC)glewGetProcAddress("glMultiTexCoord1fARB")) == NULL;
  r = r || (glMultiTexCoord1fvARB = (PFNGLMULTITEXCOORD1FVARBPROC)glewGetProcAddress("glMultiTexCoord1fvARB")) == NULL;
  r = r || (glMultiTexCoord1iARB = (PFNGLMULTITEXCOORD1IARBPROC)glewGetProcAddress("glMultiTexCoord1iARB")) == NULL;
  r = r || (glMultiTexCoord1ivARB = (PFNGLMULTITEXCOORD1IVARBPROC)glewGetProcAddress("glMultiTexCoord1ivARB")) == NULL;
  r = r || (glMultiTexCoord1sARB = (PFNGLMULTITEXCOORD1SARBPROC)glewGetProcAddress("glMultiTexCoord1sARB")) == NULL;
  r = r || (glMultiTexCoord1svARB = (PFNGLMULTITEXCOORD1SVARBPROC)glewGetProcAddress("glMultiTexCoord1svARB")) == NULL;
  r = r || (glMultiTexCoord2dARB = (PFNGLMULTITEXCOORD2DARBPROC)glewGetProcAddress("glMultiTexCoord2dARB")) == NULL;
  r = r || (glMultiTexCoord2dvARB = (PFNGLMULTITEXCOORD2DVARBPROC)glewGetProcAddress("glMultiTexCoord2dvARB")) == NULL;
  r = r || (glMultiTexCoord2fARB = (PFNGLMULTITEXCOORD2FARBPROC)glewGetProcAddress("glMultiTexCoord2fARB")) == NULL;
  r = r || (glMultiTexCoord2fvARB = (PFNGLMULTITEXCOORD2FVARBPROC)glewGetProcAddress("glMultiTexCoord2fvARB")) == NULL;
  r = r || (glMultiTexCoord2iARB = (PFNGLMULTITEXCOORD2IARBPROC)glewGetProcAddress("glMultiTexCoord2iARB")) == NULL;
  r = r || (glMultiTexCoord2ivARB = (PFNGLMULTITEXCOORD2IVARBPROC)glewGetProcAddress("glMultiTexCoord2ivARB")) == NULL;
  r = r || (glMultiTexCoord2sARB = (PFNGLMULTITEXCOORD2SARBPROC)glewGetProcAddress("glMultiTexCoord2sARB")) == NULL;
  r = r || (glMultiTexCoord2svARB = (PFNGLMULTITEXCOORD2SVARBPROC)glewGetProcAddress("glMultiTexCoord2svARB")) == NULL;
  r = r || (glMultiTexCoord3dARB = (PFNGLMULTITEXCOORD3DARBPROC)glewGetProcAddress("glMultiTexCoord3dARB")) == NULL;
  r = r || (glMultiTexCoord3dvARB = (PFNGLMULTITEXCOORD3DVARBPROC)glewGetProcAddress("glMultiTexCoord3dvARB")) == NULL;
  r = r || (glMultiTexCoord3fARB = (PFNGLMULTITEXCOORD3FARBPROC)glewGetProcAddress("glMultiTexCoord3fARB")) == NULL;
  r = r || (glMultiTexCoord3fvARB = (PFNGLMULTITEXCOORD3FVARBPROC)glewGetProcAddress("glMultiTexCoord3fvARB")) == NULL;
  r = r || (glMultiTexCoord3iARB = (PFNGLMULTITEXCOORD3IARBPROC)glewGetProcAddress("glMultiTexCoord3iARB")) == NULL;
  r = r || (glMultiTexCoord3ivARB = (PFNGLMULTITEXCOORD3IVARBPROC)glewGetProcAddress("glMultiTexCoord3ivARB")) == NULL;
  r = r || (glMultiTexCoord3sARB = (PFNGLMULTITEXCOORD3SARBPROC)glewGetProcAddress("glMultiTexCoord3sARB")) == NULL;
  r = r || (glMultiTexCoord3svARB = (PFNGLMULTITEXCOORD3SVARBPROC)glewGetProcAddress("glMultiTexCoord3svARB")) == NULL;
  r = r || (glMultiTexCoord4dARB = (PFNGLMULTITEXCOORD4DARBPROC)glewGetProcAddress("glMultiTexCoord4dARB")) == NULL;
  r = r || (glMultiTexCoord4dvARB = (PFNGLMULTITEXCOORD4DVARBPROC)glewGetProcAddress("glMultiTexCoord4dvARB")) == NULL;
  r = r || (glMultiTexCoord4fARB = (PFNGLMULTITEXCOORD4FARBPROC)glewGetProcAddress("glMultiTexCoord4fARB")) == NULL;
  r = r || (glMultiTexCoord4fvARB = (PFNGLMULTITEXCOORD4FVARBPROC)glewGetProcAddress("glMultiTexCoord4fvARB")) == NULL;
  r = r || (glMultiTexCoord4iARB = (PFNGLMULTITEXCOORD4IARBPROC)glewGetProcAddress("glMultiTexCoord4iARB")) == NULL;
  r = r || (glMultiTexCoord4ivARB = (PFNGLMULTITEXCOORD4IVARBPROC)glewGetProcAddress("glMultiTexCoord4ivARB")) == NULL;
  r = r || (glMultiTexCoord4sARB = (PFNGLMULTITEXCOORD4SARBPROC)glewGetProcAddress("glMultiTexCoord4sARB")) == NULL;
  r = r || (glMultiTexCoord4svARB = (PFNGLMULTITEXCOORD4SVARBPROC)glewGetProcAddress("glMultiTexCoord4svARB")) == NULL;
  return r;
}
#endif /* GL_ARB_multitexture */

/* ------------------------- ARB_point_parameters ------------------------- */

#ifdef GL_ARB_point_parameters
PFNGLPOINTPARAMETERFARBPROC glPointParameterfARB = NULL;
PFNGLPOINTPARAMETERFVARBPROC glPointParameterfvARB = NULL;

static GLboolean _glewInit_ARB_point_parameters ()
{
  GLboolean r = GL_FALSE;
  r = r || (glPointParameterfARB = (PFNGLPOINTPARAMETERFARBPROC)glewGetProcAddress("glPointParameterfARB")) == NULL;
  r = r || (glPointParameterfvARB = (PFNGLPOINTPARAMETERFVARBPROC)glewGetProcAddress("glPointParameterfvARB")) == NULL;
  return r;
}
#endif /* GL_ARB_point_parameters */

/* ------------------------ ARB_texture_compression ----------------------- */

#ifdef GL_ARB_texture_compression
PFNGLCOMPRESSEDTEXIMAGE3DARBPROC glCompressedTexImage3DARB = NULL;
PFNGLCOMPRESSEDTEXIMAGE2DARBPROC glCompressedTexImage2DARB = NULL;
PFNGLCOMPRESSEDTEXIMAGE1DARBPROC glCompressedTexImage1DARB = NULL; 
PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC glCompressedTexSubImage3DARB = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC glCompressedTexSubImage2DARB = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC glCompressedTexSubImage1DARB = NULL;
PFNGLGETCOMPRESSEDTEXIMAGEARBPROC glGetCompressedTexImageARB = NULL;

static GLboolean _glewInit_ARB_texture_compression ()
{
  GLboolean r = GL_FALSE;
  r = r || (glCompressedTexImage3DARB = (PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)glewGetProcAddress("glCompressedTexImage3DARB")) == NULL;
  r = r || (glCompressedTexImage2DARB = (PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)glewGetProcAddress("glCompressedTexImage2DARB")) == NULL;
  r = r || (glCompressedTexImage1DARB = (PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)glewGetProcAddress("glCompressedTexImage1DARB")) == NULL;
  r = r || (glCompressedTexSubImage3DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)glewGetProcAddress("glCompressedTexSubImage3DARB")) == NULL;
  r = r || (glCompressedTexSubImage2DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)glewGetProcAddress("glCompressedTexSubImage2DARB")) == NULL;
  r = r || (glCompressedTexSubImage1DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)glewGetProcAddress("glCompressedTexSubImage1DARB")) == NULL;
  r = r || (glGetCompressedTexImageARB = (PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)glewGetProcAddress("glGetCompressedTexImageARB")) == NULL;
  return r;
}
#endif /* GL_ARB_texture_compression */

/* ------------------------- ARB_transpose_matrix ------------------------- */

#ifdef GL_ARB_transpose_matrix
PFNGLLOADTRANSPOSEMATRIXFARBPROC glLoadTransposeMatrixfARB = NULL;
PFNGLLOADTRANSPOSEMATRIXDARBPROC glLoadTransposeMatrixdARB = NULL;
PFNGLMULTTRANSPOSEMATRIXFARBPROC glMultTransposeMatrixfARB = NULL;
PFNGLMULTTRANSPOSEMATRIXDARBPROC glMultTransposeMatrixdARB = NULL;

static GLboolean _glewInit_ARB_transpose_matrix ()
{
  GLboolean r = GL_FALSE;
  r = r || (glLoadTransposeMatrixfARB = (PFNGLLOADTRANSPOSEMATRIXFARBPROC)glewGetProcAddress("glLoadTransposeMatrixfARB")) == NULL;
  r = r || (glLoadTransposeMatrixdARB = (PFNGLLOADTRANSPOSEMATRIXDARBPROC)glewGetProcAddress("glLoadTransposeMatrixdARB")) == NULL;
  r = r || (glMultTransposeMatrixfARB = (PFNGLMULTTRANSPOSEMATRIXFARBPROC)glewGetProcAddress("glMultTransposeMatrixfARB")) == NULL;
  r = r || (glMultTransposeMatrixdARB = (PFNGLMULTTRANSPOSEMATRIXDARBPROC)glewGetProcAddress("glMultTransposeMatrixdARB")) == NULL;
  return r;
}
#endif /* GL_ARB_transpose_matrix */

/* --------------------------- ARB_vertex_blend --------------------------- */

#ifdef GL_ARB_vertex_blend
PFNGLWEIGHTBVARBPROC glWeightbvARB = NULL;
PFNGLWEIGHTSVARBPROC glWeightsvARB = NULL;
PFNGLWEIGHTIVARBPROC glWeightivARB = NULL;
PFNGLWEIGHTFVARBPROC glWeightfvARB = NULL;
PFNGLWEIGHTDVARBPROC glWeightdvARB = NULL;
PFNGLWEIGHTUBVARBPROC glWeightubvARB = NULL;
PFNGLWEIGHTUSVARBPROC glWeightusvARB = NULL;
PFNGLWEIGHTUIVARBPROC glWeightuivARB = NULL;
PFNGLWEIGHTPOINTERARBPROC glWeightPointerARB = NULL;
PFNGLVERTEXBLENDARBPROC glVertexBlendARB = NULL;

static GLboolean _glewInit_ARB_vertex_blend ()
{
  GLboolean r = GL_FALSE;
  r = r || (glWeightbvARB = (PFNGLWEIGHTBVARBPROC)glewGetProcAddress("glWeightbvARB")) == NULL;
  r = r || (glWeightsvARB = (PFNGLWEIGHTSVARBPROC)glewGetProcAddress("glWeightsvARB")) == NULL;
  r = r || (glWeightivARB = (PFNGLWEIGHTIVARBPROC)glewGetProcAddress("glWeightivARB")) == NULL;
  r = r || (glWeightfvARB = (PFNGLWEIGHTFVARBPROC)glewGetProcAddress("glWeightfvARB")) == NULL;
  r = r || (glWeightdvARB = (PFNGLWEIGHTDVARBPROC)glewGetProcAddress("glWeightdvARB")) == NULL;
  r = r || (glWeightubvARB = (PFNGLWEIGHTUBVARBPROC)glewGetProcAddress("glWeightubvARB")) == NULL;
  r = r || (glWeightusvARB = (PFNGLWEIGHTUSVARBPROC)glewGetProcAddress("glWeightusvARB")) == NULL;
  r = r || (glWeightuivARB = (PFNGLWEIGHTUIVARBPROC)glewGetProcAddress("glWeightuivARB")) == NULL;
  r = r || (glWeightPointerARB = (PFNGLWEIGHTPOINTERARBPROC)glewGetProcAddress("glWeightPointerARB")) == NULL;
  r = r || (glVertexBlendARB = (PFNGLVERTEXBLENDARBPROC)glewGetProcAddress("glVertexBlendARB")) == NULL;
  return r;
}
#endif /* GL_ARB_vertex_blend */

/* -------------------------- ARB_vertex_program -------------------------- */

#ifdef GL_ARB_vertex_program
PFNGLVERTEXATTRIB1SARBPROC glVertexAttrib1sARB = NULL;
PFNGLVERTEXATTRIB1FARBPROC glVertexAttrib1fARB = NULL;
PFNGLVERTEXATTRIB1DARBPROC glVertexAttrib1dARB = NULL;
PFNGLVERTEXATTRIB2SARBPROC glVertexAttrib2sARB = NULL;
PFNGLVERTEXATTRIB2FARBPROC glVertexAttrib2fARB = NULL;
PFNGLVERTEXATTRIB2DARBPROC glVertexAttrib2dARB = NULL;
PFNGLVERTEXATTRIB3SARBPROC glVertexAttrib3sARB = NULL;
PFNGLVERTEXATTRIB3FARBPROC glVertexAttrib3fARB = NULL;
PFNGLVERTEXATTRIB3DARBPROC glVertexAttrib3dARB = NULL;
PFNGLVERTEXATTRIB4SARBPROC glVertexAttrib4sARB = NULL;
PFNGLVERTEXATTRIB4FARBPROC glVertexAttrib4fARB = NULL;
PFNGLVERTEXATTRIB4DARBPROC glVertexAttrib4dARB = NULL;
PFNGLVERTEXATTRIB4NUBARBPROC glVertexAttrib4NubARB = NULL;
PFNGLVERTEXATTRIB1SVARBPROC glVertexAttrib1svARB = NULL;
PFNGLVERTEXATTRIB1FVARBPROC glVertexAttrib1fvARB = NULL;
PFNGLVERTEXATTRIB1DVARBPROC glVertexAttrib1dvARB = NULL;
PFNGLVERTEXATTRIB2SVARBPROC glVertexAttrib2svARB = NULL;
PFNGLVERTEXATTRIB2FVARBPROC glVertexAttrib2fvARB = NULL;
PFNGLVERTEXATTRIB2DVARBPROC glVertexAttrib2dvARB = NULL;
PFNGLVERTEXATTRIB3SVARBPROC glVertexAttrib3svARB = NULL;
PFNGLVERTEXATTRIB3FVARBPROC glVertexAttrib3fvARB = NULL;
PFNGLVERTEXATTRIB3DVARBPROC glVertexAttrib3dvARB = NULL;
PFNGLVERTEXATTRIB4BVARBPROC glVertexAttrib4bvARB = NULL;
PFNGLVERTEXATTRIB4SVARBPROC glVertexAttrib4svARB = NULL;
PFNGLVERTEXATTRIB4IVARBPROC glVertexAttrib4ivARB = NULL;
PFNGLVERTEXATTRIB4UBVARBPROC glVertexAttrib4ubvARB = NULL;
PFNGLVERTEXATTRIB4USVARBPROC glVertexAttrib4usvARB = NULL;
PFNGLVERTEXATTRIB4UIVARBPROC glVertexAttrib4uivARB = NULL;
PFNGLVERTEXATTRIB4FVARBPROC glVertexAttrib4fvARB = NULL;
PFNGLVERTEXATTRIB4DVARBPROC glVertexAttrib4dvARB = NULL;
PFNGLVERTEXATTRIB4NBVARBPROC glVertexAttrib4NbvARB = NULL;
PFNGLVERTEXATTRIB4NSVARBPROC glVertexAttrib4NsvARB = NULL;
PFNGLVERTEXATTRIB4NIVARBPROC glVertexAttrib4NivARB = NULL;
PFNGLVERTEXATTRIB4NUBVARBPROC glVertexAttrib4NubvARB = NULL;
PFNGLVERTEXATTRIB4NUSVARBPROC glVertexAttrib4NusvARB = NULL;
PFNGLVERTEXATTRIB4NUIVARBPROC glVertexAttrib4NuivARB = NULL;
PFNGLVERTEXATTRIBPOINTERARBPROC glVertexAttribPointerARB = NULL;
PFNGLENABLEVERTEXATTRIBARRAYARBPROC glEnableVertexAttribArrayARB = NULL;
PFNGLDISABLEVERTEXATTRIBARRAYARBPROC glDisableVertexAttribArrayARB = NULL;
PFNGLPROGRAMSTRINGARBPROC glProgramStringARB = NULL;
PFNGLBINDPROGRAMARBPROC glBindProgramARB = NULL;
PFNGLDELETEPROGRAMSARBPROC glDeleteProgramsARB = NULL;
PFNGLGENPROGRAMSARBPROC glGenProgramsARB = NULL;
PFNGLPROGRAMENVPARAMETER4DARBPROC glProgramEnvParameter4dARB = NULL;
PFNGLPROGRAMENVPARAMETER4DVARBPROC glProgramEnvParameter4dvARB = NULL;
PFNGLPROGRAMENVPARAMETER4FARBPROC glProgramEnvParameter4fARB = NULL;
PFNGLPROGRAMENVPARAMETER4FVARBPROC glProgramEnvParameter4fvARB = NULL;
PFNGLPROGRAMLOCALPARAMETER4DARBPROC glProgramLocalParameter4dARB = NULL;
PFNGLPROGRAMLOCALPARAMETER4DVARBPROC glProgramLocalParameter4dvARB = NULL;
PFNGLPROGRAMLOCALPARAMETER4FARBPROC glProgramLocalParameter4fARB = NULL;
PFNGLPROGRAMLOCALPARAMETER4FVARBPROC glProgramLocalParameter4fvARB = NULL;
PFNGLGETPROGRAMENVPARAMETERDVARBPROC glGetProgramEnvParameterdvARB = NULL;
PFNGLGETPROGRAMENVPARAMETERFVARBPROC glGetProgramEnvParameterfvARB = NULL;
PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC glGetProgramLocalParameterdvARB = NULL;
PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC glGetProgramLocalParameterfvARB = NULL;
PFNGLGETPROGRAMIVARBPROC glGetProgramivARB = NULL;
PFNGLGETPROGRAMSTRINGARBPROC glGetProgramStringARB = NULL;
PFNGLGETVERTEXATTRIBDVARBPROC glGetVertexAttribdvARB = NULL;
PFNGLGETVERTEXATTRIBFVARBPROC glGetVertexAttribfvARB = NULL;
PFNGLGETVERTEXATTRIBIVARBPROC glGetVertexAttribivARB = NULL;
PFNGLGETVERTEXATTRIBPOINTERVARBPROC glGetVertexAttribPointervARB = NULL;
PFNGLISPROGRAMARBPROC glIsProgramARB = NULL;

static GLboolean _glewInit_ARB_vertex_program ()
{
  GLboolean r = GL_FALSE;
  r = r || (glVertexAttrib1sARB = (PFNGLVERTEXATTRIB1SARBPROC)glewGetProcAddress("glVertexAttrib1sARB")) == NULL;
  r = r || (glVertexAttrib1fARB = (PFNGLVERTEXATTRIB1FARBPROC)glewGetProcAddress("glVertexAttrib1fARB")) == NULL;
  r = r || (glVertexAttrib1dARB = (PFNGLVERTEXATTRIB1DARBPROC)glewGetProcAddress("glVertexAttrib1dARB")) == NULL;
  r = r || (glVertexAttrib2sARB = (PFNGLVERTEXATTRIB2SARBPROC)glewGetProcAddress("glVertexAttrib2sARB")) == NULL;
  r = r || (glVertexAttrib2fARB = (PFNGLVERTEXATTRIB2FARBPROC)glewGetProcAddress("glVertexAttrib2fARB")) == NULL;
  r = r || (glVertexAttrib2dARB = (PFNGLVERTEXATTRIB2DARBPROC)glewGetProcAddress("glVertexAttrib2dARB")) == NULL;
  r = r || (glVertexAttrib3sARB = (PFNGLVERTEXATTRIB3SARBPROC)glewGetProcAddress("glVertexAttrib3sARB")) == NULL;
  r = r || (glVertexAttrib3fARB = (PFNGLVERTEXATTRIB3FARBPROC)glewGetProcAddress("glVertexAttrib3fARB")) == NULL;
  r = r || (glVertexAttrib3dARB = (PFNGLVERTEXATTRIB3DARBPROC)glewGetProcAddress("glVertexAttrib3dARB")) == NULL;
  r = r || (glVertexAttrib4sARB = (PFNGLVERTEXATTRIB4SARBPROC)glewGetProcAddress("glVertexAttrib4sARB")) == NULL;
  r = r || (glVertexAttrib4fARB = (PFNGLVERTEXATTRIB4FARBPROC)glewGetProcAddress("glVertexAttrib4fARB")) == NULL;
  r = r || (glVertexAttrib4dARB = (PFNGLVERTEXATTRIB4DARBPROC)glewGetProcAddress("glVertexAttrib4dARB")) == NULL;
  r = r || (glVertexAttrib4NubARB = (PFNGLVERTEXATTRIB4NUBARBPROC)glewGetProcAddress("glVertexAttrib4NubARB")) == NULL;
  r = r || (glVertexAttrib1svARB = (PFNGLVERTEXATTRIB1SVARBPROC)glewGetProcAddress("glVertexAttrib1svARB")) == NULL;
  r = r || (glVertexAttrib1fvARB = (PFNGLVERTEXATTRIB1FVARBPROC)glewGetProcAddress("glVertexAttrib1fvARB")) == NULL;
  r = r || (glVertexAttrib1dvARB = (PFNGLVERTEXATTRIB1DVARBPROC)glewGetProcAddress("glVertexAttrib1dvARB")) == NULL;
  r = r || (glVertexAttrib2svARB = (PFNGLVERTEXATTRIB2SVARBPROC)glewGetProcAddress("glVertexAttrib2svARB")) == NULL;
  r = r || (glVertexAttrib2fvARB = (PFNGLVERTEXATTRIB2FVARBPROC)glewGetProcAddress("glVertexAttrib2fvARB")) == NULL;
  r = r || (glVertexAttrib2dvARB = (PFNGLVERTEXATTRIB2DVARBPROC)glewGetProcAddress("glVertexAttrib2dvARB")) == NULL;
  r = r || (glVertexAttrib3svARB = (PFNGLVERTEXATTRIB3SVARBPROC)glewGetProcAddress("glVertexAttrib3svARB")) == NULL;
  r = r || (glVertexAttrib3fvARB = (PFNGLVERTEXATTRIB3FVARBPROC)glewGetProcAddress("glVertexAttrib3fvARB")) == NULL;
  r = r || (glVertexAttrib3dvARB = (PFNGLVERTEXATTRIB3DVARBPROC)glewGetProcAddress("glVertexAttrib3dvARB")) == NULL;
  r = r || (glVertexAttrib4bvARB = (PFNGLVERTEXATTRIB4BVARBPROC)glewGetProcAddress("glVertexAttrib4bvARB")) == NULL;
  r = r || (glVertexAttrib4svARB = (PFNGLVERTEXATTRIB4SVARBPROC)glewGetProcAddress("glVertexAttrib4svARB")) == NULL;
  r = r || (glVertexAttrib4ivARB = (PFNGLVERTEXATTRIB4IVARBPROC)glewGetProcAddress("glVertexAttrib4ivARB")) == NULL;
  r = r || (glVertexAttrib4ubvARB = (PFNGLVERTEXATTRIB4UBVARBPROC)glewGetProcAddress("glVertexAttrib4ubvARB")) == NULL;
  r = r || (glVertexAttrib4usvARB = (PFNGLVERTEXATTRIB4USVARBPROC)glewGetProcAddress("glVertexAttrib4usvARB")) == NULL;
  r = r || (glVertexAttrib4uivARB = (PFNGLVERTEXATTRIB4UIVARBPROC)glewGetProcAddress("glVertexAttrib4uivARB")) == NULL;
  r = r || (glVertexAttrib4fvARB = (PFNGLVERTEXATTRIB4FVARBPROC)glewGetProcAddress("glVertexAttrib4fvARB")) == NULL;
  r = r || (glVertexAttrib4dvARB = (PFNGLVERTEXATTRIB4DVARBPROC)glewGetProcAddress("glVertexAttrib4dvARB")) == NULL;
  r = r || (glVertexAttrib4NbvARB = (PFNGLVERTEXATTRIB4NBVARBPROC)glewGetProcAddress("glVertexAttrib4NbvARB")) == NULL;
  r = r || (glVertexAttrib4NsvARB = (PFNGLVERTEXATTRIB4NSVARBPROC)glewGetProcAddress("glVertexAttrib4NsvARB")) == NULL;
  r = r || (glVertexAttrib4NivARB = (PFNGLVERTEXATTRIB4NIVARBPROC)glewGetProcAddress("glVertexAttrib4NivARB")) == NULL;
  r = r || (glVertexAttrib4NubvARB = (PFNGLVERTEXATTRIB4NUBVARBPROC)glewGetProcAddress("glVertexAttrib4NubvARB")) == NULL;
  r = r || (glVertexAttrib4NusvARB = (PFNGLVERTEXATTRIB4NUSVARBPROC)glewGetProcAddress("glVertexAttrib4NusvARB")) == NULL;
  r = r || (glVertexAttrib4NuivARB = (PFNGLVERTEXATTRIB4NUIVARBPROC)glewGetProcAddress("glVertexAttrib4NuivARB")) == NULL;
  r = r || (glVertexAttribPointerARB = (PFNGLVERTEXATTRIBPOINTERARBPROC)glewGetProcAddress("glVertexAttribPointerARB")) == NULL;
  r = r || (glEnableVertexAttribArrayARB = (PFNGLENABLEVERTEXATTRIBARRAYARBPROC)glewGetProcAddress("glEnableVertexAttribArrayARB")) == NULL;
  r = r || (glDisableVertexAttribArrayARB = (PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)glewGetProcAddress("glDisableVertexAttribArrayARB")) == NULL;
  r = r || (glProgramStringARB = (PFNGLPROGRAMSTRINGARBPROC)glewGetProcAddress("glProgramStringARB")) == NULL;
  r = r || (glBindProgramARB = (PFNGLBINDPROGRAMARBPROC)glewGetProcAddress("glBindProgramARB")) == NULL;
  r = r || (glDeleteProgramsARB = (PFNGLDELETEPROGRAMSARBPROC)glewGetProcAddress("glDeleteProgramsARB")) == NULL;
  r = r || (glGenProgramsARB = (PFNGLGENPROGRAMSARBPROC)glewGetProcAddress("glGenProgramsARB")) == NULL;
  r = r || (glProgramEnvParameter4dARB = (PFNGLPROGRAMENVPARAMETER4DARBPROC)glewGetProcAddress("glProgramEnvParameter4dARB")) == NULL;
  r = r || (glProgramEnvParameter4dvARB = (PFNGLPROGRAMENVPARAMETER4DVARBPROC)glewGetProcAddress("glProgramEnvParameter4dvARB")) == NULL;
  r = r || (glProgramEnvParameter4fARB = (PFNGLPROGRAMENVPARAMETER4FARBPROC)glewGetProcAddress("glProgramEnvParameter4fARB")) == NULL;
  r = r || (glProgramEnvParameter4fvARB = (PFNGLPROGRAMENVPARAMETER4FVARBPROC)glewGetProcAddress("glProgramEnvParameter4fvARB")) == NULL;
  r = r || (glProgramLocalParameter4dARB = (PFNGLPROGRAMLOCALPARAMETER4DARBPROC)glewGetProcAddress("glProgramLocalParameter4dARB")) == NULL;
  r = r || (glProgramLocalParameter4dvARB = (PFNGLPROGRAMLOCALPARAMETER4DVARBPROC)glewGetProcAddress("glProgramLocalParameter4dvARB")) == NULL;
  r = r || (glProgramLocalParameter4fARB = (PFNGLPROGRAMLOCALPARAMETER4FARBPROC)glewGetProcAddress("glProgramLocalParameter4fARB")) == NULL;
  r = r || (glProgramLocalParameter4fvARB = (PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)glewGetProcAddress("glProgramLocalParameter4fvARB")) == NULL;
  r = r || (glGetProgramEnvParameterdvARB = (PFNGLGETPROGRAMENVPARAMETERDVARBPROC)glewGetProcAddress("glGetProgramEnvParameterdvARB")) == NULL;
  r = r || (glGetProgramEnvParameterfvARB = (PFNGLGETPROGRAMENVPARAMETERFVARBPROC)glewGetProcAddress("glGetProgramEnvParameterfvARB")) == NULL;
  r = r || (glGetProgramLocalParameterdvARB = (PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC)glewGetProcAddress("glGetProgramLocalParameterdvARB")) == NULL;
  r = r || (glGetProgramLocalParameterfvARB = (PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)glewGetProcAddress("glGetProgramLocalParameterfvARB")) == NULL;
  r = r || (glGetProgramivARB = (PFNGLGETPROGRAMIVARBPROC)glewGetProcAddress("glGetProgramivARB")) == NULL;
  r = r || (glGetProgramStringARB = (PFNGLGETPROGRAMSTRINGARBPROC)glewGetProcAddress("glGetProgramStringARB")) == NULL;
  r = r || (glGetVertexAttribdvARB = (PFNGLGETVERTEXATTRIBDVARBPROC)glewGetProcAddress("glGetVertexAttribdvARB")) == NULL;
  r = r || (glGetVertexAttribfvARB = (PFNGLGETVERTEXATTRIBFVARBPROC)glewGetProcAddress("glGetVertexAttribfvARB")) == NULL;
  r = r || (glGetVertexAttribivARB = (PFNGLGETVERTEXATTRIBIVARBPROC)glewGetProcAddress("glGetVertexAttribivARB")) == NULL;
  r = r || (glGetVertexAttribPointervARB = (PFNGLGETVERTEXATTRIBPOINTERVARBPROC)glewGetProcAddress("glGetVertexAttribPointervARB")) == NULL;
  r = r || (glIsProgramARB = (PFNGLISPROGRAMARBPROC)glewGetProcAddress("glIsProgramARB")) == NULL;
  return r;
}
#endif /* GL_ARB_vertex_program */

/* ---------------------------- ARB_window_pos ---------------------------- */

#ifdef GL_ARB_window_pos
PFNGLWINDOWPOS2DARBPROC glWindowPos2dARB = NULL;
PFNGLWINDOWPOS2FARBPROC glWindowPos2fARB = NULL;
PFNGLWINDOWPOS2IARBPROC glWindowPos2iARB = NULL;
PFNGLWINDOWPOS2SARBPROC glWindowPos2sARB = NULL;
PFNGLWINDOWPOS2DVARBPROC glWindowPos2dvARB = NULL;
PFNGLWINDOWPOS2FVARBPROC glWindowPos2fvARB = NULL;
PFNGLWINDOWPOS2IVARBPROC glWindowPos2ivARB = NULL;
PFNGLWINDOWPOS2SVARBPROC glWindowPos2svARB = NULL;
PFNGLWINDOWPOS3DARBPROC glWindowPos3dARB = NULL;
PFNGLWINDOWPOS3FARBPROC glWindowPos3fARB = NULL;
PFNGLWINDOWPOS3IARBPROC glWindowPos3iARB = NULL;
PFNGLWINDOWPOS3SARBPROC glWindowPos3sARB = NULL;
PFNGLWINDOWPOS3DVARBPROC glWindowPos3dvARB = NULL;
PFNGLWINDOWPOS3FVARBPROC glWindowPos3fvARB = NULL;
PFNGLWINDOWPOS3IVARBPROC glWindowPos3ivARB = NULL;
PFNGLWINDOWPOS3SVARBPROC glWindowPos3svARB = NULL;

static GLboolean _glewInit_ARB_window_pos ()
{
  GLboolean r = GL_FALSE;
  r = r || (glWindowPos2dARB = (PFNGLWINDOWPOS2DARBPROC)glewGetProcAddress("glWindowPos2dARB")) == NULL;
  r = r || (glWindowPos2fARB = (PFNGLWINDOWPOS2FARBPROC)glewGetProcAddress("glWindowPos2fARB")) == NULL;
  r = r || (glWindowPos2iARB = (PFNGLWINDOWPOS2IARBPROC)glewGetProcAddress("glWindowPos2iARB")) == NULL;
  r = r || (glWindowPos2sARB = (PFNGLWINDOWPOS2SARBPROC)glewGetProcAddress("glWindowPos2sARB")) == NULL;
  r = r || (glWindowPos2dvARB = (PFNGLWINDOWPOS2DVARBPROC)glewGetProcAddress("glWindowPos2dvARB")) == NULL;
  r = r || (glWindowPos2fvARB = (PFNGLWINDOWPOS2FVARBPROC)glewGetProcAddress("glWindowPos2fvARB")) == NULL;
  r = r || (glWindowPos2ivARB = (PFNGLWINDOWPOS2IVARBPROC)glewGetProcAddress("glWindowPos2ivARB")) == NULL;
  r = r || (glWindowPos2svARB = (PFNGLWINDOWPOS2SVARBPROC)glewGetProcAddress("glWindowPos2svARB")) == NULL;
  r = r || (glWindowPos3dARB = (PFNGLWINDOWPOS3DARBPROC)glewGetProcAddress("glWindowPos3dARB")) == NULL;
  r = r || (glWindowPos3fARB = (PFNGLWINDOWPOS3FARBPROC)glewGetProcAddress("glWindowPos3fARB")) == NULL;
  r = r || (glWindowPos3iARB = (PFNGLWINDOWPOS3IARBPROC)glewGetProcAddress("glWindowPos3iARB")) == NULL;
  r = r || (glWindowPos3sARB = (PFNGLWINDOWPOS3SARBPROC)glewGetProcAddress("glWindowPos3sARB")) == NULL;
  r = r || (glWindowPos3dvARB = (PFNGLWINDOWPOS3DVARBPROC)glewGetProcAddress("glWindowPos3dvARB")) == NULL;
  r = r || (glWindowPos3fvARB = (PFNGLWINDOWPOS3FVARBPROC)glewGetProcAddress("glWindowPos3fvARB")) == NULL;
  r = r || (glWindowPos3ivARB = (PFNGLWINDOWPOS3IVARBPROC)glewGetProcAddress("glWindowPos3ivARB")) == NULL;
  r = r || (glWindowPos3svARB = (PFNGLWINDOWPOS3SVARBPROC)glewGetProcAddress("glWindowPos3svARB")) == NULL;
  return r;
}
#endif /* GL_ARB_window_pos */

/* ---------------------------- EXT_blend_color --------------------------- */

#ifdef GL_EXT_blend_color
PFNGLBLENDCOLOREXTPROC glBlendColorEXT;

static GLboolean _glewInit_EXT_blend_color ()
{
  GLboolean r = GL_FALSE;
  r = r || (glBlendColorEXT = (PFNGLBLENDCOLOREXTPROC)glewGetProcAddress("glBlendColorEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_blend_color */

/* ------------------------ EXT_blend_func_separate ----------------------- */

#ifdef GL_EXT_blend_func_separate
PFNGLBLENDFUNCSEPARATEEXTPROC glBlendFuncSeparateEXT = NULL;

static GLboolean _glewInit_EXT_blend_func_separate ()
{
  GLboolean r = GL_FALSE;
  r = r || (glBlendFuncSeparateEXT = (PFNGLBLENDFUNCSEPARATEEXTPROC)glewGetProcAddress("glBlendFuncSeparateEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_blend_func_separate */

/* ---------------------------- EXT_blend_minmax -------------------------- */

#ifdef GL_EXT_blend_minmax
PFNGLBLENDEQUATIONEXTPROC glBlendEquationEXT;

static GLboolean _glewInit_EXT_blend_minmax ()
{
  GLboolean r = GL_FALSE;
  r = r || (glBlendEquationEXT = (PFNGLBLENDEQUATIONEXTPROC)glewGetProcAddress("glBlendEquationEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_blend_minmax */

/* ----------------------- EXT_compiled_vertex_array ---------------------- */

#ifdef GL_EXT_compiled_vertex_array
PFNGLLOCKARRAYSEXTPROC glLockArraysEXT = NULL;
PFNGLUNLOCKARRAYSEXTPROC glUnlockArraysEXT = NULL;

static GLboolean _glewInit_EXT_compiled_vertex_array ()
{
  GLboolean r = GL_FALSE;
  r = r || (glLockArraysEXT = (PFNGLLOCKARRAYSEXTPROC)glewGetProcAddress("glLockArraysEXT")) == NULL;
  r = r || (glUnlockArraysEXT = (PFNGLUNLOCKARRAYSEXTPROC)glewGetProcAddress("glUnlockArraysEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_compiled_vertex_array */

/* ---------------------------- EXT_cull_vertex --------------------------- */

#ifdef GL_EXT_cull_vertex
PFNGLCULLPARAMETERFVEXTPROC glCullParameterfvEXT = NULL;
PFNGLCULLPARAMETERDVEXTPROC glCullParameterdvEXT = NULL;

static GLboolean _glewInit_EXT_cull_vertex ()
{
  GLboolean r = GL_FALSE;
  r = r || (glCullParameterfvEXT = (PFNGLCULLPARAMETERFVEXTPROC)glewGetProcAddress("glCullParameterfvEXT")) == NULL;
  r = r || (glCullParameterdvEXT = (PFNGLCULLPARAMETERDVEXTPROC)glewGetProcAddress("glCullParameterdvEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_cull_vertex */

/* ------------------------ EXT_draw_range_elements ----------------------- */

#ifdef GL_EXT_draw_range_elements
PFNGLDRAWRANGEELEMENTSEXTPROC glDrawRangeElementsEXT = NULL;

static GLboolean _glewInit_EXT_draw_range_elements ()
{
  GLboolean r = GL_FALSE;
  r = r || (glDrawRangeElementsEXT = (PFNGLDRAWRANGEELEMENTSEXTPROC)glewGetProcAddress("glDrawRangeElementsEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_draw_range_elements */

/* ----------------------------- EXT_fog_coord ---------------------------- */

#ifdef GL_EXT_fog_coord
PFNGLFOGCOORDFEXTPROC glFogCoordfEXT = NULL;
PFNGLFOGCOORDFVEXTPROC glFogCoordfvEXT = NULL;
PFNGLFOGCOORDDEXTPROC glFogCoorddEXT = NULL;
PFNGLFOGCOORDDVEXTPROC glFogCoorddvEXT = NULL;
PFNGLFOGCOORDPOINTEREXTPROC glFogCoordPointerEXT = NULL;

static GLboolean _glewInit_EXT_fog_coord ()
{
  GLboolean r = GL_FALSE;
  r = r || (glFogCoordfEXT = (PFNGLFOGCOORDFEXTPROC)glewGetProcAddress("glFogCoordfEXT")) == NULL;
  r = r || (glFogCoordfvEXT = (PFNGLFOGCOORDFVEXTPROC)glewGetProcAddress("glFogCoordfvEXT")) == NULL;
  r = r || (glFogCoorddEXT = (PFNGLFOGCOORDDEXTPROC)glewGetProcAddress("glFogCoorddEXT")) == NULL;
  r = r || (glFogCoorddvEXT = (PFNGLFOGCOORDDVEXTPROC)glewGetProcAddress("glFogCoorddvEXT")) == NULL;
  r = r || (glFogCoordPointerEXT = (PFNGLFOGCOORDPOINTEREXTPROC)glewGetProcAddress("glFogCoordPointerEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_fog_coord */

/* ------------------------- EXT_multi_draw_arrays ------------------------ */

#ifdef GL_EXT_multi_draw_arrays
PFNGLMULTIDRAWARRAYSEXTPROC glMultiDrawArraysEXT = NULL;
PFNGLMULTIDRAWELEMENTSEXTPROC glMultiDrawElementsEXT = NULL;

static GLboolean _glewInit_EXT_multi_draw_arrays ()
{
  GLboolean r = GL_FALSE;
  r = r || (glMultiDrawArraysEXT = (PFNGLMULTIDRAWARRAYSEXTPROC) glewGetProcAddress("glMultiDrawArraysEXT")) == NULL;
  r = r || (glMultiDrawElementsEXT = (PFNGLMULTIDRAWELEMENTSEXTPROC) glewGetProcAddress("glMultiDrawElementsEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_multi_draw_arrays */

/* ------------------------- EXT_point_parameters ------------------------- */

#ifdef GL_EXT_point_parameters
PFNGLPOINTPARAMETERFEXTPROC glPointParameterfEXT = NULL;
PFNGLPOINTPARAMETERFVEXTPROC glPointParameterfvEXT = NULL;

static GLboolean _glewInit_EXT_point_parameters ()
{
  GLboolean r = GL_FALSE;
  r = r || (glPointParameterfEXT = (PFNGLPOINTPARAMETERFEXTPROC)glewGetProcAddress("glPointParameterfEXT")) == NULL;
  r = r || (glPointParameterfvEXT = (PFNGLPOINTPARAMETERFVEXTPROC)glewGetProcAddress("glPointParameterfvEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_point_parameters */

/* -------------------------- EXT_secondary_color ------------------------- */

#ifdef GL_EXT_secondary_color
PFNGLSECONDARYCOLOR3BEXTPROC glSecondaryColor3bEXT = NULL;
PFNGLSECONDARYCOLOR3BVEXTPROC glSecondaryColor3bvEXT = NULL;
PFNGLSECONDARYCOLOR3DEXTPROC glSecondaryColor3dEXT = NULL;
PFNGLSECONDARYCOLOR3DVEXTPROC glSecondaryColor3dvEXT = NULL;
PFNGLSECONDARYCOLOR3FEXTPROC glSecondaryColor3fEXT = NULL;
PFNGLSECONDARYCOLOR3FVEXTPROC glSecondaryColor3fvEXT = NULL;
PFNGLSECONDARYCOLOR3IEXTPROC glSecondaryColor3iEXT = NULL;
PFNGLSECONDARYCOLOR3IVEXTPROC glSecondaryColor3ivEXT = NULL;
PFNGLSECONDARYCOLOR3SEXTPROC glSecondaryColor3sEXT = NULL;
PFNGLSECONDARYCOLOR3SVEXTPROC glSecondaryColor3svEXT = NULL;
PFNGLSECONDARYCOLOR3UBEXTPROC glSecondaryColor3ubEXT = NULL;
PFNGLSECONDARYCOLOR3UBVEXTPROC glSecondaryColor3ubvEXT = NULL;
PFNGLSECONDARYCOLOR3UIEXTPROC glSecondaryColor3uiEXT = NULL;
PFNGLSECONDARYCOLOR3UIVEXTPROC glSecondaryColor3uivEXT = NULL;
PFNGLSECONDARYCOLOR3USEXTPROC glSecondaryColor3usEXT = NULL;
PFNGLSECONDARYCOLOR3USVEXTPROC glSecondaryColor3usvEXT = NULL;
PFNGLSECONDARYCOLORPOINTEREXTPROC glSecondaryColorPointerEXT = NULL;

static GLboolean _glewInit_EXT_secondary_color ()
{
  GLboolean r = GL_FALSE;
  r = r || (glSecondaryColor3bEXT = (PFNGLSECONDARYCOLOR3BEXTPROC)glewGetProcAddress("glSecondaryColor3bEXT")) == NULL;
  r = r || (glSecondaryColor3bvEXT = (PFNGLSECONDARYCOLOR3BVEXTPROC)glewGetProcAddress("glSecondaryColor3bvEXT")) == NULL;
  r = r || (glSecondaryColor3dEXT = (PFNGLSECONDARYCOLOR3DEXTPROC)glewGetProcAddress("glSecondaryColor3dEXT")) == NULL;
  r = r || (glSecondaryColor3dvEXT = (PFNGLSECONDARYCOLOR3DVEXTPROC)glewGetProcAddress("glSecondaryColor3dvEXT")) == NULL;
  r = r || (glSecondaryColor3fEXT = (PFNGLSECONDARYCOLOR3FEXTPROC)glewGetProcAddress("glSecondaryColor3fEXT")) == NULL;
  r = r || (glSecondaryColor3fvEXT = (PFNGLSECONDARYCOLOR3FVEXTPROC)glewGetProcAddress("glSecondaryColor3fvEXT")) == NULL;
  r = r || (glSecondaryColor3iEXT = (PFNGLSECONDARYCOLOR3IEXTPROC)glewGetProcAddress("glSecondaryColor3iEXT")) == NULL;
  r = r || (glSecondaryColor3ivEXT = (PFNGLSECONDARYCOLOR3IVEXTPROC)glewGetProcAddress("glSecondaryColor3ivEXT")) == NULL;
  r = r || (glSecondaryColor3sEXT = (PFNGLSECONDARYCOLOR3SEXTPROC)glewGetProcAddress("glSecondaryColor3sEXT")) == NULL;
  r = r || (glSecondaryColor3svEXT = (PFNGLSECONDARYCOLOR3SVEXTPROC)glewGetProcAddress("glSecondaryColor3svEXT")) == NULL;
  r = r || (glSecondaryColor3ubEXT = (PFNGLSECONDARYCOLOR3UBEXTPROC)glewGetProcAddress("glSecondaryColor3ubEXT")) == NULL;
  r = r || (glSecondaryColor3ubvEXT = (PFNGLSECONDARYCOLOR3UBVEXTPROC)glewGetProcAddress("glSecondaryColor3ubvEXT")) == NULL;
  r = r || (glSecondaryColor3uiEXT = (PFNGLSECONDARYCOLOR3UIEXTPROC)glewGetProcAddress("glSecondaryColor3uiEXT")) == NULL;
  r = r || (glSecondaryColor3uivEXT = (PFNGLSECONDARYCOLOR3UIVEXTPROC)glewGetProcAddress("glSecondaryColor3uivEXT")) == NULL;
  r = r || (glSecondaryColor3usEXT = (PFNGLSECONDARYCOLOR3USEXTPROC)glewGetProcAddress("glSecondaryColor3usEXT")) == NULL;
  r = r || (glSecondaryColor3usvEXT = (PFNGLSECONDARYCOLOR3USVEXTPROC)glewGetProcAddress("glSecondaryColor3usvEXT")) == NULL;
  r = r || (glSecondaryColorPointerEXT = (PFNGLSECONDARYCOLORPOINTEREXTPROC)glewGetProcAddress("glSecondaryColorPointerEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_secondary_color */

/* ------------------------- EXT_stencil_two_side ------------------------- */

#ifdef GL_EXT_stencil_two_side
PFNGLACTIVESTENCILFACEEXTPROC glActiveStencilFaceEXT = NULL;

static GLboolean _glewInit_EXT_stencil_two_side ()
{
  GLboolean r = GL_FALSE;
  r = r || (glActiveStencilFaceEXT = (PFNGLACTIVESTENCILFACEEXTPROC)glewGetProcAddress("glActiveStencilFaceEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_stencil_two_side */

/* ----------------------------- EXT_texture3D ---------------------------- */

#ifdef GL_EXT_texture3D
PFNGLTEXIMAGE3DEXTPROC glTexImage3DEXT = NULL;
PFNGLTEXSUBIMAGE3DEXTPROC glTexSubImage3DEXT = NULL;

static GLboolean _glewInit_EXT_texture3D ()
{
  GLboolean r = GL_FALSE;
  r = r || (glTexImage3DEXT = (PFNGLTEXIMAGE3DEXTPROC)glewGetProcAddress("glTexImage3DEXT")) == NULL;
  r = r || (glTexSubImage3DEXT = (PFNGLTEXSUBIMAGE3DEXTPROC)glewGetProcAddress("glTexSubImage3DEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_texture3D */

/* --------------------------- EXT_vertex_shader -------------------------- */

#ifdef GL_EXT_vertex_shader
PFNGLBEGINVERTEXSHADEREXTPROC glBeginVertexShaderEXT = NULL;
PFNGLENDVERTEXSHADEREXTPROC glEndVertexShaderEXT = NULL;
PFNGLBINDVERTEXSHADEREXTPROC glBindVertexShaderEXT = NULL;
PFNGLGENVERTEXSHADERSEXTPROC glGenVertexShadersEXT = NULL;
PFNGLDELETEVERTEXSHADEREXTPROC glDeleteVertexShaderEXT = NULL;
PFNGLSHADEROP1EXTPROC glShaderOp1EXT = NULL;
PFNGLSHADEROP2EXTPROC glShaderOp2EXT = NULL;
PFNGLSHADEROP3EXTPROC glShaderOp3EXT = NULL;
PFNGLSWIZZLEEXTPROC glSwizzleEXT = NULL;
PFNGLWRITEMASKEXTPROC glWriteMaskEXT = NULL;
PFNGLINSERTCOMPONENTEXTPROC glInsertComponentEXT = NULL;
PFNGLEXTRACTCOMPONENTEXTPROC glExtractComponentEXT = NULL;
PFNGLGENSYMBOLSEXTPROC glGenSymbolsEXT = NULL;
PFNGLSETINVARIANTEXTPROC glSetInvariantEXT = NULL;
PFNGLSETLOCALCONSTANTEXTPROC glSetLocalConstantEXT = NULL;
PFNGLVARIANTBVEXTPROC glVariantbvEXT = NULL;
PFNGLVARIANTSVEXTPROC glVariantsvEXT = NULL;
PFNGLVARIANTIVEXTPROC glVariantivEXT = NULL;
PFNGLVARIANTFVEXTPROC glVariantfvEXT = NULL;
PFNGLVARIANTDVEXTPROC glVariantdvEXT = NULL;
PFNGLVARIANTUBVEXTPROC glVariantubvEXT = NULL;
PFNGLVARIANTUSVEXTPROC glVariantusvEXT = NULL;
PFNGLVARIANTUIVEXTPROC glVariantuivEXT = NULL;
PFNGLVARIANTPOINTEREXTPROC glVariantPointerEXT = NULL;
PFNGLENABLEVARIANTCLIENTSTATEEXTPROC glEnableVariantClientStateEXT = NULL;
PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC glDisableVariantClientStateEXT = NULL;
PFNGLBINDLIGHTPARAMETEREXTPROC glBindLightParameterEXT = NULL;
PFNGLBINDMATERIALPARAMETEREXTPROC glBindMaterialParameterEXT = NULL;
PFNGLBINDTEXGENPARAMETEREXTPROC glBindTexGenParameterEXT = NULL;
PFNGLBINDTEXTUREUNITPARAMETEREXTPROC glBindTextureUnitParameterEXT = NULL;
PFNGLBINDPARAMETEREXTPROC glBindParameterEXT = NULL;
PFNGLISVARIANTENABLEDEXTPROC glIsVariantEnabledEXT = NULL;
PFNGLGETVARIANTBOOLEANVEXTPROC glGetVariantBooleanvEXT = NULL;
PFNGLGETVARIANTINTEGERVEXTPROC glGetVariantIntegervEXT = NULL;
PFNGLGETVARIANTFLOATVEXTPROC glGetVariantFloatvEXT = NULL;
PFNGLGETVARIANTPOINTERVEXTPROC glGetVariantPointervEXT = NULL;
PFNGLGETINVARIANTBOOLEANVEXTPROC glGetInvariantBooleanvEXT = NULL;
PFNGLGETINVARIANTINTEGERVEXTPROC glGetInvariantIntegervEXT = NULL;
PFNGLGETINVARIANTFLOATVEXTPROC glGetInvariantFloatvEXT = NULL;
PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC glGetLocalConstantBooleanvEXT = NULL;
PFNGLGETLOCALCONSTANTINTEGERVEXTPROC glGetLocalConstantIntegervEXT = NULL;
PFNGLGETLOCALCONSTANTFLOATVEXTPROC glGetLocalConstantFloatvEXT = NULL;

static GLboolean _glewInit_EXT_vertex_shader ()
{
  GLboolean r = GL_FALSE;
  r = r || (glBeginVertexShaderEXT = (PFNGLBEGINVERTEXSHADEREXTPROC)glewGetProcAddress("glBeginVertexShaderEXT")) == NULL;
  r = r || (glEndVertexShaderEXT = (PFNGLENDVERTEXSHADEREXTPROC)glewGetProcAddress("glEndVertexShaderEXT")) == NULL;
  r = r || (glBindVertexShaderEXT = (PFNGLBINDVERTEXSHADEREXTPROC)glewGetProcAddress("glBindVertexShaderEXT")) == NULL;
  r = r || (glGenVertexShadersEXT = (PFNGLGENVERTEXSHADERSEXTPROC)glewGetProcAddress("glGenVertexShadersEXT")) == NULL;
  r = r || (glDeleteVertexShaderEXT = (PFNGLDELETEVERTEXSHADEREXTPROC)glewGetProcAddress("glDeleteVertexShaderEXT")) == NULL;
  r = r || (glShaderOp1EXT = (PFNGLSHADEROP1EXTPROC)glewGetProcAddress("glShaderOp1EXT")) == NULL;
  r = r || (glShaderOp2EXT = (PFNGLSHADEROP2EXTPROC)glewGetProcAddress("glShaderOp2EXT")) == NULL;
  r = r || (glShaderOp3EXT = (PFNGLSHADEROP3EXTPROC)glewGetProcAddress("glShaderOp3EXT")) == NULL;
  r = r || (glSwizzleEXT = (PFNGLSWIZZLEEXTPROC)glewGetProcAddress("glSwizzleEXT")) == NULL;
  r = r || (glWriteMaskEXT = (PFNGLWRITEMASKEXTPROC)glewGetProcAddress("glWriteMaskEXT")) == NULL;
  r = r || (glInsertComponentEXT = (PFNGLINSERTCOMPONENTEXTPROC)glewGetProcAddress("glInsertComponentEXT")) == NULL;
  r = r || (glExtractComponentEXT = (PFNGLEXTRACTCOMPONENTEXTPROC)glewGetProcAddress("glExtractComponentEXT")) == NULL;
  r = r || (glGenSymbolsEXT = (PFNGLGENSYMBOLSEXTPROC)glewGetProcAddress("glGenSymbolsEXT")) == NULL;
  r = r || (glSetInvariantEXT = (PFNGLSETINVARIANTEXTPROC)glewGetProcAddress("glSetInvariantEXT")) == NULL;
  r = r || (glSetLocalConstantEXT = (PFNGLSETLOCALCONSTANTEXTPROC)glewGetProcAddress("glSetLocalConstantEXT")) == NULL;
  r = r || (glVariantbvEXT = (PFNGLVARIANTBVEXTPROC)glewGetProcAddress("glVariantbvEXT")) == NULL;
  r = r || (glVariantsvEXT = (PFNGLVARIANTSVEXTPROC)glewGetProcAddress("glVariantsvEXT")) == NULL;
  r = r || (glVariantivEXT = (PFNGLVARIANTIVEXTPROC)glewGetProcAddress("glVariantivEXT")) == NULL;
  r = r || (glVariantfvEXT = (PFNGLVARIANTFVEXTPROC)glewGetProcAddress("glVariantfvEXT")) == NULL;
  r = r || (glVariantdvEXT = (PFNGLVARIANTDVEXTPROC)glewGetProcAddress("glVariantdvEXT")) == NULL;
  r = r || (glVariantubvEXT = (PFNGLVARIANTUBVEXTPROC)glewGetProcAddress("glVariantubvEXT")) == NULL;
  r = r || (glVariantusvEXT = (PFNGLVARIANTUSVEXTPROC)glewGetProcAddress("glVariantusvEXT")) == NULL;
  r = r || (glVariantuivEXT = (PFNGLVARIANTUIVEXTPROC)glewGetProcAddress("glVariantuivEXT")) == NULL;
  r = r || (glVariantPointerEXT = (PFNGLVARIANTPOINTEREXTPROC)glewGetProcAddress("glVariantPointerEXT")) == NULL;
  r = r || (glEnableVariantClientStateEXT = (PFNGLENABLEVARIANTCLIENTSTATEEXTPROC)glewGetProcAddress("glEnableVariantClientStateEXT")) == NULL;
  r = r || (glDisableVariantClientStateEXT = (PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC)glewGetProcAddress("glDisableVariantClientStateEXT")) == NULL;
  r = r || (glBindLightParameterEXT = (PFNGLBINDLIGHTPARAMETEREXTPROC)glewGetProcAddress("glBindLightParameterEXT")) == NULL;
  r = r || (glBindMaterialParameterEXT = (PFNGLBINDMATERIALPARAMETEREXTPROC)glewGetProcAddress("glBindMaterialParameterEXT")) == NULL;
  r = r || (glBindTexGenParameterEXT = (PFNGLBINDTEXGENPARAMETEREXTPROC)glewGetProcAddress("glBindTexGenParameterEXT")) == NULL;
  r = r || (glBindTextureUnitParameterEXT = (PFNGLBINDTEXTUREUNITPARAMETEREXTPROC)glewGetProcAddress("glBindTextureUnitParameterEXT")) == NULL;
  r = r || (glBindParameterEXT = (PFNGLBINDPARAMETEREXTPROC)glewGetProcAddress("glBindParameterEXT")) == NULL;
  r = r || (glIsVariantEnabledEXT = (PFNGLISVARIANTENABLEDEXTPROC)glewGetProcAddress("glIsVariantEnabledEXT")) == NULL;
  r = r || (glGetVariantBooleanvEXT = (PFNGLGETVARIANTBOOLEANVEXTPROC)glewGetProcAddress("glGetVariantBooleanvEXT")) == NULL;
  r = r || (glGetVariantIntegervEXT = (PFNGLGETVARIANTINTEGERVEXTPROC)glewGetProcAddress("glGetVariantIntegervEXT")) == NULL;
  r = r || (glGetVariantFloatvEXT = (PFNGLGETVARIANTFLOATVEXTPROC)glewGetProcAddress("glGetVariantFloatvEXT")) == NULL;
  r = r || (glGetVariantPointervEXT = (PFNGLGETVARIANTPOINTERVEXTPROC)glewGetProcAddress("glGetVariantPointervEXT")) == NULL;
  r = r || (glGetInvariantBooleanvEXT = (PFNGLGETINVARIANTBOOLEANVEXTPROC)glewGetProcAddress("glGetInvariantBooleanvEXT")) == NULL;
  r = r || (glGetInvariantIntegervEXT = (PFNGLGETINVARIANTINTEGERVEXTPROC)glewGetProcAddress("glGetInvariantIntegervEXT")) == NULL;
  r = r || (glGetInvariantFloatvEXT = (PFNGLGETINVARIANTFLOATVEXTPROC)glewGetProcAddress("glGetInvariantFloatvEXT")) == NULL;
  r = r || (glGetLocalConstantBooleanvEXT = (PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC)glewGetProcAddress("glGetLocalConstantBooleanvEXT")) == NULL;
  r = r || (glGetLocalConstantIntegervEXT = (PFNGLGETLOCALCONSTANTINTEGERVEXTPROC)glewGetProcAddress("glGetLocalConstantIntegervEXT")) == NULL;
  r = r || (glGetLocalConstantFloatvEXT = (PFNGLGETLOCALCONSTANTFLOATVEXTPROC)glewGetProcAddress("glGetLocalConstantFloatvEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_vertex_shader */

/* ------------------------- EXT_vertex_weighting ------------------------- */

#ifdef GL_EXT_vertex_weighting
PFNGLVERTEXWEIGHTFEXTPROC glVertexWeightfEXT = NULL;
PFNGLVERTEXWEIGHTFVEXTPROC glVertexWeightfvEXT = NULL;
PFNGLVERTEXWEIGHTPOINTEREXTPROC glVertexWeightPointerEXT = NULL;

static GLboolean _glewInit_EXT_vertex_weighting ()
{
  GLboolean r = GL_FALSE;
  r = r || (glVertexWeightfEXT = (PFNGLVERTEXWEIGHTFEXTPROC)glewGetProcAddress("glVertexWeightfEXT")) == NULL;
  r = r || (glVertexWeightfvEXT = (PFNGLVERTEXWEIGHTFVEXTPROC)glewGetProcAddress("glVertexWeightfvEXT")) == NULL;
  r = r || (glVertexWeightPointerEXT = (PFNGLVERTEXWEIGHTPOINTEREXTPROC)glewGetProcAddress("glVertexWeightPointerEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_vertex_weighting */

/* --------------------------- KTX_buffer_region -------------------------- */

#ifdef GL_KTX_buffer_region
PFNGLBUFFERREGIONENABLEDEXTPROC glBufferRegionEnabledEXT = NULL;
PFNGLNEWBUFFERREGIONEXTPROC glNewBufferRegionEXT = NULL;
PFNGLDELETEBUFFERREGIONEXTPROC glDeleteBufferRegionEXT = NULL;
PFNGLREADBUFFERREGIONEXTPROC glReadBufferRegionEXT = NULL;
PFNGLDRAWBUFFERREGIONEXTPROC glDrawBufferRegionEXT = NULL;

static GLboolean _glewInit_KTX_buffer_region ()
{
  GLboolean r = GL_FALSE;
  r = r || (glBufferRegionEnabledEXT = (PFNGLBUFFERREGIONENABLEDEXTPROC)glewGetProcAddress("glBufferRegionEnabledKTX")) == NULL;
  r = r || (glNewBufferRegionEXT = (PFNGLNEWBUFFERREGIONEXTPROC)glewGetProcAddress("glNewBufferRegionKTX")) == NULL;
  r = r || (glDeleteBufferRegionEXT = (PFNGLDELETEBUFFERREGIONEXTPROC)glewGetProcAddress("glDeleteBufferRegionKTX")) == NULL;
  r = r || (glReadBufferRegionEXT = (PFNGLREADBUFFERREGIONEXTPROC)glewGetProcAddress("glReadBufferRegionKTX")) == NULL;
  r = r || (glDrawBufferRegionEXT = (PFNGLDRAWBUFFERREGIONEXTPROC)glewGetProcAddress("glDrawBufferRegionKTX")) == NULL;
  return r;
}
#endif /* GL_KTX_buffer_region */

/* ------------------------------ WIN_swap_hint --------------------------- */

#ifdef GL_WIN_swap_hint
PFNGLADDSWAPHINTRECTWINPROC glAddSwapHintRectWin = NULL;

static GLboolean _glewInit_WIN_swap_hint ()
{
  GLboolean r = GL_FALSE;
  r = r || (glAddSwapHintRectWin = (PFNGLADDSWAPHINTRECTWINPROC)glewGetProcAddress("glAddSwapHintRectWIN")) == NULL;
  return r;
}
#endif /* GL_WIN_swap_hint */

/* ---------------------------- ATI_draw_buffers -------------------------- */

#ifdef GL_ATI_draw_buffers
PFNGLDRAWBUFFERSATIPROC glDrawBuffersATI = NULL;

static GLboolean _glewInit_ATI_draw_buffers ()
{
  GLboolean r = GL_FALSE;
  r = r || (glDrawBuffersATI = (PFNGLDRAWBUFFERSATIPROC)glewGetProcAddress("glDrawBuffersATI")) == NULL;
  return r;
}
#endif /* GL_ATI_draw_buffers */

/* --------------------------- ATI_element_array -------------------------- */

#ifdef GL_ATI_element_array
PFNGLELEMENTPOINTERATIPROC glElementPointerATI = NULL;
PFNGLDRAWELEMENTARRAYATIPROC glDrawElementArrayATI = NULL;
PFNGLDRAWRANGEELEMENTARRAYATIPROC glDrawRangeElementArrayATI = NULL;

static GLboolean _glewInit_ATI_element_array ()
{
  GLboolean r = GL_FALSE;
  r = r || (glElementPointerATI = (PFNGLELEMENTPOINTERATIPROC)glewGetProcAddress("glElementPointerATI")) == NULL;
  r = r || (glDrawElementArrayATI = (PFNGLDRAWELEMENTARRAYATIPROC)glewGetProcAddress("glDrawElementArrayATI")) == NULL;
  r = r || (glDrawRangeElementArrayATI = (PFNGLDRAWRANGEELEMENTARRAYATIPROC)glewGetProcAddress("glDrawRangeElementArrayATI")) == NULL;
  return r;
}
#endif /* GL_ATI_element_array */

/* -------------------------- ATI_envmap_bumpmap -------------------------- */

#ifdef GL_ATI_envmap_bumpmap
PFNGLTEXBUMPPARAMETERIVATIPROC glTexBumpParameterivATI = NULL;
PFNGLTEXBUMPPARAMETERFVATIPROC glTexBumpParameterfvATI = NULL;
PFNGLGETTEXBUMPPARAMETERIVATIPROC glGetTexBumpParameterivATI = NULL;
PFNGLGETTEXBUMPPARAMETERFVATIPROC glGetTexBumpParameterfvATI = NULL;

static GLboolean _glewInit_ATI_envmap_bumpmap ()
{
  GLboolean r = GL_FALSE;
  r = r || (glTexBumpParameterivATI = (PFNGLTEXBUMPPARAMETERIVATIPROC)glewGetProcAddress("glTexBumpParameterivATI")) == NULL;
  r = r || (glTexBumpParameterfvATI = (PFNGLTEXBUMPPARAMETERFVATIPROC)glewGetProcAddress("glTexBumpParameterfvATI")) == NULL;
  r = r || (glGetTexBumpParameterivATI = (PFNGLGETTEXBUMPPARAMETERIVATIPROC)glewGetProcAddress("glGetTexBumpParameterivATI")) == NULL;
  r = r || (glGetTexBumpParameterfvATI = (PFNGLGETTEXBUMPPARAMETERFVATIPROC)glewGetProcAddress("glGetTexBumpParameterfvATI")) == NULL;
  return r;
}
#endif /* GL_ATI_envmap_bumpmap */

/* ------------------------- ATI_fragment_shader ------------------------- */

#ifdef GL_ATI_fragment_shader
PFNGLGENFRAGMENTSHADERSATIPROC glGenFragmentShadersATI = NULL;
PFNGLBINDFRAGMENTSHADERATIPROC glBindFragmentShaderATI = NULL;
PFNGLDELETEFRAGMENTSHADERATIPROC glDeleteFragmentShaderATI = NULL;
PFNGLBEGINFRAGMENTSHADERATIPROC glBeginFragmentShaderATI = NULL;
PFNGLENDFRAGMENTSHADERATIPROC glEndFragmentShaderATI = NULL;
PFNGLPASSTEXCOORDATIPROC glPassTexCoordATI = NULL;
PFNGLSAMPLEMAPATIPROC glSampleMapATI = NULL;
PFNGLCOLORFRAGMENTOP1ATIPROC glColorFragmentOp1ATI = NULL;
PFNGLCOLORFRAGMENTOP2ATIPROC glColorFragmentOp2ATI = NULL;
PFNGLCOLORFRAGMENTOP3ATIPROC glColorFragmentOp3ATI = NULL;
PFNGLALPHAFRAGMENTOP1ATIPROC glAlphaFragmentOp1ATI = NULL;
PFNGLALPHAFRAGMENTOP2ATIPROC glAlphaFragmentOp2ATI = NULL;
PFNGLALPHAFRAGMENTOP3ATIPROC glAlphaFragmentOp3ATI = NULL;
PFNGLSETFRAGMENTSHADERCONSTANTATIPROC glSetFragmentShaderConstantATI = NULL;

static GLboolean _glewInit_ATI_fragment_shader ()
{
  GLboolean r = GL_FALSE;
  r = r || (glGenFragmentShadersATI = (PFNGLGENFRAGMENTSHADERSATIPROC)glewGetProcAddress("glGenFragmentShadersATI")) == NULL;
  r = r || (glBindFragmentShaderATI = (PFNGLBINDFRAGMENTSHADERATIPROC)glewGetProcAddress("glBindFragmentShaderATI")) == NULL;
  r = r || (glDeleteFragmentShaderATI = (PFNGLDELETEFRAGMENTSHADERATIPROC)glewGetProcAddress("glDeleteFragmentShaderATI")) == NULL;
  r = r || (glBeginFragmentShaderATI = (PFNGLBEGINFRAGMENTSHADERATIPROC)glewGetProcAddress("glBeginFragmentShaderATI")) == NULL;
  r = r || (glEndFragmentShaderATI = (PFNGLENDFRAGMENTSHADERATIPROC)glewGetProcAddress("glEndFragmentShaderATI")) == NULL;
  r = r || (glPassTexCoordATI = (PFNGLPASSTEXCOORDATIPROC)glewGetProcAddress("glPassTexCoordATI")) == NULL;
  r = r || (glSampleMapATI = (PFNGLSAMPLEMAPATIPROC)glewGetProcAddress("glSampleMapATI")) == NULL;
  r = r || (glColorFragmentOp1ATI = (PFNGLCOLORFRAGMENTOP1ATIPROC)glewGetProcAddress("glColorFragmentOp1ATI")) == NULL;
  r = r || (glColorFragmentOp2ATI = (PFNGLCOLORFRAGMENTOP2ATIPROC)glewGetProcAddress("glColorFragmentOp2ATI")) == NULL;
  r = r || (glColorFragmentOp3ATI = (PFNGLCOLORFRAGMENTOP3ATIPROC)glewGetProcAddress("glColorFragmentOp3ATI")) == NULL;
  r = r || (glAlphaFragmentOp1ATI = (PFNGLALPHAFRAGMENTOP1ATIPROC)glewGetProcAddress("glAlphaFragmentOp1ATI")) == NULL;
  r = r || (glAlphaFragmentOp2ATI = (PFNGLALPHAFRAGMENTOP2ATIPROC)glewGetProcAddress("glAlphaFragmentOp2ATI")) == NULL;
  r = r || (glAlphaFragmentOp3ATI = (PFNGLALPHAFRAGMENTOP3ATIPROC)glewGetProcAddress("glAlphaFragmentOp3ATI")) == NULL;
  r = r || (glSetFragmentShaderConstantATI = (PFNGLSETFRAGMENTSHADERCONSTANTATIPROC)glewGetProcAddress("glSetFragmentShaderConstantATI")) == NULL;
  return r;
}
#endif /* GL_ATI_fragment_shader */

/* ------------------------- ATI_map_object_buffer ------------------------ */

#ifdef GL_ATI_map_object_buffer
PFNGLMAPOBJECTBUFFERATIPROC glMapObjectBufferATI = NULL;
PFNGLUNMAPOBJECTBUFFERATIPROC glUnmapObjectBufferATI = NULL;

static GLboolean _glewInit_ATI_map_object_buffer ()
{
  GLboolean r = GL_FALSE;
  r = r || (glMapObjectBufferATI = (PFNGLMAPOBJECTBUFFERATIPROC)glewGetProcAddress("glMapObjectBufferATI")) == NULL;
  r = r || (glUnmapObjectBufferATI = (PFNGLUNMAPOBJECTBUFFERATIPROC)glewGetProcAddress("glUnmapObjectBufferATI")) == NULL;
  return r;
}
#endif /* GL_ATI_map_object_buffer */

/* --------------------------- ATI_pn_triangles --------------------------- */

#ifdef GL_ATI_pn_triangles
PFNGLPNTRIANGLESIATIPROC glPNTrianglesiATI = NULL;
PFNGLPNTRIANGLESFATIPROC glPNTrianglesfATI = NULL;

static GLboolean _glewInit_ATI_pn_triangles ()
{
  GLboolean r = GL_FALSE;
  r = r || (glPNTrianglesiATI = (PFNGLPNTRIANGLESIATIPROC)glewGetProcAddress("glPNTrianglesiATI")) == NULL;
  r = r || (glPNTrianglesfATI = (PFNGLPNTRIANGLESFATIPROC)glewGetProcAddress("glPNTrianglesfATI")) == NULL;
  return r;
}
#endif /* GL_ATI_pn_triangles */

/* -------------------------- ATI_separate_stencil ------------------------ */

#ifdef GL_ATI_separate_stencil
PFNGLSTENCILOPSEPARATEATIPROC glStencilOpSeparateATI = NULL;
PFNGLSTENCILFUNCSEPARATEATIPROC glStencilFuncSeparateATI = NULL;

static GLboolean _glewInit_ATI_separate_stencil ()
{
  GLboolean r = GL_FALSE;
  r = r || (glStencilOpSeparateATI = (PFNGLSTENCILOPSEPARATEATIPROC)glewGetProcAddress("glStencilOpSeparateATI")) == NULL;
  r = r || (glStencilFuncSeparateATI = (PFNGLSTENCILFUNCSEPARATEATIPROC)glewGetProcAddress("glStencilFuncSeparateATI")) == NULL;
  return r;
}
#endif /* GL_ATI_separate_stencil */

/* ------------------------ ATI_vertex_array_object ----------------------- */

#ifdef GL_ATI_vertex_array_object
PFNGLNEWOBJECTBUFFERATIPROC glNewObjectBufferATI = NULL;
PFNGLISOBJECTBUFFERATIPROC glIsObjectBufferATI = NULL;
PFNGLUPDATEOBJECTBUFFERATIPROC glUpdateObjectBufferATI = NULL;
PFNGLGETOBJECTBUFFERFVATIPROC glGetObjectBufferfvATI = NULL;
PFNGLGETOBJECTBUFFERIVATIPROC glGetObjectBufferivATI = NULL;
PFNGLFREEOBJECTBUFFERATIPROC glFreeObjectBufferATI = NULL;
PFNGLARRAYOBJECTATIPROC glArrayObjectATI = NULL;
PFNGLGETARRAYOBJECTFVATIPROC glGetArrayObjectfvATI = NULL;
PFNGLGETARRAYOBJECTIVATIPROC glGetArrayObjectivATI = NULL;
PFNGLVARIANTARRAYOBJECTATIPROC glVariantArrayObjectATI = NULL;
PFNGLGETVARIANTARRAYOBJECTFVATIPROC glGetVariantArrayObjectfvATI = NULL;
PFNGLGETVARIANTARRAYOBJECTIVATIPROC glGetVariantArrayObjectivATI = NULL;

static GLboolean _glewInit_ATI_vertex_array_object ()
{
  GLboolean r = GL_FALSE;
  r = r || (glNewObjectBufferATI = (PFNGLNEWOBJECTBUFFERATIPROC)glewGetProcAddress("glNewObjectBufferATI")) == NULL;
  r = r || (glIsObjectBufferATI = (PFNGLISOBJECTBUFFERATIPROC)glewGetProcAddress("glIsObjectBufferATI")) == NULL;
  r = r || (glUpdateObjectBufferATI = (PFNGLUPDATEOBJECTBUFFERATIPROC)glewGetProcAddress("glUpdateObjectBufferATI")) == NULL;
  r = r || (glGetObjectBufferfvATI = (PFNGLGETOBJECTBUFFERFVATIPROC)glewGetProcAddress("glGetObjectBufferfvATI")) == NULL;
  r = r || (glGetObjectBufferivATI = (PFNGLGETOBJECTBUFFERIVATIPROC)glewGetProcAddress("glGetObjectBufferivATI")) == NULL;
  r = r || (glFreeObjectBufferATI = (PFNGLFREEOBJECTBUFFERATIPROC)glewGetProcAddress("glFreeObjectBufferATI")) == NULL;
  r = r || (glArrayObjectATI = (PFNGLARRAYOBJECTATIPROC)glewGetProcAddress("glArrayObjectATI")) == NULL;
  r = r || (glGetArrayObjectfvATI = (PFNGLGETARRAYOBJECTFVATIPROC)glewGetProcAddress("glGetArrayObjectfvATI")) == NULL;
  r = r || (glGetArrayObjectivATI = (PFNGLGETARRAYOBJECTIVATIPROC)glewGetProcAddress("glGetArrayObjectivATI")) == NULL;
  r = r || (glVariantArrayObjectATI = (PFNGLVARIANTARRAYOBJECTATIPROC)glewGetProcAddress("glVariantArrayObjectATI")) == NULL;
  r = r || (glGetVariantArrayObjectfvATI = (PFNGLGETVARIANTARRAYOBJECTFVATIPROC)glewGetProcAddress("glGetVariantArrayObjectfvATI")) == NULL;
  r = r || (glGetVariantArrayObjectivATI = (PFNGLGETVARIANTARRAYOBJECTIVATIPROC)glewGetProcAddress("glGetVariantArrayObjectivATI")) == NULL;
  return r;
}
#endif /* GL_ATI_vertex_array_object */

/* -------------------- ATI_vertex_attrib_array_object -------------------- */

#ifdef GL_ATI_vertex_attrib_array_object
PFNGLVERTEXATTRIBARRAYOBJECTATIPROC glVertexAttribArrayObjectATI = NULL;
PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC glGetVertexAttribArrayObjectfvATI = NULL;
PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC glGetVertexAttribArrayObjectivATI = NULL;

static GLboolean _glewInit_ATI_vertex_attrib_array_object ()
{
  GLboolean r = GL_FALSE;
  r = r || (glVertexAttribArrayObjectATI = (PFNGLVERTEXATTRIBARRAYOBJECTATIPROC) glewGetProcAddress("glVertexAttribArrayObjectATI")) == NULL;
  r = r || (glGetVertexAttribArrayObjectfvATI = (PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC) glewGetProcAddress("glGetVertexAttribArrayObjectfvATI")) == NULL;
  r = r || (glGetVertexAttribArrayObjectivATI = (PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC) glewGetProcAddress("glGetVertexAttribArrayObjectivATI")) == NULL;
  return r;
}
#endif /* GL_ATI_vertex_attrib_array_object */

/* -------------------------- ATI_vertex_streams -------------------------- */

#ifdef GL_ATI_vertex_streams 
PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC glClientActiveVertexStreamATI = NULL;
PFNGLVERTEXBLENDENVIATIPROC glVertexBlendEnviATI = NULL;
PFNGLVERTEXBLENDENVFATIPROC glVertexBlendEnvfATI = NULL;
PFNGLVERTEXSTREAM2SATIPROC glVertexStream2sATI = NULL;
PFNGLVERTEXSTREAM2SVATIPROC glVertexStream2svATI = NULL;
PFNGLVERTEXSTREAM2IATIPROC glVertexStream2iATI = NULL;
PFNGLVERTEXSTREAM2IVATIPROC glVertexStream2ivATI = NULL;
PFNGLVERTEXSTREAM2FATIPROC glVertexStream2fATI = NULL;
PFNGLVERTEXSTREAM2FVATIPROC glVertexStream2fvATI = NULL;
PFNGLVERTEXSTREAM2DATIPROC glVertexStream2dATI = NULL;
PFNGLVERTEXSTREAM2DVATIPROC glVertexStream2dvATI = NULL;
PFNGLVERTEXSTREAM3SATIPROC glVertexStream3sATI = NULL;
PFNGLVERTEXSTREAM3SVATIPROC glVertexStream3svATI = NULL;
PFNGLVERTEXSTREAM3IATIPROC glVertexStream3iATI = NULL;
PFNGLVERTEXSTREAM3IVATIPROC glVertexStream3ivATI = NULL;
PFNGLVERTEXSTREAM3FATIPROC glVertexStream3fATI = NULL;
PFNGLVERTEXSTREAM3FVATIPROC glVertexStream3fvATI = NULL;
PFNGLVERTEXSTREAM3DATIPROC glVertexStream3dATI = NULL;
PFNGLVERTEXSTREAM3DVATIPROC glVertexStream3dvATI = NULL;
PFNGLVERTEXSTREAM4SATIPROC glVertexStream4sATI = NULL;
PFNGLVERTEXSTREAM4SVATIPROC glVertexStream4svATI = NULL;
PFNGLVERTEXSTREAM4IATIPROC glVertexStream4iATI = NULL;
PFNGLVERTEXSTREAM4IVATIPROC glVertexStream4ivATI = NULL;
PFNGLVERTEXSTREAM4FATIPROC glVertexStream4fATI = NULL;
PFNGLVERTEXSTREAM4FVATIPROC glVertexStream4fvATI = NULL;
PFNGLVERTEXSTREAM4DATIPROC glVertexStream4dATI = NULL;
PFNGLVERTEXSTREAM4DVATIPROC glVertexStream4dvATI = NULL;
PFNGLNORMALSTREAM3BATIPROC glNormalStream3bATI = NULL;
PFNGLNORMALSTREAM3BVATIPROC glNormalStream3bvATI = NULL;
PFNGLNORMALSTREAM3SATIPROC glNormalStream3sATI = NULL;
PFNGLNORMALSTREAM3SVATIPROC glNormalStream3svATI = NULL;
PFNGLNORMALSTREAM3IATIPROC glNormalStream3iATI = NULL;
PFNGLNORMALSTREAM3IVATIPROC glNormalStream3ivATI = NULL;
PFNGLNORMALSTREAM3FATIPROC glNormalStream3fATI = NULL;
PFNGLNORMALSTREAM3FVATIPROC glNormalStream3fvATI = NULL;
PFNGLNORMALSTREAM3DATIPROC glNormalStream3dATI = NULL;
PFNGLNORMALSTREAM3DVATIPROC glNormalStream3dvATI = NULL;

static GLboolean _glewInit_ATI_vertex_streams ()
{
  GLboolean r = GL_FALSE;
  glClientActiveVertexStreamATI = (PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC)glewGetProcAddress("glClientActiveVertexStreamATI");
  r = r || (glVertexBlendEnviATI = (PFNGLVERTEXBLENDENVIATIPROC)glewGetProcAddress("glVertexBlendEnviATI")) == NULL;
  r = r || (glVertexBlendEnvfATI = (PFNGLVERTEXBLENDENVFATIPROC)glewGetProcAddress("glVertexBlendEnvfATI")) == NULL;
  r = r || (glVertexStream2sATI = (PFNGLVERTEXSTREAM2SATIPROC)glewGetProcAddress("glVertexStream2sATI")) == NULL;
  r = r || (glVertexStream2svATI = (PFNGLVERTEXSTREAM2SVATIPROC)glewGetProcAddress("glVertexStream2svATI")) == NULL;
  r = r || (glVertexStream2iATI = (PFNGLVERTEXSTREAM2IATIPROC)glewGetProcAddress("glVertexStream2iATI")) == NULL;
  r = r || (glVertexStream2ivATI = (PFNGLVERTEXSTREAM2IVATIPROC)glewGetProcAddress("glVertexStream2ivATI")) == NULL;
  r = r || (glVertexStream2fATI = (PFNGLVERTEXSTREAM2FATIPROC)glewGetProcAddress("glVertexStream2fATI")) == NULL;
  r = r || (glVertexStream2fvATI = (PFNGLVERTEXSTREAM2FVATIPROC)glewGetProcAddress("glVertexStream2fvATI")) == NULL;
  r = r || (glVertexStream2dATI = (PFNGLVERTEXSTREAM2DATIPROC)glewGetProcAddress("glVertexStream2dATI")) == NULL;
  r = r || (glVertexStream2dvATI = (PFNGLVERTEXSTREAM2DVATIPROC)glewGetProcAddress("glVertexStream2dvATI")) == NULL;
  r = r || (glVertexStream3sATI = (PFNGLVERTEXSTREAM3SATIPROC)glewGetProcAddress("glVertexStream3sATI")) == NULL;
  r = r || (glVertexStream3svATI = (PFNGLVERTEXSTREAM3SVATIPROC)glewGetProcAddress("glVertexStream3svATI")) == NULL;
  r = r || (glVertexStream3iATI = (PFNGLVERTEXSTREAM3IATIPROC)glewGetProcAddress("glVertexStream3iATI")) == NULL;
  r = r || (glVertexStream3ivATI = (PFNGLVERTEXSTREAM3IVATIPROC)glewGetProcAddress("glVertexStream3ivATI")) == NULL;
  r = r || (glVertexStream3fATI = (PFNGLVERTEXSTREAM3FATIPROC)glewGetProcAddress("glVertexStream3fATI")) == NULL;
  r = r || (glVertexStream3fvATI = (PFNGLVERTEXSTREAM3FVATIPROC)glewGetProcAddress("glVertexStream3fvATI")) == NULL;
  r = r || (glVertexStream3dATI = (PFNGLVERTEXSTREAM3DATIPROC)glewGetProcAddress("glVertexStream3dATI")) == NULL;
  r = r || (glVertexStream3dvATI = (PFNGLVERTEXSTREAM3DVATIPROC)glewGetProcAddress("glVertexStream3dvATI")) == NULL;
  r = r || (glVertexStream4sATI = (PFNGLVERTEXSTREAM4SATIPROC)glewGetProcAddress("glVertexStream4sATI")) == NULL;
  r = r || (glVertexStream4svATI = (PFNGLVERTEXSTREAM4SVATIPROC)glewGetProcAddress("glVertexStream4svATI")) == NULL;
  r = r || (glVertexStream4iATI = (PFNGLVERTEXSTREAM4IATIPROC)glewGetProcAddress("glVertexStream4iATI")) == NULL;
  r = r || (glVertexStream4ivATI = (PFNGLVERTEXSTREAM4IVATIPROC)glewGetProcAddress("glVertexStream4ivATI")) == NULL;
  r = r || (glVertexStream4fATI = (PFNGLVERTEXSTREAM4FATIPROC)glewGetProcAddress("glVertexStream4fATI")) == NULL;
  r = r || (glVertexStream4fvATI = (PFNGLVERTEXSTREAM4FVATIPROC)glewGetProcAddress("glVertexStream4fvATI")) == NULL;
  r = r || (glVertexStream4dATI = (PFNGLVERTEXSTREAM4DATIPROC)glewGetProcAddress("glVertexStream4dATI")) == NULL;
  r = r || (glVertexStream4dvATI = (PFNGLVERTEXSTREAM4DVATIPROC)glewGetProcAddress("glVertexStream4dvATI")) == NULL;
  r = r || (glNormalStream3bATI = (PFNGLNORMALSTREAM3BATIPROC)glewGetProcAddress("glNormalStream3bATI")) == NULL;
  r = r || (glNormalStream3bvATI = (PFNGLNORMALSTREAM3BVATIPROC)glewGetProcAddress("glNormalStream3bvATI")) == NULL;
  r = r || (glNormalStream3sATI = (PFNGLNORMALSTREAM3SATIPROC)glewGetProcAddress("glNormalStream3sATI")) == NULL;
  r = r || (glNormalStream3svATI = (PFNGLNORMALSTREAM3SVATIPROC)glewGetProcAddress("glNormalStream3svATI")) == NULL;
  r = r || (glNormalStream3iATI = (PFNGLNORMALSTREAM3IATIPROC)glewGetProcAddress("glNormalStream3iATI")) == NULL;
  r = r || (glNormalStream3ivATI = (PFNGLNORMALSTREAM3IVATIPROC)glewGetProcAddress("glNormalStream3ivATI")) == NULL;
  r = r || (glNormalStream3fATI = (PFNGLNORMALSTREAM3FATIPROC)glewGetProcAddress("glNormalStream3fATI")) == NULL;
  r = r || (glNormalStream3fvATI = (PFNGLNORMALSTREAM3FVATIPROC)glewGetProcAddress("glNormalStream3fvATI")) == NULL;
  r = r || (glNormalStream3dATI = (PFNGLNORMALSTREAM3DATIPROC)glewGetProcAddress("glNormalStream3dATI")) == NULL;
  r = r || (glNormalStream3dvATI = (PFNGLNORMALSTREAM3DVATIPROC)glewGetProcAddress("glNormalStream3dvATI")) == NULL;
  return r;
}
#endif /* GL_ATI_vertex_streams */

/* --------------------------- NV_element_array --------------------------- */

#ifdef GL_NV_element_array
PFNGLELEMENTPOINTERNVPROC glElementPointerNV = NULL;
PFNGLDRAWELEMENTARRAYNVPROC glDrawElementArrayNV = NULL;
PFNGLDRAWRANGEELEMENTARRAYNVPROC glDrawRangeElementArrayNV = NULL;
PFNGLMULTIDRAWELEMENTARRAYNVPROC glMultiDrawElementArrayNV = NULL;
PFNGLMULTIDRAWRANGEELEMENTARRAYNVPROC glMultiDrawRangeElementArrayNV = NULL;

static GLboolean _glewInit_NV_element_array ()
{
  GLboolean r = GL_FALSE;
  r = r || (glElementPointerNV = (PFNGLELEMENTPOINTERNVPROC)glewGetProcAddress("glElementPointerNV")) == NULL;
  r = r || (glDrawElementArrayNV = (PFNGLDRAWELEMENTARRAYNVPROC)glewGetProcAddress("glDrawElementArrayNV")) == NULL;
  r = r || (glDrawRangeElementArrayNV = (PFNGLDRAWRANGEELEMENTARRAYNVPROC)glewGetProcAddress("glDrawRangeElementArrayNV")) == NULL;
  r = r || (glMultiDrawElementArrayNV = (PFNGLMULTIDRAWELEMENTARRAYNVPROC)glewGetProcAddress("glMultiDrawElementArrayNV")) == NULL;
  r = r || (glMultiDrawRangeElementArrayNV = (PFNGLMULTIDRAWRANGEELEMENTARRAYNVPROC)glewGetProcAddress("glMultiDrawRangeElementArrayNV")) == NULL;
  return r;
}
#endif /* GL_NV_element_array */

/* ----------------------------- NV_evaluators ---------------------------- */

#ifdef GL_NV_evaluators
PFNGLMAPCONTROLPOINTSNVPROC glMapControlPointsNV = NULL;
PFNGLMAPPARAMETERIVNVPROC glMapParameterivNV = NULL;
PFNGLMAPPARAMETERFVNVPROC glMapParameterfvNV = NULL;
PFNGLGETMAPCONTROLPOINTSNVPROC glGetMapControlPointsNV = NULL;
PFNGLGETMAPPARAMETERIVNVPROC glGetMapParameterivNV = NULL;
PFNGLGETMAPPARAMETERFVNVPROC glGetMapParameterfvNV = NULL;
PFNGLGETMAPATTRIBPARAMETERIVNVPROC glGetMapAttribParameterivNV = NULL;
PFNGLGETMAPATTRIBPARAMETERFVNVPROC glGetMapAttribParameterfvNV = NULL;
PFNGLEVALMAPSNVPROC glEvalMapsNV = NULL;

static GLboolean _glewInit_NV_evaluators ()
{
  GLboolean r = GL_FALSE;
  r = r || (glMapControlPointsNV = (PFNGLMAPCONTROLPOINTSNVPROC)glewGetProcAddress("glMapControlPointsNV")) == NULL;
  r = r || (glMapParameterivNV = (PFNGLMAPPARAMETERIVNVPROC)glewGetProcAddress("glMapParameterivNV")) == NULL;
  r = r || (glMapParameterfvNV = (PFNGLMAPPARAMETERFVNVPROC)glewGetProcAddress("glMapParameterfvNV")) == NULL;
  r = r || (glGetMapControlPointsNV = (PFNGLGETMAPCONTROLPOINTSNVPROC)glewGetProcAddress("glGetMapControlPointsNV")) == NULL;
  r = r || (glGetMapParameterivNV = (PFNGLGETMAPPARAMETERIVNVPROC)glewGetProcAddress("glGetMapParameterivNV")) == NULL;
  r = r || (glGetMapParameterfvNV = (PFNGLGETMAPPARAMETERFVNVPROC)glewGetProcAddress("glGetMapParameterfvNV")) == NULL;
  r = r || (glGetMapAttribParameterivNV = (PFNGLGETMAPATTRIBPARAMETERIVNVPROC)glewGetProcAddress("glGetMapAttribParameterivNV")) == NULL;
  r = r || (glGetMapAttribParameterfvNV = (PFNGLGETMAPATTRIBPARAMETERFVNVPROC)glewGetProcAddress("glGetMapAttribParameterfvNV")) == NULL;
  r = r || (glEvalMapsNV = (PFNGLEVALMAPSNVPROC)glewGetProcAddress("glEvalMapsNV")) == NULL;
  return r;
}
#endif /* GL_NV_evaluators */

/* -------------------------- NV_fragment_program ------------------------- */

#ifdef GL_NV_fragment_program
PFNGLPROGRAMNAMEDPARAMETER4FNVPROC glProgramNamedParameter4fNV = NULL;
PFNGLPROGRAMNAMEDPARAMETER4DNVPROC glProgramNamedParameter4dNV = NULL;
PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC glProgramNamedParameter4fvNV = NULL;
PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC glProgramNamedParameter4dvNV = NULL;
PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC glGetProgramNamedParameterfvNV = NULL;
PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC glGetProgramNamedParameterdvNV = NULL;
#ifndef GL_ARB_vertex_program
PFNGLPROGRAMLOCALPARAMETER4DARBPROC glProgramLocalParameter4dARB = NULL;
PFNGLPROGRAMLOCALPARAMETER4DVARBPROC glProgramLocalParameter4dvARB = NULL;
PFNGLPROGRAMLOCALPARAMETER4FARBPROC glProgramLocalParameter4fARB = NULL;
PFNGLPROGRAMLOCALPARAMETER4FVARBPROC glProgramLocalParameter4fvARB = NULL;
PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC glGetProgramLocalParameterdvARB = NULL;
PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC glGetProgramLocalParameterfvARB = NULL;
#endif /* GL_ARB_vertex_program */

static GLboolean _glewInit_NV_fragment_program ()
{
  GLboolean r = GL_FALSE;
  r = r || (glProgramNamedParameter4fNV = (PFNGLPROGRAMNAMEDPARAMETER4FNVPROC)glewGetProcAddress("glProgramNamedParameter4fNV")) == NULL;
  r = r || (glProgramNamedParameter4dNV = (PFNGLPROGRAMNAMEDPARAMETER4DNVPROC)glewGetProcAddress("glProgramNamedParameter4dNV")) == NULL;
  r = r || (glProgramNamedParameter4fvNV = (PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC)glewGetProcAddress("glProgramNamedParameter4fvNV")) == NULL;
  r = r || (glProgramNamedParameter4dvNV = (PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC)glewGetProcAddress("glProgramNamedParameter4dvNV")) == NULL;
  r = r || (glGetProgramNamedParameterfvNV = (PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC)glewGetProcAddress("glGetProgramNamedParameterfvNV")) == NULL;
  r = r || (glGetProgramNamedParameterdvNV = (PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC)glewGetProcAddress("glGetProgramNamedParameterdvNV")) == NULL;
#ifndef GL_ARB_vertex_program
  r = r || (glProgramLocalParameter4dARB = (PFNGLPROGRAMLOCALPARAMETER4DARBPROC)glewGetProcAddress("glProgramLocalParameter4dARB")) == NULL;
  r = r || (glProgramLocalParameter4dvARB = (PFNGLPROGRAMLOCALPARAMETER4DVARBPROC)glewGetProcAddress("glProgramLocalParameter4dvARB")) == NULL;
  r = r || (glProgramLocalParameter4fARB = (PFNGLPROGRAMLOCALPARAMETER4FARBPROC)glewGetProcAddress("glProgramLocalParameter4fARB")) == NULL;
  r = r || (glProgramLocalParameter4fvARB = (PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)glewGetProcAddress("glProgramLocalParameter4fvARB")) == NULL;
  r = r || (glGetProgramLocalParameterdvARB = (PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC)glewGetProcAddress("glGetProgramLocalParameterdvARB")) == NULL;
  r = r || (glGetProgramLocalParameterfvARB = (PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)glewGetProcAddress("glGetProgramLocalParameterfvARB")) == NULL;
#endif /* GL_ARB_vertex_program */
  return r;
}
#endif /* GL_NV_fragment_program */

/* ------------------------------- NV_fence ------------------------------- */

#ifdef GL_NV_fence
PFNGLGENFENCESNVPROC glGenFencesNV = NULL;
PFNGLDELETEFENCESNVPROC glDeleteFencesNV = NULL;
PFNGLSETFENCENVPROC glSetFenceNV = NULL;
PFNGLTESTFENCENVPROC glTestFenceNV = NULL;
PFNGLFINISHFENCENVPROC glFinishFenceNV = NULL;
PFNGLISFENCENVPROC glIsFenceNV = NULL;
PFNGLGETFENCEIVNVPROC glGetFenceivNV = NULL;

static GLboolean _glewInit_NV_fence ()
{
  GLboolean r = GL_FALSE;
  r = r || (glGenFencesNV = (PFNGLGENFENCESNVPROC)glewGetProcAddress("glGenFencesNV")) == NULL;
  r = r || (glDeleteFencesNV = (PFNGLDELETEFENCESNVPROC)glewGetProcAddress("glDeleteFencesNV")) == NULL;
  r = r || (glSetFenceNV = (PFNGLSETFENCENVPROC)glewGetProcAddress("glSetFenceNV")) == NULL;
  r = r || (glTestFenceNV = (PFNGLTESTFENCENVPROC)glewGetProcAddress("glTestFenceNV")) == NULL;
  r = r || (glFinishFenceNV = (PFNGLFINISHFENCENVPROC)glewGetProcAddress("glFinishFenceNV")) == NULL;
  r = r || (glIsFenceNV = (PFNGLISFENCENVPROC)glewGetProcAddress("glIsFenceNV")) == NULL;
  r = r || (glGetFenceivNV = (PFNGLGETFENCEIVNVPROC)glewGetProcAddress("glGetFenceivNV")) == NULL;
  return r;
}
#endif /* GL_NV_fence */

/* -------------------------- NV_occlusion_query -------------------------- */

#ifdef GL_NV_occlusion_query
PFNGLGENOCCLUSIONQUERIESNVPROC glGenOcclusionQueriesNV = NULL;
PFNGLDELETEOCCLUSIONQUERIESNVPROC glDeleteOcclusionQueriesNV = NULL;
PFNGLISOCCLUSIONQUERYNVPROC glIsOcclusionQueryNV = NULL;
PFNGLBEGINOCCLUSIONQUERYNVPROC glBeginOcclusionQueryNV = NULL;
PFNGLENDOCCLUSIONQUERYNVPROC glEndOcclusionQueryNV = NULL;
PFNGLGETOCCLUSIONQUERYIVNVPROC glGetOcclusionQueryivNV = NULL;
PFNGLGETOCCLUSIONQUERYUIVNVPROC glGetOcclusionQueryuivNV = NULL;

static GLboolean _glewInit_NV_occlusion_query ()
{
  GLboolean r = GL_FALSE;
  r = r || (glGenOcclusionQueriesNV = (PFNGLGENOCCLUSIONQUERIESNVPROC)glewGetProcAddress("glGenOcclusionQueriesNV")) == NULL;
  r = r || (glDeleteOcclusionQueriesNV = (PFNGLDELETEOCCLUSIONQUERIESNVPROC)glewGetProcAddress("glDeleteOcclusionQueriesNV")) == NULL;
  r = r || (glIsOcclusionQueryNV = (PFNGLISOCCLUSIONQUERYNVPROC)glewGetProcAddress("glIsOcclusionQueryNV")) == NULL;
  r = r || (glBeginOcclusionQueryNV = (PFNGLBEGINOCCLUSIONQUERYNVPROC)glewGetProcAddress("glBeginOcclusionQueryNV")) == NULL;
  r = r || (glEndOcclusionQueryNV = (PFNGLENDOCCLUSIONQUERYNVPROC)glewGetProcAddress("glEndOcclusionQueryNV")) == NULL;
  r = r || (glGetOcclusionQueryivNV = (PFNGLGETOCCLUSIONQUERYIVNVPROC)glewGetProcAddress("glGetOcclusionQueryivNV")) == NULL;
  r = r || (glGetOcclusionQueryuivNV = (PFNGLGETOCCLUSIONQUERYUIVNVPROC)glewGetProcAddress("glGetOcclusionQueryuivNV")) == NULL;
  return r;
}
#endif /* GL_NV_occlusion_query */

/* -------------------------- NV_pixel_data_range ------------------------- */

#ifdef GL_NV_pixel_data_range
PFNGLPIXELDATARANGENVPROC glPixelDataRangeNV = NULL;
PFNGLFLUSHPIXELDATARANGENVPROC glFlushPixelDataRangeNV = NULL;

static GLboolean _glewInit_NV_pixel_data_range ()
{
  GLboolean r = GL_FALSE;
  r = r || (glPixelDataRangeNV = (PFNGLPIXELDATARANGENVPROC)glewGetProcAddress("glPixelDataRangeNV")) == NULL;
  r = r || (glFlushPixelDataRangeNV = (PFNGLFLUSHPIXELDATARANGENVPROC)glewGetProcAddress("glFlushPixelDataRangeNV")) == NULL;
  return r;
}
#endif /* GL_NV_pixel_data_range */

/* ---------------------------- NV_point_sprite --------------------------- */

#ifdef GL_NV_point_sprite
PFNGLPOINTPARAMETERINVPROC glPointParameteriNV = NULL;
PFNGLPOINTPARAMETERIVNVPROC glPointParameterivNV = NULL;

static GLboolean _glewInit_NV_point_sprite ()
{
  GLboolean r = GL_FALSE;
  r = r || (glPointParameteriNV = (PFNGLPOINTPARAMETERINVPROC)glewGetProcAddress("glPointParameteriNV")) == NULL;
  r = r || (glPointParameterivNV = (PFNGLPOINTPARAMETERIVNVPROC)glewGetProcAddress("glPointParameterivNV")) == NULL;
  return r;
}
#endif /* GL_NV_point_sprite */

/* ------------------------- NV_primitive_restart ------------------------- */

#ifdef GL_NV_primitive_restart
PFNGLPRIMITIVERESTARTNVPROC glPrimitiveRestartNV = NULL;
PFNGLPRIMITIVERESTARTINDEXNVPROC glPrimitiveRestartIndexNV = NULL;

static GLboolean _glewInit_NV_primitive_restart ()
{
  GLboolean r = GL_FALSE;
  r = r || (glPrimitiveRestartNV = (PFNGLPRIMITIVERESTARTNVPROC)glewGetProcAddress("glPrimitiveRestartNV")) == NULL;
  r = r || (glPrimitiveRestartIndexNV = (PFNGLPRIMITIVERESTARTINDEXNVPROC)glewGetProcAddress("glPrimitiveRestartIndexNV")) == NULL;
  return r;
}
#endif /* GL_NV_primitive_restart */

/* ------------------------- NV_register_combiners ------------------------ */

#ifdef GL_NV_register_combiners
PFNGLCOMBINERPARAMETERFVNVPROC glCombinerParameterfvNV = NULL;
PFNGLCOMBINERPARAMETERFNVPROC  glCombinerParameterfNV = NULL;
PFNGLCOMBINERPARAMETERIVNVPROC glCombinerParameterivNV = NULL;
PFNGLCOMBINERPARAMETERINVPROC glCombinerParameteriNV = NULL;
PFNGLCOMBINERINPUTNVPROC glCombinerInputNV = NULL;
PFNGLCOMBINEROUTPUTNVPROC glCombinerOutputNV = NULL;
PFNGLFINALCOMBINERINPUTNVPROC glFinalCombinerInputNV = NULL;
PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC glGetCombinerInputParameterfvNV = NULL;
PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC glGetCombinerInputParameterivNV = NULL;
PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC glGetCombinerOutputParameterfvNV = NULL;
PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC glGetCombinerOutputParameterivNV = NULL;
PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC glGetFinalCombinerInputParameterfvNV = NULL;
PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC glGetFinalCombinerInputParameterivNV = NULL;

static GLboolean _glewInit_NV_register_combiners ()
{
  GLboolean r = GL_FALSE;
  r = r || (glCombinerParameterfvNV = (PFNGLCOMBINERPARAMETERFVNVPROC)glewGetProcAddress("glCombinerParameterfvNV")) == NULL;
  r = r || (glCombinerParameterfNV = (PFNGLCOMBINERPARAMETERFNVPROC)glewGetProcAddress("glCombinerParameterfNV")) == NULL;
  r = r || (glCombinerParameterivNV = (PFNGLCOMBINERPARAMETERIVNVPROC)glewGetProcAddress("glCombinerParameterivNV")) == NULL;
  r = r || (glCombinerParameteriNV = (PFNGLCOMBINERPARAMETERINVPROC)glewGetProcAddress("glCombinerParameteriNV")) == NULL;
  r = r || (glCombinerInputNV = (PFNGLCOMBINERINPUTNVPROC)glewGetProcAddress("glCombinerInputNV")) == NULL;
  r = r || (glCombinerOutputNV = (PFNGLCOMBINEROUTPUTNVPROC)glewGetProcAddress("glCombinerOutputNV")) == NULL;
  r = r || (glFinalCombinerInputNV = (PFNGLFINALCOMBINERINPUTNVPROC)glewGetProcAddress("glFinalCombinerInputNV")) == NULL;
  r = r || (glGetCombinerInputParameterfvNV = (PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC)glewGetProcAddress("glGetCombinerInputParameterfvNV")) == NULL;
  r = r || (glGetCombinerInputParameterivNV = (PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC)glewGetProcAddress("glGetCombinerInputParameterivNV")) == NULL;
  r = r || (glGetCombinerOutputParameterfvNV = (PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC)glewGetProcAddress("glGetCombinerOutputParameterfvNV")) == NULL;
  r = r || (glGetCombinerOutputParameterivNV = (PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC)glewGetProcAddress("glGetCombinerOutputParameterivNV")) == NULL;
  r = r || (glGetFinalCombinerInputParameterfvNV = (PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC)glewGetProcAddress("glGetFinalCombinerInputParameterfvNV")) == NULL;
  r = r || (glGetFinalCombinerInputParameterivNV = (PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC)glewGetProcAddress("glGetFinalCombinerInputParameterivNV")) == NULL;
  return r;
}
#endif /* GL_NV_register_combiners */

/* ------------------------ NV_register_combiners2 ------------------------ */

#ifdef GL_NV_register_combiners2
PFNGLCOMBINERSTAGEPARAMETERFVNVPROC glCombinerStageParameterfvNV = NULL;
PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC glGetCombinerStageParameterfvNV = NULL;

static GLboolean _glewInit_NV_register_combiners2 ()
{
  GLboolean r = GL_FALSE;
  r = r || (glCombinerStageParameterfvNV = (PFNGLCOMBINERSTAGEPARAMETERFVNVPROC)glewGetProcAddress("glCombinerStageParameterfvNV")) == NULL;
  r = r || (glGetCombinerStageParameterfvNV = (PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC)glewGetProcAddress("glGetCombinerStageParameterfvNV")) == NULL;
  return r;
}
#endif /* GL_NV_register_combiners2 */

/* ------------------------- NV_vertex_array_range ------------------------ */

#ifdef GL_NV_vertex_array_range
PFNGLFLUSHVERTEXARRAYRANGENVPROC glFlushVertexArrayRangeNV = NULL;
PFNGLVERTEXARRAYRANGENVPROC glVertexArrayRangeNV = NULL;

static GLboolean _glewInit_NV_vertex_array_range ()
{
  GLboolean r = GL_FALSE;
  r = r || (glFlushVertexArrayRangeNV = (PFNGLFLUSHVERTEXARRAYRANGENVPROC)glewGetProcAddress("glFlushVertexArrayRangeNV")) == NULL;
  r = r || (glVertexArrayRangeNV = (PFNGLVERTEXARRAYRANGENVPROC)glewGetProcAddress("glVertexArrayRangeNV")) == NULL;
  return r;
}
#endif /* GL_NV_vertex_array_range */

/* --------------------------- NV_vertex_program -------------------------- */

#ifdef GL_NV_vertex_program
PFNGLBINDPROGRAMNVPROC glBindProgramNV = NULL;
PFNGLDELETEPROGRAMSNVPROC glDeleteProgramsNV = NULL;
PFNGLEXECUTEPROGRAMNVPROC glExecuteProgramNV = NULL;
PFNGLGENPROGRAMSNVPROC glGenProgramsNV = NULL;
PFNGLAREPROGRAMSRESIDENTNVPROC glAreProgramsResidentNV = NULL;
PFNGLREQUESTRESIDENTPROGRAMSNVPROC glRequestResidentProgramsNV = NULL;
PFNGLGETPROGRAMPARAMETERFVNVPROC glGetProgramParameterfvNV = NULL;
PFNGLGETPROGRAMPARAMETERDVNVPROC glGetProgramParameterdvNV = NULL;
PFNGLGETPROGRAMIVNVPROC glGetProgramivNV = NULL;
PFNGLGETPROGRAMSTRINGNVPROC glGetProgramStringNV = NULL;
PFNGLGETTRACKMATRIXIVNVPROC glGetTrackMatrixivNV = NULL;
PFNGLGETVERTEXATTRIBDVNVPROC glGetVertexAttribdvNV = NULL;
PFNGLGETVERTEXATTRIBFVNVPROC glGetVertexAttribfvNV = NULL;
PFNGLGETVERTEXATTRIBIVNVPROC glGetVertexAttribivNV = NULL;
PFNGLGETVERTEXATTRIBPOINTERVNVPROC glGetVertexAttribPointervNV = NULL;
PFNGLISPROGRAMNVPROC glIsProgramNV = NULL;
PFNGLLOADPROGRAMNVPROC glLoadProgramNV = NULL;
PFNGLPROGRAMPARAMETER4FNVPROC glProgramParameter4fNV = NULL;
PFNGLPROGRAMPARAMETER4DNVPROC glProgramParameter4dNV = NULL;
PFNGLPROGRAMPARAMETER4DVNVPROC glProgramParameter4dvNV = NULL;
PFNGLPROGRAMPARAMETER4FVNVPROC glProgramParameter4fvNV = NULL;
PFNGLPROGRAMPARAMETERS4DVNVPROC glProgramParameters4dvNV = NULL;
PFNGLPROGRAMPARAMETERS4FVNVPROC glProgramParameters4fvNV = NULL;
PFNGLTRACKMATRIXNVPROC glTrackMatrixNV = NULL;
PFNGLVERTEXATTRIBPOINTERNVPROC glVertexAttribPointerNV = NULL;
PFNGLVERTEXATTRIB1SNVPROC glVertexAttrib1sNV = NULL;
PFNGLVERTEXATTRIB1FNVPROC glVertexAttrib1fNV = NULL;
PFNGLVERTEXATTRIB1DNVPROC glVertexAttrib1dNV = NULL;
PFNGLVERTEXATTRIB2SNVPROC glVertexAttrib2sNV = NULL;
PFNGLVERTEXATTRIB2FNVPROC glVertexAttrib2fNV = NULL;
PFNGLVERTEXATTRIB2DNVPROC glVertexAttrib2dNV = NULL;
PFNGLVERTEXATTRIB3SNVPROC glVertexAttrib3sNV = NULL;
PFNGLVERTEXATTRIB3FNVPROC glVertexAttrib3fNV = NULL;
PFNGLVERTEXATTRIB3DNVPROC glVertexAttrib3dNV = NULL;
PFNGLVERTEXATTRIB4SNVPROC glVertexAttrib4sNV = NULL;
PFNGLVERTEXATTRIB4FNVPROC glVertexAttrib4fNV = NULL;
PFNGLVERTEXATTRIB4DNVPROC glVertexAttrib4dNV = NULL;
PFNGLVERTEXATTRIB4UBNVPROC glVertexAttrib4ubNV = NULL;
PFNGLVERTEXATTRIB1SVNVPROC glVertexAttrib1svNV = NULL;
PFNGLVERTEXATTRIB1FVNVPROC glVertexAttrib1fvNV = NULL;
PFNGLVERTEXATTRIB1DVNVPROC glVertexAttrib1dvNV = NULL;
PFNGLVERTEXATTRIB2SVNVPROC glVertexAttrib2svNV = NULL;
PFNGLVERTEXATTRIB2FVNVPROC glVertexAttrib2fvNV = NULL;
PFNGLVERTEXATTRIB2DVNVPROC glVertexAttrib2dvNV = NULL;
PFNGLVERTEXATTRIB3SVNVPROC glVertexAttrib3svNV = NULL;
PFNGLVERTEXATTRIB3FVNVPROC glVertexAttrib3fvNV = NULL;
PFNGLVERTEXATTRIB3DVNVPROC glVertexAttrib3dvNV = NULL;
PFNGLVERTEXATTRIB4SVNVPROC glVertexAttrib4svNV = NULL;
PFNGLVERTEXATTRIB4FVNVPROC glVertexAttrib4fvNV = NULL;
PFNGLVERTEXATTRIB4DVNVPROC glVertexAttrib4dvNV = NULL;
PFNGLVERTEXATTRIB4UBVNVPROC glVertexAttrib4ubvNV = NULL;
PFNGLVERTEXATTRIBS1SVNVPROC glVertexAttribs1svNV = NULL;
PFNGLVERTEXATTRIBS1FVNVPROC glVertexAttribs1fvNV = NULL;
PFNGLVERTEXATTRIBS1DVNVPROC glVertexAttribs1dvNV = NULL;
PFNGLVERTEXATTRIBS2SVNVPROC glVertexAttribs2svNV = NULL;
PFNGLVERTEXATTRIBS2FVNVPROC glVertexAttribs2fvNV = NULL;
PFNGLVERTEXATTRIBS2DVNVPROC glVertexAttribs2dvNV = NULL;
PFNGLVERTEXATTRIBS3SVNVPROC glVertexAttribs3svNV = NULL;
PFNGLVERTEXATTRIBS3FVNVPROC glVertexAttribs3fvNV = NULL;
PFNGLVERTEXATTRIBS3DVNVPROC glVertexAttribs3dvNV = NULL;
PFNGLVERTEXATTRIBS4SVNVPROC glVertexAttribs4svNV = NULL;
PFNGLVERTEXATTRIBS4FVNVPROC glVertexAttribs4fvNV = NULL;
PFNGLVERTEXATTRIBS4DVNVPROC glVertexAttribs4dvNV = NULL;
PFNGLVERTEXATTRIBS4UBVNVPROC glVertexAttribs4ubvNV = NULL;

static GLboolean _glewInit_NV_vertex_program ()
{
  GLboolean r = GL_FALSE;
  r = r || (glBindProgramNV = (PFNGLBINDPROGRAMNVPROC)glewGetProcAddress("glBindProgramNV")) == NULL;
  r = r || (glDeleteProgramsNV = (PFNGLDELETEPROGRAMSNVPROC)glewGetProcAddress("glDeleteProgramsNV")) == NULL;
  r = r || (glExecuteProgramNV = (PFNGLEXECUTEPROGRAMNVPROC)glewGetProcAddress("glExecuteProgramNV")) == NULL;
  r = r || (glGenProgramsNV = (PFNGLGENPROGRAMSNVPROC)glewGetProcAddress("glGenProgramsNV")) == NULL;
  r = r || (glAreProgramsResidentNV = (PFNGLAREPROGRAMSRESIDENTNVPROC)glewGetProcAddress("glAreProgramsResidentNV")) == NULL;
  r = r || (glRequestResidentProgramsNV = (PFNGLREQUESTRESIDENTPROGRAMSNVPROC)glewGetProcAddress("glRequestResidentProgramsNV")) == NULL;
  r = r || (glGetProgramParameterfvNV = (PFNGLGETPROGRAMPARAMETERFVNVPROC)glewGetProcAddress("glGetProgramParameterfvNV")) == NULL;
  r = r || (glGetProgramParameterdvNV = (PFNGLGETPROGRAMPARAMETERDVNVPROC)glewGetProcAddress("glGetProgramParameterdvNV")) == NULL;
  r = r || (glGetProgramivNV = (PFNGLGETPROGRAMIVNVPROC)glewGetProcAddress("glGetProgramivNV")) == NULL;
  r = r || (glGetProgramStringNV = (PFNGLGETPROGRAMSTRINGNVPROC)glewGetProcAddress("glGetProgramStringNV")) == NULL;
  r = r || (glGetTrackMatrixivNV = (PFNGLGETTRACKMATRIXIVNVPROC)glewGetProcAddress("glGetTrackMatrixivNV")) == NULL;
  r = r || (glGetVertexAttribdvNV = (PFNGLGETVERTEXATTRIBDVNVPROC)glewGetProcAddress("glGetVertexAttribdvNV")) == NULL;
  r = r || (glGetVertexAttribfvNV = (PFNGLGETVERTEXATTRIBFVNVPROC)glewGetProcAddress("glGetVertexAttribfvNV")) == NULL;
  r = r || (glGetVertexAttribivNV = (PFNGLGETVERTEXATTRIBIVNVPROC)glewGetProcAddress("glGetVertexAttribivNV")) == NULL;
  r = r || (glGetVertexAttribPointervNV = (PFNGLGETVERTEXATTRIBPOINTERVNVPROC)glewGetProcAddress("glGetVertexAttribPointervNV")) == NULL;
  r = r || (glIsProgramNV = (PFNGLISPROGRAMNVPROC)glewGetProcAddress("glIsProgramNV")) == NULL;
  r = r || (glLoadProgramNV = (PFNGLLOADPROGRAMNVPROC)glewGetProcAddress("glLoadProgramNV")) == NULL;
  r = r || (glProgramParameter4fNV = (PFNGLPROGRAMPARAMETER4FNVPROC)glewGetProcAddress("glProgramParameter4fNV")) == NULL;
  r = r || (glProgramParameter4dNV = (PFNGLPROGRAMPARAMETER4DNVPROC)glewGetProcAddress("glProgramParameter4dNV")) == NULL;
  r = r || (glProgramParameter4dvNV = (PFNGLPROGRAMPARAMETER4DVNVPROC)glewGetProcAddress("glProgramParameter4dvNV")) == NULL;
  r = r || (glProgramParameter4fvNV = (PFNGLPROGRAMPARAMETER4FVNVPROC)glewGetProcAddress("glProgramParameter4fvNV")) == NULL;
  r = r || (glProgramParameters4dvNV = (PFNGLPROGRAMPARAMETERS4DVNVPROC)glewGetProcAddress("glProgramParameters4dvNV")) == NULL;
  r = r || (glProgramParameters4fvNV = (PFNGLPROGRAMPARAMETERS4FVNVPROC)glewGetProcAddress("glProgramParameters4fvNV")) == NULL;
  r = r || (glTrackMatrixNV = (PFNGLTRACKMATRIXNVPROC)glewGetProcAddress("glTrackMatrixNV")) == NULL;
  r = r || (glVertexAttribPointerNV = (PFNGLVERTEXATTRIBPOINTERNVPROC)glewGetProcAddress("glVertexAttribPointerNV")) == NULL;
  r = r || (glVertexAttrib1sNV = (PFNGLVERTEXATTRIB1SNVPROC)glewGetProcAddress("glVertexAttrib1sNV")) == NULL;
  r = r || (glVertexAttrib1fNV = (PFNGLVERTEXATTRIB1FNVPROC)glewGetProcAddress("glVertexAttrib1fNV")) == NULL;
  r = r || (glVertexAttrib1dNV = (PFNGLVERTEXATTRIB1DNVPROC)glewGetProcAddress("glVertexAttrib1dNV")) == NULL;
  r = r || (glVertexAttrib2sNV = (PFNGLVERTEXATTRIB2SNVPROC)glewGetProcAddress("glVertexAttrib2sNV")) == NULL;
  r = r || (glVertexAttrib2fNV = (PFNGLVERTEXATTRIB2FNVPROC)glewGetProcAddress("glVertexAttrib2fNV")) == NULL;
  r = r || (glVertexAttrib2dNV = (PFNGLVERTEXATTRIB2DNVPROC)glewGetProcAddress("glVertexAttrib2dNV")) == NULL;
  r = r || (glVertexAttrib3sNV = (PFNGLVERTEXATTRIB3SNVPROC)glewGetProcAddress("glVertexAttrib3sNV")) == NULL;
  r = r || (glVertexAttrib3fNV = (PFNGLVERTEXATTRIB3FNVPROC)glewGetProcAddress("glVertexAttrib3fNV")) == NULL;
  r = r || (glVertexAttrib3dNV = (PFNGLVERTEXATTRIB3DNVPROC)glewGetProcAddress("glVertexAttrib3dNV")) == NULL;
  r = r || (glVertexAttrib4sNV = (PFNGLVERTEXATTRIB4SNVPROC)glewGetProcAddress("glVertexAttrib4sNV")) == NULL;
  r = r || (glVertexAttrib4fNV = (PFNGLVERTEXATTRIB4FNVPROC)glewGetProcAddress("glVertexAttrib4fNV")) == NULL;
  r = r || (glVertexAttrib4dNV = (PFNGLVERTEXATTRIB4DNVPROC)glewGetProcAddress("glVertexAttrib4dNV")) == NULL;
  r = r || (glVertexAttrib4ubNV = (PFNGLVERTEXATTRIB4UBNVPROC)glewGetProcAddress("glVertexAttrib4ubNV")) == NULL;
  r = r || (glVertexAttrib1svNV = (PFNGLVERTEXATTRIB1SVNVPROC)glewGetProcAddress("glVertexAttrib1svNV")) == NULL;
  r = r || (glVertexAttrib1fvNV = (PFNGLVERTEXATTRIB1FVNVPROC)glewGetProcAddress("glVertexAttrib1fvNV")) == NULL;
  r = r || (glVertexAttrib1dvNV = (PFNGLVERTEXATTRIB1DVNVPROC)glewGetProcAddress("glVertexAttrib1dvNV")) == NULL;
  r = r || (glVertexAttrib2svNV = (PFNGLVERTEXATTRIB2SVNVPROC)glewGetProcAddress("glVertexAttrib2svNV")) == NULL;
  r = r || (glVertexAttrib2fvNV = (PFNGLVERTEXATTRIB2FVNVPROC)glewGetProcAddress("glVertexAttrib2fvNV")) == NULL;
  r = r || (glVertexAttrib2dvNV = (PFNGLVERTEXATTRIB2DVNVPROC)glewGetProcAddress("glVertexAttrib2dvNV")) == NULL;
  r = r || (glVertexAttrib3svNV = (PFNGLVERTEXATTRIB3SVNVPROC)glewGetProcAddress("glVertexAttrib3svNV")) == NULL;
  r = r || (glVertexAttrib3fvNV = (PFNGLVERTEXATTRIB3FVNVPROC)glewGetProcAddress("glVertexAttrib3fvNV")) == NULL;
  r = r || (glVertexAttrib3dvNV = (PFNGLVERTEXATTRIB3DVNVPROC)glewGetProcAddress("glVertexAttrib3dvNV")) == NULL;
  r = r || (glVertexAttrib4svNV = (PFNGLVERTEXATTRIB4SVNVPROC)glewGetProcAddress("glVertexAttrib4svNV")) == NULL;
  r = r || (glVertexAttrib4fvNV = (PFNGLVERTEXATTRIB4FVNVPROC)glewGetProcAddress("glVertexAttrib4fvNV")) == NULL;
  r = r || (glVertexAttrib4dvNV = (PFNGLVERTEXATTRIB4DVNVPROC)glewGetProcAddress("glVertexAttrib4dvNV")) == NULL;
  r = r || (glVertexAttrib4ubvNV = (PFNGLVERTEXATTRIB4UBVNVPROC)glewGetProcAddress("glVertexAttrib4ubvNV")) == NULL;
  r = r || (glVertexAttribs1svNV = (PFNGLVERTEXATTRIBS1SVNVPROC)glewGetProcAddress("glVertexAttribs1svNV")) == NULL;
  r = r || (glVertexAttribs1fvNV = (PFNGLVERTEXATTRIBS1FVNVPROC)glewGetProcAddress("glVertexAttribs1fvNV")) == NULL;
  r = r || (glVertexAttribs1dvNV = (PFNGLVERTEXATTRIBS1DVNVPROC)glewGetProcAddress("glVertexAttribs1dvNV")) == NULL;
  r = r || (glVertexAttribs2svNV = (PFNGLVERTEXATTRIBS2SVNVPROC)glewGetProcAddress("glVertexAttribs2svNV")) == NULL;
  r = r || (glVertexAttribs2fvNV = (PFNGLVERTEXATTRIBS2FVNVPROC)glewGetProcAddress("glVertexAttribs2fvNV")) == NULL;
  r = r || (glVertexAttribs2dvNV = (PFNGLVERTEXATTRIBS2DVNVPROC)glewGetProcAddress("glVertexAttribs2dvNV")) == NULL;
  r = r || (glVertexAttribs3svNV = (PFNGLVERTEXATTRIBS3SVNVPROC)glewGetProcAddress("glVertexAttribs3svNV")) == NULL;
  r = r || (glVertexAttribs3fvNV = (PFNGLVERTEXATTRIBS3FVNVPROC)glewGetProcAddress("glVertexAttribs3fvNV")) == NULL;
  r = r || (glVertexAttribs3dvNV = (PFNGLVERTEXATTRIBS3DVNVPROC)glewGetProcAddress("glVertexAttribs3dvNV")) == NULL;
  r = r || (glVertexAttribs4svNV = (PFNGLVERTEXATTRIBS4SVNVPROC)glewGetProcAddress("glVertexAttribs4svNV")) == NULL;
  r = r || (glVertexAttribs4fvNV = (PFNGLVERTEXATTRIBS4FVNVPROC)glewGetProcAddress("glVertexAttribs4fvNV")) == NULL;
  r = r || (glVertexAttribs4dvNV = (PFNGLVERTEXATTRIBS4DVNVPROC)glewGetProcAddress("glVertexAttribs4dvNV")) == NULL;
  r = r || (glVertexAttribs4ubvNV = (PFNGLVERTEXATTRIBS4UBVNVPROC)glewGetProcAddress("glVertexAttribs4ubvNV")) == NULL;
  return r;
}
#endif /* GL_NV_vertex_program */

#ifdef _WIN32

/* ---------------------------- ARB_buffer_region ------------------------- */

#ifdef WGL_ARB_buffer_region
PFNWGLCREATEBUFFERREGIONARBPROC wglCreateBufferRegionARB = NULL;
PFNWGLDELETEBUFFERREGIONARBPROC wglDeleteBufferRegionARB = NULL;
PFNWGLSAVEBUFFERREGIONARBPROC wglSaveBufferRegionARB = NULL;
PFNWGLRESTOREBUFFERREGIONARBPROC wglRestoreBufferRegionARB = NULL;

static GLboolean _wglewInit_ARB_buffer_region ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglCreateBufferRegionARB = (PFNWGLCREATEBUFFERREGIONARBPROC)glewGetProcAddress("wglCreateBufferRegionARB")) == NULL;
  r = r || (wglDeleteBufferRegionARB = (PFNWGLDELETEBUFFERREGIONARBPROC)glewGetProcAddress("wglDeleteBufferRegionARB")) == NULL;
  r = r || (wglSaveBufferRegionARB = (PFNWGLSAVEBUFFERREGIONARBPROC)glewGetProcAddress("wglSaveBufferRegionARB")) == NULL;
  r = r || (wglRestoreBufferRegionARB = (PFNWGLRESTOREBUFFERREGIONARBPROC)glewGetProcAddress("wglRestoreBufferRegionARB")) == NULL;
  return r;
}
#endif /* WGL_ARB_buffer_region */

/* -------------------------- ARB_extensions_string ----------------------- */

#ifdef WGL_ARB_extensions_string
PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB = NULL;

static GLboolean _wglewInit_ARB_extensions_string ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC)glewGetProcAddress("wglGetExtensionsStringARB")) == NULL;
  return r;
}
#endif /* WGL_ARB_extensions_string */

/* -------------------------- ARB_make_current_read ----------------------- */

#ifdef WGL_ARB_make_current_read
PFNWGLMAKECONTEXTCURRENTARBPROC wglMakeContextCurrentARB = NULL;
PFNWGLGETCURRENTREADDCARBPROC wglGetCurrentReadDCARB = NULL;

static GLboolean _wglewInit_ARB_make_current_read ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglMakeContextCurrentARB = (PFNWGLMAKECONTEXTCURRENTARBPROC)glewGetProcAddress("wglMakeContextCurrentARB")) == NULL;
  r = r || (wglGetCurrentReadDCARB = (PFNWGLGETCURRENTREADDCARBPROC)glewGetProcAddress("wglGetCurrentReadDCARB")) == NULL;
  return r;
}
#endif /* WGL_ARB_make_current_read */

/* ------------------------------ ARB_pbuffer ----------------------------- */

#ifdef WGL_ARB_pbuffer
PFNWGLCREATEPBUFFERARBPROC wglCreatePbufferARB = NULL;
PFNWGLGETPBUFFERDCARBPROC wglGetPbufferDCARB = NULL;
PFNWGLRELEASEPBUFFERDCARBPROC wglReleasePbufferDCARB = NULL;
PFNWGLDESTROYPBUFFERARBPROC wglDestroyPbufferARB = NULL;
PFNWGLQUERYPBUFFERARBPROC wglQueryPbufferARB = NULL;

static GLboolean _wglewInit_ARB_pbuffer ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglCreatePbufferARB = (PFNWGLCREATEPBUFFERARBPROC)glewGetProcAddress("wglCreatePbufferARB")) == NULL;
  r = r || (wglGetPbufferDCARB = (PFNWGLGETPBUFFERDCARBPROC)glewGetProcAddress("wglGetPbufferDCARB")) == NULL;
  r = r || (wglReleasePbufferDCARB = (PFNWGLRELEASEPBUFFERDCARBPROC)glewGetProcAddress("wglReleasePbufferDCARB")) == NULL;
  r = r || (wglDestroyPbufferARB = (PFNWGLDESTROYPBUFFERARBPROC)glewGetProcAddress("wglDestroyPbufferARB")) == NULL;
  r = r || (wglQueryPbufferARB = (PFNWGLQUERYPBUFFERARBPROC)glewGetProcAddress("wglQueryPbufferARB")) == NULL;
  return r;
}
#endif /* WGL_ARB_pbuffer */

/* --------------------------- ARB_pixel_format --------------------------- */

#ifdef WGL_ARB_pixel_format
PFNWGLGETPIXELFORMATATTRIBIVARBPROC wglGetPixelFormatAttribivARB = NULL;
PFNWGLGETPIXELFORMATATTRIBFVARBPROC wglGetPixelFormatAttribfvARB = NULL;
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = NULL;

static GLboolean _wglewInit_ARB_pixel_format ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglGetPixelFormatAttribivARB = (PFNWGLGETPIXELFORMATATTRIBIVARBPROC)glewGetProcAddress("wglGetPixelFormatAttribivARB")) == NULL;
  r = r || (wglGetPixelFormatAttribfvARB = (PFNWGLGETPIXELFORMATATTRIBFVARBPROC)glewGetProcAddress("wglGetPixelFormatAttribfvARB")) == NULL;
  r = r || (wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)glewGetProcAddress("wglChoosePixelFormatARB")) == NULL;
  return r;
}
#endif /* WGL_ARB_pixel_format */

/* -------------------------- ARB_render_texture -------------------------- */

#ifdef WGL_ARB_render_texture
PFNWGLBINDTEXIMAGEARBPROC wglBindTexImageARB = NULL;
PFNWGLRELEASETEXIMAGEARBPROC wglReleaseTexImageARB = NULL;
PFNWGLSETPBUFFERATTRIBARBPROC wglSetPbufferAttribARB = NULL;

static GLboolean _wglewInit_ARB_render_texture ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglBindTexImageARB = (PFNWGLBINDTEXIMAGEARBPROC)glewGetProcAddress("wglBindTexImageARB")) == NULL;
  r = r || (wglReleaseTexImageARB = (PFNWGLRELEASETEXIMAGEARBPROC)glewGetProcAddress("wglReleaseTexImageARB")) == NULL;
  r = r || (wglSetPbufferAttribARB = (PFNWGLSETPBUFFERATTRIBARBPROC)glewGetProcAddress("wglSetPbufferAttribARB")) == NULL;
  return r;
}
#endif /* WGL_ARB_render_texture */

/* ------------------------- EXT_display_color_table ---------------------- */

#ifdef WGL_EXT_display_color_table

PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC wglCreateDisplayColorTableEXT = NULL;
PFNWGLLOADDISPLAYCOLORTABLEEXTPROC wglLoadDisplayColorTableEXT = NULL;
PFNWGLBINDDISPLAYCOLORTABLEEXTPROC wglBindDisplayColorTableEXT = NULL;
PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC wglDestroyDisplayColorTableEXT = NULL;

static GLboolean _wglewInit_EXT_display_color_table ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglCreateDisplayColorTableEXT = (PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC)glewGetProcAddress("wglCreateDisplayColorTableEXT")) == NULL;
  r = r || (wglLoadDisplayColorTableEXT = (PFNWGLLOADDISPLAYCOLORTABLEEXTPROC)glewGetProcAddress("wglLoadDisplayColorTableEXT")) == NULL;
  r = r || (wglBindDisplayColorTableEXT = (PFNWGLBINDDISPLAYCOLORTABLEEXTPROC)glewGetProcAddress("wglBindDisplayColorTableEXT")) == NULL;
  r = r || (wglDestroyDisplayColorTableEXT = (PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC)glewGetProcAddress("wglDestroyDisplayColorTableEXT")) == NULL;
  return r;
}
#endif /* WGL_EXT_display_color_table */

/* -------------------------- EXT_make_current_read ----------------------- */

#ifdef WGL_EXT_make_current_read

PFNWGLMAKECONTEXTCURRENTEXTPROC wglMakeContextCurrentEXT = NULL;
PFNWGLGETCURRENTREADDCEXTPROC wglGetCurrentReadDCEXT = NULL;

static GLboolean _wglewInit_EXT_make_current_read ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglMakeContextCurrentEXT = (PFNWGLMAKECONTEXTCURRENTEXTPROC)glewGetProcAddress("wglMakeContextCurrentEXT")) == NULL;
  r = r || (wglGetCurrentReadDCEXT = (PFNWGLGETCURRENTREADDCEXTPROC)glewGetProcAddress("wglGetCurrentReadDCEXT")) == NULL;
  return r;
}
#endif /* WGL_EXT_make_current_read */

/* ------------------------- EXT_extensions_string ------------------------ */

#ifdef WGL_EXT_extensions_string
PFNWGLGETEXTENSIONSSTRINGEXTPROC wglGetExtensionsStringEXT = NULL;

static GLboolean _wglewInit_EXT_extensions_string ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglGetExtensionsStringEXT = (PFNWGLGETEXTENSIONSSTRINGEXTPROC)glewGetProcAddress("wglGetExtensionsStringEXT")) == NULL;
  return r;
}
#endif /* WGL_EXT_extensions_string */

/* ----------------------------- EXT_pixel_format ------------------------- */

#ifdef WGL_EXT_pixel_format

PFNWGLGETPIXELFORMATATTRIBIVEXTPROC wglGetPixelFormatAttribivEXT = NULL;
PFNWGLGETPIXELFORMATATTRIBFVEXTPROC wglGetPixelFormatAttribfvEXT = NULL;
PFNWGLCHOOSEPIXELFORMATEXTPROC wglChoosePixelFormatEXT = NULL;

static GLboolean _wglewInit_EXT_pixel_format ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglGetPixelFormatAttribivEXT = (PFNWGLGETPIXELFORMATATTRIBIVEXTPROC)glewGetProcAddress("wglGetPixelFormatAttribivEXT")) == NULL;
  r = r || (wglGetPixelFormatAttribfvEXT = (PFNWGLGETPIXELFORMATATTRIBFVEXTPROC)glewGetProcAddress("wglGetPixelFormatAttribfvEXT")) == NULL;
  r = r || (wglChoosePixelFormatEXT = (PFNWGLCHOOSEPIXELFORMATEXTPROC)glewGetProcAddress("wglChoosePixelFormatEXT")) == NULL;
  return r;
}

#endif /* WGL_EXT_pixel_format */

/* ------------------------------- EXT_pbuffer ---------------------------- */

#ifdef WGL_EXT_pbuffer

PFNWGLCREATEPBUFFEREXTPROC wglCreatePbufferEXT = NULL;
PFNWGLGETPBUFFERDCEXTPROC wglGetPbufferDCEXT = NULL;
PFNWGLRELEASEPBUFFERDCEXTPROC wglReleasePbufferDCEXT = NULL;
PFNWGLDESTROYPBUFFEREXTPROC wglDestroyPbufferEXT = NULL;
PFNWGLQUERYPBUFFEREXTPROC wglQueryPbufferEXT = NULL;

static GLboolean _wglewInit_EXT_pbuffer ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglCreatePbufferEXT = (PFNWGLCREATEPBUFFEREXTPROC)glewGetProcAddress("wglCreatePbufferEXT")) == NULL;
  r = r || (wglGetPbufferDCEXT = (PFNWGLGETPBUFFERDCEXTPROC)glewGetProcAddress("wglGetPbufferDCEXT")) == NULL;
  r = r || (wglReleasePbufferDCEXT = (PFNWGLRELEASEPBUFFERDCEXTPROC)glewGetProcAddress("wglReleasePbufferDCEXT")) == NULL;
  r = r || (wglDestroyPbufferEXT = (PFNWGLDESTROYPBUFFEREXTPROC)glewGetProcAddress("wglDestroyPbufferEXT")) == NULL;
  r = r || (wglQueryPbufferEXT = (PFNWGLQUERYPBUFFEREXTPROC)glewGetProcAddress("wglQueryPbufferEXT")) == NULL;
  return r;
}

#endif /* WGL_EXT_pbuffer */

/* --------------------------- EXT_swap_control --------------------------- */

#ifdef WGL_EXT_swap_control
PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = NULL;
PFNWGLGETSWAPINTERVALEXTPROC wglGetSwapIntervalEXT = NULL;

static GLboolean _wglewInit_EXT_swap_control ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)glewGetProcAddress("wglSwapIntervalEXT")) == NULL;
  r = r || (wglGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALEXTPROC)glewGetProcAddress("wglGetSwapIntervalEXT")) == NULL;
  return r;
}
#endif /* WGL_EXT_swap_control */

/* ------------------------ I3D_digital_video_control --------------------- */

#ifdef WGL_I3D_digital_video_control
PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC wglGetDigitalVideoParametersI3D = NULL;
PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC wglSetDigitalVideoParametersI3D = NULL;

static GLboolean _wglewInit_I3D_digital_video_control ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglGetDigitalVideoParametersI3D = (PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC)glewGetProcAddress("wglGetDigitalVideoParametersI3D")) == NULL;
  r = r || (wglSetDigitalVideoParametersI3D = (PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC)glewGetProcAddress("wglSetDigitalVideoParametersI3D")) == NULL;
  return r;
}
#endif /* WGL_I3D_digital_video_control */

/* -------------------------------- I3D_gamma ----------------------------- */

#ifdef WGL_I3D_gamma
PFNWGLGETGAMMATABLEPARAMETERSI3DPROC wglGetGammaTableParametersI3D = NULL;
PFNWGLSETGAMMATABLEPARAMETERSI3DPROC wglSetGammaTableParametersI3D = NULL;
PFNWGLGETGAMMATABLEI3DPROC wglGetGammaTableI3D = NULL;
PFNWGLSETGAMMATABLEI3DPROC wglSetGammaTableI3D = NULL;

static GLboolean _wglewInit_I3D_gamma ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglGetGammaTableParametersI3D = (PFNWGLGETGAMMATABLEPARAMETERSI3DPROC)glewGetProcAddress("wglGetGammaTableParametersI3D")) == NULL;
  r = r || (wglSetGammaTableParametersI3D = (PFNWGLSETGAMMATABLEPARAMETERSI3DPROC)glewGetProcAddress("wglSetGammaTableParametersI3D")) == NULL;
  r = r || (wglGetGammaTableI3D = (PFNWGLGETGAMMATABLEI3DPROC)glewGetProcAddress("wglGetGammaTableI3D")) == NULL;
  r = r || (wglSetGammaTableI3D = (PFNWGLSETGAMMATABLEI3DPROC)glewGetProcAddress("wglSetGammaTableI3D")) == NULL;
  return r;
}
#endif /* WGL_I3D_gamma */

/* ------------------------------- I3D_genlock ---------------------------- */

#ifdef WGL_I3D_genlock
PFNWGLENABLEGENLOCKI3DPROC wglEnableGenlockI3D = NULL;
PFNWGLDISABLEGENLOCKI3DPROC wglDisableGenlockI3D = NULL;
PFNWGLISENABLEDGENLOCKI3DPROC wglIsEnabledGenlockI3D = NULL;
PFNWGLGENLOCKSOURCEI3DPROC wglGenlockSourceI3D = NULL;
PFNWGLGETGENLOCKSOURCEI3DPROC wglGetGenlockSourceI3D = NULL;
PFNWGLGENLOCKSOURCEEDGEI3DPROC wglGenlockSourceEdgeI3D = NULL;
PFNWGLGETGENLOCKSOURCEEDGEI3DPROC wglGetGenlockSourceEdgeI3D = NULL;
PFNWGLGENLOCKSAMPLERATEI3DPROC wglGenlockSampleRateI3D = NULL;
PFNWGLGETGENLOCKSAMPLERATEI3DPROC wglGetGenlockSampleRateI3D = NULL;
PFNWGLGENLOCKSOURCEDELAYI3DPROC wglGenlockSourceDelayI3D = NULL;
PFNWGLGETGENLOCKSOURCEDELAYI3DPROC wglGetGenlockSourceDelayI3D = NULL;
PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC wglQueryGenlockMaxSourceDelayI3D = NULL;

static GLboolean _wglewInit_I3D_genlock ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglEnableGenlockI3D = (PFNWGLENABLEGENLOCKI3DPROC)glewGetProcAddress("wglEnableGenlockI3D")) == NULL;
  r = r || (wglDisableGenlockI3D = (PFNWGLDISABLEGENLOCKI3DPROC)glewGetProcAddress("wglDisableGenlockI3D")) == NULL;
  r = r || (wglIsEnabledGenlockI3D = (PFNWGLISENABLEDGENLOCKI3DPROC)glewGetProcAddress("wglIsEnabledGenlockI3D")) == NULL;
  r = r || (wglGenlockSourceI3D = (PFNWGLGENLOCKSOURCEI3DPROC)glewGetProcAddress("wglGenlockSourceI3D")) == NULL;
  r = r || (wglGetGenlockSourceI3D = (PFNWGLGETGENLOCKSOURCEI3DPROC)glewGetProcAddress("wglGetGenlockSourceI3D")) == NULL;
  r = r || (wglGenlockSourceEdgeI3D = (PFNWGLGENLOCKSOURCEEDGEI3DPROC)glewGetProcAddress("wglGenlockSourceEdgeI3D")) == NULL;
  r = r || (wglGetGenlockSourceEdgeI3D = (PFNWGLGETGENLOCKSOURCEEDGEI3DPROC)glewGetProcAddress("wglGetGenlockSourceEdgeI3D")) == NULL;
  r = r || (wglGenlockSampleRateI3D = (PFNWGLGENLOCKSAMPLERATEI3DPROC)glewGetProcAddress("wglGenlockSampleRateI3D")) == NULL;
  r = r || (wglGetGenlockSampleRateI3D = (PFNWGLGETGENLOCKSAMPLERATEI3DPROC)glewGetProcAddress("wglGetGenlockSampleRateI3D")) == NULL;
  r = r || (wglGenlockSourceDelayI3D = (PFNWGLGENLOCKSOURCEDELAYI3DPROC)glewGetProcAddress("wglGenlockSourceDelayI3D")) == NULL;
  r = r || (wglGetGenlockSourceDelayI3D = (PFNWGLGETGENLOCKSOURCEDELAYI3DPROC)glewGetProcAddress("wglGetGenlockSourceDelayI3D")) == NULL;
  r = r || (wglQueryGenlockMaxSourceDelayI3D = (PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC)glewGetProcAddress("wglQueryGenlockMaxSourceDelayI3D")) == NULL;
  return r;
}
#endif /* WGL_I3D_genlock */

/* ---------------------------- I3D_image_buffer -------------------------- */

#ifdef WGL_I3D_image_buffer
PFNWGLCREATEIMAGEBUFFERI3DPROC wglCreateImageBufferI3D = NULL;
PFNWGLDESTROYIMAGEBUFFERI3DPROC wglDestroyImageBufferI3D = NULL;
PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC wglAssociateImageBufferEventsI3D = NULL; 
PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC wglReleaseImageBufferEventsI3D = NULL;

static GLboolean _wglewInit_I3D_image_buffer ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglCreateImageBufferI3D = (PFNWGLCREATEIMAGEBUFFERI3DPROC)glewGetProcAddress("wglCreateImageBufferI3D")) == NULL;
  r = r || (wglDestroyImageBufferI3D = (PFNWGLDESTROYIMAGEBUFFERI3DPROC)glewGetProcAddress("wglDestroyImageBufferI3D")) == NULL;
  r = r || (wglAssociateImageBufferEventsI3D = (PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC)glewGetProcAddress("wglAssociateImageBufferEventsI3D")) == NULL;
  r = r || (wglReleaseImageBufferEventsI3D = (PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC)glewGetProcAddress("wglReleaseImageBufferEventsI3D")) == NULL;
  return r;
}
#endif /* WGL_I3D_image_buffer */

/* --------------------------- I3D_swap_frame_lock ------------------------ */

#ifdef WGL_I3D_swap_frame_lock
PFNWGLENABLEFRAMELOCKI3DPROC wglEnableFrameLockI3D = NULL;
PFNWGLDISABLEFRAMELOCKI3DPROC wglDisableFrameLockI3D = NULL;
PFNWGLISENABLEDFRAMELOCKI3DPROC wglIsEnabledFrameLockI3D = NULL;
PFNWGLQUERYFRAMELOCKMASTERI3DPROC wglQueryFrameLockMasterI3D = NULL;

static GLboolean _wglewInit_I3D_swap_frame_lock ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglEnableFrameLockI3D = (PFNWGLENABLEFRAMELOCKI3DPROC)glewGetProcAddress("wglEnableFrameLockI3D")) == NULL;
  r = r || (wglDisableFrameLockI3D = (PFNWGLDISABLEFRAMELOCKI3DPROC)glewGetProcAddress("wglDisableFrameLockI3D")) == NULL;
  r = r || (wglIsEnabledFrameLockI3D = (PFNWGLISENABLEDFRAMELOCKI3DPROC)glewGetProcAddress("wglIsEnabledFrameLockI3D")) == NULL;
  r = r || (wglQueryFrameLockMasterI3D = (PFNWGLQUERYFRAMELOCKMASTERI3DPROC)glewGetProcAddress("wglQueryFrameLockMasterI3D")) == NULL;
  return r;
}
#endif /* WGL_I3D_swap_frame_lock */

/* -------------------------- I3D_swap_frame_usage ------------------------ */

#ifdef WGL_I3D_swap_frame_usage
PFNWGLGETFRAMEUSAGEI3DPROC wglGetFrameUsageI3D = NULL;
PFNWGLBEGINFRAMETRACKINGI3DPROC wglBeginFrameTrackingI3D = NULL;
PFNWGLENDFRAMETRACKINGI3DPROC wglEndFrameTrackingI3D = NULL;
PFNWGLQUERYFRAMETRACKINGI3DPROC wglQueryFrameTrackingI3D = NULL;

static GLboolean _wglewInit_I3D_swap_frame_usage ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglGetFrameUsageI3D = (PFNWGLGETFRAMEUSAGEI3DPROC)glewGetProcAddress("wglGetFrameUsageI3D")) == NULL;
  r = r || (wglBeginFrameTrackingI3D = (PFNWGLBEGINFRAMETRACKINGI3DPROC)glewGetProcAddress("wglBeginFrameTrackingI3D")) == NULL;
  r = r || (wglEndFrameTrackingI3D = (PFNWGLENDFRAMETRACKINGI3DPROC)glewGetProcAddress("wglEndFrameTrackingI3D")) == NULL;
  r = r || (wglQueryFrameTrackingI3D = (PFNWGLQUERYFRAMETRACKINGI3DPROC)glewGetProcAddress("wglQueryFrameTrackingI3D")) == NULL;
  return r;
}
#endif /* WGL_I3D_swap_frame_usage */

/* ---------------------------- OML_sync_control -------------------------- */

#ifdef WGL_OML_sync_control
PFNWGLGETSYNCVALUESOMLPROC wglGetSyncValuesOML = NULL;
PFNWGLGETMSCRATEOMLPROC wglGetMscRateOML = NULL;
PFNWGLSWAPBUFFERSMSCOMLPROC wglSwapBuffersMscOML = NULL;
PFNWGLSWAPLAYERBUFFERSMSCOMLPROC wglSwapLayerBuffersMscOML = NULL;
PFNWGLWAITFORMSCOMLPROC wglWaitForMscOML = NULL;
PFNWGLWAITFORSBCOMLPROC wglWaitForSbcOML = NULL;

static GLboolean _wglewInit_OML_sync_control ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglGetSyncValuesOML = (PFNWGLGETSYNCVALUESOMLPROC)glewGetProcAddress("wglGetSyncValuesOML")) == NULL;
  r = r || (wglGetMscRateOML = (PFNWGLGETMSCRATEOMLPROC)glewGetProcAddress("wglGetMscRateOML")) == NULL;
  r = r || (wglSwapBuffersMscOML = (PFNWGLSWAPBUFFERSMSCOMLPROC)glewGetProcAddress("wglSwapBuffersMscOML")) == NULL;
  r = r || (wglSwapLayerBuffersMscOML = (PFNWGLSWAPLAYERBUFFERSMSCOMLPROC)glewGetProcAddress("wglSwapLayerBuffersMscOML")) == NULL;
  r = r || (wglWaitForMscOML = (PFNWGLWAITFORMSCOMLPROC)glewGetProcAddress("wglWaitForMscOML")) == NULL;
  r = r || (wglWaitForSbcOML = (PFNWGLWAITFORSBCOMLPROC)glewGetProcAddress("wglWaitForSbcOML")) == NULL;
  return r;
}
#endif /* WGL_OML_sync_control */

/* ------------------------- NV_vertex_array_range ------------------------ */

#ifdef WGL_NV_vertex_array_range
PFNWGLALLOCATEMEMORYNVPROC wglAllocateMemoryNV = NULL;
PFNWGLFREEMEMORYNVPROC wglFreeMemoryNV = NULL;

static GLboolean _wglewInit_NV_vertex_array_range ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglAllocateMemoryNV = (PFNWGLALLOCATEMEMORYNVPROC)glewGetProcAddress("wglAllocateMemoryNV")) == NULL;
  r = r || (wglFreeMemoryNV = (PFNWGLFREEMEMORYNVPROC)glewGetProcAddress("wglFreeMemoryNV")) == NULL;
  return r;
}
#endif /* WGL_NV_vertex_array_range */

#else /* _UNIX */

/* -------------------------------- GLX 1.0 ------------------------------- */

#ifdef GLX_VERSION_1_0
#ifdef GLEW_PROTOTYPES
PFNGLXQUERYEXTENSIONPROC glXQueryExtension = NULL;
PFNGLXQUERYVERSIONPROC glXQueryVersion = NULL;
PFNGLXGETCONFIGPROC glXGetConfig = NULL;
PFNGLXCHOOSEVISUALPROC glXChooseVisual = NULL;
PFNGLXCREATEGLXPIXMAPPROC glXCreateGLXPixmap = NULL;
PFNGLXDESTROYGLXPIXMAPPROC glXDestroyGLXPixmap = NULL;
PFNGLXCREATECONTEXTPROC glXCreateContext = NULL;
PFNGLXDESTROYCONTEXTPROC glXDestroyContext = NULL;
PFNGLXISDIRECTPROC glXIsDirect = NULL;
PFNGLXCOPYCONTEXTPROC glXCopyContext = NULL;
PFNGLXMAKECURRENTPROC glXMakeCurrent = NULL;
PFNGLXGETCURRENTCONTEXTPROC glXGetCurrentContext = NULL;
PFNGLXGETCURRENTDRAWABLEPROC glXGetCurrentDrawable = NULL;
PFNGLXWAITGLPROC glXWaitGL = NULL;
PFNGLXWAITXPROC glXWaitX = NULL;
PFNGLXSWAPBUFFERSPROC glXSwapBuffers = NULL;
PFNGLXUSEXFONTPROC glXUseXFont = NULL;
#endif

static GLboolean _glxewInit_10 ()
{
  GLboolean r = GL_FALSE;
#ifdef GLEW_PROTOTYPES
  r = r || (glXQueryExtension = (PFNGLXQUERYEXTENSIONPROC)glewGetProcAddress("glXQueryExtension")) == NULL;
  r = r || (glXQueryVersion = (PFNGLXQUERYVERSIONPROC)glewGetProcAddress("glXQueryVersion")) == NULL;
  r = r || (glXGetConfig = (PFNGLXGETCONFIGPROC)glewGetProcAddress("glXGetConfig")) == NULL;
  r = r || (glXChooseVisual = (PFNGLXCHOOSEVISUALPROC)glewGetProcAddress("glXChooseVisual")) == NULL;
  r = r || (glXCreateGLXPixmap = (PFNGLXCREATEGLXPIXMAPPROC)glewGetProcAddress("glXCreateGLXPixmap")) == NULL;
  r = r || (glXDestroyGLXPixmap = (PFNGLXDESTROYGLXPIXMAPPROC)glewGetProcAddress("glXDestroyGLXPixmap")) == NULL;
  r = r || (glXCreateContext = (PFNGLXCREATECONTEXTPROC)glewGetProcAddress("glXCreateContext")) == NULL;
  r = r || (glXDestroyContext = (PFNGLXDESTROYCONTEXTPROC)glewGetProcAddress("glXDestroyContext")) == NULL;
  r = r || (glXIsDirect = (PFNGLXISDIRECTPROC)glewGetProcAddress("glXIsDirect")) == NULL;
  r = r || (glXCopyContext = (PFNGLXCOPYCONTEXTPROC)glewGetProcAddress("glXCopyContext")) == NULL;
  r = r || (glXMakeCurrent = (PFNGLXMAKECURRENTPROC)glewGetProcAddress("glXMakeCurrent")) == NULL;
  r = r || (glXGetCurrentContext = (PFNGLXGETCURRENTCONTEXTPROC)glewGetProcAddress("glXGetCurrentContext")) == NULL;
  r = r || (glXGetCurrentDrawable = (PFNGLXGETCURRENTDRAWABLEPROC)glewGetProcAddress("glXGetCurrentDrawable")) == NULL;
  r = r || (glXWaitGL = (PFNGLXWAITGLPROC)glewGetProcAddress("glXWaitGL")) == NULL;
  r = r || (glXWaitX = (PFNGLXWAITXPROC)glewGetProcAddress("glXWaitX")) == NULL;
  r = r || (glXSwapBuffers = (PFNGLXSWAPBUFFERSPROC)glewGetProcAddress("glXSwapBuffers")) == NULL;
  r = r || (glXUseXFont = (PFNGLXUSEXFONTPROC)glewGetProcAddress("glXUseXFont")) == NULL;
#endif
  return r;
}
#endif /* GLX_VERSION_1_0 */

/* -------------------------------- GLX 1.1 ------------------------------- */

#ifdef GLX_VERSION_1_1
#ifdef GLEW_PROTOTYPES
PFNGLXQUERYEXTENSIONSSTRINGPROC glXQueryExtensionsString = NULL;
PFNGLXGETCLIENTSTRINGPROC glXGetClientString = NULL;
PFNGLXQUERYSERVERSTRINGPROC glXQueryServerString = NULL;
#endif

static GLboolean _glxewInit_11 ()
{
  GLboolean r = GL_FALSE;
#ifdef GLEW_PROTOTYPES
  r = r || (glXQueryExtensionsString = (PFNGLXQUERYEXTENSIONSSTRINGPROC)glewGetProcAddress("glXQueryExtensionsString")) == NULL;
  r = r || (glXGetClientString = (PFNGLXGETCLIENTSTRINGPROC)glewGetProcAddress("glXGetClientString")) == NULL;
  r = r || (glXQueryServerString = (PFNGLXQUERYSERVERSTRINGPROC)glewGetProcAddress("glXQueryServerString")) == NULL;
#endif
  return r;
}
#endif /* GLX_VERSION_1_1 */

/* -------------------------------- GLX 1.2 ------------------------------- */

#ifdef GLX_VERSION_1_2
PFNGLXGETCURRENTDISPLAYPROC glXGetCurrentDisplay = NULL;

static GLboolean _glxewInit_12 ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXGetCurrentDisplay = (PFNGLXGETCURRENTDISPLAYPROC)glewGetProcAddress("glXGetCurrentDisplay")) == NULL;
  return r;
}
#endif /* GLX_VERSION_1_2 */

/* -------------------------------- GLX 1.3 ------------------------------- */

#ifdef GLX_VERSION_1_3
PFNGLXCHOOSEFBCONFIGPROC glXChooseFBConfig = NULL;
PFNGLXGETFBCONFIGSPROC glXGetFBConfigs = NULL;
PFNGLXGETVISUALFROMFBCONFIGPROC glXGetVisualFromFBConfig = NULL;
PFNGLXGETFBCONFIGATTRIBPROC glXGetFBConfigAttrib = NULL;
PFNGLXCREATEWINDOWPROC glXCreateWindow = NULL;
PFNGLXDESTROYWINDOWPROC glXDestroyWindow = NULL;
PFNGLXCREATEPIXMAPPROC glXCreatePixmap = NULL;
PFNGLXDESTROYPIXMAPPROC glXDestroyPixmap = NULL;
PFNGLXCREATEPBUFFERPROC glXCreatePbuffer = NULL;
PFNGLXDESTROYPBUFFERPROC glXDestroyPbuffer = NULL;
PFNGLXQUERYDRAWABLEPROC glXQueryDrawable = NULL;
PFNGLXCREATENEWCONTEXTPROC glXCreateNewContext = NULL;
PFNGLXMAKECONTEXTCURRENTPROC glXMakeContextCurrent = NULL;
PFNGLXGETCURRENTREADDRAWABLEPROC glXGetCurrentReadDrawable = NULL;
PFNGLXQUERYCONTEXTPROC glXQueryContext = NULL;
PFNGLXSELECTEVENTPROC glXSelectEvent = NULL;
PFNGLXGETSELECTEDEVENTPROC glXGetSelectedEvent = NULL;

static GLboolean _glxewInit_13 ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXChooseFBConfig = (PFNGLXCHOOSEFBCONFIGPROC)glewGetProcAddress("glXChooseFBConfig")) == NULL;
  r = r || (glXGetFBConfigs = (PFNGLXGETFBCONFIGSPROC)glewGetProcAddress("glXGetFBConfigs")) == NULL;
  r = r || (glXGetVisualFromFBConfig = (PFNGLXGETVISUALFROMFBCONFIGPROC)glewGetProcAddress("glXGetVisualFromFBConfig")) == NULL;
  r = r || (glXGetFBConfigAttrib = (PFNGLXGETFBCONFIGATTRIBPROC)glewGetProcAddress("glXGetFBConfigAttrib")) == NULL;
  r = r || (glXCreateWindow = (PFNGLXCREATEWINDOWPROC)glewGetProcAddress("glXCreateWindow")) == NULL;
  r = r || (glXDestroyWindow = (PFNGLXDESTROYWINDOWPROC)glewGetProcAddress("glXDestroyWindow")) == NULL;
  r = r || (glXCreatePixmap = (PFNGLXCREATEPIXMAPPROC)glewGetProcAddress("glXCreatePixmap")) == NULL;
  r = r || (glXDestroyPixmap = (PFNGLXDESTROYPIXMAPPROC)glewGetProcAddress("glXDestroyPixmap")) == NULL;
  r = r || (glXCreatePbuffer = (PFNGLXCREATEPBUFFERPROC)glewGetProcAddress("glXCreatePbuffer")) == NULL;
  r = r || (glXDestroyPbuffer = (PFNGLXDESTROYPBUFFERPROC)glewGetProcAddress("glXDestroyPbuffer")) == NULL;
  r = r || (glXQueryDrawable = (PFNGLXQUERYDRAWABLEPROC)glewGetProcAddress("glXQueryDrawable")) == NULL;
  r = r || (glXCreateNewContext = (PFNGLXCREATENEWCONTEXTPROC)glewGetProcAddress("glXCreateNewContext")) == NULL;
  r = r || (glXMakeContextCurrent = (PFNGLXMAKECONTEXTCURRENTPROC)glewGetProcAddress("glXMakeContextCurrent")) == NULL;
  r = r || (glXGetCurrentReadDrawable = (PFNGLXGETCURRENTREADDRAWABLEPROC)glewGetProcAddress("glXGetCurrentReadDrawable")) == NULL;
  r = r || (glXQueryContext = (PFNGLXQUERYCONTEXTPROC)glewGetProcAddress("glXQueryContext")) == NULL;
  r = r || (glXSelectEvent = (PFNGLXSELECTEVENTPROC)glewGetProcAddress("glXSelectEvent")) == NULL;
  r = r || (glXGetSelectedEvent = (PFNGLXGETSELECTEDEVENTPROC)glewGetProcAddress("glXGetSelectedEvent")) == NULL;
  return r;
}
#endif /* GLX_VERSION_1_3 */

/* --------------------------- EXT_import_context -------------------------- */

#ifdef GLX_EXT_import_context
PFNGLXGETCURRENTDISPLAYEXTPROC glXGetCurrentDisplayEXT = NULL;
PFNGLXQUERYCONTEXTINFOEXTPROC glXQueryContextInfoEXT = NULL;
PFNGLXGETCONTEXTIDEXTPROC glXGetContextIDEXT = NULL;
PFNGLXIMPORTCONTEXTEXTPROC glXImportContextEXT = NULL;
PFNGLXFREECONTEXTEXTPROC glXFreeContextEXT = NULL;

static GLboolean _glxewInit_EXT_import_context ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXGetCurrentDisplayEXT = (PFNGLXGETCURRENTDISPLAYEXTPROC)glewGetProcAddress("glXGetCurrentDisplayEXT")) == NULL;
  r = r || (glXQueryContextInfoEXT = (PFNGLXQUERYCONTEXTINFOEXTPROC)glewGetProcAddress("glXQueryContextInfoEXT")) == NULL;
  r = r || (glXGetContextIDEXT = (PFNGLXGETCONTEXTIDEXTPROC)glewGetProcAddress("glXGetContextIDEXT")) == NULL;
  r = r || (glXImportContextEXT = (PFNGLXIMPORTCONTEXTEXTPROC)glewGetProcAddress("glXImportContextEXT")) == NULL;
  r = r || (glXFreeContextEXT = (PFNGLXFREECONTEXTEXTPROC)glewGetProcAddress("glXFreeContextEXT")) == NULL;
  return r;
}
#endif /* GLX_EXT_import_context */

/* --------------------------- MESA_copy_sub_buffer ----------------------- */

#ifdef GLX_MESA_copy_sub_buffer
PFNGLXCOPYSUBBUFFERMESAPROC glXCopySubBufferMESA = NULL;

static GLboolean _glxewInit_MESA_copy_sub_buffer ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXCopySubBufferMESA = (PFNGLXCOPYSUBBUFFERMESAPROC)glewGetProcAddress("glXCopySubBufferMESA")) == NULL;
  return r;
}
#endif /* GLX_MESA_copy_sub_buffer */

/* -------------------------- MESA_pixmap_colormap ------------------------ */

#ifdef GLX_MESA_pixmap_colormap
PFNGLXCREATEGLXPIXMAPMESAPROC glXCreateGLXPixmapMESA = NULL;

static GLboolean _glxewInit_MESA_pixmap_colormap ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXCreateGLXPixmapMESA = (PFNGLXCREATEGLXPIXMAPMESAPROC)glewGetProcAddress("glXCreateGLXPixmapMESA")) == NULL;
  return r;
}
#endif /* GLX_MESA_pixmap_colormap */

/* -------------------------- MESA_release_buffers ------------------------ */

#ifdef GLX_MESA_release_buffers
PFNGLXRELEASEBUFFERSMESAPROC glXReleaseBuffersMESA = NULL;

static GLboolean _glxewInit_MESA_release_buffers ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXReleaseBuffersMESA = (PFNGLXRELEASEBUFFERSMESAPROC)glewGetProcAddress("glXReleaseBuffersMESA")) == NULL;
  return r;
}
#endif /* GLX_MESA_release_buffers */

/* --------------------------- MESA_set_3dfx_mode ------------------------- */

#ifdef GLX_MESA_set_3dfx_mode
PFNGLXSET3DFXMODEMESAPROC glXSet3DfxModeMESA = NULL;

static GLboolean _glxewInit_MESA_set_3dfx_mode ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXSet3DfxModeMESA = (PFNGLXSET3DFXMODEMESAPROC)glewGetProcAddress("glXSet3DfxModeMESA")) == NULL;
  return r;
}
#endif /* GLX_MESA_set_3dfx_mode */

/* ------------------------- NV_vertex_array_range ------------------------ */

#ifdef GLX_NV_vertex_array_range
PFNGLXALLOCATEMEMORYNVPROC glXAllocateMemoryNV = NULL;
PFNGLXFREEMEMORYNVPROC glXFreeMemoryNV = NULL;

static GLboolean _glxewInit_NV_vertex_array_range ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXAllocateMemoryNV = (PFNGLXALLOCATEMEMORYNVPROC)glewGetProcAddress("glXAllocateMemoryNV")) == NULL;
  r = r || (glXFreeMemoryNV = (PFNGLXFREEMEMORYNVPROC)glewGetProcAddress("glXFreeMemoryNV")) == NULL;
  return r;
}
#endif /* GLX_NV_vertex_array_range */

/* ---------------------------- OML_sync_control -------------------------- */

#ifdef GLX_OML_sync_control
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
PFNGLXGETSYNCVALUESOMLPROC glXGetSyncValuesOML = NULL;
PFNGLXGETMSCRATEOMLPROC glXGetMscRateOML = NULL;
PFNGLXSWAPBUFFERSMSCOMLPROC glXSwapBuffersMscOML = NULL;
PFNGLXWAITFORMSCOMLPROC glXWaitForMscOML = NULL;
PFNGLXWAITFORSBCOMLPROC glXWaitForSbcOML = NULL;

static GLboolean _glxewInit_OML_sync_control ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXGetSyncValuesOML = (PFNGLXGETSYNCVALUESOMLPROC)glewGetProcAddress("glXGetSyncValuesOML")) == NULL;
  r = r || (glXGetMscRateOML = (PFNGLXGETMSCRATEOMLPROC)glewGetProcAddress("glXGetMscRateOML")) == NULL;
  r = r || (glXSwapBuffersMscOML = (PFNGLXSWAPBUFFERSMSCOMLPROC)glewGetProcAddress("glXSwapBuffersMscOML")) == NULL;
  r = r || (glXWaitForMscOML = (PFNGLXWAITFORMSCOMLPROC)glewGetProcAddress("glXWaitForMscOML")) == NULL;
  r = r || (glXWaitForSbcOML = (PFNGLXWAITFORSBCOMLPROC)glewGetProcAddress("glXWaitForSbcOML")) == NULL;
  return r;
}
#endif /* __STDC_VERSION__ */
#endif /* GLX_OML_sync_control */

/* ------------------------------- SGI_cushion ---------------------------- */

#ifdef GLX_SGI_cushion
PFNGLXCUSHIONSGIPROC glXCushionSGI = NULL;

static GLboolean _glxewInit_SGI_cushion ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXCushionSGI = (PFNGLXCUSHIONSGIPROC)glewGetProcAddress("glXCushionSGI")) == NULL;
  return r;
}
#endif /* GLX_SGI_cushion */

/* -------------------------- SGI_make_current_read ----------------------- */

#ifdef GLX_SGI_make_current_read
PFNGLXMAKECURRENTREADSGIPROC glXMakeCurrentReadSGI = NULL;
PFNGLXGETCURRENTREADDRAWABLESGIPROC glXGetCurrentReadDrawableSGI = NULL;

static GLboolean _glxewInit_SGI_make_current_read ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXMakeCurrentReadSGI = (PFNGLXMAKECURRENTREADSGIPROC)glewGetProcAddress("glXMakeCurrentReadSGI")) == NULL;
  r = r || (glXGetCurrentReadDrawableSGI = (PFNGLXGETCURRENTREADDRAWABLESGIPROC)glewGetProcAddress("glXGetCurrentReadDrawableSGI")) == NULL;
  return r;
}
#endif /* GLX_SGI_make_current_read */

/* ---------------------------- SGI_swap_control -------------------------- */

#ifdef GLX_SGI_swap_control
PFNGLXSWAPINTERVALSGIPROC glXSwapIntervalSGI = NULL;

static GLboolean _glxewInit_SGI_swap_control ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXSwapIntervalSGI = (PFNGLXSWAPINTERVALSGIPROC)glewGetProcAddress("glXSwapIntervalSGI")) == NULL;
  return r;
}
#endif /* GLX_SGI_swap_control */

/* ----------------------------- SGI_video_sync --------------------------- */

#ifdef GLX_SGI_video_sync
PFNGLXGETVIDEOSYNCSGIPROC glXGetVideoSyncSGI = NULL;
PFNGLXWAITVIDEOSYNCSGIPROC glXWaitVideoSyncSGI = NULL;
PFNGLXGETREFRESHRATESGIPROC glXGetRefreshRateSGI = NULL;

static GLboolean _glxewInit_SGI_video_sync ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXGetVideoSyncSGI = (PFNGLXGETVIDEOSYNCSGIPROC)glewGetProcAddress("glXGetVideoSyncSGI")) == NULL;
  r = r || (glXWaitVideoSyncSGI = (PFNGLXWAITVIDEOSYNCSGIPROC)glewGetProcAddress("glXWaitVideoSyncSGI")) == NULL;
  r = r || (glXGetRefreshRateSGI = (PFNGLXGETREFRESHRATESGIPROC)glewGetProcAddress("glXGetRefreshRateSGI")) == NULL;
  return r;
}
#endif /* GLX_SGI_video_sync */

/* ------------------------------ SGIX_fbconfig --------------------------- */

#ifdef GLX_SGIX_fbconfig
PFNGLXGETFBCONFIGATTRIBSGIXPROC glXGetFBConfigAttribSGIX = NULL;
PFNGLXCHOOSEFBCONFIGSGIXPROC glXChooseFBConfigSGIX = NULL;
PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC glXCreateGLXPixmapWithConfigSGIX = NULL;
PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC glXCreateContextWithConfigSGIX = NULL;
PFNGLXGETVISUALFROMFBCONFIGSGIXPROC glXGetVisualFromFBConfigSGIX = NULL;
PFNGLXGETFBCONFIGFROMVISUALSGIXPROC glXGetFBConfigFromVisualSGIX = NULL;

static GLboolean _glxewInit_SGIX_fbconfig ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXGetFBConfigAttribSGIX = (PFNGLXGETFBCONFIGATTRIBSGIXPROC)glewGetProcAddress("glXGetFBConfigAttribSGIX")) == NULL;
  r = r || (glXChooseFBConfigSGIX = (PFNGLXCHOOSEFBCONFIGSGIXPROC)glewGetProcAddress("glXChooseFBConfigSGIX")) == NULL;
  r = r || (glXCreateGLXPixmapWithConfigSGIX = (PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC)glewGetProcAddress("glXCreateGLXPixmapWithConfigSGIX")) == NULL;
  r = r || (glXCreateContextWithConfigSGIX = (PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC)glewGetProcAddress("glXCreateContextWithConfigSGIX")) == NULL;
  r = r || (glXGetVisualFromFBConfigSGIX = (PFNGLXGETVISUALFROMFBCONFIGSGIXPROC)glewGetProcAddress("glXGetVisualFromFBConfigSGIX")) == NULL;
  r = r || (glXGetFBConfigFromVisualSGIX = (PFNGLXGETFBCONFIGFROMVISUALSGIXPROC)glewGetProcAddress("glXGetFBConfigFromVisualSGIX")) == NULL;
  return r;
}
#endif /* GLX_SGIX_fbconfig */

/* ------------------------------- SGIX_pbuffer --------------------------- */

#ifdef GLX_SGIX_pbuffer
PFNGLXCREATEGLXPBUFFERSGIXPROC glXCreateGLXPbufferSGIX = NULL;
PFNGLXDESTROYGLXPBUFFERSGIXPROC glXDestroyGLXPbufferSGIX = NULL;
PFNGLXQUERYGLXPBUFFERSGIXPROC glXQueryGLXPbufferSGIX = NULL;
PFNGLXSELECTEVENTSGIXPROC glXSelectEventSGIX = NULL;
PFNGLXGETSELECTEDEVENTSGIXPROC glXGetSelectedEventSGIX = NULL;

static GLboolean _glxewInit_SGIX_pbuffer ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXCreateGLXPbufferSGIX = (PFNGLXCREATEGLXPBUFFERSGIXPROC)glewGetProcAddress("glXCreateGLXPbufferSGIX")) == NULL;
  r = r || (glXDestroyGLXPbufferSGIX = (PFNGLXDESTROYGLXPBUFFERSGIXPROC)glewGetProcAddress("glXDestroyGLXPbufferSGIX")) == NULL;
  r = r || (glXQueryGLXPbufferSGIX = (PFNGLXQUERYGLXPBUFFERSGIXPROC)glewGetProcAddress("glXQueryGLXPbufferSGIX")) == NULL;
  r = r || (glXSelectEventSGIX = (PFNGLXSELECTEVENTSGIXPROC)glewGetProcAddress("glXSelectEventSGIX")) == NULL;
  r = r || (glXGetSelectedEventSGIX = (PFNGLXGETSELECTEDEVENTSGIXPROC)glewGetProcAddress("glXGetSelectedEventSGIX")) == NULL;
  return r;
}
#endif /* GLX_SGIX_pbuffer */

/* ---------------------------- SGIX_swap_barrier ------------------------- */

#ifdef GLX_SGIX_swap_barrier
PFNGLXBINDSWAPBARRIERSGIXPROC glXBindSwapBarrierSGIX = NULL;
PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC glXQueryMaxSwapBarriersSGIX = NULL;

static GLboolean _glxewInit_SGIX_swap_barrier ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXBindSwapBarrierSGIX = (PFNGLXBINDSWAPBARRIERSGIXPROC)glewGetProcAddress("glXBindSwapBarrierSGIX")) == NULL;
  r = r || (glXQueryMaxSwapBarriersSGIX = (PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC)glewGetProcAddress("glXQueryMaxSwapBarriersSGIX")) == NULL;
  return r;
}
#endif /* GLX_SGIX_swap_barrier */

/* ----------------------------- SGIX_swap_group -------------------------- */

#ifdef GLX_SGIX_swap_group
PFNGLXJOINSWAPGROUPSGIXPROC glXJoinSwapGroupSGIX = NULL;

static GLboolean _glxewInit_SGIX_swap_group ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXJoinSwapGroupSGIX = (PFNGLXJOINSWAPGROUPSGIXPROC)glewGetProcAddress("glXJoinSwapGroupSGIX")) == NULL;
  return r;
}
#endif /* GLX_SGIX_swap_group */

/* ------------------------ SUN_get_transparent_index --------------------- */

#ifdef GLX_SUN_get_transparent_index
PFNGLXGETTRANSPARENTINDEXSUNPROC glXGetTransparentIndexSUN = NULL;

static GLboolean _glxewInit_SUN_get_transparent_index ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXGetTransparentIndexSUN = (PFNGLXGETTRANSPARENTINDEXSUNPROC)glewGetProcAddress("glXGetTransparentIndexSUN")) == NULL;
  return r;
}
#endif /* GLX_SUN_get_transparent_index */

#endif /* _WIN32 */

/* ------------------------------------------------------------------------ */

/*
 * GLEW, just like OpenGL or GLU, does not rely on the standard C library.
 * These functions only implement the functionality required in this file.
 */

int _glewStrLen (const char *s)
{
  int i=0;
  while (s+i != NULL && s[i] != '\0') i++;
  return i;
}

int _glewStrCLen (const char *s, char c)
{
  int i=0;
  while (s+i != NULL && s[i] != '\0' && s[i] != c) i++;
  return i;
}

int _glewStrSame (const char *a, const char *b, int n)
{
  int i=0;
  while (i < n && a+i != NULL && b+i != NULL && a[i] == b[i]) i++;
  return i == n;
}

void* _glewMemSet (void *s, char c, int n)
{
  int i;
  char* d=(char*)s;
  for (i=0; i<n; i++) d[i]=c;
  return s;
}

/* 
 * Search for name in the extensions string. Use of strstr()
 * is not sufficient because extension names can be prefixes of
 * other extension names. Could use strtok() but the constant
 * string returned by glGetString might be in read-only memory.
 */
GLboolean glewGetExtension (const char *name)
{    
  char *p, *end;
  int len = _glewStrLen(name);
  p = (char*)glGetString(GL_EXTENSIONS);
  if (0 == p) return GL_FALSE;
  end = p + _glewStrLen(p);
  while (p < end)
  {
    int n = _glewStrCLen(p, ' ');
    if (len == n && _glewStrSame(name, p, n)) return GL_TRUE;
    p += n+1;
  }
  return GL_FALSE;
}

/* ------------------------------------------------------------------------ */

static GLint _glewInit ()
{
  char* s;
  int i;
  /* initialize glew struct */
  _glewMemSet(&glew, 0, sizeof(glew));
  /* query opengl version */
  s = (char*)glGetString(GL_VERSION);
  if (!s) return GLEW_ERROR_NO_GL_VERSION;
  i=_glewStrCLen(s, '.')+1;
  if (s+i == NULL || s[i] < '1')
  {
    glew.GL_11 = 0; glew.GL_12 = 0; glew.GL_13 = 0; glew.GL_14 = 0;
    return GLEW_ERROR_GL_VERSION_10_ONLY;
  }
  else
  {
    if (s[2] == '4')
    {
      glew.GL_11 = 1; glew.GL_12 = 1; glew.GL_13 = 1; glew.GL_14 = 1;    
    }
    if (s[2] == '3')
    {
      glew.GL_11 = 1; glew.GL_12 = 1; glew.GL_13 = 1; glew.GL_14 = 0;    
    }
    if (s[2] == '2')
    {
      glew.GL_11 = 1; glew.GL_12 = 1; glew.GL_13 = 0; glew.GL_14 = 0;    
    }
    if (s[2] < '2')
    {
      glew.GL_11 = 1; glew.GL_12 = 0; glew.GL_13 = 0; glew.GL_14 = 0;    
    }
  }
  /* load core opengl */
#ifdef GL_VERSION_1_2
  if (glewExperimental || glew.GL_12) glew.GL_12 = !_glewInit_12();
#endif
#ifdef GL_VERSION_1_3
  if (glewExperimental || glew.GL_13) glew.GL_13 = !_glewInit_13();
#endif
#ifdef GL_VERSION_1_4
  if (glewExperimental || glew.GL_14) glew.GL_14 = !_glewInit_14();
#endif
  /* load extensions */
#ifdef GL_ARB_depth_texture
  glew.ARB_depth_texture = glewGetExtension("GL_ARB_depth_texture");
#endif
#ifdef GL_ARB_fragment_program
  glew.ARB_fragment_program = glewGetExtension("GL_ARB_fragment_program");
#endif
#ifdef GL_ARB_imaging
  glew.ARB_imaging = glewGetExtension("GL_ARB_imaging");
  if (glewExperimental || glew.ARB_imaging) glew.ARB_imaging = !_glewInit_ARB_imaging();
#endif
#ifdef GL_ARB_matrix_palette
  glew.ARB_matrix_palette = glewGetExtension("GL_ARB_matrix_palette");
  if (glewExperimental || glew.ARB_matrix_palette) glew.ARB_matrix_palette = !_glewInit_ARB_matrix_palette();
#endif
#ifdef GL_ARB_multisample
  glew.ARB_multisample = glewGetExtension("GL_ARB_multisample");
  if (glewExperimental || glew.ARB_multisample) glew.ARB_multisample = !_glewInit_ARB_multisample();
#endif
#ifdef GL_ARB_multitexture
  glew.ARB_multitexture = glewGetExtension("GL_ARB_multitexture");
  if (glewExperimental || glew.ARB_multitexture) glew.ARB_multitexture = !_glewInit_ARB_multitexture();
#endif
#ifdef GL_ARB_point_parameters
  glew.ARB_point_parameters = glewGetExtension("GL_ARB_point_parameters");
  if (glewExperimental || glew.ARB_point_parameters) glew.ARB_point_parameters = !_glewInit_ARB_point_parameters();
#endif
#ifdef GL_ARB_shadow
  glew.ARB_shadow = glewGetExtension("GL_ARB_shadow");
#endif
#ifdef GL_ARB_shadow_ambient
  glew.ARB_shadow_ambient = glewGetExtension("GL_ARB_shadow_ambient");
#endif
#ifdef GL_ARB_texture_border_clamp
  glew.ARB_texture_border_clamp = glewGetExtension("GL_ARB_texture_border_clamp");
#endif
#ifdef GL_ARB_texture_compression
  glew.ARB_texture_compression = glewGetExtension("GL_ARB_texture_compression");
  if (glewExperimental || glew.ARB_texture_compression) glew.ARB_texture_compression = !_glewInit_ARB_texture_compression();
#endif
#ifdef GL_ARB_texture_cube_map
  glew.ARB_texture_cube_map = glewGetExtension("GL_ARB_texture_cube_map");
#endif
#ifdef GL_ARB_texture_env_add
  glew.ARB_texture_env_add = glewGetExtension("GL_ARB_texture_env_add");
#endif
#ifdef GL_ARB_texture_env_combine
  glew.ARB_texture_env_combine = glewGetExtension("GL_ARB_texture_env_combine");
#endif
#ifdef GL_ARB_texture_env_crossbar
  glew.ARB_texture_env_crossbar = glewGetExtension("GL_ARB_texture_env_crossbar");
#endif
#ifdef GL_ARB_texture_env_dot3
  glew.ARB_texture_env_dot3 = glewGetExtension("GL_ARB_texture_env_dot3");
#endif
#ifdef GL_ARB_texture_mirrored_repeat
  glew.ARB_texture_mirrored_repeat = glewGetExtension("GL_ARB_texture_mirrored_repeat");
#endif
#ifdef GL_ARB_transpose_matrix
  glew.ARB_transpose_matrix = glewGetExtension("GL_ARB_transpose_matrix");
  if (glewExperimental || glew.ARB_transpose_matrix) glew.ARB_transpose_matrix = !_glewInit_ARB_transpose_matrix();
#endif
#ifdef GL_ARB_vertex_blend
  glew.ARB_vertex_blend = glewGetExtension("GL_ARB_vertex_blend");
  if (glewExperimental || glew.ARB_vertex_blend) glew.ARB_vertex_blend = !_glewInit_ARB_vertex_blend();
#endif
#ifdef GL_ARB_vertex_program
  glew.ARB_vertex_program = glewGetExtension("GL_ARB_vertex_program");
  if (glewExperimental || glew.ARB_vertex_program) glew.ARB_vertex_program = !_glewInit_ARB_vertex_program();
#endif
#ifdef GL_ARB_window_pos
  glew.ARB_window_pos = glewGetExtension("GL_ARB_window_pos");
  if (glewExperimental || glew.ARB_window_pos) glew.ARB_window_pos = !_glewInit_ARB_window_pos();
#endif

#ifdef GL_EXT_abgr
  glew.EXT_abgr = glewGetExtension("GL_EXT_abgr");
#endif
#ifdef GL_EXT_bgra
  glew.EXT_bgra = glewGetExtension("GL_EXT_bgra");
#endif
#ifdef GL_EXT_blend_color
  glew.EXT_blend_color = glewGetExtension("GL_EXT_blend_color");
  if (glewExperimental || glew.EXT_blend_color) glew.EXT_blend_color = !_glewInit_EXT_blend_color();
#endif
#ifdef GL_EXT_blend_func_separate
  glew.EXT_blend_func_separate = glewGetExtension("GL_EXT_blend_func_separate");
  if (glewExperimental || glew.EXT_blend_func_separate) glew.EXT_blend_func_separate = !_glewInit_EXT_blend_func_separate();
#endif
#ifdef GL_EXT_blend_minmax
  glew.EXT_blend_minmax = glewGetExtension("GL_EXT_blend_minmax");
  if (glewExperimental || glew.EXT_blend_minmax) glew.EXT_blend_minmax = !_glewInit_EXT_blend_minmax();
#endif
#ifdef GL_EXT_blend_subtract
  glew.EXT_blend_subtract = glewGetExtension("GL_EXT_blend_subtract");
#endif
#ifdef GL_EXT_clip_volume_hint
  glew.EXT_compiled_vertex_array = glewGetExtension("GL_EXT_clip_volume_hint");
#endif
#ifdef GL_EXT_compiled_vertex_array
  glew.EXT_compiled_vertex_array = glewGetExtension("GL_EXT_compiled_vertex_array");
  if (glewExperimental || glew.EXT_compiled_vertex_array) glew.EXT_compiled_vertex_array = !_glewInit_EXT_compiled_vertex_array();
#endif
#ifdef GL_EXT_cull_vertex
  glew.EXT_cull_vertex = glewGetExtension("GL_EXT_cull_vertex");
  if (glewExperimental || glew.EXT_cull_vertex) glew.EXT_cull_vertex = !_glewInit_EXT_cull_vertex();
#endif
#ifdef GL_EXT_draw_range_elements
  glew.EXT_draw_range_elements = glewGetExtension("GL_EXT_draw_range_elements");
  if (glewExperimental || glew.EXT_draw_range_elements) glew.EXT_draw_range_elements = !_glewInit_EXT_draw_range_elements();
#endif
#ifdef GL_EXT_fog_coord
  glew.EXT_fog_coord = glewGetExtension("GL_EXT_fog_coord");
  if (glewExperimental || glew.EXT_fog_coord) glew.EXT_fog_coord = !_glewInit_EXT_fog_coord();
#endif
#ifdef GL_EXT_multi_draw_arrays
  glew.EXT_multi_draw_arrays = glewGetExtension("GL_EXT_multi_draw_arrays");
  if (glewExperimental || glew.EXT_multi_draw_arrays) glew.EXT_multi_draw_arrays = !_glewInit_EXT_multi_draw_arrays();
#endif
#ifdef GL_EXT_packed_pixels
  glew.EXT_packed_pixels = glewGetExtension("GL_EXT_packed_pixels");
#endif
#ifdef GL_EXT_point_parameters
  glew.EXT_point_parameters = glewGetExtension("GL_EXT_point_parameters");
  if (glewExperimental || glew.EXT_point_parameters) glew.EXT_point_parameters = !_glewInit_EXT_point_parameters();
#endif
#ifdef GL_EXT_secondary_color
  glew.EXT_secondary_color = glewGetExtension("GL_EXT_secondary_color");
  if (glewExperimental || glew.EXT_secondary_color) glew.EXT_secondary_color = !_glewInit_EXT_secondary_color();
#endif
#ifdef GL_EXT_separate_specular_color
  glew.EXT_separate_specular_color = glewGetExtension("GL_EXT_separate_specular_color");
#endif
#ifdef GL_EXT_shadow_funcs
  glew.EXT_shadow_funcs = glewGetExtension("GL_EXT_shadow_funcs");
#endif
#ifdef GL_EXT_stencil_two_side
  glew.EXT_stencil_two_side = glewGetExtension("GL_EXT_stencil_two_side");
  if (glewExperimental || glew.EXT_stencil_two_side) glew.EXT_stencil_two_side = !_glewInit_EXT_stencil_two_side();
#endif
#ifdef GL_EXT_stencil_wrap
  glew.EXT_stencil_wrap = glewGetExtension("GL_EXT_stencil_wrap");
#endif
#ifdef GL_EXT_texture_compression_s3tc
  glew.EXT_texture_compression_s3tc = glewGetExtension("GL_EXT_texture_compression_s3tc");
#endif
#ifdef GL_EXT_texture_env_combine
  glew.EXT_texture_env_combine = glewGetExtension("GL_EXT_texture_env_combine");
#endif
#ifdef GL_EXT_texture_filter_anisotropic
  glew.EXT_texture_filter_anisotropic = glewGetExtension("GL_EXT_texture_filter_anisotropic");
#endif
#ifdef GL_EXT_texture_lod_bias
  glew.EXT_texture_lod_bias = glewGetExtension("GL_EXT_texture_lod_bias");
#endif
#ifdef GL_EXT_texture_rectangle
  glew.EXT_texture_rectangle = glewGetExtension("GL_EXT_texture_rectangle");
#endif
#ifdef GL_EXT_texture3D
  glew.EXT_texture3D = glewGetExtension("GL_EXT_texture3D");
  if (glewExperimental || glew.EXT_texture3D) glew.EXT_texture3D = !_glewInit_EXT_texture3D();
#endif
#ifdef GL_EXT_vertex_shader
  glew.EXT_vertex_shader = glewGetExtension("GL_EXT_vertex_shader");
  if (glewExperimental || glew.EXT_vertex_shader) glew.EXT_vertex_shader = !_glewInit_EXT_vertex_shader();
#endif
#ifdef GL_EXT_vertex_weighting
  glew.EXT_vertex_weighting = glewGetExtension("GL_EXT_vertex_weighting");
  if (glewExperimental || glew.EXT_vertex_weighting) glew.EXT_vertex_weighting = !_glewInit_EXT_vertex_weighting();
#endif

#ifdef GL_SGIS_generate_mipmap
  glew.SGIS_generate_mipmap = glewGetExtension("GL_SGIS_generate_mipmap");
#endif
#ifdef GL_SGIS_texture_lod
  glew.SGIS_texture_lod = glewGetExtension("GL_SGIS_texture_lod");
#endif
#ifdef GL_SGIX_depth_texture
  glew.SGIX_depth_texture = glewGetExtension("GL_SGIX_depth_texture");
#endif
#ifdef GL_SGIX_shadow
  glew.SGIX_shadow = glewGetExtension("GL_SGIX_shadow");
#endif

#ifdef GL_HP_occlusion_test
  glew.HP_occlusion_test = glewGetExtension("GL_HP_occlusion_test");
#endif
#ifdef GL_S3_s3tc
  glew.S3_s3tc = glewGetExtension("GL_S3_s3tc");
#endif
#ifdef GL_WIN_swap_hint
  glew.WIN_swap_hint = glewGetExtension("GL_WIN_swap_hint");
  if (glewExperimental || glew.WIN_swap_hint) glew.WIN_swap_hint = !_glewInit_WIN_swap_hint();
#endif

#ifdef GL_ATI_draw_buffers
  glew.ATI_draw_buffers = glewGetExtension("GL_ATI_draw_buffers");
  if (glewExperimental || glew.ATI_draw_buffers) glew.ATI_draw_buffers = !_glewInit_ATI_draw_buffers();
#endif
#ifdef GL_ATI_element_array
  glew.ATI_element_array = glewGetExtension("GL_ATI_element_array");
  if (glewExperimental || glew.ATI_element_array) glew.ATI_element_array = !_glewInit_ATI_element_array();
#endif
#ifdef GL_ATI_envmap_bumpmap
  glew.ATI_envmap_bumpmap = glewGetExtension("GL_ATI_envmap_bumpmap");
  if (glewExperimental || glew.ATI_envmap_bumpmap) glew.ATI_envmap_bumpmap = !_glewInit_ATI_envmap_bumpmap();
#endif
#ifdef GL_ATI_fragment_shader
  glew.ATI_fragment_shader = glewGetExtension("GL_ATI_fragment_shader");
  if (glewExperimental || glew.ATI_fragment_shader) glew.ATI_fragment_shader = !_glewInit_ATI_fragment_shader();
#endif
#ifdef GL_ATI_map_object_buffer
  glew.ATI_map_object_buffer = glewGetExtension("GL_ATI_map_object_buffer");
  if (glewExperimental || glew.ATI_map_object_buffer) glew.ATI_map_object_buffer = !_glewInit_ATI_map_object_buffer();
#endif
#ifdef GL_ATI_mapped_texture
  glew.ATI_mapped_texture = glewGetExtension("GL_ATI_mapped_texture");
  if (glewExperimental || glew.ATI_mapped_texture) glew.ATI_mapped_texture = !_glewInit_ATI_mapped_texture();
#endif
#ifdef GL_ATI_pn_triangles
  glew.ATI_pn_triangles = glewGetExtension("GL_ATI_pn_triangles");
  if (glewExperimental || glew.ATI_pn_triangles) glew.ATI_pn_triangles = !_glewInit_ATI_pn_triangles();
#endif
#ifdef GL_ATI_separate_stencil
  glew.ATI_separate_stencil = glewGetExtension("GL_ATI_separate_stencil");
  if (glewExperimental || glew.ATI_separate_stencil) glew.ATI_separate_stencil = !_glewInit_ATI_separate_stencil();
#endif
#ifdef GL_ATI_text_fragment_shader
  glew.ATI_texture_float = glewGetExtension("GL_ATI_texture_float");
#endif
#ifdef GL_ATI_texture_env_combine3
  glew.ATI_texture_env_combine3 = glewGetExtension("GL_ATI_texture_env_combine3");
#endif
#ifdef GL_ATI_texture_float
  glew.ATI_texture_float = glewGetExtension("GL_ATI_texture_float");
#endif
#ifdef GL_ATI_texture_mirror_once
  glew.ATI_texture_mirror_once = glewGetExtension("GL_ATI_texture_mirror_once");
#endif
#ifdef GL_ATI_vertex_array_object
  glew.ATI_vertex_array_object = glewGetExtension("GL_ATI_vertex_array_object");
  if (glewExperimental || glew.ATI_vertex_array_object) glew.ATI_vertex_array_object = !_glewInit_ATI_vertex_array_object();
#endif
#ifdef GL_ATI_vertex_attrib_array_object
  glew.ATI_vertex_attrib_array_object = glewGetExtension("GL_ATI_vertex_attrib_array_object");
  if (glewExperimental || glew.ATI_vertex_attrib_array_object) glew.ATI_vertex_attrib_array_object = !_glewInit_ATI_vertex_attrib_array_object();
#endif
#ifdef GL_ATI_vertex_streams
  glew.ATI_vertex_streams = glewGetExtension("GL_ATI_vertex_streams");
  if (glewExperimental || glew.ATI_vertex_streams) glew.ATI_vertex_streams = !_glewInit_ATI_vertex_streams();
#endif
#ifdef GL_ATIX_point_sprites
  glew.ATIX_point_sprites = glewGetExtension("GL_ATIX_point_sprites");
#endif
#ifdef GL_ATIX_texture_env_combine3
  glew.ATIX_texture_env_combine3 = glewGetExtension("GL_ATIX_texture_env_combine3");
#endif
#ifdef GL_ATIX_texture_env_route
  glew.ATIX_texture_env_route = glewGetExtension("GL_ATIX_texture_env_route");
#endif
#ifdef GL_ATIX_vertex_shader_output_point_size
  glew.ATIX_vertex_shader_output_point_size = glewGetExtension("GL_ATIX_vertex_shader_output_point_size");
#endif

#ifdef GL_NV_blend_square
  glew.NV_blend_square = glewGetExtension("GL_NV_blend_square");
#endif
#ifdef GL_NV_copy_depth_to_color
  glew.NV_copy_depth_to_color = glewGetExtension("GL_NV_copy_depth_to_color");
#endif
#ifdef GL_NV_depth_clamp
  glew.NV_depth_clamp = glewGetExtension("GL_NV_depth_clamp");
#endif
#ifdef GL_NV_element_array
  glew.NV_element_array = glewGetExtension("GL_NV_element_array");
  if (glewExperimental || glew.NV_element_array) glew.NV_element_array = !_glewInit_NV_element_array();
#endif
#ifdef GL_NV_evaluators
  glew.NV_evaluators = glewGetExtension("GL_NV_evaluators");
  if (glewExperimental || glew.NV_evaluators) glew.NV_evaluators = !_glewInit_NV_evaluators();
#endif
#ifdef GL_NV_fence
  glew.NV_fence = glewGetExtension("GL_NV_fence");
  if (glewExperimental || glew.NV_fence) glew.NV_fence = !_glewInit_NV_fence();
#endif
#ifdef GL_NV_float_buffer
  glew.NV_float_buffer = glewGetExtension("GL_NV_float_buffer");
#endif
#ifdef GL_NV_fog_distance
  glew.NV_fog_distance = glewGetExtension("GL_NV_fog_distance");
#endif
#ifdef GL_NV_fragment_program
  glew.NV_fragment_program = glewGetExtension("GL_NV_fragment_program");
  if (glewExperimental || glew.NV_fragment_program) glew.NV_fragment_program = !_glewInit_NV_fragment_program();
#endif
#ifdef GL_NV_light_max_exponent
  glew.NV_half_float = glewGetExtension("GL_NV_half_float");
#endif
#ifdef GL_NV_light_max_exponent
  glew.NV_light_max_exponent = glewGetExtension("GL_NV_light_max_exponent");
#endif
#ifdef GL_NV_multisample_filter_hint
  glew.NV_multisample_filter_hint = glewGetExtension("GL_NV_multisample_filter_hint");
#endif
#ifdef GL_NV_occlusion_query
  glew.NV_occlusion_query = glewGetExtension("GL_NV_occlusion_query");
  if (glewExperimental || glew.NV_occlusion_query) glew.NV_occlusion_query = !_glewInit_NV_occlusion_query();
#endif
#ifdef GL_NV_packed_depth_stencil
  glew.NV_packed_depth_stencil = glewGetExtension("GL_NV_packed_depth_stencil");
#endif
#ifdef GL_NV_pixel_data_range
  glew.NV_pixel_data_range = glewGetExtension("GL_NV_pixel_data_range");
  if (glewExperimental || glew.NV_pixel_data_range) glew.NV_pixel_data_range = !_glewInit_NV_pixel_data_range();
#endif
#ifdef GL_NV_point_sprite
  glew.NV_point_sprite = glewGetExtension("GL_NV_point_sprite");
  if (glewExperimental || glew.NV_point_sprite) glew.NV_point_sprite = !_glewInit_NV_point_sprite();
#endif
#ifdef GL_NV_primitive_restart
  glew.NV_primitive_restart = glewGetExtension("GL_NV_");
  if (glewExperimental || glew.NV_primitive_restart) glew.NV_primitive_restart = !_glewInit_NV_primitive_restart();
#endif
#ifdef GL_NV_register_combiners
  glew.NV_register_combiners = glewGetExtension("GL_NV_register_combiners");
  if (glewExperimental || glew.NV_register_combiners) glew.NV_register_combiners = !_glewInit_NV_register_combiners();
#endif
#ifdef GL_NV_register_combiners2
  glew.NV_register_combiners2 = glewGetExtension("GL_NV_register_combiners2");
  if (glewExperimental || glew.NV_register_combiners2) glew.NV_register_combiners2 = !_glewInit_NV_register_combiners2();
#endif
#ifdef GL_NV_texgen_emboss
  glew.NV_texgen_emboss = glewGetExtension("GL_NV_texgen_emboss");
#endif
#ifdef GL_NV_texgen_reflection
  glew.NV_texgen_reflection = glewGetExtension("GL_NV_texgen_reflection");
#endif
#ifdef GL_NV_texture_compression_vtc
  glew.NV_texture_compression_vtc = glewGetExtension("GL_NV_texture_compression_vtc");
#endif
#ifdef GL_NV_texture_env_combine4
  glew.NV_texture_env_combine4 = glewGetExtension("GL_NV_texture_env_combine4");
#endif
#ifdef GL_NV_texture_expand_normal
  glew.NV_texture_expand_normal = glewGetExtension("GL_NV_texture_expand_normal");
#endif
#ifdef GL_NV_texture_rectangle
  glew.NV_texture_rectangle = glewGetExtension("GL_NV_texture_rectangle");
#endif
#ifdef GL_NV_texture_shader
  glew.NV_texture_shader = glewGetExtension("GL_NV_texture_shader");
#endif
#ifdef GL_NV_texture_shader2
  glew.NV_texture_shader2 = glewGetExtension("GL_NV_texture_shader2");
#endif
#ifdef GL_NV_texture_shader3
  glew.NV_texture_shader3 = glewGetExtension("GL_NV_texture_shader3");
#endif
#ifdef GL_NV_vertex_array_range
  glew.NV_vertex_array_range = glewGetExtension("GL_NV_vertex_array_range");
  if (glewExperimental || glew.NV_vertex_array_range) glew.NV_vertex_array_range = !_glewInit_NV_vertex_array_range();
#endif
#ifdef GL_NV_vertex_array_range2
  glew.NV_vertex_array_range2 = glewGetExtension("GL_NV_vertex_array_range2");
#endif
#ifdef GL_NV_vertex_program
  glew.NV_vertex_program = glewGetExtension("GL_NV_vertex_program");
  if (glewExperimental || glew.NV_vertex_array_range) glew.NV_vertex_array_range = !_glewInit_NV_vertex_program();
#endif
#ifdef GL_NV_vertex_program1_1
  glew.NV_vertex_program1_1 = glewGetExtension("GL_NV_vertex_program1_1");
#endif
#ifdef GL_NV_vertex_program2
  glew.NV_vertex_program2 = glewGetExtension("GL_NV_vertex_program2");
#endif
  return GLEW_OK;
}

/* ------------------------------------------------------------------------ */

#ifdef _WIN32

GLboolean wglewGetExtension (const char *name)
{    
  char *p, *end;
  int len = _glewStrLen(name);
  if (wglGetExtensionsStringARB == NULL)
    if (wglGetExtensionsStringEXT == NULL)
      return GL_FALSE;
    else
      p = (char*)wglGetExtensionsStringEXT();
  else
    p = (char*)wglGetExtensionsStringARB(wglGetCurrentDC());
  if (0 == p) return GL_FALSE;
  end = p + _glewStrLen(p);
  while (p < end)
  {
    int n = _glewStrCLen(p, ' ');
    if (len == n && _glewStrSame(name, p, n)) return GL_TRUE;
    p += n+1;
  }
  return GL_FALSE;
}

static GLint _wglewInit ()
{
  /* intialize wglew struct */
  _glewMemSet(&wglew, 0, sizeof(wglew));
  /* find wgl extension string query functions */
  _wglewInit_ARB_extensions_string();
  wglew.ARB_extensions_string = wglGetExtensionsStringARB != NULL;
  _wglewInit_EXT_extensions_string();
  wglew.EXT_extensions_string = wglGetExtensionsStringEXT != NULL;
  if (wglew.ARB_extensions_string == 0 && 
      wglew.EXT_extensions_string == 0) return GLEW_ERROR_NO_EXTENSIONS_STRING;
  /* initialize extensions */
#ifdef WGL_ARB_buffer_region
  wglew.ARB_buffer_region = wglewGetExtension("WGL_ARB_buffer_region");
  if (glewExperimental || wglew.ARB_buffer_region) wglew.ARB_buffer_region = !_wglewInit_ARB_buffer_region();
#endif
#ifdef WGL_ARB_make_current_read
  wglew.ARB_make_current_read = wglewGetExtension("WGL_ARB_make_current_read");
  if (glewExperimental || wglew.ARB_make_current_read) wglew.ARB_make_current_read = !_wglewInit_ARB_make_current_read();
#endif    
#ifdef WGL_ARB_multisample
  wglew.ARB_multisample = wglewGetExtension("WGL_ARB_multisample");
#endif
#ifdef WGL_ARB_pbuffer
  wglew.ARB_pbuffer = wglewGetExtension("WGL_ARB_pbuffer");
  if (glewExperimental || wglew.ARB_pbuffer) wglew.ARB_pbuffer = !_wglewInit_ARB_pbuffer();
#endif
#ifdef WGL_ARB_pixel_format
  wglew.ARB_pixel_format = wglewGetExtension("WGL_ARB_pixel_format");
  if (glewExperimental || wglew.ARB_pixel_format) wglew.ARB_pixel_format = !_wglewInit_ARB_pixel_format();
#endif
#ifdef WGL_ARB_render_texture
  wglew.ARB_render_texture = wglewGetExtension("WGL_ARB_render_texture");
  if (glewExperimental || wglew.ARB_render_texture) wglew.ARB_render_texture = !_wglewInit_ARB_render_texture();
#endif

#ifdef WGL_EXT_depth_float
  wglew.EXT_depth_float = wglewGetExtension("WGL_EXT_depth_float");
#endif
#ifdef WGL_EXT_display_color_table
  wglew.EXT_display_color_table = wglewGetExtension("WGL_EXT_display_color_table");
  if (glewExperimental || wglew.EXT_display_color_table) wglew.EXT_display_color_table = !_wglewInit_EXT_display_color_table();
#endif
#ifdef WGL_EXT_make_current_read
  wglew.EXT_make_current_read = wglewGetExtension("WGL_EXT_make_current_read");
  if (glewExperimental || wglew.EXT_make_current_read) wglew.EXT_make_current_read = !_wglewInit_EXT_make_current_read();
#endif
#ifdef WGL_EXT_multisample
  wglew.EXT_multisample = wglewGetExtension("WGL_EXT_multisample");
#endif
#ifdef WGL_EXT_pixel_format
  wglew.EXT_pixel_format = wglewGetExtension("WGL_EXT_pixel_format");
  if (glewExperimental || wglew.EXT_pixel_format) wglew.EXT_pixel_format = !_wglewInit_EXT_pixel_format();
#endif
#ifdef WGL_EXT_pbuffer
  wglew.EXT_pbuffer = wglewGetExtension("WGL_EXT_pbuffer");
  if (glewExperimental || wglew.EXT_pbuffer) wglew.EXT_pbuffer = !_wglewInit_EXT_pbuffer();
#endif
#ifdef WGL_EXT_swap_control
  wglew.EXT_swap_control = wglewGetExtension("WGL_EXT_swap_control");
  if (glewExperimental || wglew.EXT_swap_control) wglew.EXT_swap_control = !_wglewInit_EXT_swap_control();
#endif

#ifdef WGL_I3D_digital_video_control
  wglew.I3D_digital_video_control = wglewGetExtension("WGL_I3D_digital_video_control");
  if (glewExperimental || wglew.I3D_digital_video_control) wglew.I3D_digital_video_control = !_wglewInit_I3D_digital_video_control();
#endif
#ifdef WGL_I3D_gamma
  wglew.I3D_gamma = wglewGetExtension("WGL_I3D_gamma");
  if (glewExperimental || wglew.I3D_gamma) wglew.I3D_gamma = !_wglewInit_I3D_gamma();
#endif
#ifdef WGL_I3D_genlock
  wglew.I3D_genlock = wglewGetExtension("WGL_I3D_genlock");
  if (glewExperimental || wglew.I3D_genlock) wglew.I3D_genlock = !_wglewInit_I3D_genlock();
#endif
#ifdef WGL_I3D_image_buffer
  wglew.I3D_image_buffer = wglewGetExtension("WGL_I3D_image_buffer");
  if (glewExperimental || wglew.I3D_image_buffer) wglew.I3D_image_buffer = !_wglewInit_I3D_image_buffer();
#endif
#ifdef WGL_I3D_swap_frame_lock
  wglew.I3D_swap_frame_lock = wglewGetExtension("WGL_I3D_swap_frame_lock");
  if (glewExperimental || wglew.I3D_swap_frame_lock) wglew.I3D_swap_frame_lock = !_wglewInit_I3D_swap_frame_lock();
#endif
#ifdef WGL_I3D_swap_frame_usage
  wglew.I3D_swap_frame_usage = wglewGetExtension("WGL_I3D_swap_frame_usage");
  if (glewExperimental || wglew.I3D_swap_frame_usage) wglew.I3D_swap_frame_usage = !_wglewInit_I3D_swap_frame_usage();
#endif

#ifdef WGL_OML_sync_control
  wglew.OML_sync_control = wglewGetExtension("WGL_OML_sync_control");
  if (glewExperimental || wglew.OML_sync_control) wglew.OML_sync_control = !_wglewInit_OML_sync_control();
#endif

#ifdef WGL_ATI_pixel_format_float
  wglew.ATI_pixel_format_float = wglewGetExtension("WGL_ATI_pixel_format_float");
#endif

#ifdef WGL_NV_float_buffer
  wglew.NV_float_buffer = wglewGetExtension("WGL_NV_float_buffer");
#endif
#ifdef WGL_NV_render_depth_texture
  wglew.NV_render_depth_texture = wglewGetExtension("WGL_NV_render_depth_texture");
#endif
#ifdef WGL_NV_render_texture_rectangle
  wglew.NV_render_texture_rectangle = wglewGetExtension("WGL_NV_render_texture_rectangle");
#endif
#ifdef WGL_NV_vertex_array_range
  wglew.NV_vertex_array_range = wglewGetExtension("WGL_NV_vertex_array_range");
  if (glewExperimental || wglew.NV_vertex_array_range) wglew.NV_vertex_array_range = !_wglewInit_NV_vertex_array_range();
#endif
  return GLEW_OK;
}

#else /* _UNIX */

GLboolean glxewGetExtension (const char *name)
{    
  char *p, *end;
  int len = _glewStrLen(name);
  if (glXQueryExtensionsString == NULL) return GL_FALSE;
  p = (char*)glXQueryExtensionsString(glXGetCurrentDisplay(), DefaultScreen(glXGetCurrentDisplay()));
  if (0 == p) return GL_FALSE;
  end = p + _glewStrLen(p);
  while (p < end)
  {
    int n = _glewStrCLen(p, ' ');
    if (len == n && _glewStrSame(name, p, n)) return GL_TRUE;
    p += n+1;
  }
  return GL_FALSE;
}

static GLint _glxewInit ()
{
  int major, minor;
  /* intialize glxew struct */
  _glewMemSet(&glxew, 0, sizeof(glxew));
  /* initialize core GLX 1.0-1.2 */
  if (_glxewInit_10() || _glxewInit_11() || _glxewInit_12()) return GLEW_ERROR_GLX_VERSION_11_ONLY;
  /* query GLX version */
  glXQueryVersion(glXGetCurrentDisplay(), &major, &minor);
  switch (minor)
  {
    case 2:
    glxew.GLX_10 = 1; glxew.GLX_11 = 1; glxew.GLX_12 = 1; glxew.GLX_13 = 0; glxew.GLX_14 = 0; 
    break;
    case 3:
    glxew.GLX_10 = 1; glxew.GLX_11 = 1; glxew.GLX_12 = 1; glxew.GLX_13 = 1; glxew.GLX_14 = 0; 
    break;
    case 4:
    glxew.GLX_10 = 1; glxew.GLX_11 = 1; glxew.GLX_12 = 1; glxew.GLX_13 = 1; glxew.GLX_14 = 1; 
    break;
    default:
    return GLEW_ERROR_GLX_VERSION_11_ONLY;
    break;
  }
  /* initialize core GLX 1.3-1.4 */
#ifdef GLX_VERSION_1_3
  if (glewExperimental || glxew.GLX_13) glxew.GLX_13 = !_glxewInit_13();
#endif
  /* initialize extensions */
#ifdef GLX_ARB_multisample
  glxew.ARB_multisample = glxewGetExtension("GLX_ARB_multisample");
#endif

#ifdef GLX_EXT_visual_info
  glxew.EXT_visual_info = glxewGetExtension("GLX_EXT_visual_info");
#endif
#ifdef GLX_EXT_visual_rating
  glxew.EXT_visual_rating = glxewGetExtension("GLX_EXT_visual_rating");
#endif
#ifdef GLX_EXT_import_context
  glxew.EXT_import_context = glxewGetExtension("GLX_EXT_import_context");
  if (glewExperimental || glxew.EXT_import_context) glxew.EXT_import_context = !_glxewInit_EXT_import_context();
#endif

#ifdef GLX_MESA_copy_sub_buffer
  glxew.MESA_copy_sub_buffer = glxewGetExtension("GLX_MESA_copy_sub_buffer");
  if (glewExperimental || glxew.MESA_copy_sub_buffer) glxew.MESA_copy_sub_buffer = !_glxewInit_MESA_copy_sub_buffer();
#endif
#ifdef GLX_MESA_pixmap_colormap
  glxew.MESA_pixmap_colormap = glxewGetExtension("GLX_MESA_pixmap_colormap");
  if (glewExperimental || glxew.MESA_pixmap_colormap) glxew.MESA_pixmap_colormap = !_glxewInit_MESA_pixmap_colormap();
#endif
#ifdef GLX_MESA_release_buffers
  glxew.MESA_release_buffers = glxewGetExtension("GLX_MESA_release_buffers");
  if (glewExperimental || glxew.MESA_release_buffers) glxew.MESA_release_buffers = !_glxewInit_MESA_release_buffers();
#endif
#ifdef GLX_MESA_set_3dfx_mode
  glxew.MESA_set_3dfx_mode = glxewGetExtension("GLX_MESA_set_3dfx_mode");
  if (glewExperimental || glxew.MESA_set_3dfx_mode) glxew.MESA_set_3dfx_mode = !_glxewInit_MESA_set_3dfx_mode();
#endif

#ifdef GLX_NV_vertex_array_range
  glxew.NV_vertex_array_range = glxewGetExtension("GLX_NV_vertex_array_range");
  if (glewExperimental || glxew.NV_vertex_array_range) glxew.NV_vertex_array_range = !_glxewInit_NV_vertex_array_range();
#endif

#ifdef GLX_OML_swap_method
  glxew.OML_swap_method = glxewGetExtension("GLX_OML_swap_method");
#endif
#ifdef GLX_OML_sync_control
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
  glxew.OML_sync_control = glxewGetExtension("GLX_OML_sync_control");
  if (glewExperimental || glxew.OML_sync_control) glxew.OML_sync_control = !_glxewInit_OML_sync_control();
#endif /* __STDC_VERSION__ */
#endif

#ifdef GLX_SGI_cushion
  glxew.SGI_cushion = glxewGetExtension("GLX_SGI_cushion");
  if (glewExperimental || glxew.SGI_cushion) glxew.SGI_cushion = !_glxewInit_SGI_cushion();
#endif
#ifdef GLX_SGI_make_current_read
  glxew.SGI_make_current_read = glxewGetExtension("GLX_SGI_make_current_read");
  if (glewExperimental || glxew.SGI_make_current_read) glxew.SGI_make_current_read = !_glxewInit_SGI_make_current_read();
#endif
#ifdef GLX_SGI_swap_control
  glxew.SGI_swap_control = glxewGetExtension("GLX_SGI_swap_control");
  if (glewExperimental || glxew.SGI_swap_control) glxew.SGI_swap_control = !_glxewInit_SGI_swap_control();
#endif
#ifdef GLX_SGI_video_sync
  glxew.SGI_video_sync = glxewGetExtension("GLX_SGI_video_sync");
  if (glewExperimental || glxew.SGI_video_sync) glxew.SGI_video_sync = !_glxewInit_SGI_video_sync();
#endif

#ifdef GLX_SGIS_blended_overlay
  glxew.SGIS_blended_overlay = glxewGetExtension("GLX_SGIS_blended_overlay");
#endif
#ifdef GLX_SGIS_multisample
  glxew.SGIS_multisample = glxewGetExtension("GLX_SGIS_multisample");
#endif
#ifdef GLX_SGIS_shared_multisample
  glxew.SGIS_shared_multisample = glxewGetExtension("GLX_SGIS_shared_multisample");
#endif

#ifdef GLX_SGIX_fbconfig
  glxew.SGIX_fbconfig = glxewGetExtension("GLX_SGIX_fbconfig");
  if (glewExperimental || glxew.SGIX_fbconfig) glxew.SGIX_fbconfig = !_glxewInit_SGIX_fbconfig();
#endif
#ifdef GLX_SGIX_pbuffer
  glxew.SGIX_pbuffer = glxewGetExtension("GLX_SGIX_pbuffer");
  if (glewExperimental || glxew.SGIX_pbuffer) glxew.SGIX_pbuffer = !_glxewInit_SGIX_pbuffer();
#endif
#ifdef GLX_SGIX_swap_barrier
  glxew.SGIX_swap_barrier = glxewGetExtension("GLX_SGIX_swap_barrier");
  if (glewExperimental || glxew.SGIX_swap_barrier) glxew.SGIX_swap_barrier = !_glxewInit_SGIX_swap_barrier();
#endif
#ifdef GLX_SGIX_swap_group
  glxew.SGIX_swap_group = glxewGetExtension("GLX_SGIX_swap_group");
  if (glewExperimental || glxew.SGIX_swap_group) glxew.SGIX_swap_group = !_glxewInit_SGIX_swap_group();
#endif
#ifdef GLX_SGIX_visual_select_group
  glxew.SGIX_visual_select_group = glxewGetExtension("GLX_SGIX_visual_select_group");
#endif

#ifdef GLX_SUN_get_transparent_index
  glxew.SUN_get_transparent_index = glxewGetExtension("GLX_SUN_get_transparent_index");
  if (glewExperimental || glxew.SUN_get_transparent_index) glxew.SUN_get_transparent_index = !_glxewInit_SUN_get_transparent_index();
#endif
  return GLEW_OK;
}

#endif /* _WIN32 */

/* ------------------------------------------------------------------------ */

static char _glewErrorString[6][40] =
{
  "no error",
  "missing GL version",
  "missing {ARB,EXT}_extensions_string",
  "GL 1.1 and up are not supported",
  "GLX 1.2 and up are not supported",
  "unknown error"
};

const char* glewGetErrorString (GLint error)
{
  if (error > 5) error = 5;
  return _glewErrorString[error];
}

/* ------------------------------------------------------------------------ */

struct GLEW glew;
#ifdef _WIN32
struct WGLEW wglew;
#else /* _UNIX */
struct GLXEW glxew;
#endif /* _WIN32 */
GLboolean glewExperimental = GL_FALSE;

GLint glewInit ()
{
  GLint r;
  if ( (r = _glewInit()) ) return r;
#ifdef _WIN32
  return _wglewInit();
#else /* _UNIX */
  return _glxewInit();
#endif /* _WIN32 */
}
