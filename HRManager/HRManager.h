
// HRManager.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CHRManagerApp:
// �� Ŭ������ ������ ���ؼ��� HRManager.cpp�� �����Ͻʽÿ�.
//

class CHRManagerApp : public CWinApp
{
public:
	CHRManagerApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CHRManagerApp theApp;