#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StructClass.h"
#include "File_Stream.h"

/*
	��ѯ����
*/
void findAll(int nCount) {
	system("cls");
	for (int i = 0; i < nCount; i++)
	{
		printf("վ��:%s\t\t�˺�:%s\t\t����:%s\n", g_pInfo[i].WebSite, g_pInfo[i].UserName, g_pInfo[i].PassWord);
	}
}

/*
	����վ���ѯ������Ϣ
*/
void findInfoBySite(int nCount) {
	system("cls");
	char webSite[20] = {};
	printf("%s", "������վ��:");
	scanf_s("%s", webSite, 20);
	system("cls");
	printf("%s", "---------------------------------------\n");
	for (int i = 0; i < nCount; i++)
	{
		if (strcmp(webSite, g_pInfo[i].WebSite) == 0)
		{
			printf("վ��:%s\t\t�˺�:%s\t\t����:%s\n", g_pInfo[i].WebSite, g_pInfo[i].UserName, g_pInfo[i].PassWord);
			printf("%s", "---------------------------------------\n");
			break;
		}
	}
}

/*
	���һ����Ϣ
*/
void addInfo(int *pCount)
{
	
	system("cls");
	printf("%s", "վ������:");
	scanf_s("%s", g_pInfo[*pCount].WebSite, 50);
	printf("%s", "�˻�:");
	scanf_s("%s", g_pInfo[*pCount].UserName, 50);
	printf("%s", "����:");
	scanf_s("%s", g_pInfo[*pCount].PassWord, 50);
	system("cls");
	printf("��ӳɹ�!");
	printf("%s", "---------------------------------------\n");
	(*pCount)++;
	if (*pCount == g_num) //����ռ�
	{
		// ����һ��ԭ����2����С������
		SITEINFO* pTemp = (SITEINFO*)malloc(g_num * 2 * sizeof(SITEINFO));
		// �����ݿ�����ȥ
		memcpy(pTemp, g_pInfo, g_num * sizeof(SITEINFO));
		// ��ԭ���ĵ�ַ�ͷ�
		free(g_pInfo);
		// ��ȫ�ֵ�ָ�����ָ��������Ŀռ�
		g_pInfo = pTemp;
		g_num *= 2;
		return;
	}
}

/*
	����վ���޸�һ����Ϣ
*/
void upDateInfoBySite(int nCount)
{
	system("cls");
	char webSite[50] = {};
	printf("%s", "������վ��:");
	scanf_s("%s", webSite, 50);
	for (int i = 0; i < nCount; i++)
	{
		if (strcmp(webSite, g_pInfo[i].WebSite) == 0)
		{
			char user[50] = {};
			char pass[50] = {};
			char remark[50] = {};
			printf("%s", "�˺�:");
			scanf_s("%s", &user, 50);
			strcpy_s(g_pInfo[i].UserName, 50, user);

			printf("%s", "����:");
			scanf_s("%s", &pass, 50);
			strcpy_s(g_pInfo[i].PassWord, 50, pass);

			printf("%s", "�޸����\n");
			break;
		}
	}
	printf("%s", "δ�ҵ�����Ϣ\n");
	SaveFile(nCount);
	system("pause");
}

/*
	����վ��ɾ��һ����Ϣ
*/
void deleteInfoBySite(int* pCount)
{
	system("cls");
	char webSite[50] = {};
	printf("%s", "������վ��:");
	scanf_s("%s", webSite, 50);
	int i;
	for (i = 0; i < *pCount; i++)
	{
		if (strcmp(webSite, g_pInfo[i].WebSite) == 0)
		{
			printf("�Ѿ��ҵ� --> վ��:%s\t\t�˺�:%s\t\t����:%s\n ", g_pInfo[i].WebSite, g_pInfo[i].UserName, g_pInfo[i].PassWord);
			printf("�Ƿ�ɾ��? (1/0)");
			int nFlag = NULL;
			scanf_s("%d", &nFlag, 2);
			if (nFlag == 1)
			{
				for (int x = i; x < *pCount - 1; x++)
				{
					strcpy_s(g_pInfo[x].WebSite, 50, g_pInfo[x + 1].WebSite);
					strcpy_s(g_pInfo[x].UserName, 50, g_pInfo[x + 1].UserName);
					strcpy_s(g_pInfo[x].PassWord, 50, g_pInfo[x + 1].PassWord);
				}
				(*pCount)--;
				printf("%s", "��Ϣ��ɾ��!\n");
				break;
			}
			else {
				break;
			}
		}
	}
 }