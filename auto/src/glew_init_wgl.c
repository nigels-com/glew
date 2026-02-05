/* ------------------------------------------------------------------------- */

static PFNWGLGETEXTENSIONSSTRINGARBPROC _wglewGetExtensionsStringARB = NULL;
static PFNWGLGETEXTENSIONSSTRINGEXTPROC _wglewGetExtensionsStringEXT = NULL;

typedef HDC (WINAPI * PFNWGLGETCURRENTDCPROCPTR) (void);
static PFNWGLGETCURRENTDCPROCPTR _wglewGetCurrentDC = NULL;

GLboolean GLEWAPIENTRY wglewGetExtension (const char* name)
{
  const GLubyte* start;
  const GLubyte* end;

  if (_wglewGetCurrentDC == NULL)
    return GL_FALSE;

  if (_wglewGetExtensionsStringARB == NULL)
    if (_wglewGetExtensionsStringEXT == NULL)
      return GL_FALSE;
    else
      start = (const GLubyte*)_wglewGetExtensionsStringEXT();
  else
    start = (const GLubyte*)_wglewGetExtensionsStringARB(_wglewGetCurrentDC());
  if (start == 0)
    return GL_FALSE;
  end = start + _glewStrLen(start);
  return _glewSearchExtension(name, start, end);
}

GLenum GLEWAPIENTRY wglewInit (void)
{
  GLboolean crippled;
  const GLubyte* extStart;
  const GLubyte* extEnd;

  _wglewGetCurrentDC = (PFNWGLGETCURRENTDCPROCPTR)glewGetProcAddress((const GLubyte*)"wglGetCurrentDC");
  if (_wglewGetCurrentDC == NULL)
    return GLEW_ERROR_NO_GL_VERSION;

  /* find wgl extension string query functions */
  _wglewGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC)glewGetProcAddress((const GLubyte*)"wglGetExtensionsStringARB");
  _wglewGetExtensionsStringEXT = (PFNWGLGETEXTENSIONSSTRINGEXTPROC)glewGetProcAddress((const GLubyte*)"wglGetExtensionsStringEXT");
  /* query wgl extension string */
  if (_wglewGetExtensionsStringARB == NULL)
    if (_wglewGetExtensionsStringEXT == NULL)
      extStart = (const GLubyte*)"";
    else
      extStart = (const GLubyte*)_wglewGetExtensionsStringEXT();
  else
    extStart = (const GLubyte*)_wglewGetExtensionsStringARB(_wglewGetCurrentDC());
  extEnd = extStart + _glewStrLen(extStart);
  /* initialize extensions */
  crippled = _wglewGetExtensionsStringARB == NULL && _wglewGetExtensionsStringEXT == NULL;
