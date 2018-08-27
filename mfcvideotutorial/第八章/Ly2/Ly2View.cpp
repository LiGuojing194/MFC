// Ly2View.cpp : implementation of the CLy2View class
//

#include "stdafx.h"
#include "Ly2.h"

#include "Ly2Doc.h"
#include "Ly2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLy2View

IMPLEMENT_DYNCREATE(CLy2View, CView)

BEGIN_MESSAGE_MAP(CLy2View, CView)
	//{{AFX_MSG_MAP(CLy2View)
	ON_COMMAND(ID_DRAW_DRAG, OnDrawDrag)
	ON_UPDATE_COMMAND_UI(ID_DRAW_DRAG, OnUpdateDrawDrag)
	ON_COMMAND(ID_DRAW_ELLIP, OnDrawEllip)
	ON_UPDATE_COMMAND_UI(ID_DRAW_ELLIP, OnUpdateDrawEllip)
	ON_COMMAND(ID_DRAW_LINE, OnDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, OnUpdateDrawLine)
	ON_COMMAND(ID_DRAW_PENC, OnDrawPenc)
	ON_UPDATE_COMMAND_UI(ID_DRAW_PENC, OnUpdateDrawPenc)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_DRAW_ERASER, OnDrawEraser)
	ON_UPDATE_COMMAND_UI(ID_DRAW_ERASER, OnUpdateDrawEraser)
	ON_WM_SETCURSOR()
	ON_COMMAND(ID_RDE, OnRde)
	ON_UPDATE_COMMAND_UI(ID_RDE, OnUpdateRde)
	ON_COMMAND(ID_BLACK, OnBlack)
	ON_UPDATE_COMMAND_UI(ID_BLACK, OnUpdateBlack)
	ON_COMMAND(ID_BLUE, OnBlue)
	ON_UPDATE_COMMAND_UI(ID_BLUE, OnUpdateBlue)
	ON_COMMAND(ID_WHITE, OnWhite)
	ON_UPDATE_COMMAND_UI(ID_WHITE, OnUpdateWhite)
	ON_COMMAND(ID_YELLOW, OnYellow)
	ON_UPDATE_COMMAND_UI(ID_YELLOW, OnUpdateYellow)
	ON_COMMAND(ID_PURPLE, OnPurple)
	ON_UPDATE_COMMAND_UI(ID_PURPLE, OnUpdatePurple)
	ON_COMMAND(ID_GREEN, OnGreen)
	ON_UPDATE_COMMAND_UI(ID_GREEN, OnUpdateGreen)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLy2View construction/destruction

CLy2View::CLy2View()
{
	m_nType=ID_DRAW_DRAG;
	// TODO: add construction code here

}

CLy2View::~CLy2View()
{
}

BOOL CLy2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLy2View drawing

