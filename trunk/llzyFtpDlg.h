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

	void SetupOutlookBar();
	CImageList m_ImageList;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_OutlookBar;
};
