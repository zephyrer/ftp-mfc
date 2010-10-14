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


BEGIN_MESSAGE_MAP(CSecurityPage, CDialog)
END_MESSAGE_MAP()


// CSecurityPage message handlers
