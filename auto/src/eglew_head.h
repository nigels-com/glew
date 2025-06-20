#ifndef __eglew_h__
#define __eglew_h__
#define __EGLEW_H__

#ifdef __eglext_h_
#error eglext.h included before eglew.h
#endif

#if defined(__egl_h_)
#error egl.h included before eglew.h
#endif

#define __eglext_h_

#define __egl_h_

#ifndef EGLAPIENTRY
#define EGLAPIENTRY
#endif
#ifndef EGLAPI
#define EGLAPI extern
#endif

/* EGL Types */
#include <sys/types.h>

#include <KHR/khrplatform.h>
#include <EGL/eglplatform.h>

#ifndef GLEW_INCLUDE
#  include <GL/glew.h>
#else
#  include GLEW_INCLUDE
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef int32_t EGLint;

typedef unsigned int EGLBoolean;
typedef void *EGLDisplay;
typedef void *EGLConfig;
typedef void *EGLSurface;
typedef void *EGLContext;
typedef void (*__eglMustCastToProperFunctionPointerType)(void);

typedef unsigned int EGLenum;
typedef void *EGLClientBuffer;

typedef void *EGLSync;
typedef intptr_t EGLAttrib;
typedef khronos_utime_nanoseconds_t EGLTime;
typedef void *EGLImage;

typedef void *EGLSyncKHR;
typedef intptr_t EGLAttribKHR;
typedef void *EGLLabelKHR;
typedef void *EGLObjectKHR;
typedef void (EGLAPIENTRY  *EGLDEBUGPROCKHR)(EGLenum error,const char *command,EGLint messageType,EGLLabelKHR threadLabel,EGLLabelKHR objectLabel,const char* message);
typedef khronos_utime_nanoseconds_t EGLTimeKHR;
typedef void *EGLImageKHR;
typedef void *EGLStreamKHR;
typedef khronos_uint64_t EGLuint64KHR;
typedef int EGLNativeFileDescriptorKHR;
typedef khronos_ssize_t EGLsizeiANDROID;
typedef void (*EGLSetBlobFuncANDROID) (const void *key, EGLsizeiANDROID keySize, const void *value, EGLsizeiANDROID valueSize);
typedef EGLsizeiANDROID (*EGLGetBlobFuncANDROID) (const void *key, EGLsizeiANDROID keySize, void *value, EGLsizeiANDROID valueSize);
typedef void *EGLDeviceEXT;
typedef void *EGLOutputLayerEXT;
typedef void *EGLOutputPortEXT;
typedef void *EGLSyncNV;
typedef khronos_utime_nanoseconds_t EGLTimeNV;
typedef khronos_utime_nanoseconds_t EGLuint64NV;
typedef khronos_stime_nanoseconds_t EGLnsecsANDROID;

struct EGLClientPixmapHI;
struct AHardwareBuffer;

/* Wayland types for WL_bind_wayland_display purposes */
struct wl_buffer;
struct wl_display;
struct wl_resource;

EGLAPI __eglMustCastToProperFunctionPointerType EGLAPIENTRY eglGetProcAddress (const char *procname);
