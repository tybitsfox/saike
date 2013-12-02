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


BOOL myapp::InitInstance()
{
	mydlg mdlg;
	m_pMainWnd=&mdlg;
	mdlg.DoModal();
	return false;
};