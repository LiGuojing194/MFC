// NotePad.h : main header file for the NOTEPAD application
//

#if !defined(AFX_NOTEPAD_H__4A63C716_DDAA_4105_BEDC_6B0EE53864F9__INCLUDED_)
#define AFX_NOTEPAD_H__4A63C716_DDAA_4105_BEDC_6B0EE53864F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNotePadApp:
// See NotePad.cpp for the implementation of this class
//

class CNotePadApp : public CWinApp
{
public:
	CNotePadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNotePadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNotePadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOTEPAD_H__4A63C716_DDAA_4105_BEDC_6B0EE53864F9__INCLUDED_)
