#if !defined(AFX_PAGE1_H__499455FA_D9E4_47AE_A9EB_D8924BFDA56B__INCLUDED_)
#define AFX_PAGE1_H__499455FA_D9E4_47AE_A9EB_D8924BFDA56B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage1 dialog

class CPage1 : public CPropertyPage
{
	DECLARE_DYNCREATE(CPage1)

// Construction
public:
	CPage1();
	~CPage1();

// Dialog Data
	//{{AFX_DATA(CPage1)
	enum { IDD = IDD_PAGE1 };
	CString	m_szName;
	CString	m_szNumb;
	int		m_nSex;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPage1)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPage1)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE1_H__499455FA_D9E4_47AE_A9EB_D8924BFDA56B__INCLUDED_)
