void WindowsLogger()
{
	HANDLE hwFind;
	hwFind = FindWindow(TEXT("OLLYDBG"), NULL);
	if(hwFind)
		ExitProcess(0);
	hwFind = FindWindow(TEXT("Afx:00400000:0"), NULL);
	if(hwFind)
		ExitProcess(0);
	hwFind = FindWindow(TEXT("WinDbgFrameClass"), NULL);
	if(hwFind)
		ExitProcess(0);
	hwFind = FindWindow(TEXT("Window"), TEXT("Cheat Engine 6.4"));
	if (hwFind)
		ExitProcess(0);
	hwFind = FindWindow(TEXT("TfMain"),NULL);
	if (hwFind)
	{
		hwFind = FindWindow(TEXT("TApplication"), NULL);
		if (hwFind)
			ExitProcess(0);
	}
}