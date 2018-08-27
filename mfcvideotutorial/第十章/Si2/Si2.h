// Si2.h : main header file for the SI2 application
//

#if !defined(AFX_SI2_H__2187CDCC_FDC3_413C_9210_E136933C6982__INCLUDED_)
#define AFX_SI2_H__2187CDCC_FDC3_413C_9210_E136933C6982__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSi2App:
// See Si2.cpp for the implementation of this class
//

class CSi2App : public CWinApp
{
public:
	CSi2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSi2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSi2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SI2_H__2187CDCC_FDC3_413C_9210_E136933C6982__INCLUDED_)
