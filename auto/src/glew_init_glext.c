
  /* query opengl extensions string(s) */
  if(GLEW_VERSION_3_0)
  {
    GLuint len;
    struct initflag *ptr;

    glGetIntegerv(GL_NUM_EXTENSIONS, &numExts);
    for (ext = 0; ext < numExts; ext++)
    {
      extStart = glGetStringi(GL_EXTENSIONS, ext);
      len = _glewStrLen(extStart);
      ptr = in_word_set(extStart, len);

      if (ptr != NULL && ptr->flag != NULL) {
#ifdef GLEW_MX
        *(GLboolean *)((char *)ctx + (size_t)(ptr->flag)) = GL_TRUE;
#else
        *ptr->flag = GL_TRUE;
#endif
      }
      extStart += len + 1;
    }
  }
  else
  {
    extStart = glGetString(GL_EXTENSIONS);
    if (extStart == 0)
      extStart = (const GLubyte*)"";
    extEnd = extStart + _glewStrLen(extStart);

    while (extStart < extEnd)
    {
      GLuint len = _glewStrCLen(extStart, ' ');
      struct initflag *ptr = in_word_set(extStart, len);

      if (ptr != NULL && ptr->flag != NULL) {
#ifdef GLEW_MX
        *(GLboolean *)((char *)ctx + (size_t)(ptr->flag)) = GL_TRUE;
#else
        *ptr->flag = GL_TRUE;
#endif
      }
      extStart += len + 1;
    }
  }

  /* initialize extensions */
