
// yhcxp.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CyhcxpApp: 
// �йش����ʵ�֣������ yhcxp.cpp
//

class CyhcxpApp : public CWinApp
{
public:
	CyhcxpApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CyhcxpApp theApp;