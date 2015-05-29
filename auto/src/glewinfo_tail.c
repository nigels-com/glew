}

#endif /* _WIN32 */

/* ------------------------------------------------------------------------ */

int main (int argc, char** argv)
{
  GLuint err;
  struct createParams params = {
#if defined(_WIN32)
    -1,  /* pixelformat */
#elif !defined(__HAIKU__) && !defined(__APPLE__) || defined(GLEW_APPLE_GLX)
    "",  /* display */
    -1,  /* visual */
#endif
    0,   /* major */
    0,   /* minor */
    0,   /* profile mask */
    0    /* flags */
  };

  if (glewParseArgs(argc-1, argv+1, &params))
  {
    fprintf(stderr, "Usage: glewinfo "
#if defined(_WIN32)
	    "[-pf <pixelformat>] "
#elif !defined(__HAIKU__) && !defined(__APPLE__) || defined(GLEW_APPLE_GLX)
	    "[-display <display>] "
	    "[-visual <visual id>] "
#endif
	    "[-version <OpenGL version>] "
	    "[-profiles <OpenGL profile mask>] "
	    "[-flags <OpenGL flags>]"
	    "\n");
    return 1;
  }

  if (GL_TRUE == glewCreateContext(&params))
  {
    fprintf(stderr, "Error: glewCreateContext failed\n");
    glewDestroyContext();
    return 1;
  }
  glewExperimental = GL_TRUE;
#ifdef GLEW_MX
  err = glewContextInit(glewGetContext());
#ifdef _WIN32
  err = err || wglewContextInit(wglewGetContext());
#elif !defined(__HAIKU__) && !defined(__APPLE__) || defined(GLEW_APPLE_GLX)
  err = err || glxewContextInit(glxewGetContext());
#endif

#else
  err = glewInit();
#endif
  if (GLEW_OK != err)
  {
    fprintf(stderr, "Error [main]: glewInit failed: %s\n", glewGetErrorString(err));
    glewDestroyContext();
    return 1;
  }
#if defined(_WIN32)
#if defined(_MSC_VER) && (_MSC_VER >= 1400)
  if (fopen_s(&f, "glewinfo.txt", "w") != 0)
    f = stdout;
#else
  f = fopen("glewinfo.txt", "w");
#endif
  if (f == NULL) f = stdout;
#else
  f = stdout;
#endif
  fprintf(f, "---------------------------\n");
  fprintf(f, "    GLEW Extension Info\n");
  fprintf(f, "---------------------------\n\n");
  fprintf(f, "GLEW version %s\n", glewGetString(GLEW_VERSION));
#if defined(_WIN32)
  fprintf(f, "Reporting capabilities of pixelformat %d\n", params.pixelformat);
#elif !defined(__APPLE__) || defined(GLEW_APPLE_GLX)
  fprintf(f, "Reporting capabilities of display %s, visual 0x%x\n", 
    params.display == NULL ? getenv("DISPLAY") : params.display, params.visual);
#endif
  fprintf(f, "Running on a %s from %s\n", 
	  glGetString(GL_RENDERER), glGetString(GL_VENDOR));
  fprintf(f, "OpenGL version %s is supported\n", glGetString(GL_VERSION));
  glewInfo();
#if defined(_WIN32)
  wglewInfo();
#else
  glxewInfo();
#endif
  if (f != stdout) fclose(f);
  glewDestroyContext();
  return 0;
}

/* ------------------------------------------------------------------------ */

GLboolean glewParseArgs (int argc, char** argv, struct createParams *params)
{
  int p = 0;
  while (p < argc)
  {
    if (!strcmp(argv[p], "-version"))
    {
      if (++p >= argc) return GL_TRUE;
      if (sscanf(argv[p++], "%d.%d", &params->major, &params->minor) != 2) return GL_TRUE;
    }
    else if (!strcmp(argv[p], "-profiles"))
    {
      if (++p >= argc) return GL_TRUE;
      params->profile_mask = (int)strtol(argv[p++], NULL, 0);
    }
    else if (!strcmp(argv[p], "-flags"))
    {
      if (++p >= argc) return GL_TRUE;
      params->flags = (int)strtol(argv[p++], NULL, 0);
    }
#if defined(_WIN32)
    else if (!strcmp(argv[p], "-pf") || !strcmp(argv[p], "-pixelformat"))
    {
      if (++p >= argc) return GL_TRUE;
      params->pixelformat = strtol(argv[p++], NULL, 0);
    }
#elif !defined(__HAIKU__) && !defined(__APPLE__) || defined(GLEW_APPLE_GLX)
    else if (!strcmp(argv[p], "-display"))
    {
      if (++p >= argc) return GL_TRUE;
      params->display = argv[p++];
    }
    else if (!strcmp(argv[p], "-visual"))
    {
      if (++p >= argc) return GL_TRUE;
      params->visual = (int)strtol(argv[p++], NULL, 0);
    }
#endif
    else
      return GL_TRUE;
  }
  return GL_FALSE;
}

/* ------------------------------------------------------------------------ */

