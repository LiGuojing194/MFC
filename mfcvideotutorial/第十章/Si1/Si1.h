// Si1.h : main header file for the SI1 application
//

#if !defined(AFX_SI1_H__DBAF29C8_B4A4_40C4_AB39_C9732A36C4CF__INCLUDED_)
#define AFX_SI1_H__DBAF29C8_B4A4_40C4_AB39_C9732A36C4CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSi1App:
// See Si1.cpp for the implementation of this class
//

class CSi1App : public CWinApp
{
public:
	CSi1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSi1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSi1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SI1_H__DBAF29C8_B4A4_40C4_AB39_C9732A36C4CF__INCLUDED_)
