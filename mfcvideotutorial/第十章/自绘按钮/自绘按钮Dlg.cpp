// �Ի水ťDlg.cpp : implementation file
//

#include "stdafx.h"
#include "�Ի水ť.h"
#include "�Ի水ťDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Control(pDX, IDC_EDIT2, m_Edit2);
	DDX_Control(pDX, IDC_TRANSFORM_BTN, m_TransformButton);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_TRANSFORM_BTN, OnTransformBtn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    m_Brush.CreateSolidBrush (RGB(166,243,248));//����ǳ��ɫˢ��
	m_Bitmap[0].LoadBitmap (IDB_BITMAP1);//���ذ�ť������ʾλͼ
	m_Bitmap[0].LoadBitmap (IDB_BITMAP2);//���ذ�ť�ȵ���ʾλͼ
	//���á�ת������ť��ʾλͼ
	m_TransformButton.SetCBitmap (&m_Bitmap[0],&m_HotBitmap[0]);
	m_Bitmap[0].Detach ();
	m_HotBitmap[0].Detach ();
    m_Edit2.SetFocus ();//���������õ��༭��
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
//	SetIcon(m_hIcon, TRUE);			// Set big icon
//	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return FALSE;  // return TRUE  unless you set the focus to a control//���ط���ֵ�����뽹�����ڶԻ���ĵ�һ��������
	//�����㣬���뽹������ĳ�ؼ���
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
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
		CPaintDC dc(this);//���ڻ��Ƶ��豸��������
		CRect rect;
		GetClientRect(&rect);
		CDC dcMem;
		dcMem.CreateCompatibleDC (&dc);
		CBitmap bmpBackground;//λͼ����
		bmpBackground.LoadBitmap (IDB_BITMAP4);//���뱳��λͼ
		BITMAP bitmap;//�������汳��ͼƬ�ĳ�����Ϣ
		bmpBackground.GetBitmap (&bitmap);//���뱳��λͼ
       CBitmap*pbmpOld=dcMem.SelectObject (&bmpBackground);//��ͼƬѡ������
	   //�������ͼƬ�ȿͻ���С����stretchBlt����λͼ
	   dc.StretchBlt (0,0,rect.Width (),rect.Height (),&dcMem,0,0,bitmap.bmWidth ,bitmap.bmHeight ,SRCCOPY);
	   //�ͷ�DC
	   dcMem.SelectObject (pbmpOld);
	   dcMem.DeleteDC ();
	//	CDialog::OnPaint();
	}
	//		CDialog::OnPaint();

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

HBRUSH CMyDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if(nCtlColor==CTLCOLOR_STATIC)//���о�̬�ı��ؼ���ɫ
	{
	 pDC->SetTextColor (RGB(0,0,0));
	 pDC->SetBkColor (RGB(166,243,248));
	 hbr=(HBRUSH)m_Brush;
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CMyDlg::OnTransformBtn() 
{
	// TODO: Add your control notification handler code here
	m_TransformButton.EnableWindow(FALSE);
	m_Bitmap[0].LoadBitmap (IDB_BITMAP3);
	m_HotBitmap[0].LoadBitmap (IDB_BITMAP3);
	m_TransformButton.DetachCBitmap ();
	m_TransformButton.SetCBitmap (&m_Bitmap[0],&m_Bitmap[0]);
	m_Bitmap[0].Detach ();
	m_HotBitmap[0].Detach ();

}
