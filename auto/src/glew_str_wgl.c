  }
  return GL_FALSE;
}

#if defined(_WIN32)

#if defined(GLEW_MX)
GLboolean wglewContextIsSupported (WGLEWContext* ctx, const char* name)
#else
GLboolean wglewIsSupported (const char* name)
#endif
{
  GLubyte* pos = (GLubyte*)name;
  GLuint len = _glewStrLen(pos);
  if(_glewStrSame2(&pos, &len, (const GLubyte*)"WGL_", 4))
  {
