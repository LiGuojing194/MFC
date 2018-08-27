// LyView.cpp : implementation of the CLyView class
//

#include "stdafx.h"
#include "Ly.h"

#include "LyDoc.h"
#include "LyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLyView

IMPLEMENT_DYNCREATE(CLyView, CView)

BEGIN_MESSAGE_MAP(CLyView, CView)
//{{AFX_MSG_MAP(CLyView)
ON_UPDATE_COMMAND_UI(ID_DRAW_DRAG, OnUpdateDrawDrag)
ON_COMMAND(ID_DRAW_DRAG, OnDrawDrag)
ON_COMMAND(ID_DRAW_LINE, OnDrawLine)
ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, OnUpdateDrawLine)
ON_COMMAND(ID_DRAW_ELLIP, OnDrawEllip)
ON_UPDATE_COMMAND_UI(ID_DRAW_ELLIP, OnUpdateDrawEllip)
ON_COMMAND(ID_DRAW_PENC, OnDrawPenc)
ON_UPDATE_COMMAND_UI(ID_DRAW_PENC, OnUpdateDrawPenc)
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_WM_MOUSEMOVE()
//}}AFX_MSG_MAP
// Standard printing commands
ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLyView construction/destruction

CLyView::CLyView()
{
	//默认图层类型
	m_nType=ID_DRAW_DRAG;
	// TODO: add construction code here
	
}

CLyView::~CLyView()
{
}

BOOL CLyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLyView drawing

void CLyView::OnDraw(CDC* pDC)
{//在视图类中，OnDraw函数是WM_PAINT消息的回调函数
	CLyDoc*pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	int i=0,nSize=m_ls.GetSize ();
	while(i<nSize)
	{
		m_ls[i]->OnDraw (pDC);
		i++;
	}
	//	CLyDoc* pDoc = GetDocument();
	//	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CLyView printing

BOOL CLyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLyView diagnostics

#ifdef _DEBUG
void CLyView::AssertValid() const
{
	CView::AssertValid();
}

void CLyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLyDoc* CLyView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLyDoc)));
	return (CLyDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLyView message handlers

void CLyView::OnUpdateDrawDrag(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(ID_DRAW_DRAG==m_nType);	
}

void CLyView::OnDrawDrag() 
{
	m_nType=ID_DRAW_DRAG;	
}

void CLyView::OnDrawLine() 
{
	m_nType=ID_DRAW_LINE;	
	
	
}

void CLyView::OnUpdateDrawLine(CCmdUI* pCmdUI) 
{
    pCmdUI->SetCheck(ID_DRAW_LINE==m_nType);	
	
	
}

void CLyView::OnDrawEllip() 
{
    m_nType=ID_DRAW_ELLIP;	
	
	
}

void CLyView::OnUpdateDrawEllip(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(ID_DRAW_ELLIP==m_nType);	
	
	
}

void CLyView::OnDrawPenc() 
{
    m_nType=ID_DRAW_PENC;	
	
	
}

void CLyView::OnUpdateDrawPenc(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(ID_DRAW_PENC==m_nType);	
	
}

void CLyView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CLayer*pLayer=NULL;
	if(ID_DRAW_DRAG!=m_nType)
	{
		pLayer->OnLButtonDown (nFlags,point);
		m_ls.Add(pLayer);
		return;
	}
	int i=0;
	while(i<m_ls.GetSize ())
	{
		pLayer=(CLayer*)m_ls[i];
		pLayer->Select (point);
		i++;
	}
	Invalidate();
	m_point=point;
	
	//	CView::OnLButtonDown(nFlags, point);
}

void CLyView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	int nSize=m_ls.GetSize ();
	if(!nSize)
		return;
	CLayer*pLayer=NULL;
	if(ID_DRAW_DRAG!=m_nType)
	{
		pLayer=m_ls[nSize-1];
		pLayer->OnLButtonUp(nFlags,point);
		if(STU_DRAWING==pLayer->m_nStatus)
			pLayer->m_nStatus =STU_NORMAL;
	}
	else
	{//完成图层拖放
		int i=0;
		while(i<nSize)
		{
			pLayer=m_ls[i];
			if(STU_SELECT==pLayer->m_nStatus )
				pLayer->Offset(point.x-m_point.x ,point.y-m_point.y );
			++i;
		}
		
	}
	Invalidate();
	//CView::OnLButtonUp(nFlags, point);
}

void CLyView::OnMouseMove(UINT nFlags, CPoint point) 
{
	int nSize=m_ls.GetSize();
	if(!nSize)
		return;
	CLayer*pLayer=NULL;
	if(ID_DRAW_DRAG!=m_nType)
	{//新绘制图层鼠标光标移动过程使用临时DC避免画面频繁更新
		CClientDC dc(this);
		pLayer=(CLayer*)m_ls[nSize-1];
		pLayer->OnMouseMove (nFlags,point,&dc);
		return;
	}
	//光标掠过某个图层表面显示为即将开始拖动的状态
	while(nSize--)
	{
		if(m_ls[nSize]->Track (point))
		{
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_SIZEALL));
			break;
		}
	}
    
	
	//	CView::OnMouseMove(nFlags, point);
}
