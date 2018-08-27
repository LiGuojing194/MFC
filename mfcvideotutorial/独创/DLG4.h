#if !defined(AFX_DLG4_H__ADF87F7B_62C5_4D2C_929B_51231246E053__INCLUDED_)
#define AFX_DLG4_H__ADF87F7B_62C5_4D2C_929B_51231246E053__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLG4.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DLG4 dialog

class DLG4 : public CDialog
{
// Construction
public:
	DLG4(CWnd* pParent = NULL);   // standard constructor
    CWnd edital;
// Dialog Data
	//{{AFX_DATA(DLG4)
	enum { IDD = IDD_DIALOG4 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DLG4)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DLG4)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG4_H__ADF87F7B_62C5_4D2C_929B_51231246E053__INCLUDED_)
