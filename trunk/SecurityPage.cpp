// SecurityPage.cpp : implementation file
//

#include "stdafx.h"
#include "llzyFtp.h"
#include "SecurityPage.h"


// CSecurityPage dialog

IMPLEMENT_DYNAMIC(CSecurityPage, CDialog)

CSecurityPage::CSecurityPage(CWnd* pParent /*=NULL*/)
	: CDialog(CSecurityPage::IDD, pParent)
{

}

CSecurityPage::~CSecurityPage()
{
}

void CSecurityPage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BOOL CSecurityPage::OnInitDialog()
{
	CDialog::OnInitDialog();

	if (!AfxSocketInit())
	{
		AfxMessageBox("Socket³õÊ¼»¯Ê§°Ü£¡");
		return FALSE;
	}

	// get list of all ip addresses in use by this system (only show first two...)
	char szHostName[128];
	HOSTENT *lpHost=NULL;
	struct sockaddr_in sock;

	int err = gethostname(szHostName, sizeof(szHostName));
	if(err) MessageBox("SOCKET´íÎó","tips",MB_OK);
	lpHost = gethostbyname(szHostName);
	if (lpHost != NULL)
	{
		for(int i=0; lpHost->h_addr_list[i] != NULL ;i++)
		{
			memcpy(&(sock.sin_addr), lpHost->h_addr_list[i], lpHost->h_length);
			if (i == 0)
			{
				SetDlgItemText(IDC_IPADDRESS1, inet_ntoa(sock.sin_addr));
			}
			else
				if (i == 1)
				{
					SetDlgItemText(IDC_IPADDRESS2, inet_ntoa(sock.sin_addr));
				}
		}
	}
	return TRUE;
}

BEGIN_MESSAGE_MAP(CSecurityPage, CDialog)
END_MESSAGE_MAP()


// CSecurityPage message handlers
