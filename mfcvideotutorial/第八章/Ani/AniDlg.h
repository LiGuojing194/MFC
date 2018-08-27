// AniDlg.h : header file
//

#if !defined(AFX_ANIDLG_H__CE884BA7_2DA2_4A77_A542_300B5836001C__INCLUDED_)
#define AFX_ANIDLG_H__CE884BA7_2DA2_4A77_A542_300B5836001C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAniDlg dialog
#include"MemDC.h"
class CAniDlg : public CDialog
{
// Construction
	CMemDC m_dc[12];
public:
	CAniDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAniDlg)
	enum { IDD = IDD_ANI_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAniDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAniDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIDLG_H__CE884BA7_2DA2_4A77_A542_300B5836001C__INCLUDED_)
