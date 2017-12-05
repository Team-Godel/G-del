#include "GDL.hpp"

using namespace std;

int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	Godel::GDL *Gobj = new Godel::GDL(hInstance, "GDL Application", DEFAULT_POS, DEFAULT_POS, 640, 480);  // Create a window
    	Gobj->showCursor(0);  // Disable the cursor
	Gobj->update();  // Update the state of the window
    	delete Gobj;
	return 0;
}
