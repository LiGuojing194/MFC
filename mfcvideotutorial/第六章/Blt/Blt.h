// Blt.h : main header file for the BLT application
//

#if !defined(AFX_BLT_H__90D14380_1555_4CA7_B5C6_D8541F41FB86__INCLUDED_)
#define AFX_BLT_H__90D14380_1555_4CA7_B5C6_D8541F41FB86__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBltApp:
// See Blt.cpp for the implementation of this class
//

class CBltApp : public CWinApp
{
public:
	CBltApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBltApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBltApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BLT_H__90D14380_1555_4CA7_B5C6_D8541F41FB86__INCLUDED_)
