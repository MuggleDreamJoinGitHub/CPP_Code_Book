#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

// 结构体
#include "StructClass.h"
// 自定义数据
#include "Data.h"
// 文件流处理
#include "File_Stream.h" 
// CRUD
#include "ctrl.h"
// 提示
#include "Show.h"

/*
	密码本
*/
int main()
{
	int nCount = 0;
	int nSelect = 0;
	ReadMimaInfo(&nCount); // 启动读取后读取文件
	int flag = true;
	while (flag)
	{
		int nOpenNum = 0;
		show(nCount); // 操作提示
		scanf_s("%d", &nOpenNum);
		switch (nOpenNum)
		{
		case 查询所有:
			findAll(nCount);
			break;
		case 查询站点:
			findInfoBySite(nCount);
			break;
		case 添加站点:
			addInfo(&nCount);
			SaveFile(nCount);
			break;
		case 修改信息:
			upDateInfoBySite(nCount);
			break;
		case 删除站点:
			deleteInfoBySite(&nCount);
			break;
		case 退出程序:
			flag = false;
			printf("退出!");
			break;
		case 0: // 防止回车死循环问题!
			flag = false;
			printf("程序错误,已退出");
			break;
		default:
			printf("编号不正确, 请重新输入\n");
			break;
		}
	}
	return 0;	
}