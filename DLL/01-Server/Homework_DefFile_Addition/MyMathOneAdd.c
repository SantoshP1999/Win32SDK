# include<windows.h>

//Entry point function of Dll
BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:

		break;

	case DLL_THREAD_ATTACH:

		break;

	case DLL_THREAD_DETACH:

		break;

	case DLL_PROCESS_DETACH:

		break;
	}

	return TRUE;
}


//MakeSquare is for Externally usage
__declspec(dllexport) int MakeSum(int n1,int n2)
{
	int num = n1 + n2;
	//Function prototype
	void CheckNumber(num);

	//Code

	CheckNumber(num);
	return(num);

}//checkNumber is for internally usage

void CheckNumber(int num)
{
	if (num < 0)
		MessageBox(NULL, TEXT("Number is Negative!"), TEXT("MESSAGE"),MB_OK | MB_ICONINFORMATION);
}