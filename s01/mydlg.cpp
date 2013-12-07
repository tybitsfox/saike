#include"stdafx.h"
#include"mydlg.h"
#include"logindlg.h"
extern DWORD	show_sign;
extern void pump();
CString snm[7];
BEGIN_MESSAGE_MAP(mydlg,CDialog)
	//
END_MESSAGE_MAP()

BOOL mydlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	snm[0]="工作日志";snm[1]="设备台帐";snm[2]="故障记录";
	snm[3]="维修记录";snm[4]="入库记录";snm[5]="用户管理";
	snm[6]="记录查询";
	ldlg dlg(NULL);
	if(dlg.DoModal()!=IDOK)
		PostQuitMessage(0);
	pump();
	msht.Create(this,WS_CHILD|WS_VISIBLE);
	msht.uid=show_sign;
	msht.ModifyStyleEx(0,WS_EX_CONTROLPARENT);
	msht.ModifyStyle(0,WS_TABSTOP);
	msht.SetWindowPos(NULL,0,0,0,0,SWP_NOSIZE|SWP_NOACTIVATE|SWP_NOZORDER);
	msht.show();
	return true;
};
afx_msg void mydlg::OnOK()
{
	CString str;
	int i=-1;//=msht.GetActiveIndex();
	msht.GetActivePage()->GetWindowTextA(str);
//由于属性页的动态性，不能再以序号确定操作的界面了，应该按照页面标题来确定。
	for(i=0;i<7;i++)
	{
		if(str==snm[i])
			break;
	}
	switch(i)
	{
	case 0://工作日志
		msht.mpg1.osave();
		return;
	case 1://设备台帐
		msht.mpg2.onsave();
		return;
	case 2://故障
		msht.mpg3.onsave();
		return;
	case 3://维修记录
		msht.mpg4.onsave();
		return;
	case 4://入库界面
		msht.mpg5.onsave();
		return;
	case 5://用户管理
		msht.mpg6.onsave();
		return;
	case 6://查询界面
		msht.mpg7.onsave();
		return;
	};
//	CDialog::OnOK();
};
afx_msg void mydlg::OnCancel()
{
	CDialog::OnCancel();
};