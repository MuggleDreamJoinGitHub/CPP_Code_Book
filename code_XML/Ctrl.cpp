#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StructClass.h"
#include "File_Stream.h"

/*
	查询所有
*/
void findAll(int nCount) {
	system("cls");
	for (int i = 0; i < nCount; i++)
	{
		printf("站点:%s\t\t账号:%s\t\t密码:%s\n", g_pInfo[i].WebSite, g_pInfo[i].UserName, g_pInfo[i].PassWord);
	}
}

/*
	根据站点查询单条信息
*/
void findInfoBySite(int nCount) {
	system("cls");
	char webSite[20] = {};
	printf("%s", "请输入站点:");
	scanf_s("%s", webSite, 20);
	system("cls");
	printf("%s", "---------------------------------------\n");
	for (int i = 0; i < nCount; i++)
	{
		if (strcmp(webSite, g_pInfo[i].WebSite) == 0)
		{
			printf("站点:%s\t\t账号:%s\t\t密码:%s\n", g_pInfo[i].WebSite, g_pInfo[i].UserName, g_pInfo[i].PassWord);
			printf("%s", "---------------------------------------\n");
			break;
		}
	}
}

/*
	添加一条信息
*/
void addInfo(int *pCount)
{
	
	system("cls");
	printf("%s", "站点名称:");
	scanf_s("%s", g_pInfo[*pCount].WebSite, 50);
	printf("%s", "账户:");
	scanf_s("%s", g_pInfo[*pCount].UserName, 50);
	printf("%s", "密码:");
	scanf_s("%s", g_pInfo[*pCount].PassWord, 50);
	system("cls");
	printf("添加成功!");
	printf("%s", "---------------------------------------\n");
	(*pCount)++;
	if (*pCount == g_num) //申请空间
	{
		// 申请一块原来大2倍大小的内容
		SITEINFO* pTemp = (SITEINFO*)malloc(g_num * 2 * sizeof(SITEINFO));
		// 将内容拷贝进去
		memcpy(pTemp, g_pInfo, g_num * sizeof(SITEINFO));
		// 将原来的地址释放
		free(g_pInfo);
		// 让全局的指针变量指向新申请的空间
		g_pInfo = pTemp;
		g_num *= 2;
		return;
	}
}

/*
	根据站点修改一条信息
*/
void upDateInfoBySite(int nCount)
{
	system("cls");
	char webSite[50] = {};
	printf("%s", "请输入站点:");
	scanf_s("%s", webSite, 50);
	for (int i = 0; i < nCount; i++)
	{
		if (strcmp(webSite, g_pInfo[i].WebSite) == 0)
		{
			char user[50] = {};
			char pass[50] = {};
			char remark[50] = {};
			printf("%s", "账号:");
			scanf_s("%s", &user, 50);
			strcpy_s(g_pInfo[i].UserName, 50, user);

			printf("%s", "密码:");
			scanf_s("%s", &pass, 50);
			strcpy_s(g_pInfo[i].PassWord, 50, pass);

			printf("%s", "修改完成\n");
			break;
		}
	}
	printf("%s", "未找到该信息\n");
	SaveFile(nCount);
	system("pause");
}

/*
	根据站点删除一条信息
*/
void deleteInfoBySite(int* pCount)
{
	system("cls");
	char webSite[50] = {};
	printf("%s", "请输入站点:");
	scanf_s("%s", webSite, 50);
	int i;
	for (i = 0; i < *pCount; i++)
	{
		if (strcmp(webSite, g_pInfo[i].WebSite) == 0)
		{
			printf("已经找到 --> 站点:%s\t\t账号:%s\t\t密码:%s\n ", g_pInfo[i].WebSite, g_pInfo[i].UserName, g_pInfo[i].PassWord);
			printf("是否删除? (1/0)");
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
				printf("%s", "信息已删除!\n");
				break;
			}
			else {
				break;
			}
		}
	}
 }