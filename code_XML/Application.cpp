#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

// �ṹ��
#include "StructClass.h"
// �Զ�������
#include "Data.h"
// �ļ�������
#include "File_Stream.h" 
// CRUD
#include "ctrl.h"
// ��ʾ
#include "Show.h"
/*
	���뱾��Ŀ
*/
int main()
{
	ReadMimaInfo(g_info, &g_count, &g_size);
	int flag = true;
	while (flag)
	{
		int nOpenNum = 0;
		show(g_count);
		scanf_s("%d", &nOpenNum);
		switch (nOpenNum)
		{
		case ��ѯ����:
			findAll(g_info, g_count, g_size);
			break;
		case ��ѯվ��:
			findInfoBySite(g_info, g_count, g_size);
			break;
		case ���վ��:
			addInfo(g_info, &g_count, &g_size);
			break;
		case �޸���Ϣ:
			upDateInfoBySite(g_info, &g_count, &g_size);
			break;
		case ɾ��վ��:
			deleteInfoBySite(g_info, &g_count, &g_size);
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