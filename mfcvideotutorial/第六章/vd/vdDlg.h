// vdDlg.h : header file
//

#if !defined(AFX_VDDLG_H__CC0CBD17_939F_44A2_9B30_32919CC5950C__INCLUDED_)
#define AFX_VDDLG_H__CC0CBD17_939F_44A2_9B30_32919CC5950C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CVdDlg dialog

class CVdDlg : public CDialog
{
// Construction
public:
	CVdDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CVdDlg)
	enum { IDD = IDD_VD_DIALOG };
	CButton	m_del;
	CButton	m_add;
	CListCtrl	m_list;
	BOOL	m_bEngl;
	BOOL	m_bJapa;
	COleDateTime	m_dtJoin;
	BOOL	m_bKorea;
	CString	m_szName;
	CString	m_szNumb;
	BOOL	m_bRuss;
	int		m_nSex;
	int		m_nEduca;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVdDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVdDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnMod();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VDDLG_H__CC0CBD17_939F_44A2_9B30_32919CC5950C__INCLUDED_)
