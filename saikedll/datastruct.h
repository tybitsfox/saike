#define DB_DATA_STRUC

#ifndef	BYTE
#define	BYTE					unsigned char
#endif

//�����ݿ�ṹ�ֶγ�����Ӧ�Ķ���
#define dlen_m					50
#define dlen_s					20
#define dlen_l					100
#define dlen_es					10
#define	dlen_el					200



//������־��Ӧ�����ݽṹ��
typedef struct  _TAGWRKLOG
{
	CTime	u_date;						//��������
	int		dianya;						//������ѹ
	int		shidu;						//ʪ��
	char	qihou[dlen_m];				//����
	int		uptemp;						//up_temp �����¶�-��
	int		lotemp;						//lo_temp �����¶�-��
	char	weixiu1[dlen_s];			//ά����Ա1
	char	weixiu2[dlen_s];			//ά����Ա2
	char	weixiu3[dlen_s];			//ά����Ա3
	char	tiaopei1[dlen_s];			//������Ա1
	char	tiaopei2[dlen_s];			//������Ա2
	char	tiaopei3[dlen_s];			//������Ա3
	char	changjia1[dlen_s];			//������Ա1
	char	changjia2[dlen_s];			//������Ա2
	char	wind[dlen_m];				//����
	char	wind_dir[dlen_m];			//����
	char	event1[dlen_l];				//�����¼�1
	char	event2[dlen_l];				//�����¼�2
	char	event3[dlen_l];				//�����¼�3
	char	event4[dlen_l];				//�����¼�4
	BYTE	merge;						//�ϲ���־
}tagwrklog;
//�豸̨�˶�Ӧ�����ݽṹ��
typedef struct _TAGMCHLOG
{
	CTime	c_date;						//�������
	char	jk_id[dlen_s];				//��ص��ʾ
	char	posi[dlen_m];				//����λ��
	char	route[dlen_s];				//����·�ɼ���ʽ
	char	signal[dlen_s];				//�źŴ���·�ɼ���ʽ
	char	mch_type[dlen_s];			//�豸����
	char	mch_name[dlen_s];			//�豸����
	char	ip[dlen_s];					//ip
	char	xinghao[dlen_s];			//�ͺ�
	int		counts;						//����
	char	beizhu[dlen_m];				//��ע
	BYTE	merge;						//�ϲ���־
}tagmchlog;
//���ϼ�¼��Ӧ�����ݽṹ��
typedef struct _TAGGUZHANG
{
	CTime	sendtime;					//����ʱ��
	char	fangshi[dlen_s];			//���ַ�ʽ
	char	baoxiu[dlen_s];				//������/������
	char	mch_name[dlen_s];			//�豸����
	char	posi[dlen_m];				//����λ��
	char	baoxiu_con[dlen_m];			//��������ϵ��ʽ
	char	mch_type[dlen_s];			//�豸���
	char	level[dlen_es];				//�������ȼ����û���ʱ����
	char	desc[dlen_el];				//��������
	int		id;							//����id����ϲ�����idȷ�������λ�Ĺ���
	int		user_id;					//������id,���Ǳ���Ȩ�û��������ô���ӳ��Ϊ��Ȩ�û���id
	BYTE	merge;						//�ϲ���־
}tagguzhang;
//ά�޼�¼��Ӧ�����ݽṹ:
typedef struct _TAGREPAIR
{
	int id;								//����id
	CTime in_date;						//��ʼ����ʱ��
	char weixiu[dlen_s];				//ά����Ա
	char used1[dlen_s];					//ʹ�ñ���1
	char used2[dlen_s];					//ʹ�ñ���2
	char used3[dlen_s];					//ʹ�ñ���3
	char used4[dlen_s];					//ʹ�ñ���4
	char wait[dlen_s];					//�ȴ�ʱ��
	int	 times;							//ά�޴���
	CTime fin_date;						//�ָ�ʱ��
	char tiaopei1[dlen_s];				//������Ա1
	char tiaopei2[dlen_s];				//������Ա2
	char changjia1[dlen_s];				//������Ա1
	char changjia2[dlen_s];				//������Ա2
	char method[dlen_l];				//������
	BYTE merge;							//�ϲ���־
}tagrepair;
//����¼��Ӧ�����ݽṹ
typedef struct _TAGRUKU
{
	CTime	in_date;					//���ʱ��
	char	name[dlen_s];				//�豸����
	char	caigou[dlen_s];				//�ɹ���Ա
	char	pinpai[dlen_s];				//Ʒ��
	char	xinghao[dlen_s];			//�ͺ�
	char	guige[dlen_s];				//���
	int		counts;						//����
	char	in_type[dlen_s];			//��������
	char	didian[dlen_m];				//�ɹ��ص�
	char	gongying[dlen_m];			//��Ӧ��
	char	conn[dlen_m];				//������ϵ��ʽ
	char	ruku[dlen_s];				//�����Ա
	char	belong[dlen_m];				//��Ʒ����Ȩ
	BYTE	merge;						//�ϲ���־
}tagruku;



//�û����Ӧ�����ݽṹ��
typedef struct _TAGUSER
{
	int		user_id;					//�û�id
	char	uname[dlen_s];				//�û���
	char	pwd[dlen_s];				//����
	char	sexy[dlen_es];				//�Ա�
	char	phone[dlen_s];				//�ֻ�
	char	addr[dlen_m];				//סַ
	char	email[dlen_s];				//email
	char	danwei[dlen_s];				//��λ
	char	bumen[dlen_s];				//����
	char	zhiwu[dlen_es];				//ְ��
	int		level;						//Ȩ�޼��� -�û�Ҫ��ȡ������ʱ����
	int		wrklog_p;					//������־���������Ȩ�� 0���޷���Ȩ�ޣ�1����Ȩ�ޣ�2��дȨ�ޣ�3����дȨ��
	int		guzhang;					//ͬ��
	int		jifang_item;				//ͬ��
	int		ruku;						//ͬ��
	int		rep_log;					//ͬ��
}taguser;
//������Ϣ������Ϊϵͳ��ʹ�ã���ϵͳ������Ҫ���ʣ��û��޷�ֱ�Ӳ����ñ�
typedef struct _TAGBASE
{
	char	name[dlen_m];				//��λ����
	BYTE	db_type;					//���ݿ����� 0�������ݿ�  1�������ݿ�
	int		gz_id;						//���Ͽ���id
	char	cur_user[dlen_s];			//��ǰ�����û�
	int		user_id;					//��ǰ�û�id
	char	def_user[dlen_s];			//Ĭ���û�
	int		du_id;						//Ĭ���û���id
	char	auth_pwd[dlen_s];			//��Ȩ����
	int		auth_times;					//��Ȩ����
}tagbase;




























