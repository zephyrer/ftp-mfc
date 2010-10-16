// ConfigurationPage.cpp : implementation file
//

#include "stdafx.h"
#include "llzyFtp.h"
#include "ConfigurationPage.h"


// CConfigurationPage dialog

IMPLEMENT_DYNAMIC(CConfigurationPage, CDialog)

CConfigurationPage::CConfigurationPage(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigurationPage::IDD, pParent)
	, m_nMaxUsers(0)
	, m_nKeeptime(0)
{
	// read settings
	m_nPort = AfxGetApp()->GetProfileInt("ftp_Settings", "Port", 1988);
	m_nMaxUsers = AfxGetApp()->GetProfileInt("ftp_Settings", "MaxUsers", 1000);
	m_nKeeptime = AfxGetApp()->GetProfileInt("ftp_Settings", "Keeptime", 5);
	m_strWelcomeMessage = AfxGetApp()->GetProfileString("ftp_Settings", "WelcomeMsg", "爷，您来了");
	m_strGoodbyeMessage = AfxGetApp()->GetProfileString("ftp_Settings", "GoobyeMsg", "再来打死丫！");

	m_bModified = FALSE;
}

CConfigurationPage::~CConfigurationPage()
{
}

void CConfigurationPage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PORT, m_nPort);
	DDX_Text(pDX, IDC_MAX_USERS, m_nMaxUsers);
	DDX_Text(pDX, IDC_TIMEOUT, m_nKeeptime);
	DDX_Text(pDX, IDC_WELCOME_MSG, m_strWelcomeMessage);
	DDX_Text(pDX, IDC_GOODBYE_MSG, m_strGoodbyeMessage);
}

void CConfigurationPage::OnDestroy() 
{
	UpdateData();

	// save settings
	AfxGetApp()->WriteProfileInt("ftp_Settings", "Port", m_nPort);
	AfxGetApp()->WriteProfileInt("ftp_Settings", "MaxUsers", m_nMaxUsers);
	AfxGetApp()->WriteProfileInt("ftp_Settings", "Keeptime", m_nKeeptime);
	AfxGetApp()->WriteProfileString("ftp_Settings", "WelcomeMsg", m_strWelcomeMessage); 
	AfxGetApp()->WriteProfileString("ftp_Settings", "GoodbyeMsg", m_strGoodbyeMessage); 
	CDialog::OnDestroy();
}

BEGIN_MESSAGE_MAP(CConfigurationPage, CDialog)
	ON_WM_DESTROY()
	ON_EN_CHANGE(IDC_PORT, OnSomethingChanged)
END_MESSAGE_MAP()


// CConfigurationPage message handlers
void CConfigurationPage::OnSomethingChanged() 
{
	m_bModified = TRUE;	
	UpdateDialogControls(this, FALSE);	
}