#if defined(_WIN32)

HWND wnd = NULL;
HDC dc = NULL;
HGLRC rc = NULL;

GLboolean glewCreateContext (struct createParams* params)
{
  WNDCLASS wc;
  PIXELFORMATDESCRIPTOR pfd;
  /* register window class */
  ZeroMemory(&wc, sizeof(WNDCLASS));
  wc.hInstance = GetModuleHandle(NULL);
  wc.lpfnWndProc = DefWindowProc;
  wc.lpszClassName = "GLEW";
  if (0 == RegisterClass(&wc)) return GL_TRUE;
  /* create window */
  wnd = CreateWindow("GLEW", "GLEW", 0, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
                     CW_USEDEFAULT, NULL, NULL, GetModuleHandle(NULL), NULL);
  if (NULL == wnd) return GL_TRUE;
  /* get the device context */
  dc = GetDC(wnd);
  if (NULL == dc) return GL_TRUE;
  /* find pixel format */
  ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
  if (params->pixelformat == -1) /* find default */
  {
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
    params->pixelformat = ChoosePixelFormat(dc, &pfd);
    if (params->pixelformat == 0) return GL_TRUE;
  }
  /* set the pixel format for the dc */
  if (FALSE == SetPixelFormat(dc, params->pixelformat, &pfd)) return GL_TRUE;
  /* create rendering context */
  rc = wglCreateContext(dc);
  if (NULL == rc) return GL_TRUE;
  if (FALSE == wglMakeCurrent(dc, rc)) return GL_TRUE;
  if (params->major || params->profile_mask || params->flags)
  {
    HGLRC oldRC = rc;
    int contextAttrs[20];
    int i;

    extern GLenum GLEWAPIENTRY wglewContextInit();
    wglewContextInit();

    if (!wglewGetExtension("WGL_ARB_create_context_profile"))
      return GL_TRUE;

    i = 0;
    if( params->major )
    {
      contextAttrs[i++] = WGL_CONTEXT_MAJOR_VERSION_ARB;
      contextAttrs[i++] = params->major;
      contextAttrs[i++] = WGL_CONTEXT_MINOR_VERSION_ARB;
      contextAttrs[i++] = params->minor;
    }
    if( params->profile_mask )
    {
      contextAttrs[i++] = WGL_CONTEXT_PROFILE_MASK_ARB;
      contextAttrs[i++] = params->profile_mask;
    }
    if( params->flags )
    {
      contextAttrs[i++] = WGL_CONTEXT_FLAGS_ARB;
      contextAttrs[i++] = params->flags;
    }
    contextAttrs[i++] = 0;
    rc = wglCreateContextAttribsARB(dc, 0, contextAttrs);

    if (NULL == rc) return GL_TRUE;
    if (!wglMakeCurrent(dc, rc)) return GL_TRUE;

    wglDeleteContext(oldRC);
  }
  return GL_FALSE;
}

void glewDestroyContext ()
{
  if (NULL != rc) wglMakeCurrent(NULL, NULL);
  if (NULL != rc) wglDeleteContext(rc);
  if (NULL != wnd && NULL != dc) ReleaseDC(wnd, dc);
  if (NULL != wnd) DestroyWindow(wnd);
  UnregisterClass("GLEW", GetModuleHandle(NULL));
}

/* ------------------------------------------------------------------------ */

#elif defined(__APPLE__) && !defined(GLEW_APPLE_GLX)

#include <OpenGL/OpenGL.h>
#include <OpenGL/CGLTypes.h>

CGLContextObj ctx, octx;

GLboolean glewCreateContext (struct createParams *params)
{
  CGLPixelFormatAttribute contextAttrs[20];
  int i;
  CGLPixelFormatObj pf;
  GLint npix;
  CGLError error;

  i = 0;
  contextAttrs[i++] = kCGLPFAAccelerated; /* No software rendering */

  #if MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_7
  if (params->profile_mask & GL_CONTEXT_CORE_PROFILE_BIT)
  {
    if (params->major==3 && params->minor>=2)
    {
      contextAttrs[i++] = kCGLPFAOpenGLProfile;                                /* OSX 10.7 Lion onwards */
      contextAttrs[i++] = (CGLPixelFormatAttribute) kCGLOGLPVersion_3_2_Core;  /* 3.2 Core Context      */
    }
  }
  #endif

  contextAttrs[i++] = 0;

  error = CGLChoosePixelFormat(contextAttrs, &pf, &npix);
  if (error) return GL_TRUE;
  error = CGLCreateContext(pf, NULL, &ctx);
  if (error) return GL_TRUE;
  CGLReleasePixelFormat(pf);
  octx = CGLGetCurrentContext();
  error = CGLSetCurrentContext(ctx);
  if (error) return GL_TRUE;
  /* Needed for Regal on the Mac */
  #if defined(GLEW_REGAL) && defined(__APPLE__)
  RegalMakeCurrent(ctx);
  #endif
  return GL_FALSE;
}

void glewDestroyContext ()
{
  CGLSetCurrentContext(octx);
  CGLReleaseContext(ctx);
}

