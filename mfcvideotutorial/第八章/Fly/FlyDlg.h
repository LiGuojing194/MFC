// FlyDlg.h : header file
//

#if !defined(AFX_FLYDLG_H__94CADC2F_209E_43A6_825B_994FDF575DEA__INCLUDED_)
#define AFX_FLYDLG_H__94CADC2F_209E_43A6_825B_994FDF575DEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFlyDlg dialog
#include"MemDC.h"
class CFlyDlg : public CDialog
{
	enum{FLY_CNT=7};//7帧
	CMemDC m_dcBack;//加载背景
	CMemDC m_dcFly[FLY_CNT];//加载动画
	int m_nIndex;//当前帧数
	CPoint m_pos;//当前位置
    
// Construction
public:
	void OnDraw(CDC*pDC);
	void LoadPicture();
	CFlyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFlyDlg)
	enum { IDD = IDD_FLY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFlyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLYDLG_H__94CADC2F_209E_43A6_825B_994FDF575DEA__INCLUDED_)
