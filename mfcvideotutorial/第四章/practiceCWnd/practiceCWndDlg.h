// practiceCWndDlg.h : header file
//

#if !defined(AFX_PRACTICECWNDDLG_H__A62A6DC2_51D9_4187_AFE5_23AD5B3CE350__INCLUDED_)
#define AFX_PRACTICECWNDDLG_H__A62A6DC2_51D9_4187_AFE5_23AD5B3CE350__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"mybutton.h"
#include"MyList.h"
/////////////////////////////////////////////////////////////////////////////
// CPracticeCWndDlg dialog

class CPracticeCWndDlg : public CDialog
{
// Construction
public:
	CPracticeCWndDlg(CWnd* pParent = NULL);	// standard constructor
    CMyList m_list;
	CWnd m_edit;
	mybutton m_dest;
	mybutton m_cret;
// Dialog Data
	//{{AFX_DATA(CPracticeCWndDlg)
	enum { IDD = IDD_PRACTICECWND_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPracticeCWndDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPracticeCWndDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnDestroy();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRACTICECWNDDLG_H__A62A6DC2_51D9_4187_AFE5_23AD5B3CE350__INCLUDED_)
