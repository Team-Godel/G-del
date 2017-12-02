#ifndef HELP_H_INCLUDED
#define HELP_H_INCLUDED

#include <iostream>
#include <string>
#include "GDL.h"
#include "consts.h"

namespace Godel
{
  
std::string Meth[NB_METHODS] = {"GDL(HINSTANCE instance, LPSTR title, int x, int y, int w, int h) \n- Create a window",
                                "update() \n- Update the state of a window",
                                "showCursor(bool onOff) \n- Show or not the cursor",
                                "setCursorPosition(int x, int y) \n- Set the cursor to a defined position"};

std::string Const[NB_CONSTANTS] = {"#define CLASS \"gdlWindow\""};


void GodelHelp(std::string topic)
{
    if(topic == "METHODS")   // Show all the methods
    {
        std::cout << "Methods" << std::endl << std::endl << std::endl;

        for(int iMethod = 0; iMethod < NB_METHODS; iMethod ++)
        {
          std::cout << Meth[iMethod] << std::endl << std::endl;

          if(iMethod == NB_METHODS - 1)
          {
            std::cout << std::endl << std::endl << std::endl;
          }
        }
    }
    else if(topic == "CONSTANTS")  // Show all the constants
    {
        std::cout << "Constants" << std::endl << std::endl << std::endl;

        for(int iConst = 0; iConst < NB_CONSTANTS; iConst ++)
        {
          std::cout << Const[iConst] << std::endl << std::endl;

          if(iConst == NB_CONSTANTS - 1)
          {
            std::cout << std::endl << std::endl << std::endl;
          }
        }
    }
}
  
}
#endif // HELP_H_INCLUDED
