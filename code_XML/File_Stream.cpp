#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "StructClass.h"
void codePassWord(int* nCount);

/*
	��ȡ��Ϣ
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

		// ��ȡ��������
		fread(&g_num, 4, 1, pFile);
		// ��ȡ����
		fread(pCount, 4, 1, pFile);
		g_pInfo = (SITEINFO*)malloc(100 * sizeof(SITEINFO));
		// ������������ռ�
		memset(g_pInfo, 0, g_num * sizeof(SITEINFO));
		// ��ȡ�����������Ϣ
		// Ϊ���ṩһ��������, ���ǿ���ʹ���ַ�����ʽȥ��ȡ����

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
	// �ر���
	fclose(pFile);

}

/*
	д����Ϣ
*/
void SaveFile(int nCount) {
	FILE* pFile = NULL;
	int nError = fopen_s(&pFile, "data.b", "wb+");
	if (nError != 0)
	{
		return;
	}
	else {
		// ÿ�����Ƕ�ȡһ���ļ�, �ļ���ǰ�Ķ�дλ��, �ͻ���ƶ�ȡ���ֽ���
		// д�����������������
		fwrite(&g_num, 4, 1, pFile);
		fwrite(&nCount, 4, 1, pFile);

		codePassWord(&nCount);

		fwrite(g_pInfo, sizeof(SITEINFO), nCount, pFile);
		
		codePassWord(&nCount);
	}
	// �ر���
	fclose(pFile);
}

/*
	���ܽ���
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