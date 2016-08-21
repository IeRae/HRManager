
// HRManagerDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"


// CHRManagerDlg 대화 상자
class CHRManagerDlg : public CDialogEx
{
// 생성입니다.
public:
	CHRManagerDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HRMANAGER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CString Mon_1;
	CString Mon_2;
	CString Mon_3;
	CString Mon_4;
	CString Mon_5;
	CString Mon_6;
	CString Mon_7;

	CString Tue_1;
	CString Tue_2;
	CString Tue_3;
	CString Tue_4;
	CString Tue_5;
	CString Tue_6;
	CString Tue_7;

	CString Wed_1;
	CString Wed_2;
	CString Wed_3;
	CString Wed_4;
	CString Wed_5;
	CString Wed_6;
	CString Wed_7;

	CString Thu_1;
	CString Thu_2;
	CString Thu_3;
	CString Thu_4;
	CString Thu_5;
	CString Thu_6;
	CString Thu_7;

	CString Fri_1;
	CString Fri_2;
	CString Fri_3;
	CString Fri_4;
	CString Fri_5;
	CString Fri_6;
	CString Fri_7;

	CTreeCtrl treeCtrl;
};
