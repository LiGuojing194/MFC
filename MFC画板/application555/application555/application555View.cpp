
// application555View.cpp : Capplication555View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// Capplication555View 构造/析构

Capplication555View::Capplication555View()
{
	// TODO:  在此处添加构造代码
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
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Capplication555View 绘制

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


	// TODO:  在此处为本机数据添加绘制代码
}


// Capplication555View 打印


void Capplication555View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Capplication555View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Capplication555View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void Capplication555View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
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


// Capplication555View 诊断

#ifdef _DEBUG
void Capplication555View::AssertValid() const
{
	CView::AssertValid();
}

void Capplication555View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Capplication555Doc* Capplication555View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Capplication555Doc)));
	return (Capplication555Doc*)m_pDocument;
}
#endif //_DEBUG


// Capplication555View 消息处理程序


void Capplication555View::OnDrawDrag()
{
	// TODO:  在此添加命令处理程序代码
	m_nSelect = ID_DRAW_DRAG;
}


void Capplication555View::OnDrawEllip()
{
	// TODO:  在此添加命令处理程序代码
	m_nSelect = ID_DRAW_ELLIP;
}


void Capplication555View::OnDrawLine()
{
	// TODO:  在此添加命令处理程序代码
	m_nSelect = ID_DRAW_LINE;
}


void Capplication555View::OnDrawPencil()
{
	// TODO:  在此添加命令处理程序代码
	m_nSelect = ID_DRAW_PENCIL;
}


void Capplication555View::OnDrawRect()
{
	// TODO:  在此添加命令处理程序代码
	m_nSelect = ID_DRAW_RECT;
}


void Capplication555View::OnUpdateDrawDrag(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	if (m_nSelect==ID_DRAW_DRAG)
		pCmdUI->SetRadio();
	else pCmdUI->SetRadio(FALSE);
}


void Capplication555View::OnUpdateDrawEllip(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	if (m_nSelect == ID_DRAW_ELLIP)
		pCmdUI->SetRadio();
	else pCmdUI->SetRadio(FALSE);
}


void Capplication555View::OnUpdateDrawLine(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	if (m_nSelect == ID_DRAW_LINE)
		pCmdUI->SetRadio();
	else pCmdUI->SetRadio(FALSE);
}


void Capplication555View::OnUpdateDrawPencil(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	if (m_nSelect == ID_DRAW_PENCIL)
		pCmdUI->SetRadio();
	else pCmdUI->SetRadio(FALSE);
}


void Capplication555View::OnUpdateDrawRect(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	if (m_nSelect == ID_DRAW_RECT)
		pCmdUI->SetRadio();
	else pCmdUI->SetRadio(FALSE);
}


void Capplication555View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
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
	// TODO:  在此添加消息处理程序代码和/或调用默认值
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
	// TODO:  在此添加消息处理程序代码和/或调用默认值
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
	// TODO:  在此添加命令处理程序代码
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
	// TODO:  在此添加命令处理程序代码
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
	// TODO:  在此添加命令处理程序代码
	if (m_nSelect != ID_DRAW_DRAG)
	{
		AfxMessageBox(_T("请先选择一个可填充的图层!"));
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
//	// TODO:  在此添加命令处理程序代码
//	CImage bmp;
//	CFileDialog saveDlg(TRUE, _T(".bmp"), _T(""), 6UL, _T("位图(*.bmp)"));
//	saveDlg.DoModal();
//	bmp.Save(saveDlg.GetPathName());
//}


void Capplication555View::OnFileSave()
{
	// TODO:  在此添加命令处理程序代码
	CClientDC dc(this);
    CRect rect;
    BOOL  showMsgTag;                  //是否要弹出”图像保存成功对话框"   
    GetClientRect(&rect);                  //获取画布大小  
    HBITMAP hbitmap = CreateCompatibleBitmap(dc, rect.right - rect.left, rect.bottom - rect.top);
    //创建兼容位图  
    HDC hdc = CreateCompatibleDC(dc);      //创建兼容DC，以便将图像保存为不同的格式  
    HBITMAP hOldMap = (HBITMAP)SelectObject(hdc, hbitmap);
    //将位图选入DC，并保存返回值   
    BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, dc, 0, 0, SRCCOPY);
    //将屏幕DC的图像复制到内存DC中  
    CImage image;
    image.Attach(hbitmap);                //将位图转化为一般图像  
    if (!saveTag)                          //如果图像是第一次被写入,则打开对话框  
    {
		saveTag = TRUE;
		showMsgTag = TRUE;
		CString  strFilter = _T("位图文件(*.bmp)|*.bmp|JPEG 图像文件|*.jpg|  GIF图像文件 | *.gif | PNG图像文件 | *.png |其他格式(*.*) | *.* || ");  
        CFileDialog dlg(FALSE, _T("bmp"), _T("iPaint1.bmp"), NULL, strFilter);
        if (dlg.DoModal() != IDOK)
            return;
        CString strFileName;          //如果用户没有指定文件扩展名，则为其添加一个  
        CString strExtension;
        strFileName = dlg.m_ofn.lpstrFile;
        if (dlg.m_ofn.nFileExtension = 0)               //扩展名项目为0  
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
        saveFilePath = strFileName;     //saveFilePath为视类中的全局变量,类型为CString  
	}
	else
	{
		showMsgTag = FALSE;
	}
    //AfxMessageBox(saveFilePath);               //显示图像保存的全路径(包含文件名)  
    HRESULT hResult = image.Save(saveFilePath);     //保存图像  
    if (FAILED(hResult))
	{
		MessageBox(_T("保存图像文件失败！"));
	}
	else
	{
		if (showMsgTag)
			MessageBox(_T("文件保存成功！"));
	}
	image.Detach();
	SelectObject(hdc, hOldMap);
}
