// FlysDlg.h : header file
//

#if !defined(AFX_FLYSDLG_H__11052F2F_EA74_44B9_AA26_A26B3B072103__INCLUDED_)
#define AFX_FLYSDLG_H__11052F2F_EA74_44B9_AA26_A26B3B072103__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFlysDlg dialog

	struct SFly
	{
	 int nIndex;
	 int x,y;
	 int cx,cy;
	};
#include<afxtempl.h>
#include"MemDC.h"
class CFlysDlg : public CDialog
{
	enum{FLY_CNT=7};
	CMemDC m_dcBack;
	CMemDC m_dcFly[FLY_CNT];
	CList<SFly,SFly>m_list;

// Construction
public:
	void OnDraw(CDC*pDC);
	void LoadPicture();
	CFlysDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFlysDlg)
	enum { IDD = IDD_FLYS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlysDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFlysDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLYSDLG_H__11052F2F_EA74_44B9_AA26_A26B3B072103__INCLUDED_)
