#pragma once


// CCryptography_LOA_InterfacesDlg

class Cryptography_LOA_InterfacesDlg : public CDialog
{
	// Construction
	public:
		Cryptography_LOA_InterfacesDlg(CWnd* pParent = NULL);	// standard constructor
		enum { IDD = IDD_DIALOG1 };
		protected:
		virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


	// Implementation
	protected:
		HICON m_hIcon;
		virtual BOOL OnInitDialog();
		afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
		afx_msg void OnPaint();
		afx_msg HCURSOR OnQueryDragIcon();

	public:
		DECLARE_MESSAGE_MAP()
		afx_msg void OnBnClickedEncrypt();
		afx_msg void OnBnClickedClose();
};