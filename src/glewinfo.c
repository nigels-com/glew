/*
** The OpenGL Extension Wrangler Library
** Copyright (C) 2003, 2002, Milan Ikits
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

#include <stdio.h>
#include <string.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/wglew.h>
#include <GL/glxew.h>

static FILE* f;

static void glewPrintExt (const char* name, int defined)
{
  unsigned int i;
  fprintf(f, "\n%s:", name);
  for (i=0; i<42-strlen(name); i++) fprintf(f, " ");
  fprintf(f, "%s\n", defined ? "OK" : "MISSING");
  for (i=0; i<strlen(name)+1; i++) fprintf(f, "-");
  fprintf(f, "\n");
  fflush(f);
}

static void glewInfoFunc (int undefined, const char* name)
{
  unsigned int i;
  fprintf(f, "  %s:", name);
  for (i=0; i<40-strlen(name); i++) fprintf(f, " ");
  fprintf(f, "%s\n", undefined ? "MISSING" : "OK");
  fflush(f);
}

/* ------------------------------ OpenGL 1.2 ------------------------------ */

#ifdef GL_VERSION_1_2
static void glewInfo_12 ()
{
  char me[] = "GL_12"; glewPrintExt(me, glew.GL_12);
  glewInfoFunc(glCopyTexSubImage3D == NULL, "glCopyTexSubImage3D");
  glewInfoFunc(glDrawRangeElements == NULL, "glDrawRangeElements");
  glewInfoFunc(glTexImage3D == NULL, "glTexImage3D");
  glewInfoFunc(glTexSubImage3D == NULL, "glTexSubImage3D");
}
#endif /* GL_VERSION_1_2 */

/* ------------------------------ OpenGL 1.3 ------------------------------ */

#ifdef GL_VERSION_1_3
static void glewInfo_13 ()
{
  char me[] = "GL_13"; glewPrintExt(me, glew.GL_13);
  glewInfoFunc(glActiveTexture == NULL, "glActiveTexture");
  glewInfoFunc(glClientActiveTexture == NULL, "glClientActiveTexture");
  glewInfoFunc(glMultiTexCoord1d == NULL, "glMultiTexCoord1d");
  glewInfoFunc(glMultiTexCoord1dv == NULL, "glMultiTexCoord1dv");
  glewInfoFunc(glMultiTexCoord1f == NULL, "glMultiTexCoord1f");
  glewInfoFunc(glMultiTexCoord1fv == NULL, "glMultiTexCoord1fv");
  glewInfoFunc(glMultiTexCoord1i == NULL, "glMultiTexCoord1i");
  glewInfoFunc(glMultiTexCoord1iv == NULL, "glMultiTexCoord1iv");
  glewInfoFunc(glMultiTexCoord1s == NULL, "glMultiTexCoord1s");
  glewInfoFunc(glMultiTexCoord1sv == NULL, "glMultiTexCoord1sv");
  glewInfoFunc(glMultiTexCoord2d == NULL, "glMultiTexCoord2d");
  glewInfoFunc(glMultiTexCoord2dv == NULL, "glMultiTexCoord2dv");
  glewInfoFunc(glMultiTexCoord2f == NULL, "glMultiTexCoord2f");
  glewInfoFunc(glMultiTexCoord2fv == NULL, "glMultiTexCoord2fv");
  glewInfoFunc(glMultiTexCoord2i == NULL, "glMultiTexCoord2i");
  glewInfoFunc(glMultiTexCoord2iv == NULL, "glMultiTexCoord2iv");
  glewInfoFunc(glMultiTexCoord2s == NULL, "glMultiTexCoord2s");
  glewInfoFunc(glMultiTexCoord2sv == NULL, "glMultiTexCoord2sv");
  glewInfoFunc(glMultiTexCoord3d == NULL, "glMultiTexCoord3d");
  glewInfoFunc(glMultiTexCoord3dv == NULL, "glMultiTexCoord3dv");
  glewInfoFunc(glMultiTexCoord3f == NULL, "glMultiTexCoord3f");
  glewInfoFunc(glMultiTexCoord3fv == NULL, "glMultiTexCoord3fv");
  glewInfoFunc(glMultiTexCoord3i == NULL, "glMultiTexCoord3i");
  glewInfoFunc(glMultiTexCoord3iv == NULL, "glMultiTexCoord3iv");
  glewInfoFunc(glMultiTexCoord3s == NULL, "glMultiTexCoord3s");
  glewInfoFunc(glMultiTexCoord3sv == NULL, "glMultiTexCoord3sv");
  glewInfoFunc(glMultiTexCoord4d == NULL, "glMultiTexCoord4d");
  glewInfoFunc(glMultiTexCoord4dv == NULL, "glMultiTexCoord4dv");
  glewInfoFunc(glMultiTexCoord4f == NULL, "glMultiTexCoord4f");
  glewInfoFunc(glMultiTexCoord4fv == NULL, "glMultiTexCoord4fv");
  glewInfoFunc(glMultiTexCoord4i == NULL, "glMultiTexCoord4i");
  glewInfoFunc(glMultiTexCoord4iv == NULL, "glMultiTexCoord4iv");
  glewInfoFunc(glMultiTexCoord4s == NULL, "glMultiTexCoord4s");
  glewInfoFunc(glMultiTexCoord4sv == NULL, "glMultiTexCoord4sv");
  glewInfoFunc(glLoadTransposeMatrixf == NULL, "glLoadTransposeMatrixf");
  glewInfoFunc(glLoadTransposeMatrixd == NULL, "glLoadTransposeMatrixd");
  glewInfoFunc(glMultTransposeMatrixf == NULL, "glMultTransposeMatrixf");
  glewInfoFunc(glMultTransposeMatrixd == NULL, "glMultTransposeMatrixd");
  glewInfoFunc(glCompressedTexImage3D == NULL, "glCompressedTexImage3D");
  glewInfoFunc(glCompressedTexImage2D == NULL, "glCompressedTexImage2D");
  glewInfoFunc(glCompressedTexImage1D == NULL, "glCompressedTexImage1D");
  glewInfoFunc(glCompressedTexSubImage3D == NULL, "glCompressedTexSubImage3D");
  glewInfoFunc(glCompressedTexSubImage2D == NULL, "glCompressedTexSubImage2D");
  glewInfoFunc(glCompressedTexSubImage1D == NULL, "glCompressedTexSubImage1D");
  glewInfoFunc(glGetCompressedTexImage == NULL, "glGetCompressedTexImage");
  glewInfoFunc(glSampleCoverage == NULL, "glSampleCoverage");
}
#endif /* GL_VERSION_1_3 */

/* ------------------------------ OpenGL 1.4 ------------------------------ */

#ifdef GL_VERSION_1_4
static void glewInfo_14 ()
{
  char me[] = "GL_14"; glewPrintExt(me, glew.GL_14);
  glewInfoFunc(glBlendColor == NULL, "glBlendColor");
  glewInfoFunc(glBlendEquation == NULL, "glBlendEquation");
  glewInfoFunc(glFogCoordf == NULL, "glFogCoordf");
  glewInfoFunc(glFogCoordfv == NULL, "glFogCoordfv");
  glewInfoFunc(glFogCoordd == NULL, "glFogCoordd");
  glewInfoFunc(glFogCoorddv == NULL, "glFogCoorddv");
  glewInfoFunc(glFogCoordPointer == NULL, "glFogCoordPointer");
  glewInfoFunc(glMultiDrawArrays == NULL, "glMultiDrawArrays");
  glewInfoFunc(glMultiDrawElements == NULL, "glMultiDrawElements");
  glewInfoFunc(glPointParameterf == NULL, "glPointParameterf");
  glewInfoFunc(glPointParameterfv == NULL, "glPointParameterfv");
  glewInfoFunc(glSecondaryColor3b == NULL, "glSecondaryColor3b");
  glewInfoFunc(glSecondaryColor3bv == NULL, "glSecondaryColor3bv");
  glewInfoFunc(glSecondaryColor3d == NULL, "glSecondaryColor3d");
  glewInfoFunc(glSecondaryColor3dv == NULL, "glSecondaryColor3dv");
  glewInfoFunc(glSecondaryColor3f == NULL, "glSecondaryColor3f");
  glewInfoFunc(glSecondaryColor3fv == NULL, "glSecondaryColor3fv");
  glewInfoFunc(glSecondaryColor3i == NULL, "glSecondaryColor3i");
  glewInfoFunc(glSecondaryColor3iv == NULL, "glSecondaryColor3iv");
  glewInfoFunc(glSecondaryColor3s == NULL, "glSecondaryColor3s");
  glewInfoFunc(glSecondaryColor3sv == NULL, "glSecondaryColor3sv");
  glewInfoFunc(glSecondaryColor3ub == NULL, "glSecondaryColor3ub");
  glewInfoFunc(glSecondaryColor3ubv == NULL, "glSecondaryColor3ubv");
  glewInfoFunc(glSecondaryColor3ui == NULL, "glSecondaryColor3ui");
  glewInfoFunc(glSecondaryColor3uiv == NULL, "glSecondaryColor3uiv");
  glewInfoFunc(glSecondaryColor3us == NULL, "glSecondaryColor3us");
  glewInfoFunc(glSecondaryColor3usv == NULL, "glSecondaryColor3usv");
  glewInfoFunc(glSecondaryColorPointer == NULL, "glSecondaryColorPointer");
  glewInfoFunc(glBlendFuncSeparate == NULL, "glBlendFuncSeparate");
  glewInfoFunc(glWindowPos2d == NULL, "glWindowPos2d");
  glewInfoFunc(glWindowPos2f == NULL, "glWindowPos2f");
  glewInfoFunc(glWindowPos2i == NULL, "glWindowPos2i");
  glewInfoFunc(glWindowPos2s == NULL, "glWindowPos2s");
  glewInfoFunc(glWindowPos2dv == NULL, "glWindowPos2dv");
  glewInfoFunc(glWindowPos2fv == NULL, "glWindowPos2fv");
  glewInfoFunc(glWindowPos2iv == NULL, "glWindowPos2iv");
  glewInfoFunc(glWindowPos2sv == NULL, "glWindowPos2sv");
  glewInfoFunc(glWindowPos3d == NULL, "glWindowPos3d");
  glewInfoFunc(glWindowPos3f == NULL, "glWindowPos3f");
  glewInfoFunc(glWindowPos3i == NULL, "glWindowPos3i");
  glewInfoFunc(glWindowPos3s == NULL, "glWindowPos3s");
  glewInfoFunc(glWindowPos3dv == NULL, "glWindowPos3dv");
  glewInfoFunc(glWindowPos3fv == NULL, "glWindowPos3fv");
  glewInfoFunc(glWindowPos3iv == NULL, "glWindowPos3iv");
  glewInfoFunc(glWindowPos3sv == NULL, "glWindowPos3sv");
}
#endif /* GL_VERSION_1_4 */

/* ------------------------------ ARB_imaging ----------------------------- */

#ifdef GL_ARB_imaging
static void glewInfo_ARB_imaging ()
{
    //#ifdef _WIN32
  char me[] = "GL_ARB_imaging"; glewPrintExt(me, glew.ARB_imaging);
  glewInfoFunc(glBlendColor == NULL, "glBlendColor");
  glewInfoFunc(glBlendEquation == NULL, "glBlendEquation");
  glewInfoFunc(glColorTable == NULL, "glColorTable");
  glewInfoFunc(glColorTableParameterfv == NULL, "glColorTableParameterfv");
  glewInfoFunc(glColorTableParameteriv == NULL, "glColorTableParameteriv");
  glewInfoFunc(glCopyColorTable == NULL, "glCopyColorTable");
  glewInfoFunc(glGetColorTable == NULL, "glGetColorTable");
  glewInfoFunc(glGetColorTableParameterfv == NULL, "glGetColorTableParameterfv");
  glewInfoFunc(glGetColorTableParameteriv == NULL, "glGetColorTableParameteriv");
  glewInfoFunc(glColorSubTable == NULL, "glColorSubTable");
  glewInfoFunc(glCopyColorSubTable == NULL, "glCopyColorSubTable");
  glewInfoFunc(glConvolutionFilter1D == NULL, "glConvolutionFilter1D");
  glewInfoFunc(glConvolutionFilter2D == NULL, "glConvolutionFilter2D");
  glewInfoFunc(glConvolutionParameterf == NULL, "glConvolutionParameterf");
  glewInfoFunc(glConvolutionParameterfv == NULL, "glConvolutionParameterfv");
  glewInfoFunc(glConvolutionParameteri == NULL, "glConvolutionParameteri");
  glewInfoFunc(glConvolutionParameteriv == NULL, "glConvolutionParameteriv");
  glewInfoFunc(glCopyConvolutionFilter1D == NULL, "glCopyConvolutionFilter1D");
  glewInfoFunc(glCopyConvolutionFilter2D == NULL, "glCopyConvolutionFilter2D");
  glewInfoFunc(glGetConvolutionFilter == NULL, "glGetConvolutionFilter");
  glewInfoFunc(glGetConvolutionParameterfv == NULL, "glGetConvolutionParameterfv");
  glewInfoFunc(glGetConvolutionParameteriv == NULL, "glGetConvolutionParameteriv");
  glewInfoFunc(glGetSeparableFilter == NULL, "glGetSeparableFilter");
  glewInfoFunc(glSeparableFilter2D == NULL, "glSeparableFilter2D");
  glewInfoFunc(glGetHistogram == NULL, "glGetHistogram");
  glewInfoFunc(glGetHistogramParameterfv == NULL, "glGetHistogramParameterfv");
  glewInfoFunc(glGetHistogramParameteriv == NULL, "glGetHistogramParameteriv");
  glewInfoFunc(glGetMinmax == NULL, "glGetMinmax");
  glewInfoFunc(glGetMinmaxParameterfv == NULL, "glGetMinmaxParameterfv");
  glewInfoFunc(glGetMinmaxParameteriv == NULL, "glGetMinmaxParameteriv");
  glewInfoFunc(glHistogram == NULL, "glHistogram");
  glewInfoFunc(glMinmax == NULL, "glMinmax");
  glewInfoFunc(glResetHistogram == NULL, "glResetHistogram");
  glewInfoFunc(glResetMinmax == NULL, "glResetMinmax");
  //#endif /* _WIN32 */
}
#endif /* GL_ARB_imaging */

/* -------------------------- ARB_matrix_palette -------------------------- */

#ifdef GL_ARB_matrix_palette
static void glewInfo_ARB_matrix_palette ()
{
  char me[] = "GL_ARB_matrix_palette"; glewPrintExt(me, glew.ARB_matrix_palette);
  glewInfoFunc(glCurrentPaletteMatrixARB == NULL, "glCurrentPaletteMatrixARB");
  glewInfoFunc(glMatrixIndexubvARB == NULL, "glMatrixIndexubvARB");
  glewInfoFunc(glMatrixIndexusvARB == NULL, "glMatrixIndexusvARB");
  glewInfoFunc(glMatrixIndexuivARB == NULL, "glMatrixIndexuivARB");
  glewInfoFunc(glMatrixIndexPointerARB == NULL, "glMatrixIndexPointerARB");
}
#endif /* GL_ARB_matrix_palette */

/* ---------------------------- ARB_multisample --------------------------- */

#ifdef GL_ARB_multisample
static void glewInfo_ARB_multisample ()
{
  char me[] = "GL_ARB_multisample"; glewPrintExt(me, glew.ARB_multisample);
  glewInfoFunc(glSampleCoverageARB == NULL, "glSampleCoverageARB");
}
#endif /* GL_ARB_multisample */

/* --------------------------- ARB_multitexture --------------------------- */

