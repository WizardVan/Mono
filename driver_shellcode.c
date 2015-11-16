hModuleG = GetModuleHandle(TEXT("mono.dll"));
if(hModuleG==NULL)ExitProcess(-1);
dosMZ = (IMAGE_DOS_HEADER*)hModuleG;
if (dosMZ->e_magic != IMAGE_DOS_SIGNATURE)ExitProcess(-1);
peHead = (IMAGE_NT_HEADERS*)((DWORD)hModuleG + dosMZ->e_lfanew);
if (peHead->Signature != IMAGE_NT_SIGNATURE)ExitProcess(-1);
secHead = (IMAGE_SECTION_HEADER*)((DWORD)peHead + sizeof(IMAGE_NT_HEADERS));
for (i=0; i < peHead->FileHeader.NumberOfSections; i++)
{
	IMAGE_SECTION_HEADER* pSecTmp = (IMAGE_SECTION_HEADER*)((DWORD)secHead + sizeof(IMAGE_SECTION_HEADER)*i);
	if (strstr((char*)pSecTmp->Name, ".log"))
	{
		pLog = pSecTmp;
		break;
	}
}

pData = (unsigned char *)(pLog->VirtualAddress + (DWORD)hModuleG);
VirtualProtect((LPVOID)pData, 100, PAGE_READWRITE, &OldProtect);
//*pData=0xf0;
tmpData = pData;
//*tmpData=0xf0;
*tmpData=0xb0;
tmpData+=1;
*tmpData=0x11;
tmpData+=1;
*tmpData=0xc3;
tmpData+=1;
*tmpData=0xe8;
tmpData+=1;
*tmpData=0xf8;
tmpData+=1;
*tmpData=0xff;
tmpData+=1;
*tmpData=0xff;
tmpData+=1;
*tmpData=0xff;
tmpData+=1;
*tmpData=0x3c;
tmpData+=1;
*tmpData=0x12;
tmpData+=1;
*tmpData=0x74;
tmpData+=1;
*tmpData=0x03;
tmpData+=1;
*tmpData=0xc0;
tmpData+=1;
*tmpData=0xe0;
tmpData+=1;
*tmpData=0x02;
tmpData+=1;
*tmpData=0xc3;
tmpData+=1;
*tmpData=0xe8;
tmpData+=1;
*tmpData=0xeb;
tmpData+=1;
*tmpData=0xff;
tmpData+=1;
*tmpData=0xff;
tmpData+=1;

*tmpData=0xff;
tmpData+=1;
*tmpData=0x3c;
tmpData+=1;
*tmpData=0x13;
tmpData+=1;
*tmpData=0x74;
tmpData+=1;
		
*tmpData=0x04;
tmpData+=1;
*tmpData=0xb1;
tmpData+=1;
*tmpData=0x0a;
tmpData+=1;
*tmpData=0xf6;
tmpData+=1;

*tmpData=0xe9;
tmpData+=1;
*tmpData=0xc3;
tmpData+=1;
*tmpData=0x55;
tmpData+=1;
*tmpData=0x8b;
tmpData+=1;
		
*tmpData=0xec;
tmpData+=1;
*tmpData=0x0f;
tmpData+=1;
*tmpData=0xbe;
tmpData+=1;
*tmpData=0x4d;
tmpData+=1;

*tmpData=0x0c;
tmpData+=1;
*tmpData=0x0f;
tmpData+=1;
*tmpData=0xbe;
tmpData+=1;
*tmpData=0x45;
tmpData+=1;
*tmpData=0x08;
tmpData+=1;
*tmpData=0x33;
tmpData+=1;
*tmpData=0xc1;
tmpData+=1;
*tmpData=0x0f;
tmpData+=1;

*tmpData=0xbe;
tmpData+=1;
*tmpData=0x4d;
tmpData+=1;
*tmpData=0x10;
tmpData+=1;
*tmpData=0x33;
tmpData+=1;
*tmpData=0xc1;
tmpData+=1;
*tmpData=0x5d;
tmpData+=1;
*tmpData=0xc3;
tmpData+=1;
*tmpData=0x00;
tmpData+=1;

/*
for (i = 0; i <50; i++)
{		
	*tmpData = *tmpData;
	tmpData+=1;
}
		
*/
//logfile=fopen("log.txt","w");
VirtualProtect((LPVOID)pData, 100,  OldProtect, &OldProtect);