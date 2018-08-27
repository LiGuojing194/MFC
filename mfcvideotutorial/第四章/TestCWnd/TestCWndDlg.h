// TestCWndDlg.h : header file
//

#if !defined(AFX_TESTCWNDDLG_H__C3EB5A2D_027C_4048_B537_47ED777EDBFB__INCLUDED_)
#define AFX_TESTCWNDDLG_H__C3EB5A2D_027C_4048_B537_47ED777EDBFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestCWndDlg dialog

class CTestCWndDlg : public CDialog
{
// Construction
public:
	CTestCWndDlg(CWnd* pParent = NULL);	// standard constructor
    CWnd m_list;
	CWnd m_edit;
	CWnd m_dest;
// Dialog Data
	//{{AFX_DATA(CTestCWndDlg)
	enum { IDD = IDD_TESTCWND_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestCWndDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestCWndDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnDestroy();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButton8();
	afx_msg void OnButton9();
	afx_msg void OnButton10();
	afx_msg void OnButton11();
	afx_msg void OnButton12();
	afx_msg void OnButton13();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCWNDDLG_H__C3EB5A2D_027C_4048_B537_47ED777EDBFB__INCLUDED_)
