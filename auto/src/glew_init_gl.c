/* ------------------------------------------------------------------------- */

static int _glewExtensionCompare(const void *a, const void *b)
{
   return strcmp((const char *) a, *(const char**) b);
}

static GLboolean *_glewGetExtensionString(const char *name)
{
  const char **n = (const char **) bsearch(name, _glewExtensionLookup, sizeof(_glewExtensionLookup)/sizeof(char *)-1, sizeof(char *), _glewExtensionCompare);
  int i;

  if (n)
  {
      i = n-_glewExtensionLookup;
      return _glewExtensionString+i;
  }

  return NULL;
}

static GLboolean *_glewGetExtensionEnable(const char *name)
{
  const char **n = (const char **) bsearch(name, _glewExtensionLookup, sizeof(_glewExtensionLookup)/sizeof(char *)-1, sizeof(char *), _glewExtensionCompare);
  int i;

  if (n)
  {
      i = n-_glewExtensionLookup;
      return _glewExtensionEnabled[i];
  }

  return NULL;
}

static char *_glewNextSpace(char *i)
{
  char *j = i;
  if (j)
    while (*j!=' ' && *j) ++j;
  return j;
}

static char *_glewNextNonSpace(char *i)
{
  char *j = i;
  if (j)
    while (*j==' ') ++j;
  return j;
}

GLboolean GLEWAPIENTRY glewGetExtension (const char* name)
{
  GLboolean *enable = _glewGetExtensionString(name);
  if (enable)
    return *enable;
  return GL_FALSE;
}

/* ------------------------------------------------------------------------- */

#ifndef GLEW_MX
static
#endif
GLenum GLEWAPIENTRY glewContextInit (GLEW_CONTEXT_ARG_DEF_LIST)
{
  const GLubyte* s;
  GLuint dot;
  GLint major, minor;
  char *begin;
  char *end;
  char *i;
  char *j;
  GLboolean *enable;

  /* query opengl version */
  s = glGetString(GL_VERSION);
  dot = _glewStrCLen(s, '.');
  if (dot == 0)
    return GLEW_ERROR_NO_GL_VERSION;
  
  major = s[dot-1]-'0';
  minor = s[dot+1]-'0';

  if (minor < 0 || minor > 9)
    minor = 0;
  if (major<0 || major>9)
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

  memset(_glewExtensionString,0,sizeof(_glewExtensionString));

  if (GLEW_VERSION_3_0)
  {
    /* TODO */
  }
  else
  {
    begin = (char *) glGetString(GL_EXTENSIONS);
    if (begin)
    {
      begin = strdup(begin);
      end = begin + strlen(begin);
      for (i=begin; i<end; i = j + 1)
      {
        i = _glewNextNonSpace(i);
        j = _glewNextSpace(i);
        *j = 0;

        /* Based on extension string(s), glewGetExtension purposes */
        enable = _glewGetExtensionString(i);
        if (enable)
          *enable = GL_TRUE;

        /* Based on extension string(s), experimental mode, glewIsSupported purposes */
        enable = _glewGetExtensionEnable(i);
        if (enable)
          *enable = GL_TRUE;
      }
      free(begin);
    }
  }