#ifdef GL_ARB_multitexture
static void glewInfo_ARB_multitexture ()
{
  char me[] = "GL_ARB_multitexture"; glewPrintExt(me, glew.ARB_multitexture);
  glewInfoFunc(glActiveTextureARB == NULL, "glActiveTextureARB");
  glewInfoFunc(glClientActiveTextureARB == NULL, "glClientActiveTextureARB");
  glewInfoFunc(glMultiTexCoord1dARB == NULL, "glMultiTexCoord1dARB");
  glewInfoFunc(glMultiTexCoord1dvARB == NULL, "glMultiTexCoord1dvARB");
  glewInfoFunc(glMultiTexCoord1fARB == NULL, "glMultiTexCoord1fARB");
  glewInfoFunc(glMultiTexCoord1fvARB == NULL, "glMultiTexCoord1fvARB");
  glewInfoFunc(glMultiTexCoord1iARB == NULL, "glMultiTexCoord1iARB");
  glewInfoFunc(glMultiTexCoord1ivARB == NULL, "glMultiTexCoord1ivARB");
  glewInfoFunc(glMultiTexCoord1sARB == NULL, "glMultiTexCoord1sARB");
  glewInfoFunc(glMultiTexCoord1svARB == NULL, "glMultiTexCoord1svARB");
  glewInfoFunc(glMultiTexCoord2dARB == NULL, "glMultiTexCoord2dARB");
  glewInfoFunc(glMultiTexCoord2dvARB == NULL, "glMultiTexCoord2dvARB");
  glewInfoFunc(glMultiTexCoord2fARB == NULL, "glMultiTexCoord2fARB");
  glewInfoFunc(glMultiTexCoord2fvARB == NULL, "glMultiTexCoord2fvARB");
  glewInfoFunc(glMultiTexCoord2iARB == NULL, "glMultiTexCoord2iARB");
  glewInfoFunc(glMultiTexCoord2ivARB == NULL, "glMultiTexCoord2ivARB");
  glewInfoFunc(glMultiTexCoord2sARB == NULL, "glMultiTexCoord2sARB");
  glewInfoFunc(glMultiTexCoord2svARB == NULL, "glMultiTexCoord2svARB");
  glewInfoFunc(glMultiTexCoord3dARB == NULL, "glMultiTexCoord3dARB");
  glewInfoFunc(glMultiTexCoord3dvARB == NULL, "glMultiTexCoord3dvARB");
  glewInfoFunc(glMultiTexCoord3fARB == NULL, "glMultiTexCoord3fARB");
  glewInfoFunc(glMultiTexCoord3fvARB == NULL, "glMultiTexCoord3fvARB");
  glewInfoFunc(glMultiTexCoord3iARB == NULL, "glMultiTexCoord3iARB");
  glewInfoFunc(glMultiTexCoord3ivARB == NULL, "glMultiTexCoord3ivARB");
  glewInfoFunc(glMultiTexCoord3sARB == NULL, "glMultiTexCoord3sARB");
  glewInfoFunc(glMultiTexCoord3svARB == NULL, "glMultiTexCoord3svARB");
  glewInfoFunc(glMultiTexCoord4dARB == NULL, "glMultiTexCoord4dARB");
  glewInfoFunc(glMultiTexCoord4dvARB == NULL, "glMultiTexCoord4dvARB");
  glewInfoFunc(glMultiTexCoord4fARB == NULL, "glMultiTexCoord4fARB");
  glewInfoFunc(glMultiTexCoord4fvARB == NULL, "glMultiTexCoord4fvARB");
  glewInfoFunc(glMultiTexCoord4iARB == NULL, "glMultiTexCoord4iARB");
  glewInfoFunc(glMultiTexCoord4ivARB == NULL, "glMultiTexCoord4ivARB");
  glewInfoFunc(glMultiTexCoord4sARB == NULL, "glMultiTexCoord4sARB");
  glewInfoFunc(glMultiTexCoord4svARB == NULL, "glMultiTexCoord4svARB");
}
#endif /* GL_ARB_multitexture */

/* ------------------------- ARB_point_parameters ------------------------- */

#ifdef GL_ARB_point_parameters
static void glewInfo_ARB_point_parameters ()
{
  char me[] = "GL_ARB_point_parameters"; glewPrintExt(me, glew.ARB_point_parameters);
  glewInfoFunc(glPointParameterfARB == NULL, "glPointParameterfARB");
  glewInfoFunc(glPointParameterfvARB == NULL, "glPointParameterfvARB");
}
#endif /* GL_ARB_point_parameters */

/* ------------------------ ARB_texture_compression ----------------------- */

#ifdef GL_ARB_texture_compression
static void glewInfo_ARB_texture_compression ()
{
  char me[] = "GL_ARB_texture_compression"; glewPrintExt(me, glew.ARB_texture_compression);
  glewInfoFunc(glCompressedTexImage3DARB == NULL, "glCompressedTexImage3DARB");
  glewInfoFunc(glCompressedTexImage2DARB == NULL, "glCompressedTexImage2DARB");
  glewInfoFunc(glCompressedTexImage1DARB == NULL, "glCompressedTexImage1DARB");
  glewInfoFunc(glCompressedTexSubImage3DARB == NULL, "glCompressedTexSubImage3DARB");
  glewInfoFunc(glCompressedTexSubImage2DARB == NULL, "glCompressedTexSubImage2DARB");
  glewInfoFunc(glCompressedTexSubImage1DARB == NULL, "glCompressedTexSubImage1DARB");
  glewInfoFunc(glGetCompressedTexImageARB == NULL, "glGetCompressedTexImageARB");
}
#endif /* GL_ARB_texture_compression */

/* ------------------------- ARB_transpose_matrix ------------------------- */

#ifdef GL_ARB_transpose_matrix
static void glewInfo_ARB_transpose_matrix ()
{
  char me[] = "GL_ARB_transpose_matrix"; glewPrintExt(me, glew.ARB_transpose_matrix);
  glewInfoFunc(glLoadTransposeMatrixfARB == NULL, "glLoadTransposeMatrixfARB");
  glewInfoFunc(glLoadTransposeMatrixdARB == NULL, "glLoadTransposeMatrixdARB");
  glewInfoFunc(glMultTransposeMatrixfARB == NULL, "glMultTransposeMatrixfARB");
  glewInfoFunc(glMultTransposeMatrixdARB == NULL, "glMultTransposeMatrixdARB");
}
#endif /* GL_ARB_transpose_matrix */

/* --------------------------- ARB_vertex_blend --------------------------- */

#ifdef GL_ARB_vertex_blend
static void glewInfo_ARB_vertex_blend ()
{
  char me[] = "GL_ARB_vertex_blend"; glewPrintExt(me, glew.ARB_vertex_blend);
  glewInfoFunc(glWeightbvARB == NULL, "glWeightbvARB");
  glewInfoFunc(glWeightsvARB == NULL, "glWeightsvARB");
  glewInfoFunc(glWeightivARB == NULL, "glWeightivARB");
  glewInfoFunc(glWeightfvARB == NULL, "glWeightfvARB");
  glewInfoFunc(glWeightdvARB == NULL, "glWeightdvARB");
  glewInfoFunc(glWeightubvARB == NULL, "glWeightubvARB");
  glewInfoFunc(glWeightusvARB == NULL, "glWeightusvARB");
  glewInfoFunc(glWeightuivARB == NULL, "glWeightuivARB");
  glewInfoFunc(glWeightPointerARB == NULL, "glWeightPointerARB");
  glewInfoFunc(glVertexBlendARB == NULL, "glVertexBlendARB");
}
#endif /* GL_ARB_vertex_blend */

/* ---------------------- ARB_vertex_buffer_object ------------------------ */

#ifdef GL_ARB_vertex_buffer_object 
static void glewInfo_ARB_vertex_buffer_object ()
{
  char me[] = "GL_ARB_vertex_buffer_object"; glewPrintExt(me, glew.ARB_vertex_buffer_object);
  glewInfoFunc(glBindBufferARB == NULL, "glBindBufferARB");
  glewInfoFunc(glDeleteBuffersARB == NULL, "glDeleteBuffersARB");
  glewInfoFunc(glGenBuffersARB == NULL, "glGenBuffersARB");
  glewInfoFunc(glIsBufferARB == NULL, "glIsBufferARB");
  glewInfoFunc(glBufferDataARB == NULL, "glBufferDataARB");
  glewInfoFunc(glBufferSubDataARB == NULL, "glBufferSubDataARB");
  glewInfoFunc(glGetBufferSubDataARB == NULL, "glGetBufferSubDataARB");
  glewInfoFunc(glMapBufferARB == NULL, "glMapBufferARB");
  glewInfoFunc(glUnmapBufferARB == NULL, "glUnmapBufferARB");
  glewInfoFunc(glGetBufferParameterivARB == NULL, "glGetBufferParameterivARB");
  glewInfoFunc(glGetBufferPointervARB == NULL, "glGetBufferPointervARB");
}
#endif /* GL_ARB_vertex_buffer_object */

/* -------------------------- ARB_vertex_program -------------------------- */

#ifdef GL_ARB_vertex_program
static void glewInfo_ARB_vertex_program ()
{
  char me[] = "GL_ARB_vertex_program"; glewPrintExt(me, glew.ARB_vertex_program);
  glewInfoFunc(glVertexAttrib1sARB == NULL, "glVertexAttrib1sARB");
  glewInfoFunc(glVertexAttrib1fARB == NULL, "glVertexAttrib1fARB");
  glewInfoFunc(glVertexAttrib1dARB == NULL, "glVertexAttrib1dARB");
  glewInfoFunc(glVertexAttrib2sARB == NULL, "glVertexAttrib2sARB");
  glewInfoFunc(glVertexAttrib2fARB == NULL, "glVertexAttrib2fARB");
  glewInfoFunc(glVertexAttrib2dARB == NULL, "glVertexAttrib2dARB");
  glewInfoFunc(glVertexAttrib3sARB == NULL, "glVertexAttrib3sARB");
  glewInfoFunc(glVertexAttrib3fARB == NULL, "glVertexAttrib3fARB");
  glewInfoFunc(glVertexAttrib3dARB == NULL, "glVertexAttrib3dARB");
  glewInfoFunc(glVertexAttrib4sARB == NULL, "glVertexAttrib4sARB");
  glewInfoFunc(glVertexAttrib4fARB == NULL, "glVertexAttrib4fARB");
  glewInfoFunc(glVertexAttrib4dARB == NULL, "glVertexAttrib4dARB");
  glewInfoFunc(glVertexAttrib4NubARB == NULL, "glVertexAttrib4NubARB");
  glewInfoFunc(glVertexAttrib1svARB == NULL, "glVertexAttrib1svARB");
  glewInfoFunc(glVertexAttrib1fvARB == NULL, "glVertexAttrib1fvARB");
  glewInfoFunc(glVertexAttrib1dvARB == NULL, "glVertexAttrib1dvARB");
  glewInfoFunc(glVertexAttrib2svARB == NULL, "glVertexAttrib2svARB");
  glewInfoFunc(glVertexAttrib2fvARB == NULL, "glVertexAttrib2fvARB");
  glewInfoFunc(glVertexAttrib2dvARB == NULL, "glVertexAttrib2dvARB");
  glewInfoFunc(glVertexAttrib3svARB == NULL, "glVertexAttrib3svARB");
  glewInfoFunc(glVertexAttrib3fvARB == NULL, "glVertexAttrib3fvARB");
  glewInfoFunc(glVertexAttrib3dvARB == NULL, "glVertexAttrib3dvARB");
  glewInfoFunc(glVertexAttrib4bvARB == NULL, "glVertexAttrib4bvARB");
  glewInfoFunc(glVertexAttrib4svARB == NULL, "glVertexAttrib4svARB");
  glewInfoFunc(glVertexAttrib4ivARB == NULL, "glVertexAttrib4ivARB");
  glewInfoFunc(glVertexAttrib4ubvARB == NULL, "glVertexAttrib4ubvARB");
  glewInfoFunc(glVertexAttrib4usvARB == NULL, "glVertexAttrib4usvARB");
  glewInfoFunc(glVertexAttrib4uivARB == NULL, "glVertexAttrib4uivARB");
  glewInfoFunc(glVertexAttrib4fvARB == NULL, "glVertexAttrib4fvARB");
  glewInfoFunc(glVertexAttrib4dvARB == NULL, "glVertexAttrib4dvARB");
  glewInfoFunc(glVertexAttrib4NbvARB == NULL, "glVertexAttrib4NbvARB");
  glewInfoFunc(glVertexAttrib4NsvARB == NULL, "glVertexAttrib4NsvARB");
  glewInfoFunc(glVertexAttrib4NivARB == NULL, "glVertexAttrib4NivARB");
  glewInfoFunc(glVertexAttrib4NubvARB == NULL, "glVertexAttrib4NubvARB");
  glewInfoFunc(glVertexAttrib4NusvARB == NULL, "glVertexAttrib4NusvARB");
  glewInfoFunc(glVertexAttrib4NuivARB == NULL, "glVertexAttrib4NuivARB");
  glewInfoFunc(glVertexAttribPointerARB == NULL, "glVertexAttribPointerARB");
  glewInfoFunc(glEnableVertexAttribArrayARB == NULL, "glEnableVertexAttribArrayARB");
  glewInfoFunc(glDisableVertexAttribArrayARB == NULL, "glDisableVertexAttribArrayARB");
  glewInfoFunc(glProgramStringARB == NULL, "glProgramStringARB");
  glewInfoFunc(glBindProgramARB == NULL, "glBindProgramARB");
  glewInfoFunc(glDeleteProgramsARB == NULL, "glDeleteProgramsARB");
  glewInfoFunc(glGenProgramsARB == NULL, "glGenProgramsARB");
  glewInfoFunc(glProgramEnvParameter4dARB == NULL, "glProgramEnvParameter4dARB");
  glewInfoFunc(glProgramEnvParameter4dvARB == NULL, "glProgramEnvParameter4dvARB");
  glewInfoFunc(glProgramEnvParameter4fARB == NULL, "glProgramEnvParameter4fARB");
  glewInfoFunc(glProgramEnvParameter4fvARB == NULL, "glProgramEnvParameter4fvARB");
  glewInfoFunc(glProgramLocalParameter4dARB == NULL, "glProgramLocalParameter4dARB");
  glewInfoFunc(glProgramLocalParameter4dvARB == NULL, "glProgramLocalParameter4dvARB");
  glewInfoFunc(glProgramLocalParameter4fARB == NULL, "glProgramLocalParameter4fARB");
  glewInfoFunc(glProgramLocalParameter4fvARB == NULL, "glProgramLocalParameter4fvARB");
  glewInfoFunc(glGetProgramEnvParameterdvARB == NULL, "glGetProgramEnvParameterdvARB");
  glewInfoFunc(glGetProgramEnvParameterfvARB == NULL, "glGetProgramEnvParameterfvARB");
  glewInfoFunc(glGetProgramLocalParameterdvARB == NULL, "glGetProgramLocalParameterdvARB");
  glewInfoFunc(glGetProgramLocalParameterfvARB == NULL, "glGetProgramLocalParameterfvARB");
  glewInfoFunc(glGetProgramivARB == NULL, "glGetProgramivARB");
  glewInfoFunc(glGetProgramStringARB == NULL, "glGetProgramStringARB");
  glewInfoFunc(glGetVertexAttribdvARB == NULL, "glGetVertexAttribdvARB");
  glewInfoFunc(glGetVertexAttribfvARB == NULL, "glGetVertexAttribfvARB");
  glewInfoFunc(glGetVertexAttribivARB == NULL, "glGetVertexAttribivARB");
  glewInfoFunc(glGetVertexAttribPointervARB == NULL, "glGetVertexAttribPointervARB");
  glewInfoFunc(glIsProgramARB == NULL, "glIsProgramARB");
}
#endif /* GL_ARB_vertex_program */

/* ---------------------------- ARB_window_pos ---------------------------- */

#ifdef GL_ARB_window_pos
static void glewInfo_ARB_window_pos ()
{
  char me[] = "GL_ARB_window_pos"; glewPrintExt(me, glew.ARB_window_pos);
  glewInfoFunc(glWindowPos2dARB == NULL, "glWindowPos2dARB");
  glewInfoFunc(glWindowPos2fARB == NULL, "glWindowPos2fARB");
  glewInfoFunc(glWindowPos2iARB == NULL, "glWindowPos2iARB");
  glewInfoFunc(glWindowPos2sARB == NULL, "glWindowPos2sARB");
  glewInfoFunc(glWindowPos2dvARB == NULL, "glWindowPos2dvARB");
  glewInfoFunc(glWindowPos2fvARB == NULL, "glWindowPos2fvARB");
  glewInfoFunc(glWindowPos2ivARB == NULL, "glWindowPos2ivARB");
  glewInfoFunc(glWindowPos2svARB == NULL, "glWindowPos2svARB");
  glewInfoFunc(glWindowPos3dARB == NULL, "glWindowPos3dARB");
  glewInfoFunc(glWindowPos3fARB == NULL, "glWindowPos3fARB");
  glewInfoFunc(glWindowPos3iARB == NULL, "glWindowPos3iARB");
  glewInfoFunc(glWindowPos3sARB == NULL, "glWindowPos3sARB");
  glewInfoFunc(glWindowPos3dvARB == NULL, "glWindowPos3dvARB");
  glewInfoFunc(glWindowPos3fvARB == NULL, "glWindowPos3fvARB");
  glewInfoFunc(glWindowPos3ivARB == NULL, "glWindowPos3ivARB");
  glewInfoFunc(glWindowPos3svARB == NULL, "glWindowPos3svARB");
}
#endif /* GL_ARB_window_pos */

