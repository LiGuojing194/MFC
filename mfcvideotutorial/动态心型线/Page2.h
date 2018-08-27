#if !defined(AFX_PAGE2_H__901AD030_B584_4C2C_944C_595762628412__INCLUDED_)
#define AFX_PAGE2_H__901AD030_B584_4C2C_944C_595762628412__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage2 dialog
#include"MemDC.h"
class CPage2 : public CDialog
{
	CMemDC m_dc2;
// Construction
public:
	CMemDC m_dcBack2;
	CMemDC m_dcMem2;
	CPage2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage2)
	enum { IDD = IDD_DIALOG2 };
	CButton	m_sorrow;
	CButton	m_happy;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage2)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButton2();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE2_H__901AD030_B584_4C2C_944C_595762628412__INCLUDED_)
