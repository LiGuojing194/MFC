; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CChatDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Chat.h"

ClassCount=3
Class1=CChatApp
Class2=CChatDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CHAT_DIALOG

[CLS:CChatApp]
Type=0
HeaderFile=Chat.h
ImplementationFile=Chat.cpp
Filter=N
LastObject=CChatApp

[CLS:CChatDlg]
Type=0
HeaderFile=ChatDlg.h
ImplementationFile=ChatDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDOK

[CLS:CAboutDlg]
Type=0
HeaderFile=ChatDlg.h
ImplementationFile=ChatDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CHAT_DIALOG]
Type=1
Class=CChatDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_HIST,RICHEDIT,1352734724
Control4=IDC_INPUT,edit,1350631552

