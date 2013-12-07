#include"stdafx.h"
#include"mypage5.h"
#include"datastruct.h"


typedef int (WINAPI *SAVE_RUKU)(void*);
SAVE_RUKU s_k=NULL;

IMPLEMENT_DYNCREATE(mypage5,CPropertyPage)

BEGIN_MESSAGE_MAP(mypage5,CPropertyPage)
	//
END_MESSAGE_MAP()

BOOL mypage5::OnInitDialog()
{
	CPropertyPage::OnInitDialog();
	CComboBox *box=(CComboBox*)GetDlgItem(IDC_COMBO2);
	box->ResetContent();
	box->AddString("���");
	box->AddString("¥��Խ�");
	box->AddString("���紫��");
	box->AddString("����Ļ");
	box->AddString("��������");
	box->AddString("�����Ž�");
	box->AddString("�칫��ƽ");
	box->AddString("������Ʒ");
	box->AddString("����");
	box->SetCurSel(0);
	box=(CComboBox*)GetDlgItem(IDC_COMBO3);
	box->AddString("�û���Ʒ");
	box->AddString("��˾��Ʒ");
	box->AddString("����");
	box->SetCurSel(0);
	return true;
};
int mypage5::onsave()
{
	tagruku ruku;
	CString str;
	int i;
	memset((void*)&ruku,0,sizeof(ruku));
	CDateTimeCtrl *tcl=(CDateTimeCtrl *)GetDlgItem(IDC_DATETIMEPICKER1);
	tcl->GetTime(ruku.in_date);//ȡ�����ʱ��
	GetDlgItemText(IDC_EDIT1,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(ruku.name,str.GetBuffer(0),i);//ȡ���豸����
	GetDlgItemText(IDC_EDIT2,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(ruku.xinghao,str.GetBuffer(0),i);//ȡ���豸�ͺ�
	GetDlgItemText(IDC_EDIT3,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(ruku.guige,str.GetBuffer(0),i);//ȡ���豸���
	GetDlgItemText(IDC_EDIT10,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_m)
		goto err_01;
	memcpy(ruku.gongying,str.GetBuffer(0),i);//ȡ�ù�Ӧ��
	GetDlgItemText(IDC_EDIT4,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(ruku.pinpai,str.GetBuffer(0),i);//ȡ���豸Ʒ��
	CComboBox *box=(CComboBox*)GetDlgItem(IDC_COMBO2);
	box->GetLBText(box->GetCurSel(),str);
	memcpy(ruku.in_type,str.GetBuffer(0),str.GetLength());//ȡ����������
	GetDlgItemText(IDC_EDIT5,str);
	if(str.IsEmpty())
		goto err_01;
	ruku.counts=atoi(str.GetBuffer(0));//ȡ���������
	box=(CComboBox*)GetDlgItem(IDC_COMBO3);
	box->GetLBText(box->GetCurSel(),str);
	memcpy(ruku.belong,str.GetBuffer(0),str.GetLength());//ȡ�ñ�Ʒ����Ȩ
	GetDlgItemText(IDC_EDIT57,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_m)
		goto err_01;
	memcpy(ruku.didian,str.GetBuffer(0),i);//ȡ�òɹ��ص�
	GetDlgItemText(IDC_EDIT58,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(ruku.caigou,str.GetBuffer(0),i);//ȡ�òɹ���Ա
	GetDlgItemText(IDC_EDIT59,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(ruku.ruku,str.GetBuffer(0),i);//ȡ�òɹ���Ա
	GetDlgItemText(IDC_EDIT60,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_m)
		goto err_01;
	memcpy(ruku.conn,str.GetBuffer(0),i);//ȡ�ù�����ϵ��ʽ
//ȫ�����ݲɼ���ϣ���ʼд�����ݿ�
	HMODULE mod=::LoadLibraryA("saikedll.dll");
	if(mod==NULL)
	{
		MessageBox("���ض�̬���ӿ�ʧ��");
		return 1;
	}
	s_k=(SAVE_RUKU)::GetProcAddress(mod,"save_ruku");
	if(s_k==NULL)
	{
		::FreeLibrary(mod);
		MessageBox("ȡ�ú�����ַʧ�ܣ�save_ruku");
		return 1;
	}
	if(s_k((void*)&ruku)!=0)
	{
		::FreeLibrary(mod);
		return 1;
	}
	MessageBox("����ɹ�");
	return 0;
err_01:
	MessageBox("some where error");
	return 1;
};