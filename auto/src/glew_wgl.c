  return GLEW_OK;
}

/* ------------------------------------------------------------------------- */

#ifdef _WIN32

GLboolean wglewGetExtension (const GLubyte* name)
{    
  GLubyte* p;
  GLubyte* end;
  GLuint len = _glewStrLen(name);
  if (wglewDefaultContext->__wglewGetExtensionsStringARB == NULL)
    if (wglewDefaultContext->__wglewGetExtensionsStringEXT == NULL)
      return GL_FALSE;
    else
      p = (GLubyte*)wglewDefaultContext->__wglewGetExtensionsStringEXT();
  else
    p = (GLubyte*)wglewDefaultContext->__wglewGetExtensionsStringARB(wglGetCurrentDC());
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

GLenum wglewContextInit (WGLEWContext* ctx)
{
  GLboolean crippled;
  /* find wgl extension string query functions */
  _glewInit_WGL_ARB_extensions_string(ctx);
  ctx->__WGLEW_ARB_extensions_string = (ctx->__wglewGetExtensionsStringARB != NULL);
  wglewDefaultContext->__wglewGetExtensionsStringARB = ctx->__wglewGetExtensionsStringARB;
  wglewDefaultContext->__WGLEW_ARB_extensions_string = ctx->__WGLEW_ARB_extensions_string;
  _glewInit_WGL_EXT_extensions_string(ctx);
  ctx->__WGLEW_EXT_extensions_string = (ctx->__wglewGetExtensionsStringEXT != NULL);
  wglewDefaultContext->__wglewGetExtensionsStringEXT = ctx->__wglewGetExtensionsStringEXT;
  wglewDefaultContext->__WGLEW_EXT_extensions_string = ctx->__WGLEW_EXT_extensions_string;
  /* initialize extensions */
  crippled = !(ctx->__WGLEW_ARB_extensions_string || ctx->__WGLEW_EXT_extensions_string);
