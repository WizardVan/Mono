NtSIT = (pNtSetInformationThread)GetProcAddress(GetModuleHandle( TEXT("ntdll.dll")),"NtSetInformationThread");
NtSIT(hThread, 0x11, 0, 0);