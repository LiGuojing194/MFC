// Help.cpp : 实现文件
//

#include "stdafx.h"
#include "JosephusMFC.h"
#include "Help.h"
#include "afxdialogex.h"


// Help 对话框

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


// Help 消息处理程序


void Help::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
     CDialog::OnOK();
}
