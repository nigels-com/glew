#ifdef GLEW_MX
GLboolean glewContextIsSupported (GLEWContext* ctx, const char* name)
#else
GLboolean glewIsSupported (const char* name)
#endif
{
  GLubyte* pos = (GLubyte*)name;
  GLuint len = _glewStrLen(pos);
  if(_glewStrSame2(&pos, &len, (const GLubyte*)"GL_", 3))
  {
