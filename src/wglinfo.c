/*
** wglinfo.c
**
** Copyright (C) Nate Robins, 1997
**               Michael Wimmer, 1999
**               Milan Ikits, 2003
**
** wglinfo is a small utility that displays all available visuals,
** aka. pixelformats, in an OpenGL system along with renderer version
** information. It shows a table of all the visuals that support OpenGL
** and their capabilities. The format of the table is similar to glxinfo
** on Unix systems:
**
** visual  ~= pixel format descriptor
** id       = visual id (integer from 1 - max visuals)
** dep      = cColorBits - color depth
** tp       = dwFlags - visual type (wn: window, pb: pbuffer, bm: bitmap)
** xsp      = no analog - transparent pixel (currently always ".")
** bfsz     = cColorBits - framebuffer size
** lvl      = bReserved - overlay (>0), underlay (<0), main plane (0)
** rgci     = iPixelType - rb = rgba mode, ci = color index mode
** db       = dwFlags & PFD_DOUBLEBUFFER - double buffer flag (y = yes)
** stro     = dwFlags & PFD_STEREO - stereo flag (y = yes)
** gene	    = dwFlags & PFD_GENERIC - software generic (y = yes) or ICD
** geac	    = dwFlags & PFD_GENERIC_ACCELERATED - generic with hardware (MCD)
** rsz      = cRedBits - # bits of red
** gsz      = cGreenBits - # bits of green
** bsz      = cBlueBits - # bits of blue
** asz      = cAlphaBits - # bits of alpha
** axbf     = cAuxBuffers - # of aux buffers
** dpth     = cDepthBits - # bits of depth
** stcl     = cStencilBits - # bits of stencil
** accum sz = cAccumBits - total # of bits in accumulation buffer
** accum r  = cAccumRedBits - # bits of red in accumulation buffer
** accum g  = cAccumGreenBits - # bits of green in accumulation buffer
** accum b  = cAccumBlueBits  - # bits of blue in accumulation buffer
** accum a  = cAccumAlphaBits - # bits of alpha in accumulation buffer
** ms ns/b  = no analog  - multisample buffers (currently always ".")
*/

#include <stdio.h>
#include <windows.h> /* must include */
#include <GL/gl.h>   /* OpenGL header */
#include <GL/glu.h>  /* GLU header */

int drawableonly = 0;
int pixelformatok = 0;
int dontcreatecontext = 0;
int displaystdout = 0;
int verbose = 0;
FILE* file = stdout;

#define WGL_DRAW_TO_PBUFFER_ARB                                 0x202D
#define WGL_NUMBER_PIXEL_FORMATS_ARB                            0x2000

typedef const char* (APIENTRY * wglGetExtensionsStringARBPROC) (HDC hdc);
typedef const char* (APIENTRY * wglGetExtensionsStringEXTPROC) ();
typedef BOOL (APIENTRY * wglGetPixelFormatAttribivARBPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues);
typedef BOOL (APIENTRY * wglChoosePixelFormatARBPROC) (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);

wglGetExtensionsStringARBPROC wglGetExtensionsStringARB = NULL;
wglGetExtensionsStringEXTPROC wglGetExtensionsStringEXT = NULL;
wglGetPixelFormatAttribivARBPROC wglGetPixelFormatAttribivARB = NULL;
wglChoosePixelFormatARBPROC wglChoosePixelFormatARB = NULL;

