; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLoginDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TestMFC.h"

ClassCount=3
Class1=CTestMFCApp
Class2=CTestMFCDlg

ResourceCount=3
Resource2=IDD_TESTMFC_DIALOG
Resource1=IDR_MAINFRAME
Class3=CLoginDlg
Resource3=IDD_LOGIN_DLG

[CLS:CTestMFCApp]
Type=0
HeaderFile=TestMFC.h
ImplementationFile=TestMFC.cpp
Filter=N
LastObject=CTestMFCApp

[CLS:CTestMFCDlg]
Type=0
HeaderFile=TestMFCDlg.h
ImplementationFile=TestMFCDlg.cpp
Filter=D
LastObject=CTestMFCDlg



[DLG:IDD_TESTMFC_DIALOG]
Type=1
Class=CTestMFCDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[DLG:IDD_LOGIN_DLG]
Type=1
Class=CLoginDlg
ControlCount=6
Control1=IDC_STACTIC1,static,1342308352
Control2=IDC_NAME,edit,1350631552
Control3=IDC_STACTIC2,static,1342308352
Control4=IDC_PASS,edit,1350631584
Control5=IDOK,button,1342242817
Control6=IDCANCEL,button,1342242816

[CLS:CLoginDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CLoginDlg
VirtualFilter=dWC

