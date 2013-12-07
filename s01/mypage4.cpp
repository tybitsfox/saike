#include"stdafx.h"
#include"mypage4.h"
#include"datastruct.h"

extern CArray<_TAGUSER,_TAGUSER&> g_user;		//�û���Ϣ��ȫ�ֶ���
extern CArray<_TAGGUZHANG,_TAGGUZHANG&> g_gz;	//������Ϣ��ȫ�ֶ���
extern CArray<_TAGRUKU,_TAGRUKU&> g_ruku;		//�����Ϣ��ȫ�ֶ���
extern _TAGUSER  cur_user;						//���浱ǰ��¼�û���Ϣ�Ľṹ

typedef int (WINAPI *WEIXIU)(void*);
WEIXIU	wx=NULL;

IMPLEMENT_DYNCREATE(mypage4,CPropertyPage)

BEGIN_MESSAGE_MAP(mypage4,CPropertyPage)
	//
END_MESSAGE_MAP()

BOOL mypage4::OnInitDialog()
{
	CPropertyPage::OnInitDialog();
//����Ĳ��Դ����ڹ��������ݿ�������ݿ��л�ȡ���������
	CListCtrl *list=(CListCtrl*)GetDlgItem(IDC_LIST1);
	LONG style;
	style=GetWindowLong(list->m_hWnd,GWL_STYLE);
	style|=LVS_SHOWSELALWAYS;
	SetWindowLong(list->m_hWnd,GWL_STYLE,style);
	list->SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);//|LVS_EX_CHECKBOXES);
	list->InsertColumn(0,"��������",LVCFMT_LEFT,110,110);
	list->InsertColumn(1,"��������",LVCFMT_LEFT,600,600);
	list->InsertItem(0,"2013-11-14");
	list->SetItemText(0,1,"ssssssssssssssssssssssssss");
	list->InsertItem(1,"2013-12-1");
	list->SetItemText(1,1,"asdfjhasdfkjhasdflksajdfkjsdfoiuasdflkjsadfasdfqwe");
	list->InsertItem(2,"2013-10-14");
	list->SetItemText(2,1,"dddddddddddssssssssssssssssssssssssss");
	CComboBox *box=(CComboBox*)GetDlgItem(IDC_COMBO1);
	box->ResetContent();
	box->AddString("��ȫ");
	box->AddString("����");
	box->AddString("���ƽ�");
	box->AddString("��־��");
	box->AddString("�Ž���");
	box->AddString("����");
	box->AddString("����");
	box->AddString("���ΰҵ");
	box->AddString("����");
	box->SetCurSel(0);
	box=(CComboBox*)GetDlgItem(IDC_COMBO7);
	box->ResetContent();
	box->AddString("aaaa");
	box->AddString("bbbb");
	box->SetCurSel(0);
	box=(CComboBox*)GetDlgItem(IDC_COMBO8);
	box->ResetContent();
	box->AddString("aaaa");
	box->AddString("bbbb");
	box->SetCurSel(0);
	return true;
};
int mypage4::onsave()
{
	tagrepair rep;
	CString str;
	int i;//,j,k;
	memset((void*)&rep,0,sizeof(rep));
	CDateTimeCtrl *tcl=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1);
	tcl->GetTime(rep.in_date);//ȡ�ô���ʱ��
	CComboBox *box=(CComboBox*)GetDlgItem(IDC_COMBO1);
	box->GetLBText(box->GetCurSel(),str);
	memcpy(rep.weixiu,str.GetBuffer(0),str.GetLength());//ȡ��ά����Ա
	box=(CComboBox*)GetDlgItem(IDC_COMBO7);
	box->GetLBText(box->GetCurSel(),str);
	memcpy(rep.used1,str.GetBuffer(0),str.GetLength());//ȡ��ʹ�ñ���1
	box=(CComboBox*)GetDlgItem(IDC_COMBO8);
	box->GetLBText(box->GetCurSel(),str);
	memcpy(rep.used2,str.GetBuffer(0),str.GetLength());//ȡ��ʹ�ñ���2
	GetDlgItemText(IDC_EDIT1,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(rep.wait,str.GetBuffer(0),i);//ȡ�õȴ�ʱ��
	GetDlgItemText(IDC_EDIT2,str);
	if(str.IsEmpty())
		goto err_01;
	rep.times=atoi(str.GetBuffer(0));//ȡ��ά�޴���
	tcl=(CDateTimeCtrl *)GetDlgItem(IDC_DATETIMEPICKER2);
	tcl->GetTime(rep.fin_date);//ȡ�����ʱ��
	GetDlgItemText(IDC_EDIT55,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(rep.tiaopei1,str.GetBuffer(0),i);//ȡ�õ�����Ա1
	GetDlgItemText(IDC_EDIT56,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(rep.changjia1,str.GetBuffer(0),i);//ȡ�ó�����Ա1
	GetDlgItemText(IDC_EDIT6,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_l)
		goto err_01;
	memcpy(rep.method,str.GetBuffer(0),i);//ȡ�ô�����
//ȫ�������ݴ�����ϣ���ʼд�����ݿ�
	HMODULE mod=::LoadLibraryA("saikedll.dll");
	if(mod==NULL)
	{
		MessageBox("���ض�̬���ӿ�ʧ��");
		return 1;
	}
	wx=(WEIXIU)::GetProcAddress(mod,"save_weixiu");
	if(wx==NULL)
	{
		::FreeLibrary(mod);
		MessageBox("ȡ�ú�����ַʧ�ܣ�save_weixiu");
		return 1;
	}
	if(wx((void*)&rep)!=0)
	{
		::FreeLibrary(mod);
		return 1;
	}
	::FreeLibrary(mod);
	MessageBox("����ɹ�");
/*	CListCtrl *list=(CListCtrl*)GetDlgItem(IDC_LIST1);
	i=list->GetItemCount();
	k=-1;
	for(j=0;j<i;j++)
	{
		if(list->GetItemState(j,LVIS_SELECTED)==LVIS_SELECTED)
		{
			k=j;
		}
	}
	if(k==-1)
	{
		MessageBox("no selected!");
	}
	else
	{
		str.Format("%d is selected!",k);
		MessageBox(str);
	}*/
	return 0;
err_01:
	MessageBox("some where error");
	return 1;
};
void mypage4::init_data()
{
	int i,j;
	CListCtrl *list;
	CComboBox *box,*box1;
	list=(CListCtrl*)GetDlgItem(IDC_LIST1);
	list->DeleteAllItems();
	tagguzhang gz;
	tagruku  ruku;
	CString str;
	i=g_gz.GetCount();
	for(j=0;j<i;j++)
	{
		memset((void*)&gz,0,sizeof(gz));
		gz=g_gz.GetAt(j);
		str.Format("%04d-%02d-%02d :%02d",gz.sendtime.GetYear(),gz.sendtime.GetMonth(),\
			gz.sendtime.GetDay(),gz.sendtime.GetHour());
		list->InsertItem(j,str);
		str.Format(gz.desc);
		list->SetItemText(j,1,str);
	}
	i=g_ruku.GetCount();
	box=(CComboBox*)GetDlgItem(IDC_COMBO7);
	box->ResetContent();
	box1=(CComboBox*)GetDlgItem(IDC_COMBO8);
	box1->ResetContent();
	for(j=0;j<i;j++)
	{
		memset((void*)&ruku,0,sizeof(ruku));
		ruku=g_ruku.GetAt(j);
		str.Format(ruku.name);
		box->AddString(str);
		box1->AddString(str);
	}
	if(i>0)
	{
		box->SetCurSel(0);
		if(i>1)
			box1->SetCurSel(1);
		else
			box1->SetCurSel(0);
	}
};




















