// HotButton.cpp : implementation file
//

#include "stdafx.h"
#include "自绘按钮.h"
#include "HotButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHotButton

CHotButton::CHotButton()
{
	m_IsPressed=FALSE;//初始化
	m_IsInRect=FALSE;//初始化
}

CHotButton::~CHotButton()
{
}


BEGIN_MESSAGE_MAP(CHotButton, CButton)
	//{{AFX_MSG_MAP(CHotButton)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHotButton message handlers

void CHotButton::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	SetTimer(1,10,NULL);//设置定时器

	CButton::PreSubclassWindow();
}

void CHotButton::SetCBitmap(CBitmap *bitmap, CBitmap *Hotbitmap)
{
   m_Bitmap.Attach(*bitmap);//设置按钮正常状态时的CBitmap对象；
   m_HotBitmap.Attach(*Hotbitmap);//设置按钮热点状态时的CBitmap对象；
}
//在该函数中分离使用的CBitmap类对象

void CHotButton::OnTimer(UINT nIDEvent) 
{
    CPoint point;
	GetCursorPos(&point);//获得鼠标位置
	CRect rcWnd;//声明区域对象
	GetWindowRect(&rcWnd);//获得按钮区域
	if(rcWnd.PtInRect (point))//判断鼠标是否在按钮上
	{
		if(m_IsInRect==TRUE)//判断鼠标是否一直在按钮上
			goto END;
		else//鼠标移动到按钮上
		{
		   m_IsInRect=TRUE;// 设置m_IsInRect变量值；
		   Invalidate();//重绘按钮；

		}
	}
	else
	{
	 if(m_IsInRect==FALSE)//判断鼠标一直在按钮外；
		 goto END;
	 else
	 {
	   Invalidate();//重绘按钮
	   m_IsInRect=FALSE;//设置m_IsInRect变量值；
	 }
	}

END:CButton::OnTimer(nIDEvent);
}

void CHotButton::DetachCBitmap()
{
   m_Bitmap.Detach();//分离按钮正常状态时的CBitmap对象
   m_HotBitmap.Detach();//分离按钮热点状态时的CBitmap对象；

}

void CHotButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	CDC dc;//声明设备上下文
	dc.Attach (lpDrawItemStruct->hDC);//获得绘制按钮设备上下文
	UINT state=lpDrawItemStruct->itemState ;//获取状态；
	CRect rect;//声明区域对象
	GetClientRect(rect);//获取按钮客户区域；
	CRect focusRect(rect);//声明焦点区域
	focusRect.DeflateRect (2,2,2,2);//设置焦点区域；
	CDC memDC;//设备上下文
	memDC.CreateCompatibleDC (&dc);//创建内存设备上下文；
	if((state&ODS_SELECTED)||(state&ODS_FOCUS))//按钮被选中或获得焦点；
	{
	  memDC.SelectObject (&m_HotBitmap);
	  BITMAP m_Bmp;
	  m_HotBitmap.GetBitmap (&m_Bmp);//获得位图信息
	  int x=m_Bmp.bmWidth ;//获得位图的宽度
	  int y=m_Bmp.bmHeight;//获得位图的高度；
	  //绘制位图背景
	  dc.StretchBlt (0,0,rect.Width(),rect.Height(),&memDC,0,0,x,y,SRCCOPY);
	  memDC.DeleteDC ();//释放内存设备上下文
	  CBrush brush;//声明画刷；
	  brush.CreateStockObject (NULL_BRUSH);//创建画刷
	  dc.SelectObject(&brush);//将画刷选入设备上下文
	  dc.DrawFocusRect (focusRect);//绘制焦点矩形
	  dc.DrawEdge(rect,BDR_RAISEDINNER|BDR_RAISEDOUTER,BF_BOTTOMLEFT|BF_TOPRIGHT);//绘制立体效果
	  dc.Draw3dRect (rect,RGB(0,0,0),RGB(0,0,0));//获得焦点时绘制黑色

	}
	else
	{
	  if(m_IsInRect==TRUE)//鼠标在按钮区域内
	  {
	    memDC.SelectObject (&m_HotBitmap);//将位图选入设备上下文
		BITMAP m_Bmp;//声明BITMAP对象；
		m_HotBitmap.GetBitmap (&m_Bmp);
		int x=m_Bmp.bmWidth ;//获得位图的宽度；
		int y=m_Bmp.bmHeight ;//获得位图的高度；
		dc.StretchBlt (0,0,rect.Width(),rect.Height (),&memDC,0,0,x,y,SRCCOPY);//绘制位图背景
		memDC.DeleteDC ();//释放内存设备上下文；
	  }
	  else
	  {
	    memDC.SelectObject (&m_Bitmap);//将位图选入设备上下文；
		BITMAP m_Bmp;//声明BITMAP对象
		m_Bitmap.GetBitmap (&m_Bmp);//获得位图信息；
			int x=m_Bmp.bmWidth ;//获得位图的宽度；
		int y=m_Bmp.bmHeight ;//获得位图的高度；
		dc.StretchBlt (0,0,rect.Width(),rect.Height (),&memDC,0,0,x,y,SRCCOPY);//绘制位图背景
		memDC.DeleteDC ();//释放内存设备上下文；
	
	  }
	  
	}
	if(m_IsPressed)//在按钮被按下时效果
	{
	  dc.DrawFocusRect(focusRect);//绘制焦点矩形
	}
}

void CHotButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_IsPressed=TRUE;//在按钮被按下时m_IsPressed值设为TRUE;
	CButton::OnLButtonDown(nFlags, point);
}

void CHotButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	m_IsPressed=FALSE;//在按钮被按下时m_IsPressed值设为FALSE;
    CButton::OnLButtonUp(nFlags, point);
}
