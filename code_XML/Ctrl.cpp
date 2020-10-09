#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "StructClass.h"
#include "File_Stream.h"

/*
	��ѯ����
*/
void findAll(SITEINFO* g_info, int g_count, int g_size) {
	system("cls");
	for (int i = 0; i < g_count; i++)
	{
		printf("վ��:%s\t\t�˺�:%s\t\t����:%s\t\t��ע:%s\n", g_info[i].WebSite, g_info[i].UserName, g_info[i].PassWord, g_info[i].Remarks);
	}
	system("pause");
}

/*
	����վ���ѯ������Ϣ
*/
void findInfoBySite(SITEINFO* g_info, int g_count, int g_size) {
	system("cls");
	char webSite[20] = {};
	printf("%s", "������վ��:");
	scanf_s("%s", webSite, 20);
	for (int i = 0; i < g_count; i++)
	{
		if (strcmp(webSite, g_info[i].WebSite) == 0)
		{
			printf("վ��:%s\t\t�˺�:%s\t\t����:%s\t\t��ע:%s\n", g_info[i].WebSite, g_info[i].UserName, g_info[i].PassWord, g_info[i].Remarks);
			break;
		}
	}
	system("pause");
}

/*
	���һ����Ϣ
*/
void addInfo(SITEINFO* g_info, int* g_count,int * g_size)
{
	system("cls");
	printf("%s", "վ������:");
	scanf_s("%s", g_info[*g_count].WebSite, 50);
	printf("%s", "�˻�:");
	scanf_s("%s", g_info[*g_count].UserName, 50);
	printf("%s", "����:");
	scanf_s("%s", g_info[*g_count].PassWord, 50);
	printf("%s", "��ע:");
	scanf_s("%s", g_info[*g_count].Remarks, 50);
	(*g_count)++;
	printf("��ӳɹ�!,��ǰ����: %d ������\n", *g_count);
	SaveFile(g_info, g_count, g_size);
}

/*
	����վ���޸�һ����Ϣ
*/
void upDateInfoBySite(SITEINFO* g_info, int* g_count, int* g_size)
{
	system("cls");
	char webSite[50] = {};
	printf("%s", "������վ��:");
	scanf_s("%s", webSite, 50);
	for (int i = 0; i < *g_count; i++)
	{
		if (strcmp(webSite, g_info[i].WebSite) == 0)
		{
			char user[50] = {};
			char pass[50] = {};
			char remark[50] = {};
			printf("%s", "�˺�:");
			scanf_s("%s", &user, 50);
			strcpy_s(g_info[i].UserName, 50, user);

			printf("%s", "����:");
			scanf_s("%s", &pass, 50);
			strcpy_s(g_info[i].PassWord, 50, pass);

			printf("%s", "��ע:");
			scanf_s("%s", &remark, 50);
			strcpy_s(g_info[i].Remarks, 50, remark);
			printf("%s", "�޸����\n");
			printf("վ��:%s\t\t�˺�:%s\t\t����:%s\t\t��ע:%s\n", g_info[i].WebSite, g_info[i].UserName, g_info[i].PassWord, g_info[i].Remarks);
			break;
		}
	}
	SaveFile(g_info, g_count, g_size);
	system("pause");
}

/*
	����վ��ɾ��һ����Ϣ
*/
void deleteInfoBySite(SITEINFO* g_info, int* g_count, int* g_size)
{
	system("cls");
	char webSite[50] = {};
	printf("%s", "������վ��:");
	scanf_s("%s", webSite, 50);
	int i;
	for (i = 0; i < *g_count; i++)
	{
		if (strcmp(webSite, g_info[i].WebSite) == 0)
		{
			for (int x = i; x < *g_count - 1; x++)
			{
				strcpy_s(g_info[x].WebSite, 50, g_info[x + 1].WebSite);
				strcpy_s(g_info[x].UserName, 50, g_info[x + 1].UserName);
				strcpy_s(g_info[x].PassWord, 50, g_info[x + 1].PassWord);
				strcpy_s(g_info[x].Remarks, 50, g_info[x + 1].Remarks);
			}
			(*g_count)--;
			break;
		}
	}
	printf("%s", "��Ϣ��ɾ��!\n");
	SaveFile(g_info, g_count, g_size);
	system("pause");
 }