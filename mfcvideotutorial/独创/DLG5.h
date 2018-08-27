#if !defined(AFX_DLG5_H__F5EE470D_67F0_4FF2_B976_3A7F4766EB49__INCLUDED_)
#define AFX_DLG5_H__F5EE470D_67F0_4FF2_B976_3A7F4766EB49__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLG5.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DLG5 dialog

class DLG5 : public CDialog
{
// Construction
public:
	DLG5(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DLG5)
	enum { IDD = IDD_DIALOG5 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DLG5)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DLG5)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG5_H__F5EE470D_67F0_4FF2_B976_3A7F4766EB49__INCLUDED_)
