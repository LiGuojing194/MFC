// Ly2View.h : interface of the CLy2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LY2VIEW_H__A90BC6AF_30C1_4342_A0C4_3AD93F4F4EA6__INCLUDED_)
#define AFX_LY2VIEW_H__A90BC6AF_30C1_4342_A0C4_3AD93F4F4EA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include<afxtempl.h>
#include"Layer.h"
enum{
	red,
	green,
	blue,
	yellow,
	purple,
	white,
	black};


class CLy2View : public CView
{
    int color;
	UINT m_nType;
	CArray<CLayer*,CLayer*>m_ls;
	CPoint m_point;
protected: // create from serialization only
	CLy2View();
	DECLARE_DYNCREATE(CLy2View)

// Attributes
public:
	CLy2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLy2View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLy2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLy2View)
	afx_msg void OnDrawDrag();
	afx_msg void OnUpdateDrawDrag(CCmdUI* pCmdUI);
	afx_msg void OnDrawEllip();
	afx_msg void OnUpdateDrawEllip(CCmdUI* pCmdUI);
	afx_msg void OnDrawLine();
	afx_msg void OnUpdateDrawLine(CCmdUI* pCmdUI);
	afx_msg void OnDrawPenc();
	afx_msg void OnUpdateDrawPenc(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDrawEraser();
	afx_msg void OnUpdateDrawEraser(CCmdUI* pCmdUI);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnRde();
	afx_msg void OnUpdateRde(CCmdUI* pCmdUI);
	afx_msg void OnBlack();
	afx_msg void OnUpdateBlack(CCmdUI* pCmdUI);
	afx_msg void OnBlue();
	afx_msg void OnUpdateBlue(CCmdUI* pCmdUI);
	afx_msg void OnWhite();
	afx_msg void OnUpdateWhite(CCmdUI* pCmdUI);
	afx_msg void OnYellow();
	afx_msg void OnUpdateYellow(CCmdUI* pCmdUI);
	afx_msg void OnPurple();
	afx_msg void OnUpdatePurple(CCmdUI* pCmdUI);
	afx_msg void OnGreen();
	afx_msg void OnUpdateGreen(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ly2View.cpp
inline CLy2Doc* CLy2View::GetDocument()
   { return (CLy2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LY2VIEW_H__A90BC6AF_30C1_4342_A0C4_3AD93F4F4EA6__INCLUDED_)
