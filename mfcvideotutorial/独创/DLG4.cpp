// DLG4.cpp : implementation file
//

#include "stdafx.h"
#include "����.h"
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
	Str.Format  ("������                  ���տ���Ӵ���治֪����˵Щʲô�����Ǻ����ң������㡣               ���������һ����̲�ס����㷢һ�����˿�����һ��ʱ���Һ�������ҽ��⣬��Ȼ���������ϵ����治֪������ôѧ��ȥ��ӡ�������һ����:");
    Str+="�����ڷ�ѧ�������ʿα��ϵ��������㽲��һ���һ�û����ͬ�����ߴ���һ��ؼң����Ȼ��ͬ�������ˣ�ֱ�����ҽ�����˲��ߡ�����֮�⣬�һ����û��������";
	Str+="������õ����ˡ�               �о�����һ����̫��ܾ����˵��ˣ���ʱ�һ��������һЩ�������������Ҳû�лؾ����ϴ�����Ҫ��һ�Ż�������������һ�����ߵ��Ƿ���";
	Str+="������Ϊ��������ɣ��þúþ�û�������ˣ������Ƚϲ�����ǿ�����ɣ�              лл���ܹ����������ʱ����ҽ��飬лл�ϵۣ��������������������ѡ������ϵۣ�";
	Str+="���������޵Ŀ������Ҹ��ɣ�You deserve all beautifull things!!!";
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
