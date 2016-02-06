#ifdef GLEW_BUILD
#include <windows.h>
BOOL WINAPI DllMainCRTStartup(HINSTANCE instance, DWORD reason, LPVOID reserved)
{
  return TRUE;
}
#endif