
// mfcoppp4Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// Cmfcoppp4Dlg 对话框
class Cmfcoppp4Dlg : public CDialogEx
{
// 构造
public:
	Cmfcoppp4Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCOPPP4_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	HTREEITEM root, root1, root2, root3;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_Grade;
	CString m_Id;
	CListBox m_Log;
	CString m_Name;
	CTreeCtrl m_Tree;
	double m_Sub1;
	double m_Sub2;
	double m_Sub3;
	CListCtrl m_Inquiry;
	afx_msg void OnBnClickedAdd();
//	afx_msg void OnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDblclkTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedReset();
	afx_msg void OnBnClickedClear();
};
