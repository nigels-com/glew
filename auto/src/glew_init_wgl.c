/* ------------------------------------------------------------------------- */

static PFNWGLGETEXTENSIONSSTRINGARBPROC _wglewGetExtensionsStringARB = NULL;
static PFNWGLGETEXTENSIONSSTRINGEXTPROC _wglewGetExtensionsStringEXT = NULL;

GLboolean GLEWAPIENTRY wglewGetExtension (const char* name)
{
#if GLEW_MX
    WGLEWContext *ctx = wglewGetContext();
#endif
  return _glewHashListExists(WGLEW_GET_VAR(GLEW_WGL_EXTENSIONS), name);
}

GLenum GLEWAPIENTRY wglewContextInit (WGLEW_CONTEXT_ARG_DEF_LIST)
{
  GLboolean crippled;
  const GLubyte* extensions;
  GLEWHashList *ext_hashlist;

  /* find wgl extension string query functions */
  _wglewGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC)glewGetProcAddress((const GLubyte*)"wglGetExtensionsStringARB");
  _wglewGetExtensionsStringEXT = (PFNWGLGETEXTENSIONSSTRINGEXTPROC)glewGetProcAddress((const GLubyte*)"wglGetExtensionsStringEXT");
  /* query wgl extension string */
  if (_wglewGetExtensionsStringARB == NULL)
    if (_wglewGetExtensionsStringEXT == NULL)
      extensions = (const GLubyte*)"";
    else
      extensions = (const GLubyte*)_wglewGetExtensionsStringEXT();
  else
    extensions = (const GLubyte*)_wglewGetExtensionsStringARB(wglGetCurrentDC());

  WGLEW_GET_VAR(GLEW_WGL_EXTENSIONS) = calloc(1, sizeof(GLEWHashList));

  ext_hashlist = WGLEW_GET_VAR(GLEW_WGL_EXTENSIONS);

  _glewBuildHashListFromString(extensions, ext_hashlist);

  /* initialize extensions */
  crippled = _wglewGetExtensionsStringARB == NULL && _wglewGetExtensionsStringEXT == NULL;
