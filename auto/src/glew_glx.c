  return GLEW_OK;
}

#elif !defined(__APPLE__) || defined(GLEW_APPLE_GLX) /* _UNIX */

GLboolean glxewGetExtension (const char* name)
{    
  GLubyte* p;
  GLubyte* end;
  GLuint len = _glewStrLen((const GLubyte*)name);
  if (glXQueryExtensionsString == NULL || glxewDefaultContext->__glewXGetCurrentDisplay == NULL) return GL_FALSE;
  p = (GLubyte*)glXQueryExtensionsString(glxewDefaultContext->__glewXGetCurrentDisplay(), DefaultScreen(glxewDefaultContext->__glewXGetCurrentDisplay()));
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

GLenum glxewContextInit (GLXEWContext* ctx)
{
  int major, minor;
  /* initialize core GLX 1.2 */
  if (_glewInit_GLX_VERSION_1_2(ctx)) return GLEW_ERROR_GLX_VERSION_11_ONLY;
  glxewDefaultContext->__glewXGetCurrentDisplay = ctx->__glewXGetCurrentDisplay;
  /* query GLX version */
  glXQueryVersion(glXGetCurrentDisplay(), &major, &minor);
  ctx->__GLXEW_VERSION_1_0 = GL_FALSE;
  ctx->__GLXEW_VERSION_1_1 = GL_FALSE;
  ctx->__GLXEW_VERSION_1_2 = GL_FALSE;
  ctx->__GLXEW_VERSION_1_3 = GL_FALSE;
  ctx->__GLXEW_VERSION_1_4 = GL_FALSE;
  switch (minor)
  {
    case 4:
    ctx->__GLXEW_VERSION_1_4 = GL_TRUE;
    case 3:
    ctx->__GLXEW_VERSION_1_3 = GL_TRUE;
    case 2:
    ctx->__GLXEW_VERSION_1_2 = GL_TRUE;
    ctx->__GLXEW_VERSION_1_1 = GL_TRUE;
    ctx->__GLXEW_VERSION_1_0 = GL_TRUE;
    break;
    default:
    return GLEW_ERROR_GLX_VERSION_11_ONLY;
    break;
  }
  /* initialize extensions */
