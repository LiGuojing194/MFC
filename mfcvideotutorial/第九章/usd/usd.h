// usd.h : main header file for the USD application
//

#if !defined(AFX_USD_H__EA38BFFF_8E2C_4582_8B9C_4E088367A9BD__INCLUDED_)
#define AFX_USD_H__EA38BFFF_8E2C_4582_8B9C_4E088367A9BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUsdApp:
// See usd.cpp for the implementation of this class
//

class CUsdApp : public CWinApp
{
public:
	CUsdApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUsdApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUsdApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USD_H__EA38BFFF_8E2C_4582_8B9C_4E088367A9BD__INCLUDED_)
