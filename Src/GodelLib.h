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


class GDL
{
 private:
	HWND hwnd;
	HINSTANCE hInstance;
	WNDCLASSEX wincl;

	void init(LPSTR w_title, int x, int y, int w, int h);
	// The dynamic procces of the window
	LRESULT WindowProcedure(HWND, UINT, WPARAM, LPARAM);

// Process of the main window, just for initialization (i think just for initialization of another windows)
static LRESULT CALLBACK WinProcInitial(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	// If the event is the window creation, so...
	 if (Msg == WM_NCCREATE)
	 {
		 // Lparam contain a reference to a structure of kind:
		 LPCREATESTRUCT CreateStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
		 // The pointer is on the lpCreateParams
		 void * lpCreateParam = CreateStruct->lpCreateParams;
		 // Creating a reference to the class pointered by "this"
		 GDL * gWindow = reinterpret_cast<GDL*>(lpCreateParam);
		 // Storing the "this" pointer in USERDATA section
		 SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(gWindow));
		 // Changing the direction of the window process
		 SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&GDL::WinProcRedir));
	 }
	// If it is not the event or just we finish, so...
	return DefWindowProc(hWnd, Msg, wParam, lParam);
}

static LRESULT CALLBACK WinProcRedir(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	// Do you remember that we store the pointer to the class in the USERDATA section?
	// We are now recovering that pointer
	LONG_PTR UserData = GetWindowLongPtr(hWnd, GWLP_USERDATA);
	// Now, we create a new pointer to a GDL object, and assign to it the dirrection stored in UserData
	// "Construying the class"
	GDL * gWindow = reinterpret_cast<GDL*>(UserData);
	// Calling the dinamic procedure defined in the class
	return gWindow->WindowProcedure(hWnd, Msg, wParam, lParam);
}

public: 
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
	wincl.lpfnWndProc = &GDL::WinProcInitial;
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

// The dinamic window process
LRESULT GDL::WindowProcedure(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) // Events
{
	// Manage the events of the window until now, you can use this procedure normaly like the another Window procedure ^^
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
