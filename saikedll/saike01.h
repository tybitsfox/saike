#include"stdafx.h"
#include"myrecord.h"
#define sysfile			"saikedb.udv"
#define dbfile			"Saike_2013_u01.mdb"

int wtb=0;

//���幤����¼����
_declspec(dllexport) CArray<_TAGWRKLOG,_TAGWRKLOG&> cwrklg;
//�����豸̨�˶���
_declspec(dllexport) CArray<_TAGMCHLOG,_TAGMCHLOG&> cmchlg;
//������ϼ�¼����
_declspec(dllexport) CArray<_TAGGUZHANG,_TAGGUZHANG&> cgz;
//����ά�޼�¼����
_declspec(dllexport) CArray<_TAGREPAIR,_TAGREPAIR&>  cweixiu;
//��������¼����
_declspec(dllexport) CArray<_TAGRUKU,_TAGRUKU&> cruku;
//�����û���¼����
_declspec(dllexport) CArray<_TAGUSER,_TAGUSER&> cuser;

//������־��¼�ı��溯��
_declspec(dllexport) int WINAPI save_wrklg(void *res);
//�����豸̨�˵ı��溯��
_declspec(dllexport) int WINAPI save_mchlg(void *res);
//������ϼ�¼�ı��溯��
_declspec(dllexport) int WINAPI save_gz(void *res);
//����ά�޼�¼�ı��溯��
_declspec(dllexport) int WINAPI save_weixiu(void *res);
//��������¼�ı��溯��
_declspec(dllexport) int WINAPI save_ruku(void *res);
//�����û���¼�ı��溯��
_declspec(dllexport) int WINAPI save_user(void *res);
//����ϵͳ��Ķ�ȡ����
_declspec(dllexport) int WINAPI read_sys(void *result);

//����ϵͳ��ĸ��º���
/*
��ڲ���result������������µ�����
*/
_declspec(dllexport) int WINAPI update_sys(void *result);

//��ȡ������¼����
/*
����con:Ϊ����Ĳ�ѯ�����ַ�����
����pt:Ϊ���ط��ϲ�ѯ�����ļ�¼���У��ö���ָ��Ϊǰ�涨���cwrklg----�ò������ã�����ָ��cwrklg�ѽ�������ֱ��ʹ�ü���
*/
_declspec(dllexport) int WINAPI read_wrklg(void *con);
//��ȡ�豸̨�˼�¼�ĺ���������ͬ��
_declspec(dllexport) int WINAPI read_mcglg(void *con);
//��ȡ���ϼ�¼�ĺ���������ͬ��
_declspec(dllexport) int WINAPI read_gz(void *con);
//��ȡά�޼�¼�ĺ���������ͬ��
_declspec(dllexport) int WINAPI read_weixiu(void *con);
//��ȡ����¼�ĺ���������ͬ��
_declspec(dllexport) int WINAPI read_ruku(void *con);
//��ȡ�û���¼�ĺ���������ͬ��
_declspec(dllexport) int WINAPI read_user(void *con);



//���е�������
//����wָ���������
_declspec(dllexport) void WINAPI clean_ary(int w);


//�����ڲ�ʹ�õĽ���access���ʹؼ��ֵĺ���
int	crt_conn(CString &str);











