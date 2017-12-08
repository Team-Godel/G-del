//---------------------------------------------------------------------------

#pragma hdrstop

#include "GButton.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace gdl{
	void GButton::altPulsed(){
        isPulsed = !isPulsed;
    }

    void GButton::link(GWindow* gdel){
		//gdel->getInstance() = this->instance; // ????
    }

	LRESULT GButton::buttonProcedure(HWND handler, UINT message, WPARAM wParam, LPARAM lParam)
    {
        switch(message)
		{
			// Variable declarations inside switch, must be have braces in <cases>
			case WM_CREATE:
			{
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
                //SetMenu(handler, LoadMenu(this->instance, "ID_MENU"));  // Associate the menu with the window
				break;
			}
			default:
				return DefWindowProc(handler, message, wParam, lParam);
        }
        return 0;
	}
}
