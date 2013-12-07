#include"stdafx.h"
#include"resource.h"
#include"mypage1.h"
#include"mypage2.h"
#include"mypage3.h"
#include"mypage4.h"
#include"mypage5.h"
#include"mysheet.h"
#include"mydlg.h"
#include"myapp.h"
#include"datastruct.h"

CArray<_TAGUSER,_TAGUSER&> g_user;		//用户信息的全局队列
CArray<_TAGGUZHANG,_TAGGUZHANG&> g_gz;	//故障信息的全局队列
CArray<_TAGRUKU,_TAGRUKU&> g_ruku;		//入库信息的全局队列
_TAGUSER  cur_user;						//保存当前登录用户信息的结构
DWORD	show_sign=0xff;					//全部显示,位1代表第一属性页，位2代表第二...

BOOL myapp::InitInstance()
{
	mydlg mdlg;
	m_pMainWnd=&mdlg;
	mdlg.DoModal();
	return false;
};
void pump()
{
	MSG msg;
	while(::PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
	{
		if(!AfxGetApp()->PumpMessage())
		{
			PostQuitMessage(0);
			return;
		}
	}
};
