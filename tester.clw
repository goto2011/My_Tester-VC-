; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTesterDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "tester.h"

ClassCount=3
Class1=CTesterApp
Class2=CTesterDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TESTER_DIALOG

[CLS:CTesterApp]
Type=0
HeaderFile=tester.h
ImplementationFile=tester.cpp
Filter=N

[CLS:CTesterDlg]
Type=0
HeaderFile=testerDlg.h
ImplementationFile=testerDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT_END

[CLS:CAboutDlg]
Type=0
HeaderFile=testerDlg.h
ImplementationFile=testerDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TESTER_DIALOG]
Type=1
Class=CTesterDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_START,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_END,edit,1350631552
Control8=IDC_EDIT_RESULT,edit,1350631552

