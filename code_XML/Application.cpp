#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
// 文件流处理
#include "File_Stream.h" 

// 自定义宏
#define 查询所有 1
#define 查询站点 2
#define 添加站点 3
#define 修改信息 4
#define 删除站点 5
#define 输出所有信息到文件 6
#define 退出程序 7
// 存储
char g_arrWebSite[300][20];
char g_arrUserName[300][20];
char g_arrPassWord[300][20];

// 存储计数
int nCount = 0;

/*
	密码本项目-二维数组存储
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
		printf("%s", "|密码本项目 v1.0|\n");
		printf("%s", "----------------\n");
		printf("%s", "查询所有 1\n");
		printf("%s", "查询站点 2\n");
		printf("%s", "添加站点 3\n");
		printf("%s", "修改信息 4\n");
		printf("%s", "删除站点 5\n");
		printf("%s", "输出所有信息到文件 6\n");
		printf("%s", "退出程序 7\n");
		printf("%s", "----------------\n");
		printf("%s", "请输入编号:");
		scanf_s("%d", &nOpenNum);
		switch (nOpenNum)
		{
		
		case 查询所有:
			system("cls");
			for (int i = 0; i < nCount; i++)
			{
				printf("%d: 站点:%s\t\t用户名:%s\t\t密码:%s\n", (i + 1), g_arrWebSite[i], g_arrUserName[i], g_arrPassWord[i]);
			}
			if (nCount == 0)
			{
				printf("当前存储状态为0!\n");
			}
			system("pause");
			break;
		case 查询站点:
			system("cls");
			printf("%s", "请输入站点:");
			scanf_s("%s", webSite, 20);
			for (int i = 0; i < nCount; i++)
			{
				if (strcmp(webSite, g_arrWebSite[i]) == 0)
				{	
					printf("站点:%s\t\t用户名:%s\t\t密码:%s\n", g_arrWebSite[i], g_arrUserName[i], g_arrPassWord[i]);
					flag++;
				}
			}
			if (flag == 1)
			{
				printf("无此站点信息!\n");
			}
			system("pause");
			break;
		case 添加站点:
			system("cls");
			printf("%s", "请输入站点名称:");
			scanf_s("%s",g_arrWebSite[nCount], 20);
			printf("%s", "请输入账户:");
			scanf_s("%s", g_arrUserName[nCount], 20);
			printf("%s", "请输入密码:");
			scanf_s("%s", g_arrPassWord[nCount], 20);
			nCount++;
			printf("添加成功!,当前共有: %d 条数据\n", nCount);

			SaveFile(g_arrWebSite, g_arrUserName,g_arrPassWord, &nCount);

			break;
		case 修改信息:
			
			system("cls");
			printf("%s", "请输入站点:");
			scanf_s("%s", webSite, 20);
			for (int i = 0; i < nCount; i++)
			{
				if (strcmp(webSite, g_arrWebSite[i]) == 0)
				{
					flag++;
					char user[20] = {};
					char pass[20] = {};
					printf("%s", "请输入账户:");
					scanf_s("%s", &user, 20);
					strcpy_s(g_arrUserName[i], 20, user);
					
					printf("%s", "请输入密码:");
					scanf_s("%s", &pass, 20);
					strcpy_s(g_arrPassWord[i], 20, pass);
					
					printf("%s", "修改完成\n");
					printf("站点:%s\t\t用户名:%s\t\t密码:%s\n", g_arrWebSite[i], g_arrUserName[i], g_arrPassWord[i]);
				}
			}
			if (flag ==1)
			{
				printf("没有站点信息!\n");
			}
			system("pause");
			break;
		case 删除站点:
			system("cls");
			printf("%s", "请输入站点:");
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
				printf("没有站点信息!\n");
			}
			system("pause");
			break;
		case 输出所有信息到文件:
			// 保存到密码本



			break;
		case 退出程序:
			flag = false;
			break;
		case 0: // 防止回车死循环问题!
			flag = false;
			break;
		default:
			printf("编号不正确, 请重新输入\n");
			break;
		}
	}
	return 0;	
}
