#include <windows.h>

LRESULT CALLBACK
WindowProc(HWND WindowHandle,
           UINT SystemMessage,
           WPARAM WParam,
           LPARAM LParam)
{
    LRESULT Result = 0;

    switch (SystemMessage)
    {
        case WM_CLOSE:
        {
            OutputDebugStringA("WM_CLOSE\n");
        } break;

        case WM_SIZE:
        {
            OutputDebugStringA("WM_SIZE\n");
        } break;

        case WM_DESTROY:
        {
            OutputDebugStringA("WM_DESTROY\n");
        } break;

        case WM_ACTIVATEAPP:
        {
            OutputDebugStringA("WM_ACTIVATEAPP\n");
        } break;

        case WM_PAINT:
        {
            PAINTSTRUCT Paint;
            HDC DeviceContext = BeginPaint( WindowHandle, &Paint);
            int x = Paint.rcPaint.left;
            int y = Paint.rcPaint.top;
            int w = Paint.rcPaint.right - Paint.rcPaint.left;
            int h = Paint.rcPaint.top - Paint.rcPaint.bottom;
            PatBlt(DeviceContext, x, y, w, h, WHITENESS); // requires gdi32.lib
            EndPaint( WindowHandle, &Paint);
        } break;

        default:
        {
            // OutputDebugStringA("Default: windows handled this for me.\n");
            Result = DefWindowProc(WindowHandle, SystemMessage, WParam, LParam);
        } break;
    }
    return Result;
}

int CALLBACK WinMain(
        HINSTANCE Instance,      // Handle to this instance of the app
        HINSTANCE PrevInstance,  // Existing instance of the program: NULL
        LPSTR CommandLine,       // Cmd line for the app
        int ShowCode             // Controls how the window is shown
        )
{
    WNDCLASS WindowClass = {0};

    WindowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    WindowClass.lpfnWndProc = WindowProc; // func callback
    WindowClass.hInstance = Instance;
    // WindowClass.hIcon;
    WindowClass.lpszClassName = "HandmadeHeroWindowClass"; // Name of window

    // Create a window
    if (RegisterClass(&WindowClass))
    {
        HWND WindowHandle = CreateWindowEx( 0,                                  // _In_ DWORD dwExStyle,
                                            WindowClass.lpszClassName,          // LPCSTR lpClassName,
                                            "Handmade Hero",                    // LPCSTR lpWindowName,
                                            WS_OVERLAPPEDWINDOW | WS_VISIBLE,   // DWORD dwStyle,
                                            CW_USEDEFAULT,                      // int X,
                                            CW_USEDEFAULT,                      // int Y,
                                            CW_USEDEFAULT,                      // int nWidth,
                                            CW_USEDEFAULT,                      // int nHeight,
                                            0,                                  // HWND hWndParent,
                                            0,                                  // HMENU hMenu,
                                            Instance,                           // HINSTANCE hInstance,
                                            0                                   // LPVOID lpParam
                                            );
        if (WindowHandle)
        {
            MSG Message;
            for(;;)
            {
                BOOL MessageResult = GetMessage(&Message, 0, 0, 0);
                if (MessageResult > 0)
                {
                    TranslateMessage(&Message);
                    DispatchMessage(&Message);
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            // Fail to create window. Log this.
        }
    }
    else
    {
        // Fail to register. Log this.
    }
    return 0;
}

// vim:set fdm=syntax:
