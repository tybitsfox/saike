#include"stdafx.h"
#include"myrecord.h"
extern int wtb;

myrecord::myrecord(CDatabase *db):CRecordset(db)
{
	switch(wtb)
	{
	case 0://_TAGWRKLOG   工作日志表
		memset((void*)&wlg,0,sizeof(wlg));
		m_nFields=21;
		break;
	case 1://_TAGMCHLOG  设备台账
		memset((void*)&mlg,0,sizeof(mlg));
		m_nFields=12;
		break;
	case 2://_TAGGUZHANG 故障记录
		memset((void*)&gz,0,sizeof(gz));
		m_nFields=12;
		break;
	case 3://_TAGREPAIR  维修记录
		memset((void*)&rep,0,sizeof(rep));
		m_nFields=16;
		break;
	case 4://_TAGRUKU  入库记录
		memset((void*)&ruku,0,sizeof(ruku));
		m_nFields=14;
		break;
	case 5://_TAGUSER 用户表
		memset((void*)&usr,0,sizeof(usr));
		m_nFields=17;
		break;
	case 6://_TAGBASE 系统表
		memset((void*)&bas,0,sizeof(bas));
		m_nFields=9;
		break;
	};
	m_nDefaultType=snapshot;
}
CString myrecord::GetDefaultSQL()
{
	switch(wtb)
	{
	case 0://表1
		return _T("wrklog");
	case 1://_TAGMCHLOG  设备台账
		return _T("mch_log");
	case 2://_TAGGUZHANG 故障记录
		return _T("guzhang");
	case 3://_TAGREPAIR  维修记录
		return _T("rep_log");
	case 4://_TAGRUKU  入库记录
		return _T("ruku");
	case 5://_TAGUSER 用户表
		return _T("user");
	case 6://_TAGBASE 系统表
		return _T("basemsg");
	};
	return _T("error");
};
void myrecord::DoFieldExchange(CFieldExchange *pfx)
{
	pfx->SetFieldType(CFieldExchange::outputColumn);
	CString str;
	switch(wtb)
	{
	case 0://表1  工作记录
		RFX_Date(pfx,"u_date",wlg.u_date);
		RFX_Int(pfx,"dianya",wlg.dianya);
		RFX_Int(pfx,"shidu",wlg.shidu);
		RFX_Text(pfx,"qihou",wlg.qihou,dlen_m);
		RFX_Int(pfx,"up_temp",wlg.uptemp);
		RFX_Int(pfx,"lo_temp",wlg.lotemp);
		RFX_Text(pfx,"weixiu1",wlg.weixiu1,dlen_s);
		RFX_Text(pfx,"weixiu2",wlg.weixiu2,dlen_s);
		RFX_Text(pfx,"weixiu3",wlg.weixiu3,dlen_s);
		RFX_Text(pfx,"tiaopei1",wlg.tiaopei1,dlen_s);
		RFX_Text(pfx,"tiaopei2",wlg.tiaopei2,dlen_s);
		RFX_Text(pfx,"tiaopei3",wlg.tiaopei3,dlen_s);
		RFX_Text(pfx,"changjia1",wlg.changjia1,dlen_s);
		RFX_Text(pfx,"changjia2",wlg.changjia2,dlen_s);
		RFX_Text(pfx,"wind",wlg.wind,dlen_m);
		RFX_Text(pfx,"wind_dir",wlg.wind_dir,dlen_m);
		RFX_Text(pfx,"event1",wlg.event1,dlen_l);
		RFX_Text(pfx,"event2",wlg.event2,dlen_l);
		RFX_Text(pfx,"event3",wlg.event3,dlen_l);
		RFX_Text(pfx,"event4",wlg.event4,dlen_l);
		RFX_Byte(pfx,"merge",wlg.merge);
		break;
	case 1://表2  设备台账
		RFX_Date(pfx,"c_date",mlg.c_date);
		RFX_Text(pfx,"jk_id",mlg.jk_id,dlen_s);
		RFX_Text(pfx,"posi",mlg.posi,dlen_m);
		RFX_Text(pfx,"route",mlg.route,dlen_s);
		RFX_Text(pfx,"signal",mlg.signal,dlen_s);
		RFX_Text(pfx,"mch_type",mlg.mch_type,dlen_s);
		RFX_Text(pfx,"mch_name",mlg.mch_name,dlen_s);
		RFX_Text(pfx,"ip",mlg.ip,dlen_s);
		RFX_Text(pfx,"xinghao",mlg.xinghao,dlen_s);
		RFX_Int(pfx,"counts",mlg.counts);
		RFX_Text(pfx,"beizhu",mlg.beizhu,dlen_m);
		RFX_Byte(pfx,"merge",mlg.merge);
		break;
	case 2://表3  故障记录
		RFX_Date(pfx,"sendtime",gz.sendtime);
		RFX_Text(pfx,"fangshi",gz.fangshi,dlen_s);
		RFX_Text(pfx,"baoxiu",gz.baoxiu,dlen_s);
		RFX_Text(pfx,"mch_name",gz.mch_name,dlen_s);
		RFX_Text(pfx,"posi",gz.posi,dlen_m);
		RFX_Text(pfx,"baoxiu_con",gz.baoxiu_con,dlen_m);
		RFX_Text(pfx,"mch_type",gz.mch_type,dlen_s);
		RFX_Text(pfx,"level",gz.level,dlen_es);
		RFX_Text(pfx,"desc",gz.desc,dlen_el);
		RFX_Int(pfx,"id",gz.id);
		RFX_Int(pfx,"user_id",gz.user_id);
		RFX_Byte(pfx,"merge",gz.merge);
		break;
	case 3://表4  维修记录
		RFX_Int(pfx,"id",rep.id);
		RFX_Date(pfx,"in_date",rep.in_date);
		RFX_Text(pfx,"weixiu",rep.weixiu,dlen_s);
		RFX_Text(pfx,"used1",rep.used1,dlen_s);
		RFX_Text(pfx,"used2",rep.used2,dlen_s);
		RFX_Text(pfx,"used3",rep.used3,dlen_s);
		RFX_Text(pfx,"used4",rep.used4,dlen_s);
		RFX_Text(pfx,"wait",rep.wait,dlen_s);
		RFX_Int(pfx,"times",rep.times);
		RFX_Date(pfx,"fin_date",rep.fin_date);
		RFX_Text(pfx,"tiaopei1",rep.tiaopei1,dlen_s);
		RFX_Text(pfx,"tiaopei2",rep.tiaopei2,dlen_s);
		RFX_Text(pfx,"changjia1",rep.changjia1,dlen_s);
		RFX_Text(pfx,"changjia2",rep.changjia2,dlen_s);
		RFX_Text(pfx,"method",rep.method,dlen_l);
		RFX_Byte(pfx,"merge",rep.merge);
		break;
	case 4://表5  入库记录
		RFX_Date(pfx,"in_date",ruku.in_date);
		RFX_Text(pfx,"name",ruku.name,dlen_s);
		RFX_Text(pfx,"caigou",ruku.caigou,dlen_s);
		RFX_Text(pfx,"pinpai",ruku.pinpai,dlen_s);
		RFX_Text(pfx,"xinghao",ruku.xinghao,dlen_s);
		RFX_Text(pfx,"guige",ruku.guige,dlen_s);
		RFX_Int(pfx,"counts",ruku.counts);
		RFX_Text(pfx,"in_type",ruku.in_type,dlen_s);
		RFX_Text(pfx,"didian",ruku.didian,dlen_m);
		RFX_Text(pfx,"gongying",ruku.gongying,dlen_m);
		RFX_Text(pfx,"conn",ruku.conn,dlen_m);
		RFX_Text(pfx,"ruku",ruku.ruku,dlen_s);
		RFX_Text(pfx,"belong",ruku.belong,dlen_m);
		RFX_Byte(pfx,"merge",ruku.merge);
		break;
	case 5://表6   用户表
		RFX_Int(pfx,"user_id",usr.user_id);
		RFX_Text(pfx,"uname",usr.uname,dlen_s);
		RFX_Text(pfx,"pwd",usr.pwd,dlen_s);
		RFX_Text(pfx,"sexy",usr.sexy,dlen_es);
		RFX_Text(pfx,"phone",usr.phone,dlen_s);
		RFX_Text(pfx,"addr",usr.addr,dlen_m);
		RFX_Text(pfx,"email",usr.email,dlen_s);
		RFX_Text(pfx,"danwei",usr.danwei,dlen_s);
		RFX_Text(pfx,"bumen",usr.bumen,dlen_s);
		RFX_Text(pfx,"zhiwu",usr.zhiwu,dlen_es);
		RFX_Int(pfx,"level",usr.level);
		RFX_Int(pfx,"wrklog_p",usr.wrklog_p);
		RFX_Int(pfx,"guzhang",usr.guzhang);
		RFX_Int(pfx,"jifang_item",usr.jifang_item);
		RFX_Int(pfx,"ruku",usr.ruku);
		RFX_Int(pfx,"rep_log",usr.rep_log);
		RFX_Int(pfx,"user_p",usr.user_p);
		break;
	case 6://表7   系统表
		RFX_Text(pfx,"name",bas.name,dlen_m);
		RFX_Byte(pfx,"db_type",bas.db_type);
		RFX_Int(pfx,"gz_id",bas.gz_id);
		RFX_Text(pfx,"cur_user",bas.cur_user,dlen_s);
		RFX_Int(pfx,"user_id",bas.user_id);
		RFX_Text(pfx,"def_user",bas.def_user,dlen_s);
		RFX_Int(pfx,"du_id",bas.du_id);
		RFX_Text(pfx,"auth_pwd",bas.auth_pwd,dlen_s);
		RFX_Int(pfx,"auth_times",bas.auth_times);
		break;
	};
};























