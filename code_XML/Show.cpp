#include <stdio.h>

/*
	显示提示信息
*/
void show(int g_count)
{
	printf("%s", "---------------------------------------\n");
	printf("|密码本项目 v1.0 ---- 当前共有 %d 条信息|\n", g_count);
	printf("%s", "---------------------------------------\n");
	printf("%s", "查询所有 1\n");
	printf("%s", "查询站点 2\n");
	printf("%s", "添加站点 3\n");
	printf("%s", "修改信息 4\n");
	printf("%s", "删除站点 5\n");
	printf("%s", "退出程序 6\n");
	printf("%s", "----------------\n");
	printf("%s", "请输入编号:");
}