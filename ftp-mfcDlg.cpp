// ftp-mfcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ftp-mfc.h"
#include "ftp-mfcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CftpmfcDlg dialog




CftpmfcDlg::CftpmfcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CftpmfcDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CftpmfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_OUTLOOKBAR, m_OutlookBar);
}

BEGIN_MESSAGE_MAP(CftpmfcDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CftpmfcDlg message handlers

BOOL CftpmfcDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetupOutlookBar();
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CftpmfcDlg::OnPaint()
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
HCURSOR CftpmfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/********************************************************************/
/*																	*/
/* Function name : CApplicationDlg::SetupOutlookBar					*/		
/* Description   : Initialize listview, change color/iconspacing to	*/
/*				   make it look a little bit like the outlook bar.	*/
/*																	*/
/********************************************************************/
void CftpmfcDlg::SetupOutlookBar()
{
	COLORREF Rgb_blue = RGB(57,128,244);
	// create Imagelist
	m_ImageList.Create(32, 32, ILC_COLOR16|ILC_MASK,1, 4);
	m_ImageList.SetBkColor(Rgb_blue);

	HICON hIcon = ::LoadIcon (AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_LOG));
	m_ImageList.Add(hIcon);
	hIcon = ::LoadIcon (AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ONLINE_USERS));
	m_ImageList.Add(hIcon);
	hIcon = ::LoadIcon (AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_CONFIGURATION));
	m_ImageList.Add(hIcon);
	hIcon = ::LoadIcon (AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_STATISTICS));
	m_ImageList.Add(hIcon);
	hIcon = ::LoadIcon (AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_SECURITY));
	m_ImageList.Add(hIcon);

	m_OutlookBar.SetImageList(&m_ImageList, LVSIL_NORMAL);

	CRect rc;
	m_OutlookBar.GetClientRect(rc);

	// set new icon spacing
	m_OutlookBar.SetIconSpacing(rc.Width(), 64);

	// change colors
	m_OutlookBar.SetTextColor(RGB(255,255,255));
	m_OutlookBar.SetTextBkColor(Rgb_blue);
	m_OutlookBar.SetBkColor(Rgb_blue);	

	// insert items
	m_OutlookBar.InsertColumn(0, "OutlookBar");

	m_OutlookBar.InsertItem(0, "服务器日志", 0);
	m_OutlookBar.InsertItem(1, "在线者", 1);
	m_OutlookBar.InsertItem(2, "配置", 2);
	m_OutlookBar.InsertItem(3, "Statistics", 3);
	m_OutlookBar.InsertItem(4, "Security", 4);

	//	m_OutlookBar.SetExtendedStyle(LVS_EX_TRACKSELECT);
}