// myfirstMFCDlg.h : header file
//

#if !defined(AFX_MYFIRSTMFCDLG_H__5C7E69A8_17D9_46FF_971D_00FF7A9A29C7__INCLUDED_)
#define AFX_MYFIRSTMFCDLG_H__5C7E69A8_17D9_46FF_971D_00FF7A9A29C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyfirstMFCDlg dialog

class CMyfirstMFCDlg : public CDialog
{
// Construction
public:
	CMyfirstMFCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyfirstMFCDlg)
	enum { IDD = IDD_MYFIRSTMFC_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyfirstMFCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyfirstMFCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnMod();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYFIRSTMFCDLG_H__5C7E69A8_17D9_46FF_971D_00FF7A9A29C7__INCLUDED_)
