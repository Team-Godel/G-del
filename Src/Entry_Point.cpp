#include <iostream>
#include "GDL.hpp"


using namespace std;

int main(HINSTANCE instance, HINSTANCE previousInstance, LPTSTR lpCommandLine, int commandLineShow)
{
    gdl::GWindow* window = new gdl::GWindow(instance, "GDL Window", DEFAULT_WIN_POS, DEFAULT_WIN_POS, DEFAULT_WIDTH, DEFAULT_HEIGHT);
    gdl::GButton* button = new gdl::GButton();

    gdl::GodelHelp(METHODS_LIST);
    gdl::GodelHelp(CONSTANTS_LIST);

    window->setCommandLine(commandLineShow);
    button->link(window);
    window->run();

    delete window;

    return 0;
}
