#ifndef IDD_PROPPAGE_SMALL
#include"resource.h"
#endif
#define MYPAGE_DEFINE_4

class mypage4:public CPropertyPage
{
public:
	DECLARE_DYNCREATE(mypage4)
	mypage4():CPropertyPage(IDD_PROPPAGE_SMALL3){};
	BOOL OnInitDialog();
DECLARE_MESSAGE_MAP()
};
