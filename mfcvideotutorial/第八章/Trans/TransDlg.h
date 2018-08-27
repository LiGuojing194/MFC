// TransDlg.h : header file
//

#if !defined(AFX_TRANSDLG_H__F6CD255B_7E88_4CE5_AD94_35A4F6FBE2D4__INCLUDED_)
#define AFX_TRANSDLG_H__F6CD255B_7E88_4CE5_AD94_35A4F6FBE2D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTransDlg dialog
#include"MemDC.h"
class CTransDlg : public CDialog
{
// Construction
public:
	CMemDC m_dc;//加载背景图并透明输出
	CTransDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTransDlg)
	enum { IDD = IDD_TRANS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTransDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSDLG_H__F6CD255B_7E88_4CE5_AD94_35A4F6FBE2D4__INCLUDED_)
