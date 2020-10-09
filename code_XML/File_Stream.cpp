#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "StructClass.h"

/*
	读取信息
*/
void ReadMimaInfo(SITEINFO *g_info, int* g_count, int* g_size) {
	FILE* pFile = NULL;
	int nError = fopen_s(&pFile, "mima_file.b", "rb+");
	if (nError != NULL)
	{
		return;
	}
	else {
		// 读取最大数
		//fread(g_size, sizeof(int), 1, pFile);
		// 读取密码数量
		fread(g_count, sizeof(int), 1, pFile);
		// 读取数据
		fread(g_info, *g_count * 200, 1, pFile);
	}
	// 关闭流
	fclose(pFile);

}

/*
	写入信息
*/
void SaveFile(SITEINFO* g_info, int* g_count, int* g_size) {
	FILE* pFile = NULL;
	int nError = fopen_s(&pFile, "mima_file.b", "wb+");
	if (nError != 0)
	{
		return;
	}
	else {
		// 写入信息最大数
		//fwrite(&g_size, sizeof(int), 1, pFile);
		// 写入信息数量
		fwrite(g_count, sizeof(int), 1, pFile);
		// 写入数据
		fwrite(g_info, *g_count*200, 1, pFile);
	}
	// 关闭流
	fclose(pFile);
}