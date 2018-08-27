// Server2Dlg.h : header file
//

#if !defined(AFX_SERVER2DLG_H__A9E2819D_1789_41FA_9E6A_0E61F024DEA6__INCLUDED_)
#define AFX_SERVER2DLG_H__A9E2819D_1789_41FA_9E6A_0E61F024DEA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CServer2Dlg dialog
#include"Listensocket.h"
class CServer2Dlg : public CDialog
{
	CListenSocket m_sock;
// Construction
public:
	CServer2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CServer2Dlg)
	enum { IDD = IDD_SERVER2_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServer2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CServer2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVER2DLG_H__A9E2819D_1789_41FA_9E6A_0E61F024DEA6__INCLUDED_)
