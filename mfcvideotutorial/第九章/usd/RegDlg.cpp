// RegDlg.cpp : implementation file
//

#include "stdafx.h"
#include "usd.h"
#include "RegDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegDlg dialog


CRegDlg::CRegDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRegDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegDlg, CDialog)
	//{{AFX_MSG_MAP(CRegDlg)
	ON_BN_CLICKED(IDC_BACK, OnBack)
	ON_BN_CLICKED(IDC_FINISH, OnFinish)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegDlg message handlers

BOOL CRegDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//����������ҳ�Ӵ��ڣ�����ʾ��һ����ҳ
	m_p1.Create(IDD_PAGE1,this);
	m_p2.Create (IDD_PAGE2,this);
	m_p3.Create (IDD_PAGE3,this);
	m_p1.ShowWindow (SW_SHOW);
	m_nSel=0;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRegDlg::SelectPage()
{
   int i=0;
   CWnd*ps[]={&m_p1,&m_p2,&m_p3};
   while(i<sizeof(ps)/sizeof(ps[0]))//ֻ��ʾһ��ҳ��
	   ps[i++]->ShowWindow (i==m_nSel?SW_SHOW:SW_HIDE);
   //����ǰ��ʾ��ҳ�����ý���
   ps[m_nSel]->SetFocus();//�������ò��谴ť
   GetDlgItem(IDOK)->EnableWindow(m_nSel<2);
   GetDlgItem(IDC_BACK)->EnableWindow(m_nSel);

}

void CRegDlg::OnOK() 
{
  if(m_nSel<2)
  {
     ++m_nSel;
	 SelectPage();
  }
//	CDialog::OnOK();
}

void CRegDlg::OnBack() 
{
	if(m_nSel<2)
  {
     --m_nSel;
	 SelectPage();
  }

  	
}

void CRegDlg::OnFinish() 
{
int i=0;
CWnd*ps[]={&m_p1,&m_p2,&m_p3};
while(i<sizeof(ps)/sizeof(ps[0]))
ps[i++]->UpdateData ();
CDialog::EndDialog (IDOK);	
}

HBRUSH CRegDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
		if(nCtlColor==CTLCOLOR_DLG)//���о�̬�ؼ�����ɫ
	{
	  pDC->SetTextColor (RGB(0,0,0));//���о�̬�ı���ɫ
	  pDC->SetBkColor (RGB(166,243,248));
	  //hbr=(HBRUSH)CreateSolidBrush(RGB(0,120,0));//���ػ�ˢ
	}
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
