#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "File_Stream.h" // �ļ�������
#include "Show.h" // ��ʾ��Ϣ
#include "data.h" // �Զ����
#include "Ctrl_CRUD.h" // ����

// �洢
char g_arrWebSite[300][20];
char g_arrUserName[300][20];
char g_arrPassWord[300][20];

// �洢����
int nCount = 0;

/*
	���뱾v1.0
*/
int main(void)
{
	ReadMimaInfo(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount); // ��ʼ����Ϣ
	int flag = true; // ���ѭ��״̬
	while (flag)
	{
		show(); // ��ʾ��Ϣ
		int nOpenNum = 0; // ������ʾ1,2,3,4,5,6,7
		scanf_s("%d", &nOpenNum);
		switch (nOpenNum)
		{
		case ��ѯ����:
			FindALL(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount);
			break;
		case ��ѯվ��:
			FindInfoBySite(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount);
			break;
		case ���վ��:
			AddInfo(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount);
			break;
		case �޸���Ϣ:
			UPDateInfo(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount);
			break;
		case ɾ��վ��:
			DeleteInfo(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount);
			break;
		case ���������Ϣ���ļ�:
			// GOTO
			break;
		case �˳�����:
			flag = false;
			break;
		case 0:
			flag = false;
			break;
		default:
			printf("��Ų���ȷ, ����������\n");
			break;
		}
	}
	return 0;	
}
