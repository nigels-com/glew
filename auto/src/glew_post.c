  return GLEW_OK;
}

#endif /* _WIN32 */

/* ------------------------------------------------------------------------ */

const GLubyte* glewGetErrorString (GLenum error)
{
  static const GLubyte* _glewErrorString[] =
  {
    "No error",
    "Missing GL version",
    "GL 1.1 and up are not supported",
    "GLX 1.2 and up are not supported",
    "Unknown error"
  };
  const int max_error = sizeof(_glewErrorString)/sizeof(*_glewErrorString) - 1;
  return _glewErrorString[error > max_error ? max_error : error];
}

const GLubyte* glewGetString (GLenum name)
{
  static const GLubyte* _glewString[] =
  {
    NULL,
    "GLEW_VERSION_STRING"
  };
  const int max_string = sizeof(_glewString)/sizeof(*_glewString) - 1;
  return _glewString[name > max_string ? max_string : name];
}

/* ------------------------------------------------------------------------ */

GLboolean glewExperimental = GL_FALSE;

GLenum glewInit ()
{
  GLenum r;
  if ( (r = _glewInit()) ) return r;
#ifdef _WIN32
  return _wglewInit();
#else /* _UNIX */
  return _glxewInit();
#endif /* _WIN32 */
}
