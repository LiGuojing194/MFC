#if !defined(AFX_CHATDLG_H__6F094D64_FF3B_46C4_952D_F1327353B92E__INCLUDED_)
#define AFX_CHATDLG_H__6F094D64_FF3B_46C4_952D_F1327353B92E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChatDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChatDlg dialog

class CChatDlg : public CDialog
{
// Construction
public:
	CChatDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChatDlg)
	enum { IDD = IDD_CHAT_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChatDlg)
	afx_msg void OnChangeHist();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATDLG_H__6F094D64_FF3B_46C4_952D_F1327353B92E__INCLUDED_)
