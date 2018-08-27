; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTestDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "test.h"

ClassCount=3
Class1=CTestApp
Class2=CTestDlg

ResourceCount=3
Resource2=IDD_TEST_DIALOG
Resource1=IDR_MAINFRAME
Class3=ABOUTDLG
Resource3=IDD_ABOUT

[CLS:CTestApp]
Type=0
HeaderFile=test.h
ImplementationFile=test.cpp
Filter=N

[CLS:CTestDlg]
Type=0
HeaderFile=testDlg.h
ImplementationFile=testDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CTestDlg



[DLG:IDD_TEST_DIALOG]
Type=1
Class=CTestDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816

[DLG:IDD_ABOUT]
Type=1
Class=ABOUTDLG
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342177283
Control3=IDC_STATIC,static,1342308352

[CLS:ABOUTDLG]
Type=0
HeaderFile=ABOUTDLG.h
ImplementationFile=ABOUTDLG.cpp
BaseClass=CDialog
Filter=D
LastObject=ABOUTDLG

