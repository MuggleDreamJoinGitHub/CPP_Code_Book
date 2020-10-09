#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "StructClass.h"
void codePassWord(int* nCount);

/*
	读取信息
*/
void ReadMimaInfo(int *pCount) {
	FILE* pFile = NULL;
	int nError = fopen_s(&pFile, "data.b", "rb+");
	if (nError != NULL)
	{
		g_pInfo = (SITEINFO*)malloc(100 * sizeof(SITEINFO));
		g_num = 100;
		*pCount = 0;
		return;
	}
	else {

		// 读取密码数量
		fread(&g_num, 4, 1, pFile);
		// 读取数据
		fread(pCount, 4, 1, pFile);
		g_pInfo = (SITEINFO*)malloc(100 * sizeof(SITEINFO));
		// 按照容量申请空间
		memset(g_pInfo, 0, g_num * sizeof(SITEINFO));
		// 读取后面的密码信息
		// 为了提供一下利用率, 我们可以使用字符的形式去获取内容

		fread(g_pInfo, sizeof(SITEINFO), *pCount, pFile);

		codePassWord(pCount);

		fscanf_s(pFile, "\n");
		for (int i = 0; i < *pCount; i++)
		{
			fscanf_s(pFile, "%s\n", g_pInfo[i].WebSite, 50);
			fscanf_s(pFile, "%s\n", g_pInfo[i].UserName, 50);
			fscanf_s(pFile, "%s\n", g_pInfo[i].PassWord, 50);
		}
		
	}
	// 关闭流
	fclose(pFile);

}

/*
	写入信息
*/
void SaveFile(int nCount) {
	FILE* pFile = NULL;
	int nError = fopen_s(&pFile, "data.b", "wb+");
	if (nError != 0)
	{
		return;
	}
	else {
		// 每当我们读取一次文件, 文件当前的读写位置, 就会后移读取的字节数
		// 写入密码的总数和数量
		fwrite(&g_num, 4, 1, pFile);
		fwrite(&nCount, 4, 1, pFile);

		codePassWord(&nCount);

		fwrite(g_pInfo, sizeof(SITEINFO), nCount, pFile);
		
		codePassWord(&nCount);
	}
	// 关闭流
	fclose(pFile);
}

/*
	加密解密
*/
void codePassWord(int* nCount)
{
	for (int i = 0; i < *nCount; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			g_pInfo[i].WebSite[j] = g_pInfo[i].WebSite[j] ^ 0x9527;
			g_pInfo[i].UserName[j] = g_pInfo[i].UserName[j] ^ 0x9527;
			g_pInfo[i].PassWord[j] = g_pInfo[i].PassWord[j] ^ 0x9527;
		}
	}
}