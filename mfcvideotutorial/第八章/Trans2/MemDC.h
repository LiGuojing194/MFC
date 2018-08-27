#ifndef __MEMDC_H__
#define __MEMDC_H__
//Author:www.baojy.com

class CMemDC :public CDC
{
	CSize m_size;
public:
	void BitRgn(
		CRgn &rgn,			//目标区域
		COLORREF crTrans	// 透明色
		)
	{
		int i = 0,j=0;
		rgn.CreateRectRgn(0,0,0,0);
		while(i<m_size.cx)
		{
			j = 0;
			while(j<m_size.cy)
			{
				if(GetPixel(i,j) - crTrans)
				{
					CRgn r;
					r.CreateRectRgn(i,j,i+1,j+1);
					rgn.CombineRgn(&rgn,&r,RGN_OR);
				}
				++j;
			}
			++i;
		}
	}
	void BitTrans(
		int nXDest,		// 目标起点X
        int nYDest,		// 目标起点Y
        int nWidthDest,	// 目标宽度
        int nHeightDest,// 目标高度
		CDC* pDC,		// 目标DC
        int nXSrc,		// 来源起点X
        int nYSrc,		// 来源起点Y
        COLORREF crTrans// 透明色
        )
	{
		CMemDC dcImage(nWidthDest, nHeightDest,pDC);//临时DC
		CBitmap bmpMask;
		bmpMask.CreateBitmap(nWidthDest, nHeightDest, 1, 1, NULL);            // 创建单色掩码位图
		CDC dcMask;//掩码DC 
		dcMask.CreateCompatibleDC(pDC);
		dcMask.SelectObject(bmpMask);
		//将载入位图的内存DC中的位图，拷贝到临时DC中
		dcImage.BitBlt( 0, 0, nWidthDest, nHeightDest, this, nXSrc, nYSrc, SRCCOPY);
		
		// 设置临时DC的透明色
		dcImage.SetBkColor(crTrans);
		//掩码DC的透明区域为白色其它区域为黑色
		dcMask.BitBlt(0, 0, nWidthDest, nHeightDest, &dcImage, 0, 0, SRCCOPY);
		
		//临时DC透明区域为黑色，其它区域保持不变
		dcImage.SetBkColor(RGB(0,0,0));
		dcImage.SetTextColor(RGB(255,255,255));
		dcImage.BitBlt( 0, 0, nWidthDest, nHeightDest, &dcMask, 0, 0, SRCAND);
		
		// 目标DC透明部分保持屏幕不变，其它部分变成黑色
		pDC ->SetBkColor(RGB(255,255,255));
		pDC ->SetTextColor(RGB(0,0,0));
		pDC ->BitBlt(nXDest, nYDest, nWidthDest, nHeightDest, &dcMask, 0, 0, SRCAND);
		pDC ->BitBlt(nXDest, nYDest, nWidthDest, nHeightDest, &dcImage, 0, 0, SRCPAINT);
	} 
	void StretchTrans(
		int nXDest,			// 目标起点X
		int nYDest,			// 目标起点Y
		int nWidthDest,     // 目标宽度
		int nHeightDest,    // 目标高度
		CDC* pDC,			// 目标DC
		int nXSrc,			// 来源起点X
		int nYSrc,			// 来源起点Y
		int nWidthSrc,		// 来源宽度
		int nHeightSrc,		// 来源高度
		COLORREF crTrans	// 透明色
		)
	{
		CMemDC dcImage(nWidthDest, nHeightDest,pDC);//临时DC
		CBitmap bmpMask;
		// 创建单色掩码位图
		bmpMask.CreateBitmap(nWidthDest, nHeightDest, 1, 1, NULL);
		CDC dcMask;
		dcMask.CreateCompatibleDC(pDC);
		dcMask.SelectObject(bmpMask);
	
		// 将载入位图的内存DC中的位图，拷贝到临时DC中
		if (nWidthDest == nWidthSrc && nHeightDest == nHeightSrc)
			dcImage.BitBlt(0, 0, nWidthDest, nHeightDest, this, nXSrc, nYSrc, SRCCOPY);
		else
			dcImage.StretchBlt(0, 0, nWidthDest, nHeightDest, 
				this, nXSrc, nYSrc, nWidthSrc, nHeightSrc, SRCCOPY);
		
		// 设置临时DC的透明色
		dcImage.SetBkColor( crTrans);
		//掩码DC的透明区域为白色其它区域为黑色
		dcMask.BitBlt(0,0,nWidthDest, nHeightDest,&dcImage,0,0,SRCCOPY);
		
		//临时DC透明区域为黑色，其它区域保持不变
		dcImage.SetBkColor(RGB(0,0,0));
		dcImage.SetTextColor(RGB(255,255,255));
		dcImage.BitBlt(0, 0, nWidthDest, nHeightDest, &dcMask, 0, 0, SRCAND);
		
		// 目标DC透明部分保持屏幕不变，其它部分变成黑色
		pDC ->SetBkColor(RGB(255,255,255));
		pDC ->SetTextColor(RGB(0,0,0));
		pDC ->BitBlt(nXDest, nYDest, nWidthDest, nHeightDest, &dcMask, 0, 0, SRCAND);
		pDC ->BitBlt(nXDest, nYDest, nWidthDest, nHeightDest, &dcImage, 0, 0, SRCPAINT);
	}	
	CMemDC()
	{
		m_size.cx = m_size.cy = 0;
	}
	//从资源中加载位图
	BOOL LoadBitmap(UINT nBitmapID,CDC* pDC=NULL)
	{
		CBitmap bitmap;
		bitmap.LoadBitmap(nBitmapID);
		BITMAP bm;
		bitmap.GetBitmap(&bm);
		m_size.cx = bm.bmWidth;
		m_size.cy = bm.bmHeight;
		CreateCompatibleDC(pDC);
		SelectObject(bitmap);
		return TRUE;
	}
	CMemDC(UINT nBitmapID,CDC* pDC=NULL)
	{
		LoadBitmap(nBitmapID,pDC);
	}
	//从.bmp文件中加载位图
	BOOL LoadBitmap(LPCSTR szBitmapFile,CDC* pDC=NULL)
	{
		HBITMAP hBitmap = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
			szBitmapFile,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		BITMAP bm;
		GetObject(hBitmap,sizeof(bm),&bm);
		m_size.cx = bm.bmWidth;
		m_size.cy = bm.bmHeight;
		CreateCompatibleDC(pDC);
		SelectObject(hBitmap);		
		return TRUE;
	}
	CMemDC(LPCSTR szBitmapFile,CDC* pDC=NULL)
	{
		LoadBitmap(szBitmapFile,pDC);
	}
	//创建一张空白内存画布
	BOOL Create(int cx,int cy,CDC* pDC = NULL)
	{
		CreateCompatibleDC(pDC);
		CBitmap bitmap;
		if(pDC)
			bitmap.CreateCompatibleBitmap(pDC,cx,cy);
		else
			bitmap.CreateCompatibleBitmap(&CClientDC(NULL),cx,cy);
		m_size.cx = cx;
		m_size.cy = cy;
		SelectObject(bitmap);
		return TRUE;
	}
	CMemDC(int cx,int cy,CDC* pDC = NULL)
	{
		Create(cx,cy,pDC);
	}
	//摧毁
	BOOL DeleteDC()
	{
		if(!GetSafeHdc())
			return TRUE;
		CBitmap * pBitmap = GetCurrentBitmap();
		pBitmap ->DeleteObject();
		return CDC::DeleteDC();
	}
	~CMemDC()
	{
		DeleteDC();
	}
	inline int Width(){return m_size.cx;}
	inline int Height(){return m_size.cy;}
};

#endif //__MEMDC_H__