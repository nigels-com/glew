  return GLEW_OK;
}

#endif /* _WIN32 */

/* ------------------------------------------------------------------------ */

const char* glewGetErrorString (GLuint error)
{
  static const char* _glewErrorString[] =
  {
    "no error",
    "missing GL version",
    "missing {ARB,EXT}_extensions_string",
    "GL 1.1 and up are not supported",
    "GLX 1.2 and up are not supported",
    "unknown error"
  };
  if (error > 5) error = 5;
  return _glewErrorString[error];
}

/* ------------------------------------------------------------------------ */

GLboolean glewExperimental = GL_FALSE;

GLuint glewInit ()
{
  GLuint r;
  if ( (r = _glewInit()) ) return r;
#ifdef _WIN32
  return _wglewInit();
#else /* _UNIX */
  return _glxewInit();
#endif /* _WIN32 */
}
