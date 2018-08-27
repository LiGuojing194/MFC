#if !defined(AFX_MYBUTTON_H__014A6AA9_DB9F_425D_862E_2AE48D5DDA91__INCLUDED_)
#define AFX_MYBUTTON_H__014A6AA9_DB9F_425D_862E_2AE48D5DDA91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// mybutton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// mybutton window

class mybutton : public CWnd
{
// Construction
public:
	mybutton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(mybutton)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~mybutton();

	// Generated message map functions
protected:
	//{{AFX_MSG(mybutton)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYBUTTON_H__014A6AA9_DB9F_425D_862E_2AE48D5DDA91__INCLUDED_)
