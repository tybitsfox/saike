#include"stdafx.h"
#include"mypage2.h"
#include"datastruct.h"

CArray<_TAGMCHLOG,_TAGMCHLOG&> cmch;

IMPLEMENT_DYNCREATE(mypage2,CPropertyPage)

BEGIN_MESSAGE_MAP(mypage2,CPropertyPage)
	//
END_MESSAGE_MAP()

BOOL mypage2::OnInitDialog()
{
	CPropertyPage::OnInitDialog();
	return true;
};
int mypage2::onsave()
{
	tagmchlog mch,mbk;
	int i,j;
	CString str;
	cmch.RemoveAll();
	memset((void*)&mch,0,sizeof(mch));
	memset((void*)&mbk,0,sizeof(mbk));
	GetDlgItemText(IDC_EDIT1,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(mch.jk_id,str.GetBuffer(0),i);//保存监控点表示
	mch.c_date=CTime::GetTickCount();//自动获得日期
	GetDlgItemText(IDC_EDIT10,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_m)
		goto err_01;
	memcpy(mch.posi,str.GetBuffer(0),i);//保存地理位置
	GetDlgItemText(IDC_EDIT2,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(mch.signal,str.GetBuffer(0),i);//保存信号及路由传输方式
	GetDlgItemText(IDC_EDIT4,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(mch.route,str.GetBuffer(0),i);//保存供电及路由传输方式
	memcpy((void*)&mbk,(void*)&mch,sizeof(mch));//保存每条记录的公共项
/*这里对输入的处理为：先查看摄像机名称编辑框，有内容则自动确定设备类型为：摄像机，数量取
摄像机数量，然后取得对应的名称，型号，ip，备注，为一条完整的记录，所以该表一次最多可取
得6条摄像机记录和6条其他设备记录*/
	GetDlgItemText(IDC_EDIT6,str);
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//设备名称
		str="摄像机";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//设备类型
		GetDlgItemText(IDC_EDIT3,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//摄像机数量
		GetDlgItemText(IDC_EDIT7,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//摄像机型号
		GetDlgItemText(IDC_EDIT11,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip地址
		GetDlgItemText(IDC_EDIT12,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//备注，该项不是必须的
		}
		cmch.Add(mch);
	}//摄像机第一项输入完成
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//重置公共部分
	GetDlgItemText(IDC_EDIT8,str);//摄像机的第二项
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//设备名称
		str="摄像机";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//设备类型
		GetDlgItemText(IDC_EDIT3,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//摄像机数量
		GetDlgItemText(IDC_EDIT9,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//摄像机型号
		GetDlgItemText(IDC_EDIT13,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip地址
		GetDlgItemText(IDC_EDIT14,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//备注，该项不是必须的
		}
		cmch.Add(mch);
	}//摄像机第二项输入完成
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//重置公共部分
	GetDlgItemText(IDC_EDIT15,str);//摄像机的第三项
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//设备名称
		str="摄像机";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//设备类型
		GetDlgItemText(IDC_EDIT3,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//摄像机数量
		GetDlgItemText(IDC_EDIT16,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//摄像机型号
		GetDlgItemText(IDC_EDIT17,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip地址
		GetDlgItemText(IDC_EDIT18,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//备注，该项不是必须的
		}
		cmch.Add(mch);
	}//摄像机第三项输入完成
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//重置公共部分
	GetDlgItemText(IDC_EDIT19,str);//摄像机的第四项
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//设备名称
		str="摄像机";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//设备类型
		GetDlgItemText(IDC_EDIT3,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//摄像机数量
		GetDlgItemText(IDC_EDIT20,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//摄像机型号
		GetDlgItemText(IDC_EDIT21,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip地址
		GetDlgItemText(IDC_EDIT22,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//备注，该项不是必须的
		}
		cmch.Add(mch);
	}//摄像机第四项输入完成
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//重置公共部分
	GetDlgItemText(IDC_EDIT23,str);//摄像机的第五项
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//设备名称
		str="摄像机";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//设备类型
		GetDlgItemText(IDC_EDIT3,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//摄像机数量
		GetDlgItemText(IDC_EDIT24,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//摄像机型号
		GetDlgItemText(IDC_EDIT25,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip地址
		GetDlgItemText(IDC_EDIT26,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//备注，该项不是必须的
		}
		cmch.Add(mch);
	}//摄像机第五项输入完成
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//重置公共部分
	GetDlgItemText(IDC_EDIT27,str);//摄像机的第六项
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//设备名称
		str="摄像机";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//设备类型
		GetDlgItemText(IDC_EDIT3,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//摄像机数量
		GetDlgItemText(IDC_EDIT28,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//摄像机型号
		GetDlgItemText(IDC_EDIT29,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip地址
		GetDlgItemText(IDC_EDIT30,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//备注，该项不是必须的
		}
		cmch.Add(mch);
	}//摄像机第六项输入完成----全部摄像机完成
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//重置公共部分
	GetDlgItemText(IDC_EDIT31,str);//其他设备的第一项
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//设备名称
		str="其他设备";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//设备类型
		GetDlgItemText(IDC_EDIT5,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//其他设备数量
		GetDlgItemText(IDC_EDIT32,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//其他设备型号
		GetDlgItemText(IDC_EDIT33,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip地址
		GetDlgItemText(IDC_EDIT34,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//备注，该项不是必须的
		}
		cmch.Add(mch);
	}//其他设备第一项输入完成
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//重置公共部分
	GetDlgItemText(IDC_EDIT35,str);//其他设备的第二项
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//设备名称
		str="其他设备";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//设备类型
		GetDlgItemText(IDC_EDIT5,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//其他设备数量
		GetDlgItemText(IDC_EDIT36,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//其他设备型号
		GetDlgItemText(IDC_EDIT37,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip地址
		GetDlgItemText(IDC_EDIT38,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//备注，该项不是必须的
		}
		cmch.Add(mch);
	}//其他设备第二项输入完成
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//重置公共部分
	GetDlgItemText(IDC_EDIT39,str);//其他设备的第三项
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//设备名称
		str="其他设备";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//设备类型
		GetDlgItemText(IDC_EDIT5,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//其他设备数量
		GetDlgItemText(IDC_EDIT40,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//其他设备型号
		GetDlgItemText(IDC_EDIT41,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip地址
		GetDlgItemText(IDC_EDIT42,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//备注，该项不是必须的
		}
		cmch.Add(mch);
	}//其他设备第三项输入完成
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//重置公共部分
	GetDlgItemText(IDC_EDIT43,str);//其他设备的第四项
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//设备名称
		str="其他设备";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//设备类型
		GetDlgItemText(IDC_EDIT5,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//其他设备数量
		GetDlgItemText(IDC_EDIT44,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//其他设备型号
		GetDlgItemText(IDC_EDIT45,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip地址
		GetDlgItemText(IDC_EDIT46,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//备注，该项不是必须的
		}
		cmch.Add(mch);
	}//其他设备第四项输入完成
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//重置公共部分
	GetDlgItemText(IDC_EDIT47,str);//其他设备的第五项
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//设备名称
		str="其他设备";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//设备类型
		GetDlgItemText(IDC_EDIT5,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//其他设备数量
		GetDlgItemText(IDC_EDIT48,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//其他设备型号
		GetDlgItemText(IDC_EDIT49,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip地址
		GetDlgItemText(IDC_EDIT50,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//备注，该项不是必须的
		}
		cmch.Add(mch);
	}//其他设备第五项输入完成
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//重置公共部分
	GetDlgItemText(IDC_EDIT51,str);//其他设备的第六项
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//设备名称
		str="其他设备";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//设备类型
		GetDlgItemText(IDC_EDIT5,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//其他设备数量
		GetDlgItemText(IDC_EDIT52,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//其他设备型号
		GetDlgItemText(IDC_EDIT53,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip地址
		GetDlgItemText(IDC_EDIT54,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//备注，该项不是必须的
		}
		cmch.Add(mch);
	}//其他设备第六项输入完成
//全部可能的输入项都处理完毕，结果保存在队列cmch中，开始写入数据库。
	i=cmch.GetCount();
	if(i>0)
	{

	}
	cmch.RemoveAll();
	return 0;
err_01:
	MessageBox("some where error");
	return 1;
};