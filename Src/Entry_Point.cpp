#include <iostream>
#include "GDL.hpp"


using namespace std;

int main(HINSTANCE instance, HINSTANCE previousInstance, LPTSTR lpCommandLine, int commandLineShow)
{
    gdl::GWindow* window = new gdl::GWindow(instance, "GDL Window", DEFAULT_WIN_POS, DEFAULT_WIN_POS, DEFAULT_WIDTH, DEFAULT_HEIGHT);
    gdl::GButton* button = new gdl::GButton();

    gdl::GHelp(OBJECTS_LIST);  // Show the list of all the objects
    gdl::GHelp(CONSTANTS_LIST);  // Show the list of all the constants
    gdl::GGetMethodInfos("GWindow");  // Get the infos of a method

    window->setCommandLine(commandLineShow);
    button->link(window);
    window->run();

    delete window;

    return 0;
}
