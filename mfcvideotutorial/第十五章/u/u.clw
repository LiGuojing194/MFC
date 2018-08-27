; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSocku
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "u.h"

ClassCount=3
Class1=CUApp
Class2=CUDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class3=CSocku
Resource2=IDD_U_DIALOG

[CLS:CUApp]
Type=0
HeaderFile=u.h
ImplementationFile=u.cpp
Filter=N

[CLS:CUDlg]
Type=0
HeaderFile=uDlg.h
ImplementationFile=uDlg.cpp
Filter=D
LastObject=IDCANCEL
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_U_DIALOG]
Type=1
Class=CUDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_IP,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_PORT,edit,1350631552
Control7=IDC_HIST,edit,1352728580
Control8=IDC_INPUT,edit,1350631552

[CLS:CSocku]
Type=0
HeaderFile=Socku.h
ImplementationFile=Socku.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq

