void ChangeSizeOfImage()
{
	__asm
	{
		mov eax, fs:[0x30] // PEB
		mov eax, [eax + 0x0c] // PEB_LDR_DATA
		mov eax, [eax + 0x0c] // InOrderModuleList
		mov dword ptr [eax + 0x20], 0x1000000 // SizeOfImage
	}
}