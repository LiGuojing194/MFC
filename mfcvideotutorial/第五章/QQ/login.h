#if !defined(AFX_LOGIN_H__C84BB056_B854_4650_B4F1_9471B15AA4FF__INCLUDED_)
#define AFX_LOGIN_H__C84BB056_B854_4650_B4F1_9471B15AA4FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// login.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// login dialog

class login : public CDialog
{
// Construction
public:
	void CreateUser();
	BOOL CheckUser(CString szName,CString szPass);
	login(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(login)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(login)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(login)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN_H__C84BB056_B854_4650_B4F1_9471B15AA4FF__INCLUDED_)
