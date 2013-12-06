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
	memcpy(mch.jk_id,str.GetBuffer(0),i);//�����ص��ʾ
	mch.c_date=CTime::GetTickCount();//�Զ��������
	GetDlgItemText(IDC_EDIT10,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_m)
		goto err_01;
	memcpy(mch.posi,str.GetBuffer(0),i);//�������λ��
	GetDlgItemText(IDC_EDIT2,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(mch.signal,str.GetBuffer(0),i);//�����źż�·�ɴ��䷽ʽ
	GetDlgItemText(IDC_EDIT4,str);
	if(str.IsEmpty())
		goto err_01;
	i=str.GetLength();
	if(i>dlen_s)
		goto err_01;
	memcpy(mch.route,str.GetBuffer(0),i);//���湩�缰·�ɴ��䷽ʽ
	memcpy((void*)&mbk,(void*)&mch,sizeof(mch));//����ÿ����¼�Ĺ�����
/*���������Ĵ���Ϊ���Ȳ鿴��������Ʊ༭�����������Զ�ȷ���豸����Ϊ�������������ȡ
�����������Ȼ��ȡ�ö�Ӧ�����ƣ��ͺţ�ip����ע��Ϊһ�������ļ�¼�����Ըñ�һ������ȡ
��6���������¼��6�������豸��¼*/
	GetDlgItemText(IDC_EDIT6,str);
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//�豸����
		str="�����";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//�豸����
		GetDlgItemText(IDC_EDIT3,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//���������
		GetDlgItemText(IDC_EDIT7,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//������ͺ�
		GetDlgItemText(IDC_EDIT11,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip��ַ
		GetDlgItemText(IDC_EDIT12,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//��ע������Ǳ����
		}
		cmch.Add(mch);
	}//�������һ���������
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//���ù�������
	GetDlgItemText(IDC_EDIT8,str);//������ĵڶ���
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//�豸����
		str="�����";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//�豸����
		GetDlgItemText(IDC_EDIT3,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//���������
		GetDlgItemText(IDC_EDIT9,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//������ͺ�
		GetDlgItemText(IDC_EDIT13,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip��ַ
		GetDlgItemText(IDC_EDIT14,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//��ע������Ǳ����
		}
		cmch.Add(mch);
	}//������ڶ����������
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//���ù�������
	GetDlgItemText(IDC_EDIT15,str);//������ĵ�����
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//�豸����
		str="�����";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//�豸����
		GetDlgItemText(IDC_EDIT3,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//���������
		GetDlgItemText(IDC_EDIT16,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//������ͺ�
		GetDlgItemText(IDC_EDIT17,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip��ַ
		GetDlgItemText(IDC_EDIT18,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//��ע������Ǳ����
		}
		cmch.Add(mch);
	}//������������������
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//���ù�������
	GetDlgItemText(IDC_EDIT19,str);//������ĵ�����
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//�豸����
		str="�����";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//�豸����
		GetDlgItemText(IDC_EDIT3,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//���������
		GetDlgItemText(IDC_EDIT20,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//������ͺ�
		GetDlgItemText(IDC_EDIT21,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip��ַ
		GetDlgItemText(IDC_EDIT22,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//��ע������Ǳ����
		}
		cmch.Add(mch);
	}//������������������
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//���ù�������
	GetDlgItemText(IDC_EDIT23,str);//������ĵ�����
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//�豸����
		str="�����";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//�豸����
		GetDlgItemText(IDC_EDIT3,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//���������
		GetDlgItemText(IDC_EDIT24,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//������ͺ�
		GetDlgItemText(IDC_EDIT25,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip��ַ
		GetDlgItemText(IDC_EDIT26,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//��ע������Ǳ����
		}
		cmch.Add(mch);
	}//������������������
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//���ù�������
	GetDlgItemText(IDC_EDIT27,str);//������ĵ�����
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//�豸����
		str="�����";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//�豸����
		GetDlgItemText(IDC_EDIT3,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//���������
		GetDlgItemText(IDC_EDIT28,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//������ͺ�
		GetDlgItemText(IDC_EDIT29,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip��ַ
		GetDlgItemText(IDC_EDIT30,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//��ע������Ǳ����
		}
		cmch.Add(mch);
	}//������������������----ȫ����������
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//���ù�������
	GetDlgItemText(IDC_EDIT31,str);//�����豸�ĵ�һ��
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//�豸����
		str="�����豸";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//�豸����
		GetDlgItemText(IDC_EDIT5,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//�����豸����
		GetDlgItemText(IDC_EDIT32,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//�����豸�ͺ�
		GetDlgItemText(IDC_EDIT33,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip��ַ
		GetDlgItemText(IDC_EDIT34,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//��ע������Ǳ����
		}
		cmch.Add(mch);
	}//�����豸��һ���������
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//���ù�������
	GetDlgItemText(IDC_EDIT35,str);//�����豸�ĵڶ���
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//�豸����
		str="�����豸";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//�豸����
		GetDlgItemText(IDC_EDIT5,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//�����豸����
		GetDlgItemText(IDC_EDIT36,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//�����豸�ͺ�
		GetDlgItemText(IDC_EDIT37,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip��ַ
		GetDlgItemText(IDC_EDIT38,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//��ע������Ǳ����
		}
		cmch.Add(mch);
	}//�����豸�ڶ����������
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//���ù�������
	GetDlgItemText(IDC_EDIT39,str);//�����豸�ĵ�����
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//�豸����
		str="�����豸";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//�豸����
		GetDlgItemText(IDC_EDIT5,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//�����豸����
		GetDlgItemText(IDC_EDIT40,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//�����豸�ͺ�
		GetDlgItemText(IDC_EDIT41,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip��ַ
		GetDlgItemText(IDC_EDIT42,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//��ע������Ǳ����
		}
		cmch.Add(mch);
	}//�����豸�������������
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//���ù�������
	GetDlgItemText(IDC_EDIT43,str);//�����豸�ĵ�����
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//�豸����
		str="�����豸";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//�豸����
		GetDlgItemText(IDC_EDIT5,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//�����豸����
		GetDlgItemText(IDC_EDIT44,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//�����豸�ͺ�
		GetDlgItemText(IDC_EDIT45,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip��ַ
		GetDlgItemText(IDC_EDIT46,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//��ע������Ǳ����
		}
		cmch.Add(mch);
	}//�����豸�������������
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//���ù�������
	GetDlgItemText(IDC_EDIT47,str);//�����豸�ĵ�����
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//�豸����
		str="�����豸";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//�豸����
		GetDlgItemText(IDC_EDIT5,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//�����豸����
		GetDlgItemText(IDC_EDIT48,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//�����豸�ͺ�
		GetDlgItemText(IDC_EDIT49,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip��ַ
		GetDlgItemText(IDC_EDIT50,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//��ע������Ǳ����
		}
		cmch.Add(mch);
	}//�����豸�������������
	memcpy((void*)&mch,(void*)&mbk,sizeof(mch));//���ù�������
	GetDlgItemText(IDC_EDIT51,str);//�����豸�ĵ�����
	if(!str.IsEmpty())
	{
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.mch_name,str.GetBuffer(0),i);//�豸����
		str="�����豸";
		memcpy(mch.mch_type,str.GetBuffer(0),str.GetLength());//�豸����
		GetDlgItemText(IDC_EDIT5,str);
		if(str.IsEmpty())
			goto err_01;
		mch.counts=atoi(str.GetBuffer(0));//�����豸����
		GetDlgItemText(IDC_EDIT52,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.xinghao,str.GetBuffer(0),i);//�����豸�ͺ�
		GetDlgItemText(IDC_EDIT53,str);
		if(str.IsEmpty())
			goto err_01;
		i=str.GetLength();
		if(i>dlen_s)
			goto err_01;
		memcpy(mch.ip,str.GetBuffer(0),i);//ip��ַ
		GetDlgItemText(IDC_EDIT54,str);
		if(!str.IsEmpty())
		{
			i=str.GetLength();
			if(i>dlen_m)
				goto err_01;
			memcpy(mch.beizhu,str.GetBuffer(0),i);//��ע������Ǳ����
		}
		cmch.Add(mch);
	}//�����豸�������������
//ȫ�����ܵ������������ϣ���������ڶ���cmch�У���ʼд�����ݿ⡣
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