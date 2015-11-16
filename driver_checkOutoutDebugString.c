void CheckOutputDebugString(LPCTSTR String)
{
	OutputDebugString(String);
	if (GetLastError() == 0)
	{
		ExitProcess(0);
	}
}