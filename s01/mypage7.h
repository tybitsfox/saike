#define MYPAGE_DEFINE_7
#ifndef IDD_PROPPAGE_SMALL6
#include"resource.h"
#endif

class mypage7:public CPropertyPage
{
public:
	mypage7():CPropertyPage(IDD_PROPPAGE_SMALL6){};
	BOOL OnInitDialog();
	int onsave();
	afx_msg void onchg1();
protected:
	void com_chg(int sel);
public:
DECLARE_DYNCREATE(mypage7)
DECLARE_MESSAGE_MAP()
};