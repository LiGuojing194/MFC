
// JosephusMFCDlg.h : ͷ�ļ�
//

#pragma once
#include"member.h"
#include "afxwin.h"
#include "afxcmn.h"


// CJosephusMFCDlg �Ի���
class CJosephusMFCDlg : public CDialogEx
{
// ����
public:
	CJosephusMFCDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_JOSEPHUSMFC_DIALOG };

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
	afx_msg void OnBnClickedOk();
private:
	int m_nScaleDlg;
	int m_nStartDlg;
	int m_nLoopDlg;
public:
	Member*m_pMenberDlg;
	int m_nBuildCount;
	int m_nLastScale;
	int m_nFindDlg;
	int m_nResultDlg;
private:
	CListBox m_ListOutput;
public:
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedLookfor();
	CListCtrl m_list_log;
	afx_msg void OnBnClickedHelp();
	afx_msg void OnBnClickedCancel();
};
