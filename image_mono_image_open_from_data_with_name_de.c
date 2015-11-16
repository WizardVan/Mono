char key;
char vi;
if(strstr(name,"Assembly-CSharp.dll")!=NULL)
{
	//data[0]=data[0];
	key = getKey();
	vi = getIv();
	for( i=0;i < data_len;i++)
	{
		if (i == 0)
		{
			data[i] = decrypt(key , vi , data[i]);
		}
            	else 
		{
					data[i] = decrypt(key , (~data[i - 1]) , data[i]);
		}
	}
	loadedNum+=1;	
}
	
	
if(strstr(name,"GameCore.dll")!=NULL)
{
	//data[0]=data[0];
	key = getKey();
	vi = getIv();
	for( i=0;i < data_len;i++)
	{
		if (i == 0)
		{
				data[i] = decrypt (key , vi , data[i]);
		}
           else 
		{
				data[i] = decrypt(key , (~data[i - 1]) , data[i]);
		}
	}
	loadedNum+=1;
}
	