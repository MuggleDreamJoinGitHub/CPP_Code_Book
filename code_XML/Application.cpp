#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

// 提示
#include "Show.h"
// 文件流处理
#include "File_Stream.h" 
// 自定义宏
#include "Data.h"
// CRUD
#include "ctrl.h"

// 存储
char g_arrWebSite[300][20];
char g_arrUserName[300][20];
char g_arrPassWord[300][20];

// 存储计数
int nCount = 0;
// 最大容量
int g_size = 0;

/*
	密码本项目
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
		case 查询所有:
			findAll(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount);
			break;
		case 查询站点:
			findInfoBySite(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount);
			break;
		case 添加站点:
			addInfo(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount,&g_size);
			break;
		case 修改信息:
			upDateInfoBySite(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount,&g_size);
			break;
		case 删除站点:
			deleteInfoBySite(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount,&g_size);
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
