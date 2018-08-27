// refrectMFC.h : main header file for the REFRECTMFC application
//

#if !defined(AFX_REFRECTMFC_H__34E8936D_0054_45B7_BA44_A9A794217500__INCLUDED_)
#define AFX_REFRECTMFC_H__34E8936D_0054_45B7_BA44_A9A794217500__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRefrectMFCApp:
// See refrectMFC.cpp for the implementation of this class
//

class CRefrectMFCApp : public CWinApp
{
public:
	CRefrectMFCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRefrectMFCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRefrectMFCApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REFRECTMFC_H__34E8936D_0054_45B7_BA44_A9A794217500__INCLUDED_)
