#include <iostream>
#include "GDL.hpp"


using namespace std;

int main(HINSTANCE instance, HINSTANCE previousInstance, LPTSTR lpCommandLine, int commandLineShow)
{
    gdl::GWindow* window = new gdl::GWindow(instance, "GDL Window", 100, 100, 600, 400);
    gdl::GButton* button = new gdl::GButton();
    window->setCommandLine(commandLineShow);
    button->link(window);
    window->run();

    delete window;

    return 0;
}
