/* ------------------------------------------------------------------------- */

static PFNWGLGETEXTENSIONSSTRINGARBPROC _wglewGetExtensionsStringARB = NULL;
static PFNWGLGETEXTENSIONSSTRINGEXTPROC _wglewGetExtensionsStringEXT = NULL;

GLboolean GLEWAPIENTRY wglewGetExtension (const char* name)
{    
  const GLubyte* start;
  const GLubyte* end;
  if (_wglewGetExtensionsStringARB == NULL)
    if (_wglewGetExtensionsStringEXT == NULL)
      return GL_FALSE;
    else
      start = (const GLubyte*)_wglewGetExtensionsStringEXT();
  else
    start = (const GLubyte*)_wglewGetExtensionsStringARB(wglGetCurrentDC());
  if (start == 0)
    return GL_FALSE;
  end = start + _glewStrLen(start);
  return _glewSearchExtension(name, start, end);
}

GLenum GLEWAPIENTRY wglewInit ()
{
  GLboolean crippled;
  const GLubyte* extStart;
  const GLubyte* extEnd;
  GLint context_profile = 0, context_flags = 0;

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
    extStart = (const GLubyte*)_wglewGetExtensionsStringARB(wglGetCurrentDC());
  extEnd = extStart + _glewStrLen(extStart);

  while (extStart < extEnd)
  {
    GLuint len = _glewStrCLen(extStart, ' ');
    struct initflag *ptr = in_word_set(extStart, len);

    if (ptr != NULL && ptr->flag != NULL) {
#ifdef GLEW_MX
      *(GLboolean *)((char *)ctx + (size_t)(ptr->flag)) = GL_TRUE;
#else
      *ptr->flag = GL_TRUE;
#endif
    }
    extStart += len + 1;
  }

  /* initialize extensions */
  crippled = _wglewGetExtensionsStringARB == NULL && _wglewGetExtensionsStringEXT == NULL;
