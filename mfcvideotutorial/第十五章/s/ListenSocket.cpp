// ListenSocket.cpp : implementation file
//

#include "stdafx.h"
#include "s.h"
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
void CListenSocket::OnAccept(int nErrorCode) 
{
	CClientSocket*pSock=new CClientSocket;
	if(!Accept(*pSock))
		delete pSock;

	CSocket::OnAccept(nErrorCode);
}
