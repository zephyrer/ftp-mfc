// llzyFtpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "llzyFtp.h"
#include "llzyFtpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CllzyFtpDlg dialog


static UINT auIDStatusBar[] = 
{
	ID_SEPARATOR,
	ID_INDICATOR_DATA_RECEIVED,
	ID_INDICATOR_DATA_SEND,
	ID_INDICATOR_ONLINELED,
	ID_INDICATOR_OFFLINELED
};

CllzyFtpDlg::CllzyFtpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CllzyFtpDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CllzyFtpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_OUTLOOKBAR, m_OutlookBar);
}

BEGIN_MESSAGE_MAP(CllzyFtpDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CllzyFtpDlg message handlers

BOOL CllzyFtpDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetupOutlookBar();
	CreateStatusbar();
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

void CllzyFtpDlg::OnPaint()
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
HCURSOR CllzyFtpDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/************************************************************************/
/* 开灯                                                                     */
/************************************************************************/
void CllzyFtpDlg::SetOnlineLed(BOOL bOnline)
{
	HICON hIcon = (HICON)::LoadImage(AfxGetInstanceHandle(),
		bOnline ? MAKEINTRESOURCE(IDI_LED_GREEN) : MAKEINTRESOURCE(IDI_LED_OFF),
		IMAGE_ICON, 16, 16, LR_SHARED);
	m_wndStatusBar.GetStatusBarCtrl().SetIcon(m_wndStatusBar.CommandToIndex(ID_INDICATOR_ONLINELED), hIcon);
	m_wndStatusBar.GetStatusBarCtrl().Invalidate();
	m_wndStatusBar.GetStatusBarCtrl().UpdateWindow();
	DestroyIcon(hIcon);
}


/************************************************************************/
/* 关灯                                                                     */
/************************************************************************/
void CllzyFtpDlg::SetOfflineLed(BOOL bOffline)
{
	HICON hIcon = (HICON)::LoadImage(AfxGetInstanceHandle(),
		bOffline ? MAKEINTRESOURCE(IDI_LED_RED) : MAKEINTRESOURCE(IDI_LED_OFF),
		IMAGE_ICON, 16, 16, LR_SHARED);
	m_wndStatusBar.GetStatusBarCtrl().SetIcon(m_wndStatusBar.CommandToIndex(ID_INDICATOR_OFFLINELED), hIcon);
	m_wndStatusBar.GetStatusBarCtrl().Invalidate();
	m_wndStatusBar.GetStatusBarCtrl().UpdateWindow();
	DestroyIcon(hIcon);
}


/************************************************************************/
/* 创建OutLook型Bar                                                                     */
/************************************************************************/
void CllzyFtpDlg::SetupOutlookBar()
{
	COLORREF rgb_lkBar = RGB(57,128,244);	//系统任务栏颜色
	// create Imagelist
	m_ImageList.Create(32, 32, ILC_COLOR16|ILC_MASK,1, 4);
	m_ImageList.SetBkColor(rgb_lkBar);//图标背景

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
	m_OutlookBar.SetTextBkColor(rgb_lkBar);
	m_OutlookBar.SetBkColor(rgb_lkBar);	

	// insert items
	m_OutlookBar.InsertColumn(0, "OutlookBar");

	m_OutlookBar.InsertItem(0, "Server Log", 0);
	m_OutlookBar.InsertItem(1, "Online Users", 1);
	m_OutlookBar.InsertItem(2, "Configuration", 2);
	m_OutlookBar.InsertItem(3, "Statistics", 3);
	m_OutlookBar.InsertItem(4, "Security", 4);
}

/************************************************************************/
/* 真彩工具栏                                                                     */
/************************************************************************/
void CllzyFtpDlg::InitToolBar()
{
	CBitmap bm;

	//活动的工具
	m_imageToolBar.Create( 16, 16, TRUE | ILC_COLOR24, 4, 0 );
	bm.LoadBitmap( IDB_TOOLBARCOLOR );
	m_imageToolBar.Add( &bm,(CBitmap*)NULL );
	bm.Detach();
	m_wndToolBar.GetToolBarCtrl().SetImageList( &m_imageToolBar );

	//禁止的工具
	m_imageToolBarDisable.Create( 16, 16, TRUE | ILC_COLOR24, 4, 0 );
	bm.LoadBitmap( IDB_TOOLBARDISABLE );
	m_imageToolBarDisable.Add( &bm,(CBitmap*)NULL );
	bm.Detach();
	m_wndToolBar.GetToolBarCtrl().SetDisabledImageList( &m_imageToolBarDisable );
}

/************************************************************************/
/* 创建工具栏和状态条                                                                     */
/************************************************************************/
BOOL CllzyFtpDlg::CreateStatusbar()
{
	if(!m_wndToolBar.Create(this) || !m_wndToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("Failed to Create Dialog Toolbar\n");
		return FALSE;
	}
	//设置真彩工具栏
	InitToolBar();

	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() | CBRS_SIZE_DYNAMIC | CBRS_TOOLTIPS | CBRS_FLYBY);

	//flat it
	m_wndToolBar.ModifyStyle(0,m_wndToolBar.GetStyle()|TBSTYLE_FLAT);

	//状态条
	if(m_wndStatusBar.Create(this))
	{
		m_wndStatusBar.SetIndicators(auIDStatusBar,sizeof(auIDStatusBar)/sizeof(UINT));
		m_wndStatusBar.SetPaneText(0,"FTP Server is offline",TRUE);
		m_wndStatusBar.SetPaneInfo(0,m_wndStatusBar.GetItemID(0),SBPS_STRETCH,NULL);

		SetOnlineLed(FALSE);
		SetOfflineLed(FALSE);

		m_wndStatusBar.SetPaneInfo(m_wndStatusBar.CommandToIndex(ID_INDICATOR_ONLINELED),ID_INDICATOR_ONLINELED, SBPS_NOBORDERS, 14);
		m_wndStatusBar.SetPaneInfo(m_wndStatusBar.CommandToIndex(ID_INDICATOR_OFFLINELED),ID_INDICATOR_OFFLINELED, SBPS_NOBORDERS, 14);
	}


	// We need to resize the dialog to make room for control bars.
	// First, figure out how big the control bars are.
	CRect rcClientStart;
	CRect rcClientNow;
	GetClientRect(rcClientStart);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0, reposQuery, rcClientNow);

	// Now move all the controls so they are in the same relative
	// position within the remaining client area as they would be
	// with no control bars.
	CPoint ptOffset(rcClientNow.left - rcClientStart.left, rcClientNow.top - rcClientStart.top); 

	CRect  rcChild;					
	CWnd* pwndChild = GetWindow(GW_CHILD);
	while (pwndChild)
	{                               
		pwndChild->GetWindowRect(rcChild);
		ScreenToClient(rcChild);
		rcChild.OffsetRect(ptOffset);
		pwndChild->MoveWindow(rcChild, FALSE);
		pwndChild = pwndChild->GetNextWindow();
	}

	// Adjust the dialog window dimensions
	CRect rcWindow;
	GetWindowRect(rcWindow);
	rcWindow.right += rcClientStart.Width() - rcClientNow.Width();
	rcWindow.bottom += rcClientStart.Height() - rcClientNow.Height();
	MoveWindow(rcWindow, FALSE);

	//这句RepositionBars()作用是把工具栏放置在指定的位置并显示出来
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);
	return TRUE;
}