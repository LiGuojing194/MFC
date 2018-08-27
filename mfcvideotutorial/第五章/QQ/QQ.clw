; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPriorDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "QQ.h"

ClassCount=4
Class1=CQQApp
Class2=CQQDlg

ResourceCount=4
Resource2=IDD_DIALOG1
Resource1=IDR_MAINFRAME
Class3=login
Resource3=IDD_QQ_DIALOG
Class4=CPriorDlg
Resource4=IDD_PRIOR_DLG

[CLS:CQQApp]
Type=0
HeaderFile=QQ.h
ImplementationFile=QQ.cpp
Filter=N

[CLS:CQQDlg]
Type=0
HeaderFile=QQDlg.h
ImplementationFile=QQDlg.cpp
Filter=D
LastObject=CQQDlg
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_QQ_DIALOG]
Type=1
Class=CQQDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LOGIN,button,1342242816
Control4=IDC_PRIOR,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=login
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PASS,edit,1350631584
Control5=IDC_STATIC,static,1342308352
Control6=IDC_NAME,edit,1350631552

[CLS:login]
Type=0
HeaderFile=login.h
ImplementationFile=login.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_NAME
VirtualFilter=dWC

[DLG:IDD_PRIOR_DLG]
Type=1
Class=CPriorDlg
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_PASS,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_ADD,button,1342242816
Control9=IDC_DEL,button,1342242816
Control10=IDC_MOD,button,1342242816
Control11=IDC_LIST,SysListView32,1350631425
Control12=IDC_PRIOR,combobox,1344340226

[CLS:CPriorDlg]
Type=0
HeaderFile=PriorDlg.h
ImplementationFile=PriorDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CPriorDlg
VirtualFilter=dWC

