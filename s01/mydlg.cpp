#include"stdafx.h"
#include"mydlg.h"

BEGIN_MESSAGE_MAP(mydlg,CDialog)
	//
END_MESSAGE_MAP()

BOOL mydlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	msht.Create(this,WS_CHILD|WS_VISIBLE);
	msht.ModifyStyleEx(0,WS_EX_CONTROLPARENT);
	msht.ModifyStyle(0,WS_TABSTOP);
	msht.SetWindowPos(NULL,0,0,0,0,SWP_NOSIZE|SWP_NOACTIVATE|SWP_NOZORDER);
	return true;
};
afx_msg void mydlg::OnOK()
{
	CDialog::OnOK();
};
afx_msg void mydlg::OnCancel()
{
	CDialog::OnCancel();
};