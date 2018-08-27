// s.h : main header file for the S application
//

#if !defined(AFX_S_H__778BC2B9_C427_4A9B_993F_9C60F4A2AFC4__INCLUDED_)
#define AFX_S_H__778BC2B9_C427_4A9B_993F_9C60F4A2AFC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSApp:
// See s.cpp for the implementation of this class
//
enum
{//定义协议编号
  INF_ADD=0x1234,
  INF_BROW,
  INF_DEL,
  INF_MOD,
  INF_FIND
};
struct SData
{
  int nNumb;
  char sName[20];
  float fSala;
};
#include <afxtempl.h>
class CSApp : public CWinApp
{
public:
	CList<SData,SData>m_list;
	CSApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_S_H__778BC2B9_C427_4A9B_993F_9C60F4A2AFC4__INCLUDED_)
