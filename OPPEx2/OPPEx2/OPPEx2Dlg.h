
// OPPEx2Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// COPPEx2Dlg 对话框
class COPPEx2Dlg : public CDialogEx
{
// 构造
public:
	COPPEx2Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_OPPEX2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_ListCon;
	CString	m_Name;
	CString	m_Sid;
	CString	m_Value;
	int m_Listid;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnSelchangeList1();
	afx_msg void OnBnClickedShow();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnEnChangeName();
	afx_msg void OnClose();
};
