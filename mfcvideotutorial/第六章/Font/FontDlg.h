// FontDlg.h : header file
//

#if !defined(AFX_FONTDLG_H__7B2AD84A_9971_46FF_818D_47AAA7BB7471__INCLUDED_)
#define AFX_FONTDLG_H__7B2AD84A_9971_46FF_818D_47AAA7BB7471__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFontDlg dialog

class CFontDlg : public CDialog
{
// Construction
public:
	CFontDlg(CWnd* pParent = NULL);	// standard constructor
    void CreateFont(CDC*pDC);
	void SetColors(CDC*pDC);
	void Others(CDC*pDC,CFont*pFont);
	void Width(CDC*pDC,CFont*pFont);
	void Weight(CDC*pDC,CFont*pFont);
	void Escape(CDC*pDC,CFont*pFont);
	void Height(CDC*pDC,CFont*pFont);
	void Normal(CDC*pDC,CFont*pFont);
// Dialog Data
	//{{AFX_DATA(CFontDlg)
	enum { IDD = IDD_FONT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFontDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONTDLG_H__7B2AD84A_9971_46FF_818D_47AAA7BB7471__INCLUDED_)
