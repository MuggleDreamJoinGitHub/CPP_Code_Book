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
	���뱾
*/
int main()
{
	int nCount = 0;
	int nSelect = 0;
	ReadMimaInfo(&nCount); // ������ȡ���ȡ�ļ�
	int flag = true;
	while (flag)
	{
		int nOpenNum = 0;
		show(nCount); // ������ʾ
		scanf_s("%d", &nOpenNum);
		switch (nOpenNum)
		{
		case ��ѯ����:
			findAll(nCount);
			break;
		case ��ѯվ��:
			findInfoBySite(nCount);
			break;
		case ���վ��:
			addInfo(&nCount);
			SaveFile(nCount);
			break;
		case �޸���Ϣ:
			upDateInfoBySite(nCount);
			break;
		case ɾ��վ��:
			deleteInfoBySite(&nCount);
			break;
		case �˳�����:
			flag = false;
			printf("�˳�!");
			break;
		case 0: // ��ֹ�س���ѭ������!
			flag = false;
			printf("�������,���˳�");
			break;
		default:
			printf("��Ų���ȷ, ����������\n");
			break;
		}
	}
	return 0;	
}