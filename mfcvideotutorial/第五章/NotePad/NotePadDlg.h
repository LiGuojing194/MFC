// NotePadDlg.h : header file
//

#if !defined(AFX_NOTEPADDLG_H__44B304B9_91B8_4DB8_8501_FAA102230C81__INCLUDED_)
#define AFX_NOTEPADDLG_H__44B304B9_91B8_4DB8_8501_FAA102230C81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNotePadDlg dialog

class CNotePadDlg : public CDialog
{
// Construction
public:
	CNotePadDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNotePadDlg)
	enum { IDD = IDD_NOTEPAD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNotePadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNotePadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnClose();
	afx_msg void OnFileExit();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOTEPADDLG_H__44B304B9_91B8_4DB8_8501_FAA102230C81__INCLUDED_)
