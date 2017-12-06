#ifndef GDL_H_INCLUDED
#define GDL_H_INCLUDED

#include <iostream>
#include <Windows.h>
#include <string>
#include "help.hpp"
#include "consts.hpp"

namespace Godel
{
    class GDL
    {
    public:
        // The first constructor, this will be overcharged (or should be
        // overcharged) just for add funtionalities and make more easy
        // its usage
        GDL(HINSTANCE hInst, LPSTR w_title, int x, int y, int w, int h);
        void GodelHelp(std::string topic);
        void update();
        void showCursor(bool onOff);
        void setCursorPosition(int x, int y);
        // void setItem(item*); 
        void altMain(); // If this is the main windows, so it handle all the
        // children windows
    private:
        bool isMain;
        HWND hwnd;
        HINSTANCE hInstance;
        WNDCLASSEX wincl;
        // Here i need to change the WNDCLASSEX with a WNDCLASSEX vector, just for
        // put in each class instance a vector with all its WNDCLASSEX items

        void init(LPSTR w_title, int x, int y, int w, int h);
        LRESULT WindowsProcedure(HWND, UINT, WPARAM, LPARAM);
        static LRESULT CALLBACK WinProcInicial(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
        {
            if (Msg == WM_NCCREATE)
            {
                LPCREATESTRUCT CreateStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
                void * lpCreateParam = CreateStruct->lpCreateParams;
                GDL * gWindow = reinterpret_cast<GDL*>(lpCreateParam);
                SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(gWindow));
                SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&GDL::WinProcRedir));
            }
            return DefWindowProc(hWnd, Msg, wParam, lParam);
        };
        static LRESULT CALLBACK WinProcRedir(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
        {
            LONG_PTR UserData = GetWindowLongPtr(hWnd, GWLP_USERDATA);
            GDL * gWindow = reinterpret_cast<GDL*>(UserData);
            return gWindow->WindowsProcedure(hWnd, Msg, wParam, lParam);
        };
    };

    GDL::GDL(HINSTANCE hInst, LPSTR w_title, int x, int y, int w, int h) // Method called to create an instance of a window
    {
        hInstance = hInst;
        init(w_title, x, y, w, h);  // Call the function to call the window
    }

    void GDL::init(LPSTR w_title, int x, int y, int w, int h)    // Method to create a personalized window
    {
        wincl.hInstance = hInstance;
        wincl.lpszClassName = CLASS;
        wincl.hbrBackground = (HBRUSH)(COLOR_BTNFACE+1);   // Background color of the window
        wincl.lpfnWndProc = &GDL::WinProcInicial;
        wincl.style = CS_DBLCLKS;
        wincl.cbSize = sizeof(WNDCLASSEX);
        wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
        wincl.hCursor = LoadCursor(NULL, IDC_ARROW);  // Cursor of the window
        wincl.lpszMenuName = NULL;
        wincl.cbClsExtra = 0;
        wincl.cbWndExtra = 0;

        RegisterClassEx(&wincl);
        hwnd = CreateWindow(CLASS, w_title, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, x, y, w, h, NULL, (HMENU) NULL, hInstance, (LPVOID)this);
    }

    LRESULT GDL::WindowsProcedure(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) // Events
    {
        switch(Msg)
        {
            case WM_DESTROY:     // if we quit the application
                PostQuitMessage(0);
                break;
            default:
                return DefWindowProc(hWnd, Msg, wParam, lParam);
        }
        return 0;
    }   

    void GDL::update()
    {
        MSG event;
        ShowWindow(hwnd, SW_SHOWDEFAULT);
        UpdateWindow(hwnd);
        while(GetMessage(&event, hwnd, 0, 0) == TRUE)    // Main loop
        {
            TranslateMessage(&event);
            DispatchMessage(&event);  // Send the event (message) to the winProc function
        }
    }   

    void GDL::showCursor(bool onOff)  // Disable or Enable the cursor
    {
        ShowCursor(onOff);
    }

    void GDL::setCursorPosition(int x, int y)  // Set the cursor to a defined position
    {
        SetCsurorPos(x, y);
    }    

    void GDL::altMain()
    {
        isMain = !isMain;
    }

}
#endif // GDL_H_INCLUDED
