// ½á¹¹Ìå
typedef struct _SITEINFO
{
	char WebSite[50];
	char UserName[50];
	char PassWord[50];
}SITEINFO, * PSITEINFO;


extern SITEINFO* g_pInfo;
extern int g_num;
