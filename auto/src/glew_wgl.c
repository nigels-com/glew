  return GLEW_OK;
}

/* ------------------------------------------------------------------------- */

#ifdef _WIN32

static PFNWGLGETEXTENSIONSSTRINGARBPROC _wglewGetExtensionsStringARB = NULL;
static PFNWGLGETEXTENSIONSSTRINGEXTPROC _wglewGetExtensionsStringEXT = NULL;

GLboolean wglewGetExtension (const char* name)
{    
  GLubyte* p;
  GLubyte* end;
  GLuint len = _glewStrLen((const GLubyte*)name);
  if (_wglewGetExtensionsStringARB == NULL)
    if (_wglewGetExtensionsStringEXT == NULL)
      return GL_FALSE;
    else
      p = (GLubyte*)_wglewGetExtensionsStringEXT();
  else
    p = (GLubyte*)_wglewGetExtensionsStringARB(wglGetCurrentDC());
  if (0 == p) return GL_FALSE;
  end = p + _glewStrLen(p);
  while (p < end)
  {
    GLuint n = _glewStrCLen(p, ' ');
    if (len == n && _glewStrSame((const GLubyte*)name, p, n)) return GL_TRUE;
    p += n+1;
  }
  return GL_FALSE;
}

#ifndef GLEW_MX
static
#endif
GLenum wglewContextInit (WGLEW_CONTEXT_ARG_DEF_LIST)
{
  GLboolean crippled;
  /* find wgl extension string query functions */
  if (_wglewGetExtensionsStringARB == NULL)
    _wglewGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC)glewGetProcAddress((const GLubyte*)"wglGetExtensionsStringARB");
  if (_wglewGetExtensionsStringEXT == NULL)
    _wglewGetExtensionsStringEXT = (PFNWGLGETEXTENSIONSSTRINGEXTPROC)glewGetProcAddress((const GLubyte*)"wglGetExtensionsStringEXT");
  /* initialize extensions */
  crippled = _wglewGetExtensionsStringARB == NULL && _wglewGetExtensionsStringEXT == NULL;
