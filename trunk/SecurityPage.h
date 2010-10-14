#pragma once


// CSecurityPage dialog

class CSecurityPage : public CDialog
{
	DECLARE_DYNAMIC(CSecurityPage)

public:
	CSecurityPage(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSecurityPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_SECURITY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual	BOOL OnInitDialog();	

	DECLARE_MESSAGE_MAP()
};
