// MdcDlg.h : header file
//

#if !defined(AFX_MDCDLG_H__21B5A079_5C97_4935_B588_7B5E5A8D5F1F__INCLUDED_)
#define AFX_MDCDLG_H__21B5A079_5C97_4935_B588_7B5E5A8D5F1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMdcDlg dialog
#include"MemDC.h"

class CMdcDlg : public CDialog
{
// Construction
public:
	CMemDC m_dcMem;//用于存储缩放后的背景图
	CMemDC m_dcBack;//用于从文件中加载原始背景图
	CMdcDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMdcDlg)
	enum { IDD = IDD_MDC_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMdcDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMdcDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDCDLG_H__21B5A079_5C97_4935_B588_7B5E5A8D5F1F__INCLUDED_)
