#include<windows.h>
#include "Window.h"
#define SBP_TIMER 201
#define CIRCLE_DIAMETER 50

//Globle callback function prototype
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Entry-point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)

{
//variable declearation
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
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(SBP_ICON));
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(SBP_ICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = szClassName;
	wndclass.lpszMenuName = NULL;

	//register window class

	RegisterClassEx(&wndclass);

	//create the window

	hwnd = CreateWindow(szClassName, TEXT("SANTOSH PHATANGARE:FIRST WINDOW"), 
	WS_OVERLAPPEDWINDOW,
	CW_USEDEFAULT,
	CW_USEDEFAULT, 
	CW_USEDEFAULT,
	CW_USEDEFAULT,
	NULL,
	NULL, 
	hInstance, 
	NULL);
	
	//show the window
	ShowWindow(hwnd, iCmdShow);

	//update the windows

	UpdateWindow(hwnd);

	//message loop

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}
	return((int)msg.wParam);
}

//callback window procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//variable decleartion
	HDC hdc=NULL;
	PAINTSTRUCT ps;
	static RECT rect;
	HBRUSH hBrush = NULL;
	static int x1 = -(CIRCLE_DIAMETER *0);
	static int x2 = -(CIRCLE_DIAMETER *1);
	
	static int x3 = -(CIRCLE_DIAMETER *2);
	static int x4 = -(CIRCLE_DIAMETER *3);
	static int x5 = -(CIRCLE_DIAMETER *4);
	static int x6 = -(CIRCLE_DIAMETER *5);
	static int x7 = -(CIRCLE_DIAMETER *6);
	static int x8 = -(CIRCLE_DIAMETER *7);
	static int x9 = -(CIRCLE_DIAMETER *8);
	static int x10= -(CIRCLE_DIAMETER *9);
	static int y = 0;
	static BOOL bReset = TRUE;
	//static int iPaintFlag=0;//default
	//TCHAR str[] = TEXT("hello world SHITAL PHATANGARE WinDev2023");
