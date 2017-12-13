#include "GItem.hpp"

namespace gdl
{

    void GItem::setInstance(HINSTANCE instance){
        this->instance = instance;
    }

    HINSTANCE GItem::getInstance(){
        return this->instance;
    }

    void GItem::setHandler(HWND handler){
        this->handler = handler;
    }

    HWND GItem::getHandler(){
        return this->handler;
    }

}
