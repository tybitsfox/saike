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
	snm[0]="������־";snm[1]="�豸̨��";snm[2]="���ϼ�¼";
	snm[3]="ά�޼�¼";snm[4]="����¼";snm[5]="�û�����";
	snm[6]="��¼��ѯ";
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
//��������ҳ�Ķ�̬�ԣ������������ȷ�������Ľ����ˣ�Ӧ�ð���ҳ�������ȷ����
	for(i=0;i<7;i++)
	{
		if(str==snm[i])
			break;
	}
	switch(i)
	{
	case 0://������־
		msht.mpg1.osave();
		return;
	case 1://�豸̨��
		msht.mpg2.onsave();
		return;
	case 2://����
		msht.mpg3.onsave();
		return;
	case 3://ά�޼�¼
		msht.mpg4.onsave();
		return;
	case 4://������
		msht.mpg5.onsave();
		return;
	case 5://�û�����
		msht.mpg6.onsave();
		return;
	case 6://��ѯ����
		msht.mpg7.onsave();
		return;
	};
//	CDialog::OnOK();
};
afx_msg void mydlg::OnCancel()
{
	CDialog::OnCancel();
};