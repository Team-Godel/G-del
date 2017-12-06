#ifndef SET_BUTTON_H_INCLUDED
#define SET_BUTTON_H_INCLUDED

#include "GDL.hpp"

namespace Godel{

    class button : public item{
    public:
        // The first constructor, just without parameters
        button() : isPulsed(false) {};
        // The definition of the button here
        void altPulsed();
        // auto ifIsPulsed(callFunction);
    private:
        bool isPulsed;
    };

    void button::isPulsed(){
        isPulsed = false;
    }

}

#endif