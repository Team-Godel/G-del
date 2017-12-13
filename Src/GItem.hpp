#ifndef __GITEM_H_INCLUDE__
#define __GITEM_H_INCLUDE__

#include <iostream>
#include <string>
#include <vector>

#include <windows.h>

namespace gdl
{
    class GItem
    {
     public:
        void setInstance(HINSTANCE);
        HINSTANCE getInstance();
        void setHandler(HWND);
        HWND getHandler();
     protected:
        // Position
        int xPos;
        int yPos;
        int width;
        int height;
        // Handlers
        HINSTANCE instance;
        HWND handler;
        // Window
        WNDCLASSEX windowClass;
        LPSTR name;
    };
}

#endif
