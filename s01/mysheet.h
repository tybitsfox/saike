#ifndef MYPAGE_DEFINE_1
#include"mypage1.h"
#endif
#ifndef MYPAGE_DEFINE_2
#include"mypage2.h"
#endif
#ifndef MYPAGE_DEFINE_3
#include"mypage3.h"
#endif
#ifndef MYPAGE_DEFINE_4
#include"mypage4.h"
#endif
#ifndef MYPAGE_DEFINE_5
#include"mypage5.h"
#endif


class mysheet:public CPropertySheet
{
public:
	DECLARE_DYNAMIC(mysheet)
	mypage1 mpg1;
	mypage2 mpg2;
	mypage3 mpg3;
	mypage4 mpg4;
	mypage5 mpg5;
	mysheet(LPCTSTR name="aa",CWnd *pwnd=NULL);
DECLARE_MESSAGE_MAP()
};