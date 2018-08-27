#if !defined(AFX_MODDLG_H__FFE8D767_8FD6_45CA_B1E5_C4846806A863__INCLUDED_)
#define AFX_MODDLG_H__FFE8D767_8FD6_45CA_B1E5_C4846806A863__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ModDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CModDlg dialog
#include"Page1.h"
#include"Page2.h"
#include"Page3.h"

class CModDlg : public CDialog
{
// Construction
public:
	CPage1 m_p1;
	CPage2 m_p2;
	CPage3 m_p3;

	CModDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CModDlg)
	enum { IDD = IDD_MOD_DLG };
	CTabCtrl	m_tab;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CModDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODDLG_H__FFE8D767_8FD6_45CA_B1E5_C4846806A863__INCLUDED_)
