#if !defined(AFX_REGDLG_H__0A382C6B_AD95_4CF8_A0DF_702761C1348D__INCLUDED_)
#define AFX_REGDLG_H__0A382C6B_AD95_4CF8_A0DF_702761C1348D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RegDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRegDlg dialog
#include"Page1.h"
#include"Page2.h"
#include"Page3.h"

class CRegDlg : public CDialog
{
	int m_nSel;     //当前选中的页面
// Construction
public:
	void SelectPage();
	CPage1 m_p1;
	CPage2 m_p2;
	CPage3 m_p3;
	CRegDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRegDlg)
	enum { IDD = IDD_REG_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRegDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnBack();
	afx_msg void OnFinish();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGDLG_H__0A382C6B_AD95_4CF8_A0DF_702761C1348D__INCLUDED_)
