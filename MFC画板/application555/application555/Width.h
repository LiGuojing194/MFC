#pragma once
#include"Resource.h"
#include "afxcmn.h"

// CWidth 对话框

class CWidth : public CDialog
{
	DECLARE_DYNAMIC(CWidth)

public:
	CWidth(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CWidth();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_nWidth;
	CSliderCtrl m_slider;
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	int GetWidth();
};
