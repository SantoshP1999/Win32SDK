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
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
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

	// Variable Declarations
	
	HMODULE hDll = NULL;
	
	//This is Step 2 'A'
	// Define Function Pointer
	typedef int(*makemultfnptr)(int);
	
	//Declaration Function Pointer Variable
	
	makemultfnptr ptrfuncmakemult = NULL;
	int n1=5,n2=10;
	int mult;
	TCHAR str[255];

//Code
	switch (iMsg)
	{
		//Load the Library
	case WM_CREATE:
		hDll = LoadLibrary(TEXT("MyMathTwoMult.dll"));
		if (hDll == NULL)
		{
			MessageBox(hwnd, TEXT("LoadLibrary Fail"), TEXT("ERROR"), MB_OK);
			DestroyWindow(hwnd);
		}

		//step 2 call functionn from Dll
		//step 2 'a' The Declare function pointer to store address of function in Dll(see above in variable Declaration)
		//step 2 'b' Gate Adress of Dll function from the Dll & store in it function pointer
		//This is step 2 'b' 

		ptrfuncmakemult = (makemultfnptr)GetProcAddress(hDll, "MakeMult");
		if (ptrfuncmakemult == NULL)
		{
			MessageBox(hwnd, TEXT("GetProcAddress Fail"), TEXT("ERROR"), MB_OK);
			FreeLibrary(hDll);
			hDll = NULL;
			DestroyWindow(hwnd);

		}
		mult = ptrfuncmakemult(n1*n2);
		wsprintf(str, TEXT("Multiplication of %d & %d is %d"), n1,n2,mult);
		MessageBox(hwnd, str, TEXT("Multiplication"), MB_OK);
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
	return (DefWindowProc(hwnd, iMsg, wParam, lParam));

}