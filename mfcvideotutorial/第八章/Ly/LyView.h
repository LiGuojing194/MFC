// LyView.h : interface of the CLyView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LYVIEW_H__8826D119_22F7_48E6_8B48_E7584A8BBB1A__INCLUDED_)
#define AFX_LYVIEW_H__8826D119_22F7_48E6_8B48_E7584A8BBB1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include<afxtempl.h>
#include"Layer.h"

class CLyView : public CView
{//当前要绘制图层的种类
	UINT m_nType;
	CArray<CLayer*,CLayer*>m_ls;
	CPoint m_point;
protected: // create from serialization only
	CLyView();
	DECLARE_DYNCREATE(CLyView)

// Attributes
public:
	CLyDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLyView)
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
	virtual ~CLyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLyView)
	afx_msg void OnUpdateDrawDrag(CCmdUI* pCmdUI);
	afx_msg void OnDrawDrag();
	afx_msg void OnDrawLine();
	afx_msg void OnUpdateDrawLine(CCmdUI* pCmdUI);
	afx_msg void OnDrawEllip();
	afx_msg void OnUpdateDrawEllip(CCmdUI* pCmdUI);
	afx_msg void OnDrawPenc();
	afx_msg void OnUpdateDrawPenc(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LyView.cpp
inline CLyDoc* CLyView::GetDocument()
   { return (CLyDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LYVIEW_H__8826D119_22F7_48E6_8B48_E7584A8BBB1A__INCLUDED_)
