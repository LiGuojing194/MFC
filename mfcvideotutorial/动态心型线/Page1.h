#if !defined(AFX_PAGE1_H__0A0512D1_39DA_4568_B2D7_46EDD23034C0__INCLUDED_)
#define AFX_PAGE1_H__0A0512D1_39DA_4568_B2D7_46EDD23034C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage1 dialog
#include"MemDC.h"
class CPage1 : public CDialog
{
	CMemDC m_dc1;
// Construction
public:
	CMemDC m_dcBack1;
	CMemDC m_dcMem1;
	CPage1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage1)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage1)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE1_H__0A0512D1_39DA_4568_B2D7_46EDD23034C0__INCLUDED_)
