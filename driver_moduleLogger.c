void ModuleLogger( DWORD processID )
{
	HMODULE hMods[1024];
	HANDLE hProcess;
	DWORD cbNeeded;
	unsigned int i;
	unsigned int numModule=0;

	// Print the process identifier.

	//printf("\nProcess ID: %u\n", processID);

	// Get a handle to the process.

	hProcess = OpenProcess(PROCESS_ALL_ACCESS,
		FALSE, processID);
	if (NULL == hProcess)
		return;

	// Get a list of all the modules in this process.

	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
	{
		for (i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
		{
			TCHAR szModName[MAX_PATH];

			// Get the full path to the module's file.

			if (GetModuleFileNameEx(hProcess, hMods[i], szModName,
				sizeof(szModName) / sizeof(TCHAR)))
			{
				// Print the module name and handle value.
				numModule += 1;
				//_tprintf(TEXT("\t%s (0x%08X)\n"), szModName, hMods[i]);
			}
		}
		//_tprintf(TEXT("%d "), numModule);
	}

	// Release the handle to the process.

	CloseHandle(hProcess);

	return;
}