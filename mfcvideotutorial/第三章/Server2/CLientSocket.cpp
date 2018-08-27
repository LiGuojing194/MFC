// CLientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "Server2.h"
#include "CLientSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCLientSocket

CCLientSocket::CCLientSocket()
{
}

CCLientSocket::~CCLientSocket()
{
}



// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CCLientSocket, CSocket)
	//{{AFX_MSG_MAP(CCLientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CCLientSocket member functions
extern CServer2App theApp;

void CCLientSocket::OnReceive(int nErrorCode) 
{
		char s[2048];
	int nLen=Receive(s,sizeof(s)-1);
	if(nLen<=0)
		return;
	s[nLen]=0;


	CString szIP;
	UINT nPort;
	GetPeerName(szIP,nPort);
	CString str;
	str.Format ("%s-%d对所有人说:\r\n%s\r\n",szIP,nPort,s);
    
	CWnd*pWnd=AfxGetMainWnd();
	CEdit*pEdit=(CEdit*)pWnd->GetDlgItem (IDC_EDIT);
	pEdit->SetSel (pEdit->GetWindowTextLength(),-1);
	pEdit->ReplaceSel (str);
	CPtrList& list=theApp.m_list ;
	POSITION pos=list.GetHeadPosition();
	while(pos)
	{
	  //将一个客户端发来的聊天文字，群发给所有其他客户端
		CCLientSocket*pSock=(CCLientSocket*)list.GetAt(pos);
		if(pSock!=this)
			pSock->Send(str,str.GetLength());
		list.GetNext(pos);
	}
	CSocket::OnReceive(nErrorCode);
}

void CCLientSocket::OnClose(int nErrorCode) 
{
	CPtrList &list=theApp.m_list;
POSITION pos=list.GetHeadPosition ();
while(pos)
{
  if(list.GetAt(pos)==this)
  {
   list.RemoveAt (pos);
   break;
  }
  list.GetNext (pos);
}	
delete this;

	CSocket::OnClose(nErrorCode);
}
