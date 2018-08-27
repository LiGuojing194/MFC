; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRegDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "动态心型线.h"

ClassCount=5
Class1=CMyApp
Class2=CMyDlg

ResourceCount=5
Resource2=IDD_MY_DIALOG
Resource3=IDD_DIALOG1
Resource4=IDD_DIALOG2
Resource1=IDR_MAINFRAME
Class3=CPage2
Class4=CPage1
Class5=CRegDlg
Resource5=IDD_DIALOG3

[CLS:CMyApp]
Type=0
HeaderFile=动态心型线.h
ImplementationFile=动态心型线.cpp
Filter=N

[CLS:CMyDlg]
Type=0
HeaderFile=动态心型线Dlg.h
ImplementationFile=动态心型线Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BUTTON1



[DLG:IDD_MY_DIALOG]
Type=1
Class=CMyDlg
ControlCount=4
Control1=IDOK,button,1342242827
Control2=IDCANCEL,button,1342242827
Control3=IDC_STATIC,static,1342308865
Control4=IDC_BUTTON1,button,1476460555

[DLG:IDD_DIALOG1]
Type=1
Class=CPage1
ControlCount=0

[DLG:IDD_DIALOG2]
Type=1
Class=CPage2
ControlCount=2
Control1=IDC_BUTTON1,button,1342242880
Control2=IDC_BUTTON2,button,1342242880

[DLG:IDD_DIALOG3]
Type=1
Class=CRegDlg
ControlCount=9
Control1=IDOK,button,1342242827
Control2=IDCANCEL,button,1342242827
Control3=IDC_BACK,button,1342242827
Control4=IDC_STATIC,static,1342308352
Control5=IDC_BUTTON1,button,1476460544
Control6=IDC_BUTTON2,button,1476460544
Control7=IDC_BUTTON3,button,1476460544
Control8=IDC_BUTTON4,button,1476460544
Control9=IDC_BUTTON5,button,1342242880

[CLS:CPage2]
Type=0
HeaderFile=Page2.h
ImplementationFile=Page2.cpp
BaseClass=CDialog
Filter=C
LastObject=IDC_BUTTON2
VirtualFilter=dWC

[CLS:CPage1]
Type=0
HeaderFile=Page1.h
ImplementationFile=Page1.cpp
BaseClass=CDialog
Filter=C
LastObject=IDOK
VirtualFilter=dWC

[CLS:CRegDlg]
Type=0
HeaderFile=RegDlg.h
ImplementationFile=RegDlg.cpp
BaseClass=CDialog
Filter=W
LastObject=CRegDlg
VirtualFilter=dWC

