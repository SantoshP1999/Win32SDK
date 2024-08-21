#include<windows.h>

#include "Window.h"

//Global callback function prototype
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Global Declarations of Threads
DWORD WINAPI ThreadProcOne(LPOID);
DWORD WINAPI ThreadProcTwo(LPVOID);

//Entry point function
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpszCmdLine,
	int iCmdShow)
{
	//Variable declarations
	WNDCLASSEX wndclass;
	TCHAR szClassName[] = TEXT("MyFirstWindow");
	HWND hwnd;
	MSG msg;

	//Code
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);//BLACK_BRUSH
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(SBP_ICON));
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(SBP_ICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = szClassName;
	wndclass.lpszMenuName = NULL;

	//Register Window Class
	RegisterClassEx(&wndclass);

	//Create the Window
	hwnd = CreateWindow(szClassName, TEXT("Santosh Phatangare:First Window"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

		//Show The Window
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

//Callback Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{


	//Variable Declarations
	static HANDLE hThread1 = NULL;
	static HANDLE hThread2 = NULL;
	
	//Code
	switch (iMsg)
	{
	case WM_CREATE:
		hThread1 = CreateThread(NULL,		
			0,
			(LPTHREAD_START_ROUTINE)ThreadProcOne,
			(LPVOID)hwnd,
			0,
			NULL);

		hThread2 = CreateThread(NULL,
			0,
			(LPTHREAD_START_ROUTINE)ThreadProcTwo,
			(LPVOID)hwnd,
			0,
			NULL);

		break;

	case WM_LBUTTONDOWN:
		MessageBox(hwnd, TEXT("HELLO SANTOSH"), TEXT("MESSAGE"), MB_OK | MB_ICONINFORMATION);
		
		break;

	case WM_DESTROY:
		if (hThread2)
		{
			CloseHandle(hThread2);
			hThread2 = NULL;
		}

		if (hThread1)
		{
			CloseHandle(hThread1);
			hThread1 = NULL;
		}

		PostQuitMessage(0);
		break;

	default:
		break;
	}
	return (DefWindowProc(hwnd, iMsg, wParam, lParam));

}

//Defining Function body for ThreadProcOne
DWORD WINAPI ThreadProcOne(LPVOID param)
{
	//variable Declarations
	HDC hdc;
	unsigned long i;
	TCHAR str[255];

	//code
	hdc = GetDC((HWND)param);

	SetBkColor(hdc, RGB(0, 0, 0));
	SetTextColor(hdc, RGB(0, 255, 0));

	
	//Long_MAX=0;
	for (i = 0; i <= LONG_MAX; i++)
	{
		wsprintf(str, TEXT("Incrementing : %d"), i);
		TextOut(hdc, 5, 5, str, wcslen(str));
	}
	
	ReleaseDC((HWND)param, hdc);
	hdc = NULL;
	return 0;
}


//Defining Function body for ThreadProcTwo
DWORD WINAPI ThreadProcTwo(LPVOID param)
{
	//variable Declarations
	HDC hdc;
	unsigned long i;
	TCHAR str[255];

	//code
	hdc = GetDC((HWND)param);

	SetBkColor(hdc, RGB(0, 0, 0));
	SetTextColor(hdc, RGB(255, 0, 0));


	//Long_MAX=0;
	
	for (i = LONG_MAX; i >= 0; i--)
	{
		wsprintf(str, TEXT("Decrementing: %d"), i);
		TextOut(hdc, 5, 20, str, wcslen(str));
	}
	ReleaseDC((HWND)param, hdc);
	hdc = NULL;
	return 0;
}
	

	
	



