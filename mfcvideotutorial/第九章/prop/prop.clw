; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPage3
LastTemplate=CPropertyPage
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "prop.h"

ClassCount=5
Class1=CPropApp
Class2=CPropDlg

ResourceCount=5
Resource2=IDD_PROP_DIALOG
Resource3=IDD_PAGE1
Resource4=IDD_PAGE2
Resource1=IDR_MAINFRAME
Class3=CPage1
Class4=CPage2
Class5=CPage3
Resource5=IDD_PAGE3

[CLS:CPropApp]
Type=0
HeaderFile=prop.h
ImplementationFile=prop.cpp
Filter=N

[CLS:CPropDlg]
Type=0
HeaderFile=propDlg.h
ImplementationFile=propDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST



[DLG:IDD_PROP_DIALOG]
Type=1
Class=CPropDlg
ControlCount=4
Control1=IDC_ADD,button,1342242816
Control2=IDC_MOD,button,1342242816
Control3=IDC_DEL,button,1342242816
Control4=IDC_LIST,SysListView32,1350631433

[DLG:IDD_PAGE1]
Type=1
Class=CPage1
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_NUMB,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_NAME,edit,1350631552
Control5=IDC_STATIC,button,1342177287
Control6=IDC_SEX,button,1342308361
Control7=IDC_RADIO2,button,1342177289

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

[CLS:CPage1]
Type=0
HeaderFile=Page1.h
ImplementationFile=Page1.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=CPage1

[CLS:CPage2]
Type=0
HeaderFile=Page2.h
ImplementationFile=Page2.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC

[CLS:CPage3]
Type=0
HeaderFile=Page3.h
ImplementationFile=Page3.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=CPage3

