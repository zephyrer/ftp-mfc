// ftp-mfcDlg.h : header file
//

#pragma once


// CftpmfcDlg dialog
class CftpmfcDlg : public CDialog
{
// Construction
public:
	CftpmfcDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_FTPMFC_DIALOG };

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
