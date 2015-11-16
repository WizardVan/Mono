void Int2DCheck()
{
	__try
	{
		__asm
		{
			int 0x2d
				xor eax, eax
				add eax, 2
		}
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		return;
	}
	ExitProcess(0);
}