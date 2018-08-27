// ConnectSocket.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "ConnectSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConnectSocket

CConnectSocket::CConnectSocket()
{
}

CConnectSocket::~CConnectSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CConnectSocket, CSocket)
	//{{AFX_MSG_MAP(CConnectSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CConnectSocket member functions

void CConnectSocket::OnReceive(int nErrorCode) 
{
    char s[2048];
	int nLen=Receive(s,sizeof(s)-1);
	if(nLen<=0)
		return;
	s[nLen]=0;
	CWnd*pWnd=AfxGetMainWnd();
	CEdit*pEdit=(CEdit*)pWnd->GetDlgItem (IDC_HIST);
	pEdit->SetSel (pEdit->GetWindowTextLength (),-1);
	pEdit->ReplaceSel (s);
	CSocket::OnReceive(nErrorCode);
}
