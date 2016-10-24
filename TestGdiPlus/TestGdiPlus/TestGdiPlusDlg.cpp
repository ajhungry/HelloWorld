// TestGdiPlusDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestGdiPlus.h"
#include "TestGdiPlusDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Gdiplus;

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CTestGdiPlusDlg dialog




CTestGdiPlusDlg::CTestGdiPlusDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestGdiPlusDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestGdiPlusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestGdiPlusDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CTestGdiPlusDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTestGdiPlusDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CTestGdiPlusDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CTestGdiPlusDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CTestGdiPlusDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CTestGdiPlusDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CTestGdiPlusDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CTestGdiPlusDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CTestGdiPlusDlg::OnBnClickedButton9)
END_MESSAGE_MAP()


// CTestGdiPlusDlg message handlers

BOOL CTestGdiPlusDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestGdiPlusDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestGdiPlusDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestGdiPlusDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/*
Pen(IN const Color& color, 
	IN REAL width = 1.0f)
{
	Unit unit = UnitWorld;
	nativePen = NULL;
	lastResult = DllExports::GdipCreatePen1(color.GetValue(),
		width, unit, &nativePen);
}
*/
void CTestGdiPlusDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	Graphics g1(GetWindowDC()->m_hDC);
	Pen p(Color(255,0,0),10);
	p.SetStartCap(Gdiplus::LineCapRound);
	p.SetEndCap(Gdiplus::LineCapArrowAnchor);
	g1.DrawLine(&p, 150, 150, 500, 200);
}

void CTestGdiPlusDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	/*
	Graphics g1(GetWindowDC()->m_hDC);
	g1.Clear(Color(255,255,255));
	CRect rect;
	GetClientRect(&rect);
	SolidBrush * brush(Color(0,255,0))
	g1.FillRectangle(brush, rect);//»­°åÑÕÉ« 
	HatchBrush hb = new HatchBrush(HatchStyle.HatchStyleWideUpwardDiagonal, Color.White, Color.Black);
	Pen p(hb, 10);
	g1.DrawRectangle(p, 300, 30, 80, 80);
	*/
}

void CTestGdiPlusDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	Graphics GdipCreatePen1(GetWindowDC()->GetSafeHdc());
	vector<int> vContent;


}	

	


void CTestGdiPlusDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
}

void CTestGdiPlusDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
}

void CTestGdiPlusDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
}

void CTestGdiPlusDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
}

void CTestGdiPlusDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
}

void CTestGdiPlusDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
}
