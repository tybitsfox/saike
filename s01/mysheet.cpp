#include"stdafx.h"
#include"mysheet.h"

extern DWORD	show_sign;
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
	AddPage(&mpg6);
	AddPage(&mpg7);
};
void mysheet::show()
{
	if((uid & 1)==0)
		RemovePage(&mpg1);
	if((uid & 2)==0)
		RemovePage(&mpg2);
	if((uid & 4)==0)
		RemovePage(&mpg3);	
	if((uid & 8)==0)
		RemovePage(&mpg4);
	if((uid & 16)==0)
		RemovePage(&mpg5);
	if((uid & 32)==0)
		RemovePage(&mpg6);	
	if((uid & 64)==0)
		RemovePage(&mpg7);

};

