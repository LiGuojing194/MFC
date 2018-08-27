#if !defined(AFX_PAGE2_H__8367590C_1C49_44FF_A7ED_9C8643A06600__INCLUDED_)
#define AFX_PAGE2_H__8367590C_1C49_44FF_A7ED_9C8643A06600__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage2 dialog

class CPage2 : public CPropertyPage
{
	DECLARE_DYNCREATE(CPage2)

// Construction
public:
	CPage2();
	~CPage2();

// Dialog Data
	//{{AFX_DATA(CPage2)
	enum { IDD = IDD_PAGE2 };
	int		m_nBlood;
	CString	m_szHome;
	COleDateTime	m_nbirth;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPage2)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPage2)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE2_H__8367590C_1C49_44FF_A7ED_9C8643A06600__INCLUDED_)
