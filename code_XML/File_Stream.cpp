#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "StructClass.h"

/*
	��ȡ��Ϣ
*/
void ReadMimaInfo(SITEINFO *g_info, int* g_count, int* g_size) {
	FILE* pFile = NULL;
	int nError = fopen_s(&pFile, "mima_file.b", "rb+");
	if (nError != NULL)
	{
		return;
	}
	else {
		// ��ȡ�����
		//fread(g_size, sizeof(int), 1, pFile);
		// ��ȡ��������
		fread(g_count, sizeof(int), 1, pFile);
		// ��ȡ����
		fread(g_info, *g_count * 200, 1, pFile);
	}
	// �ر���
	fclose(pFile);

}

/*
	д����Ϣ
*/
void SaveFile(SITEINFO* g_info, int* g_count, int* g_size) {
	FILE* pFile = NULL;
	int nError = fopen_s(&pFile, "mima_file.b", "wb+");
	if (nError != 0)
	{
		return;
	}
	else {
		// д����Ϣ�����
		//fwrite(&g_size, sizeof(int), 1, pFile);
		// д����Ϣ����
		fwrite(g_count, sizeof(int), 1, pFile);
		// д������
		fwrite(g_info, *g_count*200, 1, pFile);
	}
	// �ر���
	fclose(pFile);
}