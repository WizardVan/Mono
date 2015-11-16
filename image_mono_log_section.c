//__declspec(allocate("log"))
#pragma code_seg(".log")
char randomTime(){
	return 0x11;
}
#pragma code_seg(".log")
char getKey(){
	char Key=0;
	Key+=randomTime();
	if (Key!=0x12)Key=Key*4;
	return Key;
};
#pragma code_seg(".log")
char getIv(){
	char Iv=1;
	Iv*=randomTime();
	if (Iv!=0x13)Iv=Iv*0xa;
	return Iv;
}
#pragma code_seg(".log")
char decrypt(char key,char vi,char data)
{
	return key^vi^data;
}

#pragma code_seg(".text")