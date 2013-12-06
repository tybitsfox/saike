#include"saike01.h"

//定义内部使用的建立access访问关键字的函数
int	crt_conn(CString &str)
{
	char ch[1024];
	int i,j,k;
	CString s1,st,s;
	DWORD len=1024;
	memset(ch,0,sizeof(ch));
	::GetModuleFileName(NULL,ch,len);
	st.Format("%s",ch);
	i=st.ReverseFind('\\');
	s1=st.Left(i+1);
	str="ODBC;Driver={Microsoft Access Driver (*.mdb)};DSN='''';Dbq=";
	str+=s1;str+=dbfile;
	s1+=sysfile;
	st.Format(";SystemDB=%s;UID=guoli; pwd=saike1234",s1);
	str+=st;
	return 0;
};

//定义日志记录的保存函数
_declspec(dllexport) int WINAPI save_wrklg(void *res)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wtb=0;
	tagwrklog *t=(tagwrklog *)res;
	if(t==NULL)
		return 1;//error
	CString str;
	crt_conn(str);
	CDatabase db;
	if(db.IsOpen())
		db.Close();
	try
	{db.Open(NULL,false,false,str);}
	catch(CDBException *ep)
	{
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	myrecord mrd(&db);
	if(mrd.IsOpen())
		mrd.Close();
	try
	{ mrd.Open(AFX_DB_USE_DEFAULT_TYPE,"SELECT * FROM wrklog");}
	catch(CDBException *ep)
	{
		db.Close();
		MessageBox(NULL,ep->m_strError,"FROM dll",0);
		return 1;
	}
	mrd.AddNew();
	memset((void*)&(mrd.wlg),0,sizeof(mrd.wlg));
	memcpy((void*)&(mrd.wlg),res,sizeof(tagwrklog));
	mrd.Update();
	mrd.Close();
	db.Close();
	return 0;
};
//定义设备台账的保存函数
_declspec(dllexport) int WINAPI save_mchlg(void *res)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wtb=1;
	if(res==NULL)
		return 1;
	CString str;
	crt_conn(str);
	CDatabase db;
	if(db.IsOpen())
		db.Close();
	try
	{db.Open(NULL,false,false,str);}
	catch(CDBException *ep)
	{
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	myrecord mrd(&db);
	if(mrd.IsOpen())
		mrd.Close();
	try
	{mrd.Open(AFX_DB_USE_DEFAULT_TYPE,"SELECT * FROM mch_log");}
	catch(CDBException *ep)
	{
		MessageBox(NULL,ep->m_strError,"from dll",0);
		db.Close();
		return 1;
	}
	mrd.AddNew();
	memset((void*)&(mrd.mlg),0,sizeof(tagwrklog));
	memcpy((void*)&(mrd.mlg),res,sizeof(tagwrklog));
	mrd.Update();
	mrd.Close();
	db.Close();
	return 0;
};
//定义故障记录的保存函数
_declspec(dllexport) int WINAPI save_gz(void *res)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wtb=2;
	if(res==NULL)
		return 1;
	CString str;
	crt_conn(str);
	CDatabase db;
	if(db.IsOpen())
		db.Close();
	try
	{db.Open(NULL,false,false,str);}
	catch(CDBException *ep)
	{
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	myrecord mrd(&db);
	if(mrd.IsOpen())
		mrd.Close();
	try
	{mrd.Open(AFX_DB_USE_DEFAULT_TYPE,"SELECT * FROM guzhang");}
	catch(CDBException *ep)
	{
		db.Close();
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	mrd.AddNew();
	memset((void*)&(mrd.gz),0,sizeof(mrd.gz));
	memcpy((void*)&(mrd.gz),res,sizeof(tagguzhang));
	mrd.Update();
	mrd.Close();
	db.Close();
	return 0;
};
//定义维修记录的保存函数
_declspec(dllexport) int WINAPI save_weixiu(void *res)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wtb=3;
	CString str;
	crt_conn(str);
	CDatabase db;
	if(db.IsOpen())
		db.Close();
	try
	{db.Open(NULL,false,false,str);}
	catch(CDBException *ep)
	{
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	myrecord mrd(&db);
	if(mrd.IsOpen())
		mrd.Close();
	try
	{mrd.Open(AFX_DB_USE_DEFAULT_TYPE,"SELECT * FROM rep_log");}
	catch(CDBException *ep)
	{
		db.Close();
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	mrd.AddNew();
	memset((void*)&(mrd.rep),0,sizeof(mrd.rep));
	memcpy((void*)&(mrd.rep),res,sizeof(mrd.rep));
	mrd.Update();
	mrd.Close();
	db.Close();
	return 0;
};
//定义入库记录的保存函数
_declspec(dllexport) int WINAPI save_ruku(void *res)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wtb=4;
	if(res==NULL)
		return 1;
	CString str;
	crt_conn(str);
	CDatabase db;
	if(db.IsOpen())
		db.Close();
	try
	{db.Open(NULL,false,false,str);}
	catch(CDBException *ep)
	{
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	myrecord mrd(&db);
	if(mrd.IsOpen())
		mrd.Close();
	try
	{mrd.Open(AFX_DB_USE_DEFAULT_TYPE,"SELECT * FROM ruku");}
	catch(CDBException *ep)
	{
		db.Close();
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	mrd.AddNew();
	memset((void*)&(mrd.ruku),0,sizeof(mrd.ruku));
	memcpy((void*)&(mrd.ruku),res,sizeof(mrd.ruku));
	mrd.Update();
	mrd.Close();
	db.Close();
	return 0;
};
//定义用户记录的保存函数
_declspec(dllexport) int WINAPI save_user(void *res)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wtb=5;
	if(res==NULL)
		return 1;
	CString str;
	crt_conn(str);
	CDatabase db;
	if(db.IsOpen())
		db.Close();
	try
	{db.Open(NULL,false,false,str);}
	catch(CDBException *ep)
	{
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	myrecord mrd(&db);
	if(mrd.IsOpen())
		mrd.Close();
	try
	{mrd.Open(AFX_DB_USE_DEFAULT_TYPE,"SELECT * FROM user");}
	catch(CDBException *ep)
	{
		db.Close();
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	mrd.AddNew();
	memset((void*)&(mrd.usr),0,sizeof(mrd.usr));
	memcpy((void*)&(mrd.usr),res,sizeof(mrd.usr));
	mrd.Update();
	mrd.Close();
	db.Close();
	return 0;
};
//定义系统表的读取函数
_declspec(dllexport) int WINAPI read_sys(void *result)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wtb=6;
	if(result==NULL)
		return 1;
	memset(result,0,sizeof(tagbase));
	CString str;
	crt_conn(str);
	CDatabase db;
	if(db.IsOpen())
		db.Close();
	try
	{db.Open(NULL,false,false,str);}
	catch(CDBException *ep)
	{
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	myrecord mrd(&db);
	if(mrd.IsOpen())
		mrd.Close();
	try
	{mrd.Open(AFX_DB_USE_DEFAULT_TYPE,"SELECT * FROM basemsg");}
	catch(CDBException *ep)
	{
		db.Close();
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	/*while(!mrd.IsBOF())
	{
		mrd.MovePrev();
	}*///mrd.MoveFirst();
	mrd.MoveFirst();//only one result!
	memcpy(result,(void*)&(mrd.bas),sizeof(mrd.bas));
	mrd.Close();
	db.Close();
	return 0;
};
//定义系统表的更新函数
/*
入口参数result必须包含待更新的数据
*/
_declspec(dllexport) int WINAPI update_sys(void *result)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wtb=6;
	if(result==NULL)
		return 1;
	CString str;
	crt_conn(str);
	CDatabase db;
	if(db.IsOpen())
		db.Close();
	try
	{db.Open(NULL,false,false,str);}
	catch(CDBException *ep)
	{
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	myrecord mrd(&db);
	if(mrd.IsOpen())
		mrd.Close();
	try
	{mrd.Open(AFX_DB_USE_DEFAULT_TYPE,"SELECT * FROM basemsg");}
	catch(CDBException *ep)
	{
		db.Close();
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	if(mrd.IsEOF())
	{
		mrd.Close();
		db.Close();
		MessageBox(NULL,"no result","from dll",0);
		return 1;
	}
	mrd.MoveFirst();
	mrd.Edit();
	memset((void*)&(mrd.bas),0,sizeof(mrd.bas));
	memcpy((void*)&(mrd.bas),result,sizeof(mrd.bas));
	mrd.Update();
	mrd.Close();
	db.Close();
	return 0;
};
//读取工作记录函数
/*
参数con:为传入的查询条件字符串，
参数pt:为返回符合查询条件的记录队列，该队列指针为前面定义的cwrklg
*/
_declspec(dllexport) int WINAPI read_wrklg(void *con)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wtb=0;
	_TAGWRKLOG tg;
	CString str,s1;
	crt_conn(str);
	s1.Format("%s",(char*)con);
	if(s1.IsEmpty())
		return 1;
	clean_ary(0);
	CDatabase db;
	if(db.IsOpen())
		db.Close();
	try
	{db.Open(NULL,false,false,str);}
	catch(CDBException *ep)
	{
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	myrecord mrd(&db);
	if(mrd.IsOpen())
		mrd.Close();
	try
	{mrd.Open(AFX_DB_USE_DEFAULT_TYPE,s1);}
	catch(CDBException *ep)
	{
		db.Close();
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
/*	if(mrd.IsEOF())
	{
		MessageBox(NULL,"no record","from dll",0);
		mrd.Close();
		db.Close();
		return 1;
	}*/
	mrd.MoveFirst();
	while(!mrd.IsEOF())
	{
		memset((void*)&tg,0,sizeof(tg));
		memcpy((void*)&tg,(void*)&(mrd.wlg),sizeof(mrd.wlg));
		cwrklg.Add(tg);
		mrd.MoveNext();
	}
	mrd.Close();
	db.Close();
	return 0;
};
//队列的清理函数
//参数w指明队列序号
_declspec(dllexport) void WINAPI clean_ary(int w)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	switch(w)
	{
	case 0://wrklog
		cwrklg.RemoveAll();
		break;
	case 1://
		cmchlg.RemoveAll();
		break;
	case 2://
		cgz.RemoveAll();
		break;
	case 3://
		cweixiu.RemoveAll();
		break;
	case 4://
		cruku.RemoveAll();
		break;
	case 5://
		cuser.RemoveAll();
		break;
	};
};
//读取设备台账记录的函数，参数同上
_declspec(dllexport) int WINAPI read_mcglg(void *con)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wtb=1;
	if(con==NULL)
		return 1;
	_TAGMCHLOG tmc;
	CString str,s1;
	crt_conn(str);
	s1.Format("%s",(char*)con);
	clean_ary(wtb);
	CDatabase db;
	if(db.IsOpen())
		db.Close();
	try
	{db.Open(NULL,false,false,str);}
	catch(CDBException *ep)
	{
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	myrecord mrd(&db);
	if(mrd.IsOpen())
		mrd.Close();
	try
	{mrd.Open(AFX_DB_USE_DEFAULT_TYPE,s1);}
	catch(CDBException *ep)
	{
		db.Close();
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	mrd.MoveFirst();
	while(!mrd.IsEOF())
	{
		memset((void*)&tmc,0,sizeof(tmc));
		memcpy((void*)&tmc,(void*)&(mrd.mlg),sizeof(tmc));
		cmchlg.Add(tmc);
		mrd.MoveNext();
	}
	mrd.Close();
	db.Close();
	return 0;
};
//读取故障记录的函数，参数同上
_declspec(dllexport) int WINAPI read_gz(void *con)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wtb=2;
	_TAGGUZHANG gz;
	CString str,s1;
	if(con==NULL)
		return 1;
	crt_conn(str);
	s1.Format("%s",(char*)con);
	clean_ary(wtb);
	CDatabase db;
	if(db.IsOpen())
		db.Close();
	try
	{db.Open(NULL,false,false,str);}
	catch(CDBException *ep)
	{
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	myrecord mrd(&db);
	if(mrd.IsOpen())
		mrd.Close();
	try
	{mrd.Open(AFX_DB_USE_DEFAULT_TYPE,s1);}
	catch(CDBException *ep)
	{
		db.Close();
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	mrd.MoveFirst();
	while(!mrd.IsEOF())
	{
		memset((void*)&gz,0,sizeof(gz));
		memcpy((void*)&gz,(void*)&(mrd.gz),sizeof(gz));
		cgz.Add(gz);
		mrd.MoveNext();
	}
	mrd.Close();
	db.Close();
	return 0;
};
//读取维修记录的函数，参数同上
_declspec(dllexport) int WINAPI read_weixiu(void *con)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wtb=3;
	CString str,s1;
//	_TAGREPAIR  rep;
	if(con==NULL)
		return 1;
	crt_conn(str);
	s1.Format("%s",(char*)con);
	clean_ary(wtb);
	CDatabase db;
	if(db.IsOpen())
		db.Close();
	try
	{db.Open(NULL,false,false,str);}
	catch(CDBException *ep)
	{
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	myrecord mrd(&db);
	if(mrd.IsOpen())
		mrd.Close();
	try
	{mrd.Open(AFX_DB_USE_DEFAULT_TYPE,s1);}
	catch(CDBException *ep)
	{
		db.Close();
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	mrd.MoveFirst();
	while(!mrd.IsEOF())
	{
		cweixiu.Add(mrd.rep);
		mrd.MoveNext();
	}
	mrd.Close();
	db.Close();
	return 0;
};
//读取入库记录的函数，参数同上
_declspec(dllexport) int WINAPI read_ruku(void *con)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wtb=4;
	_TAGRUKU ruku;
	CString str,s1;
	if(con==NULL)
		return 1;
	clean_ary(wtb);
	crt_conn(str);
	s1.Format("%s",(char*)con);
	CDatabase db;
	if(db.IsOpen())
		db.Close();
	try
	{db.Open(NULL,false,false,str);}
	catch(CDBException *ep)
	{
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	myrecord mrd(&db);
	if(mrd.IsOpen())
		mrd.Close();
	try
	{mrd.Open(AFX_DB_USE_DEFAULT_TYPE,s1);}
	catch(CDBException *ep)
	{
		db.Close();
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	mrd.MoveFirst();
	while(!mrd.IsEOF())
	{
		memset((void*)&ruku,0,sizeof(ruku));
		memcpy((void*)&ruku,(void*)&(mrd.ruku),sizeof(ruku));
		cruku.Add(ruku);
		mrd.MoveNext();
	}
	mrd.Close();
	db.Close();
	return 0;
};
//读取用户记录的函数，参数同上
_declspec(dllexport) int WINAPI read_user(void *con)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	wtb=5;
	CString str,s1;
	_TAGUSER usr;
	clean_ary(wtb);
	if(con==NULL)
		return 1;
	crt_conn(str);
	s1.Format("%s",(char*)con);
	CDatabase db;
	if(db.IsOpen())
		db.Close();
	try
	{db.Open(NULL,false,false,str);}
	catch(CDBException *ep)
	{
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	myrecord mrd(&db);
	if(mrd.IsOpen())
		mrd.Close();
	try
	{mrd.Open(AFX_DB_USE_DEFAULT_TYPE,s1);}
	catch(CDBException *ep)
	{
		db.Close();
		MessageBox(NULL,ep->m_strError,"from dll",0);
		return 1;
	}
	mrd.MoveFirst();
	while(!mrd.IsEOF())
	{
		memset((void*)&usr,0,sizeof(usr));
		memcpy((void*)&usr,(void*)&(mrd.usr),sizeof(usr));
		cuser.Add(usr);
		mrd.MoveNext();
	}
	mrd.Close();
	db.Close();
	return 0;
};







































