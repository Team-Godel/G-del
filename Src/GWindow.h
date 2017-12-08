//---------------------------------------------------------------------------

#ifndef GWindowH
#define GWindowH
//---------------------------------------------------------------------------

#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
//#include "help.hpp"
#include "GDefinitions.h"

namespace gdl
{
    class GWindow
    {
    public:
        // The first constructor, this will be overcharged (or should be
        // overcharged) just for add funtionalities and make more easy
        // its usage
		GWindow(HINSTANCE hInst, LPSTR w_title, int x, int y, int w, int h);
        void GodelHelp(std::string topic);
		void update();
		HINSTANCE getInstance();
		void showCursor(bool onOff);
		void setCursorPosition(int x, int y);
		void altMain(); // If this is the main windows, so it handle all the
		// children windows
		// void linkItem(item*); // I need find the best way for link
		// all the childrens of item
		int getCursorPositionX(int *x);
    private:
        bool isMain;
		HWND hwnd;
        WNDCLASSEX wincl;
        HINSTANCE hInstance;
		//std::vector<item*> items;
        POINT cursor; // Structure who contains the position of the cursor
        // Here i need to change the WNDCLASSEX with a WNDCLASSEX vector, just for
        // put in each class instance a vector with all its WNDCLASSEX items

		void init(LPSTR w_title, int x, int y, int w, int h);
		LRESULT WindowsProcedure(HWND, UINT, WPARAM, LPARAM);
		static LRESULT CALLBACK WinProcInicial(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK WinProcRedir(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	};

}



#endif
