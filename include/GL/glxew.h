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

#ifndef __glxew_h__
#define __glxew_h__

#ifdef __glxext_h_
#error glxext.h included before glxew.h
#endif

#define __glxext_h_

#ifndef _WIN32

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xmd.h>
#include <GL/glew.h>

#ifdef __cplusplus
extern "C" {
#endif

/* core GLX */
#define GLX_VERSION_1_0 1
#define GLX_VERSION_1_1 1
#define GLX_VERSION_1_2 1
#define GLX_VERSION_1_3 1
#define GLX_VERSION_1_4 1
/* ARB extensions */
#define GLX_ARB_get_proc_address 1
#define GLX_ARB_multisample 1
/* multi-vendor extensions */
#define GLX_EXT_import_context 1
#define GLX_EXT_visual_info 1
#define GLX_EXT_visual_rating 1
/* MESA extensions */
#define GLX_MESA_copy_sub_buffer 1
#define GLX_MESA_pixmap_colormap 1
#define GLX_MESA_release_buffers 1
#define GLX_MESA_set_3dfx_mode 1
/* NVIDIA extensions */
#define GLX_NV_vertex_array_range 1
/* OML extensions */
#define GLX_OML_swap_method 1
#define GLX_OML_sync_control 1
/* SGI extensions */
#define GLX_SGI_cushion 1
#define GLX_SGI_make_current_read 1
#define GLX_SGI_swap_control 1
#define GLX_SGI_video_sync 1
#define GLX_SGIS_blended_overlay 1
#define GLX_SGIS_multisample 1
#define GLX_SGIS_shared_multisample 1
/* #define GLX_SGIX_dm_buffer 1 */
#define GLX_SGIX_fbconfig 1
#define GLX_SGIX_pbuffer 1
#define GLX_SGIX_swap_group 1
#define GLX_SGIX_swap_barrier 1
/* #define GLX_SGIX_video_source 1*/
/* #define GLX_SGIX_video_resize 1*/
#define GLX_SGIX_visual_select_group 1
/* SUN extensions */
#define GLX_SUN_get_transparent_index 1

/* -------------------------------- GLX 1.0 ------------------------------- */

#ifdef GLX_VERSION_1_0

#define GLX_USE_GL                                              1
#define GLX_BUFFER_SIZE                                         2
#define GLX_LEVEL                                               3
#define GLX_RGBA                                                4
#define GLX_DOUBLEBUFFER                                        5
#define GLX_STEREO                                              6
#define GLX_AUX_BUFFERS                                         7
#define GLX_RED_SIZE                                            8
#define GLX_GREEN_SIZE                                          9
#define GLX_BLUE_SIZE                                           10
#define GLX_ALPHA_SIZE                                          11
#define GLX_DEPTH_SIZE                                          12
#define GLX_STENCIL_SIZE                                        13
#define GLX_ACCUM_RED_SIZE                                      14
#define GLX_ACCUM_GREEN_SIZE                                    15
#define GLX_ACCUM_BLUE_SIZE                                     16
#define GLX_ACCUM_ALPHA_SIZE                                    17
#define GLX_BAD_SCREEN                                          1
#define GLX_BAD_ATTRIBUTE                                       2
#define GLX_NO_EXTENSION                                        3
#define GLX_BAD_VISUAL                                          4
#define GLX_BAD_CONTEXT                                         5
#define GLX_BAD_VALUE                                           6
#define GLX_BAD_ENUM                                            7

typedef XID GLXDrawable;
typedef XID GLXPixmap;
typedef struct __GLXcontextRec *GLXContext;

#ifdef GLEW_PROTOTYPES
typedef Bool ( * PFNGLXQUERYEXTENSIONPROC) (Display *dpy, int *errorBase, int *eventBase);
typedef Bool ( * PFNGLXQUERYVERSIONPROC) (Display *dpy, int *major, int *minor);
typedef int ( * PFNGLXGETCONFIGPROC) (Display *dpy, XVisualInfo *vis, int attrib, int *value);
typedef XVisualInfo* ( * PFNGLXCHOOSEVISUALPROC) (Display *dpy, int screen, int *attribList);
typedef GLXPixmap ( * PFNGLXCREATEGLXPIXMAPPROC) (Display *dpy, XVisualInfo *vis, Pixmap pixmap);
typedef void ( * PFNGLXDESTROYGLXPIXMAPPROC) (Display *dpy, GLXPixmap pix);
typedef GLXContext ( * PFNGLXCREATECONTEXTPROC) (Display *dpy, XVisualInfo *vis, GLXContext shareList, Bool direct);
typedef void ( * PFNGLXDESTROYCONTEXTPROC) (Display *dpy, GLXContext ctx);
typedef Bool ( * PFNGLXISDIRECTPROC) (Display *dpy, GLXContext ctx);
typedef void ( * PFNGLXCOPYCONTEXTPROC) (Display *dpy, GLXContext src, GLXContext dst, GLuint mask);
typedef Bool ( * PFNGLXMAKECURRENTPROC) (Display *dpy, GLXDrawable drawable, GLXContext ctx);
typedef GLXContext ( * PFNGLXGETCURRENTCONTEXTPROC) (void);
typedef GLXDrawable ( * PFNGLXGETCURRENTDRAWABLEPROC) (void);
typedef void ( * PFNGLXWAITGLPROC) (void);
typedef void ( * PFNGLXWAITXPROC) (void);
typedef void ( * PFNGLXSWAPBUFFERSPROC) (Display *dpy, GLXDrawable drawable);
typedef void ( * PFNGLXUSEXFONTPROC) (Font font, int first, int count, int listBase);

extern PFNGLXQUERYEXTENSIONPROC glXQueryExtension;
extern PFNGLXQUERYVERSIONPROC glXQueryVersion;
extern PFNGLXGETCONFIGPROC glXGetConfig;
extern PFNGLXCHOOSEVISUALPROC glXChooseVisual;
extern PFNGLXCREATEGLXPIXMAPPROC glXCreateGLXPixmap;
extern PFNGLXDESTROYGLXPIXMAPPROC glXDestroyGLXPixmap;
extern PFNGLXCREATECONTEXTPROC glXCreateContext;
extern PFNGLXDESTROYCONTEXTPROC glXDestroyContext;
extern PFNGLXISDIRECTPROC glXIsDirect;
extern PFNGLXCOPYCONTEXTPROC glXCopyContext;
extern PFNGLXMAKECURRENTPROC glXMakeCurrent;
extern PFNGLXGETCURRENTCONTEXTPROC glXGetCurrentContext;
extern PFNGLXGETCURRENTDRAWABLEPROC glXGetCurrentDrawable;
extern PFNGLXWAITGLPROC glXWaitGL;
extern PFNGLXWAITXPROC glXWaitX;
extern PFNGLXSWAPBUFFERSPROC glXSwapBuffers;
extern PFNGLXUSEXFONTPROC glXUseXFont;
#else
extern Bool glXQueryExtension (Display *dpy, int *errorBase, int *eventBase);
extern Bool glXQueryVersion (Display *dpy, int *major, int *minor);
extern int glXGetConfig (Display *dpy, XVisualInfo *vis, int attrib, int *value);
extern XVisualInfo* glXChooseVisual (Display *dpy, int screen, int *attribList);
extern GLXPixmap glXCreateGLXPixmap (Display *dpy, XVisualInfo *vis, Pixmap pixmap);
extern void glXDestroyGLXPixmap (Display *dpy, GLXPixmap pix);
extern GLXContext glXCreateContext (Display *dpy, XVisualInfo *vis, GLXContext shareList, Bool direct);
extern void glXDestroyContext (Display *dpy, GLXContext ctx);
extern Bool glXIsDirect (Display *dpy, GLXContext ctx);
extern void glXCopyContext (Display *dpy, GLXContext src, GLXContext dst, GLuint mask);
extern Bool glXMakeCurrent (Display *dpy, GLXDrawable drawable, GLXContext ctx);
extern GLXContext glXGetCurrentContext (void);
extern GLXDrawable glXGetCurrentDrawable (void);
extern void glXWaitGL (void);
extern void glXWaitX (void);
extern void glXSwapBuffers (Display *dpy, GLXDrawable drawable);
extern void glXUseXFont (Font font, int first, int count, int listBase);
#endif

#endif /* GLX_VERSION_1_0 */

/* -------------------------------- GLX 1.1 ------------------------------- */

#ifdef GLX_VERSION_1_1

#define GLX_VENDOR                                              0x1
#define GLX_VERSION                                             0x2
#define GLX_EXTENSIONS                                          0x3

#ifdef GLEW_PROTOTYPES
typedef const char* ( * PFNGLXQUERYEXTENSIONSSTRINGPROC) (Display *dpy, int screen);
typedef const char* ( * PFNGLXGETCLIENTSTRINGPROC) (Display *dpy, int name);
typedef const char* ( * PFNGLXQUERYSERVERSTRINGPROC) (Display *dpy, int screen, int name);

extern PFNGLXQUERYEXTENSIONSSTRINGPROC glXQueryExtensionsString;
extern PFNGLXGETCLIENTSTRINGPROC glXGetClientString;
extern PFNGLXQUERYSERVERSTRINGPROC glXQueryServerString;
#else
extern const char* glXQueryExtensionsString (Display *dpy, int screen);
extern const char* glXGetClientString (Display *dpy, int name);
extern const char* glXQueryServerString (Display *dpy, int screen, int name);
#endif

#endif /* GLX_VERSION_1_1 */

/* -------------------------------- GLX 1.2 ------------------------------- */

#ifdef GLX_VERSION_1_2

typedef Display* ( * PFNGLXGETCURRENTDISPLAYPROC) (void);

extern PFNGLXGETCURRENTDISPLAYPROC glXGetCurrentDisplay;

#endif /* GLX_VERSION_1_2 */

/* -------------------------------- GLX 1.3 ------------------------------- */

#ifdef GLX_VERSION_1_3

#define GLX_WINDOW_BIT                                          0x00000001
#define GLX_PIXMAP_BIT                                          0x00000002
#define GLX_PBUFFER_BIT                                         0x00000004
#define GLX_RGBA_BIT                                            0x00000001
#define GLX_COLOR_INDEX_BIT                                     0x00000002
#define GLX_PBUFFER_CLOBBER_MASK                                0x08000000
#define GLX_FRONT_LEFT_BUFFER_BIT                               0x00000001
#define GLX_FRONT_RIGHT_BUFFER_BIT                              0x00000002
#define GLX_BACK_LEFT_BUFFER_BIT                                0x00000004
#define GLX_BACK_RIGHT_BUFFER_BIT                               0x00000008
#define GLX_AUX_BUFFERS_BIT                                     0x00000010
#define GLX_DEPTH_BUFFER_BIT                                    0x00000020
#define GLX_STENCIL_BUFFER_BIT                                  0x00000040
#define GLX_ACCUM_BUFFER_BIT                                    0x00000080
#define GLX_CONFIG_CAVEAT                                       0x20
#define GLX_X_VISUAL_TYPE                                       0x22
#define GLX_TRANSPARENT_TYPE                                    0x23
#define GLX_TRANSPARENT_INDEX_VALUE                             0x24
#define GLX_TRANSPARENT_RED_VALUE                               0x25
#define GLX_TRANSPARENT_GREEN_VALUE                             0x26
#define GLX_TRANSPARENT_BLUE_VALUE                              0x27
#define GLX_TRANSPARENT_ALPHA_VALUE                             0x28
#define GLX_DONT_CARE                                           0xFFFFFFFF
#define GLX_NONE                                                0x8000
#define GLX_SLOW_CONFIG                                         0x8001
#define GLX_TRUE_COLOR                                          0x8002
#define GLX_DIRECT_COLOR                                        0x8003
#define GLX_PSEUDO_COLOR                                        0x8004
#define GLX_STATIC_COLOR                                        0x8005
#define GLX_GRAY_SCALE                                          0x8006
#define GLX_STATIC_GRAY                                         0x8007
#define GLX_TRANSPARENT_RGB                                     0x8008
#define GLX_TRANSPARENT_INDEX                                   0x8009
#define GLX_VISUAL_ID                                           0x800B
#define GLX_SCREEN                                              0x800C
#define GLX_NON_CONFORMANT_CONFIG                               0x800D
#define GLX_DRAWABLE_TYPE                                       0x8010
#define GLX_RENDER_TYPE                                         0x8011
#define GLX_X_RENDERABLE                                        0x8012
#define GLX_FBCONFIG_ID                                         0x8013
#define GLX_RGBA_TYPE                                           0x8014
#define GLX_COLOR_INDEX_TYPE                                    0x8015
#define GLX_MAX_PBUFFER_WIDTH                                   0x8016
#define GLX_MAX_PBUFFER_HEIGHT                                  0x8017
#define GLX_MAX_PBUFFER_PIXELS                                  0x8018
#define GLX_PRESERVED_CONTENTS                                  0x801B
#define GLX_LARGEST_PBUFFER                                     0x801C
#define GLX_WIDTH                                               0x801D
#define GLX_HEIGHT                                              0x801E
#define GLX_EVENT_MASK                                          0x801F
#define GLX_DAMAGED                                             0x8020
#define GLX_SAVED                                               0x8021
#define GLX_WINDOW                                              0x8022
#define GLX_PBUFFER                                             0x8023
#define GLX_PBUFFER_HEIGHT                                      0x8040
#define GLX_PBUFFER_WIDTH                                       0x8041

typedef XID GLXWindow;
typedef XID GLXPbuffer;
typedef XID GLXFBConfigID;
typedef struct __GLXFBConfigRec *GLXFBConfig;
typedef struct {
  int event_type;
  int draw_type;
  unsigned long serial;
  Bool send_event;
  Display *display;
  GLXDrawable drawable;
  unsigned int buffer_mask;
  unsigned int aux_buffer;
  int x, y;
  int width, height;
  int count;
} GLXPbufferClobberEvent;
typedef union __GLXEvent {
  GLXPbufferClobberEvent glxpbufferclobber;
  long pad[24];
} GLXEvent;                                                                       

typedef GLXFBConfig* ( * PFNGLXCHOOSEFBCONFIGPROC) (Display *dpy, int screen, const int *attrib_list, int *nelements);
typedef GLXFBConfig* ( * PFNGLXGETFBCONFIGSPROC) (Display *dpy, int screen, int *nelements);
typedef XVisualInfo* ( * PFNGLXGETVISUALFROMFBCONFIGPROC) (Display *dpy, GLXFBConfig config);
typedef int ( * PFNGLXGETFBCONFIGATTRIBPROC) (Display *dpy, GLXFBConfig config, int attribute, int *value);
typedef GLXWindow ( * PFNGLXCREATEWINDOWPROC) (Display *dpy, GLXFBConfig config, Window win, const int *attrib_list);
typedef void ( * PFNGLXDESTROYWINDOWPROC) (Display *dpy, GLXWindow win);
typedef GLXPixmap ( * PFNGLXCREATEPIXMAPPROC) (Display *dpy, GLXFBConfig config, Pixmap pixmap, const int *attrib_list);
typedef void ( * PFNGLXDESTROYPIXMAPPROC) (Display *dpy, GLXPixmap pixmap);
typedef GLXPbuffer ( * PFNGLXCREATEPBUFFERPROC) (Display *dpy, GLXFBConfig config, const int *attrib_list);
typedef void ( * PFNGLXDESTROYPBUFFERPROC) (Display *dpy, GLXPbuffer pbuf);
typedef void ( * PFNGLXQUERYDRAWABLEPROC) (Display *dpy, GLXDrawable draw, int attribute, unsigned int *value);
typedef GLXContext ( * PFNGLXCREATENEWCONTEXTPROC) (Display *dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct);
typedef Bool ( * PFNGLXMAKECONTEXTCURRENTPROC) (Display *display, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
typedef GLXDrawable ( * PFNGLXGETCURRENTREADDRAWABLEPROC) (void);
typedef int ( * PFNGLXQUERYCONTEXTPROC) (Display *dpy, GLXContext ctx, int attribute, int *value);
typedef void ( * PFNGLXSELECTEVENTPROC) (Display *dpy, GLXDrawable draw, unsigned long event_mask);
typedef void ( * PFNGLXGETSELECTEDEVENTPROC) (Display *dpy, GLXDrawable draw, unsigned long *event_mask);                                 

extern PFNGLXCHOOSEFBCONFIGPROC glXChooseFBConfig;
extern PFNGLXGETFBCONFIGSPROC glXGetFBConfigs;
extern PFNGLXGETVISUALFROMFBCONFIGPROC glXGetVisualFromFBConfig;
extern PFNGLXGETFBCONFIGATTRIBPROC glXGetFBConfigAttrib;
extern PFNGLXCREATEWINDOWPROC glXCreateWindow;
extern PFNGLXDESTROYWINDOWPROC glXDestroyWindow;
extern PFNGLXCREATEPIXMAPPROC glXCreatePixmap;
extern PFNGLXDESTROYPIXMAPPROC glXDestroyPixmap;
extern PFNGLXCREATEPBUFFERPROC glXCreatePbuffer;
extern PFNGLXDESTROYPBUFFERPROC glXDestroyPbuffer;
extern PFNGLXQUERYDRAWABLEPROC glXQueryDrawable;
extern PFNGLXCREATENEWCONTEXTPROC glXCreateNewContext;
extern PFNGLXMAKECONTEXTCURRENTPROC glXMakeContextCurrent;
extern PFNGLXGETCURRENTREADDRAWABLEPROC glXGetCurrentReadDrawable;
extern PFNGLXQUERYCONTEXTPROC glXQueryContext;
extern PFNGLXSELECTEVENTPROC glXSelectEvent;
extern PFNGLXGETSELECTEDEVENTPROC glXGetSelectedEvent;

#if 0
extern GLXFBConfig* glXChooseFBConfig (Display *dpy, int screen, const int *attrib_list, int *nelements);
extern GLXFBConfig* glXGetFBConfigs (Display *dpy, int screen, int *nelements);
extern XVisualInfo* glXGetVisualFromFBConfig (Display *dpy, GLXFBConfig config);
extern int glXGetFBConfigAttrib (Display *dpy, GLXFBConfig config, int attribute, int *value);
extern GLXWindow glXCreateWindow (Display *dpy, GLXFBConfig config, Window win, const int *attrib_list);
extern void glXDestroyWindow (Display *dpy, GLXWindow win);
extern GLXPixmap glXCreatePixmap (Display *dpy, GLXFBConfig config, Pixmap pixmap, const int *attrib_list);
extern void glXDestroyPixmap (Display *dpy, GLXPixmap pixmap);
extern GLXPbuffer glXCreatePbuffer (Display *dpy, GLXFBConfig config, const int *attrib_list);
extern void glXDestroyPbuffer (Display *dpy, GLXPbuffer pbuf);
extern void glXQueryDrawable (Display *dpy, GLXDrawable draw, int attribute, unsigned int *value);
extern GLXContext glXCreateNewContext (Display *dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct);
extern Bool glXMakeContextCurrent (Display *display, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
extern GLXDrawable glXGetCurrentReadDrawable (void);
extern int glXQueryContext (Display *dpy, GLXContext ctx, int attribute, int *value);
extern void glXSelectEvent (Display *dpy, GLXDrawable draw, unsigned long event_mask);
extern void glXGetSelectedEvent (Display *dpy, GLXDrawable draw, unsigned long *event_mask);                                 
#endif

#endif /* GLX_VERSION_1_3 */

/* -------------------------------- GLX 1.4 ------------------------------- */

#ifdef GLX_VERSION_1_4

#define GLX_SAMPLE_BUFFERS                                      100000
#define GLX_SAMPLES                                             100001

extern void ( * glXGetProcAddress(const GLubyte *procName))(void);

#endif /* GLX_VERSION_1_4 */

/* ------------------------- ARB_get_proc_address ------------------------- */

#ifdef GLX_ARB_get_proc_address

extern void ( * glXGetProcAddressARB(const GLubyte *procName))(void);

#endif /* GLX_ARB_get_proc_address */

/* ---------------------------- ARB_multisample --------------------------- */

#ifdef GLX_ARB_multisample

#define GLX_SAMPLE_BUFFERS_ARB                                  100000
#define GLX_SAMPLES_ARB                                         100001

#endif /* GLX_ARB_multisample */

/* ---------------------------- EXT_visual_info --------------------------- */

#ifdef GLX_EXT_visual_info

#define GLX_X_VISUAL_TYPE_EXT                                   0x22
#define GLX_TRANSPARENT_TYPE_EXT                                0x23
#define GLX_TRANSPARENT_INDEX_VALUE_EXT                         0x24
#define GLX_TRANSPARENT_RED_VALUE_EXT                           0x25
#define GLX_TRANSPARENT_GREEN_VALUE_EXT                         0x26
#define GLX_TRANSPARENT_BLUE_VALUE_EXT                          0x27
#define GLX_TRANSPARENT_ALPHA_VALUE_EXT                         0x28
#define GLX_NONE_EXT                                            0x8000
#define GLX_TRUE_COLOR_EXT                                      0x8002
#define GLX_DIRECT_COLOR_EXT                                    0x8003
#define GLX_PSEUDO_COLOR_EXT                                    0x8004
#define GLX_STATIC_COLOR_EXT                                    0x8005
#define GLX_GRAY_SCALE_EXT                                      0x8006
#define GLX_STATIC_GRAY_EXT                                     0x8007
#define GLX_TRANSPARENT_RGB_EXT                                 0x8008
#define GLX_TRANSPARENT_INDEX_EXT                               0x8009

#endif /* GLX_EXT_visual_info */

/* --------------------------- EXT_visual_rating -------------------------- */

#ifdef GLX_EXT_visual_rating

#define GLX_VISUAL_CAVEAT_EXT                                   0x20
#define GLX_SLOW_VISUAL_EXT                                     0x8001
#define GLX_NON_CONFORMANT_VISUAL_EXT                           0x800D

#endif /* GLX_EXT_visual_rating */

/* --------------------------- EXT_import_context -------------------------- */

#ifdef GLX_EXT_import_context

#define GLX_SHARE_CONTEXT_EXT                                   0x800A
#define GLX_VISUAL_ID_EXT                                       0x800B
#define GLX_SCREEN_EXT                                          0x800C

typedef XID GLXContextID;

typedef Display * ( * PFNGLXGETCURRENTDISPLAYEXTPROC) (void);
typedef int ( * PFNGLXQUERYCONTEXTINFOEXTPROC) (Display *dpy, GLXContext context, int attribute, int *value);
typedef GLXContextID ( * PFNGLXGETCONTEXTIDEXTPROC) (const GLXContext context);
typedef GLXContext ( * PFNGLXIMPORTCONTEXTEXTPROC) (Display *dpy, GLXContextID contextID);
typedef void ( * PFNGLXFREECONTEXTEXTPROC) (Display *dpy, GLXContext context);

extern PFNGLXGETCURRENTDISPLAYEXTPROC glXGetCurrentDisplayEXT;
extern PFNGLXQUERYCONTEXTINFOEXTPROC glXQueryContextInfoEXT;
extern PFNGLXGETCONTEXTIDEXTPROC glXGetContextIDEXT;
extern PFNGLXIMPORTCONTEXTEXTPROC glXImportContextEXT;
extern PFNGLXFREECONTEXTEXTPROC glXFreeContextEXT;

#endif /* GLX_EXT_import_context */

/* --------------------------- MESA_copy_sub_buffer ----------------------- */

#ifdef GLX_MESA_copy_sub_buffer

typedef void ( * PFNGLXCOPYSUBBUFFERMESAPROC) (Display *dpy, GLXDrawable drawable, int x, int y, int width, int height);

extern PFNGLXCOPYSUBBUFFERMESAPROC glXCopySubBufferMESA;

#endif /* GLX_MESA_copy_sub_buffer */

/* -------------------------- MESA_pixmap_colormap ------------------------ */

#ifdef GLX_MESA_pixmap_colormap

typedef GLXPixmap ( * PFNGLXCREATEGLXPIXMAPMESAPROC) (Display *dpy, XVisualInfo *visual, Pixmap pixmap, Colormap cmap);

extern PFNGLXCREATEGLXPIXMAPMESAPROC glXCreateGLXPixmapMESA;

#endif /* GLX_MESA_pixmap_colormap */

/* -------------------------- MESA_release_buffers ------------------------ */

#ifdef GLX_MESA_release_buffers

typedef Bool ( * PFNGLXRELEASEBUFFERSMESAPROC) (Display *dpy, GLXDrawable drawable);

extern PFNGLXRELEASEBUFFERSMESAPROC glXReleaseBuffersMESA;

#endif /* GLX_MESA_release_buffers */

/* --------------------------- MESA_set_3dfx_mode ------------------------- */

#ifdef GLX_MESA_set_3dfx_mode

typedef Bool ( * PFNGLXSET3DFXMODEMESAPROC) (int mode);

extern PFNGLXSET3DFXMODEMESAPROC glXSet3DfxModeMESA;

#endif /* GLX_MESA_set_3dfx_mode */

/* ---------------------------- OML_swap_method --------------------------- */

#ifdef GLX_OML_swap_method

#define GLX_SWAP_METHOD_OML                                     0x8060
#define GLX_SWAP_EXCHANGE_OML                                   0x8061
#define GLX_SWAP_COPY_OML                                       0x8062
#define GLX_SWAP_UNDEFINED_OML                                  0x8063

#endif /* GLX_OML_swap_method */

/* ---------------------------- OML_sync_control -------------------------- */

#ifdef GLX_OML_sync_control

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#include <inttypes.h>
typedef Bool ( * PFNGLXGETSYNCVALUESOMLPROC) (Display *dpy, GLXDrawable drawable, int64_t *ust, int64_t *msc, int64_t *sbc);
typedef Bool ( * PFNGLXGETMSCRATEOMLPROC) (Display *dpy, GLXDrawable drawable, int32_t *numerator, int32_t *denominator);
typedef int64_t ( * PFNGLXSWAPBUFFERSMSCOMLPROC) (Display *dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder);
typedef Bool ( * PFNGLXWAITFORMSCOMLPROC) (Display *dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder, int64_t *ust, int64_t *msc, int64_t *sbc);
typedef Bool ( * PFNGLXWAITFORSBCOMLPROC) (Display *dpy, GLXDrawable drawable, int64_t target_sbc, int64_t *ust, int64_t *msc, int64_t *sbc);

extern PFNGLXGETSYNCVALUESOMLPROC glXGetSyncValuesOML;
extern PFNGLXGETMSCRATEOMLPROC glXGetMscRateOML;
extern PFNGLXSWAPBUFFERSMSCOMLPROC glXSwapBuffersMscOML;
extern PFNGLXWAITFORMSCOMLPROC glXWaitForMscOML;
extern PFNGLXWAITFORSBCOMLPROC glXWaitForSbcOML;
#endif /* __STDC_VERSION__ */

#endif /* GLX_OML_sync_control */

/* ------------------------- NV_vertex_array_range ------------------------ */

#ifdef GLX_NV_vertex_array_range

typedef void * ( * PFNGLXALLOCATEMEMORYNVPROC) (GLsizei size, GLfloat readFrequency, GLfloat writeFrequency, GLfloat priority);
typedef void ( * PFNGLXFREEMEMORYNVPROC) (void *pointer);

extern PFNGLXALLOCATEMEMORYNVPROC glXAllocateMemoryNV;
extern PFNGLXFREEMEMORYNVPROC glXFreeMemoryNV;

#endif /* GLX_NV_vertex_array_range */

/* ------------------------------- SGI_cushion ---------------------------- */

#ifdef GLX_SGI_cushion

typedef void ( * PFNGLXCUSHIONSGIPROC) (Display *dpy, Window window, float cushion);

extern PFNGLXCUSHIONSGIPROC glXCushionSGI;

#endif /* GLX_SGI_cushion */

/* -------------------------- SGI_make_current_read ----------------------- */

#ifdef GLX_SGI_make_current_read

typedef Bool ( * PFNGLXMAKECURRENTREADSGIPROC) (Display *dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
typedef GLXDrawable ( * PFNGLXGETCURRENTREADDRAWABLESGIPROC) (void);

extern PFNGLXMAKECURRENTREADSGIPROC glXMakeCurrentReadSGI;
extern PFNGLXGETCURRENTREADDRAWABLESGIPROC glXGetCurrentReadDrawableSGI;

#endif /* GLX_SGI_make_current_read */

/* ---------------------------- SGI_swap_control -------------------------- */

#ifdef GLX_SGI_swap_control

typedef int ( * PFNGLXSWAPINTERVALSGIPROC) (int interval);

extern PFNGLXSWAPINTERVALSGIPROC glXSwapIntervalSGI;

#endif /* GLX_SGI_swap_control */

/* ----------------------------- SGI_video_sync --------------------------- */

#ifdef GLX_SGI_video_sync

typedef int ( * PFNGLXGETVIDEOSYNCSGIPROC) (unsigned int *count);
typedef int ( * PFNGLXWAITVIDEOSYNCSGIPROC) (int divisor, int remainder, unsigned int *count);
typedef int ( * PFNGLXGETREFRESHRATESGIPROC) (unsigned int *rate);

extern PFNGLXGETVIDEOSYNCSGIPROC glXGetVideoSyncSGI;
extern PFNGLXWAITVIDEOSYNCSGIPROC glXWaitVideoSyncSGI;
extern PFNGLXGETREFRESHRATESGIPROC glXGetRefreshRateSGI;

#endif /* GLX_SGI_video_sync */

/* -------------------------- SGIS_blended_overlay ------------------------ */

#ifdef GLX_SGIS_blended_overlay

#define GLX_BLENDED_RGBA_SGIS                                   0x8025

#endif

/* ---------------------------- SGIS_multisample -------------------------- */

#ifdef GLX_SGIS_multisample

#define GLX_SAMPLE_BUFFERS_SGIS                                 100000
#define GLX_SAMPLES_SGIS                                        100001

#endif

/* ------------------------ SGIS_shared_multisample ----------------------- */

#ifdef GLX_SGIS_shared_multisample

#define GLX_MULTISAMPLE_SUB_RECT_WIDTH_SGIS                     0x8026
#define GLX_MULTISAMPLE_SUB_RECT_HEIGHT_SGIS                    0x8027

#endif

/* ------------------------------ SGIX_fbconfig --------------------------- */

#ifdef GLX_SGIX_fbconfig

#define GLX_WINDOW_BIT_SGIX                                     0x00000001
#define GLX_PIXMAP_BIT_SGIX                                     0x00000002
#define GLX_RGBA_BIT_SGIX                                       0x00000001
#define GLX_COLOR_INDEX_BIT_SGIX                                0x00000002
#define GLX_DRAWABLE_TYPE_SGIX                                  0x8010
#define GLX_RENDER_TYPE_SGIX                                    0x8011
#define GLX_X_RENDERABLE_SGIX                                   0x8012
#define GLX_FBCONFIG_ID_SGIX                                    0x8013
#define GLX_RGBA_TYPE_SGIX                                      0x8014
#define GLX_COLOR_INDEX_TYPE_SGIX                               0x8015

typedef XID GLXFBConfigIDSGIX;
typedef struct __GLXFBConfigRec *GLXFBConfigSGIX;

typedef int ( * PFNGLXGETFBCONFIGATTRIBSGIXPROC) (Display *dpy, GLXFBConfigSGIX config, int attribute, int *value);
typedef GLXFBConfigSGIX * ( * PFNGLXCHOOSEFBCONFIGSGIXPROC) (Display *dpy, int screen, int *attrib_list, int *nelements);
typedef GLXPixmap ( * PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC) (Display *dpy, GLXFBConfigSGIX config, Pixmap pixmap);
typedef GLXContext ( * PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC) (Display *dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct);
typedef XVisualInfo * ( * PFNGLXGETVISUALFROMFBCONFIGSGIXPROC) (Display *dpy, GLXFBConfigSGIX config);
typedef GLXFBConfigSGIX ( * PFNGLXGETFBCONFIGFROMVISUALSGIXPROC) (Display *dpy, XVisualInfo *vis);

extern PFNGLXGETFBCONFIGATTRIBSGIXPROC glXGetFBConfigAttribSGIX;
extern PFNGLXCHOOSEFBCONFIGSGIXPROC glXChooseFBConfigSGIX;
extern PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC glXCreateGLXPixmapWithConfigSGIX;
extern PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC glXCreateContextWithConfigSGIX;
extern PFNGLXGETVISUALFROMFBCONFIGSGIXPROC glXGetVisualFromFBConfigSGIX;
extern PFNGLXGETFBCONFIGFROMVISUALSGIXPROC glXGetFBConfigFromVisualSGIX;

#endif /* GLX_SGIX_fbconfig */

/* ------------------------------- SGIX_pbuffer --------------------------- */

#ifdef GLX_SGIX_pbuffer

#define GLX_PBUFFER_BIT_SGIX                                    0x00000004
#define GLX_BUFFER_CLOBBER_MASK_SGIX                            0x08000000
#define GLX_FRONT_LEFT_BUFFER_BIT_SGIX                          0x00000001
#define GLX_FRONT_RIGHT_BUFFER_BIT_SGIX                         0x00000002
#define GLX_BACK_LEFT_BUFFER_BIT_SGIX                           0x00000004
#define GLX_BACK_RIGHT_BUFFER_BIT_SGIX                          0x00000008
#define GLX_AUX_BUFFERS_BIT_SGIX                                0x00000010
#define GLX_DEPTH_BUFFER_BIT_SGIX                               0x00000020
#define GLX_STENCIL_BUFFER_BIT_SGIX                             0x00000040
#define GLX_ACCUM_BUFFER_BIT_SGIX                               0x00000080
#define GLX_SAMPLE_BUFFERS_BIT_SGIX                             0x00000100
#define GLX_MAX_PBUFFER_WIDTH_SGIX                              0x8016
#define GLX_MAX_PBUFFER_HEIGHT_SGIX                             0x8017
#define GLX_MAX_PBUFFER_PIXELS_SGIX                             0x8018
#define GLX_OPTIMAL_PBUFFER_WIDTH_SGIX                          0x8019
#define GLX_OPTIMAL_PBUFFER_HEIGHT_SGIX                         0x801A
#define GLX_PRESERVED_CONTENTS_SGIX                             0x801B
#define GLX_LARGEST_PBUFFER_SGIX                                0x801C
#define GLX_WIDTH_SGIX                                          0x801D
#define GLX_HEIGHT_SGIX                                         0x801E
#define GLX_EVENT_MASK_SGIX                                     0x801F
#define GLX_DAMAGED_SGIX                                        0x8020
#define GLX_SAVED_SGIX                                          0x8021
#define GLX_WINDOW_SGIX                                         0x8022
#define GLX_PBUFFER_SGIX                                        0x8023

typedef XID GLXPbufferSGIX;
typedef struct {
  int type;
  unsigned long serial;
  Bool send_event;
  Display *display;
  GLXDrawable drawable;
  int event_type;
  int draw_type;
  unsigned int mask;
  int x, y;
  int width, height;
  int count;
} GLXBufferClobberEventSGIX;

typedef GLXPbufferSGIX ( * PFNGLXCREATEGLXPBUFFERSGIXPROC) (Display *dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int *attrib_list);
typedef void ( * PFNGLXDESTROYGLXPBUFFERSGIXPROC) (Display *dpy, GLXPbufferSGIX pbuf);
typedef int ( * PFNGLXQUERYGLXPBUFFERSGIXPROC) (Display *dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int *value);
typedef void ( * PFNGLXSELECTEVENTSGIXPROC) (Display *dpy, GLXDrawable drawable, unsigned long mask);
typedef void ( * PFNGLXGETSELECTEDEVENTSGIXPROC) (Display *dpy, GLXDrawable drawable, unsigned long *mask);

extern PFNGLXCREATEGLXPBUFFERSGIXPROC glXCreateGLXPbufferSGIX;
extern PFNGLXDESTROYGLXPBUFFERSGIXPROC glXDestroyGLXPbufferSGIX;
extern PFNGLXQUERYGLXPBUFFERSGIXPROC glXQueryGLXPbufferSGIX;
extern PFNGLXSELECTEVENTSGIXPROC glXSelectEventSGIX;
extern PFNGLXGETSELECTEDEVENTSGIXPROC glXGetSelectedEventSGIX;

#endif /* GLX_SGIX_pbuffer */

/* ---------------------------- SGIX_swap_barrier ------------------------- */

#ifdef GLX_SGIX_swap_barrier

typedef void ( * PFNGLXBINDSWAPBARRIERSGIXPROC) (Display *dpy, GLXDrawable drawable, int barrier);
typedef Bool ( * PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC) (Display *dpy, int screen, int *max);

extern PFNGLXBINDSWAPBARRIERSGIXPROC glXBindSwapBarrierSGIX;
extern PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC glXQueryMaxSwapBarriersSGIX;

#endif /* GLX_SGIX_swap_barrier */

/* ----------------------------- SGIX_swap_group -------------------------- */

#ifdef GLX_SGIX_swap_group

typedef void ( * PFNGLXJOINSWAPGROUPSGIXPROC) (Display *dpy, GLXDrawable drawable, GLXDrawable member);

extern PFNGLXJOINSWAPGROUPSGIXPROC glXJoinSwapGroupSGIX;

#endif /* GLX_SGIX_swap_group */

/* ------------------------- SGIX_visual_select_group --------------------- */

#ifndef GLX_SGIX_visual_select_group

#define GLX_VISUAL_SELECT_GROUP_SGIX                            0x8028

#endif

/* ------------------------ SUN_get_transparent_index --------------------- */

#ifdef GLX_SUN_get_transparent_index

typedef Status ( * PFNGLXGETTRANSPARENTINDEXSUNPROC) (Display *dpy, Window overlay, Window underlay, long *pTransparentIndex);

extern PFNGLXGETTRANSPARENTINDEXSUNPROC glXGetTransparentIndexSUN;

#endif /* GLX_SUN_get_transparent_index */

/* ------------------------------------------------------------------------ */

struct GLXEW
{
  unsigned int GLX_10 : 1;
  unsigned int GLX_11 : 1;
  unsigned int GLX_12 : 1;
  unsigned int GLX_13 : 1;
  unsigned int GLX_14 : 1;

  unsigned int ARB_get_proc_address : 1;
  unsigned int ARB_multisample : 1;

  unsigned int EXT_import_context : 1;  
  unsigned int EXT_visual_info : 1;  
  unsigned int EXT_visual_rating : 1;  

  unsigned int MESA_copy_sub_buffer : 1;
  unsigned int MESA_pixmap_colormap : 1;
  unsigned int MESA_release_buffers : 1;
  unsigned int MESA_set_3dfx_mode : 1;

  unsigned int NV_vertex_array_range : 1;

  unsigned int OML_swap_method : 1;
  unsigned int OML_sync_control : 1;

  unsigned int SGI_cushion : 1;
  unsigned int SGI_make_current_read : 1;
  unsigned int SGI_swap_control : 1;
  unsigned int SGI_video_sync : 1;
  unsigned int SGIS_blended_overlay : 1;
  unsigned int SGIS_multisample : 1;
  unsigned int SGIS_shared_multisample : 1;

  /* unsigned int SGIX_dm_buffer : 1; */
  unsigned int SGIX_fbconfig : 1;
  unsigned int SGIX_pbuffer : 1;
  unsigned int SGIX_swap_group : 1;
  unsigned int SGIX_swap_barrier : 1;
  /* unsigned int SGIX_video_source : 1; */
  /* unsigned int SGIX_video_resize : 1; */
  unsigned int SGIX_visual_select_group : 1;

  unsigned int SUN_get_transparent_index : 1;
};

extern struct GLXEW glxew;
extern GLboolean glxewGetExtension (const char* name);

#ifdef __cplusplus
}
#endif

#endif /* _WIN32 */

#endif /* __glxew_h__ */
