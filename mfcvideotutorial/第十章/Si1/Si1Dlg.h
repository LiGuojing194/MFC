// Si1Dlg.h : header file
//

#if !defined(AFX_SI1DLG_H__2300E4B3_39F7_4048_9754_DBB178F99794__INCLUDED_)
#define AFX_SI1DLG_H__2300E4B3_39F7_4048_9754_DBB178F99794__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSi1Dlg dialog

class CSi1Dlg : public CDialog
{   
	int m_nCol;
	BOOL m_bOrder;//�������������ǽ�����
	CImageList m_hList;//��ͷ��ͼ���б�
	CImageList m_iList;//�б����ͼ���б�
// Construction
public:
	CSi1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSi1Dlg)
	enum { IDD = IDD_SI1_DIALOG };
	CComboBox	m_comb;
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSi1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSi1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnMod();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SI1DLG_H__2300E4B3_39F7_4048_9754_DBB178F99794__INCLUDED_)
