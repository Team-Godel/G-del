#include <GodelLib.h>


using namespace std;

int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	GDL *Gobj = new GDL(hInstance, "GDL Application", DEFAULT_POS, DEFAULT_POS, 640, 480);

    	Gobj->showCursor(0);

	Gobj->update();
	
	// Free the object.
	delete Gobj;

	return 0;
}
