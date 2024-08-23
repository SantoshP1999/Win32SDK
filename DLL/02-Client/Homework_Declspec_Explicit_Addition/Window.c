#include<windows.h>
#include "Window.h"


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
	//variable declearation
	HMODULE hDll = NULL;
	//this is step2:a
	//define function pointer
	typedef int(*MakeSumFnPtr)(int);


	//declaring function pointer variable
	typedef int(*MakeSumFnPtr)(int);
	MakeSumFnPtr ptrFuncMakeSum = NULL;

	int n1 = -8, n2 = -6;
	int sum;

	TCHAR str[255];

	//code

	switch (iMsg)
	{
		//load the library
	case WM_CREATE:
		hDll = LoadLibrary(TEXT("MyMathOneAdd.dll"));
		if (hDll == NULL)
		{
			MessageBox(hwnd, TEXT("loadlibrary failed"), TEXT("error"), MB_OK);
			DestroyWindow(hwnd);
		}
		//step2:call function from the dll

		//step2 a:decleare function pointer to store address of function in dll(see above in variable decleration)
		//step2 b:get address of dll function from the dll and store in its function pointer
		//this is step 2b
		ptrFuncMakeSum = (MakeSumFnPtr)GetProcAddress(hDll, "MakeSum");
		if (ptrFuncMakeSum == NULL)
		{
			MessageBox(hwnd, TEXT("getprocaddress failed"), TEXT("error"), MB_OK);

			FreeLibrary(hDll);
			hDll = NULL;
			DestroyWindow(hwnd);
		}
		sum = ptrFuncMakeSum(n1 + n2);

		wsprintf(str, TEXT("sum of %d and %d is %d"), n1, n2, sum);
		MessageBox(hwnd, str, TEXT("sum"), MB_OK);
		if (hDll)
		{
			FreeLibrary(hDll);
			hDll = NULL;
		}
		DestroyWindow(hwnd);


		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}