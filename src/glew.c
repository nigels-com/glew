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
glCopyTexSubImage3DPROC glCopyTexSubImage3D = NULL;
glDrawRangeElementsPROC glDrawRangeElements = NULL;
glTexImage3DPROC glTexImage3D = NULL;
glTexSubImage3DPROC glTexSubImage3D = NULL;

static GLboolean _glewInit_12 ()
{
  GLboolean r = GL_FALSE;
  r = r || (glCopyTexSubImage3D = (glCopyTexSubImage3DPROC)glewGetProcAddress("glCopyTexSubImage3D")) == NULL;
  r = r || (glDrawRangeElements = (glDrawRangeElementsPROC)glewGetProcAddress("glDrawRangeElements")) == NULL;
  r = r || (glTexImage3D = (glTexImage3DPROC)glewGetProcAddress("glTexImage3D")) == NULL;
  r = r || (glTexSubImage3D = (glTexSubImage3DPROC)glewGetProcAddress("glTexSubImage3D")) == NULL;
  return r;
}
#endif /* GL_VERSION_1_2 */

/* ------------------------------ OpenGL 1.3 ------------------------------ */

#ifdef GL_VERSION_1_3
glActiveTexturePROC glActiveTexture = NULL;
glClientActiveTexturePROC glClientActiveTexture = NULL;
glMultiTexCoord1dPROC glMultiTexCoord1d = NULL;
glMultiTexCoord1dvPROC glMultiTexCoord1dv = NULL;
glMultiTexCoord1fPROC glMultiTexCoord1f = NULL;
glMultiTexCoord1fvPROC glMultiTexCoord1fv = NULL;
glMultiTexCoord1iPROC glMultiTexCoord1i = NULL;
glMultiTexCoord1ivPROC glMultiTexCoord1iv = NULL;
glMultiTexCoord1sPROC glMultiTexCoord1s = NULL;
glMultiTexCoord1svPROC glMultiTexCoord1sv = NULL;
glMultiTexCoord2dPROC glMultiTexCoord2d = NULL;
glMultiTexCoord2dvPROC glMultiTexCoord2dv = NULL;
glMultiTexCoord2fPROC glMultiTexCoord2f = NULL;
glMultiTexCoord2fvPROC glMultiTexCoord2fv = NULL;
glMultiTexCoord2iPROC glMultiTexCoord2i = NULL;
glMultiTexCoord2ivPROC glMultiTexCoord2iv = NULL;
glMultiTexCoord2sPROC glMultiTexCoord2s = NULL;
glMultiTexCoord2svPROC glMultiTexCoord2sv = NULL;
glMultiTexCoord3dPROC glMultiTexCoord3d = NULL;
glMultiTexCoord3dvPROC glMultiTexCoord3dv = NULL;
glMultiTexCoord3fPROC glMultiTexCoord3f = NULL;
glMultiTexCoord3fvPROC glMultiTexCoord3fv = NULL;
glMultiTexCoord3iPROC glMultiTexCoord3i = NULL;
glMultiTexCoord3ivPROC glMultiTexCoord3iv = NULL;
glMultiTexCoord3sPROC glMultiTexCoord3s = NULL;
glMultiTexCoord3svPROC glMultiTexCoord3sv = NULL;
glMultiTexCoord4dPROC glMultiTexCoord4d = NULL;
glMultiTexCoord4dvPROC glMultiTexCoord4dv = NULL;
glMultiTexCoord4fPROC glMultiTexCoord4f = NULL;
glMultiTexCoord4fvPROC glMultiTexCoord4fv = NULL;
glMultiTexCoord4iPROC glMultiTexCoord4i = NULL;
glMultiTexCoord4ivPROC glMultiTexCoord4iv = NULL;
glMultiTexCoord4sPROC glMultiTexCoord4s = NULL;
glMultiTexCoord4svPROC glMultiTexCoord4sv = NULL;
glLoadTransposeMatrixfPROC glLoadTransposeMatrixf = NULL;
glLoadTransposeMatrixdPROC glLoadTransposeMatrixd = NULL;
glMultTransposeMatrixfPROC glMultTransposeMatrixf = NULL;
glMultTransposeMatrixdPROC glMultTransposeMatrixd = NULL;
glCompressedTexImage3DPROC glCompressedTexImage3D = NULL;
glCompressedTexImage2DPROC glCompressedTexImage2D = NULL;
glCompressedTexImage1DPROC glCompressedTexImage1D = NULL;
glCompressedTexSubImage3DPROC glCompressedTexSubImage3D = NULL;
glCompressedTexSubImage2DPROC glCompressedTexSubImage2D = NULL;
glCompressedTexSubImage1DPROC glCompressedTexSubImage1D = NULL;
glGetCompressedTexImagePROC glGetCompressedTexImage = NULL;
glSampleCoveragePROC glSampleCoverage = NULL;

static GLboolean _glewInit_13 ()
{
  GLboolean r = GL_FALSE;
  r = r || (glActiveTexture = (glActiveTexturePROC)glewGetProcAddress("glActiveTexture")) == NULL;
  r = r || (glClientActiveTexture = (glClientActiveTexturePROC)glewGetProcAddress("glClientActiveTexture")) == NULL;
  r = r || (glMultiTexCoord1d = (glMultiTexCoord1dPROC)glewGetProcAddress("glMultiTexCoord1d")) == NULL;
  r = r || (glMultiTexCoord1dv = (glMultiTexCoord1dvPROC)glewGetProcAddress("glMultiTexCoord1dv")) == NULL;
  r = r || (glMultiTexCoord1f = (glMultiTexCoord1fPROC)glewGetProcAddress("glMultiTexCoord1f")) == NULL;
  r = r || (glMultiTexCoord1fv = (glMultiTexCoord1fvPROC)glewGetProcAddress("glMultiTexCoord1fv")) == NULL;
  r = r || (glMultiTexCoord1i = (glMultiTexCoord1iPROC)glewGetProcAddress("glMultiTexCoord1i")) == NULL;
  r = r || (glMultiTexCoord1iv = (glMultiTexCoord1ivPROC)glewGetProcAddress("glMultiTexCoord1iv")) == NULL;
  r = r || (glMultiTexCoord1s = (glMultiTexCoord1sPROC)glewGetProcAddress("glMultiTexCoord1s")) == NULL;
  r = r || (glMultiTexCoord1sv = (glMultiTexCoord1svPROC)glewGetProcAddress("glMultiTexCoord1sv")) == NULL;
  r = r || (glMultiTexCoord2d = (glMultiTexCoord2dPROC)glewGetProcAddress("glMultiTexCoord2d")) == NULL;
  r = r || (glMultiTexCoord2dv = (glMultiTexCoord2dvPROC)glewGetProcAddress("glMultiTexCoord2dv")) == NULL;
  r = r || (glMultiTexCoord2f = (glMultiTexCoord2fPROC)glewGetProcAddress("glMultiTexCoord2f")) == NULL;
  r = r || (glMultiTexCoord2fv = (glMultiTexCoord2fvPROC)glewGetProcAddress("glMultiTexCoord2fv")) == NULL;
  r = r || (glMultiTexCoord2i = (glMultiTexCoord2iPROC)glewGetProcAddress("glMultiTexCoord2i")) == NULL;
  r = r || (glMultiTexCoord2iv = (glMultiTexCoord2ivPROC)glewGetProcAddress("glMultiTexCoord2iv")) == NULL;
  r = r || (glMultiTexCoord2s = (glMultiTexCoord2sPROC)glewGetProcAddress("glMultiTexCoord2s")) == NULL;
  r = r || (glMultiTexCoord2sv = (glMultiTexCoord2svPROC)glewGetProcAddress("glMultiTexCoord2sv")) == NULL;
  r = r || (glMultiTexCoord3d = (glMultiTexCoord3dPROC)glewGetProcAddress("glMultiTexCoord3d")) == NULL;
  r = r || (glMultiTexCoord3dv = (glMultiTexCoord3dvPROC)glewGetProcAddress("glMultiTexCoord3dv")) == NULL;
  r = r || (glMultiTexCoord3f = (glMultiTexCoord3fPROC)glewGetProcAddress("glMultiTexCoord3f")) == NULL;
  r = r || (glMultiTexCoord3fv = (glMultiTexCoord3fvPROC)glewGetProcAddress("glMultiTexCoord3fv")) == NULL;
  r = r || (glMultiTexCoord3i = (glMultiTexCoord3iPROC)glewGetProcAddress("glMultiTexCoord3i")) == NULL;
  r = r || (glMultiTexCoord3iv = (glMultiTexCoord3ivPROC)glewGetProcAddress("glMultiTexCoord3iv")) == NULL;
  r = r || (glMultiTexCoord3s = (glMultiTexCoord3sPROC)glewGetProcAddress("glMultiTexCoord3s")) == NULL;
  r = r || (glMultiTexCoord3sv = (glMultiTexCoord3svPROC)glewGetProcAddress("glMultiTexCoord3sv")) == NULL;
  r = r || (glMultiTexCoord4d = (glMultiTexCoord4dPROC)glewGetProcAddress("glMultiTexCoord4d")) == NULL;
  r = r || (glMultiTexCoord4dv = (glMultiTexCoord4dvPROC)glewGetProcAddress("glMultiTexCoord4dv")) == NULL;
  r = r || (glMultiTexCoord4f = (glMultiTexCoord4fPROC)glewGetProcAddress("glMultiTexCoord4f")) == NULL;
  r = r || (glMultiTexCoord4fv = (glMultiTexCoord4fvPROC)glewGetProcAddress("glMultiTexCoord4fv")) == NULL;
  r = r || (glMultiTexCoord4i = (glMultiTexCoord4iPROC)glewGetProcAddress("glMultiTexCoord4i")) == NULL;
  r = r || (glMultiTexCoord4iv = (glMultiTexCoord4ivPROC)glewGetProcAddress("glMultiTexCoord4iv")) == NULL;
  r = r || (glMultiTexCoord4s = (glMultiTexCoord4sPROC)glewGetProcAddress("glMultiTexCoord4s")) == NULL;
  r = r || (glMultiTexCoord4sv = (glMultiTexCoord4svPROC)glewGetProcAddress("glMultiTexCoord4sv")) == NULL;
  r = r || (glLoadTransposeMatrixf = (glLoadTransposeMatrixfPROC)glewGetProcAddress("glLoadTransposeMatrixf")) == NULL;
  r = r || (glLoadTransposeMatrixd = (glLoadTransposeMatrixdPROC)glewGetProcAddress("glLoadTransposeMatrixd")) == NULL;
  r = r || (glMultTransposeMatrixf = (glMultTransposeMatrixfPROC)glewGetProcAddress("glMultTransposeMatrixf")) == NULL;
  r = r || (glMultTransposeMatrixd = (glMultTransposeMatrixdPROC)glewGetProcAddress("glMultTransposeMatrixd")) == NULL;
  r = r || (glCompressedTexImage3D = (glCompressedTexImage3DPROC)glewGetProcAddress("glCompressedTexImage3D")) == NULL;
  r = r || (glCompressedTexImage2D = (glCompressedTexImage2DPROC)glewGetProcAddress("glCompressedTexImage2D")) == NULL;
  r = r || (glCompressedTexImage1D = (glCompressedTexImage1DPROC)glewGetProcAddress("glCompressedTexImage1D")) == NULL;
  r = r || (glCompressedTexSubImage3D = (glCompressedTexSubImage3DPROC)glewGetProcAddress("glCompressedTexSubImage3D")) == NULL;
  r = r || (glCompressedTexSubImage2D = (glCompressedTexSubImage2DPROC)glewGetProcAddress("glCompressedTexSubImage2D")) == NULL;
  r = r || (glCompressedTexSubImage1D = (glCompressedTexSubImage1DPROC)glewGetProcAddress("glCompressedTexSubImage1D")) == NULL;
  r = r || (glGetCompressedTexImage = (glGetCompressedTexImagePROC)glewGetProcAddress("glGetCompressedTexImage")) == NULL;
  r = r || (glSampleCoverage = (glSampleCoveragePROC)glewGetProcAddress("glSampleCoverage")) == NULL;
  return r;
}
#endif /* GL_VERSION_1_3 */

/* ------------------------------ OpenGL 1.4 ------------------------------ */

#ifdef GL_VERSION_1_4
#ifndef GL_ARB_imaging
glBlendColorPROC glBlendColor = NULL;
glBlendEquationPROC glBlendEquation = NULL;
#endif /* GL_ARB_imaging */
glFogCoordfPROC glFogCoordf = NULL;
glFogCoordfvPROC glFogCoordfv = NULL;
glFogCoorddPROC glFogCoordd = NULL;
glFogCoorddvPROC glFogCoorddv = NULL;
glFogCoordPointerPROC glFogCoordPointer = NULL;
glMultiDrawArraysPROC glMultiDrawArrays = NULL;
glMultiDrawElementsPROC glMultiDrawElements = NULL;
glPointParameterfPROC glPointParameterf = NULL;
glPointParameterfvPROC glPointParameterfv = NULL;
glSecondaryColor3bPROC glSecondaryColor3b = NULL;
glSecondaryColor3bvPROC glSecondaryColor3bv = NULL;
glSecondaryColor3dPROC glSecondaryColor3d = NULL;
glSecondaryColor3dvPROC glSecondaryColor3dv = NULL;
glSecondaryColor3fPROC glSecondaryColor3f = NULL;
glSecondaryColor3fvPROC glSecondaryColor3fv = NULL;
glSecondaryColor3iPROC glSecondaryColor3i = NULL;
glSecondaryColor3ivPROC glSecondaryColor3iv = NULL;
glSecondaryColor3sPROC glSecondaryColor3s = NULL;
glSecondaryColor3svPROC glSecondaryColor3sv = NULL;
glSecondaryColor3ubPROC glSecondaryColor3ub = NULL;
glSecondaryColor3ubvPROC glSecondaryColor3ubv = NULL;
glSecondaryColor3uiPROC glSecondaryColor3ui = NULL;
glSecondaryColor3uivPROC glSecondaryColor3uiv = NULL;
glSecondaryColor3usPROC glSecondaryColor3us = NULL;
glSecondaryColor3usvPROC glSecondaryColor3usv = NULL;
glSecondaryColorPointerPROC glSecondaryColorPointer = NULL;
glBlendFuncSeparatePROC glBlendFuncSeparate = NULL;
glWindowPos2dPROC glWindowPos2d = NULL;
glWindowPos2fPROC glWindowPos2f = NULL;
glWindowPos2iPROC glWindowPos2i = NULL;
glWindowPos2sPROC glWindowPos2s = NULL;
glWindowPos2dvPROC glWindowPos2dv = NULL;
glWindowPos2fvPROC glWindowPos2fv = NULL;
glWindowPos2ivPROC glWindowPos2iv = NULL;
glWindowPos2svPROC glWindowPos2sv = NULL;
glWindowPos3dPROC glWindowPos3d = NULL;
glWindowPos3fPROC glWindowPos3f = NULL;
glWindowPos3iPROC glWindowPos3i = NULL;
glWindowPos3sPROC glWindowPos3s = NULL;
glWindowPos3dvPROC glWindowPos3dv = NULL;
glWindowPos3fvPROC glWindowPos3fv = NULL;
glWindowPos3ivPROC glWindowPos3iv = NULL;
glWindowPos3svPROC glWindowPos3sv = NULL;

static GLboolean _glewInit_14 ()
{
  GLboolean r = GL_FALSE;
#ifndef GL_ARB_imaging
  r = r || (glBlendColor = (glBlendColorPROC)glewGetProcAddress("glBlendColor")) == NULL;
  r = r || (glBlendEquation = (glBlendEquationPROC)glewGetProcAddress("glBlendEquation")) == NULL;
#endif /* GL_ARB_imaging */
  r = r || (glFogCoordf = (glFogCoordfPROC)glewGetProcAddress("glFogCoordf")) == NULL;
  r = r || (glFogCoordfv = (glFogCoordfvPROC)glewGetProcAddress("glFogCoordfv")) == NULL;
  r = r || (glFogCoordd = (glFogCoorddPROC)glewGetProcAddress("glFogCoordd")) == NULL;
  r = r || (glFogCoorddv = (glFogCoorddvPROC)glewGetProcAddress("glFogCoorddv")) == NULL;
  r = r || (glFogCoordPointer = (glFogCoordPointerPROC)glewGetProcAddress("glFogCoordPointer")) == NULL;
  r = r || (glMultiDrawArrays = (glMultiDrawArraysPROC)glewGetProcAddress("glMultiDrawArrays")) == NULL;
  r = r || (glMultiDrawElements = (glMultiDrawElementsPROC)glewGetProcAddress("glMultiDrawElements")) == NULL;
  r = r || (glPointParameterf = (glPointParameterfPROC)glewGetProcAddress("glPointParameterf")) == NULL;
  r = r || (glPointParameterfv = (glPointParameterfvPROC)glewGetProcAddress("glPointParameterfv")) == NULL;
  r = r || (glSecondaryColor3b = (glSecondaryColor3bPROC)glewGetProcAddress("glSecondaryColor3b")) == NULL;
  r = r || (glSecondaryColor3bv = (glSecondaryColor3bvPROC)glewGetProcAddress("glSecondaryColor3bv")) == NULL;
  r = r || (glSecondaryColor3d = (glSecondaryColor3dPROC)glewGetProcAddress("glSecondaryColor3d")) == NULL;
  r = r || (glSecondaryColor3dv = (glSecondaryColor3dvPROC)glewGetProcAddress("glSecondaryColor3dv")) == NULL;
  r = r || (glSecondaryColor3f = (glSecondaryColor3fPROC)glewGetProcAddress("glSecondaryColor3f")) == NULL;
  r = r || (glSecondaryColor3fv = (glSecondaryColor3fvPROC)glewGetProcAddress("glSecondaryColor3fv")) == NULL;
  r = r || (glSecondaryColor3i = (glSecondaryColor3iPROC)glewGetProcAddress("glSecondaryColor3i")) == NULL;
  r = r || (glSecondaryColor3iv = (glSecondaryColor3ivPROC)glewGetProcAddress("glSecondaryColor3iv")) == NULL;
  r = r || (glSecondaryColor3s = (glSecondaryColor3sPROC)glewGetProcAddress("glSecondaryColor3s")) == NULL;
  r = r || (glSecondaryColor3sv = (glSecondaryColor3svPROC)glewGetProcAddress("glSecondaryColor3sv")) == NULL;
  r = r || (glSecondaryColor3ub = (glSecondaryColor3ubPROC)glewGetProcAddress("glSecondaryColor3ub")) == NULL;
  r = r || (glSecondaryColor3ubv = (glSecondaryColor3ubvPROC)glewGetProcAddress("glSecondaryColor3ubv")) == NULL;
  r = r || (glSecondaryColor3ui = (glSecondaryColor3uiPROC)glewGetProcAddress("glSecondaryColor3ui")) == NULL;
  r = r || (glSecondaryColor3uiv = (glSecondaryColor3uivPROC)glewGetProcAddress("glSecondaryColor3uiv")) == NULL;
  r = r || (glSecondaryColor3us = (glSecondaryColor3usPROC)glewGetProcAddress("glSecondaryColor3us")) == NULL;
  r = r || (glSecondaryColor3usv = (glSecondaryColor3usvPROC)glewGetProcAddress("glSecondaryColor3usv")) == NULL;
  r = r || (glSecondaryColorPointer = (glSecondaryColorPointerPROC)glewGetProcAddress("glSecondaryColorPointer")) == NULL;
  r = r || (glBlendFuncSeparate = (glBlendFuncSeparatePROC)glewGetProcAddress("glBlendFuncSeparate")) == NULL;
  r = r || (glWindowPos2d = (glWindowPos2dPROC)glewGetProcAddress("glWindowPos2d")) == NULL;
  r = r || (glWindowPos2f = (glWindowPos2fPROC)glewGetProcAddress("glWindowPos2f")) == NULL;
  r = r || (glWindowPos2i = (glWindowPos2iPROC)glewGetProcAddress("glWindowPos2i")) == NULL;
  r = r || (glWindowPos2s = (glWindowPos2sPROC)glewGetProcAddress("glWindowPos2s")) == NULL;
  r = r || (glWindowPos2dv = (glWindowPos2dvPROC)glewGetProcAddress("glWindowPos2dv")) == NULL;
  r = r || (glWindowPos2fv = (glWindowPos2fvPROC)glewGetProcAddress("glWindowPos2fv")) == NULL;
  r = r || (glWindowPos2iv = (glWindowPos2ivPROC)glewGetProcAddress("glWindowPos2iv")) == NULL;
  r = r || (glWindowPos2sv = (glWindowPos2svPROC)glewGetProcAddress("glWindowPos2sv")) == NULL;
  r = r || (glWindowPos3d = (glWindowPos3dPROC)glewGetProcAddress("glWindowPos3d")) == NULL;
  r = r || (glWindowPos3f = (glWindowPos3fPROC)glewGetProcAddress("glWindowPos3f")) == NULL;
  r = r || (glWindowPos3i = (glWindowPos3iPROC)glewGetProcAddress("glWindowPos3i")) == NULL;
  r = r || (glWindowPos3s = (glWindowPos3sPROC)glewGetProcAddress("glWindowPos3s")) == NULL;
  r = r || (glWindowPos3dv = (glWindowPos3dvPROC)glewGetProcAddress("glWindowPos3dv")) == NULL;
  r = r || (glWindowPos3fv = (glWindowPos3fvPROC)glewGetProcAddress("glWindowPos3fv")) == NULL;
  r = r || (glWindowPos3iv = (glWindowPos3ivPROC)glewGetProcAddress("glWindowPos3iv")) == NULL;
  r = r || (glWindowPos3sv = (glWindowPos3svPROC)glewGetProcAddress("glWindowPos3sv")) == NULL;
  return r;
}
#endif /* GL_VERSION_1_4 */

/* ------------------------------ ARB_imaging ----------------------------- */

#ifdef GL_ARB_imaging
glBlendColorPROC glBlendColor = NULL;
glBlendEquationPROC glBlendEquation = NULL;
glColorTablePROC glColorTable = NULL;
glColorTableParameterfvPROC glColorTableParameterfv = NULL;
glColorTableParameterivPROC glColorTableParameteriv = NULL;
glCopyColorTablePROC glCopyColorTable = NULL;
glGetColorTablePROC glGetColorTable = NULL;
glGetColorTableParameterfvPROC glGetColorTableParameterfv = NULL;
glGetColorTableParameterivPROC glGetColorTableParameteriv = NULL;
glColorSubTablePROC glColorSubTable = NULL;
glCopyColorSubTablePROC glCopyColorSubTable = NULL;
glConvolutionFilter1DPROC glConvolutionFilter1D = NULL;
glConvolutionFilter2DPROC glConvolutionFilter2D = NULL;
glConvolutionParameterfPROC glConvolutionParameterf = NULL;
glConvolutionParameterfvPROC glConvolutionParameterfv = NULL;
glConvolutionParameteriPROC glConvolutionParameteri = NULL;
glConvolutionParameterivPROC glConvolutionParameteriv = NULL;
glCopyConvolutionFilter1DPROC glCopyConvolutionFilter1D = NULL;
glCopyConvolutionFilter2DPROC glCopyConvolutionFilter2D = NULL;
glGetConvolutionFilterPROC glGetConvolutionFilter = NULL;
glGetConvolutionParameterfvPROC glGetConvolutionParameterfv = NULL;
glGetConvolutionParameterivPROC glGetConvolutionParameteriv = NULL;
glGetSeparableFilterPROC glGetSeparableFilter = NULL;
glSeparableFilter2DPROC glSeparableFilter2D = NULL;
glGetHistogramPROC glGetHistogram = NULL;
glGetHistogramParameterfvPROC glGetHistogramParameterfv = NULL;
glGetHistogramParameterivPROC glGetHistogramParameteriv = NULL;
glGetMinmaxPROC glGetMinmax = NULL;
glGetMinmaxParameterfvPROC glGetMinmaxParameterfv = NULL;
glGetMinmaxParameterivPROC glGetMinmaxParameteriv = NULL;
glHistogramPROC glHistogram = NULL;
glMinmaxPROC glMinmax = NULL;
glResetHistogramPROC glResetHistogram = NULL;
glResetMinmaxPROC glResetMinmax = NULL;

