
// OPPEx2Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// COPPEx2Dlg �Ի���
class COPPEx2Dlg : public CDialogEx
{
// ����
public:
	COPPEx2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_OPPEX2_DIALOG };

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
