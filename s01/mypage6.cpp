#include"stdafx.h"
#include"datastruct.h"
#include"mypage6.h"

IMPLEMENT_DYNCREATE(mypage6,CPropertyPage)
BEGIN_MESSAGE_MAP(mypage6,CPropertyPage)
	ON_BN_CLICKED(IDC_RADIO1,onrd1)
	ON_BN_CLICKED(IDC_RADIO2,onrd2)
END_MESSAGE_MAP()

BOOL mypage6::OnInitDialog()
{
	CPropertyPage::OnInitDialog();
	CComboBox *box=(CComboBox*)GetDlgItem(IDC_COMBO2);
	box->ResetContent();
	box->AddString("ÄÐ");
	box->AddString("Å®");
	box->SetCurSel(0);
	CButton *radio=(CButton*)GetDlgItem(IDC_RADIO1);
	radio->SetCheck(1);
	return true;
};
int mypage6::onsave()
{

	return 0;
};
afx_msg void mypage6::onrd1()
{
	CButton *bt=(CButton*)GetDlgItem(IDC_RADIO1);
	bt->SetCheck(1);
	bt=(CButton*)GetDlgItem(IDC_RADIO2);
	bt->SetCheck(0);
};
afx_msg void mypage6::onrd2()
{
	CButton *bt=(CButton*)GetDlgItem(IDC_RADIO2);
	bt->SetCheck(1);
	bt=(CButton*)GetDlgItem(IDC_RADIO1);
	bt->SetCheck(0);
};