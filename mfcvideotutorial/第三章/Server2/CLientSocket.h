#if !defined(AFX_CLIENTSOCKET_H__D50F5D80_A016_4D61_8070_33B345042099__INCLUDED_)
#define AFX_CLIENTSOCKET_H__D50F5D80_A016_4D61_8070_33B345042099__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CLientSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CCLientSocket command target

class CCLientSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CCLientSocket();
	virtual ~CCLientSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCLientSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CCLientSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSOCKET_H__D50F5D80_A016_4D61_8070_33B345042099__INCLUDED_)
