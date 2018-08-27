// uDlg.h : header file
//

#if !defined(AFX_UDLG_H__5813D399_9259_4865_912B_47FCF6E127FD__INCLUDED_)
#define AFX_UDLG_H__5813D399_9259_4865_912B_47FCF6E127FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUDlg dialog
#include"Socku.h"

class CUDlg : public CDialog
{
	CSocku m_sock;
// Construction
public:
	CUDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUDlg)
	enum { IDD = IDD_U_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UDLG_H__5813D399_9259_4865_912B_47FCF6E127FD__INCLUDED_)
