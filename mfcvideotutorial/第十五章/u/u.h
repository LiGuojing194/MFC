// u.h : main header file for the U application
//

#if !defined(AFX_U_H__3B7982F4_2DB9_4D89_B668_8DDE3261151C__INCLUDED_)
#define AFX_U_H__3B7982F4_2DB9_4D89_B668_8DDE3261151C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUApp:
// See u.cpp for the implementation of this class
//

class CUApp : public CWinApp
{
public:
	CUApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_U_H__3B7982F4_2DB9_4D89_B668_8DDE3261151C__INCLUDED_)
