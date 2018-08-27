#if !defined(AFX_MYMAIN_H__60C78E48_EB29_43CF_9BE2_741F7A8FD352__INCLUDED_)
#define AFX_MYMAIN_H__60C78E48_EB29_43CF_9BE2_741F7A8FD352__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyMain.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyMain dialog

class CMyMain : public CDialog
{
// Construction
public:
	CMyMain(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMyMain)
	enum { IDD = IDD_MAIN_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyMain)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMyMain)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMAIN_H__60C78E48_EB29_43CF_9BE2_741F7A8FD352__INCLUDED_)
