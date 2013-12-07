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
	box->AddString("监控");
	box->AddString("楼宇对讲");
	box->AddString("网络传输");
	box->AddString("大屏幕");
	box->AddString("车辆进出");
	box->AddString("其他门禁");
	box->AddString("办公用平");
	box->AddString("机房用品");
	box->AddString("其他");
	box->SetCurSel(0);
	box=(CComboBox*)GetDlgItem(IDC_COMBO3);
	box->AddString("用户备品");
	box->AddString("公司备品");
	box->AddString("其他");
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
	tcl->GetTime(ruku.in_date);//取得入库时间
	GetDlgItemText(IDC_EDIT1,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(ruku.name,str.GetBuffer(0),i);//取得设备名称
	GetDlgItemText(IDC_EDIT2,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(ruku.xinghao,str.GetBuffer(0),i);//取得设备型号
	GetDlgItemText(IDC_EDIT3,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(ruku.guige,str.GetBuffer(0),i);//取得设备规格
	GetDlgItemText(IDC_EDIT10,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_m)
		goto err_01;
	memcpy(ruku.gongying,str.GetBuffer(0),i);//取得供应商
	GetDlgItemText(IDC_EDIT4,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(ruku.pinpai,str.GetBuffer(0),i);//取得设备品牌
	CComboBox *box=(CComboBox*)GetDlgItem(IDC_COMBO2);
	box->GetLBText(box->GetCurSel(),str);
	memcpy(ruku.in_type,str.GetBuffer(0),str.GetLength());//取得所属分类
	GetDlgItemText(IDC_EDIT5,str);
	if(str.IsEmpty())
		goto err_01;
	ruku.counts=atoi(str.GetBuffer(0));//取得入库数量
	box=(CComboBox*)GetDlgItem(IDC_COMBO3);
	box->GetLBText(box->GetCurSel(),str);
	memcpy(ruku.belong,str.GetBuffer(0),str.GetLength());//取得备品所有权
	GetDlgItemText(IDC_EDIT57,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_m)
		goto err_01;
	memcpy(ruku.didian,str.GetBuffer(0),i);//取得采购地点
	GetDlgItemText(IDC_EDIT58,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(ruku.caigou,str.GetBuffer(0),i);//取得采购人员
	GetDlgItemText(IDC_EDIT59,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(ruku.ruku,str.GetBuffer(0),i);//取得采购人员
	GetDlgItemText(IDC_EDIT60,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_m)
		goto err_01;
	memcpy(ruku.conn,str.GetBuffer(0),i);//取得供货联系方式
//全部数据采集完毕，开始写入数据库
	HMODULE mod=::LoadLibraryA("saikedll.dll");
	if(mod==NULL)
	{
		MessageBox("加载动态链接库失败");
		return 1;
	}
	s_k=(SAVE_RUKU)::GetProcAddress(mod,"save_ruku");
	if(s_k==NULL)
	{
		::FreeLibrary(mod);
		MessageBox("取得函数地址失败：save_ruku");
		return 1;
	}
	if(s_k((void*)&ruku)!=0)
	{
		::FreeLibrary(mod);
		return 1;
	}
	MessageBox("保存成功");
	return 0;
err_01:
	MessageBox("some where error");
	return 1;
};