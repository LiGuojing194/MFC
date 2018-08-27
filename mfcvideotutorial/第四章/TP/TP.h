// TP.h : main header file for the TP application
//

#if !defined(AFX_TP_H__1F412170_A3AB_43A5_932A_571B48D4CE0F__INCLUDED_)
#define AFX_TP_H__1F412170_A3AB_43A5_932A_571B48D4CE0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTPApp:
// See TP.cpp for the implementation of this class
//

class CTPApp : public CWinApp
{
public:
	CTPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTPApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TP_H__1F412170_A3AB_43A5_932A_571B48D4CE0F__INCLUDED_)
