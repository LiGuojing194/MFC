// NotePadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NotePad.h"
#include "NotePadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNotePadDlg dialog

CNotePadDlg::CNotePadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNotePadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNotePadDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNotePadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNotePadDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNotePadDlg, CDialog)
	//{{AFX_MSG_MAP(CNotePadDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_COMMAND(ID_FILE_EXIT, OnFileExit)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNotePadDlg message handlers

BOOL CNotePadDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNotePadDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CNotePadDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CNotePadDlg::OnCancel() 
{
	
//	CDialog::OnCancel();
}

void CNotePadDlg::OnOK() 
{
	
//	CDialog::OnOK();
}

void CNotePadDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnCancel();
}

void CNotePadDlg::OnFileExit() 
{
	CDialog::OnCancel();
}

void CNotePadDlg::OnFileOpen() 
{
/*CFileDialog fd(TRUE,"*.txt",NULL,0,"文本文件(*.txt)|*.txt|所有文件|*.*||");
if(IDCANCEL==fd.DoModal ())
   return;
CString szFile=fd.GetPathName ();
CFile file;
if(!file.Open (szFile,CFile::modeRead))
{
AfxMessageBox("文件打开失败！");
return;
}
DWORD dwLen=file.GetLength ();
char*pBuf=new char[dwLen+1];
file.Read (pBuf,dwLen);
pBuf[dwLen]=0;
SetDlgItemText(IDC_EDIT1,pBuf);
file.Close ();
delete []pBuf;       //注意释放堆内存空间      */
	CFileDialog fd(TRUE,"*.text",NULL,0,"文本文件(*.text)|*.txt|所有文件|*.*||");
	if(IDCANCEL==fd.DoModal())
		return;
	CString szFile=fd.GetPathName ();
	HANDLE hFile=::CreateFile(szFile,GENERIC_READ,FILE_SHARE_READ,
		NULL,OPEN_EXISTING,0,NULL);
	if(INVALID_HANDLE_VALUE==hFile)
	{
		AfxMessageBox("文件打开失败！");
		return;
	}
    DWORD dwLen=::GetFileSize(hFile,NULL);
	char*pBuf=new char[dwLen+1];
	DWORD dwRet=0;
	::ReadFile(hFile,pBuf,dwLen,&dwRet,NULL);
	pBuf[dwRet]=0;
	SetDlgItemText(IDC_EDIT1,pBuf);
	CloseHandle(hFile);
	delete []pBuf;
}

void CNotePadDlg::OnFileSave() 
{
  /*CFileDialog fd(FALSE,"*.txt",NULL,OFN_OVERWRITEPROMPT,
	  "文本文件(*.txt)|*.txt|所有文件|*.*||");
  if(IDCANCEL==fd.DoModal())
	  return;
  CFile file;
  if(!file.Open (fd.GetPathName(),CFile::modeWrite|CFile::modeCreate))
  {
    AfxMessageBox("文件保存失败！");
	return;
  }
  CWnd*pEdit=GetDlgItem(IDC_EDIT1);
  int nLen=pEdit->GetWindowTextLength();
  char*pBuf=new char[nLen+1];
  pBuf[nLen]=0;
  pEdit->GetWindowText(pBuf,nLen+1);
  file.Write (pBuf,nLen);
  file.Close();
  delete[]pBuf;*/
	CFileDialog fd(FALSE,"*.text",NULL,OFN_OVERWRITEPROMPT,
		"文本文件(*,txt)|*.txt|所有文件|*.*||");
	if(IDCANCEL==fd.DoModal())
		return;
	HANDLE hFile=::CreateFile (fd.GetPathName(),GENERIC_WRITE,0,NULL,
		CREATE_ALWAYS,0,NULL);
	if(INVALID_HANDLE_VALUE==hFile)
	{
		AfxMessageBox("文件保存失败！");
		return;
	}
	CWnd*pEdit=GetDlgItem(IDC_EDIT1);
	int nLen=pEdit->GetWindowTextLength();
	char*pBuf=new char[nLen+1];
	pEdit->GetWindowText(pBuf,nLen);
	pBuf[nLen]=0;
	DWORD dwRet=0;
	::WriteFile (hFile,pBuf,nLen,&dwRet,NULL);
	CloseHandle(hFile);
	delete []pBuf;
}
