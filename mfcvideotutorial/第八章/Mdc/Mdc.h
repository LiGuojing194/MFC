// Mdc.h : main header file for the MDC application
//

#if !defined(AFX_MDC_H__A1674894_193C_425F_B0E3_7D557E97D364__INCLUDED_)
#define AFX_MDC_H__A1674894_193C_425F_B0E3_7D557E97D364__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMdcApp:
// See Mdc.cpp for the implementation of this class
//

class CMdcApp : public CWinApp
{
public:
	CMdcApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMdcApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMdcApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDC_H__A1674894_193C_425F_B0E3_7D557E97D364__INCLUDED_)
