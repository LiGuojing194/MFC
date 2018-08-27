// Fly.h : main header file for the FLY application
//

#if !defined(AFX_FLY_H__44FD7656_5025_44FE_84DF_1544D6C72F92__INCLUDED_)
#define AFX_FLY_H__44FD7656_5025_44FE_84DF_1544D6C72F92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFlyApp:
// See Fly.cpp for the implementation of this class
//

class CFlyApp : public CWinApp
{
public:
	CFlyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFlyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLY_H__44FD7656_5025_44FE_84DF_1544D6C72F92__INCLUDED_)
