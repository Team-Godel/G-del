#ifndef __GWINDOW_H_INCLUDED__
#define __GWINDOW_H_INCLUDED__

#include "GItem.hpp"
#include "GConsts.hpp"

#include <string>

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
        // A test message
        std::string testMessage = "I am running dynamicly!";
        // Static and original windowProcess
        static LRESULT CALLBACK initialWindowProcess(HWND, UINT, WPARAM, LPARAM);
        // redirectionWindowProcess
        static LRESULT CALLBACK windowProcessRedirection(HWND, UINT, WPARAM, LPARAM);
        // Dynamic windowProcess
        LRESULT windowProcess(HWND, UINT, WPARAM, LPARAM);
        int commandLine;         
        POINT cursor;
    };
}

#endif
