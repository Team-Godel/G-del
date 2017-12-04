#include "GDL.h"

using namespace std;

int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    int x = 0;
    int y = 0;

    Godel::GDL *Gobj = new Godel::GDL(hInstance, "GDL Application", DEFAULT_POS, DEFAULT_POS, 640, 480);  // Create a window

    Godel::GodelHelp("CONSTANTS");
    Godel::GodelHelp("METHODS");

    Gobj->showCursor(0);  // Disable the cursor
    Gobj->setCursorPosition(110, 120);  // Set the cursor to a defined position

    Gobj->getCursorPositionX(&x);  // Get cursor x position by using a pointer or returning the value
    Gobj->getCursorPositionY(&y);  // Get cursor y position by using a pointer or returning the value

    std::cout << x << std::endl;
    std::cout << y << std::endl;

    Gobj->update();  // Update the statement of the window


    delete Gobj;

    return 0;
}
