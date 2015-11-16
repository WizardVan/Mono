void HandlerLogger( DWORD processID )
{
	
	NTSTATUS status;
	
	ULONG pid;
	HANDLE processHandle;
	ULONG i;

	if (!(processHandle = OpenProcess( PROCESS_ALL_ACCESS, FALSE, processID)))
	{
		//printf("Could not open PID %d! (Don't try to open a system process.)\n", pid);
		return;
	}

	

	/* NtQuerySystemInformation won't give us the correct buffer size,
	so we guess by doubling the buffer size. */
	if(pNtQuerySystemInformation==NULL)
	{
		return;
	}

	while ((status = pNtQuerySystemInformation(
		SystemHandleInformation,
		handleInfo,
		handleInfoSize,
		NULL
		)) == STATUS_INFO_LENGTH_MISMATCH)
		handleInfo = (PSYSTEM_HANDLE_INFORMATION)realloc(handleInfo, handleInfoSize *= 2);

	/* NtQuerySystemInformation stopped giving us STATUS_INFO_LENGTH_MISMATCH. */
	if (!NT_SUCCESS(status))
	{
		//printf("NtQuerySystemInformation failed!\n");
		return;
	}

	for (i = 0; i < handleInfo->HandleCount; i++)
	{
		SYSTEM_HANDLE handle = handleInfo->Handles[i];
		HANDLE dupHandle = NULL;
		if(handle.ObjectTypeNumber!=7)
			continue;
		/* Check if this handle belongs to the PID the user specified. */
		if (handle.ProcessId != processID)
			continue;
		if((handle.GrantedAccess == 0x0012019f)
			|| (handle.GrantedAccess == 0x001a019f)
			|| (handle.GrantedAccess == 0x00120189)
			|| (handle.GrantedAccess == 0x00100000)) {
				continue;
		}
		/* Duplicate the handle so we can query it. */
		if(pNtDuplicateObject==NULL)
		{
			return;
		}

		if (!NT_SUCCESS(pNtDuplicateObject(
			processHandle,
			(HANDLE)handle.Handle,
			GetCurrentProcess(),
			&dupHandle,
			0,
			0,
			DUPLICATE_SAME_ACCESS
			)))
		{
			continue;
		}

		if(GetProcessId((HANDLE)dupHandle)==GetCurrentProcessId())
		{
			ExitProcess(0);
		}
		//do something!!
		CloseHandle(dupHandle);
	}
	
	CloseHandle(processHandle);

	return;

}
