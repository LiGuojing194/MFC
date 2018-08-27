// toumingseDlg.h : header file
//

#if !defined(AFX_TOUMINGSEDLG_H__591B4049_9C24_4C63_A114_9592A2B52251__INCLUDED_)
#define AFX_TOUMINGSEDLG_H__591B4049_9C24_4C63_A114_9592A2B52251__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CToumingseDlg dialog
#include"MemDC.h"
class CToumingseDlg : public CDialog
{
	CMemDC m_dc;
// Construction
public:
	CToumingseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CToumingseDlg)
	enum { IDD = IDD_TOUMINGSE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToumingseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CToumingseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOUMINGSEDLG_H__591B4049_9C24_4C63_A114_9592A2B52251__INCLUDED_)
