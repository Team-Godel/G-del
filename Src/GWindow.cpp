#include "GWindow.hpp"

namespace gdl
{
    // Constructor
    GWindow::GWindow
    (HINSTANCE instance, LPSTR name, int xPos, int yPos, int height, int width){
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
            this->windowClass.lpfnWndProc = windowProcedure;
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

    // WindowProcedure
    LRESULT CALLBACK GWindow::windowProcedure // This can change
    (HWND handler, UINT Message, WPARAM wParam, LPARAM lParam){
        switch(Message)
        {
            case WM_CREATE:
                std::cout << "Window succesfully created !" << std::endl;
                break;
            case WM_DESTROY:
                std::cout << "Window succesfully destroyed !" << std::endl;
                PostQuitMessage(0);
                break;
            default:
                return DefWindowProc(handler, Message, wParam, lParam);
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
