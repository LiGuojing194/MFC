// vcDlg.h : header file
//

#if !defined(AFX_VCDLG_H__D2D13C51_59A2_4890_B2DC_165070C65054__INCLUDED_)
#define AFX_VCDLG_H__D2D13C51_59A2_4890_B2DC_165070C65054__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CVcDlg dialog

class CVcDlg : public CDialog
{
// Construction
public:
	CVcDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CVcDlg)
	enum { IDD = IDD_VC_DIALOG };
	CListCtrl	m_list;
	CComboBox	m_combo;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVcDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVcDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnMod();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VCDLG_H__D2D13C51_59A2_4890_B2DC_165070C65054__INCLUDED_)
