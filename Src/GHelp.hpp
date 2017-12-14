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
"#define DEFAULT_WIN_POS CW_USEDEFAULT",
"#define DEFAULT_WIDTH 640",
"#define DEFAULT_HEIGHT 480",
"#define OBJECTS_LIST \"OBJECTS\"",
"#define CONSTANTS_LIST \"CONSTANTS\"",
"const int NB_OBJECTS = 3;",
"const int NB_CONSTANTS = 7;"};

void GHelp(std::string topic)
{
    if(topic == "OBJECTS")   // Show all the objects
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

void GGetMethodInfos(std::string method)  // Show the details of a method
{
    if(method == "GWindow"){
        std::cout << "Class: GWindow\nGWindow(HINSTANCE, LPSTR, int, int, int, int); //Constructor. Create a window\n\n" << std::endl;
    }
    else if(method == "~GWindow"){
        std::cout << "Class: GWindow\n~GWindow(); //Destructor\n\n" << std::endl;
    }
    else if(method == "showCursor"){
        std::cout << "Class: GWindow\nvoid showCursor(bool); //Enable or disable the cursor\n\n" << std::endl;
    }
    else if(method == "setCursorPosition"){
        std::cout << "Class: GWindow\nvoid setCursorPosition(int, int); //Set the cursor to a defined position\n\n" << std::endl;
    }
    else if(method == "getCursorPositionX"){
        std::cout << "Class: GWindow\nint getCursorPositionX(int*); //Get cursor's X position\n\n" << std::endl;
    }
    else if(method == "getCursorPositionY"){
        std::cout << "Class: GWindow\nint getCursorPositionY(int*); //Get cursor's Y position\n\n" << std::endl;
    }
    else if(method == "run"){
        std::cout << "Class: GWindow\nvoid run(); //Update the current state of the window\n\n" << std::endl;
    }
    else if(method == "GHelp"){
        std::cout << "Class: None\nvoid GHelp(std::string topic); //Show a list of all the objects or constants\n\n" << std::endl;
    }
    else if(method == "GGetMethodInfos"){
        std::cout << "Class: None\nvoid GGetMethodInfos(std::string method); //Show the informations of a method\n\n" << std::endl;
    }
    else{
        std::cout << "This method doesn't exist...\n\n" << std::endl;
    }
}
}

#endif // HELP_H_INCLUDED
