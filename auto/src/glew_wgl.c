  return GLEW_OK;
}

/* ------------------------------------------------------------------------- */

#ifdef _WIN32

GLboolean wglewGetExtension (const GLubyte *name)
{    
  GLubyte *p, *end;
  GLuint len = _glewStrLen(name);
  if (wglGetExtensionsStringARB == NULL)
    if (wglGetExtensionsStringEXT == NULL)
      return GL_FALSE;
    else
      p = (GLubyte*)wglGetExtensionsStringEXT();
  else
    p = (GLubyte*)wglGetExtensionsStringARB(wglGetCurrentDC());
  if (0 == p) return GL_FALSE;
  end = p + _glewStrLen(p);
  while (p < end)
  {
    GLuint n = _glewStrCLen(p, ' ');
    if (len == n && _glewStrSame(name, p, n)) return GL_TRUE;
    p += n+1;
  }
  return GL_FALSE;
}

static GLuint _wglewInit ()
{
  GLboolean crippled;
  /* find wgl extension string query functions */
  _glewInit_WGL_ARB_extensions_string();
  WGLEW_ARB_extensions_string = wglGetExtensionsStringARB != NULL;
  _glewInit_WGL_EXT_extensions_string();
  WGLEW_EXT_extensions_string = wglGetExtensionsStringEXT != NULL;
  /* initialize extensions */
  crippled = !(WGLEW_ARB_extensions_string || WGLEW_EXT_extensions_string);