/* ----------------------------- EXT_blend_color -------------------------- */

#ifdef GL_EXT_blend_color
static void glewInfo_EXT_blend_color ()
{
  char me[] = "GL_EXT_blend_color"; glewPrintExt(me, glew.EXT_blend_color);
  glewInfoFunc(glBlendColorEXT == NULL, "glBlendColorEXT");
}
#endif /* GL_EXT_blend_color */

/* ------------------------ EXT_blend_func_separate ----------------------- */

#ifdef GL_EXT_blend_func_separate
static void glewInfo_EXT_blend_func_separate ()
{
  char me[] = "GL_EXT_blend_func_separate"; glewPrintExt(me, glew.EXT_blend_func_separate);
  glewInfoFunc(glBlendFuncSeparateEXT == NULL, "glBlendFuncSeparateEXT");
}
#endif /* GL_EXT_blend_func_separate */

/* ---------------------------- EXT_blend_minmax -------------------------- */

#ifdef GL_EXT_blend_minmax
static void glewInfo_EXT_blend_minmax ()
{
  char me[] = "GL_EXT_blend_minmax"; glewPrintExt(me, glew.EXT_blend_minmax);
  glewInfoFunc(glBlendEquationEXT == NULL, "glBlendEquationEXT");
}
#endif /* GL_EXT_blend_minmax */

/* ----------------------- EXT_compiled_vertex_array ---------------------- */

#ifdef GL_EXT_compiled_vertex_array
static void glewInfo_EXT_compiled_vertex_array ()
{
  char me[] = "GL_EXT_compiled_vertex_array"; glewPrintExt(me, glew.EXT_compiled_vertex_array);
  glewInfoFunc(glLockArraysEXT == NULL, "glLockArraysEXT");
  glewInfoFunc(glUnlockArraysEXT == NULL, "glUnlockArraysEXT");
}
#endif /* GL_EXT_compiled_vertex_array */

/* ---------------------------- EXT_cull_vertex --------------------------- */

#ifdef GL_EXT_cull_vertex
static void glewInfo_EXT_cull_vertex ()
{
  char me[] = "GL_EXT_cull_vertex"; glewPrintExt(me, glew.EXT_cull_vertex);
  glewInfoFunc(glCullParameterfvEXT == NULL, "glCullParameterfvEXT");
  glewInfoFunc(glCullParameterdvEXT == NULL, "glCullParameterdvEXT");
}
#endif /* GL_EXT_cull_vertex */

/* ------------------------ GL_EXT_depth_bounds_test ---------------------- */

#ifdef GL_EXT_depth_bounds_test
static void glewInfo_EXT_depth_bounds_test ()
{
  char me[] = "GL_EXT_depth_bounds_test"; glewPrintExt(me, glew.EXT_depth_bounds_test);
  glewInfoFunc(glDepthBoundsEXT == NULL, "glDepthBoundsEXT");
}
#endif /* GL_EXT_depth_bounds_test */

/* ------------------------ EXT_draw_range_elements ----------------------- */

#ifdef GL_EXT_draw_range_elements
static void glewInfo_EXT_draw_range_elements ()
{
  char me[] = "GL_EXT_draw_range_elements"; glewPrintExt(me, glew.EXT_draw_range_elements);
  glewInfoFunc(glDrawRangeElementsEXT == NULL, "glDrawRangeElementsEXT");
}
#endif /* GL_EXT_draw_range_elements */

/* ----------------------------- EXT_fog_coord ---------------------------- */

#ifdef GL_EXT_fog_coord
static void glewInfo_EXT_fog_coord ()
{
  char me[] = "GL_EXT_fog_coord"; glewPrintExt(me, glew.EXT_fog_coord);
  glewInfoFunc(glFogCoordfEXT == NULL, "glFogCoordfEXT");
  glewInfoFunc(glFogCoordfvEXT == NULL, "glFogCoordfvEXT");
  glewInfoFunc(glFogCoorddEXT == NULL, "glFogCoorddEXT");
  glewInfoFunc(glFogCoorddvEXT == NULL, "glFogCoorddvEXT");
  glewInfoFunc(glFogCoordPointerEXT == NULL, "glFogCoordPointerEXT");
}
#endif /* GL_EXT_fog_coord */

/* ------------------------- EXT_multi_draw_arrays ------------------------ */

#ifdef GL_EXT_multi_draw_arrays
static void glewInfo_EXT_multi_draw_arrays ()
{
  char me[] = "GL_EXT_multi_draw_arrays"; glewPrintExt(me, glew.EXT_multi_draw_arrays);
  glewInfoFunc(glMultiDrawArraysEXT == NULL, "glMultiDrawArraysEXT");
  glewInfoFunc(glMultiDrawElementsEXT == NULL, "glMultiDrawElementsEXT");
}
#endif /* GL_EXT_multi_draw_arrays */

/* ------------------------- EXT_point_parameters ------------------------- */

#ifdef GL_EXT_point_parameters
static void glewInfo_EXT_point_parameters ()
{
  char me[] = "GL_EXT_point_parameters"; glewPrintExt(me, glew.EXT_point_parameters);
  glewInfoFunc(glPointParameterfEXT == NULL, "glPointParameterfEXT");
  glewInfoFunc(glPointParameterfvEXT == NULL, "glPointParameterfvEXT");
}
#endif /* GL_EXT_point_parameters */

/* -------------------------- EXT_secondary_color ------------------------- */

#ifdef GL_EXT_secondary_color
static void glewInfo_EXT_secondary_color ()
{
  char me[] = "GL_EXT_secondary_color"; glewPrintExt(me, glew.EXT_secondary_color);
  glewInfoFunc(glSecondaryColor3bEXT == NULL, "glSecondaryColor3bEXT");
  glewInfoFunc(glSecondaryColor3bvEXT == NULL, "glSecondaryColor3bvEXT");
  glewInfoFunc(glSecondaryColor3dEXT == NULL, "glSecondaryColor3dEXT");
  glewInfoFunc(glSecondaryColor3dvEXT == NULL, "glSecondaryColor3dvEXT");
  glewInfoFunc(glSecondaryColor3fEXT == NULL, "glSecondaryColor3fEXT");
  glewInfoFunc(glSecondaryColor3fvEXT == NULL, "glSecondaryColor3fvEXT");
  glewInfoFunc(glSecondaryColor3iEXT == NULL, "glSecondaryColor3iEXT");
  glewInfoFunc(glSecondaryColor3ivEXT == NULL, "glSecondaryColor3ivEXT");
  glewInfoFunc(glSecondaryColor3sEXT == NULL, "glSecondaryColor3sEXT");
  glewInfoFunc(glSecondaryColor3svEXT == NULL, "glSecondaryColor3svEXT");
  glewInfoFunc(glSecondaryColor3ubEXT == NULL, "glSecondaryColor3ubEXT");
  glewInfoFunc(glSecondaryColor3ubvEXT == NULL, "glSecondaryColor3ubvEXT");
  glewInfoFunc(glSecondaryColor3uiEXT == NULL, "glSecondaryColor3uiEXT");
  glewInfoFunc(glSecondaryColor3uivEXT == NULL, "glSecondaryColor3uivEXT");
  glewInfoFunc(glSecondaryColor3usEXT == NULL, "glSecondaryColor3usEXT");
  glewInfoFunc(glSecondaryColor3usvEXT == NULL, "glSecondaryColor3usvEXT");
  glewInfoFunc(glSecondaryColorPointerEXT == NULL, "glSecondaryColorPointerEXT");
}
#endif /* GL_EXT_secondary_color */

/* ------------------------- EXT_stencil_two_side ------------------------- */

#ifdef GL_EXT_stencil_two_side
static void glewInfo_EXT_stencil_two_side ()
{
  char me[] = "GL_EXT_stencil_two_side"; glewPrintExt(me, glew.EXT_stencil_two_side);
  glewInfoFunc(glActiveStencilFaceEXT == NULL, "glActiveStencilFaceEXT");
}
#endif /* GL_EXT_stencil_two_side */

/* ----------------------------- EXT_texture3D ---------------------------- */

#ifdef GL_EXT_texture3D
static void glewInfo_EXT_texture3D ()
{
  char me[] = "GL_EXT_texture3D"; glewPrintExt(me, glew.EXT_texture3D);
  glewInfoFunc(glTexImage3DEXT == NULL, "glTexImage3DEXT");
  glewInfoFunc(glTexSubImage3DEXT == NULL, "glTexSubImage3DEXT");
}
#endif /* GL_EXT_texture3D */

/* --------------------------- EXT_vertex_shader -------------------------- */

#ifdef GL_EXT_vertex_shader
static void glewInfo_EXT_vertex_shader ()
{
  char me[] = "GL_EXT_vertex_shader"; glewPrintExt(me, glew.EXT_vertex_shader);
  glewInfoFunc(glBeginVertexShaderEXT == NULL, "glBeginVertexShaderEXT");
  glewInfoFunc(glEndVertexShaderEXT == NULL, "glEndVertexShaderEXT");
  glewInfoFunc(glBindVertexShaderEXT == NULL, "glBindVertexShaderEXT");
  glewInfoFunc(glGenVertexShadersEXT == NULL, "glGenVertexShadersEXT");
  glewInfoFunc(glDeleteVertexShaderEXT == NULL, "glDeleteVertexShaderEXT");
  glewInfoFunc(glShaderOp1EXT == NULL, "glShaderOp1EXT");
  glewInfoFunc(glShaderOp2EXT == NULL, "glShaderOp2EXT");
  glewInfoFunc(glShaderOp3EXT == NULL, "glShaderOp3EXT");
  glewInfoFunc(glSwizzleEXT == NULL, "glSwizzleEXT");
  glewInfoFunc(glWriteMaskEXT == NULL, "glWriteMaskEXT");
  glewInfoFunc(glInsertComponentEXT == NULL, "glInsertComponentEXT");
  glewInfoFunc(glExtractComponentEXT == NULL, "glExtractComponentEXT");
  glewInfoFunc(glGenSymbolsEXT == NULL, "glGenSymbolsEXT");
  glewInfoFunc(glSetInvariantEXT == NULL, "glSetInvariantEXT");
  glewInfoFunc(glSetLocalConstantEXT == NULL, "glSetLocalConstantEXT");
  glewInfoFunc(glVariantbvEXT == NULL, "glVariantbvEXT");
  glewInfoFunc(glVariantsvEXT == NULL, "glVariantsvEXT");
  glewInfoFunc(glVariantivEXT == NULL, "glVariantivEXT");
  glewInfoFunc(glVariantfvEXT == NULL, "glVariantfvEXT");
  glewInfoFunc(glVariantdvEXT == NULL, "glVariantdvEXT");
  glewInfoFunc(glVariantubvEXT == NULL, "glVariantubvEXT");
  glewInfoFunc(glVariantusvEXT == NULL, "glVariantusvEXT");
  glewInfoFunc(glVariantuivEXT == NULL, "glVariantuivEXT");
  glewInfoFunc(glVariantPointerEXT == NULL, "glVariantPointerEXT");
  glewInfoFunc(glEnableVariantClientStateEXT == NULL, "glEnableVariantClientStateEXT");
  glewInfoFunc(glDisableVariantClientStateEXT == NULL, "glDisableVariantClientStateEXT");
  glewInfoFunc(glBindLightParameterEXT == NULL, "glBindLightParameterEXT");
  glewInfoFunc(glBindMaterialParameterEXT == NULL, "glBindMaterialParameterEXT");
  glewInfoFunc(glBindTexGenParameterEXT == NULL, "glBindTexGenParameterEXT");
  glewInfoFunc(glBindTextureUnitParameterEXT == NULL, "glBindTextureUnitParameterEXT");
  glewInfoFunc(glBindParameterEXT == NULL, "glBindParameterEXT");
  glewInfoFunc(glIsVariantEnabledEXT == NULL, "glIsVariantEnabledEXT");
  glewInfoFunc(glGetVariantBooleanvEXT == NULL, "glGetVariantBooleanvEXT");
  glewInfoFunc(glGetVariantIntegervEXT == NULL, "glGetVariantIntegervEXT");
  glewInfoFunc(glGetVariantFloatvEXT == NULL, "glGetVariantFloatvEXT");
  glewInfoFunc(glGetVariantPointervEXT == NULL, "glGetVariantPointervEXT");
  glewInfoFunc(glGetInvariantBooleanvEXT == NULL, "glGetInvariantBooleanvEXT");
  glewInfoFunc(glGetInvariantIntegervEXT == NULL, "glGetInvariantIntegervEXT");
  glewInfoFunc(glGetInvariantFloatvEXT == NULL, "glGetInvariantFloatvEXT");
  glewInfoFunc(glGetLocalConstantBooleanvEXT == NULL, "glGetLocalConstantBooleanvEXT");
  glewInfoFunc(glGetLocalConstantIntegervEXT == NULL, "glGetLocalConstantIntegervEXT");
  glewInfoFunc(glGetLocalConstantFloatvEXT == NULL, "glGetLocalConstantFloatvEXT");
}
#endif /* GL_EXT_vertex_shader */

/* ------------------------- EXT_vertex_weighting ------------------------- */

#ifdef GL_EXT_vertex_weighting
static void glewInfo_EXT_vertex_weighting ()
{
  char me[] = "GL_EXT_vertex_weighting"; glewPrintExt(me, glew.EXT_vertex_weighting);
  glewInfoFunc(glVertexWeightfEXT == NULL, "glVertexWeightfEXT");
  glewInfoFunc(glVertexWeightfvEXT == NULL, "glVertexWeightfvEXT");
  glewInfoFunc(glVertexWeightPointerEXT == NULL, "glVertexWeightPointerEXT");
}
#endif /* GL_EXT_vertex_weighting */

/* ------------------------------ WIN_swap_hint --------------------------- */

#ifdef GL_WIN_swap_hint
static void glewInfo_WIN_swap_hint ()
{
  char me[] = "GL_WIN_swap_hint"; glewPrintExt(me, glew.WIN_swap_hint);
  glewInfoFunc(glAddSwapHintRectWin == NULL, "glAddSwapHintRectWin");
}
#endif /* GL_WIN_swap_hint */

/* ---------------------------- ATI_draw_buffers -------------------------- */

#ifdef GL_ATI_draw_buffers
static void glewInfo_ATI_draw_buffers ()
{
  char me[] = "GL_ATI_draw_buffers"; glewPrintExt(me, glew.ATI_draw_buffers);
  glewInfoFunc(glDrawBuffersATI == NULL, "glDrawBuffersATI");
}
#endif /* GL_ATI_draw_buffers */

/* --------------------------- ATI_element_array -------------------------- */

#ifdef GL_ATI_element_array
static void glewInfo_ATI_element_array ()
{
  char me[] = "GL_ATI_element_array"; glewPrintExt(me, glew.ATI_element_array);
  glewInfoFunc(glElementPointerATI == NULL, "glElementPointerATI");
  glewInfoFunc(glDrawElementArrayATI == NULL, "glDrawElementArrayATI");
  glewInfoFunc(glDrawRangeElementArrayATI == NULL, "glDrawRangeElementArrayATI");
}
#endif /* GL_ATI_element_array */

/* -------------------------- ATI_envmap_bumpmap -------------------------- */

#ifdef GL_ATI_envmap_bumpmap
static void glewInfo_ATI_envmap_bumpmap ()
{
  char me[] = "GL_ATI_envmap_bumpmap"; glewPrintExt(me, glew.ATI_envmap_bumpmap);
  glewInfoFunc(glTexBumpParameterivATI == NULL, "glTexBumpParameterivATI");
  glewInfoFunc(glTexBumpParameterfvATI == NULL, "glTexBumpParameterfvATI");
  glewInfoFunc(glGetTexBumpParameterivATI == NULL, "glGetTexBumpParameterivATI");
  glewInfoFunc(glGetTexBumpParameterfvATI == NULL, "glGetTexBumpParameterfvATI");
}
#endif /* GL_ATI_envmap_bumpmap */

/* ------------------------- ATI_fragment_shader ------------------------- */