static GLboolean _glewInit_ARB_imaging ()
{
  GLboolean r = GL_FALSE;
  r = r || (glBlendColor = (glBlendColorPROC)glewGetProcAddress("glBlendColor")) == NULL;
  r = r || (glBlendEquation = (glBlendEquationPROC)glewGetProcAddress("glBlendEquation")) == NULL;
  r = r || (glColorTable = (glColorTablePROC)glewGetProcAddress("glColorTable")) == NULL;
  r = r || (glColorTableParameterfv = (glColorTableParameterfvPROC)glewGetProcAddress("glColorTableParameterfv")) == NULL;
  r = r || (glColorTableParameteriv = (glColorTableParameterivPROC)glewGetProcAddress("glColorTableParameteriv")) == NULL;
  r = r || (glCopyColorTable = (glCopyColorTablePROC)glewGetProcAddress("glCopyColorTable")) == NULL;
  r = r || (glGetColorTable = (glGetColorTablePROC)glewGetProcAddress("glGetColorTable")) == NULL;
  r = r || (glGetColorTableParameterfv = (glGetColorTableParameterfvPROC)glewGetProcAddress("glGetColorTableParameterfv")) == NULL;
  r = r || (glGetColorTableParameteriv = (glGetColorTableParameterivPROC)glewGetProcAddress("glGetColorTableParameteriv")) == NULL;
  r = r || (glColorSubTable = (glColorSubTablePROC)glewGetProcAddress("glColorSubTable")) == NULL;
  r = r || (glCopyColorSubTable = (glCopyColorSubTablePROC)glewGetProcAddress("glCopyColorSubTable")) == NULL;
  r = r || (glConvolutionFilter1D = (glConvolutionFilter1DPROC)glewGetProcAddress("glConvolutionFilter1D")) == NULL;
  r = r || (glConvolutionFilter2D = (glConvolutionFilter2DPROC)glewGetProcAddress("glConvolutionFilter2D")) == NULL;
  r = r || (glConvolutionParameterf = (glConvolutionParameterfPROC)glewGetProcAddress("glConvolutionParameterf")) == NULL;
  r = r || (glConvolutionParameterfv = (glConvolutionParameterfvPROC)glewGetProcAddress("glConvolutionParameterfv")) == NULL;
  r = r || (glConvolutionParameteri = (glConvolutionParameteriPROC)glewGetProcAddress("glConvolutionParameteri")) == NULL;
  r = r || (glConvolutionParameteriv = (glConvolutionParameterivPROC)glewGetProcAddress("glConvolutionParameteriv")) == NULL;
  r = r || (glCopyConvolutionFilter1D = (glCopyConvolutionFilter1DPROC)glewGetProcAddress("glCopyConvolutionFilter1D")) == NULL;
  r = r || (glCopyConvolutionFilter2D = (glCopyConvolutionFilter2DPROC)glewGetProcAddress("glCopyConvolutionFilter2D")) == NULL;
  r = r || (glGetConvolutionFilter = (glGetConvolutionFilterPROC)glewGetProcAddress("glGetConvolutionFilter")) == NULL;
  r = r || (glGetConvolutionParameterfv = (glGetConvolutionParameterfvPROC)glewGetProcAddress("glGetConvolutionParameterfv")) == NULL;
  r = r || (glGetConvolutionParameteriv = (glGetConvolutionParameterivPROC)glewGetProcAddress("glGetConvolutionParameteriv")) == NULL;
  r = r || (glGetSeparableFilter = (glGetSeparableFilterPROC)glewGetProcAddress("glGetSeparableFilter")) == NULL;
  r = r || (glSeparableFilter2D = (glSeparableFilter2DPROC)glewGetProcAddress("glSeparableFilter2D")) == NULL;
  r = r || (glGetHistogram = (glGetHistogramPROC)glewGetProcAddress("glGetHistogram")) == NULL;
  r = r || (glGetHistogramParameterfv = (glGetHistogramParameterfvPROC)glewGetProcAddress("glGetHistogramParameterfv")) == NULL;
  r = r || (glGetHistogramParameteriv = (glGetHistogramParameterivPROC)glewGetProcAddress("glGetHistogramParameteriv")) == NULL;
  r = r || (glGetMinmax = (glGetMinmaxPROC)glewGetProcAddress("glGetMinmax")) == NULL;
  r = r || (glGetMinmaxParameterfv = (glGetMinmaxParameterfvPROC)glewGetProcAddress("glGetMinmaxParameterfv")) == NULL;
  r = r || (glGetMinmaxParameteriv = (glGetMinmaxParameterivPROC)glewGetProcAddress("glGetMinmaxParameteriv")) == NULL;
  r = r || (glHistogram = (glHistogramPROC)glewGetProcAddress("glHistogram")) == NULL;
  r = r || (glMinmax = (glMinmaxPROC)glewGetProcAddress("glMinmax")) == NULL;
  r = r || (glResetHistogram = (glResetHistogramPROC)glewGetProcAddress("glResetHistogram")) == NULL;
  r = r || (glResetMinmax = (glResetMinmaxPROC)glewGetProcAddress("glResetMinmax")) == NULL;
  return r;
}
#endif /* GL_ARB_imaging */

/* -------------------------- ARB_matrix_palette -------------------------- */

#ifdef GL_ARB_matrix_palette
glCurrentPaletteMatrixARBPROC glCurrentPaletteMatrixARB = NULL;
glMatrixIndexubvARBPROC glMatrixIndexubvARB = NULL;
glMatrixIndexusvARBPROC glMatrixIndexusvARB = NULL;
glMatrixIndexuivARBPROC glMatrixIndexuivARB = NULL;
glMatrixIndexPointerARBPROC glMatrixIndexPointerARB = NULL;

static GLboolean _glewInit_ARB_matrix_palette ()
{
  GLboolean r = GL_FALSE;
  r = r || (glCurrentPaletteMatrixARB = (glCurrentPaletteMatrixARBPROC)glewGetProcAddress("glCurrentPaletteMatrixARB")) == NULL;
  r = r || (glMatrixIndexubvARB = (glMatrixIndexubvARBPROC)glewGetProcAddress("glMatrixIndexubvARB")) == NULL;
  r = r || (glMatrixIndexusvARB = (glMatrixIndexusvARBPROC)glewGetProcAddress("glMatrixIndexusvARB")) == NULL;
  r = r || (glMatrixIndexuivARB = (glMatrixIndexuivARBPROC)glewGetProcAddress("glMatrixIndexuivARB")) == NULL;
  r = r || (glMatrixIndexPointerARB = (glMatrixIndexPointerARBPROC)glewGetProcAddress("glMatrixIndexPointerARB")) == NULL;
  return r;
}
#endif /* GL_ARB_matrix_palette */

/* ---------------------------- ARB_multisample --------------------------- */

#ifdef GL_ARB_multisample
glSampleCoverageARBPROC glSampleCoverageARB = NULL;

static GLboolean _glewInit_ARB_multisample ()
{
  GLboolean r = GL_FALSE;
  r = r || (glSampleCoverageARB = (glSampleCoverageARBPROC)glewGetProcAddress("glSampleCoverageARB")) == NULL;
  return r;
}
#endif /* GL_ARB_multisample */

/* --------------------------- ARB_multitexture --------------------------- */

#ifdef GL_ARB_multitexture
glActiveTextureARBPROC glActiveTextureARB = NULL;
glClientActiveTextureARBPROC glClientActiveTextureARB = NULL;
glMultiTexCoord1dARBPROC glMultiTexCoord1dARB = NULL;
glMultiTexCoord1dvARBPROC glMultiTexCoord1dvARB = NULL;
glMultiTexCoord1fARBPROC glMultiTexCoord1fARB = NULL;
glMultiTexCoord1fvARBPROC glMultiTexCoord1fvARB = NULL;
glMultiTexCoord1iARBPROC glMultiTexCoord1iARB = NULL;
glMultiTexCoord1ivARBPROC glMultiTexCoord1ivARB = NULL;
glMultiTexCoord1sARBPROC glMultiTexCoord1sARB = NULL;
glMultiTexCoord1svARBPROC glMultiTexCoord1svARB = NULL;
glMultiTexCoord2dARBPROC glMultiTexCoord2dARB = NULL;
glMultiTexCoord2dvARBPROC glMultiTexCoord2dvARB = NULL;
glMultiTexCoord2fARBPROC glMultiTexCoord2fARB = NULL;
glMultiTexCoord2fvARBPROC glMultiTexCoord2fvARB = NULL;
glMultiTexCoord2iARBPROC glMultiTexCoord2iARB = NULL;
glMultiTexCoord2ivARBPROC glMultiTexCoord2ivARB = NULL;
glMultiTexCoord2sARBPROC glMultiTexCoord2sARB = NULL;
glMultiTexCoord2svARBPROC glMultiTexCoord2svARB = NULL;
glMultiTexCoord3dARBPROC glMultiTexCoord3dARB = NULL;
glMultiTexCoord3dvARBPROC glMultiTexCoord3dvARB = NULL;
glMultiTexCoord3fARBPROC glMultiTexCoord3fARB = NULL;
glMultiTexCoord3fvARBPROC glMultiTexCoord3fvARB = NULL;
glMultiTexCoord3iARBPROC glMultiTexCoord3iARB = NULL;
glMultiTexCoord3ivARBPROC glMultiTexCoord3ivARB = NULL;
glMultiTexCoord3sARBPROC glMultiTexCoord3sARB = NULL;
glMultiTexCoord3svARBPROC glMultiTexCoord3svARB = NULL;
glMultiTexCoord4dARBPROC glMultiTexCoord4dARB = NULL;
glMultiTexCoord4dvARBPROC glMultiTexCoord4dvARB = NULL;
glMultiTexCoord4fARBPROC glMultiTexCoord4fARB = NULL;
glMultiTexCoord4fvARBPROC glMultiTexCoord4fvARB = NULL;
glMultiTexCoord4iARBPROC glMultiTexCoord4iARB = NULL;
glMultiTexCoord4ivARBPROC glMultiTexCoord4ivARB = NULL;
glMultiTexCoord4sARBPROC glMultiTexCoord4sARB = NULL;
glMultiTexCoord4svARBPROC glMultiTexCoord4svARB = NULL;

static GLboolean _glewInit_ARB_multitexture ()
{
  GLboolean r = GL_FALSE;
  r = r || (glActiveTextureARB = (glActiveTextureARBPROC)glewGetProcAddress("glActiveTextureARB")) == NULL;
  r = r || (glClientActiveTextureARB = (glClientActiveTextureARBPROC)glewGetProcAddress("glClientActiveTextureARB")) == NULL;
  r = r || (glMultiTexCoord1dARB = (glMultiTexCoord1dARBPROC)glewGetProcAddress("glMultiTexCoord1dARB")) == NULL;
  r = r || (glMultiTexCoord1dvARB = (glMultiTexCoord1dvARBPROC)glewGetProcAddress("glMultiTexCoord1dvARB")) == NULL;
  r = r || (glMultiTexCoord1fARB = (glMultiTexCoord1fARBPROC)glewGetProcAddress("glMultiTexCoord1fARB")) == NULL;
  r = r || (glMultiTexCoord1fvARB = (glMultiTexCoord1fvARBPROC)glewGetProcAddress("glMultiTexCoord1fvARB")) == NULL;
  r = r || (glMultiTexCoord1iARB = (glMultiTexCoord1iARBPROC)glewGetProcAddress("glMultiTexCoord1iARB")) == NULL;
  r = r || (glMultiTexCoord1ivARB = (glMultiTexCoord1ivARBPROC)glewGetProcAddress("glMultiTexCoord1ivARB")) == NULL;
  r = r || (glMultiTexCoord1sARB = (glMultiTexCoord1sARBPROC)glewGetProcAddress("glMultiTexCoord1sARB")) == NULL;
  r = r || (glMultiTexCoord1svARB = (glMultiTexCoord1svARBPROC)glewGetProcAddress("glMultiTexCoord1svARB")) == NULL;
  r = r || (glMultiTexCoord2dARB = (glMultiTexCoord2dARBPROC)glewGetProcAddress("glMultiTexCoord2dARB")) == NULL;
  r = r || (glMultiTexCoord2dvARB = (glMultiTexCoord2dvARBPROC)glewGetProcAddress("glMultiTexCoord2dvARB")) == NULL;
  r = r || (glMultiTexCoord2fARB = (glMultiTexCoord2fARBPROC)glewGetProcAddress("glMultiTexCoord2fARB")) == NULL;
  r = r || (glMultiTexCoord2fvARB = (glMultiTexCoord2fvARBPROC)glewGetProcAddress("glMultiTexCoord2fvARB")) == NULL;
  r = r || (glMultiTexCoord2iARB = (glMultiTexCoord2iARBPROC)glewGetProcAddress("glMultiTexCoord2iARB")) == NULL;
  r = r || (glMultiTexCoord2ivARB = (glMultiTexCoord2ivARBPROC)glewGetProcAddress("glMultiTexCoord2ivARB")) == NULL;
  r = r || (glMultiTexCoord2sARB = (glMultiTexCoord2sARBPROC)glewGetProcAddress("glMultiTexCoord2sARB")) == NULL;
  r = r || (glMultiTexCoord2svARB = (glMultiTexCoord2svARBPROC)glewGetProcAddress("glMultiTexCoord2svARB")) == NULL;
  r = r || (glMultiTexCoord3dARB = (glMultiTexCoord3dARBPROC)glewGetProcAddress("glMultiTexCoord3dARB")) == NULL;
  r = r || (glMultiTexCoord3dvARB = (glMultiTexCoord3dvARBPROC)glewGetProcAddress("glMultiTexCoord3dvARB")) == NULL;
  r = r || (glMultiTexCoord3fARB = (glMultiTexCoord3fARBPROC)glewGetProcAddress("glMultiTexCoord3fARB")) == NULL;
  r = r || (glMultiTexCoord3fvARB = (glMultiTexCoord3fvARBPROC)glewGetProcAddress("glMultiTexCoord3fvARB")) == NULL;
  r = r || (glMultiTexCoord3iARB = (glMultiTexCoord3iARBPROC)glewGetProcAddress("glMultiTexCoord3iARB")) == NULL;
  r = r || (glMultiTexCoord3ivARB = (glMultiTexCoord3ivARBPROC)glewGetProcAddress("glMultiTexCoord3ivARB")) == NULL;
  r = r || (glMultiTexCoord3sARB = (glMultiTexCoord3sARBPROC)glewGetProcAddress("glMultiTexCoord3sARB")) == NULL;
  r = r || (glMultiTexCoord3svARB = (glMultiTexCoord3svARBPROC)glewGetProcAddress("glMultiTexCoord3svARB")) == NULL;
  r = r || (glMultiTexCoord4dARB = (glMultiTexCoord4dARBPROC)glewGetProcAddress("glMultiTexCoord4dARB")) == NULL;
  r = r || (glMultiTexCoord4dvARB = (glMultiTexCoord4dvARBPROC)glewGetProcAddress("glMultiTexCoord4dvARB")) == NULL;
  r = r || (glMultiTexCoord4fARB = (glMultiTexCoord4fARBPROC)glewGetProcAddress("glMultiTexCoord4fARB")) == NULL;
  r = r || (glMultiTexCoord4fvARB = (glMultiTexCoord4fvARBPROC)glewGetProcAddress("glMultiTexCoord4fvARB")) == NULL;
  r = r || (glMultiTexCoord4iARB = (glMultiTexCoord4iARBPROC)glewGetProcAddress("glMultiTexCoord4iARB")) == NULL;
  r = r || (glMultiTexCoord4ivARB = (glMultiTexCoord4ivARBPROC)glewGetProcAddress("glMultiTexCoord4ivARB")) == NULL;
  r = r || (glMultiTexCoord4sARB = (glMultiTexCoord4sARBPROC)glewGetProcAddress("glMultiTexCoord4sARB")) == NULL;
  r = r || (glMultiTexCoord4svARB = (glMultiTexCoord4svARBPROC)glewGetProcAddress("glMultiTexCoord4svARB")) == NULL;
  return r;
}
#endif /* GL_ARB_multitexture */

/* ------------------------- ARB_point_parameters ------------------------- */

#ifdef GL_ARB_point_parameters
glPointParameterfARBPROC glPointParameterfARB = NULL;
glPointParameterfvARBPROC glPointParameterfvARB = NULL;

static GLboolean _glewInit_ARB_point_parameters ()
{
  GLboolean r = GL_FALSE;
  r = r || (glPointParameterfARB = (glPointParameterfARBPROC)glewGetProcAddress("glPointParameterfARB")) == NULL;
  r = r || (glPointParameterfvARB = (glPointParameterfvARBPROC)glewGetProcAddress("glPointParameterfvARB")) == NULL;
  return r;
}
#endif /* GL_ARB_point_parameters */

/* ------------------------ ARB_texture_compression ----------------------- */

#ifdef GL_ARB_texture_compression
glCompressedTexImage3DARBPROC glCompressedTexImage3DARB = NULL;
glCompressedTexImage2DARBPROC glCompressedTexImage2DARB = NULL;
glCompressedTexImage1DARBPROC glCompressedTexImage1DARB = NULL; 
glCompressedTexSubImage3DARBPROC glCompressedTexSubImage3DARB = NULL;
glCompressedTexSubImage2DARBPROC glCompressedTexSubImage2DARB = NULL;
glCompressedTexSubImage1DARBPROC glCompressedTexSubImage1DARB = NULL;
glGetCompressedTexImageARBPROC glGetCompressedTexImageARB = NULL;

static GLboolean _glewInit_ARB_texture_compression ()
{
  GLboolean r = GL_FALSE;
  r = r || (glCompressedTexImage3DARB = (glCompressedTexImage3DARBPROC)glewGetProcAddress("glCompressedTexImage3DARB")) == NULL;
  r = r || (glCompressedTexImage2DARB = (glCompressedTexImage2DARBPROC)glewGetProcAddress("glCompressedTexImage2DARB")) == NULL;
  r = r || (glCompressedTexImage1DARB = (glCompressedTexImage1DARBPROC)glewGetProcAddress("glCompressedTexImage1DARB")) == NULL;
  r = r || (glCompressedTexSubImage3DARB = (glCompressedTexSubImage3DARBPROC)glewGetProcAddress("glCompressedTexSubImage3DARB")) == NULL;
  r = r || (glCompressedTexSubImage2DARB = (glCompressedTexSubImage2DARBPROC)glewGetProcAddress("glCompressedTexSubImage2DARB")) == NULL;
  r = r || (glCompressedTexSubImage1DARB = (glCompressedTexSubImage1DARBPROC)glewGetProcAddress("glCompressedTexSubImage1DARB")) == NULL;
  r = r || (glGetCompressedTexImageARB = (glGetCompressedTexImageARBPROC)glewGetProcAddress("glGetCompressedTexImageARB")) == NULL;
  return r;
}
#endif /* GL_ARB_texture_compression */

/* ------------------------- ARB_transpose_matrix ------------------------- */

#ifdef GL_ARB_transpose_matrix
glLoadTransposeMatrixfARBPROC glLoadTransposeMatrixfARB = NULL;
glLoadTransposeMatrixdARBPROC glLoadTransposeMatrixdARB = NULL;
glMultTransposeMatrixfARBPROC glMultTransposeMatrixfARB = NULL;
glMultTransposeMatrixdARBPROC glMultTransposeMatrixdARB = NULL;

static GLboolean _glewInit_ARB_transpose_matrix ()
{
  GLboolean r = GL_FALSE;
  r = r || (glLoadTransposeMatrixfARB = (glLoadTransposeMatrixfARBPROC)glewGetProcAddress("glLoadTransposeMatrixfARB")) == NULL;
  r = r || (glLoadTransposeMatrixdARB = (glLoadTransposeMatrixdARBPROC)glewGetProcAddress("glLoadTransposeMatrixdARB")) == NULL;
  r = r || (glMultTransposeMatrixfARB = (glMultTransposeMatrixfARBPROC)glewGetProcAddress("glMultTransposeMatrixfARB")) == NULL;
  r = r || (glMultTransposeMatrixdARB = (glMultTransposeMatrixdARBPROC)glewGetProcAddress("glMultTransposeMatrixdARB")) == NULL;
  return r;
}
#endif /* GL_ARB_transpose_matrix */

/* --------------------------- ARB_vertex_blend --------------------------- */

#ifdef GL_ARB_vertex_blend
glWeightbvARBPROC glWeightbvARB = NULL;
glWeightsvARBPROC glWeightsvARB = NULL;
glWeightivARBPROC glWeightivARB = NULL;
glWeightfvARBPROC glWeightfvARB = NULL;
glWeightdvARBPROC glWeightdvARB = NULL;
glWeightubvARBPROC glWeightubvARB = NULL;
glWeightusvARBPROC glWeightusvARB = NULL;
glWeightuivARBPROC glWeightuivARB = NULL;
glWeightPointerARBPROC glWeightPointerARB = NULL;
glVertexBlendARBPROC glVertexBlendARB = NULL;

static GLboolean _glewInit_ARB_vertex_blend ()
{
  GLboolean r = GL_FALSE;
  r = r || (glWeightbvARB = (glWeightbvARBPROC)glewGetProcAddress("glWeightbvARB")) == NULL;
  r = r || (glWeightsvARB = (glWeightsvARBPROC)glewGetProcAddress("glWeightsvARB")) == NULL;
  r = r || (glWeightivARB = (glWeightivARBPROC)glewGetProcAddress("glWeightivARB")) == NULL;
  r = r || (glWeightfvARB = (glWeightfvARBPROC)glewGetProcAddress("glWeightfvARB")) == NULL;
  r = r || (glWeightdvARB = (glWeightdvARBPROC)glewGetProcAddress("glWeightdvARB")) == NULL;
  r = r || (glWeightubvARB = (glWeightubvARBPROC)glewGetProcAddress("glWeightubvARB")) == NULL;
  r = r || (glWeightusvARB = (glWeightusvARBPROC)glewGetProcAddress("glWeightusvARB")) == NULL;
  r = r || (glWeightuivARB = (glWeightuivARBPROC)glewGetProcAddress("glWeightuivARB")) == NULL;
  r = r || (glWeightPointerARB = (glWeightPointerARBPROC)glewGetProcAddress("glWeightPointerARB")) == NULL;
  r = r || (glVertexBlendARB = (glVertexBlendARBPROC)glewGetProcAddress("glVertexBlendARB")) == NULL;
  return r;
}
#endif /* GL_ARB_vertex_blend */

/* -------------------------- ARB_vertex_program -------------------------- */

