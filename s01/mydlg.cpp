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
	CString str;
	int i=msht.GetActiveIndex();
	switch(i)
	{
	case 0://
		msht.mpg1.osave();
		return;
	case 1:
		msht.mpg2.onsave();
	case 2:
		str="page3";
		break;
	case 3:
		str="page4";
		break;
	case 4:
		str="page5";
		break;
	};
	MessageBox(str);
//	CDialog::OnOK();
};
afx_msg void mydlg::OnCancel()
{
	CDialog::OnCancel();
};