#ifdef GL_ATI_fragment_shader
static void glewInfo_ATI_fragment_shader ()
{
  char me[] = "GL_ATI_fragment_shader"; glewPrintExt(me, glew.ATI_fragment_shader);
  glewInfoFunc(glGenFragmentShadersATI == NULL, "glGenFragmentShadersATI");
  glewInfoFunc(glBindFragmentShaderATI == NULL, "glBindFragmentShaderATI");
  glewInfoFunc(glDeleteFragmentShaderATI == NULL, "glDeleteFragmentShaderATI");
  glewInfoFunc(glBeginFragmentShaderATI == NULL, "glBeginFragmentShaderATI");
  glewInfoFunc(glEndFragmentShaderATI == NULL, "glEndFragmentShaderATI");
  glewInfoFunc(glPassTexCoordATI == NULL, "glPassTexCoordATI");
  glewInfoFunc(glSampleMapATI == NULL, "glSampleMapATI");
  glewInfoFunc(glColorFragmentOp1ATI == NULL, "glColorFragmentOp1ATI");
  glewInfoFunc(glColorFragmentOp2ATI == NULL, "glColorFragmentOp2ATI");
  glewInfoFunc(glColorFragmentOp3ATI == NULL, "glColorFragmentOp3ATI");
  glewInfoFunc(glAlphaFragmentOp1ATI == NULL, "glAlphaFragmentOp1ATI");
  glewInfoFunc(glAlphaFragmentOp2ATI == NULL, "glAlphaFragmentOp2ATI");
  glewInfoFunc(glAlphaFragmentOp3ATI == NULL, "glAlphaFragmentOp3ATI");
  glewInfoFunc(glSetFragmentShaderConstantATI == NULL, "glSetFragmentShaderConstantATI");
}
#endif /* GL_ATI_fragment_shader */

/* ------------------------- ATI_map_object_buffer ------------------------ */

#ifdef GL_ATI_map_object_buffer
static void glewInfo_ATI_map_object_buffer ()
{
  char me[] = "GL_ATI_map_object_buffer"; glewPrintExt(me, glew.ATI_map_object_buffer);
  glewInfoFunc(glMapObjectBufferATI == NULL, "glMapObjectBufferATI");
  glewInfoFunc(glUnmapObjectBufferATI == NULL, "glUnmapObjectBufferATI");
}
#endif /* GL_ATI_map_object_buffer */

/* --------------------------- ATI_pn_triangles --------------------------- */

#ifdef GL_ATI_pn_triangles
static void glewInfo_ATI_pn_triangles ()
{
  char me[] = "GL_ATI_pn_triangles"; glewPrintExt(me, glew.ATI_pn_triangles);
  glewInfoFunc(glPNTrianglesiATI == NULL, "glPNTrianglesiATI");
  glewInfoFunc(glPNTrianglesfATI == NULL, "glPNTrianglesfATI");
}
#endif /* GL_ATI_pn_triangles */

/* -------------------------- ATI_separate_stencil ------------------------ */

#ifdef GL_ATI_separate_stencil
static void glewInfo_ATI_separate_stencil ()
{
  char me[] = "GL_ATI_separate_stencil"; glewPrintExt(me, glew.ATI_separate_stencil);
  glewInfoFunc(glStencilOpSeparateATI == NULL, "glStencilOpSeparateATI");
  glewInfoFunc(glStencilFuncSeparateATI == NULL, "glStencilFuncSeparateATI");
}
#endif /* GL_ATI_separate_stencil */

/* ------------------------ ATI_vertex_array_object ----------------------- */

#ifdef GL_ATI_vertex_array_object
static void glewInfo_ATI_vertex_array_object ()
{
  char me[] = "GL_ATI_vertex_array_object"; glewPrintExt(me, glew.ATI_vertex_array_object);
  glewInfoFunc(glNewObjectBufferATI == NULL, "glNewObjectBufferATI");
  glewInfoFunc(glIsObjectBufferATI == NULL, "glIsObjectBufferATI");
  glewInfoFunc(glUpdateObjectBufferATI == NULL, "glUpdateObjectBufferATI");
  glewInfoFunc(glGetObjectBufferfvATI == NULL, "glGetObjectBufferfvATI");
  glewInfoFunc(glGetObjectBufferivATI == NULL, "glGetObjectBufferivATI");
  glewInfoFunc(glFreeObjectBufferATI == NULL, "glFreeObjectBufferATI");
  glewInfoFunc(glArrayObjectATI == NULL, "glArrayObjectATI");
  glewInfoFunc(glGetArrayObjectfvATI == NULL, "glGetArrayObjectfvATI");
  glewInfoFunc(glGetArrayObjectivATI == NULL, "glGetArrayObjectivATI");
  glewInfoFunc(glVariantArrayObjectATI == NULL, "glVariantArrayObjectATI");
  glewInfoFunc(glGetVariantArrayObjectfvATI == NULL, "glGetVariantArrayObjectfvATI");
  glewInfoFunc(glGetVariantArrayObjectivATI == NULL, "glGetVariantArrayObjectivATI");
}
#endif /* GL_ATI_vertex_array_object */

/* -------------------- ATI_vertex_attrib_array_object -------------------- */

#ifdef GL_ATI_vertex_attrib_array_object
static void glewInfo_ATI_vertex_attrib_array_object ()
{
  char me[] = "GL_ATI_vertex_attrib_array_object"; glewPrintExt(me, glew.ATI_vertex_attrib_array_object);
  glewInfoFunc(glVertexAttribArrayObjectATI == NULL, "glVertexAttribArrayObjectATI");
  glewInfoFunc(glGetVertexAttribArrayObjectfvATI == NULL, "glGetVertexAttribArrayObjectfvATI");
  glewInfoFunc(glGetVertexAttribArrayObjectivATI == NULL, "glGetVertexAttribArrayObjectivATI");
}
#endif /* GL_ATI_vertex_attrib_array_object */

/* -------------------------- ATI_vertex_streams -------------------------- */

#ifdef GL_ATI_vertex_streams 
static void glewInfo_ATI_vertex_streams ()
{
  char me[] = "GL_ATI_vertex_streams"; glewPrintExt(me, glew.ATI_vertex_streams);
  glewInfoFunc(glClientActiveVertexStreamATI == NULL, "glClientActiveVertexStreamATI");
  glewInfoFunc(glVertexBlendEnviATI == NULL, "glVertexBlendEnviATI");
  glewInfoFunc(glVertexBlendEnvfATI == NULL, "glVertexBlendEnvfATI");
  glewInfoFunc(glVertexStream2sATI == NULL, "glVertexStream2sATI");
  glewInfoFunc(glVertexStream2svATI == NULL, "glVertexStream2svATI");
  glewInfoFunc(glVertexStream2iATI == NULL, "glVertexStream2iATI");
  glewInfoFunc(glVertexStream2ivATI == NULL, "glVertexStream2ivATI");
  glewInfoFunc(glVertexStream2fATI == NULL, "glVertexStream2fATI");
  glewInfoFunc(glVertexStream2fvATI == NULL, "glVertexStream2fvATI");
  glewInfoFunc(glVertexStream2dATI == NULL, "glVertexStream2dATI");
  glewInfoFunc(glVertexStream2dvATI == NULL, "glVertexStream2dvATI");
  glewInfoFunc(glVertexStream3sATI == NULL, "glVertexStream3sATI");
  glewInfoFunc(glVertexStream3svATI == NULL, "glVertexStream3svATI");
  glewInfoFunc(glVertexStream3iATI == NULL, "glVertexStream3iATI");
  glewInfoFunc(glVertexStream3ivATI == NULL, "glVertexStream3ivATI");
  glewInfoFunc(glVertexStream3fATI == NULL, "glVertexStream3fATI");
  glewInfoFunc(glVertexStream3fvATI == NULL, "glVertexStream3fvATI");
  glewInfoFunc(glVertexStream3dATI == NULL, "glVertexStream3dATI");
  glewInfoFunc(glVertexStream3dvATI == NULL, "glVertexStream3dvATI");
  glewInfoFunc(glVertexStream4sATI == NULL, "glVertexStream4sATI");
  glewInfoFunc(glVertexStream4svATI == NULL, "glVertexStream4svATI");
  glewInfoFunc(glVertexStream4iATI == NULL, "glVertexStream4iATI");
  glewInfoFunc(glVertexStream4ivATI == NULL, "glVertexStream4ivATI");
  glewInfoFunc(glVertexStream4fATI == NULL, "glVertexStream4fATI");
  glewInfoFunc(glVertexStream4fvATI == NULL, "glVertexStream4fvATI");
  glewInfoFunc(glVertexStream4dATI == NULL, "glVertexStream4dATI");
  glewInfoFunc(glVertexStream4dvATI == NULL, "glVertexStream4dvATI");
  glewInfoFunc(glNormalStream3bATI == NULL, "glNormalStream3bATI");
  glewInfoFunc(glNormalStream3bvATI == NULL, "glNormalStream3bvATI");
  glewInfoFunc(glNormalStream3sATI == NULL, "glNormalStream3sATI");
  glewInfoFunc(glNormalStream3svATI == NULL, "glNormalStream3svATI");
  glewInfoFunc(glNormalStream3iATI == NULL, "glNormalStream3iATI");
  glewInfoFunc(glNormalStream3ivATI == NULL, "glNormalStream3ivATI");
  glewInfoFunc(glNormalStream3fATI == NULL, "glNormalStream3fATI");
  glewInfoFunc(glNormalStream3fvATI == NULL, "glNormalStream3fvATI");
  glewInfoFunc(glNormalStream3dATI == NULL, "glNormalStream3dATI");
  glewInfoFunc(glNormalStream3dvATI == NULL, "glNormalStream3dvATI");
}
#endif /* GL_ATI_vertex_streams */

/* --------------------------- NV_element_array --------------------------- */

#ifdef GL_NV_element_array
static void glewInfo_NV_element_array ()
{
  char me[] = "GL_NV_element_array"; glewPrintExt(me, glew.NV_element_array);
  glewInfoFunc(glElementPointerNV == NULL, "glElementPointerNV");
  glewInfoFunc(glDrawElementArrayNV == NULL, "glDrawElementArrayNV");
  glewInfoFunc(glDrawRangeElementArrayNV == NULL, "glDrawRangeElementArrayNV");
  glewInfoFunc(glMultiDrawElementArrayNV == NULL, "glMultiDrawElementArrayNV");
  glewInfoFunc(glMultiDrawRangeElementArrayNV == NULL, "glMultiDrawRangeElementArrayNV");
}
#endif /* GL_NV_element_array */

/* ----------------------------- NV_evaluators ---------------------------- */

#ifdef GL_NV_evaluators
static void glewInfo_NV_evaluators ()
{
  char me[] = "GL_NV_evaluators"; glewPrintExt(me, glew.NV_evaluators);
  glewInfoFunc(glMapControlPointsNV == NULL, "glMapControlPointsNV");
  glewInfoFunc(glMapParameterivNV == NULL, "glMapParameterivNV");
  glewInfoFunc(glMapParameterfvNV == NULL, "glMapParameterfvNV");
  glewInfoFunc(glGetMapControlPointsNV == NULL, "glGetMapControlPointsNV");
  glewInfoFunc(glGetMapParameterivNV == NULL, "glGetMapParameterivNV");
  glewInfoFunc(glGetMapParameterfvNV == NULL, "glGetMapParameterfvNV");
  glewInfoFunc(glGetMapAttribParameterivNV == NULL, "glGetMapAttribParameterivNV");
  glewInfoFunc(glGetMapAttribParameterfvNV == NULL, "glGetMapAttribParameterfvNV");
  glewInfoFunc(glEvalMapsNV == NULL, "glEvalMapsNV");
}
#endif /* GL_NV_evaluators */

/* -------------------------- NV_fragment_program ------------------------- */

#ifdef GL_NV_fragment_program
static void glewInfo_NV_fragment_program ()
{
  char me[] = "GL_NV_fragment_program"; glewPrintExt(me, glew.NV_fragment_program);
  glewInfoFunc(glProgramNamedParameter4fNV == NULL, "glProgramNamedParameter4fNV");
  glewInfoFunc(glProgramNamedParameter4dNV == NULL, "glProgramNamedParameter4dNV");
  glewInfoFunc(glProgramNamedParameter4fvNV == NULL, "glProgramNamedParameter4fvNV");
  glewInfoFunc(glProgramNamedParameter4dvNV == NULL, "glProgramNamedParameter4dvNV");
  glewInfoFunc(glGetProgramNamedParameterfvNV == NULL, "glGetProgramNamedParameterfvNV");
  glewInfoFunc(glGetProgramNamedParameterdvNV == NULL, "glGetProgramNamedParameterdvNV");
#ifndef GL_ARB_vertex_program
  glewInfoFunc(glProgramLocalParameter4dARB == NULL, "glProgramLocalParameter4dARB");
  glewInfoFunc(glProgramLocalParameter4dvARB == NULL, "glProgramLocalParameter4dvARB");
  glewInfoFunc(glProgramLocalParameter4fARB == NULL, "glProgramLocalParameter4fARB");
  glewInfoFunc(glProgramLocalParameter4fvARB == NULL, "glProgramLocalParameter4fvARB");
  glewInfoFunc(glGetProgramLocalParameterdvARB == NULL, "glGetProgramLocalParameterdvARB");
  glewInfoFunc(glGetProgramLocalParameterfvARB == NULL, "glGetProgramLocalParameterfvARB");
#endif /* GL_ARB_vertex_program */
}

#endif /* GL_NV_fragment_program */

/* ------------------------------- NV_fence ------------------------------- */

#ifdef GL_NV_fence
static void glewInfo_NV_fence ()
{
  char me[] = "GL_NV_fence"; glewPrintExt(me, glew.NV_fence);
  glewInfoFunc(glGenFencesNV == NULL, "glGenFencesNV");
  glewInfoFunc(glDeleteFencesNV == NULL, "glDeleteFencesNV");
  glewInfoFunc(glSetFenceNV == NULL, "glSetFenceNV");
  glewInfoFunc(glTestFenceNV == NULL, "glTestFenceNV");
  glewInfoFunc(glFinishFenceNV == NULL, "glFinishFenceNV");
  glewInfoFunc(glIsFenceNV == NULL, "glIsFenceNV");
  glewInfoFunc(glGetFenceivNV == NULL, "glGetFenceivNV");
}
#endif /* GL_NV_fence */

/* ----------------------------- NV_half_float ---------------------------- */

#ifdef GL_NV_half_float
static void glewInfo_NV_half_float ()
{
  char me[] = "GL_NV_half_float"; glewPrintExt(me, glew.NV_half_float);
  glewInfoFunc(glVertex2hNV == NULL, "glVertex2hNV");
  glewInfoFunc(glVertex2hvNV == NULL, "glVertex2hvNV");
  glewInfoFunc(glVertex3hNV == NULL, "glVertex3hNV");
  glewInfoFunc(glVertex3hvNV == NULL, "glVertex3hvNV");
  glewInfoFunc(glVertex4hNV == NULL, "glVertex4hNV");
  glewInfoFunc(glVertex4hvNV == NULL, "glVertex4hvNV");
  glewInfoFunc(glNormal3hNV == NULL, "glNormal3hNV");
  glewInfoFunc(glNormal3hvNV == NULL, "glNormal3hvNV");
  glewInfoFunc(glColor3hNV == NULL, "glColor3hNV");
  glewInfoFunc(glColor3hvNV == NULL, "glColor3hvNV");
  glewInfoFunc(glColor4hNV == NULL, "glColor4hNV");
  glewInfoFunc(glColor4hvNV == NULL, "glColor4hvNV ");
  glewInfoFunc(glTexCoord1hNV == NULL, "glTexCoord1hNV");
  glewInfoFunc(glTexCoord1hvNV == NULL, "glTexCoord1hvNV");
  glewInfoFunc(glTexCoord2hNV == NULL, "glTexCoord2hNV");
  glewInfoFunc(glTexCoord2hvNV == NULL, "glTexCoord2hvNV");
  glewInfoFunc(glTexCoord3hNV == NULL, "glTexCoord3hNV");
  glewInfoFunc(glTexCoord3hvNV == NULL, "glTexCoord3hvNV");
  glewInfoFunc(glTexCoord4hNV == NULL, "glTexCoord4hNV");
  glewInfoFunc(glTexCoord4hvNV == NULL, "glTexCoord4hvNV");
  glewInfoFunc(glMultiTexCoord1hNV == NULL, "glMultiTexCoord1hNV");
  glewInfoFunc(glMultiTexCoord1hvNV == NULL, "glMultiTexCoord1hvNV");
  glewInfoFunc(glMultiTexCoord2hNV == NULL, "glMultiTexCoord2hNV");
  glewInfoFunc(glMultiTexCoord2hvNV == NULL, "glMultiTexCoord2hvNV");
  glewInfoFunc(glMultiTexCoord3hNV == NULL, "glMultiTexCoord3hNV");
  glewInfoFunc(glMultiTexCoord3hvNV == NULL, "glMultiTexCoord3hvNV");
  glewInfoFunc(glMultiTexCoord4hNV == NULL, "glMultiTexCoord4hNV");
  glewInfoFunc(glMultiTexCoord4hvNV == NULL, "glMultiTexCoord4hvNV");
  glewInfoFunc(glFogCoordhNV == NULL, "glFogCoordhNV");
  glewInfoFunc(glFogCoordhvNV == NULL, "glFogCoordhvNV");
  glewInfoFunc(glSecondaryColor3hNV == NULL, "glSecondaryColor3hNV");
  glewInfoFunc(glSecondaryColor3hvNV == NULL, "glSecondaryColor3hvNV");
  glewInfoFunc(glVertexWeighthNV == NULL, "glVertexWeighthNV");
  glewInfoFunc(glVertexWeighthvNV == NULL, "glVertexWeighthvNV");
  glewInfoFunc(glVertexAttrib1hNV == NULL, "glVertexAttrib1hNV");
  glewInfoFunc(glVertexAttrib1hvNV == NULL, "glVertexAttrib1hvNV");
  glewInfoFunc(glVertexAttrib2hNV == NULL, "glVertexAttrib2hNV");
  glewInfoFunc(glVertexAttrib2hvNV == NULL, "glVertexAttrib2hvNV");
  glewInfoFunc(glVertexAttrib3hNV == NULL, "glVertexAttrib3hNV");
  glewInfoFunc(glVertexAttrib3hvNV == NULL, "glVertexAttrib3hvNV");
  glewInfoFunc(glVertexAttrib4hNV == NULL, "glVertexAttrib4hNV");
  glewInfoFunc(glVertexAttrib4hvNV == NULL, "glVertexAttrib4hvNV");
  glewInfoFunc(glVertexAttribs1hvNV == NULL, "glVertexAttribs1hvNV");
  glewInfoFunc(glVertexAttribs2hvNV == NULL, "glVertexAttribs2hvNV");
  glewInfoFunc(glVertexAttribs3hvNV == NULL, "glVertexAttribs3hvNV");
  glewInfoFunc(glVertexAttribs4hvNV == NULL, "glVertexAttribs4hvNV");
}
#endif /* GL_NV_half_float */

