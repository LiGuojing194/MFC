// ctimeDlg.h : header file
//

#if !defined(AFX_CTIMEDLG_H__3B38DE0F_646A_4009_A967_434CD6E92A88__INCLUDED_)
#define AFX_CTIMEDLG_H__3B38DE0F_646A_4009_A967_434CD6E92A88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCtimeDlg dialog

class CCtimeDlg : public CDialog
{
// Construction
public:
	CCtimeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCtimeDlg)
	enum { IDD = IDD_CTIME_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCtimeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCtimeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTIMEDLG_H__3B38DE0F_646A_4009_A967_434CD6E92A88__INCLUDED_)
