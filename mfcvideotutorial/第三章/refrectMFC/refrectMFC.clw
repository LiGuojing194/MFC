; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRefrectMFCDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "refrectMFC.h"

ClassCount=3
Class1=CRefrectMFCApp
Class2=CRefrectMFCDlg

ResourceCount=3
Resource2=IDD_REFRECTMFC_DIALOG
Resource1=IDR_MAINFRAME
Class3=login
Resource3=IDD_DIALOG1

[CLS:CRefrectMFCApp]
Type=0
HeaderFile=refrectMFC.h
ImplementationFile=refrectMFC.cpp
Filter=N
LastObject=CRefrectMFCApp

[CLS:CRefrectMFCDlg]
Type=0
HeaderFile=refrectMFCDlg.h
ImplementationFile=refrectMFCDlg.cpp
Filter=D
LastObject=IDC_DATE
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_REFRECTMFC_DIALOG]
Type=1
Class=CRefrectMFCDlg
ControlCount=25
Control1=IDC_START,button,1342242816
Control2=IDC_DATE,edit,1350633600
Control3=IDC_STATIC,static,1342308352
Control4=IDC_RADIO1,button,1342177289
Control5=IDC_RADIO2,button,1342177289
Control6=IDC_STATIC,static,1342308352
Control7=IDC_RADIO3,button,1342177289
Control8=IDC_RADIO4,button,1342177289
Control9=IDC_STATIC,static,1342308352
Control10=IDC_RADIO5,button,1342177289
Control11=IDC_RADIO6,button,1342177289
Control12=IDC_STATIC,static,1342308352
Control13=IDC_RADIO7,button,1342177289
Control14=IDC_RADIO8,button,1342177289
Control15=IDC_STATIC,static,1342308352
Control16=IDC_RADIO9,button,1342177289
Control17=IDC_RADIO10,button,1342177289
Control18=IDC_STATIC,static,1342308352
Control19=IDC_FELL,edit,1350631552
Control20=IDC_STATIC,static,1342308352
Control21=IDC_REGRET,edit,1350631552
Control22=IDC_STATIC,static,1342308352
Control23=IDC_HOPE,edit,1350631552
Control24=IDC_STATIC,static,1342308352
Control25=IDOK,button,1342242817

[DLG:IDD_DIALOG1]
Type=1
Class=login
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_LOGIN,edit,1350631584
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816

[CLS:login]
Type=0
HeaderFile=login.h
ImplementationFile=login.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

