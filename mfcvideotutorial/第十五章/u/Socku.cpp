// Socku.cpp : implementation file
//

#include "stdafx.h"
#include "u.h"
#include "Socku.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSocku

CSocku::CSocku()
{
}

CSocku::~CSocku()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CSocku, CSocket)
	//{{AFX_MSG_MAP(CSocku)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CSocku member functions

void CSocku::OnReceive(int nErrorCode) 
{//ReceiveFrom�����ڽ������ݵ�ͬʱ����ȡ���ͷ���IP�Ͷ˿�
	char s[2048];
    CString szIP;
	UINT nPort;
	int nRet=ReceiveFrom(s,sizeof(s),szIP,nPort);
	if(nRet<=0)
		return;
	s[nRet]=0;// �����յ�������ͨ����Ϣ����ʾ
	CString str;
	str.Format ("%s����˵��\r\n%s\r\n",szIP,s);
	CWnd*pDlg=AfxGetMainWnd();
	CEdit*pEdit=(CEdit*)pDlg->GetDlgItem (IDC_HIST);
	pEdit->SetSel (pEdit->GetWindowTextLength(),-1);
	pEdit->ReplaceSel (str);
	//AfxMessageBox(s);
	CSocket::OnReceive(nErrorCode);
}
