
  /* get extensions */
  if (GLEW_VERSION_3_0 == GL_TRUE)
  {
    GLint numExt;
    GLint i;
    glGetIntegerv(GL_NUM_EXTENSIONS, &numExt);

    for(i = 0; i < numExt; ++i)
    {
      extArray[i] = glGetStringi(GL_EXTENSIONS, i);
    }

    extArrayStart = &extArray[0];
    extArrayEnd   = &extArray[i];
  }
  else
  {
    int i;

    extStart = glGetString(GL_EXTENSIONS);
    if (extStart == 0)
      extStart = (const GLubyte*)"";
    extEnd = extStart + _glewStrLen(extStart);
    i = 0;

    while (extStart < extEnd)
    {
      int len = _glewStrCLen(extStart, ' ');

      if (len > 0)
      {
        extArray[i] = extStart;
        i += 1;
      }

      extStart += len + 1;
    }

    extArrayStart = &extArray[0];
    extArrayEnd   = &extArray[i];
  }

  /* initialize extensions */
