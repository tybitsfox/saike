#include"stdafx.h"
#include"mypage1.h"
#ifndef DB_DATA_STRUC
#include"datastruct.h"
#endif

typedef int (WINAPI *SAVEWKLG)(void*);
SAVEWKLG	sw=NULL;

IMPLEMENT_DYNCREATE(mypage1,CPropertyPage)

BEGIN_MESSAGE_MAP(mypage1,CPropertyPage)
	//
END_MESSAGE_MAP()

BOOL mypage1::OnInitDialog()
{
	CPropertyPage::OnInitDialog();
	CComboBox *box;
	box=(CComboBox*)GetDlgItem(IDC_COMBO2);
	box->AddString("��ȫ");
	box->AddString("����");
	box->SetCurSel(0);
	box=(CComboBox*)GetDlgItem(IDC_COMBO1);
	box->AddString("����");
	box->AddString("����");
	box->AddString("����");
	box->SetCurSel(0);
	box=(CComboBox*)GetDlgItem(IDC_COMBO3);
	box->AddString("���ƽ�");
	box->AddString("��־��");
	box->AddString("�Ž���");
	box->SetCurSel(0);
	box=(CComboBox*)GetDlgItem(IDC_COMBO4);
	box->AddString("��");
	box->AddString("��");
	box->AddString("��");
	box->AddString("��");
	box->AddString("����");
	box->AddString("����");
	box->AddString("����");
	box->AddString("����");
	box->SetCurSel(0);
	box=(CComboBox*)GetDlgItem(IDC_COMBO5);
	box->AddString("һ��");
	box->AddString("����");
	box->AddString("����");
	box->AddString("�ļ�");
	box->AddString("�弶");
	box->AddString("����");
	box->AddString("�߼�");
	box->AddString("�˼�");
	box->AddString("�ż�");
	box->AddString("ʮ��");
	box->AddString("ʮһ��");
	box->AddString("ʮ����");
	box->SetCurSel(0);
	return true;
};
//���ݱ��溯�� 
int mypage1::osave()
{
	tagwrklog tlg;
	CString str;
	int i;
	memset((void*)&tlg,0,sizeof(tlg));
	CDateTimeCtrl *tm;
	tm=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1);
	tm->GetTime(tlg.u_date);
	GetDlgItemText(IDC_EDIT1,str);//������ѹ
	tlg.dianya=atoi(str.GetBuffer(0));
	GetDlgItemText(IDC_EDIT2,str);//����ʪ�� 
	tlg.shidu=atoi(str.GetBuffer(0));
	CComboBox *box=(CComboBox*)GetDlgItem(IDC_COMBO1);
	box->GetLBText(box->GetCurSel(),str);
	i=str.GetLength();
	if(i>dlen_m)
		goto err_01;
	memcpy(tlg.qihou,str.GetBuffer(0),i);//�������� 
	GetDlgItemText(IDC_EDIT3,str);//�¶�1
	tlg.lotemp=atoi(str.GetBuffer(0));
	GetDlgItemText(IDC_EDIT4,str);//�¶�2
	tlg.uptemp=atoi(str.GetBuffer(0));
	box=(CComboBox*)GetDlgItem(IDC_COMBO2);
	box->GetLBText(box->GetCurSel(),str);//ά����Ա 
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(tlg.weixiu1,str.GetBuffer(0),str.GetLength());
	box=(CComboBox*)GetDlgItem(IDC_COMBO3);
	box->GetLBText(box->GetCurSel(),str);//������Ա
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(tlg.tiaopei1,str.GetBuffer(0),i);
	GetDlgItemText(IDC_EDIT5,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(tlg.changjia1,str.GetBuffer(0),i);//������Ա
	box=(CComboBox*)GetDlgItem(IDC_COMBO4);
	box->GetLBText(box->GetCurSel(),str);
	memcpy(tlg.wind_dir,str.GetBuffer(0),str.GetLength());//����
	box=(CComboBox*)GetDlgItem(IDC_COMBO5);
	box->GetLBText(box->GetCurSel(),str);
	memcpy(tlg.wind,str.GetBuffer(0),str.GetLength());//����
	GetDlgItemText(IDC_EDIT6,str);//�����¼�1
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_l)
			goto err_01;
		memcpy(tlg.event1,str.GetBuffer(0),i);
	}
	GetDlgItemText(IDC_EDIT8,str);//�����¼�2
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_l)
			goto err_01;
		memcpy(tlg.event2,str.GetBuffer(0),i);
	}
	GetDlgItemText(IDC_EDIT7,str);//�����¼�3
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_l)
			goto err_01;
		memcpy(tlg.event3,str.GetBuffer(0),i);
	}
	GetDlgItemText(IDC_EDIT9,str);//�����¼�4
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_l)
			goto err_01;
		memcpy(tlg.event4,str.GetBuffer(0),i);
	}
//ok�����ˣ�������¼��������������ϣ���ʼ���档
	HMODULE mod;
	mod=::LoadLibraryA("saikedll.dll");
	if(mod==NULL)
	{
		MessageBox("load library error");
		return 0;
	}
	sw=(SAVEWKLG)::GetProcAddress(mod,"save_wrklg");
	if(sw==NULL)
	{
		::FreeLibrary(mod);
		MessageBox("get procaddrsee error");
		return 0;
	}
	sw((void*)&tlg);
	::FreeLibrary(mod);
	MessageBox("����ɹ���");
	return 0;
err_01:
	MessageBox("some where error");
	return 1;
};