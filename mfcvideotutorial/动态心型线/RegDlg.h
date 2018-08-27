#if !defined(AFX_REGDLG_H__CDFDB78D_AA37_4EDF_A117_C50D07E4D1D7__INCLUDED_)
#define AFX_REGDLG_H__CDFDB78D_AA37_4EDF_A117_C50D07E4D1D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RegDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRegDlg dialog
#include"Page1.h"
#include"Page2.h"
#include"MemDC.h"
class CRegDlg : public CDialog
{
	int i;
	CMemDC m_dc1;
	int m_nSel;
// Construction
public:
	CMemDC m_dcBack1;
	CMemDC m_dcMem1;
	void SelectPage();
	CPage1 m_p1;
	CPage2 m_p2;

	CRegDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRegDlg)
	enum { IDD = IDD_DIALOG3 };
	CButton	m_open;
	CButton	m_yu4;
	CButton	m_yu3;
	CButton	m_yu2;
	CButton	m_yu1;
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
	afx_msg void OnBack();
	virtual void OnOK();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnButton5();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGDLG_H__CDFDB78D_AA37_4EDF_A117_C50D07E4D1D7__INCLUDED_)
