#include"stdafx.h"
#include"logindlg.h"
#include"datastruct.h"

extern DWORD	show_sign;

extern CArray<_TAGUSER,_TAGUSER&> g_user;		//�û���Ϣ��ȫ�ֶ���
extern CArray<_TAGGUZHANG,_TAGGUZHANG&> g_gz;	//������Ϣ��ȫ�ֶ���
extern CArray<_TAGRUKU,_TAGRUKU&> g_ruku;		//�����Ϣ��ȫ�ֶ���
extern _TAGUSER  cur_user;	
CArray<_TAGUSER,_TAGUSER&> *cuser;
CArray<_TAGGUZHANG,_TAGGUZHANG&> *cgz;
CArray<_TAGRUKU,_TAGRUKU&> *cruku;

typedef int (WINAPI *READ_USER)(void*);
READ_USER	rd_nor=NULL;



BEGIN_MESSAGE_MAP(ldlg,CDialog)
	//
END_MESSAGE_MAP()

BOOL ldlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	return true;
};
afx_msg void ldlg::OnOK()
{
	int i,j;
	_TAGUSER  usr;	
	CString sn,sp,un,up;
	GetDlgItemText(IDC_EDIT1,sn);
	GetDlgItemText(IDC_EDIT2,sp);
//	if(read_db()!=0)
//		CDialog::OnCancel();
//���жϵ�¼�û��Ƿ����û��б��С�
	i=g_user.GetCount();
	for(j=0;j<i;j++)
	{
		memset((void*)&usr,0,sizeof(usr));
		usr=g_user.GetAt(j);
		un.Format(usr.uname);
		up.Format(usr.pwd);
		if(sn==un && sp==up)
		{
			memset((void*)&cur_user,0,sizeof(cur_user));
			if(cur_user.wrklog_p==0)
				show_sign&=0xfe;
			if(cur_user.jifang_item==0)
				show_sign&=0xfd;
			if(cur_user.guzhang==0)
				show_sign&=0xfb;
			if(cur_user.rep_log==0)
				show_sign&=0xf7;
			if(cur_user.ruku==0)
				show_sign&=0xef;
			memcpy((void*)&cur_user,(void*)&usr,sizeof(usr));//���ò����浱ǰ��¼�û���Ϣ
			g_user.RemoveAll();/////
			CDialog::OnOK();
			return;
		}
	}
	g_user.RemoveAll();
	memset((void*)&cur_user,0,sizeof(cur_user));//�ڱ���ʱҪ���ýṹ��ȷ�������û����ܽ���д�������
	if(sn!="user" || sp!="user")
	{
		if(sn=="aaa" && sp=="aaa")
		{
			show_sign&=0xdf;
			show_sign&=0xbf;
			CDialog::OnOK();
		}
		else
		{
			if(sn=="bbb" && sp=="bbb")
			{
				show_sign&=0xfe;
				show_sign&=0xfd;
				show_sign&=0xfb;
				show_sign&=0xf7;
				show_sign&=0xef;
				CDialog::OnOK();
			}
			else
				CDialog::OnCancel();
		}
	}
	else
		CDialog::OnOK();
};
afx_msg void ldlg::OnCancel()
{
	CDialog::OnCancel();
};
int ldlg::read_db()
{
	int i,j;
	taguser u;
	tagguzhang g;
	tagruku		ruku;
	HMODULE mod=::LoadLibraryA("saikedll.dll");
	if(mod==NULL)
	{
		MessageBox("���ض�̬���ӿ�ʧ�ܣ�");
		return 1;
	}
	cuser=(CArray<_TAGUSER,_TAGUSER&> *)::GetProcAddress(mod,"cuser");
	if(cuser==NULL)
	{
		MessageBox("ȡ�ú�����ַʧ��:cuser");
		::FreeLibrary(mod);
		return 1;
	}
	rd_nor=(READ_USER)::GetProcAddress(mod,"read_user");
	if(rd_nor==NULL)
	{
		MessageBox("ȡ�ú�����ַʧ��:read_user");
		::FreeLibrary(mod);
		return 1;
	}
	CString str;
	char ch[256];
	memset(ch,0,sizeof(ch));
	str.Format("SELECT * FROM user");
	memcpy(ch,str.GetBuffer(0),str.GetLength());
	if(rd_nor((void*)ch)!=0)
	{
		::FreeLibrary(mod);
		return 1;
	}
	i=cuser->GetCount();
	g_user.RemoveAll();
	for(j=0;j<i;j++)
	{
		memset((void*)&u,0,sizeof(u));
		u=cuser->GetAt(j);
		g_user.Add(u);
	}//��ȡ�û���Ϣ��������ɡ���ʼ��ȡ������Ϣ
	cgz=(CArray<_TAGGUZHANG,_TAGGUZHANG&> *)::GetProcAddress(mod,"cgz");
	if(cgz==NULL)
	{
		MessageBox("ȡ�ú�����ַʧ��:cgz");
		::FreeLibrary(mod);
		return 1;
	}
	rd_nor=(READ_USER)::GetProcAddress(mod,"read_gz");
	if(rd_nor==NULL)
	{
		MessageBox("ȡ�ú�����ַʧ��:read_gz");
		::FreeLibrary(mod);
		return 1;
	}
	memset(ch,0,sizeof(ch));
	str.Format("SELECT * FROM guzhang");
	memcpy(ch,str.GetBuffer(0),str.GetLength());
	if(rd_nor((void*)ch)!=0)
	{
		::FreeLibrary(mod);
		return 1;
	}
	i=cgz->GetCount();
	for(j=0;j<i;j++)
	{
		memset((void*)&g,0,sizeof(g));
		g=cgz->GetAt(j);
		g_gz.Add(g);
	}//��ȡ��������ϼ�¼��Ϣ��ɣ���ʼ��ȡ����¼��Ϣ��
	cruku=(CArray<_TAGRUKU,_TAGRUKU&> *)::GetProcAddress(mod,"cruku");
	if(cruku==NULL)
	{
		MessageBox("ȡ�ú�����ַʧ��:cruku");
		::FreeLibrary(mod);
		return 1;
	}
	rd_nor=(READ_USER)::GetProcAddress(mod,"read_ruku");
	if(rd_nor==NULL)
	{
		MessageBox("ȡ�ú�����ַʧ��:read_ruku");
		::FreeLibrary(mod);
		return 1;
	}
	memset(ch,0,sizeof(ch));
	str.Format("SELECT * FROM ruku");
	memcpy(ch,str.GetBuffer(0),str.GetLength());
	if(rd_nor((void*)&ch)!=0)
	{
		::FreeLibrary(mod);
		return 1;
	}
	i=cruku->GetCount();
	for(j=0;j<i;j++)
	{
		memset((void*)&ruku,0,sizeof(ruku));
		ruku=cruku->GetAt(j);
		g_ruku.Add(ruku);
	}//��ȡ�����������Ϣ���	
	::FreeLibrary(mod);
	return 0;
};



















