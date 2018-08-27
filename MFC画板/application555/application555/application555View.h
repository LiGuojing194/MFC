
// application555View.h : Capplication555View ��Ľӿ�
//

#pragma once
#include"Layer.h"
#include"Line.h"
#include"Pencil.h"
#include"Ellip.h"
#include"Width.h"
#include"Rectangle.h"


class Capplication555View : public CView
{
	int m_nSelect;
	BOOL saveTag;
	CString saveFilePath;
	CArray<CLayer*, CLayer*>m_ls;
	CPoint m_ptDrag;
	COLORREF m_clText, m_clBack;
	int m_nWidth;
	CWidth dlgWidth;
protected: // �������л�����
	Capplication555View();
	DECLARE_DYNCREATE(Capplication555View)

// ����
public:
	Capplication555Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Capplication555View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawDrag();
	afx_msg void OnDrawEllip();
	afx_msg void OnDrawLine();
	afx_msg void OnDrawPencil();
	afx_msg void OnDrawRect();
	afx_msg void OnUpdateDrawDrag(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDrawEllip(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDrawLine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDrawPencil(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDrawRect(CCmdUI *pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDrawColor();
	afx_msg void OnDrawWidth();
	afx_msg void OnDrawBush();
//	afx_msg void OnFileSave();
	afx_msg void OnFileSave();
};

#ifndef _DEBUG  // application555View.cpp �еĵ��԰汾
inline Capplication555Doc* Capplication555View::GetDocument() const
   { return reinterpret_cast<Capplication555Doc*>(m_pDocument); }
#endif

