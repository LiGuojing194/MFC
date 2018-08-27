
// application555View.cpp : Capplication555View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "application555.h"
#endif

#include "application555Doc.h"
#include "application555View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Capplication555View

IMPLEMENT_DYNCREATE(Capplication555View, CView)

BEGIN_MESSAGE_MAP(Capplication555View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Capplication555View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DRAW_DRAG, &Capplication555View::OnDrawDrag)
	ON_COMMAND(ID_DRAW_ELLIP, &Capplication555View::OnDrawEllip)
	ON_COMMAND(ID_DRAW_LINE, &Capplication555View::OnDrawLine)
	ON_COMMAND(ID_DRAW_PENCIL, &Capplication555View::OnDrawPencil)
	ON_COMMAND(ID_DRAW_RECT, &Capplication555View::OnDrawRect)
	ON_UPDATE_COMMAND_UI(ID_DRAW_DRAG, &Capplication555View::OnUpdateDrawDrag)
	ON_UPDATE_COMMAND_UI(ID_DRAW_ELLIP, &Capplication555View::OnUpdateDrawEllip)
	ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, &Capplication555View::OnUpdateDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_PENCIL, &Capplication555View::OnUpdateDrawPencil)
	ON_UPDATE_COMMAND_UI(ID_DRAW_RECT, &Capplication555View::OnUpdateDrawRect)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_DRAW_COLOR, &Capplication555View::OnDrawColor)
	ON_COMMAND(ID_DRAW_WIDTH, &Capplication555View::OnDrawWidth)
	ON_COMMAND(ID_DRAW_BUSH, &Capplication555View::OnDrawBush)
//	ON_COMMAND(ID_FILE_SAVE, &Capplication555View::OnFileSave)
ON_COMMAND(ID_FILE_SAVE, &Capplication555View::OnFileSave)
END_MESSAGE_MAP()

// Capplication555View ����/����

Capplication555View::Capplication555View()
{
	// TODO:  �ڴ˴���ӹ������
	m_nSelect = ID_DRAW_PENCIL;
	m_clText = 0;
	m_clBack = 0xfffffff;
	m_nWidth = 2;
	saveTag = FALSE;

}

Capplication555View::~Capplication555View()
{
}

BOOL Capplication555View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Capplication555View ����

void Capplication555View::OnDraw(CDC* pDC)
{
	Capplication555Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int i = 0, nSize = m_ls.GetSize();
	CLayer*pLayer = NULL;
	while (i < nSize)
	{
		pLayer = m_ls[i++];
		pLayer->OnDraw(pDC);


	}


	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Capplication555View ��ӡ


void Capplication555View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Capplication555View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Capplication555View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Capplication555View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}

void Capplication555View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Capplication555View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Capplication555View ���

#ifdef _DEBUG
void Capplication555View::AssertValid() const
{
	CView::AssertValid();
}

void Capplication555View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Capplication555Doc* Capplication555View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Capplication555Doc)));
	return (Capplication555Doc*)m_pDocument;
}
#endif //_DEBUG


// Capplication555View ��Ϣ�������


void Capplication555View::OnDrawDrag()
{
	// TODO:  �ڴ���������������
	m_nSelect = ID_DRAW_DRAG;
}


void Capplication555View::OnDrawEllip()
{
	// TODO:  �ڴ���������������
	m_nSelect = ID_DRAW_ELLIP;
}


void Capplication555View::OnDrawLine()
{
	// TODO:  �ڴ���������������
	m_nSelect = ID_DRAW_LINE;
}


void Capplication555View::OnDrawPencil()
{
	// TODO:  �ڴ���������������
	m_nSelect = ID_DRAW_PENCIL;
}


void Capplication555View::OnDrawRect()
{
	// TODO:  �ڴ���������������
	m_nSelect = ID_DRAW_RECT;
}


void Capplication555View::OnUpdateDrawDrag(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	if (m_nSelect==ID_DRAW_DRAG)
		pCmdUI->SetRadio();
	else pCmdUI->SetRadio(FALSE);
}


void Capplication555View::OnUpdateDrawEllip(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	if (m_nSelect == ID_DRAW_ELLIP)
		pCmdUI->SetRadio();
	else pCmdUI->SetRadio(FALSE);
}


void Capplication555View::OnUpdateDrawLine(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	if (m_nSelect == ID_DRAW_LINE)
		pCmdUI->SetRadio();
	else pCmdUI->SetRadio(FALSE);
}