#ifdef GL_ARB_vertex_program
glVertexAttrib1sARBPROC glVertexAttrib1sARB = NULL;
glVertexAttrib1fARBPROC glVertexAttrib1fARB = NULL;
glVertexAttrib1dARBPROC glVertexAttrib1dARB = NULL;
glVertexAttrib2sARBPROC glVertexAttrib2sARB = NULL;
glVertexAttrib2fARBPROC glVertexAttrib2fARB = NULL;
glVertexAttrib2dARBPROC glVertexAttrib2dARB = NULL;
glVertexAttrib3sARBPROC glVertexAttrib3sARB = NULL;
glVertexAttrib3fARBPROC glVertexAttrib3fARB = NULL;
glVertexAttrib3dARBPROC glVertexAttrib3dARB = NULL;
glVertexAttrib4sARBPROC glVertexAttrib4sARB = NULL;
glVertexAttrib4fARBPROC glVertexAttrib4fARB = NULL;
glVertexAttrib4dARBPROC glVertexAttrib4dARB = NULL;
glVertexAttrib4NubARBPROC glVertexAttrib4NubARB = NULL;
glVertexAttrib1svARBPROC glVertexAttrib1svARB = NULL;
glVertexAttrib1fvARBPROC glVertexAttrib1fvARB = NULL;
glVertexAttrib1dvARBPROC glVertexAttrib1dvARB = NULL;
glVertexAttrib2svARBPROC glVertexAttrib2svARB = NULL;
glVertexAttrib2fvARBPROC glVertexAttrib2fvARB = NULL;
glVertexAttrib2dvARBPROC glVertexAttrib2dvARB = NULL;
glVertexAttrib3svARBPROC glVertexAttrib3svARB = NULL;
glVertexAttrib3fvARBPROC glVertexAttrib3fvARB = NULL;
glVertexAttrib3dvARBPROC glVertexAttrib3dvARB = NULL;
glVertexAttrib4bvARBPROC glVertexAttrib4bvARB = NULL;
glVertexAttrib4svARBPROC glVertexAttrib4svARB = NULL;
glVertexAttrib4ivARBPROC glVertexAttrib4ivARB = NULL;
glVertexAttrib4ubvARBPROC glVertexAttrib4ubvARB = NULL;
glVertexAttrib4usvARBPROC glVertexAttrib4usvARB = NULL;
glVertexAttrib4uivARBPROC glVertexAttrib4uivARB = NULL;
glVertexAttrib4fvARBPROC glVertexAttrib4fvARB = NULL;
glVertexAttrib4dvARBPROC glVertexAttrib4dvARB = NULL;
glVertexAttrib4NbvARBPROC glVertexAttrib4NbvARB = NULL;
glVertexAttrib4NsvARBPROC glVertexAttrib4NsvARB = NULL;
glVertexAttrib4NivARBPROC glVertexAttrib4NivARB = NULL;
glVertexAttrib4NubvARBPROC glVertexAttrib4NubvARB = NULL;
glVertexAttrib4NusvARBPROC glVertexAttrib4NusvARB = NULL;
glVertexAttrib4NuivARBPROC glVertexAttrib4NuivARB = NULL;
glVertexAttribPointerARBPROC glVertexAttribPointerARB = NULL;
glEnableVertexAttribArrayARBPROC glEnableVertexAttribArrayARB = NULL;
glDisableVertexAttribArrayARBPROC glDisableVertexAttribArrayARB = NULL;
glProgramStringARBPROC glProgramStringARB = NULL;
glBindProgramARBPROC glBindProgramARB = NULL;
glDeleteProgramsARBPROC glDeleteProgramsARB = NULL;
glGenProgramsARBPROC glGenProgramsARB = NULL;
glProgramEnvParameter4dARBPROC glProgramEnvParameter4dARB = NULL;
glProgramEnvParameter4dvARBPROC glProgramEnvParameter4dvARB = NULL;
glProgramEnvParameter4fARBPROC glProgramEnvParameter4fARB = NULL;
glProgramEnvParameter4fvARBPROC glProgramEnvParameter4fvARB = NULL;
glProgramLocalParameter4dARBPROC glProgramLocalParameter4dARB = NULL;
glProgramLocalParameter4dvARBPROC glProgramLocalParameter4dvARB = NULL;
glProgramLocalParameter4fARBPROC glProgramLocalParameter4fARB = NULL;
glProgramLocalParameter4fvARBPROC glProgramLocalParameter4fvARB = NULL;
glGetProgramEnvParameterdvARBPROC glGetProgramEnvParameterdvARB = NULL;
glGetProgramEnvParameterfvARBPROC glGetProgramEnvParameterfvARB = NULL;
glGetProgramLocalParameterdvARBPROC glGetProgramLocalParameterdvARB = NULL;
glGetProgramLocalParameterfvARBPROC glGetProgramLocalParameterfvARB = NULL;
glGetProgramivARBPROC glGetProgramivARB = NULL;
glGetProgramStringARBPROC glGetProgramStringARB = NULL;
glGetVertexAttribdvARBPROC glGetVertexAttribdvARB = NULL;
glGetVertexAttribfvARBPROC glGetVertexAttribfvARB = NULL;
glGetVertexAttribivARBPROC glGetVertexAttribivARB = NULL;
glGetVertexAttribPointervARBPROC glGetVertexAttribPointervARB = NULL;
glIsProgramARBPROC glIsProgramARB = NULL;

static GLboolean _glewInit_ARB_vertex_program ()
{
  GLboolean r = GL_FALSE;
  r = r || (glVertexAttrib1sARB = (glVertexAttrib1sARBPROC)glewGetProcAddress("glVertexAttrib1sARB")) == NULL;
  r = r || (glVertexAttrib1fARB = (glVertexAttrib1fARBPROC)glewGetProcAddress("glVertexAttrib1fARB")) == NULL;
  r = r || (glVertexAttrib1dARB = (glVertexAttrib1dARBPROC)glewGetProcAddress("glVertexAttrib1dARB")) == NULL;
  r = r || (glVertexAttrib2sARB = (glVertexAttrib2sARBPROC)glewGetProcAddress("glVertexAttrib2sARB")) == NULL;
  r = r || (glVertexAttrib2fARB = (glVertexAttrib2fARBPROC)glewGetProcAddress("glVertexAttrib2fARB")) == NULL;
  r = r || (glVertexAttrib2dARB = (glVertexAttrib2dARBPROC)glewGetProcAddress("glVertexAttrib2dARB")) == NULL;
  r = r || (glVertexAttrib3sARB = (glVertexAttrib3sARBPROC)glewGetProcAddress("glVertexAttrib3sARB")) == NULL;
  r = r || (glVertexAttrib3fARB = (glVertexAttrib3fARBPROC)glewGetProcAddress("glVertexAttrib3fARB")) == NULL;
  r = r || (glVertexAttrib3dARB = (glVertexAttrib3dARBPROC)glewGetProcAddress("glVertexAttrib3dARB")) == NULL;
  r = r || (glVertexAttrib4sARB = (glVertexAttrib4sARBPROC)glewGetProcAddress("glVertexAttrib4sARB")) == NULL;
  r = r || (glVertexAttrib4fARB = (glVertexAttrib4fARBPROC)glewGetProcAddress("glVertexAttrib4fARB")) == NULL;
  r = r || (glVertexAttrib4dARB = (glVertexAttrib4dARBPROC)glewGetProcAddress("glVertexAttrib4dARB")) == NULL;
  r = r || (glVertexAttrib4NubARB = (glVertexAttrib4NubARBPROC)glewGetProcAddress("glVertexAttrib4NubARB")) == NULL;
  r = r || (glVertexAttrib1svARB = (glVertexAttrib1svARBPROC)glewGetProcAddress("glVertexAttrib1svARB")) == NULL;
  r = r || (glVertexAttrib1fvARB = (glVertexAttrib1fvARBPROC)glewGetProcAddress("glVertexAttrib1fvARB")) == NULL;
  r = r || (glVertexAttrib1dvARB = (glVertexAttrib1dvARBPROC)glewGetProcAddress("glVertexAttrib1dvARB")) == NULL;
  r = r || (glVertexAttrib2svARB = (glVertexAttrib2svARBPROC)glewGetProcAddress("glVertexAttrib2svARB")) == NULL;
  r = r || (glVertexAttrib2fvARB = (glVertexAttrib2fvARBPROC)glewGetProcAddress("glVertexAttrib2fvARB")) == NULL;
  r = r || (glVertexAttrib2dvARB = (glVertexAttrib2dvARBPROC)glewGetProcAddress("glVertexAttrib2dvARB")) == NULL;
  r = r || (glVertexAttrib3svARB = (glVertexAttrib3svARBPROC)glewGetProcAddress("glVertexAttrib3svARB")) == NULL;
  r = r || (glVertexAttrib3fvARB = (glVertexAttrib3fvARBPROC)glewGetProcAddress("glVertexAttrib3fvARB")) == NULL;
  r = r || (glVertexAttrib3dvARB = (glVertexAttrib3dvARBPROC)glewGetProcAddress("glVertexAttrib3dvARB")) == NULL;
  r = r || (glVertexAttrib4bvARB = (glVertexAttrib4bvARBPROC)glewGetProcAddress("glVertexAttrib4bvARB")) == NULL;
  r = r || (glVertexAttrib4svARB = (glVertexAttrib4svARBPROC)glewGetProcAddress("glVertexAttrib4svARB")) == NULL;
  r = r || (glVertexAttrib4ivARB = (glVertexAttrib4ivARBPROC)glewGetProcAddress("glVertexAttrib4ivARB")) == NULL;
  r = r || (glVertexAttrib4ubvARB = (glVertexAttrib4ubvARBPROC)glewGetProcAddress("glVertexAttrib4ubvARB")) == NULL;
  r = r || (glVertexAttrib4usvARB = (glVertexAttrib4usvARBPROC)glewGetProcAddress("glVertexAttrib4usvARB")) == NULL;
  r = r || (glVertexAttrib4uivARB = (glVertexAttrib4uivARBPROC)glewGetProcAddress("glVertexAttrib4uivARB")) == NULL;
  r = r || (glVertexAttrib4fvARB = (glVertexAttrib4fvARBPROC)glewGetProcAddress("glVertexAttrib4fvARB")) == NULL;
  r = r || (glVertexAttrib4dvARB = (glVertexAttrib4dvARBPROC)glewGetProcAddress("glVertexAttrib4dvARB")) == NULL;
  r = r || (glVertexAttrib4NbvARB = (glVertexAttrib4NbvARBPROC)glewGetProcAddress("glVertexAttrib4NbvARB")) == NULL;
  r = r || (glVertexAttrib4NsvARB = (glVertexAttrib4NsvARBPROC)glewGetProcAddress("glVertexAttrib4NsvARB")) == NULL;
  r = r || (glVertexAttrib4NivARB = (glVertexAttrib4NivARBPROC)glewGetProcAddress("glVertexAttrib4NivARB")) == NULL;
  r = r || (glVertexAttrib4NubvARB = (glVertexAttrib4NubvARBPROC)glewGetProcAddress("glVertexAttrib4NubvARB")) == NULL;
  r = r || (glVertexAttrib4NusvARB = (glVertexAttrib4NusvARBPROC)glewGetProcAddress("glVertexAttrib4NusvARB")) == NULL;
  r = r || (glVertexAttrib4NuivARB = (glVertexAttrib4NuivARBPROC)glewGetProcAddress("glVertexAttrib4NuivARB")) == NULL;
  r = r || (glVertexAttribPointerARB = (glVertexAttribPointerARBPROC)glewGetProcAddress("glVertexAttribPointerARB")) == NULL;
  r = r || (glEnableVertexAttribArrayARB = (glEnableVertexAttribArrayARBPROC)glewGetProcAddress("glEnableVertexAttribArrayARB")) == NULL;
  r = r || (glDisableVertexAttribArrayARB = (glDisableVertexAttribArrayARBPROC)glewGetProcAddress("glDisableVertexAttribArrayARB")) == NULL;
  r = r || (glProgramStringARB = (glProgramStringARBPROC)glewGetProcAddress("glProgramStringARB")) == NULL;
  r = r || (glBindProgramARB = (glBindProgramARBPROC)glewGetProcAddress("glBindProgramARB")) == NULL;
  r = r || (glDeleteProgramsARB = (glDeleteProgramsARBPROC)glewGetProcAddress("glDeleteProgramsARB")) == NULL;
  r = r || (glGenProgramsARB = (glGenProgramsARBPROC)glewGetProcAddress("glGenProgramsARB")) == NULL;
  r = r || (glProgramEnvParameter4dARB = (glProgramEnvParameter4dARBPROC)glewGetProcAddress("glProgramEnvParameter4dARB")) == NULL;
  r = r || (glProgramEnvParameter4dvARB = (glProgramEnvParameter4dvARBPROC)glewGetProcAddress("glProgramEnvParameter4dvARB")) == NULL;
  r = r || (glProgramEnvParameter4fARB = (glProgramEnvParameter4fARBPROC)glewGetProcAddress("glProgramEnvParameter4fARB")) == NULL;
  r = r || (glProgramEnvParameter4fvARB = (glProgramEnvParameter4fvARBPROC)glewGetProcAddress("glProgramEnvParameter4fvARB")) == NULL;
  r = r || (glProgramLocalParameter4dARB = (glProgramLocalParameter4dARBPROC)glewGetProcAddress("glProgramLocalParameter4dARB")) == NULL;
  r = r || (glProgramLocalParameter4dvARB = (glProgramLocalParameter4dvARBPROC)glewGetProcAddress("glProgramLocalParameter4dvARB")) == NULL;
  r = r || (glProgramLocalParameter4fARB = (glProgramLocalParameter4fARBPROC)glewGetProcAddress("glProgramLocalParameter4fARB")) == NULL;
  r = r || (glProgramLocalParameter4fvARB = (glProgramLocalParameter4fvARBPROC)glewGetProcAddress("glProgramLocalParameter4fvARB")) == NULL;
  r = r || (glGetProgramEnvParameterdvARB = (glGetProgramEnvParameterdvARBPROC)glewGetProcAddress("glGetProgramEnvParameterdvARB")) == NULL;
  r = r || (glGetProgramEnvParameterfvARB = (glGetProgramEnvParameterfvARBPROC)glewGetProcAddress("glGetProgramEnvParameterfvARB")) == NULL;
  r = r || (glGetProgramLocalParameterdvARB = (glGetProgramLocalParameterdvARBPROC)glewGetProcAddress("glGetProgramLocalParameterdvARB")) == NULL;
  r = r || (glGetProgramLocalParameterfvARB = (glGetProgramLocalParameterfvARBPROC)glewGetProcAddress("glGetProgramLocalParameterfvARB")) == NULL;
  r = r || (glGetProgramivARB = (glGetProgramivARBPROC)glewGetProcAddress("glGetProgramivARB")) == NULL;
  r = r || (glGetProgramStringARB = (glGetProgramStringARBPROC)glewGetProcAddress("glGetProgramStringARB")) == NULL;
  r = r || (glGetVertexAttribdvARB = (glGetVertexAttribdvARBPROC)glewGetProcAddress("glGetVertexAttribdvARB")) == NULL;
  r = r || (glGetVertexAttribfvARB = (glGetVertexAttribfvARBPROC)glewGetProcAddress("glGetVertexAttribfvARB")) == NULL;
  r = r || (glGetVertexAttribivARB = (glGetVertexAttribivARBPROC)glewGetProcAddress("glGetVertexAttribivARB")) == NULL;
  r = r || (glGetVertexAttribPointervARB = (glGetVertexAttribPointervARBPROC)glewGetProcAddress("glGetVertexAttribPointervARB")) == NULL;
  r = r || (glIsProgramARB = (glIsProgramARBPROC)glewGetProcAddress("glIsProgramARB")) == NULL;
  return r;
}
#endif /* GL_ARB_vertex_program */

/* ---------------------------- ARB_window_pos ---------------------------- */

#ifdef GL_ARB_window_pos
glWindowPos2dARBPROC glWindowPos2dARB = NULL;
glWindowPos2fARBPROC glWindowPos2fARB = NULL;
glWindowPos2iARBPROC glWindowPos2iARB = NULL;
glWindowPos2sARBPROC glWindowPos2sARB = NULL;
glWindowPos2dvARBPROC glWindowPos2dvARB = NULL;
glWindowPos2fvARBPROC glWindowPos2fvARB = NULL;
glWindowPos2ivARBPROC glWindowPos2ivARB = NULL;
glWindowPos2svARBPROC glWindowPos2svARB = NULL;
glWindowPos3dARBPROC glWindowPos3dARB = NULL;
glWindowPos3fARBPROC glWindowPos3fARB = NULL;
glWindowPos3iARBPROC glWindowPos3iARB = NULL;
glWindowPos3sARBPROC glWindowPos3sARB = NULL;
glWindowPos3dvARBPROC glWindowPos3dvARB = NULL;
glWindowPos3fvARBPROC glWindowPos3fvARB = NULL;
glWindowPos3ivARBPROC glWindowPos3ivARB = NULL;
glWindowPos3svARBPROC glWindowPos3svARB = NULL;

static GLboolean _glewInit_ARB_window_pos ()
{
  GLboolean r = GL_FALSE;
  r = r || (glWindowPos2dARB = (glWindowPos2dARBPROC)glewGetProcAddress("glWindowPos2dARB")) == NULL;
  r = r || (glWindowPos2fARB = (glWindowPos2fARBPROC)glewGetProcAddress("glWindowPos2fARB")) == NULL;
  r = r || (glWindowPos2iARB = (glWindowPos2iARBPROC)glewGetProcAddress("glWindowPos2iARB")) == NULL;
  r = r || (glWindowPos2sARB = (glWindowPos2sARBPROC)glewGetProcAddress("glWindowPos2sARB")) == NULL;
  r = r || (glWindowPos2dvARB = (glWindowPos2dvARBPROC)glewGetProcAddress("glWindowPos2dvARB")) == NULL;
  r = r || (glWindowPos2fvARB = (glWindowPos2fvARBPROC)glewGetProcAddress("glWindowPos2fvARB")) == NULL;
  r = r || (glWindowPos2ivARB = (glWindowPos2ivARBPROC)glewGetProcAddress("glWindowPos2ivARB")) == NULL;
  r = r || (glWindowPos2svARB = (glWindowPos2svARBPROC)glewGetProcAddress("glWindowPos2svARB")) == NULL;
  r = r || (glWindowPos3dARB = (glWindowPos3dARBPROC)glewGetProcAddress("glWindowPos3dARB")) == NULL;
  r = r || (glWindowPos3fARB = (glWindowPos3fARBPROC)glewGetProcAddress("glWindowPos3fARB")) == NULL;
  r = r || (glWindowPos3iARB = (glWindowPos3iARBPROC)glewGetProcAddress("glWindowPos3iARB")) == NULL;
  r = r || (glWindowPos3sARB = (glWindowPos3sARBPROC)glewGetProcAddress("glWindowPos3sARB")) == NULL;
  r = r || (glWindowPos3dvARB = (glWindowPos3dvARBPROC)glewGetProcAddress("glWindowPos3dvARB")) == NULL;
  r = r || (glWindowPos3fvARB = (glWindowPos3fvARBPROC)glewGetProcAddress("glWindowPos3fvARB")) == NULL;
  r = r || (glWindowPos3ivARB = (glWindowPos3ivARBPROC)glewGetProcAddress("glWindowPos3ivARB")) == NULL;
  r = r || (glWindowPos3svARB = (glWindowPos3svARBPROC)glewGetProcAddress("glWindowPos3svARB")) == NULL;
  return r;
}
#endif /* GL_ARB_window_pos */

/* ---------------------------- EXT_blend_color --------------------------- */

#ifdef GL_EXT_blend_color
glBlendColorEXTPROC glBlendColorEXT;

