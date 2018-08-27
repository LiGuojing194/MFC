#if !defined(AFX_PAGE1_H__88CB01DD_D63A_487F_B341_7882DB86F605__INCLUDED_)
#define AFX_PAGE1_H__88CB01DD_D63A_487F_B341_7882DB86F605__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage1 dialog

class CPage1 : public CDialog
{
// Construction
public:
	CPage1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage1)
	enum { IDD = IDD_PAGE1 };
	CString	m_szName;
	CString	m_szNumb;
	int		m_nSex;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage1)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE1_H__88CB01DD_D63A_487F_B341_7882DB86F605__INCLUDED_)
