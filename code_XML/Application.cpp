#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "File_Stream.h" // 文件流处理
#include "Show.h" // 提示信息
#include "data.h" // 自定义宏
#include "Ctrl_CRUD.h" // 操作

// 存储
char g_arrWebSite[300][20];
char g_arrUserName[300][20];
char g_arrPassWord[300][20];

// 存储计数
int nCount = 0;

/*
	密码本v1.0
*/
int main(void)
{
	ReadMimaInfo(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount); // 初始化信息
	int flag = true; // 标记循环状态
	while (flag)
	{
		show(); // 提示信息
		int nOpenNum = 0; // 输入提示1,2,3,4,5,6,7
		scanf_s("%d", &nOpenNum);
		switch (nOpenNum)
		{
		case 查询所有:
			FindALL(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount);
			break;
		case 查询站点:
			FindInfoBySite(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount);
			break;
		case 添加站点:
			AddInfo(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount);
			break;
		case 修改信息:
			UPDateInfo(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount);
			break;
		case 删除站点:
			DeleteInfo(g_arrWebSite, g_arrUserName, g_arrPassWord, &nCount);
			break;
		case 输出所有信息到文件:
			// GOTO
			break;
		case 退出程序:
			flag = false;
			break;
		case 0:
			flag = false;
			break;
		default:
			printf("编号不正确, 请重新输入\n");
			break;
		}
	}
	return 0;	
}