static GLboolean _glewInit_EXT_blend_color ()
{
  GLboolean r = GL_FALSE;
  r = r || (glBlendColorEXT = (glBlendColorEXTPROC)glewGetProcAddress("glBlendColorEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_blend_color */

/* ------------------------ EXT_blend_func_separate ----------------------- */

#ifdef GL_EXT_blend_func_separate
glBlendFuncSeparateEXTPROC glBlendFuncSeparateEXT = NULL;

static GLboolean _glewInit_EXT_blend_func_separate ()
{
  GLboolean r = GL_FALSE;
  r = r || (glBlendFuncSeparateEXT = (glBlendFuncSeparateEXTPROC)glewGetProcAddress("glBlendFuncSeparateEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_blend_func_separate */

/* ---------------------------- EXT_blend_minmax -------------------------- */

#ifdef GL_EXT_blend_minmax
glBlendEquationEXTPROC glBlendEquationEXT;

static GLboolean _glewInit_EXT_blend_minmax ()
{
  GLboolean r = GL_FALSE;
  r = r || (glBlendEquationEXT = (glBlendEquationEXTPROC)glewGetProcAddress("glBlendEquationEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_blend_minmax */

/* ----------------------- EXT_compiled_vertex_array ---------------------- */

#ifdef GL_EXT_compiled_vertex_array
glLockArraysEXTPROC glLockArraysEXT = NULL;
glUnlockArraysEXTPROC glUnlockArraysEXT = NULL;

static GLboolean _glewInit_EXT_compiled_vertex_array ()
{
  GLboolean r = GL_FALSE;
  r = r || (glLockArraysEXT = (glLockArraysEXTPROC)glewGetProcAddress("glLockArraysEXT")) == NULL;
  r = r || (glUnlockArraysEXT = (glUnlockArraysEXTPROC)glewGetProcAddress("glUnlockArraysEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_compiled_vertex_array */

/* ---------------------------- EXT_cull_vertex --------------------------- */

#ifdef GL_EXT_cull_vertex
glCullParameterfvEXTPROC glCullParameterfvEXT = NULL;
glCullParameterdvEXTPROC glCullParameterdvEXT = NULL;

static GLboolean _glewInit_EXT_cull_vertex ()
{
  GLboolean r = GL_FALSE;
  r = r || (glCullParameterfvEXT = (glCullParameterfvEXTPROC)glewGetProcAddress("glCullParameterfvEXT")) == NULL;
  r = r || (glCullParameterdvEXT = (glCullParameterdvEXTPROC)glewGetProcAddress("glCullParameterdvEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_cull_vertex */

/* ------------------------ EXT_draw_range_elements ----------------------- */

#ifdef GL_EXT_draw_range_elements
glDrawRangeElementsEXTPROC glDrawRangeElementsEXT = NULL;

static GLboolean _glewInit_EXT_draw_range_elements ()
{
  GLboolean r = GL_FALSE;
  r = r || (glDrawRangeElementsEXT = (glDrawRangeElementsEXTPROC)glewGetProcAddress("glDrawRangeElementsEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_draw_range_elements */

/* ----------------------------- EXT_fog_coord ---------------------------- */

#ifdef GL_EXT_fog_coord
glFogCoordfEXTPROC glFogCoordfEXT = NULL;
glFogCoordfvEXTPROC glFogCoordfvEXT = NULL;
glFogCoorddEXTPROC glFogCoorddEXT = NULL;
glFogCoorddvEXTPROC glFogCoorddvEXT = NULL;
glFogCoordPointerEXTPROC glFogCoordPointerEXT = NULL;

static GLboolean _glewInit_EXT_fog_coord ()
{
  GLboolean r = GL_FALSE;
  r = r || (glFogCoordfEXT = (glFogCoordfEXTPROC)glewGetProcAddress("glFogCoordfEXT")) == NULL;
  r = r || (glFogCoordfvEXT = (glFogCoordfvEXTPROC)glewGetProcAddress("glFogCoordfvEXT")) == NULL;
  r = r || (glFogCoorddEXT = (glFogCoorddEXTPROC)glewGetProcAddress("glFogCoorddEXT")) == NULL;
  r = r || (glFogCoorddvEXT = (glFogCoorddvEXTPROC)glewGetProcAddress("glFogCoorddvEXT")) == NULL;
  r = r || (glFogCoordPointerEXT = (glFogCoordPointerEXTPROC)glewGetProcAddress("glFogCoordPointerEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_fog_coord */

/* ------------------------- EXT_multi_draw_arrays ------------------------ */

#ifdef GL_EXT_multi_draw_arrays
glMultiDrawArraysEXTPROC glMultiDrawArraysEXT = NULL;
glMultiDrawElementsEXTPROC glMultiDrawElementsEXT = NULL;

static GLboolean _glewInit_EXT_multi_draw_arrays ()
{
  GLboolean r = GL_FALSE;
  r = r || (glMultiDrawArraysEXT = (glMultiDrawArraysEXTPROC) glewGetProcAddress("glMultiDrawArraysEXT")) == NULL;
  r = r || (glMultiDrawElementsEXT = (glMultiDrawElementsEXTPROC) glewGetProcAddress("glMultiDrawElementsEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_multi_draw_arrays */

/* ------------------------- EXT_point_parameters ------------------------- */

#ifdef GL_EXT_point_parameters
glPointParameterfEXTPROC glPointParameterfEXT = NULL;
glPointParameterfvEXTPROC glPointParameterfvEXT = NULL;

static GLboolean _glewInit_EXT_point_parameters ()
{
  GLboolean r = GL_FALSE;
  r = r || (glPointParameterfEXT = (glPointParameterfEXTPROC)glewGetProcAddress("glPointParameterfEXT")) == NULL;
  r = r || (glPointParameterfvEXT = (glPointParameterfvEXTPROC)glewGetProcAddress("glPointParameterfvEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_point_parameters */

/* -------------------------- EXT_secondary_color ------------------------- */

#ifdef GL_EXT_secondary_color
glSecondaryColor3bEXTPROC glSecondaryColor3bEXT = NULL;
glSecondaryColor3bvEXTPROC glSecondaryColor3bvEXT = NULL;
glSecondaryColor3dEXTPROC glSecondaryColor3dEXT = NULL;
glSecondaryColor3dvEXTPROC glSecondaryColor3dvEXT = NULL;
glSecondaryColor3fEXTPROC glSecondaryColor3fEXT = NULL;
glSecondaryColor3fvEXTPROC glSecondaryColor3fvEXT = NULL;
glSecondaryColor3iEXTPROC glSecondaryColor3iEXT = NULL;
glSecondaryColor3ivEXTPROC glSecondaryColor3ivEXT = NULL;
glSecondaryColor3sEXTPROC glSecondaryColor3sEXT = NULL;
glSecondaryColor3svEXTPROC glSecondaryColor3svEXT = NULL;
glSecondaryColor3ubEXTPROC glSecondaryColor3ubEXT = NULL;
glSecondaryColor3ubvEXTPROC glSecondaryColor3ubvEXT = NULL;
glSecondaryColor3uiEXTPROC glSecondaryColor3uiEXT = NULL;
glSecondaryColor3uivEXTPROC glSecondaryColor3uivEXT = NULL;
glSecondaryColor3usEXTPROC glSecondaryColor3usEXT = NULL;
glSecondaryColor3usvEXTPROC glSecondaryColor3usvEXT = NULL;
glSecondaryColorPointerEXTPROC glSecondaryColorPointerEXT = NULL;

static GLboolean _glewInit_EXT_secondary_color ()
{
  GLboolean r = GL_FALSE;
  r = r || (glSecondaryColor3bEXT = (glSecondaryColor3bEXTPROC)glewGetProcAddress("glSecondaryColor3bEXT")) == NULL;
  r = r || (glSecondaryColor3bvEXT = (glSecondaryColor3bvEXTPROC)glewGetProcAddress("glSecondaryColor3bvEXT")) == NULL;
  r = r || (glSecondaryColor3dEXT = (glSecondaryColor3dEXTPROC)glewGetProcAddress("glSecondaryColor3dEXT")) == NULL;
  r = r || (glSecondaryColor3dvEXT = (glSecondaryColor3dvEXTPROC)glewGetProcAddress("glSecondaryColor3dvEXT")) == NULL;
  r = r || (glSecondaryColor3fEXT = (glSecondaryColor3fEXTPROC)glewGetProcAddress("glSecondaryColor3fEXT")) == NULL;
  r = r || (glSecondaryColor3fvEXT = (glSecondaryColor3fvEXTPROC)glewGetProcAddress("glSecondaryColor3fvEXT")) == NULL;
  r = r || (glSecondaryColor3iEXT = (glSecondaryColor3iEXTPROC)glewGetProcAddress("glSecondaryColor3iEXT")) == NULL;
  r = r || (glSecondaryColor3ivEXT = (glSecondaryColor3ivEXTPROC)glewGetProcAddress("glSecondaryColor3ivEXT")) == NULL;
  r = r || (glSecondaryColor3sEXT = (glSecondaryColor3sEXTPROC)glewGetProcAddress("glSecondaryColor3sEXT")) == NULL;
  r = r || (glSecondaryColor3svEXT = (glSecondaryColor3svEXTPROC)glewGetProcAddress("glSecondaryColor3svEXT")) == NULL;
  r = r || (glSecondaryColor3ubEXT = (glSecondaryColor3ubEXTPROC)glewGetProcAddress("glSecondaryColor3ubEXT")) == NULL;
  r = r || (glSecondaryColor3ubvEXT = (glSecondaryColor3ubvEXTPROC)glewGetProcAddress("glSecondaryColor3ubvEXT")) == NULL;
  r = r || (glSecondaryColor3uiEXT = (glSecondaryColor3uiEXTPROC)glewGetProcAddress("glSecondaryColor3uiEXT")) == NULL;
  r = r || (glSecondaryColor3uivEXT = (glSecondaryColor3uivEXTPROC)glewGetProcAddress("glSecondaryColor3uivEXT")) == NULL;
  r = r || (glSecondaryColor3usEXT = (glSecondaryColor3usEXTPROC)glewGetProcAddress("glSecondaryColor3usEXT")) == NULL;
  r = r || (glSecondaryColor3usvEXT = (glSecondaryColor3usvEXTPROC)glewGetProcAddress("glSecondaryColor3usvEXT")) == NULL;
  r = r || (glSecondaryColorPointerEXT = (glSecondaryColorPointerEXTPROC)glewGetProcAddress("glSecondaryColorPointerEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_secondary_color */

/* ------------------------- EXT_stencil_two_side ------------------------- */

#ifdef GL_EXT_stencil_two_side
glActiveStencilFaceEXTPROC glActiveStencilFaceEXT = NULL;

static GLboolean _glewInit_EXT_stencil_two_side ()
{
  GLboolean r = GL_FALSE;
  r = r || (glActiveStencilFaceEXT = (glActiveStencilFaceEXTPROC)glewGetProcAddress("glActiveStencilFaceEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_stencil_two_side */

/* --------------------------- EXT_vertex_shader -------------------------- */

#ifdef GL_EXT_vertex_shader
glBeginVertexShaderEXTPROC glBeginVertexShaderEXT = NULL;
glEndVertexShaderEXTPROC glEndVertexShaderEXT = NULL;
glBindVertexShaderEXTPROC glBindVertexShaderEXT = NULL;
glGenVertexShadersEXTPROC glGenVertexShadersEXT = NULL;
glDeleteVertexShaderEXTPROC glDeleteVertexShaderEXT = NULL;
glShaderOp1EXTPROC glShaderOp1EXT = NULL;
glShaderOp2EXTPROC glShaderOp2EXT = NULL;
glShaderOp3EXTPROC glShaderOp3EXT = NULL;
glSwizzleEXTPROC glSwizzleEXT = NULL;
glWriteMaskEXTPROC glWriteMaskEXT = NULL;
glInsertComponentEXTPROC glInsertComponentEXT = NULL;
glExtractComponentEXTPROC glExtractComponentEXT = NULL;
glGenSymbolsEXTPROC glGenSymbolsEXT = NULL;
glSetInvariantEXTPROC glSetInvariantEXT = NULL;
glSetLocalConstantEXTPROC glSetLocalConstantEXT = NULL;
glVariantbvEXTPROC glVariantbvEXT = NULL;
glVariantsvEXTPROC glVariantsvEXT = NULL;
glVariantivEXTPROC glVariantivEXT = NULL;
glVariantfvEXTPROC glVariantfvEXT = NULL;
glVariantdvEXTPROC glVariantdvEXT = NULL;
glVariantubvEXTPROC glVariantubvEXT = NULL;
glVariantusvEXTPROC glVariantusvEXT = NULL;
glVariantuivEXTPROC glVariantuivEXT = NULL;
glVariantPointerEXTPROC glVariantPointerEXT = NULL;
glEnableVariantClientStateEXTPROC glEnableVariantClientStateEXT = NULL;
glDisableVariantClientStateEXTPROC glDisableVariantClientStateEXT = NULL;
glBindLightParameterEXTPROC glBindLightParameterEXT = NULL;
glBindMaterialParameterEXTPROC glBindMaterialParameterEXT = NULL;
glBindTexGenParameterEXTPROC glBindTexGenParameterEXT = NULL;
glBindTextureUnitParameterEXTPROC glBindTextureUnitParameterEXT = NULL;
glBindParameterEXTPROC glBindParameterEXT = NULL;
glIsVariantEnabledEXTPROC glIsVariantEnabledEXT = NULL;
glGetVariantBooleanvEXTPROC glGetVariantBooleanvEXT = NULL;
glGetVariantIntegervEXTPROC glGetVariantIntegervEXT = NULL;
glGetVariantFloatvEXTPROC glGetVariantFloatvEXT = NULL;
glGetVariantPointervEXTPROC glGetVariantPointervEXT = NULL;
glGetInvariantBooleanvEXTPROC glGetInvariantBooleanvEXT = NULL;
glGetInvariantIntegervEXTPROC glGetInvariantIntegervEXT = NULL;
glGetInvariantFloatvEXTPROC glGetInvariantFloatvEXT = NULL;
glGetLocalConstantBooleanvEXTPROC glGetLocalConstantBooleanvEXT = NULL;
glGetLocalConstantIntegervEXTPROC glGetLocalConstantIntegervEXT = NULL;
glGetLocalConstantFloatvEXTPROC glGetLocalConstantFloatvEXT = NULL;

static GLboolean _glewInit_EXT_vertex_shader ()
{
  GLboolean r = GL_FALSE;
  r = r || (glBeginVertexShaderEXT = (glBeginVertexShaderEXTPROC)glewGetProcAddress("glBeginVertexShaderEXT")) == NULL;
  r = r || (glEndVertexShaderEXT = (glEndVertexShaderEXTPROC)glewGetProcAddress("glEndVertexShaderEXT")) == NULL;
  r = r || (glBindVertexShaderEXT = (glBindVertexShaderEXTPROC)glewGetProcAddress("glBindVertexShaderEXT")) == NULL;
  r = r || (glGenVertexShadersEXT = (glGenVertexShadersEXTPROC)glewGetProcAddress("glGenVertexShadersEXT")) == NULL;
  r = r || (glDeleteVertexShaderEXT = (glDeleteVertexShaderEXTPROC)glewGetProcAddress("glDeleteVertexShaderEXT")) == NULL;
  r = r || (glShaderOp1EXT = (glShaderOp1EXTPROC)glewGetProcAddress("glShaderOp1EXT")) == NULL;
  r = r || (glShaderOp2EXT = (glShaderOp2EXTPROC)glewGetProcAddress("glShaderOp2EXT")) == NULL;
  r = r || (glShaderOp3EXT = (glShaderOp3EXTPROC)glewGetProcAddress("glShaderOp3EXT")) == NULL;
  r = r || (glSwizzleEXT = (glSwizzleEXTPROC)glewGetProcAddress("glSwizzleEXT")) == NULL;
  r = r || (glWriteMaskEXT = (glWriteMaskEXTPROC)glewGetProcAddress("glWriteMaskEXT")) == NULL;
  r = r || (glInsertComponentEXT = (glInsertComponentEXTPROC)glewGetProcAddress("glInsertComponentEXT")) == NULL;
  r = r || (glExtractComponentEXT = (glExtractComponentEXTPROC)glewGetProcAddress("glExtractComponentEXT")) == NULL;
  r = r || (glGenSymbolsEXT = (glGenSymbolsEXTPROC)glewGetProcAddress("glGenSymbolsEXT")) == NULL;
  r = r || (glSetInvariantEXT = (glSetInvariantEXTPROC)glewGetProcAddress("glSetInvariantEXT")) == NULL;
  r = r || (glSetLocalConstantEXT = (glSetLocalConstantEXTPROC)glewGetProcAddress("glSetLocalConstantEXT")) == NULL;
  r = r || (glVariantbvEXT = (glVariantbvEXTPROC)glewGetProcAddress("glVariantbvEXT")) == NULL;
  r = r || (glVariantsvEXT = (glVariantsvEXTPROC)glewGetProcAddress("glVariantsvEXT")) == NULL;
  r = r || (glVariantivEXT = (glVariantivEXTPROC)glewGetProcAddress("glVariantivEXT")) == NULL;
  r = r || (glVariantfvEXT = (glVariantfvEXTPROC)glewGetProcAddress("glVariantfvEXT")) == NULL;
  r = r || (glVariantdvEXT = (glVariantdvEXTPROC)glewGetProcAddress("glVariantdvEXT")) == NULL;
  r = r || (glVariantubvEXT = (glVariantubvEXTPROC)glewGetProcAddress("glVariantubvEXT")) == NULL;
  r = r || (glVariantusvEXT = (glVariantusvEXTPROC)glewGetProcAddress("glVariantusvEXT")) == NULL;
  r = r || (glVariantuivEXT = (glVariantuivEXTPROC)glewGetProcAddress("glVariantuivEXT")) == NULL;
  r = r || (glVariantPointerEXT = (glVariantPointerEXTPROC)glewGetProcAddress("glVariantPointerEXT")) == NULL;
  r = r || (glEnableVariantClientStateEXT = (glEnableVariantClientStateEXTPROC)glewGetProcAddress("glEnableVariantClientStateEXT")) == NULL;
  r = r || (glDisableVariantClientStateEXT = (glDisableVariantClientStateEXTPROC)glewGetProcAddress("glDisableVariantClientStateEXT")) == NULL;
  r = r || (glBindLightParameterEXT = (glBindLightParameterEXTPROC)glewGetProcAddress("glBindLightParameterEXT")) == NULL;
  r = r || (glBindMaterialParameterEXT = (glBindMaterialParameterEXTPROC)glewGetProcAddress("glBindMaterialParameterEXT")) == NULL;
  r = r || (glBindTexGenParameterEXT = (glBindTexGenParameterEXTPROC)glewGetProcAddress("glBindTexGenParameterEXT")) == NULL;
  r = r || (glBindTextureUnitParameterEXT = (glBindTextureUnitParameterEXTPROC)glewGetProcAddress("glBindTextureUnitParameterEXT")) == NULL;
  r = r || (glBindParameterEXT = (glBindParameterEXTPROC)glewGetProcAddress("glBindParameterEXT")) == NULL;
  r = r || (glIsVariantEnabledEXT = (glIsVariantEnabledEXTPROC)glewGetProcAddress("glIsVariantEnabledEXT")) == NULL;
  r = r || (glGetVariantBooleanvEXT = (glGetVariantBooleanvEXTPROC)glewGetProcAddress("glGetVariantBooleanvEXT")) == NULL;
  r = r || (glGetVariantIntegervEXT = (glGetVariantIntegervEXTPROC)glewGetProcAddress("glGetVariantIntegervEXT")) == NULL;
  r = r || (glGetVariantFloatvEXT = (glGetVariantFloatvEXTPROC)glewGetProcAddress("glGetVariantFloatvEXT")) == NULL;
  r = r || (glGetVariantPointervEXT = (glGetVariantPointervEXTPROC)glewGetProcAddress("glGetVariantPointervEXT")) == NULL;
  r = r || (glGetInvariantBooleanvEXT = (glGetInvariantBooleanvEXTPROC)glewGetProcAddress("glGetInvariantBooleanvEXT")) == NULL;
  r = r || (glGetInvariantIntegervEXT = (glGetInvariantIntegervEXTPROC)glewGetProcAddress("glGetInvariantIntegervEXT")) == NULL;
  r = r || (glGetInvariantFloatvEXT = (glGetInvariantFloatvEXTPROC)glewGetProcAddress("glGetInvariantFloatvEXT")) == NULL;
  r = r || (glGetLocalConstantBooleanvEXT = (glGetLocalConstantBooleanvEXTPROC)glewGetProcAddress("glGetLocalConstantBooleanvEXT")) == NULL;
  r = r || (glGetLocalConstantIntegervEXT = (glGetLocalConstantIntegervEXTPROC)glewGetProcAddress("glGetLocalConstantIntegervEXT")) == NULL;
  r = r || (glGetLocalConstantFloatvEXT = (glGetLocalConstantFloatvEXTPROC)glewGetProcAddress("glGetLocalConstantFloatvEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_vertex_shader */

/* ------------------------- EXT_vertex_weighting ------------------------- */

#ifdef GL_EXT_vertex_weighting
glVertexWeightfEXTPROC glVertexWeightfEXT = NULL;
glVertexWeightfvEXTPROC glVertexWeightfvEXT = NULL;
glVertexWeightPointerEXTPROC glVertexWeightPointerEXT = NULL;

static GLboolean _glewInit_EXT_vertex_weighting ()
{
  GLboolean r = GL_FALSE;
  r = r || (glVertexWeightfEXT = (glVertexWeightfEXTPROC)glewGetProcAddress("glVertexWeightfEXT")) == NULL;
  r = r || (glVertexWeightfvEXT = (glVertexWeightfvEXTPROC)glewGetProcAddress("glVertexWeightfvEXT")) == NULL;
  r = r || (glVertexWeightPointerEXT = (glVertexWeightPointerEXTPROC)glewGetProcAddress("glVertexWeightPointerEXT")) == NULL;
  return r;
}
#endif /* GL_EXT_vertex_weighting */

/* --------------------------- KTX_buffer_region -------------------------- */

#ifdef GL_KTX_buffer_region
glBufferRegionEnabledEXTPROC glBufferRegionEnabledEXT = NULL;
glNewBufferRegionEXTPROC glNewBufferRegionEXT = NULL;
glDeleteBufferRegionEXTPROC glDeleteBufferRegionEXT = NULL;
glReadBufferRegionEXTPROC glReadBufferRegionEXT = NULL;
glDrawBufferRegionEXTPROC glDrawBufferRegionEXT = NULL;

static GLboolean _glewInit_KTX_buffer_region ()
{
  GLboolean r = GL_FALSE;
  r = r || (glBufferRegionEnabledEXT = (glBufferRegionEnabledEXTPROC)glewGetProcAddress("glBufferRegionEnabledKTX")) == NULL;
  r = r || (glNewBufferRegionEXT = (glNewBufferRegionEXTPROC)glewGetProcAddress("glNewBufferRegionKTX")) == NULL;
  r = r || (glDeleteBufferRegionEXT = (glDeleteBufferRegionEXTPROC)glewGetProcAddress("glDeleteBufferRegionKTX")) == NULL;
  r = r || (glReadBufferRegionEXT = (glReadBufferRegionEXTPROC)glewGetProcAddress("glReadBufferRegionKTX")) == NULL;
  r = r || (glDrawBufferRegionEXT = (glDrawBufferRegionEXTPROC)glewGetProcAddress("glDrawBufferRegionKTX")) == NULL;
  return r;
}
#endif /* GL_KTX_buffer_region */

/* ------------------------------ WIN_swap_hint --------------------------- */

#ifdef GL_WIN_swap_hint
glAddSwapHintRectWinPROC glAddSwapHintRectWin = NULL;

static GLboolean _glewInit_WIN_swap_hint ()
{
  GLboolean r = GL_FALSE;
  r = r || (glAddSwapHintRectWin = (glAddSwapHintRectWinPROC)glewGetProcAddress("glAddSwapHintRectWIN")) == NULL;
  return r;
}
#endif /* GL_WIN_swap_hint */

/* ---------------------------- ATI_draw_buffers -------------------------- */

#ifdef GL_ATI_draw_buffers
glDrawBuffersPROC glDrawBuffers = NULL;

static GLboolean _glewInit_ATI_draw_buffers ()
{
  GLboolean r = GL_FALSE;
  r = r || (glDrawBuffers = (glDrawBuffersPROC)glewGetProcAddress("glDrawBuffers")) == NULL;
  return r;
}
#endif /* GL_ATI_draw_buffers */

/* --------------------------- ATI_element_array -------------------------- */

#ifdef GL_ATI_element_array
glElementPointerATIPROC glElementPointerATI = NULL;
glDrawElementArrayATIPROC glDrawElementArrayATI = NULL;
glDrawRangeElementArrayATIPROC glDrawRangeElementArrayATI = NULL;

static GLboolean _glewInit_ATI_element_array ()
{
  GLboolean r = GL_FALSE;
  r = r || (glElementPointerATI = (glElementPointerATIPROC)glewGetProcAddress("glElementPointerATI")) == NULL;
  r = r || (glDrawElementArrayATI = (glDrawElementArrayATIPROC)glewGetProcAddress("glDrawElementArrayATI")) == NULL;
  r = r || (glDrawRangeElementArrayATI = (glDrawRangeElementArrayATIPROC)glewGetProcAddress("glDrawRangeElementArrayATI")) == NULL;
  return r;
}
#endif /* GL_ATI_element_array */

/* -------------------------- ATI_envmap_bumpmap -------------------------- */

#ifdef GL_ATI_envmap_bumpmap
glTexBumpParameterivATIPROC glTexBumpParameterivATI = NULL;
glTexBumpParameterfvATIPROC glTexBumpParameterfvATI = NULL;
glGetTexBumpParameterivATIPROC glGetTexBumpParameterivATI = NULL;
glGetTexBumpParameterfvATIPROC glGetTexBumpParameterfvATI = NULL;

static GLboolean _glewInit_ATI_envmap_bumpmap ()
{
  GLboolean r = GL_FALSE;
  r = r || (glTexBumpParameterivATI = (glTexBumpParameterivATIPROC)glewGetProcAddress("glTexBumpParameterivATI")) == NULL;
  r = r || (glTexBumpParameterfvATI = (glTexBumpParameterfvATIPROC)glewGetProcAddress("glTexBumpParameterfvATI")) == NULL;
  r = r || (glGetTexBumpParameterivATI = (glGetTexBumpParameterivATIPROC)glewGetProcAddress("glGetTexBumpParameterivATI")) == NULL;
  r = r || (glGetTexBumpParameterfvATI = (glGetTexBumpParameterfvATIPROC)glewGetProcAddress("glGetTexBumpParameterfvATI")) == NULL;
  return r;
}
#endif /* GL_ATI_envmap_bumpmap */

/* ------------------------- ATI_fragment_shader ------------------------- */

#ifdef GL_ATI_fragment_shader
glGenFragmentShadersATIPROC glGenFragmentShadersATI = NULL;
glBindFragmentShaderATIPROC glBindFragmentShaderATI = NULL;
glDeleteFragmentShaderATIPROC glDeleteFragmentShaderATI = NULL;
glBeginFragmentShaderATIPROC glBeginFragmentShaderATI = NULL;
glEndFragmentShaderATIPROC glEndFragmentShaderATI = NULL;
glPassTexCoordATIPROC glPassTexCoordATI = NULL;
glSampleMapATIPROC glSampleMapATI = NULL;
glColorFragmentOp1ATIPROC glColorFragmentOp1ATI = NULL;
glColorFragmentOp2ATIPROC glColorFragmentOp2ATI = NULL;
glColorFragmentOp3ATIPROC glColorFragmentOp3ATI = NULL;
glAlphaFragmentOp1ATIPROC glAlphaFragmentOp1ATI = NULL;
glAlphaFragmentOp2ATIPROC glAlphaFragmentOp2ATI = NULL;
glAlphaFragmentOp3ATIPROC glAlphaFragmentOp3ATI = NULL;
glSetFragmentShaderConstantATIPROC glSetFragmentShaderConstantATI = NULL;

static GLboolean _glewInit_ATI_fragment_shader ()
{
  GLboolean r = GL_FALSE;
  r = r || (glGenFragmentShadersATI = (glGenFragmentShadersATIPROC)glewGetProcAddress("glGenFragmentShadersATI")) == NULL;
  r = r || (glBindFragmentShaderATI = (glBindFragmentShaderATIPROC)glewGetProcAddress("glBindFragmentShaderATI")) == NULL;
  r = r || (glDeleteFragmentShaderATI = (glDeleteFragmentShaderATIPROC)glewGetProcAddress("glDeleteFragmentShaderATI")) == NULL;
  r = r || (glBeginFragmentShaderATI = (glBeginFragmentShaderATIPROC)glewGetProcAddress("glBeginFragmentShaderATI")) == NULL;
  r = r || (glEndFragmentShaderATI = (glEndFragmentShaderATIPROC)glewGetProcAddress("glEndFragmentShaderATI")) == NULL;
  r = r || (glPassTexCoordATI = (glPassTexCoordATIPROC)glewGetProcAddress("glPassTexCoordATI")) == NULL;
  r = r || (glSampleMapATI = (glSampleMapATIPROC)glewGetProcAddress("glSampleMapATI")) == NULL;
  r = r || (glColorFragmentOp1ATI = (glColorFragmentOp1ATIPROC)glewGetProcAddress("glColorFragmentOp1ATI")) == NULL;
  r = r || (glColorFragmentOp2ATI = (glColorFragmentOp2ATIPROC)glewGetProcAddress("glColorFragmentOp2ATI")) == NULL;
  r = r || (glColorFragmentOp3ATI = (glColorFragmentOp3ATIPROC)glewGetProcAddress("glColorFragmentOp3ATI")) == NULL;
  r = r || (glAlphaFragmentOp1ATI = (glAlphaFragmentOp1ATIPROC)glewGetProcAddress("glAlphaFragmentOp1ATI")) == NULL;
  r = r || (glAlphaFragmentOp2ATI = (glAlphaFragmentOp2ATIPROC)glewGetProcAddress("glAlphaFragmentOp2ATI")) == NULL;
  r = r || (glAlphaFragmentOp3ATI = (glAlphaFragmentOp3ATIPROC)glewGetProcAddress("glAlphaFragmentOp3ATI")) == NULL;
  r = r || (glSetFragmentShaderConstantATI = (glSetFragmentShaderConstantATIPROC)glewGetProcAddress("glSetFragmentShaderConstantATI")) == NULL;
  return r;
}
#endif /* GL_ATI_fragment_shader */

/* ------------------------- ATI_map_object_buffer ------------------------ */

#ifdef GL_ATI_map_object_buffer
glMapObjectBufferATIPROC glMapObjectBufferATI = NULL;
glUnmapObjectBufferATIPROC glUnmapObjectBufferATI = NULL;

static GLboolean _glewInit_ATI_map_object_buffer ()
{
  GLboolean r = GL_FALSE;
  r = r || (glMapObjectBufferATI = (glMapObjectBufferATIPROC)glewGetProcAddress("glMapObjectBufferATI")) == NULL;
  r = r || (glUnmapObjectBufferATI = (glUnmapObjectBufferATIPROC)glewGetProcAddress("glUnmapObjectBufferATI")) == NULL;
  return r;
}
#endif /* GL_ATI_map_object_buffer */

/* --------------------------- ATI_mapped_texture ------------------------- */

#ifdef GL_ATI_mapped_texture
glMapTexture3DPROC glMapTexture3D;
glUnmapTexture3DPROC glUnmapTexture3D;

static GLboolean _glewInit_ATI_mapped_texture ()
{
  GLboolean r = GL_FALSE;
  r = r || (glMapTexture3D = (glMapTexture3DPROC)glewGetProcAddress("glMapTexture3D")) == NULL;
  r = r || (glUnmapTexture3D = (glUnmapTexture3DPROC)glewGetProcAddress("glUnmapTexture3D")) == NULL;
  return r;
}
#endif /* GL_ATI_mapped_texture */

/* --------------------------- ATI_pn_triangles --------------------------- */

#ifdef GL_ATI_pn_triangles
glPNTrianglesiATIPROC glPNTrianglesiATI = NULL;
glPNTrianglesfATIPROC glPNTrianglesfATI = NULL;

static GLboolean _glewInit_ATI_pn_triangles ()
{
  GLboolean r = GL_FALSE;
  r = r || (glPNTrianglesiATI = (glPNTrianglesiATIPROC)glewGetProcAddress("glPNTrianglesiATI")) == NULL;
  r = r || (glPNTrianglesfATI = (glPNTrianglesfATIPROC)glewGetProcAddress("glPNTrianglesfATI")) == NULL;
  return r;
}
#endif /* GL_ATI_pn_triangles */

/* -------------------------- ATI_separate_stencil ------------------------ */

#ifdef GL_ATI_separate_stencil
glStencilOpSeparateATIPROC glStencilOpSeparateATI = NULL;
glStencilFuncSeparateATIPROC glStencilFuncSeparateATI = NULL;

static GLboolean _glewInit_ATI_separate_stencil ()
{
  GLboolean r = GL_FALSE;
  r = r || (glStencilOpSeparateATI = (glStencilOpSeparateATIPROC)glewGetProcAddress("glStencilOpSeparateATI")) == NULL;
  r = r || (glStencilFuncSeparateATI = (glStencilFuncSeparateATIPROC)glewGetProcAddress("glStencilFuncSeparateATI")) == NULL;
  return r;
}
#endif /* GL_ATI_separate_stencil */

/* ----------------------------- ATI_timestamp ---------------------------- */

#ifdef GL_ATI_timestamp
glNewTimeStampPROC glNewTimeStamp = NULL;
glDeleteTimeStampPROC glDeleteTimeStamp = NULL;
glSendTimeStampPROC glSendTimeStamp = NULL;
glWaitTimeStampPROC glWaitTimeStamp = NULL;

static GLboolean _glewInit_ATI_timestamp ()
{
  GLboolean r = GL_FALSE;
  r = r || (glNewTimeStamp = (glNewTimeStampPROC) glewGetProcAddress("glNewTimeStamp")) == NULL;
  r = r || (glDeleteTimeStamp = (glDeleteTimeStampPROC)glewGetProcAddress("glDeleteTimeStamp")) == NULL;
  r = r || (glSendTimeStamp = (glSendTimeStampPROC)glewGetProcAddress("glSendTimeStamp")) == NULL;
  r = r || (glWaitTimeStamp = (glWaitTimeStampPROC)glewGetProcAddress("glWaitTimeStamp")) == NULL;
  return r;
}
#endif /* GL_ATI_timestamp */

/* ------------------------ ATI_vertex_array_object ----------------------- */

#ifdef GL_ATI_vertex_array_object
glNewObjectBufferATIPROC glNewObjectBufferATI = NULL;
glIsObjectBufferATIPROC glIsObjectBufferATI = NULL;
glUpdateObjectBufferATIPROC glUpdateObjectBufferATI = NULL;
glGetObjectBufferfvATIPROC glGetObjectBufferfvATI = NULL;
glGetObjectBufferivATIPROC glGetObjectBufferivATI = NULL;
glFreeObjectBufferATIPROC glFreeObjectBufferATI = NULL;
glArrayObjectATIPROC glArrayObjectATI = NULL;
glGetArrayObjectfvATIPROC glGetArrayObjectfvATI = NULL;
glGetArrayObjectivATIPROC glGetArrayObjectivATI = NULL;
glVariantArrayObjectATIPROC glVariantArrayObjectATI = NULL;
glGetVariantArrayObjectfvATIPROC glGetVariantArrayObjectfvATI = NULL;
glGetVariantArrayObjectivATIPROC glGetVariantArrayObjectivATI = NULL;

static GLboolean _glewInit_ATI_vertex_array_object ()
{
  GLboolean r = GL_FALSE;
  r = r || (glNewObjectBufferATI = (glNewObjectBufferATIPROC)glewGetProcAddress("glNewObjectBufferATI")) == NULL;
  r = r || (glIsObjectBufferATI = (glIsObjectBufferATIPROC)glewGetProcAddress("glIsObjectBufferATI")) == NULL;
  r = r || (glUpdateObjectBufferATI = (glUpdateObjectBufferATIPROC)glewGetProcAddress("glUpdateObjectBufferATI")) == NULL;
  r = r || (glGetObjectBufferfvATI = (glGetObjectBufferfvATIPROC)glewGetProcAddress("glGetObjectBufferfvATI")) == NULL;
  r = r || (glGetObjectBufferivATI = (glGetObjectBufferivATIPROC)glewGetProcAddress("glGetObjectBufferivATI")) == NULL;
  r = r || (glFreeObjectBufferATI = (glFreeObjectBufferATIPROC)glewGetProcAddress("glFreeObjectBufferATI")) == NULL;
  r = r || (glArrayObjectATI = (glArrayObjectATIPROC)glewGetProcAddress("glArrayObjectATI")) == NULL;
  r = r || (glGetArrayObjectfvATI = (glGetArrayObjectfvATIPROC)glewGetProcAddress("glGetArrayObjectfvATI")) == NULL;
  r = r || (glGetArrayObjectivATI = (glGetArrayObjectivATIPROC)glewGetProcAddress("glGetArrayObjectivATI")) == NULL;
  r = r || (glVariantArrayObjectATI = (glVariantArrayObjectATIPROC)glewGetProcAddress("glVariantArrayObjectATI")) == NULL;
  r = r || (glGetVariantArrayObjectfvATI = (glGetVariantArrayObjectfvATIPROC)glewGetProcAddress("glGetVariantArrayObjectfvATI")) == NULL;
  r = r || (glGetVariantArrayObjectivATI = (glGetVariantArrayObjectivATIPROC)glewGetProcAddress("glGetVariantArrayObjectivATI")) == NULL;
  return r;
}
#endif /* GL_ATI_vertex_array_object */

/* -------------------- ATI_vertex_attrib_array_object -------------------- */

#ifdef GL_ATI_vertex_attrib_array_object
glVertexAttribArratObjectATIPROC glVertexAttribArratObjectATI = NULL;
glGetVertexAttribArratObjectfvATIPROC glGetVertexAttribArratObjectfvATI = NULL;
glGetVertexAttrubAttatObjectivATIPROC glGetVertexAttrubAttatObjectivATI = NULL;

static GLboolean _glewInit_ATI_vertex_attrib_array_object ()
{
  GLboolean r = GL_FALSE;
  r = r || (glVertexAttribArratObjectATI = (glVertexAttribArratObjectATIPROC) glewGetProcAddress("glVertexAttribArratObjectATI")) == NULL;
  r = r || (glGetVertexAttribArratObjectfvATI = (glGetVertexAttribArratObjectfvATIPROC) glewGetProcAddress("glGetVertexAttribArratObjectfvATI")) == NULL;
  r = r || (glGetVertexAttrubAttatObjectivATI = (glGetVertexAttrubAttatObjectivATIPROC) glewGetProcAddress("glGetVertexAttrubAttatObjectivATI")) == NULL;
  return r;
}
#endif /* GL_ATI_vertex_attrib_array_object */

/* -------------------------- ATI_vertex_streams -------------------------- */

#ifdef GL_ATI_vertex_streams 
glClientActiveVertexStreamATIPROC glClientActiveVertexStreamATI = NULL;
glVertexBlendEnviATIPROC glVertexBlendEnviATI = NULL;
glVertexBlendEnvfATIPROC glVertexBlendEnvfATI = NULL;
glVertexStream2sATIPROC glVertexStream2sATI = NULL;
glVertexStream2svATIPROC glVertexStream2svATI = NULL;
glVertexStream2iATIPROC glVertexStream2iATI = NULL;
glVertexStream2ivATIPROC glVertexStream2ivATI = NULL;
glVertexStream2fATIPROC glVertexStream2fATI = NULL;
glVertexStream2fvATIPROC glVertexStream2fvATI = NULL;
glVertexStream2dATIPROC glVertexStream2dATI = NULL;
glVertexStream2dvATIPROC glVertexStream2dvATI = NULL;
glVertexStream3sATIPROC glVertexStream3sATI = NULL;
glVertexStream3svATIPROC glVertexStream3svATI = NULL;
glVertexStream3iATIPROC glVertexStream3iATI = NULL;
glVertexStream3ivATIPROC glVertexStream3ivATI = NULL;
glVertexStream3fATIPROC glVertexStream3fATI = NULL;
glVertexStream3fvATIPROC glVertexStream3fvATI = NULL;
glVertexStream3dATIPROC glVertexStream3dATI = NULL;
glVertexStream3dvATIPROC glVertexStream3dvATI = NULL;
glVertexStream4sATIPROC glVertexStream4sATI = NULL;
glVertexStream4svATIPROC glVertexStream4svATI = NULL;
glVertexStream4iATIPROC glVertexStream4iATI = NULL;
glVertexStream4ivATIPROC glVertexStream4ivATI = NULL;
glVertexStream4fATIPROC glVertexStream4fATI = NULL;
glVertexStream4fvATIPROC glVertexStream4fvATI = NULL;
glVertexStream4dATIPROC glVertexStream4dATI = NULL;
glVertexStream4dvATIPROC glVertexStream4dvATI = NULL;
glNormalStream3bATIPROC glNormalStream3bATI = NULL;
glNormalStream3bvATIPROC glNormalStream3bvATI = NULL;
glNormalStream3sATIPROC glNormalStream3sATI = NULL;
glNormalStream3svATIPROC glNormalStream3svATI = NULL;
glNormalStream3iATIPROC glNormalStream3iATI = NULL;
glNormalStream3ivATIPROC glNormalStream3ivATI = NULL;
glNormalStream3fATIPROC glNormalStream3fATI = NULL;
glNormalStream3fvATIPROC glNormalStream3fvATI = NULL;
glNormalStream3dATIPROC glNormalStream3dATI = NULL;
glNormalStream3dvATIPROC glNormalStream3dvATI = NULL;

static GLboolean _glewInit_ATI_vertex_streams ()
{
  GLboolean r = GL_FALSE;
  glClientActiveVertexStreamATI = (glClientActiveVertexStreamATIPROC)glewGetProcAddress("glClientActiveVertexStreamATI");
  r = r || (glVertexBlendEnviATI = (glVertexBlendEnviATIPROC)glewGetProcAddress("glVertexBlendEnviATI")) == NULL;
  r = r || (glVertexBlendEnvfATI = (glVertexBlendEnvfATIPROC)glewGetProcAddress("glVertexBlendEnvfATI")) == NULL;
  r = r || (glVertexStream2sATI = (glVertexStream2sATIPROC)glewGetProcAddress("glVertexStream2sATI")) == NULL;
  r = r || (glVertexStream2svATI = (glVertexStream2svATIPROC)glewGetProcAddress("glVertexStream2svATI")) == NULL;
  r = r || (glVertexStream2iATI = (glVertexStream2iATIPROC)glewGetProcAddress("glVertexStream2iATI")) == NULL;
  r = r || (glVertexStream2ivATI = (glVertexStream2ivATIPROC)glewGetProcAddress("glVertexStream2ivATI")) == NULL;
  r = r || (glVertexStream2fATI = (glVertexStream2fATIPROC)glewGetProcAddress("glVertexStream2fATI")) == NULL;
  r = r || (glVertexStream2fvATI = (glVertexStream2fvATIPROC)glewGetProcAddress("glVertexStream2fvATI")) == NULL;
  r = r || (glVertexStream2dATI = (glVertexStream2dATIPROC)glewGetProcAddress("glVertexStream2dATI")) == NULL;
  r = r || (glVertexStream2dvATI = (glVertexStream2dvATIPROC)glewGetProcAddress("glVertexStream2dvATI")) == NULL;
  r = r || (glVertexStream3sATI = (glVertexStream3sATIPROC)glewGetProcAddress("glVertexStream3sATI")) == NULL;
  r = r || (glVertexStream3svATI = (glVertexStream3svATIPROC)glewGetProcAddress("glVertexStream3svATI")) == NULL;
  r = r || (glVertexStream3iATI = (glVertexStream3iATIPROC)glewGetProcAddress("glVertexStream3iATI")) == NULL;
  r = r || (glVertexStream3ivATI = (glVertexStream3ivATIPROC)glewGetProcAddress("glVertexStream3ivATI")) == NULL;
  r = r || (glVertexStream3fATI = (glVertexStream3fATIPROC)glewGetProcAddress("glVertexStream3fATI")) == NULL;
  r = r || (glVertexStream3fvATI = (glVertexStream3fvATIPROC)glewGetProcAddress("glVertexStream3fvATI")) == NULL;
  r = r || (glVertexStream3dATI = (glVertexStream3dATIPROC)glewGetProcAddress("glVertexStream3dATI")) == NULL;
  r = r || (glVertexStream3dvATI = (glVertexStream3dvATIPROC)glewGetProcAddress("glVertexStream3dvATI")) == NULL;
  r = r || (glVertexStream4sATI = (glVertexStream4sATIPROC)glewGetProcAddress("glVertexStream4sATI")) == NULL;
  r = r || (glVertexStream4svATI = (glVertexStream4svATIPROC)glewGetProcAddress("glVertexStream4svATI")) == NULL;
  r = r || (glVertexStream4iATI = (glVertexStream4iATIPROC)glewGetProcAddress("glVertexStream4iATI")) == NULL;
  r = r || (glVertexStream4ivATI = (glVertexStream4ivATIPROC)glewGetProcAddress("glVertexStream4ivATI")) == NULL;
  r = r || (glVertexStream4fATI = (glVertexStream4fATIPROC)glewGetProcAddress("glVertexStream4fATI")) == NULL;
  r = r || (glVertexStream4fvATI = (glVertexStream4fvATIPROC)glewGetProcAddress("glVertexStream4fvATI")) == NULL;
  r = r || (glVertexStream4dATI = (glVertexStream4dATIPROC)glewGetProcAddress("glVertexStream4dATI")) == NULL;
  r = r || (glVertexStream4dvATI = (glVertexStream4dvATIPROC)glewGetProcAddress("glVertexStream4dvATI")) == NULL;
  r = r || (glNormalStream3bATI = (glNormalStream3bATIPROC)glewGetProcAddress("glNormalStream3bATI")) == NULL;
  r = r || (glNormalStream3bvATI = (glNormalStream3bvATIPROC)glewGetProcAddress("glNormalStream3bvATI")) == NULL;
  r = r || (glNormalStream3sATI = (glNormalStream3sATIPROC)glewGetProcAddress("glNormalStream3sATI")) == NULL;
  r = r || (glNormalStream3svATI = (glNormalStream3svATIPROC)glewGetProcAddress("glNormalStream3svATI")) == NULL;
  r = r || (glNormalStream3iATI = (glNormalStream3iATIPROC)glewGetProcAddress("glNormalStream3iATI")) == NULL;
  r = r || (glNormalStream3ivATI = (glNormalStream3ivATIPROC)glewGetProcAddress("glNormalStream3ivATI")) == NULL;
  r = r || (glNormalStream3fATI = (glNormalStream3fATIPROC)glewGetProcAddress("glNormalStream3fATI")) == NULL;
  r = r || (glNormalStream3fvATI = (glNormalStream3fvATIPROC)glewGetProcAddress("glNormalStream3fvATI")) == NULL;
  r = r || (glNormalStream3dATI = (glNormalStream3dATIPROC)glewGetProcAddress("glNormalStream3dATI")) == NULL;
  r = r || (glNormalStream3dvATI = (glNormalStream3dvATIPROC)glewGetProcAddress("glNormalStream3dvATI")) == NULL;
  return r;
}
#endif /* GL_ATI_vertex_streams */

/* --------------------------- NV_element_array --------------------------- */

#ifdef GL_NV_element_array
glElementPointerNVPROC glElementPointerNV = NULL;
glDrawElementArrayNVPROC glDrawElementArrayNV = NULL;
glDrawRangeElementArrayNVPROC glDrawRangeElementArrayNV = NULL;
glMultiDrawElementArrayNVPROC glMultiDrawElementArrayNV = NULL;
glMultiDrawRangeElementArrayNVPROC glMultiDrawRangeElementArrayNV = NULL;

static GLboolean _glewInit_NV_element_array ()
{
  GLboolean r = GL_FALSE;
  r = r || (glElementPointerNV = (glElementPointerNVPROC)glewGetProcAddress("glElementPointerNV")) == NULL;
  r = r || (glDrawElementArrayNV = (glDrawElementArrayNVPROC)glewGetProcAddress("glDrawElementArrayNV")) == NULL;
  r = r || (glDrawRangeElementArrayNV = (glDrawRangeElementArrayNVPROC)glewGetProcAddress("glDrawRangeElementArrayNV")) == NULL;
  r = r || (glMultiDrawElementArrayNV = (glMultiDrawElementArrayNVPROC)glewGetProcAddress("glMultiDrawElementArrayNV")) == NULL;
  r = r || (glMultiDrawRangeElementArrayNV = (glMultiDrawRangeElementArrayNVPROC)glewGetProcAddress("glMultiDrawRangeElementArrayNV")) == NULL;
  return r;
}
#endif /* GL_NV_element_array */

/* ----------------------------- NV_evaluators ---------------------------- */

#ifdef GL_NV_evaluators
glMapControlPointsNVPROC glMapControlPointsNV = NULL;
glMapParameterivNVPROC glMapParameterivNV = NULL;
glMapParameterfvNVPROC glMapParameterfvNV = NULL;
glGetMapControlPointsNVPROC glGetMapControlPointsNV = NULL;
glGetMapParameterivNVPROC glGetMapParameterivNV = NULL;
glGetMapParameterfvNVPROC glGetMapParameterfvNV = NULL;
glGetMapAttribParameterivNVPROC glGetMapAttribParameterivNV = NULL;
glGetMapAttribParameterfvNVPROC glGetMapAttribParameterfvNV = NULL;
glEvalMapsNVPROC glEvalMapsNV = NULL;

static GLboolean _glewInit_NV_evaluators ()
{
  GLboolean r = GL_FALSE;
  r = r || (glMapControlPointsNV = (glMapControlPointsNVPROC)glewGetProcAddress("glMapControlPointsNV")) == NULL;
  r = r || (glMapParameterivNV = (glMapParameterivNVPROC)glewGetProcAddress("glMapParameterivNV")) == NULL;
  r = r || (glMapParameterfvNV = (glMapParameterfvNVPROC)glewGetProcAddress("glMapParameterfvNV")) == NULL;
  r = r || (glGetMapControlPointsNV = (glGetMapControlPointsNVPROC)glewGetProcAddress("glGetMapControlPointsNV")) == NULL;
  r = r || (glGetMapParameterivNV = (glGetMapParameterivNVPROC)glewGetProcAddress("glGetMapParameterivNV")) == NULL;
  r = r || (glGetMapParameterfvNV = (glGetMapParameterfvNVPROC)glewGetProcAddress("glGetMapParameterfvNV")) == NULL;
  r = r || (glGetMapAttribParameterivNV = (glGetMapAttribParameterivNVPROC)glewGetProcAddress("glGetMapAttribParameterivNV")) == NULL;
  r = r || (glGetMapAttribParameterfvNV = (glGetMapAttribParameterfvNVPROC)glewGetProcAddress("glGetMapAttribParameterfvNV")) == NULL;
  r = r || (glEvalMapsNV = (glEvalMapsNVPROC)glewGetProcAddress("glEvalMapsNV")) == NULL;
  return r;
}
#endif /* GL_NV_evaluators */

/* -------------------------- NV_fragment_program ------------------------- */

#ifdef GL_NV_fragment_program
glProgramNamedParameter4fNVPROC glProgramNamedParameter4fNV = NULL;
glProgramNamedParameter4dNVPROC glProgramNamedParameter4dNV = NULL;
glProgramNamedParameter4fvNVPROC glProgramNamedParameter4fvNV = NULL;
glProgramNamedParameter4dvNVPROC glProgramNamedParameter4dvNV = NULL;
glGetProgramNamedParameterfvNVPROC glGetProgramNamedParameterfvNV = NULL;
glGetProgramNamedParameterdvNVPROC glGetProgramNamedParameterdvNV = NULL;
#ifndef GL_ARB_vertex_program
glProgramLocalParameter4dARBPROC glProgramLocalParameter4dARB = NULL;
glProgramLocalParameter4dvARBPROC glProgramLocalParameter4dvARB = NULL;
glProgramLocalParameter4fARBPROC glProgramLocalParameter4fARB = NULL;
glProgramLocalParameter4fvARBPROC glProgramLocalParameter4fvARB = NULL;
glGetProgramLocalParameterdvARBPROC glGetProgramLocalParameterdvARB = NULL;
glGetProgramLocalParameterfvARBPROC glGetProgramLocalParameterfvARB = NULL;
#endif /* GL_ARB_vertex_program */

static GLboolean _glewInit_NV_fragment_program ()
{
  GLboolean r = GL_FALSE;
  r = r || (glProgramNamedParameter4fNV = (glProgramNamedParameter4fNVPROC)glewGetProcAddress("glProgramNamedParameter4fNV")) == NULL;
  r = r || (glProgramNamedParameter4dNV = (glProgramNamedParameter4dNVPROC)glewGetProcAddress("glProgramNamedParameter4dNV")) == NULL;
  r = r || (glProgramNamedParameter4fvNV = (glProgramNamedParameter4fvNVPROC)glewGetProcAddress("glProgramNamedParameter4fvNV")) == NULL;
  r = r || (glProgramNamedParameter4dvNV = (glProgramNamedParameter4dvNVPROC)glewGetProcAddress("glProgramNamedParameter4dvNV")) == NULL;
  r = r || (glGetProgramNamedParameterfvNV = (glGetProgramNamedParameterfvNVPROC)glewGetProcAddress("glGetProgramNamedParameterfvNV")) == NULL;
  r = r || (glGetProgramNamedParameterdvNV = (glGetProgramNamedParameterdvNVPROC)glewGetProcAddress("glGetProgramNamedParameterdvNV")) == NULL;
#ifndef GL_ARB_vertex_program
  r = r || (glProgramLocalParameter4dARB = (glProgramLocalParameter4dARBPROC)glewGetProcAddress("glProgramLocalParameter4dARB")) == NULL;
  r = r || (glProgramLocalParameter4dvARB = (glProgramLocalParameter4dvARBPROC)glewGetProcAddress("glProgramLocalParameter4dvARB")) == NULL;
  r = r || (glProgramLocalParameter4fARB = (glProgramLocalParameter4fARBPROC)glewGetProcAddress("glProgramLocalParameter4fARB")) == NULL;
  r = r || (glProgramLocalParameter4fvARB = (glProgramLocalParameter4fvARBPROC)glewGetProcAddress("glProgramLocalParameter4fvARB")) == NULL;
  r = r || (glGetProgramLocalParameterdvARB = (glGetProgramLocalParameterdvARBPROC)glewGetProcAddress("glGetProgramLocalParameterdvARB")) == NULL;
  r = r || (glGetProgramLocalParameterfvARB = (glGetProgramLocalParameterfvARBPROC)glewGetProcAddress("glGetProgramLocalParameterfvARB")) == NULL;
#endif /* GL_ARB_vertex_program */
  return r;
}
#endif /* GL_NV_fragment_program */

/* ------------------------------- NV_fence ------------------------------- */

#ifdef GL_NV_fence
glGenFencesNVPROC glGenFencesNV = NULL;
glDeleteFencesNVPROC glDeleteFencesNV = NULL;
glSetFenceNVPROC glSetFenceNV = NULL;
glTestFenceNVPROC glTestFenceNV = NULL;
glFinishFenceNVPROC glFinishFenceNV = NULL;
glIsFenceNVPROC glIsFenceNV = NULL;
glGetFenceivNVPROC glGetFenceivNV = NULL;

static GLboolean _glewInit_NV_fence ()
{
  GLboolean r = GL_FALSE;
  r = r || (glGenFencesNV = (glGenFencesNVPROC)glewGetProcAddress("glGenFencesNV")) == NULL;
  r = r || (glDeleteFencesNV = (glDeleteFencesNVPROC)glewGetProcAddress("glDeleteFencesNV")) == NULL;
  r = r || (glSetFenceNV = (glSetFenceNVPROC)glewGetProcAddress("glSetFenceNV")) == NULL;
  r = r || (glTestFenceNV = (glTestFenceNVPROC)glewGetProcAddress("glTestFenceNV")) == NULL;
  r = r || (glFinishFenceNV = (glFinishFenceNVPROC)glewGetProcAddress("glFinishFenceNV")) == NULL;
  r = r || (glIsFenceNV = (glIsFenceNVPROC)glewGetProcAddress("glIsFenceNV")) == NULL;
  r = r || (glGetFenceivNV = (glGetFenceivNVPROC)glewGetProcAddress("glGetFenceivNV")) == NULL;
  return r;
}
#endif /* GL_NV_fence */

/* -------------------------- NV_occlusion_query -------------------------- */

#ifdef GL_NV_occlusion_query
glGenOcclusionQueriesNVPROC glGenOcclusionQueriesNV = NULL;
glDeleteOcclusionQueriesNVPROC glDeleteOcclusionQueriesNV = NULL;
glIsOcclusionQueryNVPROC glIsOcclusionQueryNV = NULL;
glBeginOcclusionQueryNVPROC glBeginOcclusionQueryNV = NULL;
glEndOcclusionQueryNVPROC glEndOcclusionQueryNV = NULL;
glGetOcclusionQueryivNVPROC glGetOcclusionQueryivNV = NULL;
glGetOcclusionQueryuivNVPROC glGetOcclusionQueryuivNV = NULL;

static GLboolean _glewInit_NV_occlusion_query ()
{
  GLboolean r = GL_FALSE;
  r = r || (glGenOcclusionQueriesNV = (glGenOcclusionQueriesNVPROC)glewGetProcAddress("glGenOcclusionQueriesNV")) == NULL;
  r = r || (glDeleteOcclusionQueriesNV = (glDeleteOcclusionQueriesNVPROC)glewGetProcAddress("glDeleteOcclusionQueriesNV")) == NULL;
  r = r || (glIsOcclusionQueryNV = (glIsOcclusionQueryNVPROC)glewGetProcAddress("glIsOcclusionQueryNV")) == NULL;
  r = r || (glBeginOcclusionQueryNV = (glBeginOcclusionQueryNVPROC)glewGetProcAddress("glBeginOcclusionQueryNV")) == NULL;
  r = r || (glEndOcclusionQueryNV = (glEndOcclusionQueryNVPROC)glewGetProcAddress("glEndOcclusionQueryNV")) == NULL;
  r = r || (glGetOcclusionQueryivNV = (glGetOcclusionQueryivNVPROC)glewGetProcAddress("glGetOcclusionQueryivNV")) == NULL;
  r = r || (glGetOcclusionQueryuivNV = (glGetOcclusionQueryuivNVPROC)glewGetProcAddress("glGetOcclusionQueryuivNV")) == NULL;
  return r;
}
#endif /* GL_NV_occlusion_query */

/* -------------------------- NV_pixel_data_range ------------------------- */

#ifdef GL_NV_pixel_data_range
glPixelDataRangeNVPROC glPixelDataRangeNV = NULL;
glFlushPixelDataRangeNVPROC glFlushPixelDataRangeNV = NULL;

static GLboolean _glewInit_NV_pixel_data_range ()
{
  GLboolean r = GL_FALSE;
  r = r || (glPixelDataRangeNV = (glPixelDataRangeNVPROC)glewGetProcAddress("glPixelDataRangeNV")) == NULL;
  r = r || (glFlushPixelDataRangeNV = (glFlushPixelDataRangeNVPROC)glewGetProcAddress("glFlushPixelDataRangeNV")) == NULL;
  return r;
}
#endif /* GL_NV_pixel_data_range */

/* ---------------------------- NV_point_sprite --------------------------- */

#ifdef GL_NV_point_sprite
glPointParameteriNVPROC glPointParameteriNV = NULL;
glPointParameterivNVPROC glPointParameterivNV = NULL;

static GLboolean _glewInit_NV_point_sprite ()
{
  GLboolean r = GL_FALSE;
  r = r || (glPointParameteriNV = (glPointParameteriNVPROC)glewGetProcAddress("glPointParameteriNV")) == NULL;
  r = r || (glPointParameterivNV = (glPointParameterivNVPROC)glewGetProcAddress("glPointParameterivNV")) == NULL;
  return r;
}
#endif /* GL_NV_point_sprite */

/* ------------------------- NV_primitive_restart ------------------------- */

#ifdef GL_NV_primitive_restart
glPrimitiveRestartNVPROC glPrimitiveRestartNV = NULL;
glPrimitiveRestartIndexNVPROC glPrimitiveRestartIndexNV = NULL;

static GLboolean _glewInit_NV_primitive_restart ()
{
  GLboolean r = GL_FALSE;
  r = r || (glPrimitiveRestartNV = (glPrimitiveRestartNVPROC)glewGetProcAddress("glPrimitiveRestartNV")) == NULL;
  r = r || (glPrimitiveRestartIndexNV = (glPrimitiveRestartIndexNVPROC)glewGetProcAddress("glPrimitiveRestartIndexNV")) == NULL;
  return r;
}
#endif /* GL_NV_primitive_restart */

/* ------------------------- NV_register_combiners ------------------------ */

#ifdef GL_NV_register_combiners
glCombinerParameterfvNVPROC glCombinerParameterfvNV = NULL;
glCombinerParameterfNVPROC  glCombinerParameterfNV = NULL;
glCombinerParameterivNVPROC glCombinerParameterivNV = NULL;
glCombinerParameteriNVPROC glCombinerParameteriNV = NULL;
glCombinerInputNVPROC glCombinerInputNV = NULL;
glCombinerOutputNVPROC glCombinerOutputNV = NULL;
glFinalCombinerInputNVPROC glFinalCombinerInputNV = NULL;
glGetCombinerInputParameterfvNVPROC glGetCombinerInputParameterfvNV = NULL;
glGetCombinerInputParameterivNVPROC glGetCombinerInputParameterivNV = NULL;
glGetCombinerOutputParameterfvNVPROC glGetCombinerOutputParameterfvNV = NULL;
glGetCombinerOutputParameterivNVPROC glGetCombinerOutputParameterivNV = NULL;
glGetFinalCombinerInputParameterfvNVPROC glGetFinalCombinerInputParameterfvNV = NULL;
glGetFinalCombinerInputParameterivNVPROC glGetFinalCombinerInputParameterivNV = NULL;

static GLboolean _glewInit_NV_register_combiners ()
{
  GLboolean r = GL_FALSE;
  r = r || (glCombinerParameterfvNV = (glCombinerParameterfvNVPROC)glewGetProcAddress("glCombinerParameterfvNV")) == NULL;
  r = r || (glCombinerParameterfNV = (glCombinerParameterfNVPROC)glewGetProcAddress("glCombinerParameterfNV")) == NULL;
  r = r || (glCombinerParameterivNV = (glCombinerParameterivNVPROC)glewGetProcAddress("glCombinerParameterivNV")) == NULL;
  r = r || (glCombinerParameteriNV = (glCombinerParameteriNVPROC)glewGetProcAddress("glCombinerParameteriNV")) == NULL;
  r = r || (glCombinerInputNV = (glCombinerInputNVPROC)glewGetProcAddress("glCombinerInputNV")) == NULL;
  r = r || (glCombinerOutputNV = (glCombinerOutputNVPROC)glewGetProcAddress("glCombinerOutputNV")) == NULL;
  r = r || (glFinalCombinerInputNV = (glFinalCombinerInputNVPROC)glewGetProcAddress("glFinalCombinerInputNV")) == NULL;
  r = r || (glGetCombinerInputParameterfvNV = (glGetCombinerInputParameterfvNVPROC)glewGetProcAddress("glGetCombinerInputParameterfvNV")) == NULL;
  r = r || (glGetCombinerInputParameterivNV = (glGetCombinerInputParameterivNVPROC)glewGetProcAddress("glGetCombinerInputParameterivNV")) == NULL;
  r = r || (glGetCombinerOutputParameterfvNV = (glGetCombinerOutputParameterfvNVPROC)glewGetProcAddress("glGetCombinerOutputParameterfvNV")) == NULL;
  r = r || (glGetCombinerOutputParameterivNV = (glGetCombinerOutputParameterivNVPROC)glewGetProcAddress("glGetCombinerOutputParameterivNV")) == NULL;
  r = r || (glGetFinalCombinerInputParameterfvNV = (glGetFinalCombinerInputParameterfvNVPROC)glewGetProcAddress("glGetFinalCombinerInputParameterfvNV")) == NULL;
  r = r || (glGetFinalCombinerInputParameterivNV = (glGetFinalCombinerInputParameterivNVPROC)glewGetProcAddress("glGetFinalCombinerInputParameterivNV")) == NULL;
  return r;
}
#endif /* GL_NV_register_combiners */

/* ------------------------ NV_register_combiners2 ------------------------ */

#ifdef GL_NV_register_combiners2
glCombinerStageParameterfvNVPROC glCombinerStageParameterfvNV = NULL;
glGetCombinerStageParameterfvNVPROC glGetCombinerStageParameterfvNV = NULL;

static GLboolean _glewInit_NV_register_combiners2 ()
{
  GLboolean r = GL_FALSE;
  r = r || (glCombinerStageParameterfvNV = (glCombinerStageParameterfvNVPROC)glewGetProcAddress("glCombinerStageParameterfvNV")) == NULL;
  r = r || (glGetCombinerStageParameterfvNV = (glGetCombinerStageParameterfvNVPROC)glewGetProcAddress("glGetCombinerStageParameterfvNV")) == NULL;
  return r;
}
#endif /* GL_NV_register_combiners2 */

/* ------------------------- NV_vertex_array_range ------------------------ */

#ifdef GL_NV_vertex_array_range
glFlushVertexArrayRangeNVPROC glFlushVertexArrayRangeNV = NULL;
glVertexArrayRangeNVPROC glVertexArrayRangeNV = NULL;

static GLboolean _glewInit_NV_vertex_array_range ()
{
  GLboolean r = GL_FALSE;
  r = r || (glFlushVertexArrayRangeNV = (glFlushVertexArrayRangeNVPROC)glewGetProcAddress("glFlushVertexArrayRangeNV")) == NULL;
  r = r || (glVertexArrayRangeNV = (glVertexArrayRangeNVPROC)glewGetProcAddress("glVertexArrayRangeNV")) == NULL;
  return r;
}
#endif /* GL_NV_vertex_array_range */

/* --------------------------- NV_vertex_program -------------------------- */

#ifdef GL_NV_vertex_program
glBindProgramNVPROC glBindProgramNV = NULL;
glDeleteProgramsNVPROC glDeleteProgramsNV = NULL;
glExecuteProgramNVPROC glExecuteProgramNV = NULL;
glGenProgramsNVPROC glGenProgramsNV = NULL;
glAreProgramsResidentNVPROC glAreProgramsResidentNV = NULL;
glRequestResidentProgramsNVPROC glRequestResidentProgramsNV = NULL;
glGetProgramParameterfvNVPROC glGetProgramParameterfvNV = NULL;
glGetProgramParameterdvNVPROC glGetProgramParameterdvNV = NULL;
glGetProgramivNVPROC glGetProgramivNV = NULL;
glGetProgramStringNVPROC glGetProgramStringNV = NULL;
glGetTrackMatrixivNVPROC glGetTrackMatrixivNV = NULL;
glGetVertexAttribdvNVPROC glGetVertexAttribdvNV = NULL;
glGetVertexAttribfvNVPROC glGetVertexAttribfvNV = NULL;
glGetVertexAttribivNVPROC glGetVertexAttribivNV = NULL;
glGetVertexAttribPointervNVPROC glGetVertexAttribPointervNV = NULL;
glIsProgramNVPROC glIsProgramNV = NULL;
glLoadProgramNVPROC glLoadProgramNV = NULL;
glProgramParameter4fNVPROC glProgramParameter4fNV = NULL;
glProgramParameter4dNVPROC glProgramParameter4dNV = NULL;
glProgramParameter4dvNVPROC glProgramParameter4dvNV = NULL;
glProgramParameter4fvNVPROC glProgramParameter4fvNV = NULL;
glProgramParameters4dvNVPROC glProgramParameters4dvNV = NULL;
glProgramParameters4fvNVPROC glProgramParameters4fvNV = NULL;
glTrackMatrixNVPROC glTrackMatrixNV = NULL;
glVertexAttribPointerNVPROC glVertexAttribPointerNV = NULL;
glVertexAttrib1sNVPROC glVertexAttrib1sNV = NULL;
glVertexAttrib1fNVPROC glVertexAttrib1fNV = NULL;
glVertexAttrib1dNVPROC glVertexAttrib1dNV = NULL;
glVertexAttrib2sNVPROC glVertexAttrib2sNV = NULL;
glVertexAttrib2fNVPROC glVertexAttrib2fNV = NULL;
glVertexAttrib2dNVPROC glVertexAttrib2dNV = NULL;
glVertexAttrib3sNVPROC glVertexAttrib3sNV = NULL;
glVertexAttrib3fNVPROC glVertexAttrib3fNV = NULL;
glVertexAttrib3dNVPROC glVertexAttrib3dNV = NULL;
glVertexAttrib4sNVPROC glVertexAttrib4sNV = NULL;
glVertexAttrib4fNVPROC glVertexAttrib4fNV = NULL;
glVertexAttrib4dNVPROC glVertexAttrib4dNV = NULL;
glVertexAttrib4ubNVPROC glVertexAttrib4ubNV = NULL;
glVertexAttrib1svNVPROC glVertexAttrib1svNV = NULL;
glVertexAttrib1fvNVPROC glVertexAttrib1fvNV = NULL;
glVertexAttrib1dvNVPROC glVertexAttrib1dvNV = NULL;
glVertexAttrib2svNVPROC glVertexAttrib2svNV = NULL;
glVertexAttrib2fvNVPROC glVertexAttrib2fvNV = NULL;
glVertexAttrib2dvNVPROC glVertexAttrib2dvNV = NULL;
glVertexAttrib3svNVPROC glVertexAttrib3svNV = NULL;
glVertexAttrib3fvNVPROC glVertexAttrib3fvNV = NULL;
glVertexAttrib3dvNVPROC glVertexAttrib3dvNV = NULL;
glVertexAttrib4svNVPROC glVertexAttrib4svNV = NULL;
glVertexAttrib4fvNVPROC glVertexAttrib4fvNV = NULL;
glVertexAttrib4dvNVPROC glVertexAttrib4dvNV = NULL;
glVertexAttrib4ubvNVPROC glVertexAttrib4ubvNV = NULL;
glVertexAttribs1svNVPROC glVertexAttribs1svNV = NULL;
glVertexAttribs1fvNVPROC glVertexAttribs1fvNV = NULL;
glVertexAttribs1dvNVPROC glVertexAttribs1dvNV = NULL;
glVertexAttribs2svNVPROC glVertexAttribs2svNV = NULL;
glVertexAttribs2fvNVPROC glVertexAttribs2fvNV = NULL;
glVertexAttribs2dvNVPROC glVertexAttribs2dvNV = NULL;
glVertexAttribs3svNVPROC glVertexAttribs3svNV = NULL;
glVertexAttribs3fvNVPROC glVertexAttribs3fvNV = NULL;
glVertexAttribs3dvNVPROC glVertexAttribs3dvNV = NULL;
glVertexAttribs4svNVPROC glVertexAttribs4svNV = NULL;
glVertexAttribs4fvNVPROC glVertexAttribs4fvNV = NULL;
glVertexAttribs4dvNVPROC glVertexAttribs4dvNV = NULL;
glVertexAttribs4ubvNVPROC glVertexAttribs4ubvNV = NULL;

static GLboolean _glewInit_NV_vertex_program ()
{
  GLboolean r = GL_FALSE;
  r = r || (glBindProgramNV = (glBindProgramNVPROC)glewGetProcAddress("glBindProgramNV")) == NULL;
  r = r || (glDeleteProgramsNV = (glDeleteProgramsNVPROC)glewGetProcAddress("glDeleteProgramsNV")) == NULL;
  r = r || (glExecuteProgramNV = (glExecuteProgramNVPROC)glewGetProcAddress("glExecuteProgramNV")) == NULL;
  r = r || (glGenProgramsNV = (glGenProgramsNVPROC)glewGetProcAddress("glGenProgramsNV")) == NULL;
  r = r || (glAreProgramsResidentNV = (glAreProgramsResidentNVPROC)glewGetProcAddress("glAreProgramsResidentNV")) == NULL;
  r = r || (glRequestResidentProgramsNV = (glRequestResidentProgramsNVPROC)glewGetProcAddress("glRequestResidentProgramsNV")) == NULL;
  r = r || (glGetProgramParameterfvNV = (glGetProgramParameterfvNVPROC)glewGetProcAddress("glGetProgramParameterfvNV")) == NULL;
  r = r || (glGetProgramParameterdvNV = (glGetProgramParameterdvNVPROC)glewGetProcAddress("glGetProgramParameterdvNV")) == NULL;
  r = r || (glGetProgramivNV = (glGetProgramivNVPROC)glewGetProcAddress("glGetProgramivNV")) == NULL;
  r = r || (glGetProgramStringNV = (glGetProgramStringNVPROC)glewGetProcAddress("glGetProgramStringNV")) == NULL;
  r = r || (glGetTrackMatrixivNV = (glGetTrackMatrixivNVPROC)glewGetProcAddress("glGetTrackMatrixivNV")) == NULL;
  r = r || (glGetVertexAttribdvNV = (glGetVertexAttribdvNVPROC)glewGetProcAddress("glGetVertexAttribdvNV")) == NULL;
  r = r || (glGetVertexAttribfvNV = (glGetVertexAttribfvNVPROC)glewGetProcAddress("glGetVertexAttribfvNV")) == NULL;
  r = r || (glGetVertexAttribivNV = (glGetVertexAttribivNVPROC)glewGetProcAddress("glGetVertexAttribivNV")) == NULL;
  r = r || (glGetVertexAttribPointervNV = (glGetVertexAttribPointervNVPROC)glewGetProcAddress("glGetVertexAttribPointervNV")) == NULL;
  r = r || (glIsProgramNV = (glIsProgramNVPROC)glewGetProcAddress("glIsProgramNV")) == NULL;
  r = r || (glLoadProgramNV = (glLoadProgramNVPROC)glewGetProcAddress("glLoadProgramNV")) == NULL;
  r = r || (glProgramParameter4fNV = (glProgramParameter4fNVPROC)glewGetProcAddress("glProgramParameter4fNV")) == NULL;
  r = r || (glProgramParameter4dNV = (glProgramParameter4dNVPROC)glewGetProcAddress("glProgramParameter4dNV")) == NULL;
  r = r || (glProgramParameter4dvNV = (glProgramParameter4dvNVPROC)glewGetProcAddress("glProgramParameter4dvNV")) == NULL;
  r = r || (glProgramParameter4fvNV = (glProgramParameter4fvNVPROC)glewGetProcAddress("glProgramParameter4fvNV")) == NULL;
  r = r || (glProgramParameters4dvNV = (glProgramParameters4dvNVPROC)glewGetProcAddress("glProgramParameters4dvNV")) == NULL;
  r = r || (glProgramParameters4fvNV = (glProgramParameters4fvNVPROC)glewGetProcAddress("glProgramParameters4fvNV")) == NULL;
  r = r || (glTrackMatrixNV = (glTrackMatrixNVPROC)glewGetProcAddress("glTrackMatrixNV")) == NULL;
  r = r || (glVertexAttribPointerNV = (glVertexAttribPointerNVPROC)glewGetProcAddress("glVertexAttribPointerNV")) == NULL;
  r = r || (glVertexAttrib1sNV = (glVertexAttrib1sNVPROC)glewGetProcAddress("glVertexAttrib1sNV")) == NULL;
  r = r || (glVertexAttrib1fNV = (glVertexAttrib1fNVPROC)glewGetProcAddress("glVertexAttrib1fNV")) == NULL;
  r = r || (glVertexAttrib1dNV = (glVertexAttrib1dNVPROC)glewGetProcAddress("glVertexAttrib1dNV")) == NULL;
  r = r || (glVertexAttrib2sNV = (glVertexAttrib2sNVPROC)glewGetProcAddress("glVertexAttrib2sNV")) == NULL;
  r = r || (glVertexAttrib2fNV = (glVertexAttrib2fNVPROC)glewGetProcAddress("glVertexAttrib2fNV")) == NULL;
  r = r || (glVertexAttrib2dNV = (glVertexAttrib2dNVPROC)glewGetProcAddress("glVertexAttrib2dNV")) == NULL;
  r = r || (glVertexAttrib3sNV = (glVertexAttrib3sNVPROC)glewGetProcAddress("glVertexAttrib3sNV")) == NULL;
  r = r || (glVertexAttrib3fNV = (glVertexAttrib3fNVPROC)glewGetProcAddress("glVertexAttrib3fNV")) == NULL;
  r = r || (glVertexAttrib3dNV = (glVertexAttrib3dNVPROC)glewGetProcAddress("glVertexAttrib3dNV")) == NULL;
  r = r || (glVertexAttrib4sNV = (glVertexAttrib4sNVPROC)glewGetProcAddress("glVertexAttrib4sNV")) == NULL;
  r = r || (glVertexAttrib4fNV = (glVertexAttrib4fNVPROC)glewGetProcAddress("glVertexAttrib4fNV")) == NULL;
  r = r || (glVertexAttrib4dNV = (glVertexAttrib4dNVPROC)glewGetProcAddress("glVertexAttrib4dNV")) == NULL;
  r = r || (glVertexAttrib4ubNV = (glVertexAttrib4ubNVPROC)glewGetProcAddress("glVertexAttrib4ubNV")) == NULL;
  r = r || (glVertexAttrib1svNV = (glVertexAttrib1svNVPROC)glewGetProcAddress("glVertexAttrib1svNV")) == NULL;
  r = r || (glVertexAttrib1fvNV = (glVertexAttrib1fvNVPROC)glewGetProcAddress("glVertexAttrib1fvNV")) == NULL;
  r = r || (glVertexAttrib1dvNV = (glVertexAttrib1dvNVPROC)glewGetProcAddress("glVertexAttrib1dvNV")) == NULL;
  r = r || (glVertexAttrib2svNV = (glVertexAttrib2svNVPROC)glewGetProcAddress("glVertexAttrib2svNV")) == NULL;
  r = r || (glVertexAttrib2fvNV = (glVertexAttrib2fvNVPROC)glewGetProcAddress("glVertexAttrib2fvNV")) == NULL;
  r = r || (glVertexAttrib2dvNV = (glVertexAttrib2dvNVPROC)glewGetProcAddress("glVertexAttrib2dvNV")) == NULL;
  r = r || (glVertexAttrib3svNV = (glVertexAttrib3svNVPROC)glewGetProcAddress("glVertexAttrib3svNV")) == NULL;
  r = r || (glVertexAttrib3fvNV = (glVertexAttrib3fvNVPROC)glewGetProcAddress("glVertexAttrib3fvNV")) == NULL;
  r = r || (glVertexAttrib3dvNV = (glVertexAttrib3dvNVPROC)glewGetProcAddress("glVertexAttrib3dvNV")) == NULL;
  r = r || (glVertexAttrib4svNV = (glVertexAttrib4svNVPROC)glewGetProcAddress("glVertexAttrib4svNV")) == NULL;
  r = r || (glVertexAttrib4fvNV = (glVertexAttrib4fvNVPROC)glewGetProcAddress("glVertexAttrib4fvNV")) == NULL;
  r = r || (glVertexAttrib4dvNV = (glVertexAttrib4dvNVPROC)glewGetProcAddress("glVertexAttrib4dvNV")) == NULL;
  r = r || (glVertexAttrib4ubvNV = (glVertexAttrib4ubvNVPROC)glewGetProcAddress("glVertexAttrib4ubvNV")) == NULL;
  r = r || (glVertexAttribs1svNV = (glVertexAttribs1svNVPROC)glewGetProcAddress("glVertexAttribs1svNV")) == NULL;
  r = r || (glVertexAttribs1fvNV = (glVertexAttribs1fvNVPROC)glewGetProcAddress("glVertexAttribs1fvNV")) == NULL;
  r = r || (glVertexAttribs1dvNV = (glVertexAttribs1dvNVPROC)glewGetProcAddress("glVertexAttribs1dvNV")) == NULL;
  r = r || (glVertexAttribs2svNV = (glVertexAttribs2svNVPROC)glewGetProcAddress("glVertexAttribs2svNV")) == NULL;
  r = r || (glVertexAttribs2fvNV = (glVertexAttribs2fvNVPROC)glewGetProcAddress("glVertexAttribs2fvNV")) == NULL;
  r = r || (glVertexAttribs2dvNV = (glVertexAttribs2dvNVPROC)glewGetProcAddress("glVertexAttribs2dvNV")) == NULL;
  r = r || (glVertexAttribs3svNV = (glVertexAttribs3svNVPROC)glewGetProcAddress("glVertexAttribs3svNV")) == NULL;
  r = r || (glVertexAttribs3fvNV = (glVertexAttribs3fvNVPROC)glewGetProcAddress("glVertexAttribs3fvNV")) == NULL;
  r = r || (glVertexAttribs3dvNV = (glVertexAttribs3dvNVPROC)glewGetProcAddress("glVertexAttribs3dvNV")) == NULL;
  r = r || (glVertexAttribs4svNV = (glVertexAttribs4svNVPROC)glewGetProcAddress("glVertexAttribs4svNV")) == NULL;
  r = r || (glVertexAttribs4fvNV = (glVertexAttribs4fvNVPROC)glewGetProcAddress("glVertexAttribs4fvNV")) == NULL;
  r = r || (glVertexAttribs4dvNV = (glVertexAttribs4dvNVPROC)glewGetProcAddress("glVertexAttribs4dvNV")) == NULL;
  r = r || (glVertexAttribs4ubvNV = (glVertexAttribs4ubvNVPROC)glewGetProcAddress("glVertexAttribs4ubvNV")) == NULL;
  return r;
}
#endif /* GL_NV_vertex_program */

#ifdef _WIN32

/* ---------------------------- ARB_buffer_region ------------------------- */

#ifdef WGL_ARB_buffer_region
wglCreateBufferRegionARBPROC wglCreateBufferRegionARB = NULL;
wglDeleteBufferRegionARBPROC wglDeleteBufferRegionARB = NULL;
wglSaveBufferRegionARBPROC wglSaveBufferRegionARB = NULL;
wglRestoreBufferRegionARBPROC wglRestoreBufferRegionARB = NULL;

static GLboolean _wglewInit_ARB_buffer_region ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglCreateBufferRegionARB = (wglCreateBufferRegionARBPROC)glewGetProcAddress("wglCreateBufferRegionARB")) == NULL;
  r = r || (wglDeleteBufferRegionARB = (wglDeleteBufferRegionARBPROC)glewGetProcAddress("wglDeleteBufferRegionARB")) == NULL;
  r = r || (wglSaveBufferRegionARB = (wglSaveBufferRegionARBPROC)glewGetProcAddress("wglSaveBufferRegionARB")) == NULL;
  r = r || (wglRestoreBufferRegionARB = (wglRestoreBufferRegionARBPROC)glewGetProcAddress("wglRestoreBufferRegionARB")) == NULL;
  return r;
}
#endif /* WGL_ARB_buffer_region */

/* -------------------------- ARB_extensions_string ----------------------- */

#ifdef WGL_ARB_extensions_string
wglGetExtensionsStringARBPROC wglGetExtensionsStringARB = NULL;

static GLboolean _wglewInit_ARB_extensions_string ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglGetExtensionsStringARB = (wglGetExtensionsStringARBPROC)glewGetProcAddress("wglGetExtensionsStringARB")) == NULL;
  return r;
}
#endif /* WGL_ARB_extensions_string */

/* -------------------------- ARB_make_current_read ----------------------- */

#ifdef WGL_ARB_make_current_read
wglMakeContextCurrentARBPROC wglMakeContextCurrentARB = NULL;
wglGetCurrentReadDCARBPROC wglGetCurrentReadDCARB = NULL;

static GLboolean _wglewInit_ARB_make_current_read ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglMakeContextCurrentARB = (wglMakeContextCurrentARBPROC)glewGetProcAddress("wglMakeContextCurrentARB")) == NULL;
  r = r || (wglGetCurrentReadDCARB = (wglGetCurrentReadDCARBPROC)glewGetProcAddress("wglGetCurrentReadDCARB")) == NULL;
  return r;
}
#endif /* WGL_ARB_make_current_read */

/* ------------------------------ ARB_pbuffer ----------------------------- */

#ifdef WGL_ARB_pbuffer
wglCreatePbufferARBPROC wglCreatePbufferARB = NULL;
wglGetPbufferDCARBPROC wglGetPbufferDCARB = NULL;
wglReleasePbufferDCARBPROC wglReleasePbufferDCARB = NULL;
wglDestroyPbufferARBPROC wglDestroyPbufferARB = NULL;
wglQueryPbufferARBPROC wglQueryPbufferARB = NULL;

static GLboolean _wglewInit_ARB_pbuffer ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglCreatePbufferARB = (wglCreatePbufferARBPROC)glewGetProcAddress("wglCreatePbufferARB")) == NULL;
  r = r || (wglGetPbufferDCARB = (wglGetPbufferDCARBPROC)glewGetProcAddress("wglGetPbufferDCARB")) == NULL;
  r = r || (wglReleasePbufferDCARB = (wglReleasePbufferDCARBPROC)glewGetProcAddress("wglReleasePbufferDCARB")) == NULL;
  r = r || (wglDestroyPbufferARB = (wglDestroyPbufferARBPROC)glewGetProcAddress("wglDestroyPbufferARB")) == NULL;
  r = r || (wglQueryPbufferARB = (wglQueryPbufferARBPROC)glewGetProcAddress("wglQueryPbufferARB")) == NULL;
  return r;
}
#endif /* WGL_ARB_pbuffer */

/* --------------------------- ARB_pixel_format --------------------------- */

#ifdef WGL_ARB_pixel_format
wglGetPixelFormatAttribivARBPROC wglGetPixelFormatAttribivARB = NULL;
wglGetPixelFormatAttribfvARBPROC wglGetPixelFormatAttribfvARB = NULL;
wglChoosePixelFormatARBPROC wglChoosePixelFormatARB = NULL;

static GLboolean _wglewInit_ARB_pixel_format ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglGetPixelFormatAttribivARB = (wglGetPixelFormatAttribivARBPROC)glewGetProcAddress("wglGetPixelFormatAttribivARB")) == NULL;
  r = r || (wglGetPixelFormatAttribfvARB = (wglGetPixelFormatAttribfvARBPROC)glewGetProcAddress("wglGetPixelFormatAttribfvARB")) == NULL;
  r = r || (wglChoosePixelFormatARB = (wglChoosePixelFormatARBPROC)glewGetProcAddress("wglChoosePixelFormatARB")) == NULL;
  return r;
}
#endif /* WGL_ARB_pixel_format */

/* -------------------------- ARB_render_texture -------------------------- */

#ifdef WGL_ARB_render_texture
wglBindTexImageARBPROC wglBindTexImageARB = NULL;
wglReleaseTexImageARBPROC wglReleaseTexImageARB = NULL;
wglSetPbufferAttribARBPROC wglSetPbufferAttribARB = NULL;

static GLboolean _wglewInit_ARB_render_texture ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglBindTexImageARB = (wglBindTexImageARBPROC)glewGetProcAddress("wglBindTexImageARB")) == NULL;
  r = r || (wglReleaseTexImageARB = (wglReleaseTexImageARBPROC)glewGetProcAddress("wglReleaseTexImageARB")) == NULL;
  r = r || (wglSetPbufferAttribARB = (wglSetPbufferAttribARBPROC)glewGetProcAddress("wglSetPbufferAttribARB")) == NULL;
  return r;
}
#endif /* WGL_ARB_render_texture */

/* ------------------------- EXT_display_color_table ---------------------- */

#ifdef WGL_EXT_display_color_table

wglCreateDisplayColorTableEXTPROC wglCreateDisplayColorTableEXT = NULL;
wglLoadDisplayColorTableEXTPROC wglLoadDisplayColorTableEXT = NULL;
wglBindDisplayColorTableEXTPROC wglBindDisplayColorTableEXT = NULL;
wglDestroyDisplayColorTableEXTPROC wglDestroyDisplayColorTableEXT = NULL;

static GLboolean _wglewInit_EXT_display_color_table ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglCreateDisplayColorTableEXT = (wglCreateDisplayColorTableEXTPROC)glewGetProcAddress("wglCreateDisplayColorTableEXT")) == NULL;
  r = r || (wglLoadDisplayColorTableEXT = (wglLoadDisplayColorTableEXTPROC)glewGetProcAddress("wglLoadDisplayColorTableEXT")) == NULL;
  r = r || (wglBindDisplayColorTableEXT = (wglBindDisplayColorTableEXTPROC)glewGetProcAddress("wglBindDisplayColorTableEXT")) == NULL;
  r = r || (wglDestroyDisplayColorTableEXT = (wglDestroyDisplayColorTableEXTPROC)glewGetProcAddress("wglDestroyDisplayColorTableEXT")) == NULL;
  return r;
}
#endif /* WGL_EXT_display_color_table */

/* -------------------------- EXT_make_current_read ----------------------- */

#ifdef WGL_EXT_make_current_read

wglMakeContextCurrentEXTPROC wglMakeContextCurrentEXT = NULL;
wglGetCurrentReadDCEXTPROC wglGetCurrentReadDCEXT = NULL;

static GLboolean _wglewInit_EXT_make_current_read ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglMakeContextCurrentEXT = (wglMakeContextCurrentEXTPROC)glewGetProcAddress("wglMakeContextCurrentEXT")) == NULL;
  r = r || (wglGetCurrentReadDCEXT = (wglGetCurrentReadDCEXTPROC)glewGetProcAddress("wglGetCurrentReadDCEXT")) == NULL;
  return r;
}
#endif /* WGL_EXT_make_current_read */

/* ------------------------- EXT_extensions_string ------------------------ */

#ifdef WGL_EXT_extensions_string
wglGetExtensionsStringEXTPROC wglGetExtensionsStringEXT = NULL;

static GLboolean _wglewInit_EXT_extensions_string ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglGetExtensionsStringEXT = (wglGetExtensionsStringEXTPROC)glewGetProcAddress("wglGetExtensionsStringEXT")) == NULL;
  return r;
}
#endif /* WGL_EXT_extensions_string */

/* ----------------------------- EXT_pixel_format ------------------------- */

#ifdef WGL_EXT_pixel_format

wglGetPixelFormatAttribivEXTPROC wglGetPixelFormatAttribivEXT = NULL;
wglGetPixelFormatAttribfvEXTPROC wglGetPixelFormatAttribfvEXT = NULL;
wglChoosePixelFormatEXTPROC wglChoosePixelFormatEXT = NULL;

static GLboolean _wglewInit_EXT_pixel_format ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglGetPixelFormatAttribivEXT = (wglGetPixelFormatAttribivEXTPROC)glewGetProcAddress("wglGetPixelFormatAttribivEXT")) == NULL;
  r = r || (wglGetPixelFormatAttribfvEXT = (wglGetPixelFormatAttribfvEXTPROC)glewGetProcAddress("wglGetPixelFormatAttribfvEXT")) == NULL;
  r = r || (wglChoosePixelFormatEXT = (wglChoosePixelFormatEXTPROC)glewGetProcAddress("wglChoosePixelFormatEXT")) == NULL;
  return r;
}

#endif /* WGL_EXT_pixel_format */

/* ------------------------------- EXT_pbuffer ---------------------------- */

#ifdef WGL_EXT_pbuffer

wglCreatePbufferEXTPROC wglCreatePbufferEXT = NULL;
wglGetPbufferDCEXTPROC wglGetPbufferDCEXT = NULL;
wglReleasePbufferDCEXTPROC wglReleasePbufferDCEXT = NULL;
wglDestroyPbufferEXTPROC wglDestroyPbufferEXT = NULL;
wglQueryPbufferEXTPROC wglQueryPbufferEXT = NULL;

static GLboolean _wglewInit_EXT_pbuffer ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglCreatePbufferEXT = (wglCreatePbufferEXTPROC)glewGetProcAddress("wglCreatePbufferEXT")) == NULL;
  r = r || (wglGetPbufferDCEXT = (wglGetPbufferDCEXTPROC)glewGetProcAddress("wglGetPbufferDCEXT")) == NULL;
  r = r || (wglReleasePbufferDCEXT = (wglReleasePbufferDCEXTPROC)glewGetProcAddress("wglReleasePbufferDCEXT")) == NULL;
  r = r || (wglDestroyPbufferEXT = (wglDestroyPbufferEXTPROC)glewGetProcAddress("wglDestroyPbufferEXT")) == NULL;
  r = r || (wglQueryPbufferEXT = (wglQueryPbufferEXTPROC)glewGetProcAddress("wglQueryPbufferEXT")) == NULL;
  return r;
}

#endif /* WGL_EXT_pbuffer */

/* --------------------------- EXT_swap_control --------------------------- */

#ifdef WGL_EXT_swap_control
wglSwapIntervalEXTPROC wglSwapIntervalEXT = NULL;
wglGetSwapIntervalEXTPROC wglGetSwapIntervalEXT = NULL;

static GLboolean _wglewInit_EXT_swap_control ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglSwapIntervalEXT = (wglSwapIntervalEXTPROC)glewGetProcAddress("wglSwapIntervalEXT")) == NULL;
  r = r || (wglGetSwapIntervalEXT = (wglGetSwapIntervalEXTPROC)glewGetProcAddress("wglGetSwapIntervalEXT")) == NULL;
  return r;
}
#endif /* WGL_EXT_swap_control */

/* ------------------------ I3D_digital_video_control --------------------- */

#ifdef WGL_I3D_digital_video_control
wglGetDigitalVideoParametersI3DPROC wglGetDigitalVideoParametersI3D = NULL;
wglSetDigitalVideoParametersI3DPROC wglSetDigitalVideoParametersI3D = NULL;

static GLboolean _wglewInit_I3D_digital_video_control ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglGetDigitalVideoParametersI3D = (wglGetDigitalVideoParametersI3DPROC)glewGetProcAddress("wglGetDigitalVideoParametersI3D")) == NULL;
  r = r || (wglSetDigitalVideoParametersI3D = (wglSetDigitalVideoParametersI3DPROC)glewGetProcAddress("wglSetDigitalVideoParametersI3D")) == NULL;
  return r;
}
#endif /* WGL_I3D_digital_video_control */

/* -------------------------------- I3D_gamma ----------------------------- */

#ifdef WGL_I3D_gamma
wglGetGammaTableParametersI3DPROC wglGetGammaTableParametersI3D = NULL;
wglSetGammaTableParametersI3DPROC wglSetGammaTableParametersI3D = NULL;
wglGetGammaTableI3DPROC wglGetGammaTableI3D = NULL;
wglSetGammaTableI3DPROC wglSetGammaTableI3D = NULL;

static GLboolean _wglewInit_I3D_gamma ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglGetGammaTableParametersI3D = (wglGetGammaTableParametersI3DPROC)glewGetProcAddress("wglGetGammaTableParametersI3D")) == NULL;
  r = r || (wglSetGammaTableParametersI3D = (wglSetGammaTableParametersI3DPROC)glewGetProcAddress("wglSetGammaTableParametersI3D")) == NULL;
  r = r || (wglGetGammaTableI3D = (wglGetGammaTableI3DPROC)glewGetProcAddress("wglGetGammaTableI3D")) == NULL;
  r = r || (wglSetGammaTableI3D = (wglSetGammaTableI3DPROC)glewGetProcAddress("wglSetGammaTableI3D")) == NULL;
  return r;
}
#endif /* WGL_I3D_gamma */

/* ------------------------------- I3D_genlock ---------------------------- */

#ifdef WGL_I3D_genlock
wglEnableGenlockI3DPROC wglEnableGenlockI3D = NULL;
wglDisableGenlockI3DPROC wglDisableGenlockI3D = NULL;
wglIsEnabledGenlockI3DPROC wglIsEnabledGenlockI3D = NULL;
wglGenlockSourceI3DPROC wglGenlockSourceI3D = NULL;
wglGetGenlockSourceI3DPROC wglGetGenlockSourceI3D = NULL;
wglGenlockSourceEdgeI3DPROC wglGenlockSourceEdgeI3D = NULL;
wglGetGenlockSourceEdgeI3DPROC wglGetGenlockSourceEdgeI3D = NULL;
wglGenlockSampleRateI3DPROC wglGenlockSampleRateI3D = NULL;
wglGetGenlockSampleRateI3DPROC wglGetGenlockSampleRateI3D = NULL;
wglGenlockSourceDelayI3DPROC wglGenlockSourceDelayI3D = NULL;
wglGetGenlockSourceDelayI3DPROC wglGetGenlockSourceDelayI3D = NULL;
wglQueryGenlockMaxSourceDelayI3DPROC wglQueryGenlockMaxSourceDelayI3D = NULL;

static GLboolean _wglewInit_I3D_genlock ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglEnableGenlockI3D = (wglEnableGenlockI3DPROC)glewGetProcAddress("wglEnableGenlockI3D")) == NULL;
  r = r || (wglDisableGenlockI3D = (wglDisableGenlockI3DPROC)glewGetProcAddress("wglDisableGenlockI3D")) == NULL;
  r = r || (wglIsEnabledGenlockI3D = (wglIsEnabledGenlockI3DPROC)glewGetProcAddress("wglIsEnabledGenlockI3D")) == NULL;
  r = r || (wglGenlockSourceI3D = (wglGenlockSourceI3DPROC)glewGetProcAddress("wglGenlockSourceI3D")) == NULL;
  r = r || (wglGetGenlockSourceI3D = (wglGetGenlockSourceI3DPROC)glewGetProcAddress("wglGetGenlockSourceI3D")) == NULL;
  r = r || (wglGenlockSourceEdgeI3D = (wglGenlockSourceEdgeI3DPROC)glewGetProcAddress("wglGenlockSourceEdgeI3D")) == NULL;
  r = r || (wglGetGenlockSourceEdgeI3D = (wglGetGenlockSourceEdgeI3DPROC)glewGetProcAddress("wglGetGenlockSourceEdgeI3D")) == NULL;
  r = r || (wglGenlockSampleRateI3D = (wglGenlockSampleRateI3DPROC)glewGetProcAddress("wglGenlockSampleRateI3D")) == NULL;
  r = r || (wglGetGenlockSampleRateI3D = (wglGetGenlockSampleRateI3DPROC)glewGetProcAddress("wglGetGenlockSampleRateI3D")) == NULL;
  r = r || (wglGenlockSourceDelayI3D = (wglGenlockSourceDelayI3DPROC)glewGetProcAddress("wglGenlockSourceDelayI3D")) == NULL;
  r = r || (wglGetGenlockSourceDelayI3D = (wglGetGenlockSourceDelayI3DPROC)glewGetProcAddress("wglGetGenlockSourceDelayI3D")) == NULL;
  r = r || (wglQueryGenlockMaxSourceDelayI3D = (wglQueryGenlockMaxSourceDelayI3DPROC)glewGetProcAddress("wglQueryGenlockMaxSourceDelayI3D")) == NULL;
  return r;
}
#endif /* WGL_I3D_genlock */

/* ---------------------------- I3D_image_buffer -------------------------- */

#ifdef WGL_I3D_image_buffer
wglCreateImageBufferI3DPROC wglCreateImageBufferI3D = NULL;
wglDestroyImageBufferI3DPROC wglDestroyImageBufferI3D = NULL;
wglAssociateImageBufferEventsI3DPROC wglAssociateImageBufferEventsI3D = NULL; 
wglReleaseImageBufferEventsI3DPROC wglReleaseImageBufferEventsI3D = NULL;

static GLboolean _wglewInit_I3D_image_buffer ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglCreateImageBufferI3D = (wglCreateImageBufferI3DPROC)glewGetProcAddress("wglCreateImageBufferI3D")) == NULL;
  r = r || (wglDestroyImageBufferI3D = (wglDestroyImageBufferI3DPROC)glewGetProcAddress("wglDestroyImageBufferI3D")) == NULL;
  r = r || (wglAssociateImageBufferEventsI3D = (wglAssociateImageBufferEventsI3DPROC)glewGetProcAddress("wglAssociateImageBufferEventsI3D")) == NULL;
  r = r || (wglReleaseImageBufferEventsI3D = (wglReleaseImageBufferEventsI3DPROC)glewGetProcAddress("wglReleaseImageBufferEventsI3D")) == NULL;
  return r;
}
#endif /* WGL_I3D_image_buffer */

/* --------------------------- I3D_swap_frame_lock ------------------------ */

#ifdef WGL_I3D_swap_frame_lock
wglEnableFrameLockI3DPROC wglEnableFrameLockI3D = NULL;
wglDisableFrameLockI3DPROC wglDisableFrameLockI3D = NULL;
wglIsEnabledFrameLockI3DPROC wglIsEnabledFrameLockI3D = NULL;
wglQueryFrameLockMasterI3DPROC wglQueryFrameLockMasterI3D = NULL;

static GLboolean _wglewInit_I3D_swap_frame_lock ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglEnableFrameLockI3D = (wglEnableFrameLockI3DPROC)glewGetProcAddress("wglEnableFrameLockI3D")) == NULL;
  r = r || (wglDisableFrameLockI3D = (wglDisableFrameLockI3DPROC)glewGetProcAddress("wglDisableFrameLockI3D")) == NULL;
  r = r || (wglIsEnabledFrameLockI3D = (wglIsEnabledFrameLockI3DPROC)glewGetProcAddress("wglIsEnabledFrameLockI3D")) == NULL;
  r = r || (wglQueryFrameLockMasterI3D = (wglQueryFrameLockMasterI3DPROC)glewGetProcAddress("wglQueryFrameLockMasterI3D")) == NULL;
  return r;
}
#endif /* WGL_I3D_swap_frame_lock */

/* -------------------------- I3D_swap_frame_usage ------------------------ */

#ifdef WGL_I3D_swap_frame_usage
wglGetFrameUsageI3DPROC wglGetFrameUsageI3D = NULL;
wglBeginFrameTrackingI3DPROC wglBeginFrameTrackingI3D = NULL;
wglEndFrameTrackingI3DPROC wglEndFrameTrackingI3D = NULL;
wglQueryFrameTrackingI3DPROC wglQueryFrameTrackingI3D = NULL;

static GLboolean _wglewInit_I3D_swap_frame_usage ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglGetFrameUsageI3D = (wglGetFrameUsageI3DPROC)glewGetProcAddress("wglGetFrameUsageI3D")) == NULL;
  r = r || (wglBeginFrameTrackingI3D = (wglBeginFrameTrackingI3DPROC)glewGetProcAddress("wglBeginFrameTrackingI3D")) == NULL;
  r = r || (wglEndFrameTrackingI3D = (wglEndFrameTrackingI3DPROC)glewGetProcAddress("wglEndFrameTrackingI3D")) == NULL;
  r = r || (wglQueryFrameTrackingI3D = (wglQueryFrameTrackingI3DPROC)glewGetProcAddress("wglQueryFrameTrackingI3D")) == NULL;
  return r;
}
#endif /* WGL_I3D_swap_frame_usage */

