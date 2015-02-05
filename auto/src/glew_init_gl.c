/* ------------------------------------------------------------------------- */

static
GLboolean glewGetVersion(GLint *major, GLint *minor)
{
  const GLubyte* s;
  GLuint dot;

  s = glGetString(GL_VERSION);
  dot = _glewStrCLen(s, '.');
  if (dot == 0)
    return GL_FALSE;

  *major = s[dot-1]-'0';
  *minor = s[dot+1]-'0';

  if (*minor < 0 || *minor > 9)
    *minor = 0;
  if (*major<0 || *major>9)
    return GL_FALSE;

  return GL_TRUE;
}

GLboolean GLEWAPIENTRY glewGetExtension (const char* name)
{    
  GLint major, minor;
  const GLubyte* start;
  const GLubyte* end;
  GLint numExts, ext;

  if (!glewGetVersion(&major, &minor))
    return GL_FALSE;

  if (major < 3)
  {
    start = (const GLubyte*)glGetString(GL_EXTENSIONS);
    if (start == 0)
      return GL_FALSE;
    end = start + _glewStrLen(start);
    return _glewSearchExtension(name, start, end);
  }
  else
  {
    glGetIntegerv(GL_NUM_EXTENSIONS, &numExts);
    for (ext = 0; ext < numExts; ext++)
    {
      start = (const GLubyte *)glGetStringi(GL_EXTENSIONS, ext);
      end = start + _glewStrLen(start);
      if (_glewSearchExtension(name, start, end))
	return GL_TRUE;
    }
    return GL_FALSE;
  }
}

/* ------------------------------------------------------------------------- */

#ifndef GLEW_MX
static
#endif
GLenum GLEWAPIENTRY glewContextInit (GLEW_CONTEXT_ARG_DEF_LIST)
{
  GLint major, minor;
  const GLubyte* extStart;
  const GLubyte* extEnd;
  GLint numExts, ext;
  GLint context_flags = 0;
  GLint context_profile = GL_CONTEXT_COMPATIBILITY_PROFILE_BIT;

  /* query opengl version */
  if (!glewGetVersion(&major, &minor))
    return GLEW_ERROR_NO_GL_VERSION;
  
  if (major == 1 && minor == 0)
  {
    return GLEW_ERROR_GL_VERSION_10_ONLY;
  }
  else
  {
    GLEW_VERSION_4_5   = ( major > 4 )                 || ( major == 4 && minor >= 5 ) ? GL_TRUE : GL_FALSE;
    GLEW_VERSION_4_4   = GLEW_VERSION_4_5   == GL_TRUE || ( major == 4 && minor >= 4 ) ? GL_TRUE : GL_FALSE;
    GLEW_VERSION_4_3   = GLEW_VERSION_4_4   == GL_TRUE || ( major == 4 && minor >= 3 ) ? GL_TRUE : GL_FALSE;
    GLEW_VERSION_4_2   = GLEW_VERSION_4_3   == GL_TRUE || ( major == 4 && minor >= 2 ) ? GL_TRUE : GL_FALSE;
    GLEW_VERSION_4_1   = GLEW_VERSION_4_2   == GL_TRUE || ( major == 4 && minor >= 1 ) ? GL_TRUE : GL_FALSE;
    GLEW_VERSION_4_0   = GLEW_VERSION_4_1   == GL_TRUE || ( major == 4               ) ? GL_TRUE : GL_FALSE;
    GLEW_VERSION_3_3   = GLEW_VERSION_4_0   == GL_TRUE || ( major == 3 && minor >= 3 ) ? GL_TRUE : GL_FALSE;
    GLEW_VERSION_3_2   = GLEW_VERSION_3_3   == GL_TRUE || ( major == 3 && minor >= 2 ) ? GL_TRUE : GL_FALSE;
    GLEW_VERSION_3_1   = GLEW_VERSION_3_2   == GL_TRUE || ( major == 3 && minor >= 1 ) ? GL_TRUE : GL_FALSE;
    GLEW_VERSION_3_0   = GLEW_VERSION_3_1   == GL_TRUE || ( major == 3               ) ? GL_TRUE : GL_FALSE;
    GLEW_VERSION_2_1   = GLEW_VERSION_3_0   == GL_TRUE || ( major == 2 && minor >= 1 ) ? GL_TRUE : GL_FALSE;    
    GLEW_VERSION_2_0   = GLEW_VERSION_2_1   == GL_TRUE || ( major == 2               ) ? GL_TRUE : GL_FALSE;
    GLEW_VERSION_1_5   = GLEW_VERSION_2_0   == GL_TRUE || ( major == 1 && minor >= 5 ) ? GL_TRUE : GL_FALSE;
    GLEW_VERSION_1_4   = GLEW_VERSION_1_5   == GL_TRUE || ( major == 1 && minor >= 4 ) ? GL_TRUE : GL_FALSE;
    GLEW_VERSION_1_3   = GLEW_VERSION_1_4   == GL_TRUE || ( major == 1 && minor >= 3 ) ? GL_TRUE : GL_FALSE;
    GLEW_VERSION_1_2_1 = GLEW_VERSION_1_3   == GL_TRUE                                 ? GL_TRUE : GL_FALSE; 
    GLEW_VERSION_1_2   = GLEW_VERSION_1_2_1 == GL_TRUE || ( major == 1 && minor >= 2 ) ? GL_TRUE : GL_FALSE;
    GLEW_VERSION_1_1   = GLEW_VERSION_1_2   == GL_TRUE || ( major == 1 && minor >= 1 ) ? GL_TRUE : GL_FALSE;
  }

  if( GLEW_VERSION_3_0 )
    glGetIntegerv(GL_CONTEXT_FLAGS, &context_flags);
  if( GLEW_VERSION_3_2 )
    glGetIntegerv(GL_CONTEXT_PROFILE_MASK, &context_profile);
  else if( GLEW_VERSION_3_1 && !glewGetExtension("GL_ARB_compatibility"))
    context_profile = GL_CONTEXT_CORE_PROFILE_BIT;

  /* initialize core functions */
