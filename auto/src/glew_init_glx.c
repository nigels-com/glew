/* ------------------------------------------------------------------------ */

PFNGLXQUERYVERSIONPROC __glewXQueryVersion = NULL;

PFNGLXGETCLIENTSTRINGPROC __glewXGetClientString = NULL;

static GLboolean _glewInit_GLX_VERSION_1_0 ()
{
  GLboolean r = GL_FALSE;

  r = ((glXQueryVersion = (PFNGLXQUERYVERSIONPROC)glewGetProcAddress((const GLubyte*)"glXQueryVersion")) == NULL) || r;

  return r;
}

static GLboolean _glewInit_GLX_VERSION_1_1 ()
{
  GLboolean r = GL_FALSE;

  r = ((glXGetClientString = (PFNGLXGETCLIENTSTRINGPROC)glewGetProcAddress((const GLubyte*)"glXGetClientString")) == NULL) || r;

  return r;
}

/* ------------------------------------------------------------------------ */

GLboolean glxewGetExtension (const char* name)
{
  const GLubyte* start;
  const GLubyte* end;

  if (glXGetCurrentDisplay == NULL) return GL_FALSE;
  start = (const GLubyte*)glXGetClientString(glXGetCurrentDisplay(), GLX_EXTENSIONS);
  if (0 == start) return GL_FALSE;
  end = start + _glewStrLen(start);
  return _glewSearchExtension(name, start, end);
}

GLenum glxewInit ()
{
  int major, minor;
  const GLubyte* extStart;
  const GLubyte* extEnd;

  if (_glewInit_GLX_VERSION_1_0() || _glewInit_GLX_VERSION_1_1())
      return GLEW_ERROR_GLX_VERSION_11_ONLY;

  /* initialize core GLX 1.2 */
  if (_glewInit_GLX_VERSION_1_2()) return GLEW_ERROR_GLX_VERSION_11_ONLY;
  /* initialize flags */
  GLXEW_VERSION_1_0 = GL_TRUE;
  GLXEW_VERSION_1_1 = GL_TRUE;
  GLXEW_VERSION_1_2 = GL_TRUE;
  GLXEW_VERSION_1_3 = GL_TRUE;
  GLXEW_VERSION_1_4 = GL_TRUE;
  /* query GLX version */
  glXQueryVersion(glXGetCurrentDisplay(), &major, &minor);
  if (major == 1 && minor <= 3)
  {
    switch (minor)
    {
      case 3:
      GLXEW_VERSION_1_4 = GL_FALSE;
      break;
      case 2:
      GLXEW_VERSION_1_4 = GL_FALSE;
      GLXEW_VERSION_1_3 = GL_FALSE;
      break;
      default:
      return GLEW_ERROR_GLX_VERSION_11_ONLY;
      break;
    }
  }
  /* query GLX extension string */
  extStart = 0;
  if (glXGetCurrentDisplay != NULL)
    extStart = (const GLubyte*)glXGetClientString(glXGetCurrentDisplay(), GLX_EXTENSIONS);
  if (extStart == 0)
    extStart = (const GLubyte *)"";
  extEnd = extStart + _glewStrLen(extStart);
  /* initialize extensions */
