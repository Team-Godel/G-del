#ifndef GDL_H
#define GDL_H

// Includes of the library
#include <Windows.h>
#include <string>

// Preprocessor directives
#define CLASS "gdlWindow"
#define DEFAULT_POS CW_USEDEFAULT
#define DEFAULT_WIDTH 640
#define DEFAULT_HEIGHT 480

using namespace std;


class GDL      // Class of a GDL object
{
 private:  // private members
	HWND hwnd;
	HINSTANCE hInstance;
	WNDCLASSEX wincl;

	void init(LPSTR w_title, int x, int y, int w, int h);   // private methods
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
}


static LRESULT CALLBACK WinProcRedir(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	LONG_PTR UserData = GetWindowLongPtr(hWnd, GWLP_USERDATA);
	GDL * gWindow = reinterpret_cast<GDL*>(UserData);
	return gWindow->WindowsProcedure(hWnd, Msg, wParam, lParam);
}


  public: // public methods
    GDL(HINSTANCE hInst, LPSTR w_title, int x, int y, int w, int h);
    void update();
    void showCursor(bool onOff);
    void setCursorPosition(int x, int y);
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
	wincl.cbClsExtra = NULL;
	wincl.cbWndExtra = NULL;

	RegisterClassEx(&wincl);
    // Creation of the window with the parameters of this method
	hwnd = CreateWindowEx(NULL, CLASS, w_title, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, x, y, w, h, NULL, (HMENU) NULL, hInstance, (LPVOID)this);
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

    while(GetMessage(&event, hwnd, NULL, NULL) == TRUE)    // Main loop
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
    SetCursorPos(x, y);
}



#endif // GDL_H
