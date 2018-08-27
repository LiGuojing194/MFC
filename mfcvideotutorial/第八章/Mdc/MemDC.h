#ifndef _MEMDC_H_
#define _MEMDC_H_
//Author.www.baojy.com
class CMemDC:public CDC
{
 CSize m_size;
public:
	CMemDC()
	{
	m_size.cx=m_size.cy=0;
	}
BOOL LoadBitmap(UINT nBitmapID,CDC*pDC=NULL)
{
 //从资源中加载位图资源
	CBitmap bitmap;
	bitmap.LoadBitmap (nBitmapID);
	BITMAP bm;
	bitmap.GetBitmap (&bm);
	m_size.cx=bm.bmWidth ;
	m_size.cy=bm.bmHeight ;
	CreateCompatibleDC(pDC);
	SelectObject(bitmap);
	return TRUE;

}
CMenDC(UINT nBitmapID,CDC*pDC=NULL)
{
 //构造时加载位图资源
	LoadBitmap(nBitmapID,pDC);
}
BOOL LoadBitmap(LPCSTR szBitmapFile,CDC*pDC=NULL)
{
 //从BMP文件中加载位图
	HBITMAP hBitmap=(HBITMAP)LoadImage(AfxGetInstanceHandle(),
		szBitmapFile,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	BITMAP bm;
	GetObject(hBitmap,sizeof(bm),&bm);
	m_size.cx=bm.bmWidth;
	m_size.cy=bm.bmHeight ;
	CreateCompatibleDC(pDC);
	SelectObject(hBitmap);
	return TRUE;

}
CMemDC(LPCSTR szBitmapFile,CDC*pDC=NULL )
{
  //构造时加载位图文件
	LoadBitmap(szBitmapFile,pDC);

}
BOOL Create(int cx,int cy,CDC*pDC=NULL)
{
  //创建一张指定高宽的空白内存画布
	CBitmap bitmap;
bitmap.CreateCompatibleBitmap (pDC,cx,cy);
m_size.cx=cx;
m_size.cy=cy;
CreateCompatibleDC(pDC);
SelectObject(bitmap);
return TRUE;
}
CMemDC(int cx,int cy,CDC*pDC=NULL)
{
 //构造时创建空白内存画布
	Create(cx,cy,pDC);

}
BOOL DeleteDC()
{
  //(防止内存泄漏)销毁
	if(!GetSafeHdc())
		return TRUE;
  CBitmap*pBitmap=GetCurrentBitmap();
  pBitmap->DeleteObject ();
  return CDC::DeleteDC ();
}
~CMemDC()
{
  DeleteDC();
}
inline int Width()
{
  return m_size.cx;
}
inline int Height()
{
  return m_size.cy;
}
};
#endif //_MEMDC_H_