#ifndef IDD_PROPPAGE_SMALL
#include"resource.h"
#endif
#define MYPAGE_DEFINE_5

class mypage5:public CPropertyPage
{
public:
	DECLARE_DYNCREATE(mypage5)
	mypage5():CPropertyPage(IDD_PROPPAGE_SMALL4){};
	BOOL OnInitDialog();
DECLARE_MESSAGE_MAP()
};
