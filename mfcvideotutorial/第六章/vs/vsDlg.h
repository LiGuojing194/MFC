// vsDlg.h : header file
//

#if !defined(AFX_VSDLG_H__62836D16_C0BB_4D1C_9932_C78B4BA24C92__INCLUDED_)
#define AFX_VSDLG_H__62836D16_C0BB_4D1C_9932_C78B4BA24C92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CVsDlg dialog

class CVsDlg : public CDialog
{
// Construction
public:
	CVsDlg(CWnd* pParent = NULL);	// standard constructor
    CEdit m_numb;
	CEdit m_name;
	CComboBox m_combo;
	CListCtrl m_list;
// Dialog Data
	//{{AFX_DATA(CVsDlg)
	enum { IDD = IDD_VS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnMod();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VSDLG_H__62836D16_C0BB_4D1C_9932_C78B4BA24C92__INCLUDED_)
