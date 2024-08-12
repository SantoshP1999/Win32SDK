/*
	Objectives of the code
	GetClientRect() is not related to painting
	*/

#include<windows.h>

#include "Window.h"

//Global callback function prototype
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

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
	HDC hdc=NULL;
	PAINTSTRUCT ps;
	static RECT rect;
	TCHAR str[] = TEXT("Hello World Santosh Phatangare WinDev 2023");
	
	//Code
	switch (iMsg)
	{

	case WM_CREATE:
		GetClientRect(hwnd, &rect);
		break;

	case WM_PAINT:
	//case WM_LBUTTONDOWN:
		//step 1:Get the Painter :HDC
		hdc = BeginPaint(hwnd, &ps);

		//step 2:Get the Client Area Rectangle :RECT
		//GetClientRect(hwnd, &rect);

		//step 3:Set Text Background color to Black
		SetBkColor(hdc, RGB(0, 0, 0));

		//Step 4:Set the Text Color to Green 
		SetTextColor(hdc, RGB(0,255,0));

		//step 5:Draw the Text on The Window 
		DrawText(hdc, str, -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		

		//Step 6:
			//EndPaint(hwnd, &ps);
			if (hdc)
			{
				EndPaint(hwnd, &ps);
				hdc = NULL;
			}
			
			//hdc = BeginPaint(hwnd, &ps);
			
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		break;
	}
	return (DefWindowProc(hwnd, iMsg, wParam, lParam));

}