#pragma once
//#include "ColorListBox.h"

// CTracePage dialog

class CTracePage : public CDialog
{
	DECLARE_DYNAMIC(CTracePage)

public:
	CTracePage(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTracePage();

//	void AddTraceLine(int nLevel,LPCTSTR pstrFormat,...);
// Dialog Data
	enum { IDD = IDD_PROPPAGE_TRACE };
//	CColorListBox	m_TraceList;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()
};
