// TRY.h : main header file for the TRY application
//

#if !defined(AFX_TRY_H__C6A0A0D0_4E81_4EF0_BC62_5836B22ADCC1__INCLUDED_)
#define AFX_TRY_H__C6A0A0D0_4E81_4EF0_BC62_5836B22ADCC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTRYApp:
// See TRY.cpp for the implementation of this class
//

class CTRYApp : public CWinApp
{
public:
	CTRYApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTRYApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTRYApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRY_H__C6A0A0D0_4E81_4EF0_BC62_5836B22ADCC1__INCLUDED_)
