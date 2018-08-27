// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "s.h"
#include "ClientSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSocket, CSocket)
	//{{AFX_MSG_MAP(CClientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSocket member functions

void CClientSocket::OnClose(int nErrorCode) 
{
    delete this;	
	CSocket::OnClose(nErrorCode);
}

void CClientSocket::OnReceive(int nErrorCode) 
{
   int nCmd=0,nLen=0;
   if((Receive(&nCmd,sizeof(nCmd))<=0))
	   return ;
   switch(nCmd)
   {
   case INF_ADD:
	   AddData();
	   break;
   case INF_BROW:
	   Browse();
	   break;
   }
	CSocket::OnReceive(nErrorCode);
}
extern CSApp theApp;
void CClientSocket::AddData()
{//添加数据的协议处理
	SData data;
	if(Receive(&data,sizeof(data))<=0)
		return;
	theApp.m_list .AddTail (data);

}

void CClientSocket::Browse()
{//浏览数据的协议处理，先发总数再逐条发送具体数据
	int nCount=theApp.m_list .GetCount ();
	Send(&nCount,sizeof(nCount));
	POSITION pos=theApp.m_list.GetHeadPosition ();
	while(pos)
	{
	 SData data=theApp.m_list .GetNext(pos);
	 Send(&data,sizeof(data));
	}

}
