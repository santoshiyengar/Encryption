
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols



// Cryptography_LOA_Interfaces

class Cryptography_LOA_Interfaces : public CWinAppEx
{
public:
	Cryptography_LOA_Interfaces();

public:
	virtual BOOL InitInstance();

protected:
	DECLARE_MESSAGE_MAP()
};

extern Cryptography_LOA_Interfaces theApp;