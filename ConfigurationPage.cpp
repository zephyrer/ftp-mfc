// ConfigurationPage.cpp : implementation file
//

#include "stdafx.h"
#include "llzyFtp.h"
#include "ConfigurationPage.h"


// CConfigurationPage dialog

IMPLEMENT_DYNAMIC(CConfigurationPage, CDialog)

CConfigurationPage::CConfigurationPage(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigurationPage::IDD, pParent)
{

}

CConfigurationPage::~CConfigurationPage()
{
}

void CConfigurationPage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CConfigurationPage, CDialog)
END_MESSAGE_MAP()


// CConfigurationPage message handlers
