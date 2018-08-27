// SpnDlg.h : header file
//

#if !defined(AFX_SPNDLG_H__060BF036_0968_40EE_8D18_B676780CE597__INCLUDED_)
#define AFX_SPNDLG_H__060BF036_0968_40EE_8D18_B676780CE597__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSpnDlg dialog

class CSpnDlg : public CDialog
{
// Construction
public:
	CSpnDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSpnDlg)
	enum { IDD = IDD_SPN_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpnDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSpnDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPNDLG_H__060BF036_0968_40EE_8D18_B676780CE597__INCLUDED_)
