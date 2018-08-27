#if !defined(AFX_LISTENSOCKET_H__492B9949_574C_4F7A_9E9E_C4E6124C70E3__INCLUDED_)
#define AFX_LISTENSOCKET_H__492B9949_574C_4F7A_9E9E_C4E6124C70E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListenSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CListenSocket command target

class CListenSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CListenSocket();
	virtual ~CListenSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListenSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CListenSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTENSOCKET_H__492B9949_574C_4F7A_9E9E_C4E6124C70E3__INCLUDED_)
