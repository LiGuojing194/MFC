#pragma once
#include"memdc1.h"

// Enter �Ի���

class Enter : public CDialog
{
	DECLARE_DYNAMIC(Enter)
	MemDC m_dc;
public:
	MemDC m_dcBack;
	MemDC m_dcMem;
	Enter(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Enter();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
};
