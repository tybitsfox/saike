#include"stdafx.h"
#include"mypage1.h"

IMPLEMENT_DYNCREATE(mypage1,CPropertyPage)

BEGIN_MESSAGE_MAP(mypage1,CPropertyPage)
	//
END_MESSAGE_MAP()

BOOL mypage1::OnInitDialog()
{
	CPropertyPage::OnInitDialog();
	return true;
};
