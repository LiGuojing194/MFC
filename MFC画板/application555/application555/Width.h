#pragma once
#include"Resource.h"
#include "afxcmn.h"

// CWidth �Ի���

class CWidth : public CDialog
{
	DECLARE_DYNAMIC(CWidth)

public:
	CWidth(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CWidth();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_nWidth;
	CSliderCtrl m_slider;
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	int GetWidth();
};
