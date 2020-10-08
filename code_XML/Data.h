// 提示信息
#define 查询所有 1
#define 查询站点 2
#define 添加站点 3
#define 修改信息 4
#define 删除站点 5
#define 退出程序 6

// 存储
char g_arrWebSite[300][20];
char g_arrUserName[300][20];
char g_arrPassWord[300][20];

// 存储计数
int nCount = 0;
// 最大容量
int g_size = 0;