/* ---------------------------- OML_sync_control -------------------------- */

#ifdef WGL_OML_sync_control
wglGetSyncValuesOMLPROC wglGetSyncValuesOML = NULL;
wglGetMscRateOMLPROC wglGetMscRateOML = NULL;
wglSwapBuffersMscOMLPROC wglSwapBuffersMscOML = NULL;
wglSwapLayerBuffersMscOMLPROC wglSwapLayerBuffersMscOML = NULL;
wglWaitForMscOMLPROC wglWaitForMscOML = NULL;
wglWaitForSbcOMLPROC wglWaitForSbcOML = NULL;

static GLboolean _wglewInit_OML_sync_control ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglGetSyncValuesOML = (wglGetSyncValuesOMLPROC)glewGetProcAddress("wglGetSyncValuesOML")) == NULL;
  r = r || (wglGetMscRateOML = (wglGetMscRateOMLPROC)glewGetProcAddress("wglGetMscRateOML")) == NULL;
  r = r || (wglSwapBuffersMscOML = (wglSwapBuffersMscOMLPROC)glewGetProcAddress("wglSwapBuffersMscOML")) == NULL;
  r = r || (wglSwapLayerBuffersMscOML = (wglSwapLayerBuffersMscOMLPROC)glewGetProcAddress("wglSwapLayerBuffersMscOML")) == NULL;
  r = r || (wglWaitForMscOML = (wglWaitForMscOMLPROC)glewGetProcAddress("wglWaitForMscOML")) == NULL;
  r = r || (wglWaitForSbcOML = (wglWaitForSbcOMLPROC)glewGetProcAddress("wglWaitForSbcOML")) == NULL;
  return r;
}
#endif /* WGL_OML_sync_control */

