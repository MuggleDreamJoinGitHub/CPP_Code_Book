#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

// ��ʾ
#include "Show.h"
// �ļ�������
#include "File_Stream.h" 
// �Զ����
#include "Data.h"
// CRUD
#include "ctrl.h"

// �洢
char g_arrWebSite[300][20];
char g_arrUserName[300][20];
char g_arrPassWord[300][20];

// �洢����
int nCount = 0;
// �������
int g_size = 0;

/*
	���뱾��Ŀ
*/
int main()
{
	ReadMimaInfo(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount,&g_size);
	int flag = true;
	while (flag)
	{
		int nOpenNum = 0;
		int flag = 0;
		show();
		scanf_s("%d", &nOpenNum);
		switch (nOpenNum)
		{
		case ��ѯ����:
			findAll(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount);
			break;
		case ��ѯվ��:
			findInfoBySite(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount);
			break;
		case ���վ��:
			addInfo(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount,&g_size);
			break;
		case �޸���Ϣ:
			upDateInfoBySite(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount,&g_size);
			break;
		case ɾ��վ��:
			deleteInfoBySite(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount,&g_size);
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
