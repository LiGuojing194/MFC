
// slideblockDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"


// CslideblockDlg 对话框
class CslideblockDlg : public CDialogEx
{
// 构造
public:
	CslideblockDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SLIDEBLOCK_DIALOG };

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
	int m_SliderV1;
	int m_SliderV2;
	int m_SliderV3;
	CProgressCtrl m_CProgressCtrl;
	CSliderCtrl m_CSlider1;
	CSliderCtrl m_CSlider2;
	CSliderCtrl m_CSlider3;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
