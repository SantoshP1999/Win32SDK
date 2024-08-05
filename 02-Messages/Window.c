#include<windows.h>

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
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);//COLOR_WINDOW+1
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = szClassName;
	wndclass.lpszMenuName = NULL;

	//Register Window Class
	RegisterClassEx(&wndclass);

	//create the window
	hwnd = CreateWindow(szClassName,
		TEXT("Santosh Phatangare :First Window"),
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
	return((int)msg.wParam);	//get 0
}

//callback window procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//Variable Declarations
	TCHAR str[255];
	wchar_t ch;
	int x, y;

	//Code
	switch (iMsg)
	{
	
	case WM_CREATE:
		wsprintf(str, TEXT("WM_CREATE message received."));

		MessageBox(NULL, str, TEXT("Message"),
			MB_OK | MB_ICONINFORMATION);

		break;

	case WM_KEYDOWN:
		//ch = wParam;
		//wsprintf(str, TEXT("WM_KEYDOWN message received."));
		//MessageBox(NULL, str, TEXT("Message"),
			//MB_OK | MB_ICONINFORMATION);
		switch (wParam)
		{
		case VK_SPACE:
			wsprintf(str, TEXT("VK_SPACE message received :%d", ch));
			MessageBox(NULL,str,TEXT("Message"),
				MB_OK | MB_ICONINFORMATION);
			break;

		case VK_ESCAPE:
			wsprintf(str, TEXT("VK_ESCAPE message received :%d", ch));
			MessageBox(NULL, str, TEXT("Message"),
				MB_OK | MB_ICONINFORMATION);
			break;

		case VK_ADD:
			wsprintf(str, TEXT("VK_ADD message received :%d", ch));
			MessageBox(NULL,str,TEXT("Message"),
				MB_OK | MB_ICONINFORMATION);
			break;

		case VK_SUBTRACT:
			wsprintf(str, TEXT("VK_SUBSTRACT message received :%d", ch));
			MessageBox(NULL, str, TEXT("Message"),
				MB_OK | MB_ICONINFORMATION);
			break;
			

		case VK_UP:
			wsprintf(str, TEXT("VK_UP Message received :%d", ch));
			MessageBox(NULL, str, TEXT("Message"),
				MB_OK | MB_ICONINFORMATION);
			break;

		case VK_DOWN:
			wsprintf(str, TEXT("VK_DOWN Message received :%d", ch));
			MessageBox(NULL, str, TEXT("Message"),
				MB_OK | MB_ICONINFORMATION);
			break;

		}

		break;

	case WM_CHAR:
		ch = wParam;
		wsprintf(str, TEXT("WM_CHAR message received : %c,",ch));
		MessageBox(NULL, str, TEXT("Message"),
			MB_OK | MB_ICONINFORMATION);
		break;

	case WM_LBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
			wsprintf(str, TEXT("Left Mouse Button Click at :%d,%d"),x,y);

			MessageBox(NULL, str, TEXT("Message"),
				MB_OK | MB_ICONINFORMATION);
			break;

			
		case WM_RBUTTONDOWN:
			x = LOWORD(lParam);
			y = HIWORD(lParam);
			wsprintf(str, TEXT("Right Mouse Button Click at :%d,%d"), x, y);
				

				MessageBox(NULL, str, TEXT("Message"),
					MB_OK | MB_ICONINFORMATION);
				break;

		

	case WM_DESTROY:

		wsprintf(str, TEXT("WM_DESTROY message received."));

		MessageBox(NULL, str, TEXT("Message"),
			MB_OK | MB_ICONERROR);

		PostQuitMessage(0);
		break;

	default:
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));

}