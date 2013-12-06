#define DB_DATA_STRUC

#ifndef	BYTE
#define	BYTE					unsigned char
#endif

//与数据库结构字段长度相应的定义
#define dlen_m					50
#define dlen_s					20
#define dlen_l					100
#define dlen_es					10
#define	dlen_el					200



//工作日志对应的数据结构：
typedef struct  _TAGWRKLOG
{
	CTime	u_date;						//工作日期
	int		dianya;						//机房电压
	int		shidu;						//湿度
	char	qihou[dlen_m];				//气候
	int		uptemp;						//up_temp 环境温度-高
	int		lotemp;						//lo_temp 环境温度-低
	char	weixiu1[dlen_s];			//维修人员1
	char	weixiu2[dlen_s];			//维修人员2
	char	weixiu3[dlen_s];			//维修人员3
	char	tiaopei1[dlen_s];			//调配人员1
	char	tiaopei2[dlen_s];			//调配人员2
	char	tiaopei3[dlen_s];			//调配人员3
	char	changjia1[dlen_s];			//厂家人员1
	char	changjia2[dlen_s];			//厂家人员2
	char	wind[dlen_m];				//风力
	char	wind_dir[dlen_m];			//风向
	char	event1[dlen_l];				//特殊事件1
	char	event2[dlen_l];				//特殊事件2
	char	event3[dlen_l];				//特殊事件3
	char	event4[dlen_l];				//特殊事件4
	BYTE	merge;						//合并标志
}tagwrklog;
//设备台账对应的数据结构：
typedef struct _TAGMCHLOG
{
	CTime	c_date;						//清查日期
	char	jk_id[dlen_s];				//监控点标示
	char	posi[dlen_m];				//地理位置
	char	route[dlen_s];				//供电路由及方式
	char	signal[dlen_s];				//信号传输路由及方式
	char	mch_type[dlen_s];			//设备类型
	char	mch_name[dlen_s];			//设备名称
	char	ip[dlen_s];					//ip
	char	xinghao[dlen_s];			//型号
	int		counts;						//数量
	char	beizhu[dlen_m];				//备注
	BYTE	merge;						//合并标志
}tagmchlog;
//故障记录对应的数据结构：
typedef struct _TAGGUZHANG
{
	CTime	sendtime;					//发送时间
	char	fangshi[dlen_s];			//发现方式
	char	baoxiu[dlen_s];				//保修人/发现人
	char	mch_name[dlen_s];			//设备名称
	char	posi[dlen_m];				//地理位置
	char	baoxiu_con[dlen_m];			//保修人联系方式
	char	mch_type[dlen_s];			//设备类别
	char	level[dlen_es];				//处理优先级，用户暂时不用
	char	desc[dlen_el];				//故障描述
	int		id;							//故障id，配合操作者id确定具体点位的故障
	int		user_id;					//操作者id,如是被授权用户操作，该处反映的为授权用户的id
	BYTE	merge;						//合并标志
}tagguzhang;
//维修记录对应的数据结构:
typedef struct _TAGREPAIR
{
	int id;								//故障id
	CTime in_date;						//开始处理时间
	char weixiu[dlen_s];				//维修人员
	char used1[dlen_s];					//使用备件1
	char used2[dlen_s];					//使用备件2
	char used3[dlen_s];					//使用备件3
	char used4[dlen_s];					//使用备件4
	char wait[dlen_s];					//等待时间
	int	 times;							//维修次数
	CTime fin_date;						//恢复时间
	char tiaopei1[dlen_s];				//调配人员1
	char tiaopei2[dlen_s];				//调配人员2
	char changjia1[dlen_s];				//厂家人员1
	char changjia2[dlen_s];				//厂家人员2
	char method[dlen_l];				//处理方法
	BYTE merge;							//合并标志
}tagrepair;
//入库记录对应的数据结构
typedef struct _TAGRUKU
{
	CTime	in_date;					//入库时间
	char	name[dlen_s];				//设备名称
	char	caigou[dlen_s];				//采购人员
	char	pinpai[dlen_s];				//品牌
	char	xinghao[dlen_s];			//型号
	char	guige[dlen_s];				//规格
	int		counts;						//数量
	char	in_type[dlen_s];			//所属分类
	char	didian[dlen_m];				//采购地点
	char	gongying[dlen_m];			//供应商
	char	conn[dlen_m];				//供货联系方式
	char	ruku[dlen_s];				//入库人员
	char	belong[dlen_m];				//备品所有权
	BYTE	merge;						//合并标志
}tagruku;



//用户表对应的数据结构：
typedef struct _TAGUSER
{
	int		user_id;					//用户id
	char	uname[dlen_s];				//用户名
	char	pwd[dlen_s];				//密码
	char	sexy[dlen_es];				//性别
	char	phone[dlen_s];				//手机
	char	addr[dlen_m];				//住址
	char	email[dlen_s];				//email
	char	danwei[dlen_s];				//单位
	char	bumen[dlen_s];				//部门
	char	zhiwu[dlen_es];				//职务
	int		level;						//权限级别 -用户要求取消，暂时保存
	int		wrklog_p;					//工作日志表访问所需权限 0：无访问权限，1：读权限，2：写权限，3：读写权限
	int		guzhang;					//同上
	int		jifang_item;				//同上
	int		ruku;						//同上
	int		rep_log;					//同上
}taguser;
//基本信息表，可作为系统表使用，由系统根据需要访问，用户无法直接操作该表
typedef struct _TAGBASE
{
	char	name[dlen_m];				//单位名称
	BYTE	db_type;					//数据库类型 0：主数据库  1：子数据库
	int		gz_id;						//故障可用id
	char	cur_user[dlen_s];			//当前操作用户
	int		user_id;					//当前用户id
	char	def_user[dlen_s];			//默认用户
	int		du_id;						//默认用户的id
	char	auth_pwd[dlen_s];			//授权密码
	int		auth_times;					//授权次数
}tagbase;




























