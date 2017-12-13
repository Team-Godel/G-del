#include "GButton.hpp"

namespace gdl
{
    GButton::GButton(){}
    GButton::~GButton(){}
    void GButton::link(GWindow* gwindow)
    {
        this->instance = gwindow->getInstance();
        this->handler = CreateWindow(TEXT("BUTTON"),
        TEXT("OK"),
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        200, 200, 100, 100,
        gwindow->getHandler(),
        NULL,
        (HINSTANCE)GetWindowLong(gwindow->getHandler(), GWL_HINSTANCE),
        NULL);
        SetMenu(this->handler, LoadMenu(this->instance, "ID_MENU"));  // Associate the menu with the window
    }
}
