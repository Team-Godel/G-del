#ifndef __HELP_H_INCLUDED__
#define __HELP_H_INCLUDED__

#include <iostream>
#include <string>
#include "GDL.hpp"
#include "GConsts.hpp"

namespace gdl
{
std::string Meth[NB_METHODS] = {
"GDL(HINSTANCE instance, LPSTR title, int x, int y, int w, int h) \n- Create a window",
"update() \n- Update the state of a window",
"showCursor(bool onOff) \n- Show or not the cursor",
"setCursorPosition(int x, int y) \n- Set the cursor to a defined position"};

std::string Const[NB_CONSTANTS] = {
"#define CLASS \"gdlWindow\"",
"#define DEFAULT_POS CW_USEDEFAULT",
"#define DEFAULT_WIDTH 640",
"#define DEFAULT_HEIGHT 480",
"#define METHODS_LIST \"METHODS\"",
"#define CONSTANTS_LIST \"CONSTANTS\"",
"const int NB_METHODS = 4;",
"const int NB_CONSTANTS = 6;"};

void GodelHelp(std::string topic)
{
    if(topic == "METHODS"){   // Show all the methods
        std::cout << "Methods" << std::endl << std::endl << std::endl;

        for(int iMethod = 0; iMethod < NB_METHODS; iMethod ++){
          std::cout << Meth[iMethod] << std::endl << std::endl;

          if(iMethod == NB_METHODS - 1)
            std::cout << std::endl << std::endl << std::endl;
        }
    }
    else if(topic == "CONSTANTS"){  // Show all the constants
        std::cout << "Constants" << std::endl << std::endl << std::endl;

        for(int iConst = 0; iConst < NB_CONSTANTS; iConst ++){
          std::cout << Const[iConst] << std::endl << std::endl;

          if(iConst == NB_CONSTANTS - 1) 
            std::cout << std::endl << std::endl << std::endl; 
        }
    }
}  
}
#endif // HELP_H_INCLUDED
