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
** along with their capabilities. The format of the table is similar to
** that of glxinfo on Unix systems:
**
** visual ~= pixel format descriptor
** id       = visual id (integer from 1 - max visuals)
** tp       = type (wn: window, pb: pbuffer, wp: window & pbuffer, bm: bitmap)
** ac	    = acceleration (ge: generic, fu: full, no: none)
** fm	    = format (i: integer, f: float, c: color index)
** db	    = double buffer (y = yes)
** sw       = swap method (x: exchange, c: copy, u: undefined)
** st	    = stereo (y = yes)
** sz       = total # bits
** r        = # bits of red
** g        = # bits of green
** b        = # bits of blue
** a        = # bits of alpha
** axbf     = # aux buffers
** dpth     = # bits of depth
** stcl     = # bits of stencil
*/

#include <stdio.h>
#include <GL/glew.h>
#include <GL/wglew.h>

int drawableonly = 0;
int showall = 0;
int pixelformatok = 0;
int dontcreatecontext = 0;
int displaystdout = 0;
int verbose = 0;
FILE* file = 0;

void
VisualInfoARB (HDC hDC, int verbose)
{
  int attrib[32], value[32], n_attrib, n_pbuffer, n_float;
  int i, maxpf;

  attrib[0] = WGL_NUMBER_PIXEL_FORMATS_ARB;
  wglGetPixelFormatAttribivARB(hDC, 1, 0, 1, attrib, value);
  maxpf = value[0];

  for (i=0; i<32; i++)
    value[i] = 0;

  attrib[0] = WGL_SUPPORT_OPENGL_ARB;
  attrib[1] = WGL_DRAW_TO_WINDOW_ARB;
  attrib[2] = WGL_DRAW_TO_BITMAP_ARB;
  attrib[3] = WGL_ACCELERATION_ARB;
  /* WGL_NO_ACCELERATION_ARB, WGL_GENERIC_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB */
  attrib[4] = WGL_SWAP_METHOD_ARB;
  /* WGL_SWAP_EXCHANGE_ARB, WGL_SWAP_COPY_ARB, WGL_SWAP_UNDEFINED_ARB */
  attrib[5] = WGL_DOUBLE_BUFFER_ARB;
  attrib[6] = WGL_STEREO_ARB;
  attrib[7] = WGL_PIXEL_TYPE_ARB;
  /* WGL_TYPE_RGBA_ARB, WGL_TYPE_COLORINDEX_ARB,
     WGL_TYPE_RGBA_FLOAT_ATI (WGL_ATI_pixel_format_float) */
  /* Color buffer information */
  attrib[8] = WGL_COLOR_BITS_ARB;
  attrib[9] = WGL_RED_BITS_ARB;
  attrib[10] = WGL_GREEN_BITS_ARB;
  attrib[11] = WGL_BLUE_BITS_ARB;
  attrib[12] = WGL_ALPHA_BITS_ARB;
  /* Accumulation buffer information */
  attrib[13] = WGL_ACCUM_BITS_ARB;
  attrib[14] = WGL_ACCUM_RED_BITS_ARB;
  attrib[15] = WGL_ACCUM_GREEN_BITS_ARB;
  attrib[16] = WGL_ACCUM_BLUE_BITS_ARB;
  attrib[17] = WGL_ACCUM_ALPHA_BITS_ARB;
  /* Depth, stencil, and aux buffer information */
  attrib[18] = WGL_DEPTH_BITS_ARB;
  attrib[19] = WGL_STENCIL_BITS_ARB;
  attrib[20] = WGL_AUX_BUFFERS_ARB;
  /* Layer information */
  attrib[21] = WGL_NUMBER_OVERLAYS_ARB;
  attrib[22] = WGL_NUMBER_UNDERLAYS_ARB;
  attrib[23] = WGL_SWAP_LAYER_BUFFERS_ARB;
  attrib[24] = WGL_SAMPLES_ARB;
  attrib[25] = WGL_SUPPORT_GDI_ARB;
  n_attrib = 26;
  if (WGLEW_ARB_pbuffer)
  {
    attrib[n_attrib] = WGL_DRAW_TO_PBUFFER_ARB;
    n_pbuffer = n_attrib;
    n_attrib++;
  }
  if (WGLEW_NV_float_buffer)
  {
    attrib[n_attrib] = WGL_FLOAT_COMPONENTS_NV;
    n_float = n_attrib;
    n_attrib++;
  }
  
  if (!verbose)
  {
    /* print table header */
    fprintf(file, " +-----+-------------------------+-----------------+----------+-----------------+----------+\n");
    fprintf(file, " |     |          visual         |      color      | ax dp st |      accum      |   layer  |\n");
    fprintf(file, " |  id | tp ac gd fm db sw st ms |  sz  r  g  b  a | bf th cl |  sz  r  g  b  a | ov un sw |\n");
    fprintf(file, " +-----+-------------------------+-----------------+----------+-----------------+----------+\n");
    /* loop through all the pixel formats */
    for(i = 1; i <= maxpf; i++)
    {
      wglGetPixelFormatAttribivARB(hDC, i, 0, n_attrib, attrib, value);
      /* only describe this format if it supports OpenGL */
      if (!value[0]) continue;
      /* by default show only fully accelerated window or pbuffer capable visuals */
      if (!showall
	  && ((value[2] && !value[1])
	  || (!WGLEW_ARB_pbuffer || !value[n_pbuffer])
	  || (value[3] != WGL_FULL_ACCELERATION_ARB))) continue;
      /* print out the information for this visual */
      /* visual id */
      fprintf(file, " |% 4d | ", i);
      /* visual type */
      if (value[1])
      {
	if (WGLEW_ARB_pbuffer && value[n_pbuffer]) fprintf(file, "wp ");
	else fprintf(file, "wn ");
      }
      else
      {
	if (value[2]) fprintf(file, "bm ");
	else if (WGLEW_ARB_pbuffer && value[n_pbuffer]) fprintf(file, "pb ");
      }
      /* acceleration */
      fprintf(file, "%s ", value[3] == WGL_FULL_ACCELERATION_ARB ? "fu" : 
	      value[3] == WGL_GENERIC_ACCELERATION_ARB ? "ge" :
	      value[3] == WGL_NO_ACCELERATION_ARB ? "no" : ". ");
      /* gdi support */
      fprintf(file, " %c ", value[25] ? 'y' : '.');
      /* format */
      if (WGLEW_NV_float_buffer && value[n_float]) fprintf(file, " f ");
      else if (WGLEW_ATI_pixel_format_float && value[7] == WGL_TYPE_RGBA_FLOAT_ATI) fprintf(file, " f ");
      else if (value[7] == WGL_TYPE_RGBA_ARB) fprintf(file, " i ");
      else if (value[7] == WGL_TYPE_COLORINDEX_ARB) fprintf(file, " c ");
      /* double buffer */
      fprintf(file, " %c ", value[5] ? 'y' : '.');
      /* swap method */
      if (value[4] == WGL_SWAP_EXCHANGE_ARB) fprintf(file, " x ");
      else if (value[4] == WGL_SWAP_COPY_ARB) fprintf(file, " c ");
      else if (value[4] == WGL_SWAP_UNDEFINED_ARB) fprintf(file, " . ");
      else fprintf(file, " . ");
      /* stereo */
      fprintf(file, " %c ", value[6] ? 'y' : '.');
      /* multisample */
      if (value[24] > 0)
	fprintf(file, "%2d | ", value[24]);
      else
	fprintf(file, " . | ", value[24]);
      /* color size */
      if (value[8]) fprintf(file, "%3d ", value[8]);
      else fprintf(file, "  . ");
      /* red */
      if (value[9]) fprintf(file, "%2d ", value[9]); 
      else fprintf(file, " . ");
      /* green */
      if (value[10]) fprintf(file, "%2d ", value[10]); 
      else fprintf(file, " . ");
      /* blue */
      if (value[11]) fprintf(file, "%2d ", value[11]);
      else fprintf(file, " . ");
      /* alpha */
      if (value[12]) fprintf(file, "%2d | ", value[12]); 
      else fprintf(file, " . | ");
      /* aux buffers */
      if (value[20]) fprintf(file, "%2d ", value[20]);
      else fprintf(file, " . ");
      /* depth */
      if (value[18]) fprintf(file, "%2d ", value[18]);
      else fprintf(file, " . ");
      /* stencil */
      if (value[19]) fprintf(file, "%2d | ", value[19]);
      else fprintf(file, " . | ");
      /* accum size */
      if (value[13]) fprintf(file, "%3d ", value[13]);
      else fprintf(file, "  . ");
      /* accum red */
      if (value[14]) fprintf(file, "%2d ", value[14]);
      else fprintf(file, " . ");
      /* accum green */
      if (value[15]) fprintf(file, "%2d ", value[15]);
      else fprintf(file, " . ");
      /* accum blue */
      if (value[16]) fprintf(file, "%2d ", value[16]);
      else fprintf(file, " . ");
      /* accum alpha */
      if (value[17]) fprintf(file, "%2d | ", value[17]);
      else fprintf(file, " . | ");
      /* overlay */
      if (value[21]) fprintf(file, "%2d ", value[21]);
      else fprintf(file, " . ");
      /* underlay */
      if (value[22]) fprintf(file, "%2d ", value[22]);
      else fprintf(file, " . ");
      /* layer swap */
      if (value[23]) fprintf(file, "y ");
      else fprintf(file, " . ");
      fprintf(file, "|\n");
    }
    /* print table footer */
    fprintf(file, " +-----+-------------------------+-----------------+----------+-----------------+----------+\n");
    fprintf(file, " |     |          visual         |      color      | ax dp st |      accum      |   layer  |\n");
    fprintf(file, " |  id | tp ac gd fm db sw st ms |  sz  r  g  b  a | bf th cl |  sz  r  g  b  a | ov un sw |\n");
    fprintf(file, " +-----+-------------------------+-----------------+----------+-----------------+----------+\n");
  }
  else /* verbose */
  {
#if 0
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
#endif
  }
}

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
      MessageBox(NULL, "Failed to register window class", "Error", MB_OK);
      return NULL;
    }
  }
  hWnd = CreateWindow("OpenGL", title, WS_OVERLAPPEDWINDOW |
		      WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
		      x, y, width, height, NULL, NULL, hInstance, NULL);
  if (hWnd == NULL)
  {
    MessageBox(NULL, "Failed to create a window", "Error", MB_OK);
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
    //fprintf(stderr, "ChoosePixelFormat() failed - trying with Pixelformat 1!\n");
    pf = 1;
  } 
  if (SetPixelFormat(hDC, pf, &pfd) == FALSE)
  {
    //fprintf(stderr, "SetPixelFormat(%d) failed! No Renderer data will be available!\n", pf);
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
  int err;

  while (--argc)
  {
    if (strcmp("-h", argv[argc]) == 0) {
      //printf("Usage: wglinfo [-v] [-t] [-m] [-h] [-dispay <dname>] [-nfbc] [-fpcinfo]\n");
      fprintf(stderr, "Usage: wglinfo [-v] [-a] [-s] [-h]\n");
      fprintf(stderr, "        -d: no context (pixelformat enumeration, but no render string)\n");
      fprintf(stderr, "        -v: print visual info in verbose form\n");
      fprintf(stderr, "        -a: show all visuals\n");
      fprintf(stderr, "        -s: display to stdout instead of wglinfo.txt\n");      
      fprintf(stderr, "        -h: this screen\n");
      return 1;
    }
    else if (strcmp("-v", argv[argc]) == 0)
    {
      verbose = 1;
    }
    else if (strcmp("-a", argv[argc]) == 0)
    {
      showall = 1;
    }
    else if (strcmp("-s", argv[argc]) == 0)
    {
      displaystdout = 1;
    }
  }
  /* create window and OpenGL rendering context */
  hWnd = CreateGLWindow("wglinfo", 0, 0, 100, 100, PFD_TYPE_RGBA, PFD_DOUBLEBUFFER);
  if (hWnd == NULL) return 1;
  hDC = GetDC(hWnd);
  hRC = wglCreateContext(hDC);
  wglMakeCurrent(hDC, hRC);
  /* initialize GLEW */
  err = glewInit();    
  if (GLEW_OK != err)
  {
    char errStr[128];
    sprintf(errStr, "GLEW failed to initialize: %s", glewGetErrorString(err));
    MessageBox(NULL, errStr, "Error", MB_OK);
    return 1;
  }
  ShowWindow(hWnd, SW_HIDE);
  /* open file */
  if (!displaystdout) file = fopen("wglinfo.txt", "w");
  if (file == NULL) file = stdout;
  /* output header information */
  /* OpenGL extensions */
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
  if (WGLEW_ARB_extensions_string || WGLEW_EXT_extensions_string)
  {
    fprintf(file, "WGL extensions (WGL_): \n");
    PrintExtensions(wglGetExtensionsStringARB ? (char*)wglGetExtensionsStringARB(hDC) :
		    (char*)wglGetExtensionsStringEXT());
  }
  /* enumerate all the formats */
  if (WGLEW_ARB_pixel_format)
  {
    int attrib[16], value[16], pf;
    unsigned int c;
    attrib[0] = WGL_DRAW_TO_PBUFFER_ARB;
    attrib[1] = GL_TRUE;
    attrib[2] = 0;
    wglChoosePixelFormatARB(hDC, attrib, 0, 1, &pf, &c);
    attrib[0] = WGL_NUMBER_PIXEL_FORMATS_ARB;
    wglGetPixelFormatAttribivARB(hDC, 0, 0, 1, attrib, value);
    VisualInfoARB(hDC, verbose);
  }
  else
  {
    VisualInfo(hDC, verbose);
  }
  /* quit event loop */
  PostQuitMessage(0);
  while (GetMessage(&msg, hWnd, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  /* release resources */
  if (pixelformatok) wglMakeCurrent(NULL, NULL);
  ReleaseDC(hWnd, hDC);
  if (pixelformatok) wglDeleteContext(hRC);
  DestroyWindow(hWnd);
  if (file != stdout) fclose(file);

  return msg.wParam;
}
