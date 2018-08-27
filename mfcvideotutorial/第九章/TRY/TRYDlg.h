// TRYDlg.h : header file
//

#if !defined(AFX_TRYDLG_H__A884F2CD_A74B_4508_A8DD_FF7BDE3D0644__INCLUDED_)
#define AFX_TRYDLG_H__A884F2CD_A74B_4508_A8DD_FF7BDE3D0644__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTRYDlg dialog

class CTRYDlg : public CDialog
{
// Construction
public:
	CTRYDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTRYDlg)
	enum { IDD = IDD_TRY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTRYDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTRYDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRYDLG_H__A884F2CD_A74B_4508_A8DD_FF7BDE3D0644__INCLUDED_)
