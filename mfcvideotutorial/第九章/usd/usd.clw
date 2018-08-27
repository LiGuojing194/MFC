; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRegDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "usd.h"

ClassCount=8
Class1=CUsdApp
Class2=CUsdDlg
Class3=CAboutDlg

ResourceCount=8
Resource1=IDD_MOD_DLG
Resource2=IDR_MAINFRAME
Resource3=IDD_REG_DLG
Resource4=IDD_PAGE3
Resource5=IDD_PAGE1
Resource6=IDD_PAGE2
Class4=CPage1
Class5=CPage2
Class6=CPage3
Class7=CRegDlg
Resource7=IDD_ABOUTBOX
Class8=CModDlg
Resource8=IDD_USD_DIALOG

[CLS:CUsdApp]
Type=0
HeaderFile=usd.h
ImplementationFile=usd.cpp
Filter=N

[CLS:CUsdDlg]
Type=0
HeaderFile=usdDlg.h
ImplementationFile=usdDlg.cpp
Filter=D
LastObject=IDC_ADD
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=usdDlg.h
ImplementationFile=usdDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_USD_DIALOG]
Type=1
Class=CUsdDlg
ControlCount=4
Control1=IDC_ADD,button,1342242816
Control2=IDC_MOD,button,1342242816
Control3=IDC_DEL,button,1342242816
Control4=IDC_LIST,SysListView32,1350631433

[DLG:IDD_REG_DLG]
Type=1
Class=CRegDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_FINISH,button,1342242816
Control4=IDC_BACK,button,1342242816

[DLG:IDD_PAGE3]
Type=1
Class=CPage3
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_TEL,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EMAIL,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_ADDR,edit,1350631552

[DLG:IDD_PAGE2]
Type=1
Class=CPage2
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BIRTH,SysDateTimePick32,1342242848
Control3=IDC_STATIC,static,1342308352
Control4=IDC_BLOOD,combobox,1344339971
Control5=IDC_STATIC,static,1342308352
Control6=IDC_HOME,edit,1350631552

[DLG:IDD_PAGE1]
Type=1
Class=CPage1
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_NUMB,edit,1350639744
Control3=IDC_STATIC,static,1342308352
Control4=IDC_NAME,edit,1350631552
Control5=IDC_STATIC,button,1342177287
Control6=IDC_SEX,button,1342308361
Control7=IDC_RADIO2,button,1342177289

[CLS:CPage1]
Type=0
HeaderFile=Page1.h
ImplementationFile=Page1.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPage1

[CLS:CPage2]
Type=0
HeaderFile=Page2.h
ImplementationFile=Page2.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:CPage3]
Type=0
HeaderFile=Page3.h
ImplementationFile=Page3.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_ADDR

[CLS:CRegDlg]
Type=0
HeaderFile=RegDlg.h
ImplementationFile=RegDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CRegDlg

[DLG:IDD_MOD_DLG]
Type=1
Class=CModDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TAB,SysTabControl32,1342177280

[CLS:CModDlg]
Type=0
HeaderFile=ModDlg.h
ImplementationFile=ModDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_TAB
VirtualFilter=dWC