/* -------------------------- NV_occlusion_query -------------------------- */

#ifdef GL_NV_occlusion_query
static void glewInfo_NV_occlusion_query ()
{
  char me[] = "GL_NV_occlusion_query"; glewPrintExt(me, glew.NV_occlusion_query);
  glewInfoFunc(glGenOcclusionQueriesNV == NULL, "glGenOcclusionQueriesNV");
  glewInfoFunc(glDeleteOcclusionQueriesNV == NULL, "glDeleteOcclusionQueriesNV");
  glewInfoFunc(glIsOcclusionQueryNV == NULL, "glIsOcclusionQueryNV");
  glewInfoFunc(glBeginOcclusionQueryNV == NULL, "glBeginOcclusionQueryNV");
  glewInfoFunc(glEndOcclusionQueryNV == NULL, "glEndOcclusionQueryNV");
  glewInfoFunc(glGetOcclusionQueryivNV == NULL, "glGetOcclusionQueryivNV");
  glewInfoFunc(glGetOcclusionQueryuivNV == NULL, "glGetOcclusionQueryuivNV");
}
#endif /* GL_NV_occlusion_query */

/* -------------------------- NV_pixel_data_range ------------------------- */

#ifdef GL_NV_pixel_data_range
static void glewInfo_NV_pixel_data_range ()
{
  char me[] = "GL_NV_pixel_data_range"; glewPrintExt(me, glew.NV_pixel_data_range);
  glewInfoFunc(glPixelDataRangeNV == NULL, "glPixelDataRangeNV");
  glewInfoFunc(glFlushPixelDataRangeNV == NULL, "glFlushPixelDataRangeNV");
}
#endif /* GL_NV_pixel_data_range */

/* ---------------------------- NV_point_sprite --------------------------- */

#ifdef GL_NV_point_sprite
static void glewInfo_NV_point_sprite ()
{
  char me[] = "GL_NV_point_sprite"; glewPrintExt(me, glew.NV_point_sprite);
  glewInfoFunc(glPointParameteriNV == NULL, "glPointParameteriNV");
  glewInfoFunc(glPointParameterivNV == NULL, "glPointParameterivNV");
}
#endif /* GL_NV_point_sprite */

/* ------------------------- NV_primitive_restart ------------------------- */

#ifdef GL_NV_primitive_restart
static void glewInfo_NV_primitive_restart ()
{
  char me[] = "GL_NV_primitive_restart"; glewPrintExt(me, glew.NV_primitive_restart);
  glewInfoFunc(glPrimitiveRestartNV == NULL, "glPrimitiveRestartNV");
  glewInfoFunc(glPrimitiveRestartIndexNV == NULL, "glPrimitiveRestartIndexNV");
}
#endif /* GL_NV_primitive_restart */

/* ------------------------- NV_register_combiners ------------------------ */

#ifdef GL_NV_register_combiners
static void glewInfo_NV_register_combiners ()
{
  char me[] = "GL_NV_register_combiners"; glewPrintExt(me, glew.NV_register_combiners);
  glewInfoFunc(glCombinerParameterfvNV == NULL, "glCombinerParameterfvNV");
  glewInfoFunc(glCombinerParameterfNV == NULL, "glCombinerParameterfNV");
  glewInfoFunc(glCombinerParameterivNV == NULL, "glCombinerParameterivNV");
  glewInfoFunc(glCombinerParameteriNV == NULL, "glCombinerParameteriNV");
  glewInfoFunc(glCombinerInputNV == NULL, "glCombinerInputNV");
  glewInfoFunc(glCombinerOutputNV == NULL, "glCombinerOutputNV");
  glewInfoFunc(glFinalCombinerInputNV == NULL, "glFinalCombinerInputNV");
  glewInfoFunc(glGetCombinerInputParameterfvNV == NULL, "glGetCombinerInputParameterfvNV");
  glewInfoFunc(glGetCombinerInputParameterivNV == NULL, "glGetCombinerInputParameterivNV");
  glewInfoFunc(glGetCombinerOutputParameterfvNV == NULL, "glGetCombinerOutputParameterfvNV");
  glewInfoFunc(glGetCombinerOutputParameterivNV == NULL, "glGetCombinerOutputParameterivNV");
  glewInfoFunc(glGetFinalCombinerInputParameterfvNV == NULL, "glGetFinalCombinerInputParameterfvNV");
  glewInfoFunc(glGetFinalCombinerInputParameterivNV == NULL, "glGetFinalCombinerInputParameterivNV");
}
#endif /* GL_NV_register_combiners */

/* ------------------------ NV_register_combiners2 ------------------------ */

#ifdef GL_NV_register_combiners2
static void glewInfo_NV_register_combiners2 ()
{
  char me[] = "GL_NV_register_combiners2"; glewPrintExt(me, glew.NV_register_combiners2);
  glewInfoFunc(glCombinerStageParameterfvNV == NULL, "glCombinerStageParameterfvNV");
  glewInfoFunc(glGetCombinerStageParameterfvNV == NULL, "glGetCombinerStageParameterfvNV");
}
#endif /* GL_NV_register_combiners2 */

/* ------------------------- NV_vertex_array_range ------------------------ */

#ifdef GL_NV_vertex_array_range
static void glewInfo_NV_vertex_array_range ()
{
  char me[] = "GL_NV_vertex_array_range"; glewPrintExt(me, glew.NV_vertex_array_range);
  glewInfoFunc(glFlushVertexArrayRangeNV == NULL, "glFlushVertexArrayRangeNV");
  glewInfoFunc(glVertexArrayRangeNV == NULL, "glVertexArrayRangeNV");
}
#endif /* GL_NV_vertex_array_range */

/* --------------------------- NV_vertex_program -------------------------- */

#ifdef GL_NV_vertex_program
static void glewInfo_NV_vertex_program ()
{
  char me[] = "GL_NV_vertex_program"; glewPrintExt(me, glew.NV_vertex_program);
  glewInfoFunc(glBindProgramNV == NULL, "glBindProgramNV");
  glewInfoFunc(glDeleteProgramsNV == NULL, "glDeleteProgramsNV");
  glewInfoFunc(glExecuteProgramNV == NULL, "glExecuteProgramNV");
  glewInfoFunc(glGenProgramsNV == NULL, "glGenProgramsNV");
  glewInfoFunc(glAreProgramsResidentNV == NULL, "glAreProgramsResidentNV");
  glewInfoFunc(glRequestResidentProgramsNV == NULL, "glRequestResidentProgramsNV");
  glewInfoFunc(glGetProgramParameterfvNV == NULL, "glGetProgramParameterfvNV");
  glewInfoFunc(glGetProgramParameterdvNV == NULL, "glGetProgramParameterdvNV");
  glewInfoFunc(glGetProgramivNV == NULL, "glGetProgramivNV");
  glewInfoFunc(glGetProgramStringNV == NULL, "glGetProgramStringNV");
  glewInfoFunc(glGetTrackMatrixivNV == NULL, "glGetTrackMatrixivNV");
  glewInfoFunc(glGetVertexAttribdvNV == NULL, "glGetVertexAttribdvNV");
  glewInfoFunc(glGetVertexAttribfvNV == NULL, "glGetVertexAttribfvNV");
  glewInfoFunc(glGetVertexAttribivNV == NULL, "glGetVertexAttribivNV");
  glewInfoFunc(glGetVertexAttribPointervNV == NULL, "glGetVertexAttribPointervNV");
  glewInfoFunc(glIsProgramNV == NULL, "glIsProgramNV");
  glewInfoFunc(glLoadProgramNV == NULL, "glLoadProgramNV");
  glewInfoFunc(glProgramParameter4fNV == NULL, "glProgramParameter4fNV");
  glewInfoFunc(glProgramParameter4dNV == NULL, "glProgramParameter4dNV");
  glewInfoFunc(glProgramParameter4dvNV == NULL, "glProgramParameter4dvNV");
  glewInfoFunc(glProgramParameter4fvNV == NULL, "glProgramParameter4fvNV");
  glewInfoFunc(glProgramParameters4dvNV == NULL, "glProgramParameters4dvNV");
  glewInfoFunc(glProgramParameters4fvNV == NULL, "glProgramParameters4fvNV");
  glewInfoFunc(glTrackMatrixNV == NULL, "glTrackMatrixNV");
  glewInfoFunc(glVertexAttribPointerNV == NULL, "glVertexAttribPointerNV");
  glewInfoFunc(glVertexAttrib1sNV == NULL, "glVertexAttrib1sNV");
  glewInfoFunc(glVertexAttrib1fNV == NULL, "glVertexAttrib1fNV");
  glewInfoFunc(glVertexAttrib1dNV == NULL, "glVertexAttrib1dNV");
  glewInfoFunc(glVertexAttrib2sNV == NULL, "glVertexAttrib2sNV");
  glewInfoFunc(glVertexAttrib2fNV == NULL, "glVertexAttrib2fNV");
  glewInfoFunc(glVertexAttrib2dNV == NULL, "glVertexAttrib2dNV");
  glewInfoFunc(glVertexAttrib3sNV == NULL, "glVertexAttrib3sNV");
  glewInfoFunc(glVertexAttrib3fNV == NULL, "glVertexAttrib3fNV");
  glewInfoFunc(glVertexAttrib3dNV == NULL, "glVertexAttrib3dNV");
  glewInfoFunc(glVertexAttrib4sNV == NULL, "glVertexAttrib4sNV");
  glewInfoFunc(glVertexAttrib4fNV == NULL, "glVertexAttrib4fNV");
  glewInfoFunc(glVertexAttrib4dNV == NULL, "glVertexAttrib4dNV");
  glewInfoFunc(glVertexAttrib4ubNV == NULL, "glVertexAttrib4ubNV");
  glewInfoFunc(glVertexAttrib1svNV == NULL, "glVertexAttrib1svNV");
  glewInfoFunc(glVertexAttrib1fvNV == NULL, "glVertexAttrib1fvNV");
  glewInfoFunc(glVertexAttrib1dvNV == NULL, "glVertexAttrib1dvNV");
  glewInfoFunc(glVertexAttrib2svNV == NULL, "glVertexAttrib2svNV");
  glewInfoFunc(glVertexAttrib2fvNV == NULL, "glVertexAttrib2fvNV");
  glewInfoFunc(glVertexAttrib2dvNV == NULL, "glVertexAttrib2dvNV");
  glewInfoFunc(glVertexAttrib3svNV == NULL, "glVertexAttrib3svNV");
  glewInfoFunc(glVertexAttrib3fvNV == NULL, "glVertexAttrib3fvNV");
  glewInfoFunc(glVertexAttrib3dvNV == NULL, "glVertexAttrib3dvNV");
  glewInfoFunc(glVertexAttrib4svNV == NULL, "glVertexAttrib4svNV");
  glewInfoFunc(glVertexAttrib4fvNV == NULL, "glVertexAttrib4fvNV");
  glewInfoFunc(glVertexAttrib4dvNV == NULL, "glVertexAttrib4dvNV");
  glewInfoFunc(glVertexAttrib4ubvNV == NULL, "glVertexAttrib4ubvNV");
  glewInfoFunc(glVertexAttribs1svNV == NULL, "glVertexAttribs1svNV");
  glewInfoFunc(glVertexAttribs1fvNV == NULL, "glVertexAttribs1fvNV");
  glewInfoFunc(glVertexAttribs1dvNV == NULL, "glVertexAttribs1dvNV");
  glewInfoFunc(glVertexAttribs2svNV == NULL, "glVertexAttribs2svNV");
  glewInfoFunc(glVertexAttribs2fvNV == NULL, "glVertexAttribs2fvNV");
  glewInfoFunc(glVertexAttribs2dvNV == NULL, "glVertexAttribs2dvNV");
  glewInfoFunc(glVertexAttribs3svNV == NULL, "glVertexAttribs3svNV");
  glewInfoFunc(glVertexAttribs3fvNV == NULL, "glVertexAttribs3fvNV");
  glewInfoFunc(glVertexAttribs3dvNV == NULL, "glVertexAttribs3dvNV");
  glewInfoFunc(glVertexAttribs4svNV == NULL, "glVertexAttribs4svNV");
  glewInfoFunc(glVertexAttribs4fvNV == NULL, "glVertexAttribs4fvNV");
  glewInfoFunc(glVertexAttribs4dvNV == NULL, "glVertexAttribs4dvNV");
  glewInfoFunc(glVertexAttribs4ubvNV == NULL, "glVertexAttribs4ubvNV");
}
#endif /* GL_NV_vertex_program */

#ifdef _WIN32

/* ---------------------------- ARB_buffer_region ------------------------- */

#ifdef WGL_ARB_buffer_region
static void wglewInfo_ARB_buffer_region ()
{
  char me[] = "WGL_ARB_buffer_region"; glewPrintExt(me, wglew.ARB_buffer_region);
  glewInfoFunc(wglCreateBufferRegionARB == NULL, "wglCreateBufferRegionARB");
  glewInfoFunc(wglDeleteBufferRegionARB == NULL, "wglDeleteBufferRegionARB");
  glewInfoFunc(wglSaveBufferRegionARB == NULL, "wglSaveBufferRegionARB");
  glewInfoFunc(wglRestoreBufferRegionARB == NULL, "wglRestoreBufferRegionARB");
}
#endif /* WGL_ARB_buffer_region */

/* -------------------------- ARB_extensions_string ----------------------- */

#ifdef WGL_ARB_extensions_string
static void wglewInfo_ARB_extensions_string ()
{
  char me[] = "WGL_ARB_extensions_string"; glewPrintExt(me, wglew.ARB_extensions_string);
  glewInfoFunc(wglGetExtensionsStringARB == NULL, "wglGetExtensionsStringARB");
}
#endif /* WGL_ARB_extensions_string */

/* -------------------------- ARB_make_current_read ----------------------- */

#ifdef WGL_ARB_make_current_read
static void wglewInfo_ARB_make_current_read ()
{
  char me[] = "WGL_ARB_make_current_read"; glewPrintExt(me, wglew.ARB_make_current_read);
  glewInfoFunc(wglMakeContextCurrentARB == NULL, "wglMakeContextCurrentARB");
  glewInfoFunc(wglGetCurrentReadDCARB == NULL, "wglGetCurrentReadDCARB");
}
#endif /* WGL_ARB_make_current_read */

/* ------------------------------ ARB_pbuffer ----------------------------- */

