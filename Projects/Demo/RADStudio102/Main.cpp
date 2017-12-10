#include <windows.h>

#pragma hdrstop

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include "../../../Src/Godel.h"


int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	gdl::GWindow wnd(hInstance, "My Window", 0, 0, 640, 480);
	wnd.update();
	return 0;
}
