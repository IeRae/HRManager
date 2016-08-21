
// HRManagerDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "HRManager.h"
#include "HRManagerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CHRManagerDlg ��ȭ ����



CHRManagerDlg::CHRManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_HRMANAGER_DIALOG, pParent)
	, Mon_1(_T(""))
	, Mon_2(_T(""))
	, Mon_3(_T(""))
	, Mon_4(_T(""))
	, Mon_5(_T(""))
	, Mon_6(_T(""))
	, Mon_7(_T(""))
	, Tue_1(_T(""))
	, Tue_2(_T(""))
	, Tue_3(_T(""))
	, Tue_4(_T(""))
	, Tue_5(_T(""))
	, Tue_6(_T(""))
	, Tue_7(_T(""))
	, Wed_1(_T(""))
	, Wed_2(_T(""))
	, Wed_3(_T(""))
	, Wed_4(_T(""))
	, Wed_5(_T(""))
	, Wed_6(_T(""))
	, Wed_7(_T(""))
	, Thu_1(_T(""))
	, Thu_2(_T(""))
	, Thu_3(_T(""))
	, Thu_4(_T(""))
	, Thu_5(_T(""))
	, Thu_6(_T(""))
	, Thu_7(_T(""))
	, Fri_1(_T(""))
	, Fri_2(_T(""))
	, Fri_3(_T(""))
	, Fri_4(_T(""))
	, Fri_5(_T(""))
	, Fri_6(_T(""))
	, Fri_7(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHRManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_LBString(pDX, IDC_LIST2, Mon_1);
	DDX_LBString(pDX, IDC_LIST7, Mon_2);
	DDX_LBString(pDX, IDC_LIST12, Mon_3);
	DDX_LBString(pDX, IDC_LIST17, Mon_4);
	DDX_LBString(pDX, IDC_LIST22, Mon_5);
	DDX_LBString(pDX, IDC_LIST27, Mon_6);
	DDX_LBString(pDX, IDC_LIST32, Mon_7);
	DDX_LBString(pDX, IDC_LIST3, Tue_1);
	DDX_LBString(pDX, IDC_LIST8, Tue_2);
	DDX_LBString(pDX, IDC_LIST13, Tue_3);
	DDX_LBString(pDX, IDC_LIST18, Tue_4);
	DDX_LBString(pDX, IDC_LIST23, Tue_5);
	DDX_LBString(pDX, IDC_LIST28, Tue_6);
	DDX_LBString(pDX, IDC_LIST33, Tue_7);
	DDX_LBString(pDX, IDC_LIST4, Wed_1);
	DDX_LBString(pDX, IDC_LIST9, Wed_2);
	DDX_LBString(pDX, IDC_LIST14, Wed_3);
	DDX_LBString(pDX, IDC_LIST19, Wed_4);
	DDX_LBString(pDX, IDC_LIST24, Wed_5);
	DDX_LBString(pDX, IDC_LIST29, Wed_6);
	DDX_LBString(pDX, IDC_LIST34, Wed_7);
	DDX_LBString(pDX, IDC_LIST5, Thu_1);
	DDX_LBString(pDX, IDC_LIST10, Thu_2);
	DDX_LBString(pDX, IDC_LIST15, Thu_3);
	DDX_LBString(pDX, IDC_LIST20, Thu_4);
	DDX_LBString(pDX, IDC_LIST25, Thu_5);
	DDX_LBString(pDX, IDC_LIST30, Thu_6);
	DDX_LBString(pDX, IDC_LIST35, Thu_7);
	DDX_LBString(pDX, IDC_LIST6, Fri_1);
	DDX_LBString(pDX, IDC_LIST11, Fri_2);
	DDX_LBString(pDX, IDC_LIST16, Fri_3);
	DDX_LBString(pDX, IDC_LIST21, Fri_4);
	DDX_LBString(pDX, IDC_LIST26, Fri_5);
	DDX_LBString(pDX, IDC_LIST31, Fri_6);
	DDX_LBString(pDX, IDC_LIST36, Fri_7);
	DDX_Control(pDX, IDC_TREE1, treeCtrl);
}

BEGIN_MESSAGE_MAP(CHRManagerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CHRManagerDlg �޽��� ó����

BOOL CHRManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	
	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	
	int num = init_base_data();


	HTREEITEM  hRoot;
	hRoot = treeCtrl.InsertItem(L"������", 0/* nImage */, 1/* nSelectedImage */, TVI_ROOT, TVI_LAST);
	
	HTREEITEM  hChild;

	CStringArray nameArrayOfApplicant;
	
	CString ms;
	ms.Format(_T("%d"), num);
	AfxMessageBox(ms);

	nameArrayOfApplicant.SetSize(num);
	
	print_base_data(nameArrayOfApplicant);
	

	for (int i = 0; i < last_data_index; i++){
		hChild = treeCtrl.InsertItem(nameArrayOfApplicant[i], 1/* nImage */, 1/* nSelectedImage */, hRoot, TVI_LAST);
	}

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}


void CHRManagerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CHRManagerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CHRManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



HBRUSH CHRManagerDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.

	switch (nCtlColor) {
		case CTLCOLOR_STATIC:
		{

			if (pWnd->GetDlgCtrlID() == IDC_STATIC)
			{
				pDC->SetBkMode(TRANSPARENT);
				return (HBRUSH)GetStockObject(NULL_BRUSH);
			}

		}
	}
	
	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;
}
