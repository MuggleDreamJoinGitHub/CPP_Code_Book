#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
// �ļ�������
#include "File_Stream.h" 

// �Զ����
#define ��ѯ���� 1
#define ��ѯվ�� 2
#define ���վ�� 3
#define �޸���Ϣ 4
#define ɾ��վ�� 5
#define ���������Ϣ���ļ� 6
#define �˳����� 7
// �洢
char g_arrWebSite[300][20];
char g_arrUserName[300][20];
char g_arrPassWord[300][20];

// �洢����
int nCount = 0;

/*
	���뱾��Ŀ-��ά����洢
*/

int main(void)
{
	ReadMimaInfo(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount);
	int flag = true;
	while (flag)
	{
		int nOpenNum = 0;
		int flag = 0;
		char userName[20] = {};
		char webSite[20] = {};
		printf("%s", "----------------\n");
		printf("%s", "|���뱾��Ŀ v1.0|\n");
		printf("%s", "----------------\n");
		printf("%s", "��ѯ���� 1\n");
		printf("%s", "��ѯվ�� 2\n");
		printf("%s", "���վ�� 3\n");
		printf("%s", "�޸���Ϣ 4\n");
		printf("%s", "ɾ��վ�� 5\n");
		printf("%s", "���������Ϣ���ļ� 6\n");
		printf("%s", "�˳����� 7\n");
		printf("%s", "----------------\n");
		printf("%s", "��������:");
		scanf_s("%d", &nOpenNum);
		switch (nOpenNum)
		{
		
		case ��ѯ����:
			system("cls");
			for (int i = 0; i < nCount; i++)
			{
				printf("%d: վ��:%s\t\t�û���:%s\t\t����:%s\n", (i + 1), g_arrWebSite[i], g_arrUserName[i], g_arrPassWord[i]);
			}
			if (nCount == 0)
			{
				printf("��ǰ�洢״̬Ϊ0!\n");
			}
			system("pause");
			break;
		case ��ѯվ��:
			system("cls");
			printf("%s", "������վ��:");
			scanf_s("%s", webSite, 20);
			for (int i = 0; i < nCount; i++)
			{
				if (strcmp(webSite, g_arrWebSite[i]) == 0)
				{	
					printf("վ��:%s\t\t�û���:%s\t\t����:%s\n", g_arrWebSite[i], g_arrUserName[i], g_arrPassWord[i]);
					flag++;
				}
			}
			if (flag == 1)
			{
				printf("�޴�վ����Ϣ!\n");
			}
			system("pause");
			break;
		case ���վ��:
			system("cls");
			printf("%s", "������վ������:");
			scanf_s("%s",g_arrWebSite[nCount], 20);
			printf("%s", "�������˻�:");
			scanf_s("%s", g_arrUserName[nCount], 20);
			printf("%s", "����������:");
			scanf_s("%s", g_arrPassWord[nCount], 20);
			nCount++;
			printf("��ӳɹ�!,��ǰ����: %d ������\n", nCount);

			SaveFile(g_arrWebSite, g_arrUserName,g_arrPassWord, &nCount);

			break;
		case �޸���Ϣ:
			
			system("cls");
			printf("%s", "������վ��:");
			scanf_s("%s", webSite, 20);
			for (int i = 0; i < nCount; i++)
			{
				if (strcmp(webSite, g_arrWebSite[i]) == 0)
				{
					flag++;
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
				}
			}
			if (flag ==1)
			{
				printf("û��վ����Ϣ!\n");
			}
			system("pause");
			break;
		case ɾ��վ��:
			system("cls");
			printf("%s", "������վ��:");
			scanf_s("%s", webSite, 20);
			int i;
			for (i = 0; i < nCount; i++)
			{
				if (strcmp(webSite, g_arrWebSite[i]) == 0)
				{
					for (int x = i; x < nCount - 1; x++)
					{
						strcpy_s(g_arrWebSite[x], 20, g_arrWebSite[x + 1]);
						strcpy_s(g_arrUserName[x], 20, g_arrUserName[x + 1]);
						strcpy_s(g_arrPassWord[x], 20, g_arrPassWord[x + 1]);
					}
					nCount--;
					flag++;
					break;
				}
			}
			if (flag == 0)
			{
				printf("û��վ����Ϣ!\n");
			}
			system("pause");
			break;
		case ���������Ϣ���ļ�:
			// ���浽���뱾



			break;
		case �˳�����:
			flag = false;
			break;
		case 0: // ��ֹ�س���ѭ������!
			flag = false;
			break;
		default:
			printf("��Ų���ȷ, ����������\n");
			break;
		}
	}
	return 0;	
}
