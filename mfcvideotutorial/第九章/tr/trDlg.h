// trDlg.h : header file
//

#if !defined(AFX_TRDLG_H__BB2601D6_8CBB_4ABC_97E8_6267ADA9F2C3__INCLUDED_)
#define AFX_TRDLG_H__BB2601D6_8CBB_4ABC_97E8_6267ADA9F2C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTrDlg dialog
struct SInfo
{//��Ա��Ϣ�������ļ���/дʱʹ��
 int nNumb;         //����
 char sName[20]; //����
 float fSala;  //����
};
class CTrDlg : public CDialog
{
	BOOL m_bFlag;
	void Load();
	int GetDepth(HTREEITEM hItem);//��ȡһ�����ڵ����ڵĲ�
	CString GetPath(HTREEITEM hItem);//ͨ��һ�����ڵ��ȡ·��
	BOOL MakeDir(CString &szPath);//����һ�����Ŀ¼
	// Construction
public:
	CTrDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTrDlg)
	enum { IDD = IDD_TR_DIALOG };
	CTreeCtrl	m_tree;
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTrDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnSave();
	afx_msg void OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeSala();
	afx_msg void OnItemchangedList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRDLG_H__BB2601D6_8CBB_4ABC_97E8_6267ADA9F2C3__INCLUDED_)
