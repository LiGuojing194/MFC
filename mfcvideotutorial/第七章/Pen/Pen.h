// Pen.h : main header file for the PEN application
//

#if !defined(AFX_PEN_H__9A171B1E_F757_485A_8F03_1B66FBA726BC__INCLUDED_)
#define AFX_PEN_H__9A171B1E_F757_485A_8F03_1B66FBA726BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPenApp:
// See Pen.cpp for the implementation of this class
//

class CPenApp : public CWinApp
{
public:
	CPenApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPenApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPenApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PEN_H__9A171B1E_F757_485A_8F03_1B66FBA726BC__INCLUDED_)
