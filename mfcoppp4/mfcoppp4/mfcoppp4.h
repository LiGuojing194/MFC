
// mfcoppp4.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cmfcoppp4App: 
// �йش����ʵ�֣������ mfcoppp4.cpp
//

class Cmfcoppp4App : public CWinApp
{
public:
	Cmfcoppp4App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cmfcoppp4App theApp;