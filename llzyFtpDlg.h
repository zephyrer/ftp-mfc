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

	//LED��
	void SetOnlineLed(BOOL bOnline);
	void SetOfflineLed(BOOL bOffline);
	//��๤����
	void SetupOutlookBar();
	CImageList m_ImageList;

	//������������״̬��
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
