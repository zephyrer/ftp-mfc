// llzyFtpDlg.h : header file
//

#pragma once
#include "afxcmn.h"


// CllzyFtpDlg dialog
class CllzyFtpDlg : public CDialog
{
// Construction
public:
	CllzyFtpDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_LLZYFTP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	//LED灯
	void SetOnlineLed(BOOL bOnline);
	void SetOfflineLed(BOOL bOffline);
	//左侧工具条
	void SetupOutlookBar();
	CImageList m_ImageList;

	//创建工具栏和状态条
	BOOL CreateStatusbar();
	CStatusBar m_wndStatusBar;
	CToolBar m_wndToolBar;

	CImageList    m_imageToolBar;
	CImageList    m_imageToolBarDisable;
	void InitToolBar();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_OutlookBar;
};
