Mono is a patch for mono-2010-4-26,and theoretically,it can be used on latest mono or any version after modification. It patches two parts,driver.c and image.c. In driver.c this patch adds anti-debug mechanism and decryption code initialization.In image,c this patch adds code to extract encrypted data.

Mono 是一个对mono-2010-4-26使用的补丁，理论上来说代码可以用于任何版本的mono，如果进行少许修改的话。 这个补丁主要修改两个部分，一个是driver.c，用于加入反调试机制和解码器的初始化，另一个是image,c，用于将加密的数据文件在载入时进行解码。
