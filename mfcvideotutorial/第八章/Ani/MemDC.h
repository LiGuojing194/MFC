#ifndef _MEMDC_H_
#define _MEMDC_H_
//Author.www.baojy.com
class CMemDC:public CDC
{
 CSize m_size;
public:
	void BitTrans(
		int nXDest, //Ŀ�����X
		int nYDest,//Ŀ�����Y
	    int nWidthDest,  //Ŀ����
		int nHeightDest,//Ŀ��߶�
		CDC*pDC,//Ŀ��DC
		int nXSrc,   //��Դ���X
		int nYSrc,     //��Դ���Y
		COLORREF crTrans   //͸��ɫ
		)
		{
		  CMemDC dcImage(nWidthDest,nHeightDest,pDC);   //��ʱDC
		  CBitmap bmpMask;
		  bmpMask.CreateBitmap(nWidthDest,nHeightDest,1,1,NULL);//������ɫ����λͼ
		  CDC dcMask;//����DC
		  dcMask.CreateCompatibleDC(pDC);
		  dcMask.SelectObject(bmpMask);
		  //�������λͼ���Ƶ���ʱDC��
		  dcImage.BitBlt(0,0,nWidthDest,nHeightDest,this,nXSrc,nYSrc,SRCCOPY);
		  //������ʱDC��͸��ɫ
		  dcImage.SetBkColor(crTrans);
		  //����DC��͸������Ϊ��ɫ����������Ϊ��ɫ
		  dcMask.BitBlt(0,0,nWidthDest,nHeightDest,&dcImage,0,0,SRCCOPY);
		  //��ʱDC��͸������Ϊ��ɫ���������򱣳ֲ���
		  dcImage.SetBkColor(RGB(0,0,0));
		  dcImage.SetTextColor(RGB(255,255,255));
		  dcImage.BitBlt(0,0,nWidthDest,nHeightDest,&dcMask,0,0,SRCAND);
		  //Ŀ��DC��͸�����ֱ�����Ļ���䣬�������ֱ�ɺ�ɫ
		  pDC->SetBkColor(RGB(255,255,255));
		  pDC->SetTextColor(RGB(0,0,0));
		  pDC->BitBlt(nXDest,nYDest,nWidthDest,nHeightDest,&dcMask,0,0,SRCAND);
		  pDC->BitBlt(nXDest,nYDest,nWidthDest,nHeightDest,&dcImage,0,0,SRCPAINT);

		}
		void StretchTrans(
			int nXDest,         //Ŀ�����X
		    int nYDest,         //Ŀ�����Y
			int nWidthDest,     //Ŀ����
			int nHeightDest,        //Ŀ��߶�
		    CDC* pDC,            //Ŀ��DC
			int nXSrc,           //��Դ���X
			int nYSrc,            //��Դ���Y
			int nWidthSrc,         //��Դ���
			int nHeightSrc,        //��Դ�߶�
			COLORREF crTrans      //͸��ɫ
			)
		{
		  CMemDC dcImage(nWidthDest,nHeightDest,pDC);         //��ʱDC
		  CBitmap bmpMask;
		  //������ɫ����λͼ��
		  bmpMask.CreateBitmap(nWidthDest,nHeightDest,1,1,NULL);
		  CDC dcMask;
		  dcMask.CreateCompatibleDC(pDC);
		  dcMask.SelectObject (bmpMask);
		  //�������λͼ���Ƶ���ʱDC��
		  if(nWidthDest==nWidthSrc&&nHeightDest==nHeightSrc)
			  dcImage.BitBlt(0,0,nWidthDest,nHeightDest,this,nXSrc,nYSrc,SRCCOPY);
		  else
			 dcImage.StretchBlt(0,0,nWidthDest,nHeightDest,this,nXSrc,nYSrc,nWidthSrc,nHeightSrc,SRCCOPY);
		  //������ʱDC��͸��ɫ
		  dcImage.SetBkColor(crTrans);
		  //����DC��͸������Ϊ��ɫ����������Ϊ��ɫ
		  dcMask.BitBlt (0,0,nWidthDest,nHeightDest,&dcImage,0,0,SRCCOPY);
		  //Ŀ��DC��͸�����ֱ�����Ļ���䣬�������ֱ�ɺ�ɫ
		  pDC->SetBkColor (RGB(255,255,255));
		  pDC->SetTextColor(RGB(0,0,0));
		  pDC->BitBlt (nXDest,nYDest,nWidthDest,nHeightDest,&dcMask,0,0,SRCAND);
		  pDC->BitBlt (nXDest,nYDest,nWidthDest,nHeightDest,&dcImage,0,0,SRCPAINT);

		
		
		
		}



	CMemDC()
	{
	m_size.cx=m_size.cy=0;
	}
BOOL LoadBitmap(UINT nBitmapID,CDC*pDC=NULL)
{
 //����Դ�м���λͼ��Դ
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
 //����ʱ����λͼ��Դ
	LoadBitmap(nBitmapID,pDC);
}
BOOL LoadBitmap(LPCSTR szBitmapFile,CDC*pDC=NULL)
{
 //��BMP�ļ��м���λͼ
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
  //����ʱ����λͼ�ļ�
	LoadBitmap(szBitmapFile,pDC);

}
BOOL Create(int cx,int cy,CDC*pDC=NULL)
{
  //����һ��ָ���߿�Ŀհ��ڴ滭��
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
 //����ʱ�����հ��ڴ滭��
	Create(cx,cy,pDC);

}
BOOL DeleteDC()
{
  //(��ֹ�ڴ�й©)����
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
