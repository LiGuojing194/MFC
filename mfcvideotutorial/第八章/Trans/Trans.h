// Trans.h : main header file for the TRANS application
//

#if !defined(AFX_TRANS_H__7AEEC878_C35D_455D_921D_8AEDBA4AF479__INCLUDED_)
#define AFX_TRANS_H__7AEEC878_C35D_455D_921D_8AEDBA4AF479__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTransApp:
// See Trans.cpp for the implementation of this class
//

class CTransApp : public CWinApp
{
public:
	CTransApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTransApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANS_H__7AEEC878_C35D_455D_921D_8AEDBA4AF479__INCLUDED_)
