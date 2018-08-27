// DLG3.cpp : implementation file
//

#include "stdafx.h"
#include "独创.h"
#include "DLG3.h"
#include"DLG4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DLG3 dialog


DLG3::DLG3(CWnd* pParent /*=NULL*/)
	: CDialog(DLG3::IDD, pParent)
{
	//{{AFX_DATA_INIT(DLG3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DLG3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DLG3)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DLG3, CDialog)
	//{{AFX_MSG_MAP(DLG3)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLG3 message handlers

void DLG3::OnOK() 
{
	DLG4 dlg4;
	dlg4.DoModal ();
	
	CDialog::OnOK();
}

BOOL DLG3::OnInitDialog() 
{
	CDialog::OnInitDialog();
	HWND hWnd=::GetDlgItem(m_hWnd,IDC_EDIT1);
	edit1.Attach (hWnd);
    CTime t=CTime::GetCurrentTime();
	int nYear=t.GetYear();
	int nMonth=t.GetMonth();
    int nDay=t.GetDay();
	int nHour=t.GetHour();
	int nMin=t.GetMinute();
	int nSec=t.GetSecond();
	int nWeek=t.GetDayOfWeek();//1代表周日
	CString Str;
	Str.Format("%d年%02d月%02d日 %02d:%02d:%02d                      在这里写下你的心愿吧! ",nYear,nMonth,nDay,nHour,nMin,nSec);
	edit1.SetWindowText(Str);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DLG3::OnDestroy() 
{
	CDialog::OnDestroy();
	edit1.Detach ();
	
}
