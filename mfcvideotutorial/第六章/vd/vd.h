// vd.h : main header file for the VD application
//

#if !defined(AFX_VD_H__7027A1B4_6AAD_47CB_9205_60E80529B0CA__INCLUDED_)
#define AFX_VD_H__7027A1B4_6AAD_47CB_9205_60E80529B0CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVdApp:
// See vd.cpp for the implementation of this class
//

class CVdApp : public CWinApp
{
public:
	CVdApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVdApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVdApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VD_H__7027A1B4_6AAD_47CB_9205_60E80529B0CA__INCLUDED_)
