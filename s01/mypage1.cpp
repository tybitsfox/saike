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
	box->AddString("张全");
	box->AddString("王珏");
	box->SetCurSel(0);
	box=(CComboBox*)GetDlgItem(IDC_COMBO1);
	box->AddString("晴天");
	box->AddString("多云");
	box->AddString("雨天");
	box->SetCurSel(0);
	box=(CComboBox*)GetDlgItem(IDC_COMBO3);
	box->AddString("吴善江");
	box->AddString("张志明");
	box->AddString("张进军");
	box->SetCurSel(0);
	box=(CComboBox*)GetDlgItem(IDC_COMBO4);
	box->AddString("东");
	box->AddString("西");
	box->AddString("南");
	box->AddString("北");
	box->AddString("东南");
	box->AddString("东北");
	box->AddString("西南");
	box->AddString("西北");
	box->SetCurSel(0);
	box=(CComboBox*)GetDlgItem(IDC_COMBO5);
	box->AddString("一级");
	box->AddString("二级");
	box->AddString("三级");
	box->AddString("四级");
	box->AddString("五级");
	box->AddString("六级");
	box->AddString("七级");
	box->AddString("八级");
	box->AddString("九级");
	box->AddString("十级");
	box->AddString("十一级");
	box->AddString("十二级");
	box->SetCurSel(0);
	return true;
};
//数据保存函数 
int mypage1::osave()
{
	tagwrklog tlg;
	CString str;
	int i;
	memset((void*)&tlg,0,sizeof(tlg));
	CDateTimeCtrl *tm;
	tm=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1);
	tm->GetTime(tlg.u_date);
	GetDlgItemText(IDC_EDIT1,str);//机房电压
	tlg.dianya=atoi(str.GetBuffer(0));
	GetDlgItemText(IDC_EDIT2,str);//机房湿度 
	tlg.shidu=atoi(str.GetBuffer(0));
	CComboBox *box=(CComboBox*)GetDlgItem(IDC_COMBO1);
	box->GetLBText(box->GetCurSel(),str);
	i=str.GetLength();
	if(i>dlen_m)
		goto err_01;
	memcpy(tlg.qihou,str.GetBuffer(0),i);//气候条件 
	GetDlgItemText(IDC_EDIT3,str);//温度1
	tlg.lotemp=atoi(str.GetBuffer(0));
	GetDlgItemText(IDC_EDIT4,str);//温度2
	tlg.uptemp=atoi(str.GetBuffer(0));
	box=(CComboBox*)GetDlgItem(IDC_COMBO2);
	box->GetLBText(box->GetCurSel(),str);//维保人员 
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(tlg.weixiu1,str.GetBuffer(0),str.GetLength());
	box=(CComboBox*)GetDlgItem(IDC_COMBO3);
	box->GetLBText(box->GetCurSel(),str);//调配人员
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
	memcpy(tlg.changjia1,str.GetBuffer(0),i);//厂家人员
	box=(CComboBox*)GetDlgItem(IDC_COMBO4);
	box->GetLBText(box->GetCurSel(),str);
	memcpy(tlg.wind_dir,str.GetBuffer(0),str.GetLength());//风向
	box=(CComboBox*)GetDlgItem(IDC_COMBO5);
	box->GetLBText(box->GetCurSel(),str);
	memcpy(tlg.wind,str.GetBuffer(0),str.GetLength());//风力
	GetDlgItemText(IDC_EDIT6,str);//特殊事件1
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_l)
			goto err_01;
		memcpy(tlg.event1,str.GetBuffer(0),i);
	}
	GetDlgItemText(IDC_EDIT8,str);//特殊事件2
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_l)
			goto err_01;
		memcpy(tlg.event2,str.GetBuffer(0),i);
	}
	GetDlgItemText(IDC_EDIT7,str);//特殊事件3
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_l)
			goto err_01;
		memcpy(tlg.event3,str.GetBuffer(0),i);
	}
	GetDlgItemText(IDC_EDIT9,str);//特殊事件4
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_l)
			goto err_01;
		memcpy(tlg.event4,str.GetBuffer(0),i);
	}
//ok，至此，工作记录中所有项输入完毕，开始保存。
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
	MessageBox("保存成功！");
	return 0;
err_01:
	MessageBox("some where error");
	return 1;
};