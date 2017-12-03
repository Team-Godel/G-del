#include "GDL.h"

using namespace std;

int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	Godel::GDL *Gobj = new Godel::GDL(hInstance, "GDL Application", DEFAULT_POS, DEFAULT_POS, 640, 480);  // Create a window

    	Godel::GodelHelp("CONSTANTS");
    	Godel::GodelHelp("METHODS");

        Gobj->showCursor(0);  // Disable the cursor
	Gobj->setCursorPosition(0, 0);  // Set the cursor to a defined position
	Gobj->update();  // Update the statement of the window

        delete Gobj;

	return 0;
}
