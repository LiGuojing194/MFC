// cDlg.h : header file
//

#if !defined(AFX_CDLG_H__614C41B8_2925_4C0F_A9CA_73007CC74282__INCLUDED_)
#define AFX_CDLG_H__614C41B8_2925_4C0F_A9CA_73007CC74282__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCDlg dialog
struct SData
{
  int nNumb;
  char sName[20];
  float fSala;
};
enum
{
  INF_ADD=0x1234,
	  INF_BROW,
	  INF_DEL,
	  INF_MOD,
	  INF_FIND
};
class CCDlg : public CDialog
{
	CSocket m_sock;
// Construction
public:
	void OnRefresh();
	CCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCDlg)
	enum { IDD = IDD_C_DIALOG };
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CDLG_H__614C41B8_2925_4C0F_A9CA_73007CC74282__INCLUDED_)
