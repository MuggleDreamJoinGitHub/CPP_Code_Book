#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

/*
	��ȡ��Ϣ
*/
void ReadMimaInfo(char WebSite[300][20], char User[300][20],char Mima[300][20], int* pCount, int* g_size) {

	FILE* pFile = NULL;
	int nError = fopen_s(&pFile, "mima_file.a", "rb+");
	if (nError != NULL)
	{
		return;
	}

	// ÿ�����Ƕ�ȡһ���ļ�, �ļ���ǰ�Ķ�дλ��, �ͻ���ƶ�ȡ���ֽ���

	// ��ȡ��һ�α�������ֵ
	//fread(&g_size, sizeof(int), 1, pFile);

	// ��ȡ��������
	fread(&pCount, sizeof(int), 1, pFile);


	// ��ȡվ����Ϣ
	fread(WebSite, 300 * 20, 4, pFile);
	// ��ȡ�˻���Ϣ
	fread(User, 300 * 20, 4, pFile);
	// ��ȡ������Ϣ
	fread(Mima, 300 * 20, 4, pFile);
	// �ر���
	fclose(pFile);

}

/*
	д����Ϣ
*/
void SaveFile(char WebSite[300][20], char User[300][20],char Mima[300][20], int* pCount, int*g_size) {
	
	FILE* pFile = NULL;
	int nError = fopen_s(&pFile, "mima_file.a", "wb+");

	if (nError != 0)
	{
		return;
	}

	// ÿ�����Ƕ�ȡһ���ļ�, �ļ���ǰ�Ķ�дλ��, �ͻ���ƶ�ȡ���ֽ���

	// д���ļ��������
	//fwrite(&g_size, sizeof(int), 1, pFile);
	// д����������
	fwrite(&pCount, sizeof(int), 1, pFile);
	// д��վ����Ϣ
	fwrite(WebSite, 300 * 20, 4, pFile);
	// д���˻���Ϣ
	fwrite(User, 300 * 20, 4, pFile);
	// д��������Ϣ
	fwrite(Mima, 300 * 20, 4, pFile);
	// �ر���
	fclose(pFile);
}