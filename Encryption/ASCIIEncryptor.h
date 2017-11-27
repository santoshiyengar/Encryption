#include <tchar.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <afxstr.h>

int randASCIISet[]={85,89,90,84,125,86,83,88,91,87,105,62,
					108,35,39,40,34,42,36,33,38,41,37,111,
					107,45,49,48,51,47,110,104,95,99,100,
					102,96,93,98,101,97,112,55,59,123,60,
					56,53,58,61,57,106,103,50,44,52,46,43,
					69,75,79,80,74,82,76,73,115,119,120,114,
					122,92,63,54,116,113,118,121,117,78,81,
					70,64,72,66,124,68,71,67,109,77,65,94};


void MyHandleError(LPTSTR psz, int nErrorNumber)
{
    _ftprintf(stderr, TEXT("An error occurred in the program. \n"));
    _ftprintf(stderr, TEXT("%s\n"), psz);
    _ftprintf(stderr, TEXT("Error number %x.\n"), nErrorNumber);
}

CString charToCStr(char* a){
	int i=0;
	CString encrPass;
	while(a[i]!='\0'){
		encrPass = encrPass + a[i++];
	}
	return(encrPass);
}

CString getEncryptedKey(
    CString pszPassword)
{
	// Declare and initialize local variables.
	char pass2bEncrypted[61]="\0", encryptedPassword[61]="\0";
	CString lenPass, p2e, encrPass;
	CString secretKey = _T("SaNvxZyUxZbXmNbZxUxIiYaMsJaHsP2a");
	int i;

	lenPass.Format(_T("%02d"),pszPassword.GetLength());
	
	p2e = lenPass + pszPassword + secretKey;
	
	USES_CONVERSION;
	strcpy (pass2bEncrypted, T2A(p2e));
	
	for(i=0; i<40;i++){
		char passChar = pass2bEncrypted[i];
		if(int(passChar)>=126) 
			encryptedPassword[i] = passChar;
		else
			encryptedPassword[i] = randASCIISet[ int(passChar) - 33];
	}

	encryptedPassword[i]='\0';
	
	encrPass = charToCStr(encryptedPassword);
	return(encrPass); 
}
