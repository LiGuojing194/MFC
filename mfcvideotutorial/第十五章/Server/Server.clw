; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CClientSocket
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Server.h"

ClassCount=4
Class1=CServerApp
Class2=CServerDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class3=CListenSocket
Class4=CClientSocket
Resource2=IDD_SERVER_DIALOG

[CLS:CServerApp]
Type=0
HeaderFile=Server.h
ImplementationFile=Server.cpp
Filter=N
LastObject=CServerApp

[CLS:CServerDlg]
Type=0
HeaderFile=ServerDlg.h
ImplementationFile=ServerDlg.cpp
Filter=D



[DLG:IDD_SERVER_DIALOG]
Type=1
Class=CServerDlg
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

[CLS:CClientSocket]
Type=0
HeaderFile=ClientSocket.h
ImplementationFile=ClientSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq

