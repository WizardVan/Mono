void ProcessLogger( DWORD processID )
{
	TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

	// Get a handle to the process.

	HANDLE hProcess = OpenProcess( PROCESS_ALL_ACCESS,
		FALSE, processID );
	//GetProcessId(hProcess);
	// Get the process name.

	if (NULL != hProcess )
	{
		HMODULE hMod;
		DWORD cbNeeded;

		if ( EnumProcessModules( hProcess, &hMod, sizeof(hMod), 
			&cbNeeded) )
		{
			GetModuleBaseName( hProcess, hMod, szProcessName, 
				sizeof(szProcessName)/sizeof(TCHAR) );
		}
	}

	
	if (_tcsstr(szProcessName, TEXT("OLLYDBG.EXE"))!=NULL)
	{
		TerminateProcess(hProcess,1);
		ExitProcess(0);
	}

	// Release the handle to the process.

	CloseHandle( hProcess );
}