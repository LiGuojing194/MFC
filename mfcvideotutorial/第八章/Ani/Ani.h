// Ani.h : main header file for the ANI application
//

#if !defined(AFX_ANI_H__1E5AEB71_6B46_4B39_BE7E_78554DEC1F67__INCLUDED_)
#define AFX_ANI_H__1E5AEB71_6B46_4B39_BE7E_78554DEC1F67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAniApp:
// See Ani.cpp for the implementation of this class
//

class CAniApp : public CWinApp
{
public:
	CAniApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAniApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAniApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANI_H__1E5AEB71_6B46_4B39_BE7E_78554DEC1F67__INCLUDED_)
