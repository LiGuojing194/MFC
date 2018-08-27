// Spn.h : main header file for the SPN application
//

#if !defined(AFX_SPN_H__22BF34CA_DBC3_430C_B004_714AD7F63522__INCLUDED_)
#define AFX_SPN_H__22BF34CA_DBC3_430C_B004_714AD7F63522__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSpnApp:
// See Spn.cpp for the implementation of this class
//

class CSpnApp : public CWinApp
{
public:
	CSpnApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpnApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSpnApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPN_H__22BF34CA_DBC3_430C_B004_714AD7F63522__INCLUDED_)
