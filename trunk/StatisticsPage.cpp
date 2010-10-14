// StatisticsPage.cpp : implementation file
//

#include "stdafx.h"
#include "llzyFtp.h"
#include "StatisticsPage.h"


// CStatisticsPage dialog

IMPLEMENT_DYNAMIC(CStatisticsPage, CDialog)

CStatisticsPage::CStatisticsPage(CWnd* pParent /*=NULL*/)
	: CDialog(CStatisticsPage::IDD, pParent)
{

}

CStatisticsPage::~CStatisticsPage()
{
}

void CStatisticsPage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATISTICS, m_StatisticsCtrl);
}

BOOL CStatisticsPage::OnInitDialog() 
{
	CDialog::OnInitDialog();


	m_StatisticsCtrl.InsertColumn(0, "统计");		
	m_StatisticsCtrl.InsertColumn(1, "数值");	

	/*
	m_StatisticsCtrl.InsertItem(0, "Total Connections");
	m_StatisticsCtrl.SetItemText(0, 1, "0");
	m_StatisticsCtrl.InsertItem(1, "Current Connections");
	m_StatisticsCtrl.SetItemText(1, 1, "0");
	m_StatisticsCtrl.InsertItem(2, "Files Downloaded");
	m_StatisticsCtrl.SetItemText(2, 1, "0");
	m_StatisticsCtrl.InsertItem(3, "Files Uploaded");
	m_StatisticsCtrl.SetItemText(3, 1, "0");
	m_StatisticsCtrl.InsertItem(4, "Failed Downloads");
	m_StatisticsCtrl.SetItemText(4, 1, "0");
	m_StatisticsCtrl.InsertItem(5, "Failed Uploads");
	m_StatisticsCtrl.SetItemText(5, 1, "0");
	m_StatisticsCtrl.InsertItem(6, "Total kilobytes received");
	m_StatisticsCtrl.SetItemText(6, 1, "0");
	m_StatisticsCtrl.InsertItem(7, "Total kilobytes sent");
	m_StatisticsCtrl.SetItemText(7, 1, "0");
	*/

	DWORD dwStyle = m_StatisticsCtrl.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	m_StatisticsCtrl.SetExtendedStyle(dwStyle);

	return TRUE;
}

void CStatisticsPage::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);

	if (IsWindow(::GetDlgItem(m_hWnd, IDC_STATISTICS)))
	{
		CRect rect;
		GetClientRect(rect);
		m_StatisticsCtrl.MoveWindow(rect);
		m_StatisticsCtrl.SetColumnWidth(0, rect.Width()*0.3-2);
		m_StatisticsCtrl.SetColumnWidth(1, rect.Width()*0.6-2);
	}	
}

BEGIN_MESSAGE_MAP(CStatisticsPage, CDialog)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CStatisticsPage message handlers