/* ------------------------- NV_vertex_array_range ------------------------ */

#ifdef WGL_NV_vertex_array_range
wglAllocateMemoryNVPROC wglAllocateMemoryNV = NULL;
wglFreeMemoryNVPROC wglFreeMemoryNV = NULL;

static GLboolean _wglewInit_NV_vertex_array_range ()
{
  GLboolean r = GL_FALSE;
  r = r || (wglAllocateMemoryNV = (wglAllocateMemoryNVPROC)glewGetProcAddress("wglAllocateMemoryNV")) == NULL;
  r = r || (wglFreeMemoryNV = (wglFreeMemoryNVPROC)glewGetProcAddress("wglFreeMemoryNV")) == NULL;
  return r;
}
#endif /* WGL_NV_vertex_array_range */

#else /* _UNIX */

/* -------------------------------- GLX 1.0 ------------------------------- */

#ifdef GLX_VERSION_1_0
#ifdef GLEW_PROTOTYPES
glXQueryExtensionPROC glXQueryExtension = NULL;
glXQueryVersionPROC glXQueryVersion = NULL;
glXGetConfigPROC glXGetConfig = NULL;
glXChooseVisualPROC glXChooseVisual = NULL;
glXCreateGLXPixmapPROC glXCreateGLXPixmap = NULL;
glXDestroyGLXPixmapPROC glXDestroyGLXPixmap = NULL;
glXCreateContextPROC glXCreateContext = NULL;
glXDestroyContextPROC glXDestroyContext = NULL;
glXIsDirectPROC glXIsDirect = NULL;
glXCopyContextPROC glXCopyContext = NULL;
glXMakeCurrentPROC glXMakeCurrent = NULL;
glXGetCurrentContextPROC glXGetCurrentContext = NULL;
glXGetCurrentDrawablePROC glXGetCurrentDrawable = NULL;
glXWaitGLPROC glXWaitGL = NULL;
glXWaitXPROC glXWaitX = NULL;
glXSwapBuffersPROC glXSwapBuffers = NULL;
glXUseXFontPROC glXUseXFont = NULL;
#endif

