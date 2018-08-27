// vs.h : main header file for the VS application
//

#if !defined(AFX_VS_H__F8BCD744_7F4E_4B9B_A3EF_43E544649626__INCLUDED_)
#define AFX_VS_H__F8BCD744_7F4E_4B9B_A3EF_43E544649626__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVsApp:
// See vs.cpp for the implementation of this class
//

class CVsApp : public CWinApp
{
public:
	CVsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VS_H__F8BCD744_7F4E_4B9B_A3EF_43E544649626__INCLUDED_)