void
VisualInfo (HDC hDC, int verbose)
{
  int i, maxpf;
  PIXELFORMATDESCRIPTOR pfd;

  /* calling DescribePixelFormat() with NULL pfd (!!!) return maximum
     number of pixel formats */
  maxpf = DescribePixelFormat(hDC, 1, 0, NULL);

  if (!verbose)
  {
    fprintf(file, "-----------------------------------------------------------------------------\n");
    fprintf(file, "   visual   x  bf  lv rg d st ge ge  r  g  b a  ax dp st   accum buffs    ms \n");
    fprintf(file, " id  dep tp sp sz  l  ci b ro ne ac sz sz sz sz bf th cl  sz  r  g  b  a ns b\n");
    fprintf(file, "-----------------------------------------------------------------------------\n");

    /* loop through all the pixel formats */
    for(i = 1; i <= maxpf; i++)
    {
      DescribePixelFormat(hDC, i, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
      /* only describe this format if it supports OpenGL */
      if(!(pfd.dwFlags & PFD_SUPPORT_OPENGL)
	 || (drawableonly && (pfd.dwFlags & PFD_DRAW_TO_BITMAP))) continue;
      /* other criteria could be tested here for actual pixel format
	 choosing in an application:
	   
	 for (...each pixel format...) {
	 if (pfd.dwFlags & PFD_SUPPORT_OPENGL &&
	 pfd.dwFlags & PFD_DOUBLEBUFFER &&
	 pfd.cDepthBits >= 24 &&
	 pfd.cColorBits >= 24)
	 {
	 goto found;
	 }
	 }
	 ... not found so exit ...
	 found:
	 ... found so use it ...
      */
      /* print out the information for this pixel format */
      fprintf(file, "0x%02x ", i);
      fprintf(file, "%3d ", pfd.cColorBits);
      if(pfd.dwFlags & PFD_DRAW_TO_WINDOW) fprintf(file, "wn ");
      else if(pfd.dwFlags & PFD_DRAW_TO_BITMAP) fprintf(file, "bm ");
      else fprintf(file, "pb ");
      /* should find transparent pixel from LAYERPLANEDESCRIPTOR */
      fprintf(file, " . "); 
      fprintf(file, "%3d ", pfd.cColorBits);
      /* bReserved field indicates number of over/underlays */
      if(pfd.bReserved) fprintf(file, " %d ", pfd.bReserved);
      else fprintf(file, " . "); 
      fprintf(file, " %c ", pfd.iPixelType == PFD_TYPE_RGBA ? 'r' : 'c');
      fprintf(file, "%c ", pfd.dwFlags & PFD_DOUBLEBUFFER ? 'y' : '.');
      fprintf(file, " %c ", pfd.dwFlags & PFD_STEREO ? 'y' : '.');
      /* added: */
      fprintf(file, " %c ", pfd.dwFlags & PFD_GENERIC_FORMAT ? 'y' : '.');
      fprintf(file, " %c ", pfd.dwFlags & PFD_GENERIC_ACCELERATED ? 'y' : '.');
      if(pfd.cRedBits && pfd.iPixelType == PFD_TYPE_RGBA) 
	fprintf(file, "%2d ", pfd.cRedBits);
      else fprintf(file, " . ");
      if(pfd.cGreenBits && pfd.iPixelType == PFD_TYPE_RGBA) 
	fprintf(file, "%2d ", pfd.cGreenBits);
      else fprintf(file, " . ");
      if(pfd.cBlueBits && pfd.iPixelType == PFD_TYPE_RGBA) 
	fprintf(file, "%2d ", pfd.cBlueBits);
      else fprintf(file, " . ");
      if(pfd.cAlphaBits && pfd.iPixelType == PFD_TYPE_RGBA) 
	fprintf(file, "%2d ", pfd.cAlphaBits);
      else fprintf(file, " . ");
      if(pfd.cAuxBuffers)     fprintf(file, "%2d ", pfd.cAuxBuffers);
      else fprintf(file, " . ");
      if(pfd.cDepthBits)      fprintf(file, "%2d ", pfd.cDepthBits);
      else fprintf(file, " . ");
      if(pfd.cStencilBits)    fprintf(file, "%2d ", pfd.cStencilBits);
      else fprintf(file, " . ");
      if(pfd.cAccumBits)   fprintf(file, "%3d ", pfd.cAccumBits);
      else fprintf(file, "  . ");
      if(pfd.cAccumRedBits)   fprintf(file, "%2d ", pfd.cAccumRedBits);
      else fprintf(file, " . ");
      if(pfd.cAccumGreenBits) fprintf(file, "%2d ", pfd.cAccumGreenBits);
      else fprintf(file, " . ");
      if(pfd.cAccumBlueBits)  fprintf(file, "%2d ", pfd.cAccumBlueBits);
      else fprintf(file, " . ");
      if(pfd.cAccumAlphaBits) fprintf(file, "%2d ", pfd.cAccumAlphaBits);
      else fprintf(file, " . ");
      /* no multisample in win32 */
      fprintf(file, " . .\n");
    }
    /* print table footer */
    fprintf(file, "-----------------------------------------------------------------------------\n");
    fprintf(file, "   visual   x  bf  lv rg d st ge ge  r  g  b a  ax dp st   accum buffs    ms \n");
    fprintf(file, " id  dep tp sp sz  l  ci b ro ne ac sz sz sz sz bf th cl  sz  r  g  b  a ns b\n");
    fprintf(file, "-----------------------------------------------------------------------------\n");
  }
  else /* verbose */
  {
    fprintf(file, "\n");
    /* loop through all the pixel formats */
    for(i = 1; i <= maxpf; i++)
    {	    
      DescribePixelFormat(hDC, i, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
      /* only describe this format if it supports OpenGL */
      if(!(pfd.dwFlags & PFD_SUPPORT_OPENGL)
	 || (drawableonly && !(pfd.dwFlags & PFD_DRAW_TO_WINDOW))) continue;
      fprintf(file, "Visual ID: %2d  depth=%d  class=%s\n", i, pfd.cDepthBits, 
	     pfd.cColorBits <= 8 ? "PseudoColor" : "TrueColor");
      fprintf(file, "    bufferSize=%d level=%d renderType=%s doubleBuffer=%d stereo=%d\n", pfd.cColorBits, pfd.bReserved, pfd.iPixelType == PFD_TYPE_RGBA ? "rgba" : "ci", pfd.dwFlags & PFD_DOUBLEBUFFER, pfd.dwFlags & PFD_STEREO);
      fprintf(file, "    generic=%d generic accelerated=%d\n", (pfd.dwFlags & PFD_GENERIC_FORMAT) == PFD_GENERIC_FORMAT, (pfd.dwFlags & PFD_GENERIC_ACCELERATED) == PFD_GENERIC_ACCELERATED);
      fprintf(file, "    rgba: redSize=%d greenSize=%d blueSize=%d alphaSize=%d\n", pfd.cRedBits, pfd.cGreenBits, pfd.cBlueBits, pfd.cAlphaBits);
      fprintf(file, "    auxBuffers=%d depthSize=%d stencilSize=%d\n", pfd.cAuxBuffers, pfd.cDepthBits, pfd.cStencilBits);
      fprintf(file, "    accum: redSize=%d greenSize=%d blueSize=%d alphaSize=%d\n", pfd.cAccumRedBits, pfd.cAccumGreenBits, pfd.cAccumBlueBits, pfd.cAccumAlphaBits);
      fprintf(file, "    multiSample=%d multisampleBuffers=%d\n", 0, 0);
      fprintf(file, "    Opaque.\n");
    }
  }
}

LONG WINAPI
WindowProc (HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{ 
  static PAINTSTRUCT ps;

  switch(uMsg)
  {
    case WM_PAINT:
    BeginPaint(hWnd, &ps);
    EndPaint(hWnd, &ps);
    return 0;

    case WM_SIZE:
    //glViewport(0, 0, LOWORD(lParam), HIWORD(lParam));
    PostMessage(hWnd, WM_PAINT, 0, 0);
    return 0;

    case WM_CHAR:
    switch (wParam)
    {
      case 27:
      PostQuitMessage(0);
      break;
    }
    return 0;

    case WM_CLOSE:
    PostQuitMessage(0);
    return 0;
  }

  return DefWindowProc(hWnd, uMsg, wParam, lParam); 
} 

HWND
CreateGLWindow (char* title, int x, int y, int width, int height, 
		BYTE type, DWORD flags)
{
  int pf;
  HDC hDC;
  HWND hWnd;
  WNDCLASS wc;
  PIXELFORMATDESCRIPTOR pfd;
  static HINSTANCE hInstance = 0;

  /* only register the window class once - use hInstance as a flag. */
  if (!hInstance)
  {
    hInstance = GetModuleHandle(NULL);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = (WNDPROC)WindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = NULL;
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = "OpenGL";

    if (!RegisterClass(&wc))
    {
      MessageBox(NULL, "RegisterClass() failed:  "
		 "Cannot register window class.", "Error", MB_OK);
      return NULL;
    }
  }
  hWnd = CreateWindow("OpenGL", title, WS_OVERLAPPEDWINDOW |
		      WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
		      x, y, width, height, NULL, NULL, hInstance, NULL);

  if (hWnd == NULL)
  {
    MessageBox(NULL, "CreateWindow() failed:  Cannot create a window.",
	       "Error", MB_OK);
    return NULL;
  }
  hDC = GetDC(hWnd);
  /* there is no guarantee that the contents of the stack that become
     the pfd are zeroed, therefore _make sure_ to clear these bits. */
  memset(&pfd, 0, sizeof(pfd));
  pfd.nSize = sizeof(pfd);
  pfd.nVersion = 1;
  pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | flags;
  //pfd.iPixelType = type;
  //pfd.cColorBits = 32;
  pf = ChoosePixelFormat(hDC, &pfd);
  if (pf == 0)
  {
    fprintf(stderr, "ChoosePixelFormat() failed - trying with Pixelformat 1!\n");
    pf = 1;
  } 
  if (SetPixelFormat(hDC, pf, &pfd) == FALSE)
  {
    fprintf(stderr, "SetPixelFormat(%d) failed! No Renderer data will be available!\n", pf);
  } 
  else
  {
    DescribePixelFormat(hDC, pf, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
    if (pfd.cColorBits == 0)
      fprintf(stderr, "SetPixelFormat(%d) returned pfd with 0 colorbits - assuming invalid!\n", pf);
    else
      pixelformatok = 1;
  }
  // no effect (because of CS_OWNDC)
  ReleaseDC(hWnd, hDC);

  return hWnd;
}    

/* do the magic to separate all extensions with comma's, except
   for the last one that _may_ terminate in a space. */
void PrintExtensions (char* s)
{
  char t[80];
  int i=0;
  char* p;

  t[79] = '\0';
  while (*s)
  {
    t[i++] = *s;
    if(*s == ' ')
    {
      if (*(s+1) != '\0') {
	t[i-1] = ',';
	t[i] = ' ';
	p = &t[i++];
      }
      else /* zoinks! last one terminated in a space! */
      {
	t[i-1] = '\0';
      }
    }
    if(i > 80 - 5)
    {
      *p = t[i] = '\0';
      fprintf(file, "    %s\n", t);
      p++;
      i = strlen(p);
      strcpy(t, p);
    }
    s++;
  }
  t[i] = '\0';
  fprintf(file, "    %s.\n", t);
}

int 
main (int argc, char** argv)
{
  HDC hDC;
  HGLRC hRC;
  HWND hWnd;
  MSG msg;

  while (--argc)
  {
    if (strcmp("-h", argv[argc]) == 0) {
      //printf("Usage: wglinfo [-v] [-t] [-m] [-h] [-dispay <dname>] [-nfbc] [-fpcinfo]\n");
      fprintf(stderr, "Usage: wglinfo [-d] [-v] [-w] [-s] [-h]\n");
      fprintf(stderr, "        -d: no context (pixelformat enumeration, but no render string)\n");
      fprintf(stderr, "        -v: print visuals info in verbose form\n");
      /*
	printf("        -t: Print verbose table (not implemented on Win32)\n");
	printf("        -m: Don't print mid table headers (in long tables). (not on Win32)\n");
	printf("        -display <dname>: Print GLX visuals on specified server. (not on Win32)\n");
	printf("        -nfbc: Don't use fbconfig extension (not available on Win32)\n");
	printf("        -fbcinfo: print out additional fbconfig information (not on Win32)\n");
      */
      fprintf(stderr, "        -w: show only visuals that can draw to the screen\n");
      fprintf(stderr, "        -s: display to stdout instead of wglinfo.txt\n");      
      fprintf(stderr, "        -h: this screen\n");
      return 1;
    }
    else if (strcmp("-v", argv[argc]) == 0)
    {
      verbose = 1;
    }
    else if (strcmp("-w", argv[argc]) == 0)
    {
      drawableonly = 1;
    }
    else if (strcmp("-d", argv[argc]) == 0)
    {
      dontcreatecontext = 1;
    }	
    else if (strcmp("-s", argv[argc]) == 0)
    {
      displaystdout = 1;
    }
  }

  if (!displaystdout) file = fopen("wglinfo.txt", "w");
  if (file == NULL) file = stdout;

  hWnd = CreateGLWindow("wglinfo", 0, 0, 100, 100, PFD_TYPE_RGBA, PFD_DOUBLEBUFFER);
  if (hWnd == NULL) return 1;
  hDC = GetDC(hWnd);
  pixelformatok = pixelformatok && !dontcreatecontext;
  if (pixelformatok)
  {
    hRC = wglCreateContext(hDC);
    wglMakeCurrent(hDC, hRC);
  }
  ShowWindow(hWnd, SW_HIDE);

  if (pixelformatok)
  {
    /* output header information */
    /* OpenGL extensions */
    /*
      printf("display: N/A\n");
      printf("server wgl vendor string: N/A\n");
      printf("server wgl version string: N/A\n");
      printf("server wgl extensions (WGL_): N/A\n");
      printf("client wgl version: N/A\n");
      printf("client wgl extensions (WGL_): none\n");
    */
    fprintf(file, "OpenGL vendor string: %s\n", glGetString(GL_VENDOR));
    fprintf(file, "OpenGL renderer string: %s\n", glGetString(GL_RENDERER));
    fprintf(file, "OpenGL version string: %s\n", glGetString(GL_VERSION));
    fprintf(file, "OpenGL extensions (GL_): \n");
    PrintExtensions((char*)glGetString(GL_EXTENSIONS));

    /* GLU extensions */
    fprintf(file, "GLU version string: %s\n", gluGetString(GLU_VERSION));
    fprintf(file, "GLU extensions (GLU_): \n");
    PrintExtensions((char*)gluGetString(GLU_EXTENSIONS));

    /* WGL extensions */
    wglGetExtensionsStringARB = (wglGetExtensionsStringARBPROC)
      wglGetProcAddress("wglGetExtensionsStringARB");
    if (!wglGetExtensionsStringARB)
    {
      wglGetExtensionsStringEXT = (wglGetExtensionsStringEXTPROC)
	wglGetProcAddress("wglGetExtensionsStringEXT");
    }
    if (wglGetExtensionsStringARB || wglGetExtensionsStringEXT)
    {
      //fprintf(file, "WGL vendor string: %s\n", );
      //fprintf(file, "WGL version string: %s\n", );
      fprintf(file, "WGL extensions (WGL_): \n");
      if (wglGetExtensionsStringARB)
	PrintExtensions(wglGetExtensionsStringARB ? (char*)wglGetExtensionsStringARB(hDC):
			(char*)wglGetExtensionsStringARB(hDC));
    }
  }

  /* enumerate all the formats */
  wglChoosePixelFormatARB = 
    (wglChoosePixelFormatARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");
  wglGetPixelFormatAttribivARB =
    (wglGetPixelFormatAttribivARBPROC)wglGetProcAddress("wglGetPixelFormatAttribivARB");
  if (wglChoosePixelFormatARB != NULL && wglGetPixelFormatAttribivARB != NULL)
  {
    int attrib[16], value[16], pf;
    unsigned int c;
    attrib[0] = WGL_DRAW_TO_PBUFFER_ARB;
    attrib[1] = GL_TRUE;
    attrib[2] = 0;
    wglChoosePixelFormatARB(hDC, attrib, 0, 1, &pf, &c);
    attrib[0] = WGL_NUMBER_PIXEL_FORMATS_ARB;
    wglGetPixelFormatAttribivARB(hDC, 0, 0, 1, attrib, value);
  }
  VisualInfo(hDC, verbose);

  PostQuitMessage(0);
  while (GetMessage(&msg, hWnd, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  if (pixelformatok) wglMakeCurrent(NULL, NULL);
  ReleaseDC(hWnd, hDC);
  if (pixelformatok) wglDeleteContext(hRC);
  DestroyWindow(hWnd);

  if (file != stdout) fclose(file);

  return msg.wParam;
}
