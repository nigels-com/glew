}

#endif /* _WIN32 */

/* ------------------------------------------------------------------------ */

int main (int argc, char** argv)
{
  GLuint err;
  glutInit(&argc, argv);
  glutCreateWindow("GLEW Extension Info");
  glewExperimental = GL_TRUE;
  err = glewInit();
  if (GLEW_OK != err)
  {
    fprintf(stderr, "Error [main]: glewInit failed: %s\n", glewGetErrorString(err));
    return 1;
  }
#ifdef _WIN32
  f = fopen("glewinfo.txt", "w");
  if (f == NULL) f = stdout;
#else
  f = stdout;
#endif
  fprintf(f, "---------------------------\n");
  fprintf(f, "    GLEW Extension Info\n");
  fprintf(f, "---------------------------\n\n");
  fprintf(f, "Running on a %s from %s\n", 
	  glGetString(GL_RENDERER), glGetString(GL_VENDOR));
  fprintf(f, "OpenGL version %s is supported\n", glGetString(GL_VERSION));
  fprintf(f, "GLEW version %s is supported\n", glewGetString(GLEW_VERSION));
  glewInfo();
#ifdef _WIN32
  wglewInfo();
#else
  glxewInfo();
#endif
  if (f != stdout) fclose(f);
  return 0;
}
