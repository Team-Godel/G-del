
#include <GDL.hpp>

using namespace std;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	GDL *Gobj = new GDL(hInstance);

	Gobj->update();

	return 0;
}
