
// Scroll-VDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Scroll-V.h"
#include "Scroll-VDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CScrollVDlg dialog



CScrollVDlg::CScrollVDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SCROLLV_DIALOG, pParent)
	, m_strEdit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScrollVDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_ctrlScroll);
	DDX_Text(pDX, IDC_EDIT1, m_strEdit);
}

BEGIN_MESSAGE_MAP(CScrollVDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_VSCROLL()
END_MESSAGE_MAP()


// CScrollVDlg message handlers

BOOL CScrollVDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_ctrlScroll.SetScrollRange(0, 27);
	SetDlgItemText(IDC_POSITION, _T("0"));
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CScrollVDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CScrollVDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CScrollVDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CScrollVDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default
	int CurPos = m_ctrlScroll.GetScrollPos();
	// Determin? noua pozi?ia a scroll-ului
	switch (nSBCode)
	{
	case SB_THUMBPOSITION: // Scroll pân? la
	//pozi?ia absolut?. nPos este
		CurPos = nPos; // pozi?ia final? a
		//scoll-ului
		break;
	case SB_THUMBTRACK: // Trage scroll-ul
	//la pozi?ia dat?. nPos este
		CurPos = nPos; // pozitia final? a
		//scroll-ului
		break;
	case SB_LEFT: // Scroll la cap?tul stâng.
		CurPos = 0;
		break;
	case SB_RIGHT: // Scroll la cap?tul drept.
		CurPos = 27;
		break;
	case SB_ENDSCROLL: // Scroll final.
		break;
	case SB_LINELEFT: // Scroll la stânga.
		if (CurPos > 0)
			CurPos--;
		break;
	case SB_LINERIGHT: // Scroll la dreapta.
		if (CurPos < 27)
			CurPos++;
		break;
	}
	// Set the new position of the thumb (scroll
	//box).
	m_ctrlScroll.SetScrollPos(CurPos);
	CString szPosition;
	szPosition.Format(_T("%d"), CurPos);
	SetDlgItemText(IDC_POSITION, szPosition);
	m_strEdit.Format(_T("%s"), Country[CurPos]);
	UpdateData(FALSE);
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}
