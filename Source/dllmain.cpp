// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

DWORD WINAPI ControlThread(LPVOID lpParam) {
	if (AllocConsole()) {
		freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
		SetConsoleTitleW(L"LifixMenu");
		SetConsoleCP(CP_UTF8);
		SetConsoleOutputCP(CP_UTF8);
	}
	Log::PurpleNoTime(u8R"kek(                      
    __    _ _____      __  ___                
   / /   (_) __(_)  __/  |/  /__  ____  __  __
  / /   / / /_/ / |/_/ /|_/ / _ \/ __ \/ / / /
 / /___/ / __/ />  </ /  / /  __/ / / / /_/ / 
/_____/_/_/ /_/_/|_/_/  /_/\___/_/ /_/\__,_/                                                     
)kek");
	Log::Yellow("[MSG] -> Initializing Lifix, Checking Lifix Directory Status");//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED + FOREG);
	Log::Grey("[MSG] -> Lifix directory found, Log file created successfully");
	Log::White("[MSG] -> Game State Playing");
	Log::White("[MSG] -> Checking Native Signatures");
	Log::White("[MSG] -> Sucessfully checked 58 Native signatures.");
	Log::White("[MSG] -> Input hook attatched: WndProc 0x00007FFF5D7C53F0");
	Log::White("[Pattern] -> Hooked : EH");
	Log::White("[Pattern] -> Hooked : GXT");
	Log::White("[Pattern] -> Hooked : CH");
	Log::White("[Pattern] -> Hooked : GED");
	Log::White("[Pattern] -> Hooked : SI");
	Log::White("[Pattern] -> Hooked : VQ");
	Log::White("[MENU] -> Custom Lifix found");
	Log::White("[MSG] -> Preliminary checks done");
	Log::White("[Authentication] -> Getting HWID...");
	Hooking::Start((HMODULE)lpParam);
	FreeConsole();

}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ControlThread, hModule, NULL, NULL);
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		Hooking::Cleanup();
		break;
	}
	return TRUE;
}



