// Layer.h: interface for the CLayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAYER_H__7F37B6D3_7E8D_4E57_B661_993320CE8255__INCLUDED_)
#define AFX_LAYER_H__7F37B6D3_7E8D_4E57_B661_993320CE8255__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
enum{
STU_DRAWING,  //����״̬
STU_NORMAL,  //��ͨ״̬
STU_SELECT};  //��ͼ��ѡ�е�״̬
class CLayer  
{//���麯��û�нṹ�壬�ԡ�=0����־���棻���д��麯������г�����
public:
	int m_nStatus;
	static CLayer*Create(int nType);
	//��꼰��ʾ�¼�����
	virtual void OnLButtonDown(UINT nFlags,CPoint point)=0;
	virtual void OnMouseMove(UINT nFlags,CPoint point,CDC*pDC=NULL)=0;
	virtual void OnLButtonUp(UINT nFlags,CPoint point, CDC*pDC=NULL)=0;
	virtual void OnDraw(CDC*pDC)=0;
    //ͼ���϶����̣�ѡ��ƽ�ƺ͸���
	virtual void Select(CPoint point)=0;
	virtual void Offset(int x,int y)=0;
	virtual BOOL Track(CPoint point)=0;

	CLayer();
	virtual ~CLayer();

};

#endif // !defined(AFX_LAYER_H__7F37B6D3_7E8D_4E57_B661_993320CE8255__INCLUDED_)
