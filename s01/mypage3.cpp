#include"stdafx.h"
#include"mypage3.h"
#include"datastruct.h"

typedef int (WINAPI *SAVE_GZ)(void*);
SAVE_GZ s_gz=NULL;

IMPLEMENT_DYNCREATE(mypage3,CPropertyPage)

BEGIN_MESSAGE_MAP(mypage3,CPropertyPage)
	//
END_MESSAGE_MAP()

BOOL mypage3::OnInitDialog()
{
	CPropertyPage::OnInitDialog();
	CComboBox *box=(CComboBox*)GetDlgItem(IDC_COMBO1);
	box->AddString("报修");
	box->AddString("巡检");
	box->AddString("其他");
	box->SetCurSel(0);
	box=(CComboBox*)GetDlgItem(IDC_COMBO6);
	box->AddString("监控");
	box->AddString("楼宇对讲");
	box->AddString("网络传输");
	box->AddString("大屏幕");
	box->AddString("车辆管理");
	box->AddString("其他门禁");
	box->AddString("其他");
	box->SetCurSel(0);
	return true;
};
int mypage3::onsave()
{
	tagguzhang gz;
	CString str;
	int i;
	CDateTimeCtrl *tcl=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1);
	memset((void*)&gz,0,sizeof(gz));//发现时间
	tcl->GetTime(gz.sendtime);
	CComboBox *box=(CComboBox*)GetDlgItem(IDC_COMBO1);
	box->GetLBText(box->GetCurSel(),str);
	memcpy(gz.fangshi,str.GetBuffer(0),str.GetLength());//发现方式
	GetDlgItemText(IDC_EDIT1,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(gz.baoxiu,str.GetBuffer(0),i);//发现人/保修人
	GetDlgItemText(IDC_EDIT2,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(gz.mch_name,str.GetBuffer(0),i);//设备名称
	GetDlgItemText(IDC_EDIT3,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_m)
		goto err_01;
	memcpy(gz.posi,str.GetBuffer(0),i);//地理位置
	GetDlgItemText(IDC_EDIT4,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_m)
		goto err_01;
	memcpy(gz.baoxiu_con,str.GetBuffer(0),i);//保修人联系方式
	box=(CComboBox*)GetDlgItem(IDC_COMBO6);
	box->GetLBText(box->GetCurSel(),str);
	memcpy(gz.mch_type,str.GetBuffer(0),str.GetLength());//设备类别
	GetDlgItemText(IDC_EDIT6,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_el)
		goto err_01;
	memcpy(gz.desc,str.GetBuffer(0),i);// 故障描述
//故障id和操作者id为预留字段，暂不处理
	HMODULE mod=::LoadLibraryA("saikedll.dll");
	if(mod==NULL)
	{
		MessageBox("加载链接库失败。");
		return 1;
	}
	s_gz=(SAVE_GZ)::GetProcAddress(mod,"save_gz");
	if(s_gz==NULL)
	{
		::FreeLibrary(mod);
		MessageBox("getprocaddress error");
		return 1;
	}
	if(s_gz((void*)&gz)==0)
	{
		MessageBox("保存成功");
	}
	::FreeLibrary(mod);
	return 0;
err_01:
	MessageBox("some where error");
	return 1;
};