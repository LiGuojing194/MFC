// mybutton.cpp : implementation file
//

#include "stdafx.h"
#include "practiceCWnd.h"
#include "mybutton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// mybutton

mybutton::mybutton()
{
}

mybutton::~mybutton()
{
}


BEGIN_MESSAGE_MAP(mybutton, CWnd)
	//{{AFX_MSG_MAP(mybutton)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// mybutton message handlers

void mybutton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CWnd::OnLButtonDown(nFlags, point);
}
