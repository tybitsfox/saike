#include"stdafx.h"
#include"mysheet.h"

IMPLEMENT_DYNAMIC(mysheet,CPropertySheet)
BEGIN_MESSAGE_MAP(mysheet,CPropertySheet)
	//
END_MESSAGE_MAP()

mysheet::mysheet(LPCTSTR name,CWnd *pwnd):CPropertySheet(name,pwnd,0)
{
	AddPage(&mpg1);
	AddPage(&mpg2);
	AddPage(&mpg3);
	AddPage(&mpg4);
	AddPage(&mpg5);
};