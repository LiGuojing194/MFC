// refrectMFCDlg.h : header file
//

#if !defined(AFX_REFRECTMFCDLG_H__92A950A9_398A_4334_9D36_2A1AF39C2DB7__INCLUDED_)
#define AFX_REFRECTMFCDLG_H__92A950A9_398A_4334_9D36_2A1AF39C2DB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRefrectMFCDlg dialog

class CRefrectMFCDlg : public CDialog
{
// Construction
public:
	CRefrectMFCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRefrectMFCDlg)
	enum { IDD = IDD_REFRECTMFC_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRefrectMFCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRefrectMFCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REFRECTMFCDLG_H__92A950A9_398A_4334_9D36_2A1AF39C2DB7__INCLUDED_)