void Capplication555View::OnUpdateDrawPencil(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	if (m_nSelect == ID_DRAW_PENCIL)
		pCmdUI->SetRadio();
	else pCmdUI->SetRadio(FALSE);
}


void Capplication555View::OnUpdateDrawRect(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	if (m_nSelect == ID_DRAW_RECT)
		pCmdUI->SetRadio();
	else pCmdUI->SetRadio(FALSE);
}


void Capplication555View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CLayer *pLayer = NULL;
	if (m_nSelect == ID_DRAW_DRAG)
	{
		int i = 0, nSize = m_ls.GetSize();
		while (i < nSize)
		{
			pLayer = m_ls[i++];
			/*if (pLayer->Track(point))
			{
				pLayer->m_nStatus = STU_SELECT;
			}*/
			pLayer->m_nStatus = pLayer->Track(point);
		}
		m_ptDrag = point;
		Invalidate(TRUE);
		return;
	}
	switch (m_nSelect)
	{
	case ID_DRAW_LINE: pLayer = new CLine; break;
	case ID_DRAW_ELLIP: pLayer = new CEllip; break;
	case ID_DRAW_PENCIL: pLayer = new CPencil; break;
	case ID_DRAW_RECT: pLayer = new CRectangle; break;
	}
	if (pLayer)
	{
		pLayer->m_clText = m_clText;
		pLayer->m_clBack = m_clBack;
		pLayer->m_nWidth = m_nWidth;
		m_ls.Add(pLayer);
		pLayer->OnLButtonDown(nFlags, point);
		//pDoc->m_ls.Add(pLayer);
		//pDoc->SetModifiedFlag();
	}
	//Invalidate(TRUE);
	
	CView::OnLButtonDown(nFlags, point);
}


void Capplication555View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//Capplication555Doc*pDoc = GetDocument();
	int nSize = m_ls.GetSize();
	if (!nSize)
		return;
	CLayer*pLayer = NULL;
	if (m_nSelect == ID_DRAW_DRAG)
	{
		int i = 0;
		int cx = point.x - m_ptDrag.x;
		int cy = point.y - m_ptDrag.y;
		while (i < nSize)
		{
			pLayer = m_ls[i++];
			if (pLayer->m_nStatus == STU_SELECT)
			{
				pLayer->OffSet(cx, cy);
				//pDoc->SetModifiedFlag();
			}

		}
		Invalidate(TRUE);
		return;
	}
	pLayer = m_ls[nSize - 1];
	pLayer->OnLButtonUp(nFlags,point);
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void Capplication555View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//Capplication555Doc*pDoc = GetDocument();
	int nSize = m_ls.GetSize();
	if (!nSize)
		return;
	//CLayer*pLayer = m_ls[nSize - 1];
	CLayer*pLayer = NULL;
	if (m_nSelect == ID_DRAW_DRAG)
	{
		int i = 0;
		while (i < nSize)
		{
			pLayer = m_ls[i++];
			if (pLayer->Track(point))
			{
				SetCursor(AfxGetApp()->LoadStandardCursor(IDC_SIZEALL));
			}
		}
		return;
	}
	pLayer = m_ls[nSize - 1];
	CClientDC dc(this);
	CPen pen(PS_SOLID, m_nWidth, m_clText);
	CPen*pPen = dc.SelectObject(&pen);
	pLayer->OnMouseMove(nFlags, point,&dc);
	dc.SelectObject(pPen);
	//Invalidate(TRUE);
	CView::OnMouseMove(nFlags, point);
}


void Capplication555View::OnDrawColor()
{
	// TODO:  �ڴ���������������
	CColorDialog dlg;
	if (IDCANCEL == dlg.DoModal())
		return;
	CLayer*pLayer = NULL;
	int i = 0, nSize = m_ls.GetSize();
	COLORREF cl = dlg.GetColor();
	while (i < nSize)
	{
		pLayer = m_ls[i++];
		if (STU_SELECT == pLayer->m_nStatus)
			pLayer->m_clText = cl;
	}
	m_clText = cl;
	Invalidate();
}


