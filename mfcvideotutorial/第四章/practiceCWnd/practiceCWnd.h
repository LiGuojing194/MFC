// practiceCWnd.h : main header file for the PRACTICECWND application
//

#if !defined(AFX_PRACTICECWND_H__45D1C227_E31B_4D7B_93A8_6226E34BCB1A__INCLUDED_)
#define AFX_PRACTICECWND_H__45D1C227_E31B_4D7B_93A8_6226E34BCB1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPracticeCWndApp:
// See practiceCWnd.cpp for the implementation of this class
//

class CPracticeCWndApp : public CWinApp
{
public:
	CPracticeCWndApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPracticeCWndApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPracticeCWndApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRACTICECWND_H__45D1C227_E31B_4D7B_93A8_6226E34BCB1A__INCLUDED_)
