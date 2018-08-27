// xdc.h : main header file for the XDC application
//

#if !defined(AFX_XDC_H__A5485529_8893_46A4_8916_85FBCFECAA4B__INCLUDED_)
#define AFX_XDC_H__A5485529_8893_46A4_8916_85FBCFECAA4B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CXdcApp:
// See xdc.cpp for the implementation of this class
//

class CXdcApp : public CWinApp
{
public:
	CXdcApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXdcApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CXdcApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XDC_H__A5485529_8893_46A4_8916_85FBCFECAA4B__INCLUDED_)