#ifdef WGL_ARB_pbuffer
static void wglewInfo_ARB_pbuffer ()
{
  char me[] = "WGL_ARB_pbuffer"; glewPrintExt(me, wglew.ARB_pbuffer);
  glewInfoFunc(wglCreatePbufferARB == NULL, "wglCreatePbufferARB");
  glewInfoFunc(wglGetPbufferDCARB == NULL, "wglGetPbufferDCARB");
  glewInfoFunc(wglReleasePbufferDCARB == NULL, "wglReleasePbufferDCARB");
  glewInfoFunc(wglDestroyPbufferARB == NULL, "wglDestroyPbufferARB");
  glewInfoFunc(wglQueryPbufferARB == NULL, "wglQueryPbufferARB");
}
#endif /* WGL_ARB_pbuffer */

/* --------------------------- ARB_pixel_format --------------------------- */

#ifdef WGL_ARB_pixel_format
static void wglewInfo_ARB_pixel_format ()
{
  char me[] = "WGL_ARB_pixel_format"; glewPrintExt(me, wglew.ARB_pixel_format);
  glewInfoFunc(wglGetPixelFormatAttribivARB == NULL, "wglGetPixelFormatAttribivARB");
  glewInfoFunc(wglGetPixelFormatAttribfvARB == NULL, "wglGetPixelFormatAttribfvARB");
  glewInfoFunc(wglChoosePixelFormatARB == NULL, "wglChoosePixelFormatARB");
}
#endif /* WGL_ARB_pixel_format */

/* -------------------------- ARB_render_texture -------------------------- */

#ifdef WGL_ARB_render_texture
static void wglewInfo_ARB_render_texture ()
{
  char me[] = "WGL_ARB_render_texture"; glewPrintExt(me, wglew.ARB_render_texture);
  glewInfoFunc(wglBindTexImageARB == NULL, "wglBindTexImageARB");
  glewInfoFunc(wglReleaseTexImageARB == NULL, "wglReleaseTexImageARB");
  glewInfoFunc(wglSetPbufferAttribARB == NULL, "wglSetPbufferAttribARB");
}
#endif /* WGL_ARB_render_texture */

/* ------------------------- EXT_display_color_table ---------------------- */

#ifdef WGL_EXT_display_color_table
static void wglewInfo_EXT_display_color_table ()
{
  char me[] = "WGL_EXT_display_color_table"; glewPrintExt(me, wglew.EXT_display_color_table);
  glewInfoFunc(wglCreateDisplayColorTableEXT == NULL, "wglCreateDisplayColorTableEXT");
  glewInfoFunc(wglLoadDisplayColorTableEXT == NULL, "wglLoadDisplayColorTableEXT");
  glewInfoFunc(wglBindDisplayColorTableEXT == NULL, "wglBindDisplayColorTableEXT");
  glewInfoFunc(wglDestroyDisplayColorTableEXT == NULL, "wglDestroyDisplayColorTableEXT");
}
#endif /* WGL_EXT_display_color_table */

/* -------------------------- EXT_make_current_read ----------------------- */

#ifdef WGL_EXT_make_current_read
static void wglewInfo_EXT_make_current_read ()
{
  char me[] = "WGL_EXT_make_current_read"; glewPrintExt(me, wglew.EXT_make_current_read);
  glewInfoFunc(wglMakeContextCurrentEXT == NULL, "wglMakeContextCurrentEXT");
  glewInfoFunc(wglGetCurrentReadDCEXT == NULL, "wglGetCurrentReadDCEXT");
}
#endif /* WGL_EXT_make_current_read */

/* ------------------------- EXT_extensions_string ------------------------ */

#ifdef WGL_EXT_extensions_string
static void wglewInfo_EXT_extensions_string ()
{
  char me[] = "WGL_EXT_extensions_string"; glewPrintExt(me, wglew.EXT_extensions_string);
  glewInfoFunc(wglGetExtensionsStringEXT == NULL, "wglGetExtensionsStringEXT");
}
#endif /* WGL_EXT_extensions_string */

/* ----------------------------- EXT_pixel_format ------------------------- */

#ifdef WGL_EXT_pixel_format
static void wglewInfo_EXT_pixel_format ()
{
  char me[] = "WGL_EXT_pixel_format"; glewPrintExt(me, wglew.EXT_pixel_format);
  glewInfoFunc(wglGetPixelFormatAttribivEXT == NULL, "wglGetPixelFormatAttribivEXT");
  glewInfoFunc(wglGetPixelFormatAttribfvEXT == NULL, "wglGetPixelFormatAttribfvEXT");
  glewInfoFunc(wglChoosePixelFormatEXT == NULL, "wglChoosePixelFormatEXT");
}

#endif /* WGL_EXT_pixel_format */

/* ------------------------------- EXT_pbuffer ---------------------------- */

#ifdef WGL_EXT_pbuffer
static void wglewInfo_EXT_pbuffer ()
{
  char me[] = "WGL_EXT_pbuffer"; glewPrintExt(me, wglew.EXT_pbuffer);
  glewInfoFunc(wglCreatePbufferEXT == NULL, "wglCreatePbufferEXT");
  glewInfoFunc(wglGetPbufferDCEXT == NULL, "wglGetPbufferDCEXT");
  glewInfoFunc(wglReleasePbufferDCEXT == NULL, "wglReleasePbufferDCEXT");
  glewInfoFunc(wglDestroyPbufferEXT == NULL, "wglDestroyPbufferEXT");
  glewInfoFunc(wglQueryPbufferEXT == NULL, "wglQueryPbufferEXT");
}

#endif /* WGL_EXT_pbuffer */

/* --------------------------- EXT_swap_control --------------------------- */

#ifdef WGL_EXT_swap_control
static void wglewInfo_EXT_swap_control ()
{
  char me[] = "WGL_EXT_swap_control"; glewPrintExt(me, wglew.EXT_swap_control);
  glewInfoFunc(wglSwapIntervalEXT == NULL, "wglSwapIntervalEXT");
  glewInfoFunc(wglGetSwapIntervalEXT == NULL, "wglGetSwapIntervalEXT");
}
#endif /* WGL_EXT_swap_control */

/* ------------------------ I3D_digital_video_control --------------------- */

#ifdef WGL_I3D_digital_video_control
static void wglewInfo_I3D_digital_video_control ()
{
  char me[] = "WGL_I3D_digital_video_control"; glewPrintExt(me, wglew.I3D_digital_video_control);
  glewInfoFunc(wglGetDigitalVideoParametersI3D == NULL, "wglGetDigitalVideoParametersI3D");
  glewInfoFunc(wglSetDigitalVideoParametersI3D == NULL, "wglSetDigitalVideoParametersI3D");
}
#endif /* WGL_I3D_digital_video_control */

/* -------------------------------- I3D_gamma ----------------------------- */

#ifdef WGL_I3D_gamma
static void wglewInfo_I3D_gamma ()
{
  char me[] = "WGL_I3D_gamma"; glewPrintExt(me, wglew.I3D_gamma);
  glewInfoFunc(wglGetGammaTableParametersI3D == NULL, "wglGetGammaTableParametersI3D");
  glewInfoFunc(wglSetGammaTableParametersI3D == NULL, "wglSetGammaTableParametersI3D");
  glewInfoFunc(wglGetGammaTableI3D == NULL, "wglGetGammaTableI3D");
  glewInfoFunc(wglSetGammaTableI3D == NULL, "wglSetGammaTableI3D");
}
#endif /* WGL_I3D_gamma */

/* ------------------------------- I3D_genlock ---------------------------- */

#ifdef WGL_I3D_genlock
static void wglewInfo_I3D_genlock ()
{
  char me[] = "WGL_I3D_genlock"; glewPrintExt(me, wglew.I3D_genlock);
  glewInfoFunc(wglEnableGenlockI3D == NULL, "wglEnableGenlockI3D");
  glewInfoFunc(wglDisableGenlockI3D == NULL, "wglDisableGenlockI3D");
  glewInfoFunc(wglIsEnabledGenlockI3D == NULL, "wglIsEnabledGenlockI3D");
  glewInfoFunc(wglGenlockSourceI3D == NULL, "wglGenlockSourceI3D");
  glewInfoFunc(wglGetGenlockSourceI3D == NULL, "wglGetGenlockSourceI3D");
  glewInfoFunc(wglGenlockSourceEdgeI3D == NULL, "wglGenlockSourceEdgeI3D");
  glewInfoFunc(wglGetGenlockSourceEdgeI3D == NULL, "wglGetGenlockSourceEdgeI3D");
  glewInfoFunc(wglGenlockSampleRateI3D == NULL, "wglGenlockSampleRateI3D");
  glewInfoFunc(wglGetGenlockSampleRateI3D == NULL, "wglGetGenlockSampleRateI3D");
  glewInfoFunc(wglGenlockSourceDelayI3D == NULL, "wglGenlockSourceDelayI3D");
  glewInfoFunc(wglGetGenlockSourceDelayI3D == NULL, "wglGetGenlockSourceDelayI3D");
  glewInfoFunc(wglQueryGenlockMaxSourceDelayI3D == NULL, "wglQueryGenlockMaxSourceDelayI3D");
}
#endif /* WGL_I3D_genlock */

/* ---------------------------- I3D_image_buffer -------------------------- */

#ifdef WGL_I3D_image_buffer
static void wglewInfo_I3D_image_buffer ()
{
  char me[] = "WGL_I3D_image_buffer"; glewPrintExt(me, wglew.I3D_image_buffer);
  glewInfoFunc(wglCreateImageBufferI3D == NULL, "wglCreateImageBufferI3D");
  glewInfoFunc(wglDestroyImageBufferI3D == NULL, "wglDestroyImageBufferI3D");
  glewInfoFunc(wglAssociateImageBufferEventsI3D == NULL, "wglAssociateImageBufferEventsI3D");
  glewInfoFunc(wglReleaseImageBufferEventsI3D == NULL, "wglReleaseImageBufferEventsI3D");
}
#endif /* WGL_I3D_image_buffer */

/* --------------------------- I3DI3D_swap_frame_usage_swap_frame_lock ------------------------ */

#ifdef WGL_I3D_swap_frame_lock
static void wglewInfo_I3D_swap_frame_lock ()
{
  char me[] = "WGL_I3D_swap_frame_lock"; glewPrintExt(me, wglew.I3D_swap_frame_lock);
  glewInfoFunc(wglEnableFrameLockI3D == NULL, "wglEnableFrameLockI3D");
  glewInfoFunc(wglDisableFrameLockI3D == NULL, "wglDisableFrameLockI3D");
  glewInfoFunc(wglIsEnabledFrameLockI3D == NULL, "wglIsEnabledFrameLockI3D");
  glewInfoFunc(wglQueryFrameLockMasterI3D == NULL, "wglQueryFrameLockMasterI3D");
}
#endif /* WGL_I3D_swap_frame_lock */

/* -------------------------- I3D_swap_frame_usage ------------------------ */

#ifdef WGL_I3D_swap_frame_usage
static void wglewInfo_I3D_swap_frame_usage ()
{
  char me[] = "WGL_I3D_swap_frame_usage"; glewPrintExt(me, wglew.I3D_swap_frame_usage);
  glewInfoFunc(wglGetFrameUsageI3D == NULL, "wglGetFrameUsageI3D");
  glewInfoFunc(wglBeginFrameTrackingI3D == NULL, "wglBeginFrameTrackingI3D");
  glewInfoFunc(wglEndFrameTrackingI3D == NULL, "wglEndFrameTrackingI3D");
  glewInfoFunc(wglQueryFrameTrackingI3D == NULL, "wglQueryFrameTrackingI3D");
}
#endif /* WGL_I3D_swap_frame_usage */

/* ---------------------------- OML_sync_control -------------------------- */

#ifdef WGL_OML_sync_control
static void wglewInfo_OML_sync_control ()
{
  char me[] = "WGL_OML_sync_control"; glewPrintExt(me, wglew.OML_sync_control);
  glewInfoFunc(wglGetSyncValuesOML == NULL, "wglGetSyncValuesOML");
  glewInfoFunc(wglGetMscRateOML == NULL, "wglGetMscRateOML");
  glewInfoFunc(wglSwapBuffersMscOML == NULL, "wglSwapBuffersMscOML");
  glewInfoFunc(wglSwapLayerBuffersMscOML == NULL, "wglSwapLayerBuffersMscOML");
  glewInfoFunc(wglWaitForMscOML == NULL, "wglWaitForMscOML");
  glewInfoFunc(wglWaitForSbcOML == NULL, "wglWaitForSbcOML");
}
#endif /* WGL_OML_sync_control */

/* ------------------------- NV_vertex_array_range ------------------------ */

#ifdef WGL_NV_vertex_array_range
static void wglewInfo_NV_vertex_array_range ()
{
  char me[] = "WGL_NV_vertex_array_range"; glewPrintExt(me, wglew.NV_vertex_array_range);
  glewInfoFunc(wglAllocateMemoryNV == NULL, "wglAllocateMemoryNV");
  glewInfoFunc(wglFreeMemoryNV == NULL, "wglFreeMemoryNV");
}
#endif /* WGL_NV_vertex_array_range */

#else /* _UNIX */

/* -------------------------------- GLX 1.0 ------------------------------- */

#ifdef GLX_VERSION_1_0
static void glxewInfo_10 ()
{
  char me[] = "GLX_10"; glewPrintExt(me, glxew.GLX_10);
#ifdef GLEW_PROTOTYPES
  glewInfoFunc(glXQueryExtension == NULL, "glXQueryExtension");
  glewInfoFunc(glXQueryVersion == NULL, "glXQueryVersion");
  glewInfoFunc(glXGetConfig == NULL, "glXGetConfig");
  glewInfoFunc(glXChooseVisual == NULL, "glXChooseVisual");
  glewInfoFunc(glXCreateGLXPixmap == NULL, "glXCreateGLXPixmap");
  glewInfoFunc(glXDestroyGLXPixmap == NULL, "glXDestroyGLXPixmap");
  glewInfoFunc(glXCreateContext == NULL, "glXCreateContext");
  glewInfoFunc(glXDestroyContext == NULL, "glXDestroyContext");
  glewInfoFunc(glXIsDirect == NULL, "glXIsDirect");
  glewInfoFunc(glXCopyContext == NULL, "glXCopyContext");
  glewInfoFunc(glXMakeCurrent == NULL, "glXMakeCurrent");
  glewInfoFunc(glXGetCurrentContext == NULL, "glXGetCurrentContext");
  glewInfoFunc(glXGetCurrentDrawable == NULL, "glXGetCurrentDrawable");
  glewInfoFunc(glXWaitGL == NULL, "glXWaitGL");
  glewInfoFunc(glXWaitX == NULL, "glXWaitX");
  glewInfoFunc(glXSwapBuffers == NULL, "glXSwapBuffers");
  glewInfoFunc(glXUseXFont == NULL, "glXUseXFont");
#endif
}
#endif /* GLX_VERSION_1_0 */

/* -------------------------------- GLX 1.1 ------------------------------- */

#ifdef GLX_VERSION_1_1
static void glxewInfo_11 ()
{
  char me[] = "GLX_11"; glewPrintExt(me, glxew.GLX_11);
#ifdef GLEW_PROTOTYPES
  glewInfoFunc(glXQueryExtensionsString == NULL, "glXQueryExtensionsString");
  glewInfoFunc(glXGetClientString == NULL, "glXGetClientString");
  glewInfoFunc(glXQueryServerString == NULL, "glXQueryServerString");
#endif
}
#endif /* GLX_VERSION_1_1 */

/* -------------------------------- GLX 1.2 ------------------------------- */

#ifdef GLX_VERSION_1_2
static void glxewInfo_12 ()
{
  char me[] = "GLX_12"; glewPrintExt(me, glxew.GLX_12);
  glewInfoFunc(glXGetCurrentDisplay == NULL, "glXGetCurrentDisplay");  
}
#endif /* GLX_VERSION_1_2 */

/* -------------------------------- GLX 1.3 ------------------------------- */

