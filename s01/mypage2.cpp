#include"stdafx.h"
#include"mypage2.h"

IMPLEMENT_DYNCREATE(mypage2,CPropertyPage)

BEGIN_MESSAGE_MAP(mypage2,CPropertyPage)
	//
END_MESSAGE_MAP()

BOOL mypage2::OnInitDialog()
{
	CPropertyPage::OnInitDialog();
	return true;
};
