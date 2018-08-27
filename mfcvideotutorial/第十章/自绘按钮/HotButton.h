#if !defined(AFX_HOTBUTTON_H__651E577C_4928_427D_8FAF_4D16B3530A58__INCLUDED_)
#define AFX_HOTBUTTON_H__651E577C_4928_427D_8FAF_4D16B3530A58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HotButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHotButton window

class CHotButton : public CButton
{
CBitmap m_Bitmap;//  ��ť����״̬ʱ��CBitmap����
CBitmap m_HotBitmap;//  ��ť�ȵ�״̬ʱ��CBitmap����
BOOL m_IsPressed;//��ť�Ƿ񱻰���
BOOL m_IsInRect;  //�ж�����Ƿ��ڰ�ť�����ڣ�

// Construction
public:
	CHotButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHotButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	void DetachCBitmap();
	void SetCBitmap(CBitmap*bitmap,CBitmap*Hotbitmap);
	virtual ~CHotButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CHotButton)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOTBUTTON_H__651E577C_4928_427D_8FAF_4D16B3530A58__INCLUDED_)
