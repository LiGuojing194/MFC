// Ly2Doc.h : interface of the CLy2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LY2DOC_H__79BF2E96_CD42_46F4_9E3C_609244CE6AB2__INCLUDED_)
#define AFX_LY2DOC_H__79BF2E96_CD42_46F4_9E3C_609244CE6AB2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLy2Doc : public CDocument
{
protected: // create from serialization only
	CLy2Doc();
	DECLARE_DYNCREATE(CLy2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLy2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLy2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLy2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LY2DOC_H__79BF2E96_CD42_46F4_9E3C_609244CE6AB2__INCLUDED_)
