#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

/*
	��ȡ��Ϣ
*/
void ReadMimaInfo(char WebSite[300][20], char User[300][20],char Mima[300][20], int* pCount) {

	FILE* pFile = NULL;
	int nError = fopen_s(&pFile, "mima_file.b", "rb+");
	if (nError != 0)
	{
		return;
	}

	// ÿ�����Ƕ�ȡһ���ļ�, �ļ���ǰ�Ķ�дλ��, �ͻ���ƶ�ȡ���ֽ���

	// ��ȡ��������
	int nNum = 0;
	fread(&nNum, 4, 1, pFile);
	*pCount = nNum;
	// ��ȡվ����Ϣ
	fread(WebSite, 300 * 20, 1, pFile);
	// ��ȡ�˻���Ϣ
	fread(User, 300 * 20, 1, pFile);
	// ��ȡ������Ϣ
	fread(Mima, 300 * 20, 1, pFile);
	// �ر���
	fclose(pFile);


}

/*
	д����Ϣ
*/
void SaveFile(char WebSite[300][20], char User[300][20],char Mima[300][20], int* pCount) {
	
	FILE* pFile = NULL;
	int nError = fopen_s(&pFile, "mima_file.b", "wb+");

	if (nError != 0)
	{
		return;
	}

	// ÿ�����Ƕ�ȡһ���ļ�, �ļ���ǰ�Ķ�дλ��, �ͻ���ƶ�ȡ���ֽ���

	// д����������
	fwrite(&pCount, 4, 1, pFile);
	// д��վ����Ϣ
	fwrite(WebSite, 300 * 20, 1, pFile);
	// д���˻���Ϣ
	fwrite(User, 300 * 20, 1, pFile);
	// д��������Ϣ
	fwrite(Mima, 300 * 20, 1, pFile);
	// �ر���
	fclose(pFile);
}