#pragma once


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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
