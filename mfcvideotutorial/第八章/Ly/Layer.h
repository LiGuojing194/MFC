// Layer.h: interface for the CLayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAYER_H__7F37B6D3_7E8D_4E57_B661_993320CE8255__INCLUDED_)
#define AFX_LAYER_H__7F37B6D3_7E8D_4E57_B661_993320CE8255__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
enum{
STU_DRAWING,  //绘制状态
STU_NORMAL,  //普通状态
STU_SELECT};  //被图层选中的状态
class CLayer  
{//纯虚函数没有结构体，以“=0”标志代替；含有纯虚函数的类叫抽象类
public:
	int m_nStatus;
	static CLayer*Create(int nType);
	//鼠标及显示事件处理
	virtual void OnLButtonDown(UINT nFlags,CPoint point)=0;
	virtual void OnMouseMove(UINT nFlags,CPoint point,CDC*pDC=NULL)=0;
	virtual void OnLButtonUp(UINT nFlags,CPoint point, CDC*pDC=NULL)=0;
	virtual void OnDraw(CDC*pDC)=0;
    //图层拖动过程，选择，平移和跟踪
	virtual void Select(CPoint point)=0;
	virtual void Offset(int x,int y)=0;
	virtual BOOL Track(CPoint point)=0;

	CLayer();
	virtual ~CLayer();

};

#endif // !defined(AFX_LAYER_H__7F37B6D3_7E8D_4E57_B661_993320CE8255__INCLUDED_)
