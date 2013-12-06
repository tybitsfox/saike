#ifndef IDD_PROPPAGE_SMALL
#include"resource.h"
#endif
#define MYPAGE_DEFINE_2

class mypage2:public CPropertyPage
{
public:
	DECLARE_DYNCREATE(mypage2)
	mypage2():CPropertyPage(IDD_PROPPAGE_SMALL1){};
	BOOL OnInitDialog();
	int onsave();
DECLARE_MESSAGE_MAP()
};
