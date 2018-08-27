#if !defined(AFX_DLG1_H__22DC82F5_9A57_46D9_99A0_F15DBD0A98DB__INCLUDED_)
#define AFX_DLG1_H__22DC82F5_9A57_46D9_99A0_F15DBD0A98DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLG1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DLG1 dialog

class DLG1 : public CDialog
{
// Construction
public:
	DLG1(CWnd* pParent = NULL);   // standard constructor
    CWnd m_edit1,m_edit2,m_edit3;
// Dialog Data
	//{{AFX_DATA(DLG1)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DLG1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DLG1)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG1_H__22DC82F5_9A57_46D9_99A0_F15DBD0A98DB__INCLUDED_)
