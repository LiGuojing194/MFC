#if !defined(AFX_ABOUTDLG_H__09F68132_5A3E_4D42_82D6_D600BB29E64B__INCLUDED_)
#define AFX_ABOUTDLG_H__09F68132_5A3E_4D42_82D6_D600BB29E64B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ABOUTDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ABOUTDLG dialog

class ABOUTDLG : public CDialog
{
// Construction
public:
	ABOUTDLG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ABOUTDLG)
	enum { IDD = IDD_ABOUT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ABOUTDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ABOUTDLG)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ABOUTDLG_H__09F68132_5A3E_4D42_82D6_D600BB29E64B__INCLUDED_)
