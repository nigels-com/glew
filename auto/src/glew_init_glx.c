/* ------------------------------------------------------------------------ */

GLboolean glxewGetExtension (const char* name)
{
#if GLEW_MX
    GLXEWContext *ctx = glxewGetContext();
#endif
  return _glewHashListExists(GLXEW_GET_VAR(GLEW_GLX_EXTENSIONS), name);
}

GLenum glxewContextInit (GLXEW_CONTEXT_ARG_DEF_LIST)
{
  int major, minor;
  const GLubyte* extensions;
  GLEWHashList *ext_hashlist;
  /* initialize core GLX 1.2 */
  if (_glewInit_GLX_VERSION_1_2(GLEW_CONTEXT_ARG_VAR_INIT)) return GLEW_ERROR_GLX_VERSION_11_ONLY;
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
  GLXEW_GET_VAR(GLEW_GLX_EXTENSIONS) = calloc(1, sizeof(GLEWHashList));

  ext_hashlist = GLXEW_GET_VAR(GLEW_GLX_EXTENSIONS);

  extensions = (const GLubyte*)glXGetClientString(glXGetCurrentDisplay(), GLX_EXTENSIONS);
  _glewBuildHashListFromString(extensions, ext_hashlist);

  /* initialize extensions */
