#if !defined(AFX_DLG2_H__3C4A3F12_BDA3_4DF5_B72D_F381DA901DC5__INCLUDED_)
#define AFX_DLG2_H__3C4A3F12_BDA3_4DF5_B72D_F381DA901DC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLG2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DLG2 dialog

class DLG2 : public CDialog
{
// Construction
public:
	DLG2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DLG2)
	enum { IDD = IDD_DIALOG2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DLG2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DLG2)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG2_H__3C4A3F12_BDA3_4DF5_B72D_F381DA901DC5__INCLUDED_)
