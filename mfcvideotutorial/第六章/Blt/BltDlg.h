// BltDlg.h : header file
//

#if !defined(AFX_BLTDLG_H__C7359719_07D6_4E1E_9735_B40CF1AB40AC__INCLUDED_)
#define AFX_BLTDLG_H__C7359719_07D6_4E1E_9735_B40CF1AB40AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBltDlg dialog

class CBltDlg : public CDialog
{
// Construction
public:
	CBltDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBltDlg)
	enum { IDD = IDD_BLT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBltDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBltDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BLTDLG_H__C7359719_07D6_4E1E_9735_B40CF1AB40AC__INCLUDED_)
