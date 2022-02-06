#include <windows.h>

int CALLBACK WinMain(
        HINSTANCE hInst,        // Handle to this instance of the app
        HINSTANCE hInstPrev,    // Existing instance of the program: NULL
        LPSTR cmdline,          // Cmd line for the app
        int cmdshow             // Controls how the window is shown
        )
{
    MessageBox(
        0,                          // HWND hWnd,
        "Bob.",                     // LPCTSTR lpText,
        "bob",                      // LPCTSTR lpCaption,
        MB_OK|MB_ICONINFORMATION    // UINT uType
        );

    return 0;
}

