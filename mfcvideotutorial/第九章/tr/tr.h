// tr.h : main header file for the TR application
//

#if !defined(AFX_TR_H__C6A36FD0_EECA_4501_BF20_8612EE88F201__INCLUDED_)
#define AFX_TR_H__C6A36FD0_EECA_4501_BF20_8612EE88F201__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTrApp:
// See tr.cpp for the implementation of this class
//

class CTrApp : public CWinApp
{
public:
	CTrApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTrApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TR_H__C6A36FD0_EECA_4501_BF20_8612EE88F201__INCLUDED_)
