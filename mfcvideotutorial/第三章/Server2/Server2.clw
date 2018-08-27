; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCLientSocket
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Server2.h"

ClassCount=6
Class1=CServer2App
Class2=CServer2Dlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CListenSocket
Class6=CCLientSocket
Resource2=IDD_SERVER2_DIALOG

[CLS:CServer2App]
Type=0
HeaderFile=Server2.h
ImplementationFile=Server2.cpp
Filter=N

[CLS:CServer2Dlg]
Type=0
HeaderFile=Server2Dlg.h
ImplementationFile=Server2Dlg.cpp
Filter=D



[DLG:IDD_SERVER2_DIALOG]
Type=1
Class=CServer2Dlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT,edit,1352730628

[CLS:CListenSocket]
Type=0
HeaderFile=ListenSocket.h
ImplementationFile=ListenSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq

[CLS:CCLientSocket]
Type=0
HeaderFile=CLientSocket.h
ImplementationFile=CLientSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq

