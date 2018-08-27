// Brush.h : main header file for the BRUSH application
//

#if !defined(AFX_BRUSH_H__BD824BBF_FFE6_4E30_8409_D73F59578A26__INCLUDED_)
#define AFX_BRUSH_H__BD824BBF_FFE6_4E30_8409_D73F59578A26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBrushApp:
// See Brush.cpp for the implementation of this class
//

class CBrushApp : public CWinApp
{
public:
	CBrushApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrushApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBrushApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BRUSH_H__BD824BBF_FFE6_4E30_8409_D73F59578A26__INCLUDED_)
