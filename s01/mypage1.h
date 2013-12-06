#ifndef IDD_PROPPAGE_SMALL
#include"resource.h"
#endif
#define MYPAGE_DEFINE_1

class mypage1:public CPropertyPage
{
public:
	DECLARE_DYNCREATE(mypage1)
	mypage1():CPropertyPage(IDD_PROPPAGE_SMALL){};
	BOOL OnInitDialog();
	int  osave();//
DECLARE_MESSAGE_MAP()
};
