
// slideblockDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CslideblockDlg �Ի���
class CslideblockDlg : public CDialogEx
{
// ����
public:
	CslideblockDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SLIDEBLOCK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
