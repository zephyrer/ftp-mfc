// llzyFtpDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "TracePage.h"
#include "OnlineUsersPage.h"
#include "ConfigurationPage.h"
#include "StatisticsPage.h"
#include "SecurityPage.h"

// CllzyFtpDlg dialog
class CllzyFtpDlg : public CDialog
{
// Construction
public:
	CllzyFtpDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CllzyFtpDlg();

	CTracePage	m_TracePage;
	COnlineUsersPage	m_OnlineUsersPage;
	CConfigurationPage	m_ConfigurationPage;
	CStatisticsPage		m_StatisticsPage;	
	CSecurityPage		m_SecurityPage;
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
	BOOL m_bInitialized;
	//左侧工具条
	void SetupOutlookBar();
	CImageList m_ImageList;

	//创建工具栏和状态条
	BOOL CreateStatusbar();
	CStatusBar m_wndStatusBar;
	CToolBar m_wndToolBar;

	//移动子对话框
	void MoveChilds();
	void ActivatePage(int nIndex);

	CImageList    m_imageToolBar;
	CImageList    m_imageToolBarDisable;
	void InitToolBar();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnUpdateServerStart(CCmdUI* pCmdUI);
	afx_msg void OnUpdateServerStop(CCmdUI* pCmdUI);
	afx_msg void OnUpdateUserManeg(CCmdUI* pCmdUI);
	afx_msg void OnUpdateAbout(CCmdUI* pCmdUI);

	afx_msg void OnClickOutlookBar(NMHDR* pNMHDR, LRESULT* pResult);
	//工具栏提示
	BOOL OnToolTipText(UINT, NMHDR* pNMHDR, LRESULT* pResult);
	//按钮状态
	LRESULT OnKickIdle(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_OutlookBar;
};
