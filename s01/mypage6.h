#define MYPAGE_DEFINE_6
#ifndef IDD_PROPPAGE_SMALL5
#include"resource.h"
#endif

class mypage6:public CPropertyPage
{
public:
	DECLARE_DYNCREATE(mypage6)
	mypage6():CPropertyPage(IDD_PROPPAGE_SMALL5){}
	BOOL OnInitDialog();
	int onsave();
	afx_msg void onrd1();
	afx_msg void onrd2();
DECLARE_MESSAGE_MAP()
};