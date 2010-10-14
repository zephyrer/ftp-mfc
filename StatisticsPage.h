#pragma once
#include "afxcmn.h"


// CStatisticsPage dialog

class CStatisticsPage : public CDialog
{
	DECLARE_DYNAMIC(CStatisticsPage)

public:
	CStatisticsPage(CWnd* pParent = NULL);   // standard constructor
	virtual ~CStatisticsPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_SECURITY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_StatisticsCtrl;
};