#ifdef GLX_VERSION_1_3
static void glxewInfo_13 ()
{
  char me[] = "GLX_13"; glewPrintExt(me, glxew.GLX_13);
  glewInfoFunc(glXChooseFBConfig == NULL, "glXChooseFBConfig");
  glewInfoFunc(glXGetFBConfigs == NULL, "glXGetFBConfigs");
  glewInfoFunc(glXGetVisualFromFBConfig == NULL, "glXGetVisualFromFBConfig");
  glewInfoFunc(glXGetFBConfigAttrib == NULL, "glXGetFBConfigAttrib");
  glewInfoFunc(glXCreateWindow == NULL, "glXCreateWindow");
  glewInfoFunc(glXDestroyWindow == NULL, "glXDestroyWindow");
  glewInfoFunc(glXCreatePixmap == NULL, "glXCreatePixmap");
  glewInfoFunc(glXDestroyPixmap == NULL, "glXDestroyPixmap");
  glewInfoFunc(glXCreatePbuffer == NULL, "glXCreatePbuffer");
  glewInfoFunc(glXDestroyPbuffer == NULL, "glXDestroyPbuffer");
  glewInfoFunc(glXQueryDrawable == NULL, "glXQueryDrawable");
  glewInfoFunc(glXCreateNewContext == NULL, "glXCreateNewContext");
  glewInfoFunc(glXMakeContextCurrent == NULL, "glXMakeContextCurrent");
  glewInfoFunc(glXGetCurrentReadDrawable == NULL, "glXGetCurrentReadDrawable");
  glewInfoFunc(glXQueryContext == NULL, "glXQueryContext");
  glewInfoFunc(glXSelectEvent == NULL, "glXSelectEvent");
  glewInfoFunc(glXGetSelectedEvent == NULL, "glXGetSelectedEvent");
}
#endif /* GLX_VERSION_1_3 */

/* -------------------------- EXT_import_context -------------------------- */

#ifdef GLX_EXT_import_context
static void glxewInfo_EXT_import_context ()
{
  char me[] = "GLX_EXT_import_context"; glewPrintExt(me, glxew.EXT_import_context);
  glewInfoFunc(glXGetCurrentDisplayEXT == NULL, "glXGetCurrentDisplayEXT");
  glewInfoFunc(glXQueryContextInfoEXT == NULL, "glXQueryContextInfoEXT");
  glewInfoFunc(glXGetContextIDEXT == NULL, "glXGetContextIDEXT");
  glewInfoFunc(glXImportContextEXT == NULL, "glXImportContextEXT");
  glewInfoFunc(glXFreeContextEXT == NULL, "glXFreeContextEXT");
}
#endif /* GLX_EXT_import_context */

/* -------------------------- MESA_copy_sub_buffer ------------------------ */

#ifdef GLX_MESA_copy_sub_buffer
static void glxewInfo_MESA_copy_sub_buffer ()
{
  char me[] = "GLX_MESA_copy_sub_buffer"; glewPrintExt(me, glxew.MESA_copy_sub_buffer);
  glewInfoFunc(glXCopySubBufferMESA == NULL, "glXCopySubBufferMESA");
}
#endif /* GLX_MESA_copy_sub_buffer */

/* -------------------------- MESA_pixmap_colormap ------------------------ */

#ifdef GLX_MESA_pixmap_colormap
static void glxewInfo_MESA_pixmap_colormap ()
{
  char me[] = "GLX_MESA_pixmap_colormap"; glewPrintExt(me, glxew.MESA_pixmap_colormap);
  glewInfoFunc(glXCreateGLXPixmapMESA == NULL, "glXCreateGLXPixmapMESA");
}
#endif /* GLX_MESA_pixmap_colormap */

/* -------------------------- MESA_release_buffers ------------------------ */

#ifdef GLX_MESA_release_buffers
static void glxewInfo_MESA_release_buffers ()
{
  char me[] = "GLX_MESA_release_buffers"; glewPrintExt(me, glxew.MESA_release_buffers);
  glewInfoFunc(glXReleaseBuffersMESA == NULL, "glXReleaseBuffersMESA");
}
#endif /* GLX_MESA_release_buffers */

/* --------------------------- MESA_set_3dfx_mode ------------------------- */

#ifdef GLX_MESA_set_3dfx_mode
static void glxewInfo_MESA_set_3dfx_mode ()
{
  char me[] = "GLX_MESA_set_3dfx_mode"; glewPrintExt(me, glxew.MESA_set_3dfx_mode);
  glewInfoFunc(glXSet3DfxModeMESA == NULL, "glXSet3DfxModeMESA");
}
#endif /* GLX_MESA_set_3dfx_mode */

/* ------------------------- NV_vertex_array_range ------------------------ */

#ifdef GLX_NV_vertex_array_range
static void glxewInfo_NV_vertex_array_range ()
{
  char me[] = "GLX_NV_vertex_array_range"; glewPrintExt(me, glxew.NV_vertex_array_range);
  glewInfoFunc(glXAllocateMemoryNV == NULL, "glXAllocateMemoryNV");
  glewInfoFunc(glXFreeMemoryNV == NULL, "glXFreeMemoryNV");
}
#endif /* GLX_NV_vertex_array_range */

/* ---------------------------- OML_sync_control -------------------------- */

#ifdef GLX_OML_sync_control
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
static void glxewInfo_OML_sync_control ()
{
  char me[] = "GLX_OML_sync_control"; glewPrintExt(me, glxew.OML_sync_control);
  glewInfoFunc(glXGetSyncValuesOML == NULL, "glXGetSyncValuesOML");
  glewInfoFunc(glXGetMscRateOML == NULL, "glXGetMscRateOML");
  glewInfoFunc(glXSwapBuffersMscOML == NULL, "glXSwapBuffersMscOML");
  glewInfoFunc(glXWaitForMscOML == NULL, "glXWaitForMscOML");
  glewInfoFunc(glXWaitForSbcOML == NULL, "glXWaitForSbcOML");
}
#endif /* __STDC_VERSION__ */
#endif /* GLX_OML_sync_control */

/* ------------------------------- SGI_cushion ---------------------------- */

#ifdef GLX_SGI_cushion
static void glxewInfo_SGI_cushion ()
{
  char me[] = "GLX_SGI_cushion"; glewPrintExt(me, glxew.SGI_cushion);
  glewInfoFunc(glXCushionSGI == NULL, "glXCushionSGI");
}
#endif /* GLX_SGI_cushion */

/* -------------------------- SGI_make_current_read ----------------------- */

#ifdef GLX_SGI_make_current_read
static void glxewInfo_SGI_make_current_read ()
{
  char me[] = "GLX_SGI_make_current_read"; glewPrintExt(me, glxew.SGI_make_current_read);
  glewInfoFunc(glXMakeCurrentReadSGI == NULL, "glXMakeCurrentReadSGI");
  glewInfoFunc(glXGetCurrentReadDrawableSGI == NULL, "glXGetCurrentReadDrawableSGI");
}
#endif /* GLX_SGI_make_current_read */

/* ---------------------------- SGI_swap_control -------------------------- */

#ifdef GLX_SGI_swap_control
static void glxewInfo_SGI_swap_control ()
{
  char me[] = "GLX_SGI_swap_control"; glewPrintExt(me, glxew.SGI_swap_control);
  glewInfoFunc(glXSwapIntervalSGI == NULL, "glXSwapIntervalSGI");
}
#endif /* GLX_SGI_swap_control */

/* ----------------------------- SGI_video_sync --------------------------- */

#ifdef GLX_SGI_video_sync
static void glxewInfo_SGI_video_sync ()
{
  char me[] = "GLX_SGI_video_sync"; glewPrintExt(me, glxew.SGI_video_sync);
  glewInfoFunc(glXGetVideoSyncSGI == NULL, "glXGetVideoSyncSGI");
  glewInfoFunc(glXWaitVideoSyncSGI == NULL, "glXWaitVideoSyncSGI");
  glewInfoFunc(glXGetRefreshRateSGI == NULL, "glXGetRefreshRateSGI");
}
#endif /* GLX_SGI_video_sync */

/* ------------------------------ SGIX_fbconfig --------------------------- */

#ifdef GLX_SGIX_fbconfig
static void glxewInfo_SGIX_fbconfig ()
{
  char me[] = "GLX_SGIX_fbconfig"; glewPrintExt(me, glxew.SGIX_fbconfig);
  glewInfoFunc(glXGetFBConfigAttribSGIX == NULL, "glXGetFBConfigAttribSGIX");
  glewInfoFunc(glXChooseFBConfigSGIX == NULL, "glXChooseFBConfigSGIX");
  glewInfoFunc(glXCreateGLXPixmapWithConfigSGIX == NULL, "glXCreateGLXPixmapWithConfigSGIX");
  glewInfoFunc(glXCreateContextWithConfigSGIX == NULL, "glXCreateContextWithConfigSGIX");
  glewInfoFunc(glXGetVisualFromFBConfigSGIX == NULL, "glXGetVisualFromFBConfigSGIX");
  glewInfoFunc(glXGetFBConfigFromVisualSGIX == NULL, "glXGetFBConfigFromVisualSGIX");
}
#endif /* GLX_SGIX_fbconfig */

/* ------------------------------- SGIX_pbuffer --------------------------- */

#ifdef GLX_SGIX_pbuffer
static void glxewInfo_SGIX_pbuffer ()
{
  char me[] = "GLX_SGIX_pbuffer"; glewPrintExt(me, glxew.SGIX_pbuffer);
  glewInfoFunc(glXCreateGLXPbufferSGIX == NULL, "glXCreateGLXPbufferSGIX");
  glewInfoFunc(glXDestroyGLXPbufferSGIX == NULL, "glXDestroyGLXPbufferSGIX");
  glewInfoFunc(glXQueryGLXPbufferSGIX == NULL, "glXQueryGLXPbufferSGIX");
  glewInfoFunc(glXSelectEventSGIX == NULL, "glXSelectEventSGIX");
  glewInfoFunc(glXGetSelectedEventSGIX == NULL, "glXGetSelectedEventSGIX");
}
#endif /* GLX_SGIX_pbuffer */

/* ---------------------------- SGIX_swap_barrier ------------------------- */

#ifdef GLX_SGIX_swap_barrier
static void glxewInfo_SGIX_swap_barrier ()
{
  char me[] = "GLX_SGIX_swap_barrier"; glewPrintExt(me, glxew.SGIX_swap_barrier);
  glewInfoFunc(glXBindSwapBarrierSGIX == NULL, "glXBindSwapBarrierSGIX");
  glewInfoFunc(glXQueryMaxSwapBarriersSGIX == NULL, "glXQueryMaxSwapBarriersSGIX");
}
#endif /* GLX_SGIX_swap_barrier */

/* ----------------------------- SGIX_swap_group -------------------------- */

#ifdef GLX_SGIX_swap_group
static void glxewInfo_SGIX_swap_group ()
{
  char me[] = "GLX_SGIX_swap_group"; glewPrintExt(me, glxew.SGIX_swap_group);
  glewInfoFunc(glXJoinSwapGroupSGIX == NULL, "glXJoinSwapGroupSGIX");
}
#endif /* GLX_SGIX_swap_group */

/* ------------------------ SUN_get_transparent_index --------------------- */

#ifdef GLX_SUN_get_transparent_index
static void glxewInfo_SUN_get_transparent_index ()
{
  char me[] = "GLX_SUN_get_transparent_index"; glewPrintExt(me, glxew.SUN_get_transparent_index);
  glewInfoFunc(glXGetTransparentIndexSUN == NULL, "glXGetTransparentIndexSUN");
}
#endif /* GLX_SUN_get_transparent_index */

#endif /* _WIN32 */

/* ------------------------------------------------------------------------ */

