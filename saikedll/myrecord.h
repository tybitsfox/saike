#ifndef DB_DATA_STRUC
#include "datastruct.h"
#endif

class myrecord:public CRecordset
{
public:
	_TAGWRKLOG wlg;
	_TAGMCHLOG mlg;
	_TAGGUZHANG gz;
	_TAGREPAIR	rep;
	_TAGRUKU	ruku;
	_TAGUSER	usr;
	_TAGBASE	bas;
	myrecord(CDatabase *db);
	CString GetDefaultSQL();
	void DoFieldExchange(CFieldExchange *pfx);
};