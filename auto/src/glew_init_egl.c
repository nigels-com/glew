/* ------------------------------------------------------------------------ */

GLboolean eglewGetExtension (const char* name)
{    
  const GLubyte* start;
  const GLubyte* end;

  start = (const GLubyte*) eglQueryString(eglGetDisplay(EGL_DEFAULT_DISPLAY), EGL_EXTENSIONS);
  if (0 == start) return GL_FALSE;
  end = start + _glewStrLen(start);
  return _glewSearchExtension(name, start, end);
}

GLenum eglewInit ()
{
  GLuint dot;
  GLint major, minor;
  const GLubyte* version;
  const GLubyte* extStart;
  const GLubyte* extEnd;

  /* query EGK version */
  major = 0;
  minor = 0;
  version = (const GLubyte*) eglQueryString(eglGetDisplay(EGL_DEFAULT_DISPLAY), EGL_VERSION);
  dot = _glewStrCLen(version, '.');
  if (dot != 0)
  {
    major = version[dot-1]-'0';
    minor = version[dot+1]-'0';
  }

  EGLEW_VERSION_1_5   = ( major > 1 )              || ( major == 1 && minor >= 5 ) ? GL_TRUE : GL_FALSE;
  EGLEW_VERSION_1_4   = EGLEW_VERSION_1_5 == GL_TRUE || ( major == 1 && minor >= 4 ) ? GL_TRUE : GL_FALSE;
  EGLEW_VERSION_1_3   = EGLEW_VERSION_1_4 == GL_TRUE || ( major == 1 && minor >= 3 ) ? GL_TRUE : GL_FALSE;
  EGLEW_VERSION_1_2   = EGLEW_VERSION_1_3 == GL_TRUE || ( major == 1 && minor >= 2 ) ? GL_TRUE : GL_FALSE;
  EGLEW_VERSION_1_1   = EGLEW_VERSION_1_2 == GL_TRUE || ( major == 1 && minor >= 1 ) ? GL_TRUE : GL_FALSE;
  EGLEW_VERSION_1_0   = EGLEW_VERSION_1_1 == GL_TRUE || ( major == 1 && minor >= 0 ) ? GL_TRUE : GL_FALSE;

  /* query EGL extension string */
  extStart = (const GLubyte*) eglQueryString(eglGetDisplay(EGL_DEFAULT_DISPLAY), EGL_EXTENSIONS);
  if (extStart == 0)
    extStart = (const GLubyte *)"";
  extEnd = extStart + _glewStrLen(extStart);

  /* initialize extensions */
