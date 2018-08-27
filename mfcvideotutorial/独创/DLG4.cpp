// DLG4.cpp : implementation file
//

#include "stdafx.h"
#include "独创.h"
#include "DLG4.h"
#include"DLG5.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DLG4 dialog


DLG4::DLG4(CWnd* pParent /*=NULL*/)
	: CDialog(DLG4::IDD, pParent)
{
	//{{AFX_DATA_INIT(DLG4)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DLG4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DLG4)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DLG4, CDialog)
	//{{AFX_MSG_MAP(DLG4)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLG4 message handlers

void DLG4::OnOK() 
{
DLG5 dlg5;
dlg5.DoModal ();	

}

BOOL DLG4::OnInitDialog() 
{
	CDialog::OnInitDialog();
	HWND hWnd=::GetDlgItem(m_hWnd,IDC_EDIT1);
	edital.Attach (hWnd);
	CString Str;
	Str.Format  ("启凡：                  生日快乐哟！真不知道该说些什么。但是很庆幸，遇见你。               接下来，我还是忍不住想给你发一发好人卡。高一的时候，幸好有你给我讲题，不然，及格线上的我真不知道该怎么学下去。印象最深的一次是:");
    Str+="曾经在放学后向你问课本上的向量，你讲了一遍我还没懂，同伴正催促你一起回家，你居然让同伴先走了，直到给我讲清楚了才走。除你之外，我还真的没有遇到过";
	Str+="比你更好的人了。               感觉你是一个不太会拒绝别人的人，有时我会向你提出一些不合理的请求，你也没有回绝，上次向你要了一张画留作纪念，昨天我画了左边的那幅画";
	Str+="送你作为生日礼物吧！好久好久没画过画了，画技比较差，你就勉强看看吧！              谢谢你能够在我困惑的时候给我建议，谢谢上帝，让我能有你这样的朋友。祈求上帝，";
	Str+="给予你无限的快乐与幸福吧！You deserve all beautifull things!!!";
	edital.SetWindowText(Str);

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DLG4::OnDestroy() 
{
	CDialog::OnDestroy();
	edital.Detach ();
	// TODO: Add your message handler code here
	
}
