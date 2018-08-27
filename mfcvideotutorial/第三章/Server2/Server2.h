// Server2.h : main header file for the SERVER2 application
//

#if !defined(AFX_SERVER2_H__6E976A6C_DEB5_4FCD_B05E_8A78B1C5D2A9__INCLUDED_)
#define AFX_SERVER2_H__6E976A6C_DEB5_4FCD_B05E_8A78B1C5D2A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CServer2App:
// See Server2.cpp for the implementation of this class
//

class CServer2App : public CWinApp
{
public:
	CPtrList m_list;
	CServer2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServer2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CServer2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVER2_H__6E976A6C_DEB5_4FCD_B05E_8A78B1C5D2A9__INCLUDED_)
