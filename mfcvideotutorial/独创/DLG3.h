#if !defined(AFX_DLG3_H__302AED91_7A55_4A26_8C78_2DD17A5B435A__INCLUDED_)
#define AFX_DLG3_H__302AED91_7A55_4A26_8C78_2DD17A5B435A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLG3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DLG3 dialog

class DLG3 : public CDialog
{
// Construction
public:
	DLG3(CWnd* pParent = NULL);   // standard constructor
  CWnd edit1;
// Dialog Data
	//{{AFX_DATA(DLG3)
	enum { IDD = IDD_DIALOG3 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DLG3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DLG3)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG3_H__302AED91_7A55_4A26_8C78_2DD17A5B435A__INCLUDED_)
