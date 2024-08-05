#include<windows.h>

//Global callback function prototype
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

//Entry point function
int WINAPI WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpszCmdLine,
    int iCmdShow)
{
    //Variable Declarations
    WNDCLASSEX wndclass;
    TCHAR szClassName[] = TEXT("MyFirstWindow");
    HWND hwnd;
    MSG msg;

    //code
    wndclass.cbSize = sizeof(WNDCLASSEX);
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpfnWndProc = WndProc;
    wndclass.lpszClassName = szClassName;
    wndclass.lpszMenuName = NULL;

    //Register Window class
    RegisterClassEx(&wndclass);

    //Create the Window
    hwnd = CreateWindow(szClassName,
        TEXT("SANTOSH PHATANGARE:First Window"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL);

    //Show the Window
    ShowWindow(hwnd, iCmdShow);

    //Update the Window
    UpdateWindow(hwnd);

    //Message Loop
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return((int)msg.wParam);
}

    //callback Window Procedure
    LRESULT CALLBACK WndProc(HWND hwnd,UINT iMsg,WPARAM wParam,LPARAM lParam)
    {
        //code
        switch(iMsg)
        {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;

            default:
            break;
        }
        return(DefWindowProc(hwnd,iMsg,wParam,lParam));
    }

