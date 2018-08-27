// BrushDlg.h : header file
//

#if !defined(AFX_BRUSHDLG_H__9B7A8044_ECBC_45B9_B578_712F641ABCF9__INCLUDED_)
#define AFX_BRUSHDLG_H__9B7A8044_ECBC_45B9_B578_712F641ABCF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBrushDlg dialog

class CBrushDlg : public CDialog
{
// Construction
public:
	CBrushDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBrushDlg)
	enum { IDD = IDD_BRUSH_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrushDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBrushDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BRUSHDLG_H__9B7A8044_ECBC_45B9_B578_712F641ABCF9__INCLUDED_)
