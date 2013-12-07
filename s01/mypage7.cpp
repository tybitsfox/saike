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
	box->AddString("������־��ѯ");
	box->AddString("�豸̨�ʲ�ѯ");
	box->AddString("���ϼ�¼��ѯ");
	box->AddString("ά�޼�¼��ѯ");
	box->AddString("����¼��ѯ");
	box->AddString("�û����ϲ�ѯ");
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
	box->AddString("��������һ��ѯ");
	box->AddString("������������ѯ");
	box->AddString("����һ ���� ��������ѯ");
	box->AddString("����һ �� ��������ѯ");
	box->AddString("����������ȫ����ѯ");
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
	case 0://������־��ѯ
		box1->ResetContent();
		box2->ResetContent();
		box1->AddString("��������");
		box1->AddString("������ѹ");
		box1->AddString("ʪ��");
		box1->AddString("����");
		box1->AddString("�����¶�-��");
		box1->AddString("�����¶�-��");
		box1->AddString("ά����Ա");
		box1->AddString("������Ա");
		box1->AddString("������Ա");
		box1->AddString("�����¼�1");
		box1->AddString("�����¼�2");
		box1->AddString("�����¼�3");
		box1->AddString("�����¼�4");
		box2->AddString("��������");
		box2->AddString("������ѹ");
		box2->AddString("ʪ��");
		box2->AddString("����");
		box2->AddString("�����¶�-��");
		box2->AddString("�����¶�-��");
		box2->AddString("ά����Ա");
		box2->AddString("������Ա");
		box2->AddString("������Ա");
		box2->AddString("�����¼�1");
		box2->AddString("�����¼�2");
		box2->AddString("�����¼�3");
		box2->AddString("�����¼�4");
		break;
	case 1://�豸̨�ʲ�ѯ
		box1->ResetContent();
		box2->ResetContent();
		box1->AddString("�������");
		box1->AddString("��ص��ʾ");
		box1->AddString("����λ��");
		box1->AddString("����·�ɼ���ʽ");
		box1->AddString("�źŴ���·�ɼ���ʽ");
		box1->AddString("�豸����");
		box1->AddString("�豸����");
		box1->AddString("ip��ַ");
		box1->AddString("�ͺ�");
		box1->AddString("����");
		box1->AddString("��ע");
		box2->AddString("�������");
		box2->AddString("��ص��ʾ");
		box2->AddString("����λ��");
		box2->AddString("����·�ɼ���ʽ");
		box2->AddString("�źŴ���·�ɼ���ʽ");
		box2->AddString("�豸����");
		box2->AddString("�豸����");
		box2->AddString("ip��ַ");
		box2->AddString("�ͺ�");
		box2->AddString("����");
		box2->AddString("��ע");
		break;
	case 2://���ϼ�¼
		box1->ResetContent();
		box2->ResetContent();
		box1->AddString("����ʱ��");
		box1->AddString("���ַ�ʽ");
		box1->AddString("������/������");
		box1->AddString("�豸����");
		box1->AddString("����λ��");
		box1->AddString("��������ϵ��ʽ");
		box1->AddString("�豸���");
		box1->AddString("��������");
		box2->AddString("����ʱ��");
		box2->AddString("���ַ�ʽ");
		box2->AddString("������/������");
		box2->AddString("�豸����");
		box2->AddString("����λ��");
		box2->AddString("��������ϵ��ʽ");
		box2->AddString("�豸���");
		box2->AddString("��������");
		break;
	case 3://ά�޼�¼
		box1->ResetContent();
		box2->ResetContent();
		box1->AddString("��ʼ����ʱ��");
		box1->AddString("ά����Ա");
		box1->AddString("ʹ�ñ���1");
		box1->AddString("ʹ�ñ���2");
		box1->AddString("�ȴ�ʱ��");
		box1->AddString("ά�޴���");
		box1->AddString("�ָ�ʱ��");
		box1->AddString("������Ա");
		box1->AddString("������Ա");
		box1->AddString("������");

		box2->AddString("��ʼ����ʱ��");
		box2->AddString("ά����Ա");
		box2->AddString("ʹ�ñ���1");
		box2->AddString("ʹ�ñ���2");
		box2->AddString("�ȴ�ʱ��");
		box2->AddString("ά�޴���");
		box2->AddString("�ָ�ʱ��");
		box2->AddString("������Ա");
		box2->AddString("������Ա");
		box2->AddString("������");
		break;
	case 4://����¼��ѯ
		box1->ResetContent();
		box2->ResetContent();
		box1->AddString("���ʱ��");
		box1->AddString("�豸����");
		box1->AddString("�ɹ���Ա");
		box1->AddString("Ʒ��");
		box1->AddString("�ͺ�");
		box1->AddString("���");
		box1->AddString("����");
		box1->AddString("��������");
		box1->AddString("�ɹ��ص�");
		box1->AddString("��Ӧ��");
		box1->AddString("������ϵ��ʽ");
		box1->AddString("�����Ա");
		box1->AddString("��Ʒ����Ȩ");
		box2->AddString("���ʱ��");
		box2->AddString("�豸����");
		box2->AddString("�ɹ���Ա");
		box2->AddString("Ʒ��");
		box2->AddString("�ͺ�");
		box2->AddString("���");
		box2->AddString("����");
		box2->AddString("��������");
		box2->AddString("�ɹ��ص�");
		box2->AddString("��Ӧ��");
		box2->AddString("������ϵ��ʽ");
		box2->AddString("�����Ա");
		box2->AddString("��Ʒ����Ȩ");
		break;
	case 5://��Ա��ѯ
		box1->ResetContent();
		box2->ResetContent();
		box1->AddString("�û���");
		box1->AddString("�Ա�");
		box1->AddString("�ֻ�");
		box1->AddString("סַ");
		box1->AddString("email");
		box1->AddString("��λ");
		box1->AddString("����");
		box1->AddString("ְ��");
		box2->AddString("�û���");
		box2->AddString("�Ա�");
		box2->AddString("�ֻ�");
		box2->AddString("סַ");
		box2->AddString("email");
		box2->AddString("��λ");
		box2->AddString("����");
		box2->AddString("ְ��");
		break;
	};
};













