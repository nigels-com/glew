  }
#elif !defined(__APPLE__) || defined(GLEW_APPLE_GLX)
  else if(_glewStrSame2(&pos, &len, (const GLubyte*)"GLX_", 4))
  {
