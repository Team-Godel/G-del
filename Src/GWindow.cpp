// ---------------------------------------------------------------------------

#pragma hdrstop

#include "GWindow.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

namespace gdl
{
	GWindow::GWindow(HINSTANCE hInst, LPSTR w_title, int x, int y, int w,
		int h) // Method called to create an instance of a window
	{
		hInstance = hInst;
		init(w_title, x, y, w, h); // Call the function to call the window
	}

	void GWindow::init(LPSTR w_title, int x, int y, int w, int h)
		// Method to create a personalized window
	{
		wincl.hInstance = hInstance;
		wincl.lpszClassName = CLASS;
		wincl.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
		// Background color of the window
		wincl.lpfnWndProc = &GWindow::WinProcInicial;
		wincl.style = CS_DBLCLKS;
		wincl.cbSize = sizeof(WNDCLASSEX);
		wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		wincl.hCursor = LoadCursor(NULL, IDC_ARROW); // Cursor of the window
		wincl.lpszMenuName = NULL;
		wincl.cbClsExtra = 0;
		wincl.cbWndExtra = 0;

		RegisterClassEx(&wincl);
		hwnd = CreateWindow(CLASS, w_title,
			WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, x, y, w, h, NULL,
			(HMENU) NULL, hInstance, (LPVOID)this);
	}

	LRESULT GWindow::WindowsProcedure(HWND hWnd, UINT Msg, WPARAM wParam,
		LPARAM lParam) // Events
	{
		switch (Msg)
		{
		case WM_DESTROY: // if we quit the application
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, Msg, wParam, lParam);
		}
		return 0;
	}

	void GWindow::update()
	{
		MSG event;
		ShowWindow(hwnd, SW_SHOWDEFAULT);
		UpdateWindow(hwnd);
		while (GetMessage(&event, hwnd, 0, 0) == TRUE) // Main loop
		{
			TranslateMessage(&event);
			DispatchMessage(&event);
			// Send the event (message) to the winProc function
		}
	}

	// CURSOR METHODS

	void GWindow::showCursor(bool onOff) // Disable or Enable the cursor
	{
		ShowCursor(onOff);
	}

	void GWindow::setCursorPosition(int x, int y)
		// Set the cursor to a defined position
	{
		SetCursorPos(x, y);
	}

	void GWindow::altMain()
	{
		isMain = !isMain;
	}

		// Get the current X position of the cursor
	int GWindow::getCursorPositionX(int *x)
	{
		GetCursorPos(&cursor);
		*x = cursor.x;
		return cursor.x;
	}

	HINSTANCE GWindow::getInstance()
	{
		return this->hInstance;
	}

	LRESULT CALLBACK GWindow::WinProcInicial(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
	{
		if (Msg == WM_NCCREATE)
		{
			LPCREATESTRUCT CreateStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
			void * lpCreateParam = CreateStruct->lpCreateParams;
			GWindow * gWindow = reinterpret_cast<GWindow*>(lpCreateParam);
			SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(gWindow));
			SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&GWindow::WinProcRedir));
		}
		return DefWindowProc(hWnd, Msg, wParam, lParam);
	}
	LRESULT CALLBACK GWindow::WinProcRedir(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
	{
		LONG_PTR UserData = GetWindowLongPtr(hWnd, GWLP_USERDATA);
		GWindow * gWindow = reinterpret_cast<GWindow*>(UserData);
		return gWindow->WindowsProcedure(hWnd, Msg, wParam, lParam);
	}

	// void GDL::linkItem(item* Item)
	// {
	// items.push_back(Item);
	// }

}
