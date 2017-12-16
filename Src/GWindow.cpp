#include "GWindow.hpp"

#include <iostream>

namespace gdl
{
    // Constructor
    GWindow::GWindow(HINSTANCE instance, LPSTR name, int xPos, int yPos, int height, int width)
    {
        // Setting the class
        this->instance = instance;
        this->name = name;
        // Setting the position
        this->xPos = xPos;
        this->yPos = yPos;
        this->width = height;
        this->height = width;
        // Setting the structure
        if(!GetClassInfoEx(this->instance, this->name, &this->windowClass)){
            this->windowClass.hInstance = this->instance;
            this->windowClass.lpszClassName = this->name;
            this->windowClass.hbrBackground = (HBRUSH)(COLOR_BTNFACE+1);
            // Here is the pointer to the windproc
            this->windowClass.lpfnWndProc = initialWindowProcess;
            this->windowClass.style = CS_DBLCLKS;
            this->windowClass.cbSize = sizeof(WNDCLASSEX);
            this->windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
            this->windowClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
            this->windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
            this->windowClass.lpszMenuName = NULL;
            this->windowClass.cbClsExtra = 0;
            this->windowClass.cbWndExtra = 0;
            if (RegisterClassEx(&this->windowClass) == 0)
            {
                MessageBox(NULL,"The window class failed to register.","Error",0);
                delete this;
            }
        }
    }

    // Destructor
    GWindow::~GWindow(){}

    // initialWindowProcess
    LRESULT CALLBACK GWindow::initialWindowProcess(HWND handler, UINT message, WPARAM wParam, LPARAM lParam)
    {
        if(message == WM_NCCREATE){
            LPCREATESTRUCT dynamicStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
            void* thisStorage = dynamicStruct->lpCreateParams;
            GWindow* thisWindow = reinterpret_cast<GWindow*>(thisStorage);
            SetWindowLongPtr(handler, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(thisWindow));
            SetWindowLongPtr(handler, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&GWindow::windowProcessRedirection));
        }
        return DefWindowProc(handler, message, wParam, lParam);
    }

    // windowProcessRedirection
    LRESULT CALLBACK GWindow::windowProcessRedirection(HWND handler, UINT message, WPARAM wParam, LPARAM lParam)
    {
        LONG_PTR userData = GetWindowLongPtr(handler, GWLP_USERDATA);
        GWindow* thisWindow = reinterpret_cast<GWindow*>(userData);
        return thisWindow->windowProcess(handler, message, wParam, lParam);
    }

    // dynamic windowProcess
    LRESULT GWindow::windowProcess(HWND handler, UINT message, WPARAM wParam, LPARAM lParam)
    {
        switch (message)
        {
	        case WM_DESTROY:
                // The test!
                std::cout << this->testMessage << std::endl;
                PostQuitMessage(0);
		        break;
            default:
                return DefWindowProc(handler, message, wParam, lParam);
	    }
	    return 0;
    }

    // Run
    void GWindow::run(){
        this->handler = CreateWindow(this->name,
                                     this->name, 
                                     WS_VISIBLE | WS_OVERLAPPEDWINDOW, 
                                     this->xPos, 
                                     this->yPos, 
                                     this->width, 
                                     this->height, 
                                     NULL, 
                                     NULL, 
                                     this->instance, 
                                     this);
        BOOL booleanReturn;
        MSG events;
        ShowWindow(this->handler, this->commandLine);
    	UpdateWindow(this->handler);
        while(booleanReturn = GetMessage(&events, 0, 0, 0 ))
        {
            TranslateMessage(&events);
            DispatchMessage(&events);
        }
    }

    // SetCommandLine
    void GWindow::setCommandLine(int commandLineShow){
        this->commandLine = commandLineShow;
    }

    // ShowCursor
    void GWindow::showCursor(bool isShowed){
        ShowCursor(isShowed);
    }

    // SetCursorPosition
    void GWindow::setCursorPosition(int x, int y)  // Set the cursor to a defined position
    {
        SetCursorPos(x, y);
    }

    // GetCursorPositionX
    int GWindow::getCursorPositionX(int* x){
        GetCursorPos(&this->cursor);
        *x = cursor.x;
        return cursor.x;
    }

    // GetCursorPositionY
    int GWindow::getCursorPositionY(int* y){
        GetCursorPos(&this->cursor);
        *y = cursor.y;
        return cursor.y;
    }
}
