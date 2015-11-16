IMAGE_NT_HEADERS* peHead;
IMAGE_DOS_HEADER* dosMZ;
IMAGE_SECTION_HEADER* secHead;
IMAGE_SECTION_HEADER* pLog=NULL;
DWORD OldProtect=0;
int i;
unsigned char * pData;
unsigned char *tmpData;
HMODULE hModuleG;
static char loadedNum=0;

hModuleG = GetModuleHandleA("mono.dll");
dosMZ = (IMAGE_DOS_HEADER*)hModuleG;
peHead = (IMAGE_NT_HEADERS*)((DWORD)hModuleG + dosMZ->e_lfanew);
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
tmpData=pData;
for (i = 0; i <54; i++)
{
	*tmpData = 0;
	tmpData+=1;
}
VirtualProtect((LPVOID)pData, 100,  OldProtect, &OldProtect);
loadedNum=0;

	
	
