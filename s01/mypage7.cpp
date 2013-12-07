#include"stdafx.h"
#include"datastruct.h"
#include"mypage7.h"

IMPLEMENT_DYNCREATE(mypage7,CPropertyPage)
BEGIN_MESSAGE_MAP(mypage7,CPropertyPage)
	ON_CBN_SELCHANGE(IDC_COMBO1,onchg1)
END_MESSAGE_MAP()
BOOL mypage7::OnInitDialog()
{
	CPropertyPage::OnInitDialog();
	CComboBox *box=(CComboBox*)GetDlgItem(IDC_COMBO1);
	box->ResetContent();
	box->AddString("工作日志查询");
	box->AddString("设备台帐查询");
	box->AddString("故障记录查询");
	box->AddString("维修记录查询");
	box->AddString("入库记录查询");
	box->AddString("用户资料查询");
	box->SetCurSel(0);
	com_chg(0);
	box=(CComboBox*)GetDlgItem(IDC_COMBO3);
	box->AddString(">");
	box->AddString(">=");
	box->AddString("=");
	box->AddString("<");
	box->AddString("<=");
	box->AddString("like");
	box=(CComboBox*)GetDlgItem(IDC_COMBO5);
	box->AddString(">");
	box->AddString(">=");
	box->AddString("=");
	box->AddString("<");
	box->AddString("<=");
	box->AddString("like");
	box=(CComboBox*)GetDlgItem(IDC_COMBO6);
	box->ResetContent();
	box->AddString("按照条件一查询");
	box->AddString("按照条件二查询");
	box->AddString("条件一 并且 条件二查询");
	box->AddString("条件一 或 条件二查询");
	box->AddString("不按条件，全部查询");
	box->SetCurSel(0);
	return true;
};
int mypage7::onsave()
{return 0;};
afx_msg void mypage7::onchg1()
{
	int i;
	CComboBox *box=(CComboBox*)GetDlgItem(IDC_COMBO1);
	i=box->GetCurSel();
	com_chg(i);
};
void mypage7::com_chg(int sel)
{
	CComboBox *box1,*box2;
	box1=(CComboBox*)GetDlgItem(IDC_COMBO2);
	box2=(CComboBox*)GetDlgItem(IDC_COMBO4);
	switch(sel)
	{
	case 0://工作日志查询
		box1->ResetContent();
		box2->ResetContent();
		box1->AddString("工作日期");
		box1->AddString("机房电压");
		box1->AddString("湿度");
		box1->AddString("气候");
		box1->AddString("环境温度-高");
		box1->AddString("环境温度-低");
		box1->AddString("维修人员");
		box1->AddString("调配人员");
		box1->AddString("厂家人员");
		box1->AddString("特殊事件1");
		box1->AddString("特殊事件2");
		box1->AddString("特殊事件3");
		box1->AddString("特殊事件4");
		box2->AddString("工作日期");
		box2->AddString("机房电压");
		box2->AddString("湿度");
		box2->AddString("气候");
		box2->AddString("环境温度-高");
		box2->AddString("环境温度-低");
		box2->AddString("维修人员");
		box2->AddString("调配人员");
		box2->AddString("厂家人员");
		box2->AddString("特殊事件1");
		box2->AddString("特殊事件2");
		box2->AddString("特殊事件3");
		box2->AddString("特殊事件4");
		break;
	case 1://设备台帐查询
		box1->ResetContent();
		box2->ResetContent();
		box1->AddString("清查日期");
		box1->AddString("监控点标示");
		box1->AddString("地理位置");
		box1->AddString("供电路由及方式");
		box1->AddString("信号传输路由及方式");
		box1->AddString("设备类型");
		box1->AddString("设备名称");
		box1->AddString("ip地址");
		box1->AddString("型号");
		box1->AddString("数量");
		box1->AddString("备注");
		box2->AddString("清查日期");
		box2->AddString("监控点标示");
		box2->AddString("地理位置");
		box2->AddString("供电路由及方式");
		box2->AddString("信号传输路由及方式");
		box2->AddString("设备类型");
		box2->AddString("设备名称");
		box2->AddString("ip地址");
		box2->AddString("型号");
		box2->AddString("数量");
		box2->AddString("备注");
		break;
	case 2://故障记录
		box1->ResetContent();
		box2->ResetContent();
		box1->AddString("发现时间");
		box1->AddString("发现方式");
		box1->AddString("保修人/发现人");
		box1->AddString("设备名称");
		box1->AddString("地理位置");
		box1->AddString("保修人联系方式");
		box1->AddString("设备类别");
		box1->AddString("故障描述");
		box2->AddString("发现时间");
		box2->AddString("发现方式");
		box2->AddString("保修人/发现人");
		box2->AddString("设备名称");
		box2->AddString("地理位置");
		box2->AddString("保修人联系方式");
		box2->AddString("设备类别");
		box2->AddString("故障描述");
		break;
	case 3://维修记录
		box1->ResetContent();
		box2->ResetContent();
		box1->AddString("开始处理时间");
		box1->AddString("维修人员");
		box1->AddString("使用备件1");
		box1->AddString("使用备件2");
		box1->AddString("等待时间");
		box1->AddString("维修次数");
		box1->AddString("恢复时间");
		box1->AddString("调配人员");
		box1->AddString("厂家人员");
		box1->AddString("处理方法");

		box2->AddString("开始处理时间");
		box2->AddString("维修人员");
		box2->AddString("使用备件1");
		box2->AddString("使用备件2");
		box2->AddString("等待时间");
		box2->AddString("维修次数");
		box2->AddString("恢复时间");
		box2->AddString("调配人员");
		box2->AddString("厂家人员");
		box2->AddString("处理方法");
		break;
	case 4://入库记录查询
		box1->ResetContent();
		box2->ResetContent();
		box1->AddString("入库时间");
		box1->AddString("设备名称");
		box1->AddString("采购人员");
		box1->AddString("品牌");
		box1->AddString("型号");
		box1->AddString("规格");
		box1->AddString("数量");
		box1->AddString("所属分类");
		box1->AddString("采购地点");
		box1->AddString("供应商");
		box1->AddString("供货联系方式");
		box1->AddString("入库人员");
		box1->AddString("备品所有权");
		box2->AddString("入库时间");
		box2->AddString("设备名称");
		box2->AddString("采购人员");
		box2->AddString("品牌");
		box2->AddString("型号");
		box2->AddString("规格");
		box2->AddString("数量");
		box2->AddString("所属分类");
		box2->AddString("采购地点");
		box2->AddString("供应商");
		box2->AddString("供货联系方式");
		box2->AddString("入库人员");
		box2->AddString("备品所有权");
		break;
	case 5://人员查询
		box1->ResetContent();
		box2->ResetContent();
		box1->AddString("用户名");
		box1->AddString("性别");
		box1->AddString("手机");
		box1->AddString("住址");
		box1->AddString("email");
		box1->AddString("单位");
		box1->AddString("部门");
		box1->AddString("职务");
		box2->AddString("用户名");
		box2->AddString("性别");
		box2->AddString("手机");
		box2->AddString("住址");
		box2->AddString("email");
		box2->AddString("单位");
		box2->AddString("部门");
		box2->AddString("职务");
		break;
	};
};













