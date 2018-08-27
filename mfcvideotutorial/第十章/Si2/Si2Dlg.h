// Si2Dlg.h : header file
//

#if !defined(AFX_SI2DLG_H__243B8068_3477_4B01_A900_6D490B0CE970__INCLUDED_)
#define AFX_SI2DLG_H__243B8068_3477_4B01_A900_6D490B0CE970__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSi2Dlg dialog

class CSi2Dlg : public CDialog
{
// Construction
public:
	CSi2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSi2Dlg)
	enum { IDD = IDD_SI2_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSi2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSi2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SI2DLG_H__243B8068_3477_4B01_A900_6D490B0CE970__INCLUDED_)
