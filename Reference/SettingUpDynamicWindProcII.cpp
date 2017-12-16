class GWindow : public GItem{
public:
    // The original windproc
    static LRESULT CALLBACK stWinMsgHandler(HWND, UINT, WPARAM, LPARAM);
private:
    // The msgHandler?
    virtual LRESULT CALLBACK WinMsgHandler(HWND, UINT, WPARAM, LPARAM);

    // A function that return a pointer to the window, from the GWL_USERDATA
    inline static GWindow *GetObjectFromWindow(HWND hWnd)
    {
        return (GWindow*) GetWindowLong(hWnd, GWL_USERDATA);
    }
};

// The original windproc implementation
LRESULT CALLBACK GWindow::stWinMsgHandler(HWND handler, UINT events, WPARAM wParam, LPARAM lParam)
{
    // A instance of the GWindow class
    GWindow* handlerAdress;

    // If the event is just the window creation
    if (events == WM_NCCREATE)
    {
        // You change the attributes of the window. You access to the handler
        // of the window and you set the user data (a storage for customized 
        // purposes) as the long cast to the parameters of the creation of the 
        // current window
        SetWindowLong(handler, GWL_USERDATA, (long)((LPCREATESTRUCT(lParam))->lpCreateParams));
    }

    // Also, we are instantiating the GWindow as the return of the
    // GetObjectFromWindow(handler), this is, the object handler
    // from the window handler 
    handlerAdress = GetObjectFromWindow(handler);

    // If everything is fine, and the handlerAdress could be instantiated, so
    // the wndproc return the WinMsgHandler from the class, (another wndproc)
    if (handlerAdress)
        return handlerAdress->WinMsgHandler(handler, events, wParam, lParam);
    // If it could not load all, so return the clasic DefWindowProc, the
    // DefWindowProc is a windproc that work when the event were not 
    // defined. 
    else
        return DefWindowProc(handler, events, wParam, lParam);
}

// Now, the implementation of the create function.
BOOL GWindow::Create(DWORD dwStyles, RECT* rect)
{ 
    m_hwnd = CreateWindow(szClassName, szWindowTitle, dwStyles, 
        rect->left, rect->top, rect->right - rect->left, 
        rect->bottom - rect->top, NULL, NULL, hInstance, 
        (void *)this);

    return (m_hwnd != NULL);
}
