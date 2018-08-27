// sDlg.h : header file
//

#if !defined(AFX_SDLG_H__AECE6B15_C574_434D_AE75_96F7CE767F98__INCLUDED_)
#define AFX_SDLG_H__AECE6B15_C574_434D_AE75_96F7CE767F98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSDlg dialog
#include"ListenSocket.h"
class CSDlg : public CDialog
{
	CListenSocket m_sock;
// Construction
public:
	CSDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSDlg)
	enum { IDD = IDD_S_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SDLG_H__AECE6B15_C574_434D_AE75_96F7CE767F98__INCLUDED_)
