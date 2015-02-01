// testerDlg.h : header file
//

#if !defined(AFX_TESTERDLG_H__9D6F4A3D_8C39_4943_8715_1D8FC2C5C586__INCLUDED_)
#define AFX_TESTERDLG_H__9D6F4A3D_8C39_4943_8715_1D8FC2C5C586__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTesterDlg dialog

class CTesterDlg : public CDialog
{
// Construction
public:
	CTesterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTesterDlg)
	// duangan. 注意下面字符串要和dialog 窗口名称保存一致.
	enum { IDD = IDHELP };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTesterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTesterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTERDLG_H__9D6F4A3D_8C39_4943_8715_1D8FC2C5C586__INCLUDED_)
