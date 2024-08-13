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
	RECT rect;
	HBRUSH hBrush = NULL;
	static int iPaintFlag =0;	//default
	//TCHAR str[] = TEXT("Hello World Santosh Phatangare WinDev 2023");
	
	//Code
	switch (iMsg)
	{
	case WM_PAINT:
		//step 1:Get the Painter :HDC
		hdc = BeginPaint(hwnd, &ps);

		//step 2:Get the Client Area Rectangle :RECT
		GetClientRect(hwnd, &rect);


		//step 3 :Create Brush of Desired Color
		hBrush = CreateSolidBrush(RGB(255, 0, 0));
		if (iPaintFlag == 1)
		{
			hBrush = CreateSolidBrush(RGB(255, 0, 0));
		}
		else if (iPaintFlag == 2)
		{
			hBrush = CreateSolidBrush(RGB(0, 255, 0));
		}
		else if (iPaintFlag == 3)
		{
			hBrush = CreateSolidBrush(RGB(0, 0, 255));
		}
		else if (iPaintFlag == 4)
		{
			hBrush = CreateSolidBrush(RGB(0, 255, 255));
		}
		else if (iPaintFlag == 5)
		{
			hBrush = CreateSolidBrush(RGB(255, 0, 255));
		}
		else if (iPaintFlag == 6)
		{
			hBrush = CreateSolidBrush(RGB(255, 255, 0));
		}
		else if (iPaintFlag == 7)
		{
			hBrush = CreateSolidBrush(RGB(255, 255, 255));
		}
		else if(iPaintFlag == 8)
		{
			hBrush = CreateSolidBrush(RGB(0, 0, 0));
		}
		else
		{
			hBrush = CreateSolidBrush(RGB(128, 128, 128));
		}
		

		//Step 4:Give this brush to the Painter
		SelectObject(hdc, hBrush);

		//step 5:Color the Window Client Area with the selected Brush 
		FillRect(hdc,&rect,hBrush);
		

		//Step 6:Release the Brush
		if (hBrush)
		{
			DeleteObject(hBrush);
			hBrush = NULL;
		}
		 
		//Step 7:End Paint
			//EndPaint(hwnd, &ps);
			if (hdc)
			{
				
				EndPaint(hwnd, &ps);
				hdc = NULL;
			}
			
			//hdc = BeginPaint(hwnd, &ps);
			
		break;

	case WM_LBUTTONDOWN:
		iPaintFlag++;

		if (iPaintFlag > 8)
		{
			iPaintFlag = 0;
		}

		InvalidateRect(hwnd, NULL, TRUE);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
		
	default:
		break;
	}
	return (DefWindowProc(hwnd, iMsg, wParam, lParam));

}