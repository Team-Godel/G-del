#ifndef __HELP_H_INCLUDED__
#define __HELP_H_INCLUDED__

#include <iostream>
#include <string>
#include "GDL.hpp"
#include "GConsts.hpp"

namespace gdl
{
std::string Obj[NB_OBJECTS] = {
"GWindow \n",
"GItem \n",
"GButton \n"};

std::string Const[NB_CONSTANTS] = {
"#define CLASS \"gdlWindow\"",
"#define DEFAULT_WIN_POS CW_USEDEFAULT",
"#define DEFAULT_WIDTH 640",
"#define DEFAULT_HEIGHT 480",
"#define OBJECTS_LIST \"OBJECTS\"",
"#define CONSTANTS_LIST \"CONSTANTS\"",
"const int NB_OBJECTS = 3;",
"const int NB_CONSTANTS = 6;"};

void GHelp(std::string topic)
{
    if(topic == "OBJECTS")   // Show all the methods
    {
        std::cout << "Objects" << std::endl << std::endl << std::endl;

        for(int iObj = 0; iObj < NB_OBJECTS; iObj ++){
          std::cout << Obj[iObj] << std::endl;

          if(iObj == NB_OBJECTS - 1)
            std::cout << std::endl << std::endl << std::endl;
        }
    }
    else if(topic == "CONSTANTS")  // Show all the constants
    {
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