//code

	switch (iMsg)
	{
	case WM_CREATE:
		SetTimer(hwnd, SBP_TIMER, 5, NULL);
		break;
		
	case WM_PAINT:
		//1.get the painter hdc
		hdc = BeginPaint(hwnd, &ps);

		//2.get the client area rectangle
		GetClientRect(hwnd, &rect);
		if (bReset == TRUE) {
			y = (rect.bottom - rect.top) / 2;

		}
		//3.create desired color brush
		hBrush=CreateSolidBrush(RGB(255,0,0));
	

		

		
		//4.give this brush to painter
		SelectObject(hdc, hBrush);
		//y = (rect.bottom - rect.top) / 2;


		
		Ellipse(hdc,x1,y,x1+ CIRCLE_DIAMETER,y+ CIRCLE_DIAMETER);
		//6.release the brush
		if (hBrush)
		{
			DeleteObject(hBrush);
			hBrush = NULL;
		}

		
		//3.create desired color brush
		hBrush = CreateSolidBrush(RGB(128, 128, 255));





		//4.give this brush to painter
		SelectObject(hdc, hBrush);
		//y = (rect.bottom - rect.top) / 2;



		Ellipse(hdc, x2, y, x2 + CIRCLE_DIAMETER, y + CIRCLE_DIAMETER);
		//6.release the brush
		if (hBrush)
		{
			DeleteObject(hBrush);
			hBrush = NULL;
		}

		//3.create desired color brush
		hBrush = CreateSolidBrush(RGB(255, 0, 0));





		//4.give this brush to painter
		SelectObject(hdc, hBrush);
		//y = (rect.bottom - rect.top) / 2;



		Ellipse(hdc, x3, y, x3 + CIRCLE_DIAMETER, y + CIRCLE_DIAMETER);
		//6.release the brush
		if (hBrush)
		{
			DeleteObject(hBrush);
			hBrush = NULL;
		}
		//3.create desired color brush
		hBrush = CreateSolidBrush(RGB(0, 0, 255));





		//4.give this brush to painter
		SelectObject(hdc, hBrush);
		//y = (rect.bottom - rect.top) / 2;



		Ellipse(hdc, x4, y, x4 + CIRCLE_DIAMETER, y + CIRCLE_DIAMETER);
		//6.release the brush
		if (hBrush)
		{
			DeleteObject(hBrush);
			hBrush = NULL;
		}

		//3.create desired color brush
		hBrush = CreateSolidBrush(RGB(0, 255, 0));





		//4.give this brush to painter
		SelectObject(hdc, hBrush);
		//y = (rect.bottom - rect.top) / 2;



		Ellipse(hdc, x5, y, x5 + CIRCLE_DIAMETER, y + CIRCLE_DIAMETER);
		//6.release the brush
		if (hBrush)
		{
			DeleteObject(hBrush);
			hBrush = NULL;
		}
		//3.create desired color brush
		hBrush = CreateSolidBrush(RGB(255, 255, 0));





		//4.give this brush to painter
		SelectObject(hdc, hBrush);
		//y = (rect.bottom - rect.top) / 2;



		Ellipse(hdc, x6, y, x6 + CIRCLE_DIAMETER, y + CIRCLE_DIAMETER);
		//6.release the brush
		if (hBrush)
		{
			DeleteObject(hBrush);
			hBrush = NULL;
		}
		//3.create desired color brush
		hBrush = CreateSolidBrush(RGB(255, 0, 0));





		//4.give this brush to painter
		SelectObject(hdc, hBrush);
		//y = (rect.bottom - rect.top) / 2;



		Ellipse(hdc, x7, y, x7 + CIRCLE_DIAMETER, y + CIRCLE_DIAMETER);
		//6.release the brush
		if (hBrush)
		{
			DeleteObject(hBrush);
			hBrush = NULL;
		}
		//3.create desired color brush
		hBrush = CreateSolidBrush(RGB(255, 255, 255));





		//4.give this brush to painter
		SelectObject(hdc, hBrush);
		//y = (rect.bottom - rect.top) / 2;



		Ellipse(hdc, x8, y, x8 + CIRCLE_DIAMETER, y + CIRCLE_DIAMETER);
		//6.release the brush
		if (hBrush)
		{
			DeleteObject(hBrush);
			hBrush = NULL;
		}
		//3.create desired color brush
		hBrush = CreateSolidBrush(RGB(128, 128, 128));





		//4.give this brush to painter
		SelectObject(hdc, hBrush);
		//y = (rect.bottom - rect.top) / 2;



		Ellipse(hdc, x9, y, x9 + CIRCLE_DIAMETER, y + CIRCLE_DIAMETER);
		//6.release the brush
		if (hBrush)
		{
			DeleteObject(hBrush);
			hBrush = NULL;
		}
		//3.create desired color brush
		hBrush = CreateSolidBrush(RGB(255, 128, 0));





		//4.give this brush to painter
		SelectObject(hdc, hBrush);
		//y = (rect.bottom - rect.top) / 2;



		Ellipse(hdc, x10, y, x10 + CIRCLE_DIAMETER, y + CIRCLE_DIAMETER);
		//6.release the brush
		if (hBrush)
		{
			DeleteObject(hBrush);
			hBrush = NULL;
		}




		//7.end
		if (hdc)
		{
			EndPaint(hwnd, &ps);
			hdc = NULL;
		}
		
		break;


		case WM_TIMER:
			KillTimer(hwnd, SBP_TIMER);
			x1++;
			x2++;
			x3++;
			x4++;
			x5++;
			x6++;
			x7++;
			x8++;
			x9++;
			x10++;

			if (x10 > rect.right)
			{
		           x1 = -(CIRCLE_DIAMETER * 0);
				   x2 = -(CIRCLE_DIAMETER * 1);

				  x3 = -(CIRCLE_DIAMETER * 2);
				  x4 = -(CIRCLE_DIAMETER * 3);
				  x5 = -(CIRCLE_DIAMETER * 4);
				  x6 = -(CIRCLE_DIAMETER * 5);
				  x7 = -(CIRCLE_DIAMETER * 6);
				  x8 = -(CIRCLE_DIAMETER * 7);
				  x9 = -(CIRCLE_DIAMETER * 8);
				  x10 = -(CIRCLE_DIAMETER * 9);
			}

			InvalidateRect(hwnd, NULL, TRUE);
			SetTimer(hwnd, SBP_TIMER, 5, NULL);

			break;
		case WM_KEYDOWN:
			switch (LOWORD(wParam))
			{
			case VK_ESCAPE:
				DestroyWindow(hwnd);
				break;
			case VK_UP:
				bReset = FALSE;
				y = y - 5;
				if (y < rect.top)
				{
					y = rect.top;
				}
				
				break;

			case VK_DOWN:
				bReset = FALSE;
				y = y + 5;
				if (y > (rect.bottom - CIRCLE_DIAMETER))
				{
					y = rect.bottom - CIRCLE_DIAMETER;
						
				}
				
				break;
			default:
				break;
			}

			break;
		case WM_CHAR:
			switch (LOWORD(wParam))
			{
			case 'R':
			case 'r':
				bReset = TRUE;
					

				break;
			default:
				break;

			}
			break;
		case WM_LBUTTONDOWN:
			x1 = LOWORD(lParam);
			x2 = x1 - (CIRCLE_DIAMETER * 1);
			x3 = x1 - (CIRCLE_DIAMETER * 2);
			x4 = x1 - (CIRCLE_DIAMETER * 3);
			x5 = x1 - (CIRCLE_DIAMETER * 4);
			x6 = x1 - (CIRCLE_DIAMETER * 5);
			x7 = x1 - (CIRCLE_DIAMETER * 6);
			x8 = x1 - (CIRCLE_DIAMETER * 7);
			x9 = x1 - (CIRCLE_DIAMETER * 8);
			x10 = x1 -(CIRCLE_DIAMETER * 9);
			bReset = FALSE;


			y = HIWORD(lParam);
			
			break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}