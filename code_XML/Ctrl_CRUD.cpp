#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "File_Stream.h"

void FindALL(char g_arrWebSite[300][20], char g_arrUserName[300][20], char g_arrPassWord[300][20], int* nCount) {
	system("cls");
	for (int i = 0; i < *nCount; i++)
	{
		// �ж�Ϊ�վ��ж϶�ȡ,��ֹ���������ڴ�����
		if (strcmp(g_arrWebSite[i], ""))
		{
			printf("%d: վ��:%s\t\t�û���:%s\t\t����:%s\n", (i + 1), g_arrWebSite[i], g_arrUserName[i], g_arrPassWord[i]);
		}
		else {
			break;
		}
	}
	if (nCount == 0)
	{
		printf("��ǰ�洢״̬Ϊ0!\n");
	}
	system("pause");
}


void FindInfoBySite(char g_arrWebSite[300][20], char g_arrUserName[300][20], char g_arrPassWord[300][20], int* nCount) {

	char webSite[20] = {};
	system("cls");
	printf("%s", "������վ��:");
	scanf_s("%s", webSite, 20);
	for (int i = 0; i < *nCount; i++)
	{
		if (strcmp(webSite, g_arrWebSite[i]) == 0)
		{
			printf("վ��:%s\t\t�û���:%s\t\t����:%s\n", g_arrWebSite[i], g_arrUserName[i], g_arrPassWord[i]);
			break;
		}
	}
	system("pause");

}

void UPDateInfo(char g_arrWebSite[300][20], char g_arrUserName[300][20], char g_arrPassWord[300][20], int* nCount)
{
	char webSite[20] = {};
	printf("%s", "������վ��:");
	scanf_s("%s", webSite, 20);
	for (int i = 0; i < *nCount; i++)
	{
		if (strcmp(webSite, g_arrWebSite[i]) == 0)
		{
			char user[20] = {};
			char pass[20] = {};
			printf("%s", "�������˻�:");
			scanf_s("%s", &user, 20);
			strcpy_s(g_arrUserName[i], 20, user);

			printf("%s", "����������:");
			scanf_s("%s", &pass, 20);
			strcpy_s(g_arrPassWord[i], 20, pass);

			printf("%s", "�޸����\n");
			printf("վ��:%s\t\t�û���:%s\t\t����:%s\n", g_arrWebSite[i], g_arrUserName[i], g_arrPassWord[i]);
			break;
		}
	}

}



void AddInfo(char g_arrWebSite[300][20], char g_arrUserName[300][20], char g_arrPassWord[300][20], int* nCount)
{
	system("cls");
	printf("%s", "������վ������:");
	scanf_s("%s", g_arrWebSite[*nCount], 20);
	printf("%s", "�������˻�:");
	scanf_s("%s", g_arrUserName[*nCount], 20);
	printf("%s", "����������:");
	scanf_s("%s", g_arrPassWord[*nCount], 20);
	nCount++;
	printf("��ӳɹ�!,��ǰ����: %d ������\n", nCount);

	SaveFile(g_arrWebSite, g_arrUserName, g_arrPassWord, nCount);
}

void DeleteInfo(char g_arrWebSite[300][20], char g_arrUserName[300][20], char g_arrPassWord[300][20], int* nCount)
{
	system("cls");
	char webSite[20] = {};
	printf("%s", "������վ��:");
	scanf_s("%s", webSite, 20);
	int i;
	for (i = 0; i < *nCount; i++)
	{
		if (strcmp(webSite, g_arrWebSite[i]) == 0)
		{
			for (int x = i; x < *nCount - 1; x++)
			{
				strcpy_s(g_arrWebSite[x], 20, g_arrWebSite[x + 1]);
				strcpy_s(g_arrUserName[x], 20, g_arrUserName[x + 1]);
				strcpy_s(g_arrPassWord[x], 20, g_arrPassWord[x + 1]);
			}
			nCount--;
			break;
		}
	}
	system("pause");
}