static GLboolean _glxewInit_10 ()
{
  GLboolean r = GL_FALSE;
#ifdef GLEW_PROTOTYPES
  r = r || (glXQueryExtension = (glXQueryExtensionPROC)glewGetProcAddress("glXQueryExtension")) == NULL;
  r = r || (glXQueryVersion = (glXQueryVersionPROC)glewGetProcAddress("glXQueryVersion")) == NULL;
  r = r || (glXGetConfig = (glXGetConfigPROC)glewGetProcAddress("glXGetConfig")) == NULL;
  r = r || (glXChooseVisual = (glXChooseVisualPROC)glewGetProcAddress("glXChooseVisual")) == NULL;
  r = r || (glXCreateGLXPixmap = (glXCreateGLXPixmapPROC)glewGetProcAddress("glXCreateGLXPixmap")) == NULL;
  r = r || (glXDestroyGLXPixmap = (glXDestroyGLXPixmapPROC)glewGetProcAddress("glXDestroyGLXPixmap")) == NULL;
  r = r || (glXCreateContext = (glXCreateContextPROC)glewGetProcAddress("glXCreateContext")) == NULL;
  r = r || (glXDestroyContext = (glXDestroyContextPROC)glewGetProcAddress("glXDestroyContext")) == NULL;
  r = r || (glXIsDirect = (glXIsDirectPROC)glewGetProcAddress("glXIsDirect")) == NULL;
  r = r || (glXCopyContext = (glXCopyContextPROC)glewGetProcAddress("glXCopyContext")) == NULL;
  r = r || (glXMakeCurrent = (glXMakeCurrentPROC)glewGetProcAddress("glXMakeCurrent")) == NULL;
  r = r || (glXGetCurrentContext = (glXGetCurrentContextPROC)glewGetProcAddress("glXGetCurrentContext")) == NULL;
  r = r || (glXGetCurrentDrawable = (glXGetCurrentDrawablePROC)glewGetProcAddress("glXGetCurrentDrawable")) == NULL;
  r = r || (glXWaitGL = (glXWaitGLPROC)glewGetProcAddress("glXWaitGL")) == NULL;
  r = r || (glXWaitX = (glXWaitXPROC)glewGetProcAddress("glXWaitX")) == NULL;
  r = r || (glXSwapBuffers = (glXSwapBuffersPROC)glewGetProcAddress("glXSwapBuffers")) == NULL;
  r = r || (glXUseXFont = (glXUseXFontPROC)glewGetProcAddress("glXUseXFont")) == NULL;
#endif
  return r;
}
#endif /* GLX_VERSION_1_0 */

