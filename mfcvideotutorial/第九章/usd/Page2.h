#if !defined(AFX_PAGE2_H__C65CC761_B341_487F_B679_776376DCC1E1__INCLUDED_)
#define AFX_PAGE2_H__C65CC761_B341_487F_B679_776376DCC1E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage2 dialog

class CPage2 : public CDialog
{
// Construction
public:
	CPage2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage2)
	enum { IDD = IDD_PAGE2 };
	COleDateTime	m_birth;
	int		m_nBlood;
	CString	m_szHome;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage2)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE2_H__C65CC761_B341_487F_B679_776376DCC1E1__INCLUDED_)
