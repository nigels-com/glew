  return GLEW_OK;
}

#elif !defined(__APPLE__) || defined(GLEW_APPLE_GLX) /* _UNIX */

GLboolean glxewGetExtension (const char* name)
{    
  GLubyte* p;
  GLubyte* end;
  GLuint len = _glewStrLen((const GLubyte*)name);
/*   if (glXQueryExtensionsString == NULL || glXGetCurrentDisplay == NULL) return GL_FALSE; */
/*   p = (GLubyte*)glXQueryExtensionsString(glXGetCurrentDisplay(), DefaultScreen(glXGetCurrentDisplay())); */
  if (glXGetClientString == NULL || glXGetCurrentDisplay == NULL) return GL_FALSE;
  p = (GLubyte*)glXGetClientString(glXGetCurrentDisplay(), GLX_EXTENSIONS);
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
GLenum glxewContextInit (GLXEW_CONTEXT_ARG_DEF_LIST)
{
  int major, minor;
  /* initialize core GLX 1.2 */
  if (_glewInit_GLX_VERSION_1_2(GLEW_CONTEXT_ARG_VAR_INIT)) return GLEW_ERROR_GLX_VERSION_11_ONLY;
  /* initialize flags */
  GLXEW_VERSION_1_0 = GL_FALSE;
  GLXEW_VERSION_1_1 = GL_FALSE;
  GLXEW_VERSION_1_2 = GL_FALSE;
  GLXEW_VERSION_1_3 = GL_FALSE;
  GLXEW_VERSION_1_4 = GL_FALSE;
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
