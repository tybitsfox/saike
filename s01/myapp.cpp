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

CArray<_TAGUSER,_TAGUSER&> g_user;		//�û���Ϣ��ȫ�ֶ���
CArray<_TAGGUZHANG,_TAGGUZHANG&> g_gz;	//������Ϣ��ȫ�ֶ���
CArray<_TAGRUKU,_TAGRUKU&> g_ruku;		//�����Ϣ��ȫ�ֶ���
_TAGUSER  cur_user;						//���浱ǰ��¼�û���Ϣ�Ľṹ
DWORD	show_sign=0xff;					//ȫ����ʾ,λ1�����һ����ҳ��λ2����ڶ�...

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