void CLy2View::OnDraw(CDC* pDC)
{
    CPen pn1(PS_SOLID,1,RGB(255,0,0));
	CPen pn2(PS_SOLID,1,RGB(0,0,255));
	CPen pn3(PS_SOLID,1,RGB(0,255,0));
    CPen pn4(PS_SOLID,1,RGB(255,255,0));
    CPen pn5(PS_SOLID,1,RGB(255,0,255));
    CPen pn6(PS_SOLID,1,RGB(255,255,255));
	CPen pn7(PS_SOLID,1,RGB(0,0,0));
	switch(color)//::SetCursor (AfxGetApp()->LoadCursor (IDC_CURSOR1));
	{
	case red:   	pDC->SelectObject (&pn1);break;
	case blue:   	pDC->SelectObject (&pn2);break;
	case green:   	pDC->SelectObject (&pn3);break;
	case yellow:   	pDC->SelectObject (&pn4);break;
	case purple:   	pDC->SelectObject (&pn5);break;
	case white:   	pDC->SelectObject (&pn6);break;
    case black:   	pDC->SelectObject (&pn7);break;
	}
//	if(!(m_nType==ID_DRAW_DRAG||m_nType==ID_DRAW_LINE||m_nType==ID_DRAW_ELLIP||m_nType==ID_DRAW_PENC||m_nType==ID_DRAW_ERASER))
//	   AfxMessageBox("请选择一个绘图工具后再绘图！！！");
	CLy2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	int i=0,nSize=m_ls.GetSize ();
	while(i<nSize)//谁new的对象，基类指针调用抽象函数时就会自动转入谁的派生类
	{
	   m_ls[i]->OnDraw (pDC);
	   i++;
	}
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CLy2View printing

BOOL CLy2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLy2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLy2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLy2View diagnostics

#ifdef _DEBUG
void CLy2View::AssertValid() const
{
	CView::AssertValid();
}

void CLy2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLy2Doc* CLy2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLy2Doc)));
	return (CLy2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLy2View message handlers

void CLy2View::OnDrawDrag() 
{
	// TODO: Add your command handler code here
	m_nType=ID_DRAW_DRAG;
}

void CLy2View::OnUpdateDrawDrag(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		pCmdUI->SetCheck (ID_DRAW_DRAG==m_nType);

}

void CLy2View::OnDrawEllip() 
{
	// TODO: Add your command handler code here
		m_nType=ID_DRAW_ELLIP;

}

void CLy2View::OnUpdateDrawEllip(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		pCmdUI->SetCheck (ID_DRAW_ELLIP==m_nType);

}

void CLy2View::OnDrawLine() 
{
	// TODO: Add your command handler code here
		m_nType=ID_DRAW_LINE;

}

void CLy2View::OnUpdateDrawLine(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		pCmdUI->SetCheck (ID_DRAW_LINE==m_nType);

}

void CLy2View::OnDrawPenc() 
{
	// TODO: Add your command handler code here
		m_nType=ID_DRAW_PENC;

}

void CLy2View::OnUpdateDrawPenc(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck (ID_DRAW_PENC==m_nType);
}

void CLy2View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if(!(m_nType==ID_DRAW_DRAG||m_nType==ID_DRAW_LINE||m_nType==ID_DRAW_ELLIP||m_nType==ID_DRAW_PENC||m_nType==ID_DRAW_ERASER))
	{
		AfxMessageBox("请选择一个绘图工具后再绘图！！！");
		return;
	}

	// TODO: Add your message handler code here and/or call default
		CLayer*pLayer=NULL;
	if(ID_DRAW_DRAG!=m_nType)
	{
		pLayer=CLayer::Create (m_nType);
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

void CLy2View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
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

//	CView::OnLButtonUp(nFlags, point);
}

void CLy2View::OnMouseMove(UINT nFlags, CPoint point) 
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
//	if(m_nType==ID_DRAW_ERASER)
		   // ::SetCursor (AfxGetApp()->LoadCursor (IDC_CURSOR1));

    }

void CLy2View::OnDrawEraser() 
{
	// TODO: Add your command handler code here
	m_nType=ID_DRAW_ERASER;
	//::SetCursor (AfxGetApp()->LoadCursor (IDC_CURSOR1));

}

void CLy2View::OnUpdateDrawEraser(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck (ID_DRAW_ERASER==m_nType);
}

BOOL CLy2View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	switch(m_nType)
	{
	case ID_DRAW_ERASER:   ::SetCursor (AfxGetApp()->LoadCursor (IDC_CURSOR1));
		return TRUE;
	case ID_DRAW_LINE:   ::SetCursor (AfxGetApp()->LoadCursor (IDC_CURSOR2));
		return  TRUE;
    default :   ::SetCursor(AfxGetApp()->LoadStandardCursor (IDC_ARROW));


	}

  	
	return CView::OnSetCursor(pWnd, nHitTest, message);
}

void CLy2View::OnRde() 
{
  m_nType=ID_RDE;
  color=red;
}

void CLy2View::OnUpdateRde(CCmdUI* pCmdUI) 
{
  	pCmdUI->SetCheck (ID_RDE==m_nType);
	
}

void CLy2View::OnBlack() 
{
  m_nType=ID_BLACK;
  color=black;
	
}

void CLy2View::OnUpdateBlack(CCmdUI* pCmdUI) 
{
    	pCmdUI->SetCheck (ID_BLACK==m_nType);

	
}

void CLy2View::OnBlue() 
{
  m_nType=ID_BLUE;
  color=blue;
	
}

void CLy2View::OnUpdateBlue(CCmdUI* pCmdUI) 
{
	  	pCmdUI->SetCheck (ID_BLUE==m_nType);

	
}

void CLy2View::OnWhite() 
{
	m_nType=ID_WHITE;
  color=white;
	
}

void CLy2View::OnUpdateWhite(CCmdUI* pCmdUI) 
{
	  	pCmdUI->SetCheck (ID_WHITE==m_nType);

	
}

void CLy2View::OnYellow() 
{
  m_nType=ID_YELLOW;
  color=yellow;
	
}

void CLy2View::OnUpdateYellow(CCmdUI* pCmdUI) 
{
     	pCmdUI->SetCheck (ID_YELLOW==m_nType);

	
}

void CLy2View::OnPurple() 
{
  m_nType=ID_PURPLE;
  color=purple;

	
}

void CLy2View::OnUpdatePurple(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck (ID_PURPLE==m_nType);

}

void CLy2View::OnGreen() 
{
 m_nType=ID_GREEN;
  color=green;	
	
}

void CLy2View::OnUpdateGreen(CCmdUI* pCmdUI) 
{
      	pCmdUI->SetCheck (ID_GREEN==m_nType);

}
