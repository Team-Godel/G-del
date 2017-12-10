#include "GDL.hpp"

int APIENTRY WinMain(HINSTANCE instance, 
         HINSTANCE previousInstance, 
         LPTSTR lpCommandLine, 
         int commandLineShow){
    
    int x = 0;
    int y = 0;

    gdl::GWindow* window = new gdl::GWindow(instance, "GWindow", 10, 10, 600, 400);
    gdl::GButton* button = new gdl::GButton();
    window->setCommandLine(commandLineShow);
    button->link(window);
    window->run();
    delete window;
    
    return 0;
}