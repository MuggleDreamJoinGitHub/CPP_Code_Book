#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

/*
	读取信息
*/
void ReadMimaInfo(char WebSite[300][20], char User[300][20],char Mima[300][20], int* pCount, int* g_size) {

	FILE* pFile = NULL;
	int nError = fopen_s(&pFile, "mima_file.a", "rb+");
	if (nError != NULL)
	{
		return;
	}

	// 每当我们读取一次文件, 文件当前的读写位置, 就会后移读取的字节数

	// 读取上一次保存的最大值
	//fread(&g_size, sizeof(int), 1, pFile);

	// 读取密码数量
	fread(&pCount, sizeof(int), 1, pFile);


	// 读取站点信息
	fread(WebSite, 300 * 20, 4, pFile);
	// 读取账户信息
	fread(User, 300 * 20, 4, pFile);
	// 读取密码信息
	fread(Mima, 300 * 20, 4, pFile);
	// 关闭流
	fclose(pFile);

}

/*
	写入信息
*/
void SaveFile(char WebSite[300][20], char User[300][20],char Mima[300][20], int* pCount, int*g_size) {
	
	FILE* pFile = NULL;
	int nError = fopen_s(&pFile, "mima_file.a", "wb+");

	if (nError != 0)
	{
		return;
	}

	// 每当我们读取一次文件, 文件当前的读写位置, 就会后移读取的字节数

	// 写入文件的最大数
	//fwrite(&g_size, sizeof(int), 1, pFile);
	// 写入密码数量
	fwrite(&pCount, sizeof(int), 1, pFile);
	// 写入站点信息
	fwrite(WebSite, 300 * 20, 4, pFile);
	// 写入账户信息
	fwrite(User, 300 * 20, 4, pFile);
	// 写入密码信息
	fwrite(Mima, 300 * 20, 4, pFile);
	// 关闭流
	fclose(pFile);
}