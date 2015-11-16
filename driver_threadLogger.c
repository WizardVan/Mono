void ThreadLogger( DWORD dwOwnerPID )
{
	HANDLE hThreadSnap = INVALID_HANDLE_VALUE;
	HANDLE hThread=NULL;
	THREADENTRY32 te32;

	// Take a snapshot of all running threads  
	hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	if (hThreadSnap == INVALID_HANDLE_VALUE)
		return;

	// Fill in the size of the structure before using it. 
	te32.dwSize = sizeof(THREADENTRY32);

	// Retrieve information about the first thread,
	// and exit if unsuccessful
	if (!Thread32First(hThreadSnap, &te32))
	{
		//printError(TEXT("Thread32First"));  // Show cause of failure
		CloseHandle(hThreadSnap);     // Must clean up the snapshot object!
		return;
	}

	// Now walk the thread list of the system,
	// and display information about each thread
	// associated with the specified process
	do
	{
		if (te32.th32OwnerProcessID == dwOwnerPID)
		{
			hThread = OpenThread(THREAD_QUERY_INFORMATION, FALSE, te32.th32ThreadID);
			//_tprintf(TEXT("\n     THREAD ID      = 0x%08X"), te32.th32ThreadID);
			//_tprintf(TEXT("\n     base priority  = %d"), te32.tpBasePri);
			//_tprintf(TEXT("\n     StartAddress  = 0x%08X"), GetThreadStartAddress(hThread));
			//_tprintf(TEXT("\n     delta priority = %d"), te32.tpDeltaPri);
			GetThreadStartAddress(hThread);
		}
	} while (Thread32Next(hThreadSnap, &te32));

	//_tprintf(TEXT("\n"));

	//  Don't forget to clean up the snapshot object.
	CloseHandle(hThreadSnap);
	return;
}

DWORD GetThreadStartAddress(HANDLE hThread)

{

	NTSTATUS ntStatus;
	typedef NTSTATUS(WINAPI *pNtQIT)(HANDLE, LONG, PVOID, ULONG, PULONG);

	DWORD dwStartAddress=0;

	pNtQIT NtQueryInformationThread = (pNtQIT)GetProcAddress(GetModuleHandle(TEXT("ntdll.dll")), "NtQueryInformationThread");
	if (NtQueryInformationThread == NULL)
		return 0;

	ntStatus = NtQueryInformationThread(hThread, ThreadQuerySetWin32StartAddress, &dwStartAddress, sizeof(DWORD), NULL);

	CloseHandle(hThread);

	if (ntStatus != STATUS_SUCCESS) return 0;

	if(dwStartAddress==(DWORD)LLaddr)ExitProcess(-1);
	if(dwStartAddress==(DWORD)LLaddrA)ExitProcess(-1);
	if(dwStartAddress==(DWORD)LLaddrW)ExitProcess(-1);
	if(dwStartAddress==(DWORD)LLaddrEx)ExitProcess(-1);
	if(dwStartAddress==(DWORD)LLaddrExA)ExitProcess(-1);
	if(dwStartAddress==(DWORD)LLaddrExW)ExitProcess(-1);
	if(dwStartAddress==(DWORD)NTLLaddr)ExitProcess(-1);

	return dwStartAddress;

}