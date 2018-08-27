// TestCWnd.h : main header file for the TESTCWND application
//

#if !defined(AFX_TESTCWND_H__94E0AF3F_1115_463B_A0DA_FF2324B686A7__INCLUDED_)
#define AFX_TESTCWND_H__94E0AF3F_1115_463B_A0DA_FF2324B686A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestCWndApp:
// See TestCWnd.cpp for the implementation of this class
//

class CTestCWndApp : public CWinApp
{
public:
	CTestCWndApp();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestCWndApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestCWndApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCWND_H__94E0AF3F_1115_463B_A0DA_FF2324B686A7__INCLUDED_)