void Capplication555View::OnDrawWidth()
{
	// TODO:  �ڴ���������������
	if(IDCANCEL == dlgWidth.DoModal())
	{
		return;
	}
	CLayer*pLayer = NULL;
	int i = 0, nSize = m_ls.GetSize();
	int width = dlgWidth.GetWidth();
	while (i < nSize)
	{
		pLayer = m_ls[i++];
		if (STU_SELECT == pLayer->m_nStatus)
			pLayer->m_nWidth = width;
	}
	m_nWidth = width;
	Invalidate();
}


void Capplication555View::OnDrawBush()
{
	// TODO:  �ڴ���������������
	if (m_nSelect != ID_DRAW_DRAG)
	{
		AfxMessageBox(_T("����ѡ��һ��������ͼ��!"));
		return;
	}
	CColorDialog dlg;
	if (IDCANCEL == dlg.DoModal())
		return;
	CLayer*pLayer = NULL;
	int i = 0, nSize = m_ls.GetSize();
	COLORREF cl = dlg.GetColor();
	while (i < nSize)
	{
		pLayer = m_ls[i++];
		if (STU_SELECT == pLayer->m_nStatus)
			pLayer->m_clBack = cl;
	}
	//m_clBack = cl;
	Invalidate();
}


//void Capplication555View::OnFileSave()
//{
//	// TODO:  �ڴ���������������
//	CImage bmp;
//	CFileDialog saveDlg(TRUE, _T(".bmp"), _T(""), 6UL, _T("λͼ(*.bmp)"));
//	saveDlg.DoModal();
//	bmp.Save(saveDlg.GetPathName());
//}


void Capplication555View::OnFileSave()
{
	// TODO:  �ڴ���������������
	CClientDC dc(this);
    CRect rect;
    BOOL  showMsgTag;                  //�Ƿ�Ҫ������ͼ�񱣴�ɹ��Ի���"   
    GetClientRect(&rect);                  //��ȡ������С  
    HBITMAP hbitmap = CreateCompatibleBitmap(dc, rect.right - rect.left, rect.bottom - rect.top);
    //��������λͼ  
    HDC hdc = CreateCompatibleDC(dc);      //��������DC���Ա㽫ͼ�񱣴�Ϊ��ͬ�ĸ�ʽ  
    HBITMAP hOldMap = (HBITMAP)SelectObject(hdc, hbitmap);
    //��λͼѡ��DC�������淵��ֵ   
    BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, dc, 0, 0, SRCCOPY);
    //����ĻDC��ͼ���Ƶ��ڴ�DC��  
    CImage image;
    image.Attach(hbitmap);                //��λͼת��Ϊһ��ͼ��  
    if (!saveTag)                          //���ͼ���ǵ�һ�α�д��,��򿪶Ի���  
    {
		saveTag = TRUE;
		showMsgTag = TRUE;
		CString  strFilter = _T("λͼ�ļ�(*.bmp)|*.bmp|JPEG ͼ���ļ�|*.jpg|  GIFͼ���ļ� | *.gif | PNGͼ���ļ� | *.png |������ʽ(*.*) | *.* || ");  
        CFileDialog dlg(FALSE, _T("bmp"), _T("iPaint1.bmp"), NULL, strFilter);
        if (dlg.DoModal() != IDOK)
            return;
        CString strFileName;          //����û�û��ָ���ļ���չ������Ϊ�����һ��  
        CString strExtension;
        strFileName = dlg.m_ofn.lpstrFile;
        if (dlg.m_ofn.nFileExtension = 0)               //��չ����ĿΪ0  
        {
          switch (dlg.m_ofn.nFilterIndex)
		  {
		  case 1: strExtension = "bmp"; break;
		  case 2: strExtension = "jpg"; break;
          case 3: strExtension = "gif"; break;
          case 4: strExtension = "png"; break;
		  default: break;
		  }
		  strFileName = strFileName + "." + strExtension;
		}
        saveFilePath = strFileName;     //saveFilePathΪ�����е�ȫ�ֱ���,����ΪCString  
	}
	else
	{
		showMsgTag = FALSE;
	}
    //AfxMessageBox(saveFilePath);               //��ʾͼ�񱣴��ȫ·��(�����ļ���)  
    HRESULT hResult = image.Save(saveFilePath);     //����ͼ��  
    if (FAILED(hResult))
	{
		MessageBox(_T("����ͼ���ļ�ʧ�ܣ�"));
	}
	else
	{
		if (showMsgTag)
			MessageBox(_T("�ļ�����ɹ���"));
	}
	image.Detach();
	SelectObject(hdc, hOldMap);
}
