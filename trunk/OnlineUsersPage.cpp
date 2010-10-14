// OnlineUsersPage.cpp : implementation file
//

#include "stdafx.h"
#include "llzyFtp.h"
#include "OnlineUsersPage.h"


// COnlineUsersPage dialog

IMPLEMENT_DYNAMIC(COnlineUsersPage, CDialog)

COnlineUsersPage::COnlineUsersPage(CWnd* pParent /*=NULL*/)
	: CDialog(COnlineUsersPage::IDD, pParent)
{

}

COnlineUsersPage::~COnlineUsersPage()
{
}

void COnlineUsersPage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ONLINE_USERS, m_OnlineUsers);
}

BOOL COnlineUsersPage::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_OnlineUsers.InsertColumn(0, "ThreadID");		
	m_OnlineUsers.InsertColumn(1, "Username");	
	m_OnlineUsers.InsertColumn(2, "IP Adress");	
	m_OnlineUsers.InsertColumn(3, "Login Time");

	DWORD dwStyle = m_OnlineUsers.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	m_OnlineUsers.SetExtendedStyle(dwStyle);
	return TRUE;
}

void COnlineUsersPage::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);

	if (IsWindow(::GetDlgItem(m_hWnd, IDC_ONLINE_USERS)))
	{
		CRect rect;
		GetClientRect(rect);
		m_OnlineUsers.MoveWindow(rect);
		m_OnlineUsers.SetColumnWidth(0, 0);
		m_OnlineUsers.SetColumnWidth(1, rect.Width()/3-2);
		m_OnlineUsers.SetColumnWidth(2, rect.Width()/3-2);
		m_OnlineUsers.SetColumnWidth(3, rect.Width()/3-2);
	}	
}

BEGIN_MESSAGE_MAP(COnlineUsersPage, CDialog)
		ON_WM_SIZE()
END_MESSAGE_MAP()


// COnlineUsersPage message handlers
