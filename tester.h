// tester.h : main header file for the TESTER application
//

#if !defined(AFX_TESTER_H__0014B275_E5D2_4A0F_8970_91CD8E748174__INCLUDED_)
#define AFX_TESTER_H__0014B275_E5D2_4A0F_8970_91CD8E748174__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTesterApp:
// See tester.cpp for the implementation of this class
//

class CTesterApp : public CWinApp
{
public:
	CTesterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTesterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTesterApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTER_H__0014B275_E5D2_4A0F_8970_91CD8E748174__INCLUDED_)
