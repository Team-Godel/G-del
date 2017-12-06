#ifndef SET_ITEM_H_INCLUDED
#define SET_ITEM_H_INCLUDED

#include "GDL.hpp"

namespace Godel{
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

    void item::setHandler(hwnd handler){
        this->handler = handler;
    };
    
    void setPosition(int x, int y){
        this->xPosition = x;
        this->yPosition = y;
    };

    void setSize(int height, int width){
        this->height = height;
        this->width = width;
    };

}

#endif //SET_ITEM_H_INCLUDED