static void glewInfo ()
{
  /* test core opengl */
#ifdef GL_VERSION_1_1
  glewPrintExt("GL_11", glew.GL_11);
#endif
#ifdef GL_VERSION_1_2
  glewInfo_12();
#endif
#ifdef GL_VERSION_1_3
  glewInfo_13();
#endif
#ifdef GL_VERSION_1_4
  glewInfo_14();
#endif
  /* test extensions */
#ifdef GL_ARB_depth_texture
  glewPrintExt("GL_ARB_depth_texture", glew.ARB_depth_texture);
#endif
#ifdef GL_ARB_fragment_program
  glewPrintExt("GL_ARB_fragment_program", glew.ARB_fragment_program);
#endif
#ifdef GL_ARB_imaging
  glewInfo_ARB_imaging();
#endif
#ifdef GL_ARB_matrix_palette
  glewInfo_ARB_matrix_palette();
#endif
#ifdef GL_ARB_multisample
  glewInfo_ARB_multisample();
#endif
#ifdef GL_ARB_multitexture
  glewInfo_ARB_multitexture();
#endif
#ifdef GL_ARB_point_parameters
  glewInfo_ARB_point_parameters();
#endif
#ifdef GL_ARB_shadow
  glewPrintExt("GL_ARB_shadow", glew.ARB_shadow);
#endif
#ifdef GL_ARB_shadow_ambient
  glewPrintExt("GL_ARB_shadow_ambient", glew.ARB_shadow_ambient);
#endif
#ifdef GL_ARB_texture_border_clamp
  glewPrintExt("GL_ARB_texture_border_clamp", glew.ARB_texture_border_clamp);
#endif
#ifdef GL_ARB_texture_compression
  glewInfo_ARB_texture_compression();
#endif
#ifdef GL_ARB_transpose_matrix
  glewInfo_ARB_transpose_matrix();
#endif
#ifdef GL_ARB_texture_cube_map
  glewPrintExt("GL_ARB_texture_cube_map", glew.ARB_texture_cube_map);
#endif
#ifdef GL_ARB_texture_env_add
  glewPrintExt("GL_ARB_texture_env_add", glew.ARB_texture_env_add);
#endif
#ifdef GL_ARB_texture_env_combine
  glewPrintExt("GL_ARB_texture_env_combine", glew.ARB_texture_env_combine);
#endif
#ifdef GL_ARB_texture_env_crossbar
  glewPrintExt("GL_ARB_texture_env_crossbar", glew.ARB_texture_env_crossbar);
#endif
#ifdef GL_ARB_texture_env_dot3
  glewPrintExt("GL_ARB_texture_env_dot3", glew.ARB_texture_env_dot3);
#endif
#ifdef GL_ARB_texture_mirrored_repeat
  glewPrintExt("GL_ARB_texture_mirrored_repeat", glew.ARB_texture_mirrored_repeat);
#endif
#ifdef GL_ARB_vertex_blend
  glewInfo_ARB_vertex_blend();
#endif
#ifdef GL_ARB_vertex_buffer_object
  glewInfo_ARB_vertex_buffer_object();
#endif
#ifdef GL_ARB_vertex_program
  glewInfo_ARB_vertex_program();
#endif
#ifdef GL_ARB_window_pos
  glewInfo_ARB_window_pos();
#endif

#ifdef GL_EXT_abgr
  glewPrintExt("GL_EXT_abgr", glew.EXT_abgr);
#endif
#ifdef GL_EXT_bgra
  glewPrintExt("GL_EXT_bgra", glew.EXT_bgra);
#endif
#ifdef GL_EXT_blend_color
  glewInfo_EXT_blend_color();
#endif
#ifdef GL_EXT_blend_func_separate
  glewInfo_EXT_blend_func_separate();
#endif
#ifdef GL_EXT_blend_minmax
  glewInfo_EXT_blend_minmax();
#endif
#ifdef GL_EXT_blend_subtract
  glewPrintExt("GL_EXT_blend_subtract", glew.EXT_blend_subtract);
#endif
#ifdef GL_EXT_clip_volume_hint
  glewPrintExt("GL_EXT_clip_volume_hint", glew.EXT_clip_volume_hint);
#endif
#ifdef GL_EXT_compiled_vertex_array
  glewInfo_EXT_compiled_vertex_array();
#endif
#ifdef GL_EXT_cull_vertex
  glewInfo_EXT_cull_vertex();
#endif
#ifdef GL_EXT_depth_bounds_test
  glewInfo_EXT_depth_bounds_test();
#endif
#ifdef GL_EXT_draw_range_elements
  glewInfo_EXT_draw_range_elements();
#endif
#ifdef GL_EXT_fog_coord
  glewInfo_EXT_fog_coord();
#endif
#ifdef GL_EXT_multi_draw_arrays
  glewInfo_EXT_multi_draw_arrays();
#endif
#ifdef GL_EXT_packed_pixels
  glewPrintExt("GL_EXT_packed_pixels", glew.EXT_packed_pixels);
#endif
#ifdef GL_EXT_point_parameters
  glewInfo_EXT_point_parameters();
#endif
#ifdef GL_EXT_secondary_color
  glewInfo_EXT_secondary_color();
#endif
#ifdef GL_EXT_separate_specular_color
  glewPrintExt("GL_EXT_separate_specular_color", glew.EXT_separate_specular_color);
#endif
#ifdef GL_EXT_shadow_funcs
  glewPrintExt("GL_EXT_shadow_funcs", glew.EXT_shadow_funcs);
#endif
#ifdef GL_EXT_stencil_two_side
  glewInfo_EXT_stencil_two_side();
#endif
#ifdef GL_EXT_stencil_wrap
  glewPrintExt("GL_EXT_stencil_two_side", glew.EXT_stencil_wrap);
#endif
#ifdef GL_EXT_texture_compression_s3tc
  glewPrintExt("GL_EXT_texture_compression_s3tc", glew.EXT_texture_compression_s3tc);
#endif
#ifdef GL_EXT_texture_env_combine
  glewPrintExt("GL_EXT_texture_env_combine", glew.EXT_texture_env_combine);
#endif
#ifdef GL_EXT_texture_filter_anisotropic
  glewPrintExt("GL_EXT_texture_filter_anisotropic", glew.EXT_texture_filter_anisotropic);
#endif
#ifdef GL_EXT_texture_lod_bias
  glewPrintExt("GL_EXT_texture_lod_bias", glew.EXT_texture_lod_bias);
#endif
#ifdef GL_EXT_texture_rectangle
  glewPrintExt("GL_EXT_texture_rectangle", glew.EXT_texture_rectangle);
#endif
#ifdef GL_EXT_texture3D
  glewInfo_EXT_texture3D();
#endif
#ifdef GL_EXT_vertex_shader
  glewInfo_EXT_vertex_shader();
#endif
#ifdef GL_EXT_vertex_weighting
  glewInfo_EXT_vertex_weighting();
#endif

#ifdef GL_SGIS_generate_mipmap
  glewPrintExt("GL_SGIS_generate_mipmap", glew.SGIS_generate_mipmap);
#endif
#ifdef GL_SGIS_texture_lod
  glewPrintExt("GL_SGIS_texture_lod", glew.SGIS_texture_lod);
#endif
#ifdef GL_SGIX_depth_texture
  glewPrintExt("GL_SGIX_depth_texture", glew.SGIX_depth_texture);
#endif
#ifdef GL_SGIX_shadow
  glewPrintExt("GL_SGIX_shadow", glew.SGIX_shadow);
#endif

#ifdef GL_HP_occlusion_test
  glewPrintExt("GL_HP_occlusion_test", glew.HP_occlusion_test);
#endif
#ifdef GL_S3_s3tc
  glewPrintExt("GL_S3_s3tc", glew.S3_s3tc);
#endif
#ifdef GL_WIN_swap_hint
  glewInfo_WIN_swap_hint();
#endif

#ifdef GL_ATI_draw_buffers
  glewInfo_ATI_draw_buffers();
#endif
#ifdef GL_ATI_element_array
  glewInfo_ATI_element_array();
#endif
#ifdef GL_ATI_envmap_bumpmap
  glewInfo_ATI_envmap_bumpmap();
#endif
#ifdef GL_ATI_fragment_shader
  glewInfo_ATI_fragment_shader();
#endif
#ifdef GL_ATI_map_object_buffer
  glewInfo_ATI_map_object_buffer();
#endif
#ifdef GL_ATI_mapped_texture
  glewInfo_ATI_mapped_texture();
#endif
#ifdef GL_ATI_pn_triangles
  glewInfo_ATI_pn_triangles();
#endif
#ifdef GL_ATI_separate_stencil
  glewInfo_ATI_separate_stencil();
#endif
#ifdef GL_ATI_text_fragment_shader
  glewPrintExt("GL_ATI_text_fragment_shader", glew.ATI_text_fragment_shader);
#endif
#ifdef GL_ATI_texture_env_combine3
  glewPrintExt("GL_ATI_texture_env_combine3", glew.ATI_texture_env_combine3);
#endif
#ifdef GL_ATI_texture_float
  glewPrintExt("GL_ATI_texture_float", glew.ATI_texture_float);
#endif
#ifdef GL_ATI_texture_mirror_once
  glewPrintExt("GL_ATI_texture_mirror_once", glew.ATI_texture_mirror_once);
#endif
#ifdef GL_ATI_vertex_array_object
  glewInfo_ATI_vertex_array_object();
#endif
#ifdef GL_ATI_vertex_attrib_array_object
  glewInfo_ATI_vertex_attrib_array_object();
#endif
#ifdef GL_ATI_vertex_streams
  glewInfo_ATI_vertex_streams();
#endif
#ifdef GL_ATIX_point_sprites
  glewPrintExt("GL_ATIX_point_sprites", glew.ATIX_point_sprites);
#endif
#ifdef GL_ATIX_texture_env_combine3
  glewPrintExt("GL_ATIX_texture_env_combine3", glew.ATIX_texture_env_combine3);
#endif
#ifdef GL_ATIX_texture_env_route
  glewPrintExt("GL_ATIX_texture_env_route", glew.ATIX_texture_env_route);
#endif
#ifdef GL_ATIX_vertex_shader_output_point_size
  glewPrintExt("GL_ATIX_vertex_shader_output_point_size", glew.ATIX_vertex_shader_output_point_size);
#endif

#ifdef GL_NV_blend_square
  glewPrintExt("GL_NV_blend_square", glew.NV_blend_square);
#endif
#ifdef GL_NV_copy_depth_to_color
  glewPrintExt("GL_NV_copy_depth_to_color", glew.NV_copy_depth_to_color);
#endif
#ifdef GL_NV_depth_clamp
  glewPrintExt("GL_NV_depth_clamp", glew.NV_depth_clamp);
#endif
#ifdef GL_NV_element_array
  glewInfo_NV_element_array();
#endif
#ifdef GL_NV_evaluators
  glewInfo_NV_evaluators();
#endif
#ifdef GL_NV_fence
  glewInfo_NV_fence();
#endif
#ifdef GL_NV_float_buffer
  glewPrintExt("GL_NV_float_buffer", glew.NV_float_buffer);
#endif
#ifdef GL_NV_fog_distance
  glewPrintExt("GL_NV_fog_distance", glew.NV_fog_distance);
#endif
#ifdef GL_NV_fragment_program
  glewInfo_NV_fragment_program();
#endif
#ifdef GL_NV_half_float
  glewInfo_NV_half_float();
#endif
#ifdef GL_NV_light_max_exponent
  glewPrintExt("GL_NV_light_max_exponent", glew.NV_light_max_exponent);
#endif
#ifdef GL_NV_multisample_filter_hint
  glewPrintExt("GL_NV_multisample_filter_hint", glew.NV_multisample_filter_hint);
#endif
#ifdef GL_NV_occlusion_query
  glewInfo_NV_occlusion_query();
#endif
#ifdef GL_NV_packed_depth_stencil
  glewPrintExt("GL_NV_packed_depth_stencil", glew.NV_packed_depth_stencil);
#endif
#ifdef GL_NV_pixel_data_range
  glewInfo_NV_pixel_data_range();
#endif
#ifdef GL_NV_point_sprite
  glewInfo_NV_point_sprite();
#endif
#ifdef GL_NV_primitive_restart
  glewInfo_NV_primitive_restart();
#endif
#ifdef GL_NV_register_combiners
  glewInfo_NV_register_combiners();
#endif
#ifdef GL_NV_register_combiners2
  glewInfo_NV_register_combiners2();
#endif
#ifdef GL_NV_texgen_emboss
  glewPrintExt("GL_NV_texgen_emboss", glew.NV_texgen_emboss);
#endif
#ifdef GL_NV_texgen_reflection
  glewPrintExt("GL_NV_texgen_reflection", glew.NV_texgen_reflection);
#endif
#ifdef GL_NV_texture_compression_vtc
  glewPrintExt("GL_NV_texture_compression_vtc", glew.NV_texture_compression_vtc);
#endif
#ifdef GL_NV_texture_env_combine4
  glewPrintExt("GL_NV_texture_env_combine4", glew.NV_texture_env_combine4);
#endif
#ifdef GL_NV_texture_expand_normal
  glewPrintExt("GL_NV_texture_expand_normal", glew.NV_texture_expand_normal);
#endif
#ifdef GL_NV_texture_rectangle
  glewPrintExt("GL_NV_texture_rectangle", glew.NV_texture_rectangle);
#endif
#ifdef GL_NV_texture_shader
  glewPrintExt("GL_NV_texture_shader", glew.NV_texture_shader);
#endif
#ifdef GL_NV_texture_shader2
  glewPrintExt("GL_NV_texture_shader2", glew.NV_texture_shader2);
#endif
#ifdef GL_NV_texture_shader3
  glewPrintExt("GL_NV_texture_shader3", glew.NV_texture_shader3);
#endif
#ifdef GL_NV_vertex_array_range
  glewInfo_NV_vertex_array_range();
#endif
#ifdef GL_NV_vertex_array_range2
  glewPrintExt("GL_NV_vertex_array_range2", glew.NV_vertex_array_range2);
#endif
#ifdef GL_NV_vertex_program
  glewInfo_NV_vertex_program();
#endif
#ifdef GL_NV_vertex_program1_1
  glewPrintExt("GL_NV_vertex_program1_1", glew.NV_vertex_program1_1);
#endif
#ifdef GL_NV_vertex_program2
  glewPrintExt("GL_NV_vertex_program2", glew.NV_vertex_program2);
#endif
}

/* ------------------------------------------------------------------------ */

#ifdef _WIN32

static void wglewInfo ()
{
#ifdef WGL_ARB_buffer_region
  wglewInfo_ARB_buffer_region();
#endif
#ifdef WGL_ARB_make_current_read
  wglewInfo_ARB_make_current_read();
#endif
#ifdef WGL_ARB_multisample
  glewPrintExt("WGL_ARB_multisample", wglew.ARB_multisample);
#endif   
#ifdef WGL_ARB_pbuffer
  wglewInfo_ARB_pbuffer();
#endif
#ifdef WGL_ARB_pixel_format
  wglewInfo_ARB_pixel_format();
#endif
#ifdef WGL_ARB_render_texture
  wglewInfo_ARB_render_texture();
#endif

#ifdef WGL_EXT_depth_float
  glewPrintExt("WGL_EXT_depth_float", wglew.EXT_depth_float);
#endif
#ifdef WGL_EXT_display_color_table
  wglewInfo_EXT_display_color_table();
#endif
#ifdef WGL_EXT_make_current_read
  wglewInfo_EXT_make_current_read();
#endif
#ifdef WGL_EXT_multisample
  glewPrintExt("WGL_EXT_multisample", wglew.EXT_multisample);
#endif
#ifdef WGL_EXT_pixel_format
  wglewInfo_EXT_pixel_format();
#endif
#ifdef WGL_EXT_pbuffer
  wglewInfo_EXT_pbuffer();
#endif
#ifdef WGL_EXT_swap_control
  wglewInfo_EXT_swap_control();
#endif

#ifdef WGL_I3D_digital_video_control
  wglewInfo_I3D_digital_video_control();
#endif
#ifdef WGL_I3D_gamma
  wglewInfo_I3D_gamma();
#endif
#ifdef WGL_I3D_genlock
  wglewInfo_I3D_genlock();
#endif
#ifdef WGL_I3D_image_buffer
  wglewInfo_I3D_image_buffer();
#endif
#ifdef WGL_I3D_swap_frame_lock
  wglewInfo_I3D_swap_frame_lock();
#endif
#ifdef WGL_I3D_swap_frame_usage
  wglewInfo_I3D_swap_frame_usage();
#endif

#ifdef WGL_OML_sync_control
  wglewInfo_OML_sync_control();
#endif

#ifdef WGL_ATI_pixel_format_float
  glewPrintExt("WGL_ATI_pixel_format_float", wglew.ATI_pixel_format_float);
#endif

#ifdef WGL_NV_float_buffer
  glewPrintExt("WGL_NV_float_buffer", wglew.NV_float_buffer);
#endif
#ifdef WGL_NV_render_depth_texture
  glewPrintExt("WGL_NV_render_depth_texture", wglew.NV_render_depth_texture);
#endif
#ifdef WGL_NV_render_texture_rectangle
  glewPrintExt("WGL_NV_render_texture_rectangle", wglew.NV_render_texture_rectangle);
#endif
#ifdef WGL_NV_vertex_array_range
  wglewInfo_NV_vertex_array_range();
#endif
}

#else /* _UNIX */

static void glxewInfo ()
{
#ifdef GLX_VERSION_1_0
  glxewInfo_10();
#endif
#ifdef GLX_VERSION_1_1
  glxewInfo_11();
#endif
#ifdef GLX_VERSION_1_2
  glxewInfo_12();
#endif
#ifdef GLX_VERSION_1_3
  glxewInfo_13();
#endif
#ifdef GLX_VERSION_1_4
  glewPrintExt("GLX_14", glxew.GLX_14);
#endif

#ifdef GLX_ARB_get_proc_address
  glewPrintExt("GLX_ARB_get_proc_address", glxew.ARB_get_proc_address);
#endif
#ifdef GLX_ARB_multisample
  glewPrintExt("GLX_ARB_multisample", glxew.ARB_multisample);
#endif

#ifdef GLX_EXT_import_context
  glxewInfo_EXT_import_context();
#endif
#ifdef GLX_EXT_visual_info
  glewPrintExt("GLX_EXT_visual_info", glxew.EXT_visual_info);
#endif
#ifdef GLX_EXT_visual_rating
  glewPrintExt("GLX_EXT_visual_rating", glxew.EXT_visual_rating);
#endif

#ifdef GLX_MESA_copy_sub_buffer
  glxewInfo_MESA_copy_sub_buffer();
#endif
#ifdef GLX_MESA_pixmap_colormap
  glxewInfo_MESA_pixmap_colormap();
#endif
#ifdef GLX_MESA_release_buffers
  glxewInfo_MESA_release_buffers();
#endif
#ifdef GLX_MESA_set_3dfx_mode
  glxewInfo_MESA_set_3dfx_mode();
#endif

#ifdef GLX_NV_vertex_array_range
  glxewInfo_NV_vertex_array_range();
#endif

#ifdef GLX_OML_swap_method
  glewPrintExt("GLX_OML_swap_method", glxew.OML_swap_method);
#endif
#ifdef GLX_OML_sync_control
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
  glxewInfo_OML_sync_control();
#endif /* __STDC_VERSION__ */
#endif

#ifdef GLX_SGI_cushion
  glxewInfo_SGI_cushion();
#endif
#ifdef GLX_SGI_make_current_read
  glxewInfo_SGI_make_current_read();
#endif
#ifdef GLX_SGI_swap_control
  glxewInfo_SGI_swap_control();
#endif
#ifdef GLX_SGI_video_sync
  glxewInfo_SGI_video_sync();
#endif

#ifdef GLX_SGIS_blended_overlay
  glewPrintExt("GLX_SGIS_blended_overlay", glxew.SGIS_blended_overlay);
#endif
#ifdef GLX_SGIS_multisample
  glewPrintExt("GLX_SGIS_multisample", glxew.SGIS_multisample);
#endif
#ifdef GLX_SGIS_shared_multisample
  glewPrintExt("GLX_SGIS_shared_multisample", glxew.SGIS_shared_multisample);
#endif

#ifdef GLX_SGIX_fbconfig
  glxewInfo_SGIX_fbconfig();
#endif
#ifdef GLX_SGIX_pbuffer
  glxewInfo_SGIX_pbuffer();
#endif
#ifdef GLX_SGIX_swap_barrier
  glxewInfo_SGIX_swap_barrier();
#endif
#ifdef GLX_SGIX_swap_group
  glxewInfo_SGIX_swap_group();
#endif
#ifdef GLX_SGIX_visual_select_group
  glewPrintExt("GLX_SGIX_visual_select_group", glxew.SGIX_visual_select_group);
#endif

#ifdef GLX_SUN_get_transparent_index
  glxewInfo_SUN_get_transparent_index();
#endif
}

#endif /* _WIN32 */

/* ------------------------------------------------------------------------ */

int main (int argc, char** argv)
{
  GLint err;
  glutInit(&argc, argv);
  glutCreateWindow("GLEW Extension Info");
  glewExperimental = GL_TRUE;
  err = glewInit();
  if (GLEW_OK != err)
  {
    fprintf(stderr, "Error [main]: glewInit failed: %s\n", glewGetErrorString(err));
    return 1;
  }
  f = fopen("glewinfo.txt", "w");
  if (f == NULL) f = stdout;
  fprintf(f, "---------------------------\n");
  fprintf(f, "    GLEW Extension Info\n");
  fprintf(f, "---------------------------\n\n");
  fprintf(f, "Running on a %s from %s\n", 
	  glGetString(GL_RENDERER), glGetString(GL_VENDOR));
  fprintf(f, "OpenGL version %s is supported\n", glGetString(GL_VERSION));
  glewInfo();
#ifdef WIN32
  wglewInfo();
#else
  glxewInfo();
#endif
  if (f != stdout) fclose(f);
  return 0;
}
