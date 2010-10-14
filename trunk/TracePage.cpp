// TracePage.cpp : implementation file
//

#include "stdafx.h"
#include "llzyFtp.h"
#include "TracePage.h"


// CTracePage dialog

IMPLEMENT_DYNAMIC(CTracePage, CDialog)

CTracePage::CTracePage(CWnd* pParent /*=NULL*/)
	: CDialog(CTracePage::IDD, pParent)
{

}

CTracePage::~CTracePage()
{
}

void CTracePage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

void CTracePage::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);

	if (IsWindow(::GetDlgItem(m_hWnd, IDC_TRACE)))
	{
		CRect rect;
		GetClientRect(rect);
		//		rect.DeflateRect(5,5,10,10);
//		m_TraceList.MoveWindow(rect);
	}
}

BEGIN_MESSAGE_MAP(CTracePage, CDialog)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CTracePage message handlers
