// Help.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JosephusMFC.h"
#include "Help.h"
#include "afxdialogex.h"


// Help �Ի���

IMPLEMENT_DYNAMIC(Help, CDialog)

Help::Help(CWnd* pParent /*=NULL*/)
	: CDialog(Help::IDD, pParent)
{

}

Help::~Help()
{
}

void Help::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Help, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &Help::OnBnClickedButton1)
END_MESSAGE_MAP()


// Help ��Ϣ�������


void Help::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
     CDialog::OnOK();
}
