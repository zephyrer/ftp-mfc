#pragma once


// COnlineUsersPage dialog

class COnlineUsersPage : public CDialog
{
	DECLARE_DYNAMIC(COnlineUsersPage)

public:
	COnlineUsersPage(CWnd* pParent = NULL);   // standard constructor
	virtual ~COnlineUsersPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_ONLINE };
	CListCtrl	m_OnlineUsers;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()
};
