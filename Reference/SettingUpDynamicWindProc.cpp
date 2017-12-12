class GWindow : public GItem{
public:

    // Static event handler to put in WNDCLASSEX structure
    static LRESULT CALLBACK stWinMsgHandler(HWND, UINT, WPARAM, LPARAM);
private:
    // I need to analyze where I need to put the windProc, because I think
    // we can put it here, but there are a little possibility of put the
    // WndProc inside the GItem class
    
    // The real message handler
    virtual LRESULT CALLBACK WinMsgHandler(HWND, UINT, WPARAM, LPARAM);

    // Returns a pointer the window (stored as the WindowLong)
    inline static GWindow *GetObjectFromWindow(HWND hWnd)
    {
        return (GWindow*) GetWindowLong(hWnd, GWL_USERDATA); // I need to replace this statement
        // with the C++ way to cast.
    }
};

// Implementation
LRESULT CALLBACK GWindow::stWinMsgHandler(HWND handler, UINT events, WPARAM wParam, LPARAM lParam)
{
    GWindow* handlerAdress;

    if (events == WM_NCCREATE)
    {
        // Get the pointer to the window from lpCreateParams which was set in CreateWindow
        SetWindowLong(handler, GWL_USERDATA, (long)((LPCREATESTRUCT(lParam))->lpCreateParams));
    }

    // get the pointer to the window
    handlerAdress = GetObjectFromWindow(handler);

    // if we have the pointer, go to the message handler of the window
    // else, use DefWindowProc
    if (handlerAdress)
        return handlerAdress->WinMsgHandler(handler, events, wParam, lParam);
    else
        return DefWindowProc(handler, events, wParam, lParam);
}

BOOL GWindow::Create(DWORD dwStyles, RECT* rect)
{ 
    // Create the window

    // send the this pointer as the window creation parameter
    m_hwnd = CreateWindow(szClassName, szWindowTitle, dwStyles, 
        rect->left, rect->top, rect->right - rect->left, 
        rect->bottom - rect->top, NULL, NULL, hInstance, 
        (void *)this);

    return (m_hwnd != NULL);
}
