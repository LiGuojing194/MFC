// HotButton.cpp : implementation file
//

#include "stdafx.h"
#include "�Ի水ť.h"
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
	m_IsPressed=FALSE;//��ʼ��
	m_IsInRect=FALSE;//��ʼ��
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
	SetTimer(1,10,NULL);//���ö�ʱ��

	CButton::PreSubclassWindow();
}

void CHotButton::SetCBitmap(CBitmap *bitmap, CBitmap *Hotbitmap)
{
   m_Bitmap.Attach(*bitmap);//���ð�ť����״̬ʱ��CBitmap����
   m_HotBitmap.Attach(*Hotbitmap);//���ð�ť�ȵ�״̬ʱ��CBitmap����
}
//�ڸú����з���ʹ�õ�CBitmap�����

void CHotButton::OnTimer(UINT nIDEvent) 
{
    CPoint point;
	GetCursorPos(&point);//������λ��
	CRect rcWnd;//�����������
	GetWindowRect(&rcWnd);//��ð�ť����
	if(rcWnd.PtInRect (point))//�ж�����Ƿ��ڰ�ť��
	{
		if(m_IsInRect==TRUE)//�ж�����Ƿ�һֱ�ڰ�ť��
			goto END;
		else//����ƶ�����ť��
		{
		   m_IsInRect=TRUE;// ����m_IsInRect����ֵ��
		   Invalidate();//�ػ水ť��

		}
	}
	else
	{
	 if(m_IsInRect==FALSE)//�ж����һֱ�ڰ�ť�⣻
		 goto END;
	 else
	 {
	   Invalidate();//�ػ水ť
	   m_IsInRect=FALSE;//����m_IsInRect����ֵ��
	 }
	}

END:CButton::OnTimer(nIDEvent);
}

void CHotButton::DetachCBitmap()
{
   m_Bitmap.Detach();//���밴ť����״̬ʱ��CBitmap����
   m_HotBitmap.Detach();//���밴ť�ȵ�״̬ʱ��CBitmap����

}

void CHotButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	CDC dc;//�����豸������
	dc.Attach (lpDrawItemStruct->hDC);//��û��ư�ť�豸������
	UINT state=lpDrawItemStruct->itemState ;//��ȡ״̬��
	CRect rect;//�����������
	GetClientRect(rect);//��ȡ��ť�ͻ�����
	CRect focusRect(rect);//������������
	focusRect.DeflateRect (2,2,2,2);//���ý�������
	CDC memDC;//�豸������
	memDC.CreateCompatibleDC (&dc);//�����ڴ��豸�����ģ�
	if((state&ODS_SELECTED)||(state&ODS_FOCUS))//��ť��ѡ�л��ý��㣻
	{
	  memDC.SelectObject (&m_HotBitmap);
	  BITMAP m_Bmp;
	  m_HotBitmap.GetBitmap (&m_Bmp);//���λͼ��Ϣ
	  int x=m_Bmp.bmWidth ;//���λͼ�Ŀ��
	  int y=m_Bmp.bmHeight;//���λͼ�ĸ߶ȣ�
	  //����λͼ����
	  dc.StretchBlt (0,0,rect.Width(),rect.Height(),&memDC,0,0,x,y,SRCCOPY);
	  memDC.DeleteDC ();//�ͷ��ڴ��豸������
	  CBrush brush;//������ˢ��
	  brush.CreateStockObject (NULL_BRUSH);//������ˢ
	  dc.SelectObject(&brush);//����ˢѡ���豸������
	  dc.DrawFocusRect (focusRect);//���ƽ������
	  dc.DrawEdge(rect,BDR_RAISEDINNER|BDR_RAISEDOUTER,BF_BOTTOMLEFT|BF_TOPRIGHT);//��������Ч��
	  dc.Draw3dRect (rect,RGB(0,0,0),RGB(0,0,0));//��ý���ʱ���ƺ�ɫ

	}
	else
	{
	  if(m_IsInRect==TRUE)//����ڰ�ť������
	  {
	    memDC.SelectObject (&m_HotBitmap);//��λͼѡ���豸������
		BITMAP m_Bmp;//����BITMAP����
		m_HotBitmap.GetBitmap (&m_Bmp);
		int x=m_Bmp.bmWidth ;//���λͼ�Ŀ�ȣ�
		int y=m_Bmp.bmHeight ;//���λͼ�ĸ߶ȣ�
		dc.StretchBlt (0,0,rect.Width(),rect.Height (),&memDC,0,0,x,y,SRCCOPY);//����λͼ����
		memDC.DeleteDC ();//�ͷ��ڴ��豸�����ģ�
	  }
	  else
	  {
	    memDC.SelectObject (&m_Bitmap);//��λͼѡ���豸�����ģ�
		BITMAP m_Bmp;//����BITMAP����
		m_Bitmap.GetBitmap (&m_Bmp);//���λͼ��Ϣ��
			int x=m_Bmp.bmWidth ;//���λͼ�Ŀ�ȣ�
		int y=m_Bmp.bmHeight ;//���λͼ�ĸ߶ȣ�
		dc.StretchBlt (0,0,rect.Width(),rect.Height (),&memDC,0,0,x,y,SRCCOPY);//����λͼ����
		memDC.DeleteDC ();//�ͷ��ڴ��豸�����ģ�
	
	  }
	  
	}
	if(m_IsPressed)//�ڰ�ť������ʱЧ��
	{
	  dc.DrawFocusRect(focusRect);//���ƽ������
	}
}

void CHotButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_IsPressed=TRUE;//�ڰ�ť������ʱm_IsPressedֵ��ΪTRUE;
	CButton::OnLButtonDown(nFlags, point);
}

void CHotButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	m_IsPressed=FALSE;//�ڰ�ť������ʱm_IsPressedֵ��ΪFALSE;
    CButton::OnLButtonUp(nFlags, point);
}
