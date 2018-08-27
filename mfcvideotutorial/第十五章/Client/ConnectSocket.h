#if !defined(AFX_CONNECTSOCKET_H__5C472E3D_2123_4C80_84E4_1CCB24174328__INCLUDED_)
#define AFX_CONNECTSOCKET_H__5C472E3D_2123_4C80_84E4_1CCB24174328__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConnectSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CConnectSocket command target

class CConnectSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CConnectSocket();
	virtual ~CConnectSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConnectSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CConnectSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONNECTSOCKET_H__5C472E3D_2123_4C80_84E4_1CCB24174328__INCLUDED_)
