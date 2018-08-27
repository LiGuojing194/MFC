// RgnDlg.h : header file
//

#if !defined(AFX_RGNDLG_H__4638C9AC_0356_4226_A363_2EA30DF2C638__INCLUDED_)
#define AFX_RGNDLG_H__4638C9AC_0356_4226_A363_2EA30DF2C638__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRgnDlg dialog

class CRgnDlg : public CDialog
{
// Construction
public:
	CRgnDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRgnDlg)
	enum { IDD = IDD_RGN_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRgnDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRgnDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg UINT OnNcHitTest(CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RGNDLG_H__4638C9AC_0356_4226_A363_2EA30DF2C638__INCLUDED_)