/* -------------------------------- GLX 1.1 ------------------------------- */

#ifdef GLX_VERSION_1_1
#ifdef GLEW_PROTOTYPES
glXQueryExtensionsStringPROC glXQueryExtensionsString = NULL;
glXGetClientStringPROC glXGetClientString = NULL;
glXQueryServerStringPROC glXQueryServerString = NULL;
#endif

static GLboolean _glxewInit_11 ()
{
  GLboolean r = GL_FALSE;
#ifdef GLEW_PROTOTYPES
  r = r || (glXQueryExtensionsString = (glXQueryExtensionsStringPROC)glewGetProcAddress("glXQueryExtensionsString")) == NULL;
  r = r || (glXGetClientString = (glXGetClientStringPROC)glewGetProcAddress("glXGetClientString")) == NULL;
  r = r || (glXQueryServerString = (glXQueryServerStringPROC)glewGetProcAddress("glXQueryServerString")) == NULL;
#endif
  return r;
}
#endif /* GLX_VERSION_1_1 */

/* -------------------------------- GLX 1.2 ------------------------------- */

#ifdef GLX_VERSION_1_2
glXGetCurrentDisplayPROC glXGetCurrentDisplay = NULL;

static GLboolean _glxewInit_12 ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXGetCurrentDisplay = (glXGetCurrentDisplayPROC)glewGetProcAddress("glXGetCurrentDisplay")) == NULL;
  return r;
}
#endif /* GLX_VERSION_1_2 */

/* -------------------------------- GLX 1.3 ------------------------------- */

#ifdef GLX_VERSION_1_3
glXChooseFBConfigPROC glXChooseFBConfig = NULL;
glXGetFBConfigsPROC glXGetFBConfigs = NULL;
glXGetVisualFromFBConfigPROC glXGetVisualFromFBConfig = NULL;
glXGetFBConfigAttribPROC glXGetFBConfigAttrib = NULL;
glXCreateWindowPROC glXCreateWindow = NULL;
glXDestroyWindowPROC glXDestroyWindow = NULL;
glXCreatePixmapPROC glXCreatePixmap = NULL;
glXDestroyPixmapPROC glXDestroyPixmap = NULL;
glXCreatePbufferPROC glXCreatePbuffer = NULL;
glXDestroyPbufferPROC glXDestroyPbuffer = NULL;
glXQueryDrawablePROC glXQueryDrawable = NULL;
glXCreateNewContextPROC glXCreateNewContext = NULL;
glXMakeContextCurrentPROC glXMakeContextCurrent = NULL;
glXGetCurrentReadDrawablePROC glXGetCurrentReadDrawable = NULL;
glXQueryContextPROC glXQueryContext = NULL;
glXSelectEventPROC glXSelectEvent = NULL;
glXGetSelectedEventPROC glXGetSelectedEvent = NULL;

static GLboolean _glxewInit_13 ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXChooseFBConfig = (glXChooseFBConfigPROC)glewGetProcAddress("glXChooseFBConfig")) == NULL;
  r = r || (glXGetFBConfigs = (glXGetFBConfigsPROC)glewGetProcAddress("glXGetFBConfigs")) == NULL;
  r = r || (glXGetVisualFromFBConfig = (glXGetVisualFromFBConfigPROC)glewGetProcAddress("glXGetVisualFromFBConfig")) == NULL;
  r = r || (glXGetFBConfigAttrib = (glXGetFBConfigAttribPROC)glewGetProcAddress("glXGetFBConfigAttrib")) == NULL;
  r = r || (glXCreateWindow = (glXCreateWindowPROC)glewGetProcAddress("glXCreateWindow")) == NULL;
  r = r || (glXDestroyWindow = (glXDestroyWindowPROC)glewGetProcAddress("glXDestroyWindow")) == NULL;
  r = r || (glXCreatePixmap = (glXCreatePixmapPROC)glewGetProcAddress("glXCreatePixmap")) == NULL;
  r = r || (glXDestroyPixmap = (glXDestroyPixmapPROC)glewGetProcAddress("glXDestroyPixmap")) == NULL;
  r = r || (glXCreatePbuffer = (glXCreatePbufferPROC)glewGetProcAddress("glXCreatePbuffer")) == NULL;
  r = r || (glXDestroyPbuffer = (glXDestroyPbufferPROC)glewGetProcAddress("glXDestroyPbuffer")) == NULL;
  r = r || (glXQueryDrawable = (glXQueryDrawablePROC)glewGetProcAddress("glXQueryDrawable")) == NULL;
  r = r || (glXCreateNewContext = (glXCreateNewContextPROC)glewGetProcAddress("glXCreateNewContext")) == NULL;
  r = r || (glXMakeContextCurrent = (glXMakeContextCurrentPROC)glewGetProcAddress("glXMakeContextCurrent")) == NULL;
  r = r || (glXGetCurrentReadDrawable = (glXGetCurrentReadDrawablePROC)glewGetProcAddress("glXGetCurrentReadDrawable")) == NULL;
  r = r || (glXQueryContext = (glXQueryContextPROC)glewGetProcAddress("glXQueryContext")) == NULL;
  r = r || (glXSelectEvent = (glXSelectEventPROC)glewGetProcAddress("glXSelectEvent")) == NULL;
  r = r || (glXGetSelectedEvent = (glXGetSelectedEventPROC)glewGetProcAddress("glXGetSelectedEvent")) == NULL;
  return r;
}
#endif /* GLX_VERSION_1_3 */

/* --------------------------- EXT_import_context -------------------------- */

#ifdef GLX_EXT_import_context
glXGetCurrentDisplayEXTPROC glXGetCurrentDisplayEXT = NULL;
glXQueryContextInfoEXTPROC glXQueryContextInfoEXT = NULL;
glXGetContextIDEXTPROC glXGetContextIDEXT = NULL;
glXImportContextEXTPROC glXImportContextEXT = NULL;
glXFreeContextEXTPROC glXFreeContextEXT = NULL;

static GLboolean _glxewInit_EXT_import_context ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXGetCurrentDisplayEXT = (glXGetCurrentDisplayEXTPROC)glewGetProcAddress("glXGetCurrentDisplayEXT")) == NULL;
  r = r || (glXQueryContextInfoEXT = (glXQueryContextInfoEXTPROC)glewGetProcAddress("glXQueryContextInfoEXT")) == NULL;
  r = r || (glXGetContextIDEXT = (glXGetContextIDEXTPROC)glewGetProcAddress("glXGetContextIDEXT")) == NULL;
  r = r || (glXImportContextEXT = (glXImportContextEXTPROC)glewGetProcAddress("glXImportContextEXT")) == NULL;
  r = r || (glXFreeContextEXT = (glXFreeContextEXTPROC)glewGetProcAddress("glXFreeContextEXT")) == NULL;
  return r;
}
#endif /* GLX_EXT_import_context */

/* --------------------------- MESA_copy_sub_buffer ----------------------- */

#ifdef GLX_MESA_copy_sub_buffer
glXCopySubBufferMESAPROC glXCopySubBufferMESA = NULL;

static GLboolean _glxewInit_MESA_copy_sub_buffer ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXCopySubBufferMESA = (glXCopySubBufferMESAPROC)glewGetProcAddress("glXCopySubBufferMESA")) == NULL;
  return r;
}
#endif /* GLX_MESA_copy_sub_buffer */

/* -------------------------- MESA_pixmap_colormap ------------------------ */

#ifdef GLX_MESA_pixmap_colormap
glXCreateGLXPixmapMESAPROC glXCreateGLXPixmapMESA = NULL;

static GLboolean _glxewInit_MESA_pixmap_colormap ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXCreateGLXPixmapMESA = (glXCreateGLXPixmapMESAPROC)glewGetProcAddress("glXCreateGLXPixmapMESA")) == NULL;
  return r;
}
#endif /* GLX_MESA_pixmap_colormap */

/* -------------------------- MESA_release_buffers ------------------------ */

#ifdef GLX_MESA_release_buffers
glXReleaseBuffersMESAPROC glXReleaseBuffersMESA = NULL;

static GLboolean _glxewInit_MESA_release_buffers ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXReleaseBuffersMESA = (glXReleaseBuffersMESAPROC)glewGetProcAddress("glXReleaseBuffersMESA")) == NULL;
  return r;
}
#endif /* GLX_MESA_release_buffers */

/* --------------------------- MESA_set_3dfx_mode ------------------------- */

#ifdef GLX_MESA_set_3dfx_mode
glXSet3DfxModeMESAPROC glXSet3DfxModeMESA = NULL;

static GLboolean _glxewInit_MESA_set_3dfx_mode ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXSet3DfxModeMESA = (glXSet3DfxModeMESAPROC)glewGetProcAddress("glXSet3DfxModeMESA")) == NULL;
  return r;
}
#endif /* GLX_MESA_set_3dfx_mode */

/* ------------------------- NV_vertex_array_range ------------------------ */

#ifdef GLX_NV_vertex_array_range
glXAllocateMemoryNVPROC glXAllocateMemoryNV = NULL;
glXFreeMemoryNVPROC glXFreeMemoryNV = NULL;

static GLboolean _glxewInit_NV_vertex_array_range ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXAllocateMemoryNV = (glXAllocateMemoryNVPROC)glewGetProcAddress("glXAllocateMemoryNV")) == NULL;
  r = r || (glXFreeMemoryNV = (glXFreeMemoryNVPROC)glewGetProcAddress("glXFreeMemoryNV")) == NULL;
  return r;
}
#endif /* GLX_NV_vertex_array_range */

/* ---------------------------- OML_sync_control -------------------------- */

#ifdef GLX_OML_sync_control
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
glXGetSyncValuesOMLPROC glXGetSyncValuesOML = NULL;
glXGetMscRateOMLPROC glXGetMscRateOML = NULL;
glXSwapBuffersMscOMLPROC glXSwapBuffersMscOML = NULL;
glXWaitForMscOMLPROC glXWaitForMscOML = NULL;
glXWaitForSbcOMLPROC glXWaitForSbcOML = NULL;

static GLboolean _glxewInit_OML_sync_control ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXGetSyncValuesOML = (glXGetSyncValuesOMLPROC)glewGetProcAddress("glXGetSyncValuesOML")) == NULL;
  r = r || (glXGetMscRateOML = (glXGetMscRateOMLPROC)glewGetProcAddress("glXGetMscRateOML")) == NULL;
  r = r || (glXSwapBuffersMscOML = (glXSwapBuffersMscOMLPROC)glewGetProcAddress("glXSwapBuffersMscOML")) == NULL;
  r = r || (glXWaitForMscOML = (glXWaitForMscOMLPROC)glewGetProcAddress("glXWaitForMscOML")) == NULL;
  r = r || (glXWaitForSbcOML = (glXWaitForSbcOMLPROC)glewGetProcAddress("glXWaitForSbcOML")) == NULL;
  return r;
}
#endif /* __STDC_VERSION__ */
#endif /* GLX_OML_sync_control */

/* ------------------------------- SGI_cushion ---------------------------- */

#ifdef GLX_SGI_cushion
glXCushionSGIPROC glXCushionSGI = NULL;

static GLboolean _glxewInit_SGI_cushion ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXCushionSGI = (glXCushionSGIPROC)glewGetProcAddress("glXCushionSGI")) == NULL;
  return r;
}
#endif /* GLX_SGI_cushion */

/* -------------------------- SGI_make_current_read ----------------------- */

#ifdef GLX_SGI_make_current_read
glXMakeCurrentReadSGIPROC glXMakeCurrentReadSGI = NULL;
glXGetCurrentReadDrawableSGIPROC glXGetCurrentReadDrawableSGI = NULL;

static GLboolean _glxewInit_SGI_make_current_read ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXMakeCurrentReadSGI = (glXMakeCurrentReadSGIPROC)glewGetProcAddress("glXMakeCurrentReadSGI")) == NULL;
  r = r || (glXGetCurrentReadDrawableSGI = (glXGetCurrentReadDrawableSGIPROC)glewGetProcAddress("glXGetCurrentReadDrawableSGI")) == NULL;
  return r;
}
#endif /* GLX_SGI_make_current_read */

/* ---------------------------- SGI_swap_control -------------------------- */

#ifdef GLX_SGI_swap_control
glXSwapIntervalSGIPROC glXSwapIntervalSGI = NULL;

static GLboolean _glxewInit_SGI_swap_control ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXSwapIntervalSGI = (glXSwapIntervalSGIPROC)glewGetProcAddress("glXSwapIntervalSGI")) == NULL;
  return r;
}
#endif /* GLX_SGI_swap_control */

/* ----------------------------- SGI_video_sync --------------------------- */

#ifdef GLX_SGI_video_sync
glXGetVideoSyncSGIPROC glXGetVideoSyncSGI = NULL;
glXWaitVideoSyncSGIPROC glXWaitVideoSyncSGI = NULL;
glXGetRefreshRateSGIPROC glXGetRefreshRateSGI = NULL;

static GLboolean _glxewInit_SGI_video_sync ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXGetVideoSyncSGI = (glXGetVideoSyncSGIPROC)glewGetProcAddress("glXGetVideoSyncSGI")) == NULL;
  r = r || (glXWaitVideoSyncSGI = (glXWaitVideoSyncSGIPROC)glewGetProcAddress("glXWaitVideoSyncSGI")) == NULL;
  r = r || (glXGetRefreshRateSGI = (glXGetRefreshRateSGIPROC)glewGetProcAddress("glXGetRefreshRateSGI")) == NULL;
  return r;
}
#endif /* GLX_SGI_video_sync */

/* ------------------------------ SGIX_fbconfig --------------------------- */

#ifdef GLX_SGIX_fbconfig
glXGetFBConfigAttribSGIXPROC glXGetFBConfigAttribSGIX = NULL;
glXChooseFBConfigSGIXPROC glXChooseFBConfigSGIX = NULL;
glXCreateGLXPixmapWithConfigSGIXPROC glXCreateGLXPixmapWithConfigSGIX = NULL;
glXCreateContextWithConfigSGIXPROC glXCreateContextWithConfigSGIX = NULL;
glXGetVisualFromFBConfigSGIXPROC glXGetVisualFromFBConfigSGIX = NULL;
glXGetFBConfigFromVisualSGIXPROC glXGetFBConfigFromVisualSGIX = NULL;

static GLboolean _glxewInit_SGIX_fbconfig ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXGetFBConfigAttribSGIX = (glXGetFBConfigAttribSGIXPROC)glewGetProcAddress("glXGetFBConfigAttribSGIX")) == NULL;
  r = r || (glXChooseFBConfigSGIX = (glXChooseFBConfigSGIXPROC)glewGetProcAddress("glXChooseFBConfigSGIX")) == NULL;
  r = r || (glXCreateGLXPixmapWithConfigSGIX = (glXCreateGLXPixmapWithConfigSGIXPROC)glewGetProcAddress("glXCreateGLXPixmapWithConfigSGIX")) == NULL;
  r = r || (glXCreateContextWithConfigSGIX = (glXCreateContextWithConfigSGIXPROC)glewGetProcAddress("glXCreateContextWithConfigSGIX")) == NULL;
  r = r || (glXGetVisualFromFBConfigSGIX = (glXGetVisualFromFBConfigSGIXPROC)glewGetProcAddress("glXGetVisualFromFBConfigSGIX")) == NULL;
  r = r || (glXGetFBConfigFromVisualSGIX = (glXGetFBConfigFromVisualSGIXPROC)glewGetProcAddress("glXGetFBConfigFromVisualSGIX")) == NULL;
  return r;
}
#endif /* GLX_SGIX_fbconfig */

/* ------------------------------- SGIX_pbuffer --------------------------- */

#ifdef GLX_SGIX_pbuffer
glXCreateGLXPbufferSGIXPROC glXCreateGLXPbufferSGIX = NULL;
glXDestroyGLXPbufferSGIXPROC glXDestroyGLXPbufferSGIX = NULL;
glXQueryGLXPbufferSGIXPROC glXQueryGLXPbufferSGIX = NULL;
glXSelectEventSGIXPROC glXSelectEventSGIX = NULL;
glXGetSelectedEventSGIXPROC glXGetSelectedEventSGIX = NULL;

static GLboolean _glxewInit_SGIX_pbuffer ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXCreateGLXPbufferSGIX = (glXCreateGLXPbufferSGIXPROC)glewGetProcAddress("glXCreateGLXPbufferSGIX")) == NULL;
  r = r || (glXDestroyGLXPbufferSGIX = (glXDestroyGLXPbufferSGIXPROC)glewGetProcAddress("glXDestroyGLXPbufferSGIX")) == NULL;
  r = r || (glXQueryGLXPbufferSGIX = (glXQueryGLXPbufferSGIXPROC)glewGetProcAddress("glXQueryGLXPbufferSGIX")) == NULL;
  r = r || (glXSelectEventSGIX = (glXSelectEventSGIXPROC)glewGetProcAddress("glXSelectEventSGIX")) == NULL;
  r = r || (glXGetSelectedEventSGIX = (glXGetSelectedEventSGIXPROC)glewGetProcAddress("glXGetSelectedEventSGIX")) == NULL;
  return r;
}
#endif /* GLX_SGIX_pbuffer */

/* ---------------------------- SGIX_swap_barrier ------------------------- */

#ifdef GLX_SGIX_swap_barrier
glXBindSwapBarrierSGIXPROC glXBindSwapBarrierSGIX = NULL;
glXQueryMaxSwapBarriersSGIXPROC glXQueryMaxSwapBarriersSGIX = NULL;

static GLboolean _glxewInit_SGIX_swap_barrier ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXBindSwapBarrierSGIX = (glXBindSwapBarrierSGIXPROC)glewGetProcAddress("glXBindSwapBarrierSGIX")) == NULL;
  r = r || (glXQueryMaxSwapBarriersSGIX = (glXQueryMaxSwapBarriersSGIXPROC)glewGetProcAddress("glXQueryMaxSwapBarriersSGIX")) == NULL;
  return r;
}
#endif /* GLX_SGIX_swap_barrier */

/* ----------------------------- SGIX_swap_group -------------------------- */

#ifdef GLX_SGIX_swap_group
glXJoinSwapGroupSGIXPROC glXJoinSwapGroupSGIX = NULL;

static GLboolean _glxewInit_SGIX_swap_group ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXJoinSwapGroupSGIX = (glXJoinSwapGroupSGIXPROC)glewGetProcAddress("glXJoinSwapGroupSGIX")) == NULL;
  return r;
}
#endif /* GLX_SGIX_swap_group */

/* ------------------------ SUN_get_transparent_index --------------------- */

#ifdef GLX_SUN_get_transparent_index
glXGetTransparentIndexSUNPROC glXGetTransparentIndexSUN = NULL;

static GLboolean _glxewInit_SUN_get_transparent_index ()
{
  GLboolean r = GL_FALSE;
  r = r || (glXGetTransparentIndexSUN = (glXGetTransparentIndexSUNPROC)glewGetProcAddress("glXGetTransparentIndexSUN")) == NULL;
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
  glew.EXT_texture_filter_anisotropic = glewGetExtension("GL_EXT_texture_filter_anisotropic");
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
#ifdef GL_ATI_point_cull_mode
  glew.ATI_point_cull_mode = glewGetExtension("GL_ATI_point_cull_mode");
#endif
#ifdef GL_ATI_separate_stencil
  glew.ATI_separate_stencil = glewGetExtension("GL_ATI_separate_stencil");
  if (glewExperimental || glew.ATI_separate_stencil) glew.ATI_separate_stencil = !_glewInit_ATI_separate_stencil();
#endif
#ifdef GL_ATI_text_fragment_shader
  glew.ATI_texture_float = glewGetExtension("GL_ATI_texture_float");
#endif
#ifdef GL_ATI_texture_float
  glew.ATI_texture_float = glewGetExtension("GL_ATI_texture_float");
#endif
#ifdef GL_ATI_texture_mirror_once
  glew.ATI_texture_mirror_once = glewGetExtension("GL_ATI_texture_mirror_once");
#endif
#ifdef GL_ATI_timestamp
  glew.ATI_timestamp = glewGetExtension("GL_ATI_timestamp");
  if (glewExperimental || glew.ATI_timestamp) glew.ATI_timestamp = !_glewInit_ATI_timestamp();
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
  if (r = _glewInit()) return r;
#ifdef _WIN32
  return _wglewInit();
#else /* _UNIX */
  return _glxewInit();
#endif /* _WIN32 */
}
