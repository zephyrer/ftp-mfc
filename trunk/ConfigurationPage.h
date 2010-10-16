#pragma once
#include "afxwin.h"


// CConfigurationPage dialog

class CConfigurationPage : public CDialog
{
	DECLARE_DYNAMIC(CConfigurationPage)

public:
	CConfigurationPage(CWnd* pParent = NULL);   // standard constructor
	virtual ~CConfigurationPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_CONFIGURATION };

protected:
	BOOL m_bModified;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	afx_msg void OnDestroy();
	afx_msg void OnSomethingChanged();
	DECLARE_MESSAGE_MAP()
public:
	int m_nPort;
	int m_nMaxUsers;
	int m_nKeeptime;
	CString	m_strWelcomeMessage;
	CString	m_strGoodbyeMessage;
};
