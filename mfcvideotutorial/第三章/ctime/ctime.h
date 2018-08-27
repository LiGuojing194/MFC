// ctime.h : main header file for the CTIME application
//

#if !defined(AFX_CTIME_H__30B36B4E_84EC_481A_B044_3815C194966E__INCLUDED_)
#define AFX_CTIME_H__30B36B4E_84EC_481A_B044_3815C194966E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCtimeApp:
// See ctime.cpp for the implementation of this class
//

class CCtimeApp : public CWinApp
{
public:
	CCtimeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCtimeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCtimeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTIME_H__30B36B4E_84EC_481A_B044_3815C194966E__INCLUDED_)
