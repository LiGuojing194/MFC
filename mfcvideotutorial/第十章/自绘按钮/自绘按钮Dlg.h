// ×Ô»æ°´Å¥Dlg.h : header file
//

#if !defined(AFX_DLG_H__7B6FA598_81BD_4B88_9F61_13E127E1BD1A__INCLUDED_)
#define AFX_DLG_H__7B6FA598_81BD_4B88_9F61_13E127E1BD1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog
#include"HotButton.h"
class CMyDlg : public CDialog
{
	CBitmap m_Bitmap[1];//(´¢´æ°´Å¥Õý³£×´Ì¬Î»Í¼)
	CBitmap m_HotBitmap[1];//(´¢´æ°´Å¥ÈÈµã×´Ì¬Î»Í¼)
	CBrush m_Brush;//»­Ë¢
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
	CEdit	m_Edit2;
	CHotButton	m_TransformButton;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnTransformBtn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__7B6FA598_81BD_4B88_9F61_13E127E1BD1A__INCLUDED_)
