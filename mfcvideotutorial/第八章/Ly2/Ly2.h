// Ly2.h : main header file for the LY2 application
//

#if !defined(AFX_LY2_H__0EA700DA_42FC_4AFF_BDD3_CA8F3F31CF82__INCLUDED_)
#define AFX_LY2_H__0EA700DA_42FC_4AFF_BDD3_CA8F3F31CF82__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLy2App:
// See Ly2.cpp for the implementation of this class
//

class CLy2App : public CWinApp
{
public:
	CLy2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLy2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLy2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LY2_H__0EA700DA_42FC_4AFF_BDD3_CA8F3F31CF82__INCLUDED_)
