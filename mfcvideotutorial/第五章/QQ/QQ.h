// QQ.h : main header file for the QQ application
//

#if !defined(AFX_QQ_H__A263B103_FE83_4B83_9329_427C744CD0B5__INCLUDED_)
#define AFX_QQ_H__A263B103_FE83_4B83_9329_427C744CD0B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CQQApp:
// See QQ.cpp for the implementation of this class
//


struct SUser
{//登录用户信息结构体
  char sName[20];
  char sPass[20];
  char sPrior[8];
};





class CQQApp : public CWinApp
{
public:
	CQQApp();
    SUser m_user;//用于保存当前登录用户信息
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQQApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CQQApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QQ_H__A263B103_FE83_4B83_9329_427C744CD0B5__INCLUDED_)
