; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTest2Dlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "test2.h"

ClassCount=4
Class1=CTest2App
Class2=CTest2Dlg

ResourceCount=4
Resource2=IDD_TEST2_DIALOG
Resource1=IDR_MAINFRAME
Class3=ABOUTDLG
Resource3=IDD_ABOUT
Class4=CChatDlg
Resource4=IDD_CHAT_DLG

[CLS:CTest2App]
Type=0
HeaderFile=test2.h
ImplementationFile=test2.cpp
Filter=N

[CLS:CTest2Dlg]
Type=0
HeaderFile=test2Dlg.h
ImplementationFile=test2Dlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CTest2Dlg



[DLG:IDD_TEST2_DIALOG]
Type=1
Class=CTest2Dlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816
Control5=IDC_BUTTON3,button,1342242816
Control6=IDC_BUTTON4,button,1342242816
Control7=IDC_STATIC,static,1342177294

[DLG:IDD_ABOUT]
Type=1
Class=ABOUTDLG
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342177294
Control3=IDC_STATIC,static,1342308352

[CLS:ABOUTDLG]
Type=0
HeaderFile=ABOUTDLG.h
ImplementationFile=ABOUTDLG.cpp
BaseClass=CDialog
Filter=D
LastObject=ABOUTDLG

[DLG:IDD_CHAT_DLG]
Type=1
Class=CChatDlg
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_HIST,edit,1352728708
Control4=IDC_INPU,edit,1352728708
Control5=IDC_STATIC,static,1342177287
Control6=IDC_STATIC,static,1342177287
Control7=IDC_STATIC,static,1342177287
Control8=IDC_STATIC,static,1342177287
Control9=IDC_STATIC,static,1342177294

[CLS:CChatDlg]
Type=0
HeaderFile=ChatDlg.h
ImplementationFile=ChatDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CChatDlg
VirtualFilter=dWC

