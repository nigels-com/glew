  return GLEW_OK;
}

#else /* _UNIX */

GLboolean glxewGetExtension (const GLubyte *name)
{    
  GLubyte *p, *end;
  GLuint len = _glewStrLen(name);
  if (glXQueryExtensionsString == NULL || glXGetCurrentDisplay == NULL) return GL_FALSE;
  p = (GLubyte*)glXQueryExtensionsString(glXGetCurrentDisplay(), DefaultScreen(glXGetCurrentDisplay()));
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

static GLuint _glxewInit ()
{
  int major, minor;
  /* initialize core GLX 1.2 */
  if (_glewInit_GLX_VERSION_1_2()) return GLEW_ERROR_GLX_VERSION_11_ONLY;
  /* query GLX version */
  glXQueryVersion(glXGetCurrentDisplay(), &major, &minor);
  switch (minor)
  {
    case 4:
    GLXEW_VERSION_1_4 = GL_TRUE;
    case 3:
    GLXEW_VERSION_1_3 = GL_TRUE;
    case 2:
    GLXEW_VERSION_1_2 = GL_TRUE;
    GLXEW_VERSION_1_1 = GL_TRUE;
    GLXEW_VERSION_1_0 = GL_TRUE;
    break;
    default:
    return GLEW_ERROR_GLX_VERSION_11_ONLY;
    break;
  }
  /* initialize extensions */
