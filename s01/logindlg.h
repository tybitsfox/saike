#ifndef IDD_DIALOG2
#include"resource.h"
#endif

class ldlg:public CDialog
{
public:
	ldlg(CWnd *pwnd=NULL):CDialog(IDD_DIALOG2,pwnd){};
	BOOL OnInitDialog();
	afx_msg void OnOK();
	afx_msg void OnCancel();
	int read_db();
DECLARE_MESSAGE_MAP()
};