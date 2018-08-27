// calDlg.h : header file
//

#if !defined(AFX_CALDLG_H__55696DC8_A54F_4249_BC92_5F2545BF2C03__INCLUDED_)
#define AFX_CALDLG_H__55696DC8_A54F_4249_BC92_5F2545BF2C03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCalDlg dialog

class CCalDlg : public CDialog
{
// Construction
public:
	CCalDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCalDlg)
	enum { IDD = IDD_CAL_DIALOG };
	int		m_nResult;
	int		m_nLeft;
	int		m_nRight;
	int		m_nOper;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCalDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALDLG_H__55696DC8_A54F_4249_BC92_5F2545BF2C03__INCLUDED_)
