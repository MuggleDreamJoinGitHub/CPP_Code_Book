#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "StructClass.h"
#include "File_Stream.h"

/*
	查询所有
*/
void findAll(SITEINFO* g_info, int g_count, int g_size) {
	system("cls");
	for (int i = 0; i < g_count; i++)
	{
		printf("站点:%s\t\t账号:%s\t\t密码:%s\t\t备注:%s\n", g_info[i].WebSite, g_info[i].UserName, g_info[i].PassWord, g_info[i].Remarks);
	}
	system("pause");
}

/*
	根据站点查询单条信息
*/
void findInfoBySite(SITEINFO* g_info, int g_count, int g_size) {
	system("cls");
	char webSite[20] = {};
	printf("%s", "请输入站点:");
	scanf_s("%s", webSite, 20);
	for (int i = 0; i < g_count; i++)
	{
		if (strcmp(webSite, g_info[i].WebSite) == 0)
		{
			printf("站点:%s\t\t账号:%s\t\t密码:%s\t\t备注:%s\n", g_info[i].WebSite, g_info[i].UserName, g_info[i].PassWord, g_info[i].Remarks);
			break;
		}
	}
	system("pause");
}

/*
	添加一条信息
*/
void addInfo(SITEINFO* g_info, int* g_count,int * g_size)
{
	system("cls");
	printf("%s", "站点名称:");
	scanf_s("%s", g_info[*g_count].WebSite, 50);
	printf("%s", "账户:");
	scanf_s("%s", g_info[*g_count].UserName, 50);
	printf("%s", "密码:");
	scanf_s("%s", g_info[*g_count].PassWord, 50);
	printf("%s", "备注:");
	scanf_s("%s", g_info[*g_count].Remarks, 50);
	(*g_count)++;
	printf("添加成功!,当前共有: %d 条数据\n", *g_count);
	SaveFile(g_info, g_count, g_size);
}

/*
	根据站点修改一条信息
*/
void upDateInfoBySite(SITEINFO* g_info, int* g_count, int* g_size)
{
	system("cls");
	char webSite[50] = {};
	printf("%s", "请输入站点:");
	scanf_s("%s", webSite, 50);
	for (int i = 0; i < *g_count; i++)
	{
		if (strcmp(webSite, g_info[i].WebSite) == 0)
		{
			char user[50] = {};
			char pass[50] = {};
			char remark[50] = {};
			printf("%s", "账号:");
			scanf_s("%s", &user, 50);
			strcpy_s(g_info[i].UserName, 50, user);

			printf("%s", "密码:");
			scanf_s("%s", &pass, 50);
			strcpy_s(g_info[i].PassWord, 50, pass);

			printf("%s", "备注:");
			scanf_s("%s", &remark, 50);
			strcpy_s(g_info[i].Remarks, 50, remark);
			printf("%s", "修改完成\n");
			printf("站点:%s\t\t账号:%s\t\t密码:%s\t\t备注:%s\n", g_info[i].WebSite, g_info[i].UserName, g_info[i].PassWord, g_info[i].Remarks);
			break;
		}
	}
	SaveFile(g_info, g_count, g_size);
	system("pause");
}

/*
	根据站点删除一条信息
*/
void deleteInfoBySite(SITEINFO* g_info, int* g_count, int* g_size)
{
	system("cls");
	char webSite[50] = {};
	printf("%s", "请输入站点:");
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
	printf("%s", "信息已删除!\n");
	SaveFile(g_info, g_count, g_size);
	system("pause");
 }