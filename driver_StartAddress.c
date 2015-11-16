//HookFunction("Kernel32.dll","LoadLibraryW", (LPDWORD)&HOOKLoadLib,(LPDWORD*) &pLoadLib);
LLaddr = (LPVOID)GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "LoadLibrary");
LLaddrA = (LPVOID)GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "LoadLibraryA");
LLaddrW = (LPVOID)GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "LoadLibraryW");
LLaddrEx=(LPVOID)GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "LoadLibraryEx");
LLaddrExA=(LPVOID)GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "LoadLibraryExA");
LLaddrExW=(LPVOID)GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "LoadLibraryExW");
NTLLaddr= (LPVOID)GetProcAddress(GetModuleHandle(TEXT("ntdll.dll")), "LdrLoadDll");