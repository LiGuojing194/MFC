// Si.h : main header file for the SI application
//

#if !defined(AFX_SI_H__54610F9A_30F3_4EF8_A1AA_45359755C7C3__INCLUDED_)
#define AFX_SI_H__54610F9A_30F3_4EF8_A1AA_45359755C7C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSiApp:
// See Si.cpp for the implementation of this class
//

class CSiApp : public CWinApp
{
public:
	CSiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSiApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SI_H__54610F9A_30F3_4EF8_A1AA_45359755C7C3__INCLUDED_)
