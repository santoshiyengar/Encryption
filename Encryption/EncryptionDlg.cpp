
#include "stdafx.h"
#include "Encryption.h"
#include "EncryptionDlg.h"
#include "ASCIIEncryptor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

Cryptography_LOA_InterfacesDlg::Cryptography_LOA_InterfacesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cryptography_LOA_InterfacesDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cryptography_LOA_InterfacesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cryptography_LOA_InterfacesDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
   ON_BN_CLICKED(ID_ENCRYPT, &Cryptography_LOA_InterfacesDlg::OnBnClickedEncrypt)
   ON_BN_CLICKED(IDCLOSE, &Cryptography_LOA_InterfacesDlg::OnBnClickedClose)
END_MESSAGE_MAP()

BOOL Cryptography_LOA_InterfacesDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	ASSERT((IDM_ABOUTBOX & 0x0010) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0x00F0);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	GotoDlgCtrl(GetDlgItem(IDC_EDIT2)); 

	return FALSE;
}

void Cryptography_LOA_InterfacesDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void Cryptography_LOA_InterfacesDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cryptography_LOA_InterfacesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Cryptography_LOA_InterfacesDlg::OnBnClickedEncrypt()
{
	CString password, encryptedKey;
	GetDlgItemText(IDC_EDIT2, password);

	if(password.IsEmpty())
	{
		AfxMessageBox(_T("Password is Empty!!"));
	}
	encryptedKey = getEncryptedKey(password);
	SetDlgItemText(IDC_EDIT3, encryptedKey);
}


void Cryptography_LOA_InterfacesDlg::OnBnClickedClose()
{
	CDialog::OnOK();
}
