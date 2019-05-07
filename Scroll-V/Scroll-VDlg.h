
// Scroll-VDlg.h : header file
//

#pragma once


// CScrollVDlg dialog
class CScrollVDlg : public CDialogEx
{
// Construction
public:
	CScrollVDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCROLLV_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CScrollBar m_ctrlScroll;
	CString m_strEdit;
afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
static char* Country[] = { "Afghanistan", "Lesotho",
"Argentina", "Italy", "New Zealand", "Madagascar",
"Sri Lanka", "Brazil", "Gambia", "Chili", "Greece",
"Thailand", "Cuba", "Ghana", "Canada", "Mexico",
"Uganda", "Australia", "Panama", "Qatar",
"Senegal", "Turkey", "Uzbekistan", "Algeria",
"Bolivia", "Cameroon", "Finland", "United States" };