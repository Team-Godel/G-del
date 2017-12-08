//---------------------------------------------------------------------------

#ifndef GItemH
#define GItemH
#include <Windows.h>
//---------------------------------------------------------------------------

namespace gdl
{
    // In the class, we can put a vector of items, one item instance for
    // each item in the window
    class item{
    public:
        // It is not ok, this is the advice about the interface, i mean
        // the programmer does not need and will not know nothing about
        // the winapi
        void setHandler(HWND);
        void setPosition(int, int);
        void setSize(int, int);

    private:
        HWND handler;
        int xPosition;
        int yPosition;
        int height;
        int width;
    };

}


#endif
