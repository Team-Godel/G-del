#include <iostream>
#include "GDL.hpp"


using namespace std;

int main(HINSTANCE instance, HINSTANCE previousInstance, LPTSTR lpCommandLine, int commandLineShow)
{
    int x = 0;
    int y = 0;

    gdl::GWindow* window = new gdl::GWindow(instance, "GDL Window", 100, 100, 600, 400);
    gdl::GButton* button = new gdl::GButton();
    window->setCommandLine(commandLineShow);
    button->link(window);
    window->run();

    delete window;

    return 0;
}
