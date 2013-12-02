#ifndef IDD_DIALOG1
#include"resource.h"
#endif
#ifndef MYPAGE_DEFINE_2
#include"mysheet.h"
#endif

class mydlg:public CDialog
{
public:
	mysheet msht;
	mydlg(CWnd *pwnd=NULL):CDialog(IDD_DIALOG1,pwnd)
	{};
	BOOL OnInitDialog();
	afx_msg void OnOK();
	afx_msg void OnCancel();
DECLARE_MESSAGE_MAP()
};