  return GLEW_OK;
}

/* ------------------------------------------------------------------------- */

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

static GLuint _wglewInit ()
{
  /* find wgl extension string query functions */
  _glewInit_WGL_ARB_extensions_string();
  WGLEW_ARB_extensions_string = wglGetExtensionsStringARB != NULL;
  _glewInit_WGL_EXT_extensions_string();
  WGLEW_EXT_extensions_string = wglGetExtensionsStringEXT != NULL;
  /* initialize extensions */
