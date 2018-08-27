// Trans2Dlg.h : header file
//

#if !defined(AFX_TRANS2DLG_H__663A235D_7D68_44DD_BE47_21DC2A8E63AF__INCLUDED_)
#define AFX_TRANS2DLG_H__663A235D_7D68_44DD_BE47_21DC2A8E63AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTrans2Dlg dialog
#include"MemDC.h"
class CTrans2Dlg : public CDialog
{
// Construction
public:
	CMemDC m_dc;
	CTrans2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTrans2Dlg)
	enum { IDD = IDD_TRANS2_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrans2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTrans2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANS2DLG_H__663A235D_7D68_44DD_BE47_21DC2A8E63AF__INCLUDED_)
