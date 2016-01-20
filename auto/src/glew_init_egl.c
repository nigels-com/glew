/* ------------------------------------------------------------------------ */

GLboolean eglewGetExtension (const char* name)
{    
  const GLubyte* start;
  const GLubyte* end;

/* TODO */
/* return _glewSearchExtension(name, start, end); */
  return GL_FALSE;
}

GLenum eglewInit ()
{
  int major, minor;
  const GLubyte* extStart;
  const GLubyte* extEnd;

  /* initialize flags */
  EGLEW_VERSION_1_0 = GL_TRUE;
  EGLEW_VERSION_1_1 = GL_TRUE;
  EGLEW_VERSION_1_2 = GL_TRUE;
  EGLEW_VERSION_1_3 = GL_TRUE;
  EGLEW_VERSION_1_4 = GL_TRUE;
  EGLEW_VERSION_1_5 = GL_TRUE;

  /* query EGL version */

  /* query EGL extension string */

  /* initialize extensions */
