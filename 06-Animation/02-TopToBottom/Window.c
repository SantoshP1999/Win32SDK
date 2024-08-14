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
	static int y1 = -(CIRCLE_DIAMETER *0);
	static int y2 = -(CIRCLE_DIAMETER *1);
	
	static int y3 = -(CIRCLE_DIAMETER *2);
	static int y4 = -(CIRCLE_DIAMETER *3);
	static int y5 = -(CIRCLE_DIAMETER *4);
	static int y6 = -(CIRCLE_DIAMETER *5);
	static int y7 = -(CIRCLE_DIAMETER *6);
	static int y8 = -(CIRCLE_DIAMETER *7);
	static int y9 = -(CIRCLE_DIAMETER *8);
	static int y10= -(CIRCLE_DIAMETER *9);
	static int x = 0;
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
			x = (rect.right - rect.left) / 2;

		}
		//3.create desired color brush
		hBrush=CreateSolidBrush(RGB(255,0,0));
	

		

		
		//4.give this brush to painter
		SelectObject(hdc, hBrush);
		//y = (rect.bottom - rect.top) / 2;


		
		Ellipse(hdc,x,y1,x+ CIRCLE_DIAMETER,y1+ CIRCLE_DIAMETER);
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



		Ellipse(hdc, x, y2, x + CIRCLE_DIAMETER, y2 + CIRCLE_DIAMETER);
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



		Ellipse(hdc, x, y3, x + CIRCLE_DIAMETER, y3 + CIRCLE_DIAMETER);
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



		Ellipse(hdc, x, y4, x + CIRCLE_DIAMETER, y4 + CIRCLE_DIAMETER);
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



		Ellipse(hdc, x, y5, x + CIRCLE_DIAMETER, y5 + CIRCLE_DIAMETER);
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



		Ellipse(hdc, x, y6, x + CIRCLE_DIAMETER, y6 + CIRCLE_DIAMETER);
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



		Ellipse(hdc, x, y7, x + CIRCLE_DIAMETER, y7 + CIRCLE_DIAMETER);
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



		Ellipse(hdc, x, y8, x + CIRCLE_DIAMETER, y8 + CIRCLE_DIAMETER);
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



		Ellipse(hdc, x, y9, x + CIRCLE_DIAMETER, y9 + CIRCLE_DIAMETER);
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



		Ellipse(hdc, x, y10, x + CIRCLE_DIAMETER, y10 + CIRCLE_DIAMETER);
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
			y1++;
			y2++;
			y3++;
			y4++;
			y5++;
			y6++;
			y7++;
			y8++;
			y9++;
			y10++;

			if (y10 > rect.right)
			{
		           y1 = -(CIRCLE_DIAMETER * 0);
				  y2 = -(CIRCLE_DIAMETER * 1);

				  y3 = -(CIRCLE_DIAMETER * 2);
				  y4 = -(CIRCLE_DIAMETER * 3);
				  y5 = -(CIRCLE_DIAMETER * 4);
				  y6 = -(CIRCLE_DIAMETER * 5);
				  y7 = -(CIRCLE_DIAMETER * 6);
				  y8 = -(CIRCLE_DIAMETER * 7);
				  y9 = -(CIRCLE_DIAMETER * 8);
				  y10 = -(CIRCLE_DIAMETER * 9);
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
				x = x - 5;
				if (x < rect.right)
				{
					x = rect.bottom;
				}
				
				break;

			case VK_DOWN:
				bReset = FALSE;
				x = x + 5;
				if (x > (rect.bottom - CIRCLE_DIAMETER))
				{
					x = rect.bottom - CIRCLE_DIAMETER;
						
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
			y1 = LOWORD(lParam);
			y2 = y1 - (CIRCLE_DIAMETER * 1);
			y3 = y1 - (CIRCLE_DIAMETER * 2);
			y4 = y1 - (CIRCLE_DIAMETER * 3);
			y5 = y1 - (CIRCLE_DIAMETER * 4);
			y6 = y1 - (CIRCLE_DIAMETER * 5);
			y7 = y1 - (CIRCLE_DIAMETER * 6);
			y8 = y1 - (CIRCLE_DIAMETER * 7);
			y9 = y1 - (CIRCLE_DIAMETER * 8);
			y10 = y1 -(CIRCLE_DIAMETER * 9);
			bReset = FALSE;


			x = HIWORD(lParam);
			
			break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}