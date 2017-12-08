#ifndef SET_BUTTON_H_INCLUDED
#define SET_BUTTON_H_INCLUDED

#include "GDL.hpp"
#include "setItem.hpp"

namespace Godel{

    class button : public item{
    public:
        // The first constructor, just without parameters
        button() : isPulsed(false) {};
        void altPulsed();
        void link(GDL*); 
        // auto ifIsPulsed(callFunction);
    private:
        HINSTANCE instance;
        bool isPulsed;
        // I think that this function should be in the item class, because
        // every children of that class need to has one
        static LRESULT CALLBACK buttonProcedure(HWND, UINT, WPARAM, LPARAM);
    };

    void button::altPulsed(){
        isPulsed = !isPulsed;
    }

    void button::link(GDL* gdl){
        gdl->getInstance() = this->instance;
    }

    LRESULT button::buttonProcedure(HWND handler, UINT message, WPARAM wParam, LPARAM lParam)
    {
        switch(message)
        {
            case WM_CREATE:     
                HWND button = CreateWindow(TEXT("button"),
                                           TEXT("LOL"),
                                           WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                           0, 0, 100, 20,
                                           handler,
                                           (HMENU) button,
                                           NULL,
                                           NULL);
                // I need to implement the little trick for
                // use the this pointer in this scope
                SetMenu(handler, LoadMenu(this->instance, "ID_MENU"));  // Associate the menu with the window
                break;
            default:
                return DefWindowProc(hWnd, Msg, wParam, lParam);
        }
        return 0;
    }
}

#endif
