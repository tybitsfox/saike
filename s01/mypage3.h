#ifndef IDD_PROPPAGE_SMALL
#include"resource.h"
#endif
#define MYPAGE_DEFINE_3

class mypage3:public CPropertyPage
{
public:
	DECLARE_DYNCREATE(mypage3)
	mypage3():CPropertyPage(IDD_PROPPAGE_SMALL2){};
	BOOL OnInitDialog();
	int onsave();
DECLARE_MESSAGE_MAP()
};