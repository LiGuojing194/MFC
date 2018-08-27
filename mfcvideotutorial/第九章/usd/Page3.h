#if !defined(AFX_PAGE3_H__371FF26A_89D7_4457_91EE_7A4850DFE877__INCLUDED_)
#define AFX_PAGE3_H__371FF26A_89D7_4457_91EE_7A4850DFE877__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage3 dialog

class CPage3 : public CDialog
{
// Construction
public:
	CPage3(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage3)
	enum { IDD = IDD_PAGE3 };
	CString	m_szAdd;
	CString	m_szEmail;
	CString	m_szTel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage3)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE3_H__371FF26A_89D7_4457_91EE_7A4850DFE877__INCLUDED_)