/* ------------------------------------------------------------------------ */

#elif defined(__HAIKU__)

GLboolean glewCreateContext (struct createParams *params)
{
  /* TODO: Haiku: We need to call C++ code here */
  return GL_FALSE;
}

void glewDestroyContext ()
{
  /* TODO: Haiku: We need to call C++ code here */
}

/* ------------------------------------------------------------------------ */

#else /* __UNIX || (__APPLE__ && GLEW_APPLE_GLX) */

Display* dpy = NULL;
XVisualInfo* vi = NULL;
XVisualInfo* vis = NULL;
GLXContext ctx = NULL;
Window wnd = 0;
Colormap cmap = 0;

GLboolean glewCreateContext (struct createParams *params)
{
  int attrib[] = { GLX_RGBA, GLX_DOUBLEBUFFER, None };
  int erb, evb;
  XSetWindowAttributes swa;
  /* open display */
  dpy = XOpenDisplay(params->display);
  if (NULL == dpy) return GL_TRUE;
  /* query for glx */
  if (!glXQueryExtension(dpy, &erb, &evb)) return GL_TRUE;
  /* choose visual */
  if (params->visual == -1)
  {
    vi = glXChooseVisual(dpy, DefaultScreen(dpy), attrib);
    if (NULL == vi) return GL_TRUE;
    params->visual = (int)XVisualIDFromVisual(vi->visual);
  }
  else
  {
    int n_vis, i;
    vis = XGetVisualInfo(dpy, 0, NULL, &n_vis);
    for (i=0; i<n_vis; i++)
    {
      if ((int)XVisualIDFromVisual(vis[i].visual) == params->visual)
        vi = &vis[i];
    }
    if (vi == NULL) return GL_TRUE;
  }
  /* create context */
  ctx = glXCreateContext(dpy, vi, None, True);
  if (NULL == ctx) return GL_TRUE;
  /* create window */
  /*wnd = XCreateSimpleWindow(dpy, RootWindow(dpy, vi->screen), 0, 0, 1, 1, 1, 0, 0);*/
  cmap = XCreateColormap(dpy, RootWindow(dpy, vi->screen), vi->visual, AllocNone);
  swa.border_pixel = 0;
  swa.colormap = cmap;
  wnd = XCreateWindow(dpy, RootWindow(dpy, vi->screen), 
                      0, 0, 1, 1, 0, vi->depth, InputOutput, vi->visual, 
                      CWBorderPixel | CWColormap, &swa);
  /* make context current */
  if (!glXMakeCurrent(dpy, wnd, ctx)) return GL_TRUE;
  if (params->major || params->profile_mask || params->flags)
  {
    GLXContext oldCtx = ctx;
    GLXFBConfig *FBConfigs;
    int FBConfigAttrs[] = { GLX_FBCONFIG_ID, 0, None };
    int contextAttrs[20];
    int nelems, i;

    glxewContextInit();

    if (!glxewGetExtension("GLX_ARB_create_context_profile"))
      return GL_TRUE;

    if (glXQueryContext(dpy, oldCtx, GLX_FBCONFIG_ID, &FBConfigAttrs[1]))
      return GL_TRUE;
    FBConfigs = glXChooseFBConfig(dpy, vi->screen, FBConfigAttrs, &nelems);

    if (nelems < 1)
      return GL_TRUE;

    i = 0;
    if( params->major )
    {
      contextAttrs[i++] = GLX_CONTEXT_MAJOR_VERSION_ARB;
      contextAttrs[i++] = params->major;
      contextAttrs[i++] = GLX_CONTEXT_MINOR_VERSION_ARB;
      contextAttrs[i++] = params->minor;
    }
    if( params->profile_mask )
    {
      contextAttrs[i++] = GLX_CONTEXT_PROFILE_MASK_ARB;
      contextAttrs[i++] = params->profile_mask;
    }
    if( params->flags )
    {
      contextAttrs[i++] = GLX_CONTEXT_FLAGS_ARB;
      contextAttrs[i++] = params->flags;
    }
    contextAttrs[i++] = None;
    ctx = glXCreateContextAttribsARB(dpy, *FBConfigs, NULL, True, contextAttrs);

    if (NULL == ctx) return GL_TRUE;
    if (!glXMakeCurrent(dpy, wnd, ctx)) return GL_TRUE;

    glXDestroyContext(dpy, oldCtx);

    XFree(FBConfigs);
  }
  return GL_FALSE;
}

void glewDestroyContext ()
{
  if (NULL != dpy && NULL != ctx) glXDestroyContext(dpy, ctx);
  if (NULL != dpy && 0 != wnd) XDestroyWindow(dpy, wnd);
  if (NULL != dpy && 0 != cmap) XFreeColormap(dpy, cmap);
  if (NULL != vis)
    XFree(vis);
  else if (NULL != vi)
    XFree(vi);
  if (NULL != dpy) XCloseDisplay(dpy);
}

#endif /* __UNIX || (__APPLE__ && GLEW_APPLE_GLX) */
