#include"stdafx.h"
#include"myrecord.h"
#define sysfile			"saikedb.udv"
#define dbfile			"Saike_2013_u01.mdb"

int wtb=0;

//定义工作记录队列
_declspec(dllexport) CArray<_TAGWRKLOG,_TAGWRKLOG&> cwrklg;
//定义设备台账队列
_declspec(dllexport) CArray<_TAGMCHLOG,_TAGMCHLOG&> cmchlg;
//定义故障记录队列
_declspec(dllexport) CArray<_TAGGUZHANG,_TAGGUZHANG&> cgz;
//定义维修记录队列
_declspec(dllexport) CArray<_TAGREPAIR,_TAGREPAIR&>  cweixiu;
//定义入库记录队列
_declspec(dllexport) CArray<_TAGRUKU,_TAGRUKU&> cruku;
//定义用户记录队列
_declspec(dllexport) CArray<_TAGUSER,_TAGUSER&> cuser;

//定义日志记录的保存函数
_declspec(dllexport) int WINAPI save_wrklg(void *res);
//定义设备台账的保存函数
_declspec(dllexport) int WINAPI save_mchlg(void *res);
//定义故障记录的保存函数
_declspec(dllexport) int WINAPI save_gz(void *res);
//定义维修记录的保存函数
_declspec(dllexport) int WINAPI save_weixiu(void *res);
//定义入库记录的保存函数
_declspec(dllexport) int WINAPI save_ruku(void *res);
//定义用户记录的保存函数
_declspec(dllexport) int WINAPI save_user(void *res);
//定义系统表的读取函数
_declspec(dllexport) int WINAPI read_sys(void *result);

//定义系统表的更新函数
/*
入口参数result必须包含待更新的数据
*/
_declspec(dllexport) int WINAPI update_sys(void *result);

//读取工作记录函数
/*
参数con:为传入的查询条件字符串，
参数pt:为返回符合查询条件的记录队列，该队列指针为前面定义的cwrklg----该参数无用，队列指针cwrklg已近导出，直接使用即可
*/
_declspec(dllexport) int WINAPI read_wrklg(void *con);
//读取设备台账记录的函数，参数同上
_declspec(dllexport) int WINAPI read_mcglg(void *con);
//读取故障记录的函数，参数同上
_declspec(dllexport) int WINAPI read_gz(void *con);
//读取维修记录的函数，参数同上
_declspec(dllexport) int WINAPI read_weixiu(void *con);
//读取入库记录的函数，参数同上
_declspec(dllexport) int WINAPI read_ruku(void *con);
//读取用户记录的函数，参数同上
_declspec(dllexport) int WINAPI read_user(void *con);



//队列的清理函数
//参数w指明队列序号
_declspec(dllexport) void WINAPI clean_ary(int w);


//定义内部使用的建立access访问关键字的函数
int	crt_conn(CString &str);











