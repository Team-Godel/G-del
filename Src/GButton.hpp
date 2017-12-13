#ifndef __GBUTTON_H_INCLUDED__
#define __GBUTTON_H_INCLUDED__

#include "GButton.hpp"
#include "GWindow.hpp"

namespace gdl
{
    class GButton : public GItem
    {
     public:
        GButton();
        ~GButton();
        void link(GWindow*);
 //  private:
//      doSomethingWithTheButton();
    };
}

#endif
