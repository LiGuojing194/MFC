
// JosephusMFC.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CJosephusMFCApp: 
// �йش����ʵ�֣������ JosephusMFC.cpp
//

class CJosephusMFCApp : public CWinApp
{
public:
	CJosephusMFCApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CJosephusMFCApp theApp;