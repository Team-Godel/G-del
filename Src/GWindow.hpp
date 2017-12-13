#ifndef __GWINDOW_H_INCLUDED__
#define __GWINDOW_H_INCLUDED__

#include "GItem.hpp"
#include "GConsts.hpp"

namespace gdl
{
    class GWindow : public GItem
    {
     public:
        // Constructor and destructor
        GWindow(HINSTANCE, LPSTR, int, int, int, int);
        ~GWindow();
        // ...
        void setCommandLine(int);
        void run();
        // Cursor Methods
        void showCursor(bool);
        void setCursorPosition(int, int);
        int getCursorPositionX(int*);
        int getCursorPositionY(int*);

     private:
        static LRESULT CALLBACK windowProcedure(HWND, UINT, WPARAM, LPARAM);
        int commandLine;         
        POINT cursor;
    };
}

#endif
