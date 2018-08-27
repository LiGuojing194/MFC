// Ly2Doc.cpp : implementation of the CLy2Doc class
//

#include "stdafx.h"
#include "Ly2.h"

#include "Ly2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLy2Doc

IMPLEMENT_DYNCREATE(CLy2Doc, CDocument)

BEGIN_MESSAGE_MAP(CLy2Doc, CDocument)
	//{{AFX_MSG_MAP(CLy2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLy2Doc construction/destruction

CLy2Doc::CLy2Doc()
{
	// TODO: add one-time construction code here

}

CLy2Doc::~CLy2Doc()
{
}

BOOL CLy2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLy2Doc serialization

void CLy2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CLy2Doc diagnostics

#ifdef _DEBUG
void CLy2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLy2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLy2Doc commands
