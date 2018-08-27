// ListenSocket.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ListenSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListenSocket

CListenSocket::CListenSocket()
{
}

CListenSocket::~CListenSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CListenSocket, CSocket)
	//{{AFX_MSG_MAP(CListenSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CListenSocket member functions
#include"ClientSocket.h"
extern CServerApp theApp;
void CListenSocket::OnAccept(int nErrorCode) 
{
	//新建一个CClientSocket对象，与新连接进入的客户端关联
	CClientSocket*pSock=new CClientSocket;
	if(Accept(*pSock))
		theApp.m_list.AddTail (pSock);
	else
		delete pSock;
	
	CSocket::OnAccept(nErrorCode);
}
