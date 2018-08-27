#if !defined(AFX_LISTENSOCKET_H__1CD8E7C5_69D2_4212_BE95_5C6D7758FCB9__INCLUDED_)
#define AFX_LISTENSOCKET_H__1CD8E7C5_69D2_4212_BE95_5C6D7758FCB9__INCLUDED_

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

#endif // !defined(AFX_LISTENSOCKET_H__1CD8E7C5_69D2_4212_BE95_5C6D7758FCB9__INCLUDED_)
