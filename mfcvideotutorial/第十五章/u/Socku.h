#if !defined(AFX_SOCKU_H__76938EAB_0D9B_43A6_9F78_0E895E26361E__INCLUDED_)
#define AFX_SOCKU_H__76938EAB_0D9B_43A6_9F78_0E895E26361E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Socku.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CSocku command target
#include<afxsock.h>
class CSocku : public CSocket
{
// Attributes
public:

// Operations
public:
	CSocku();
	virtual ~CSocku();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSocku)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CSocku)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOCKU_H__76938EAB_0D9B_43A6_9F78_0E895E26361E__INCLUDED_)
