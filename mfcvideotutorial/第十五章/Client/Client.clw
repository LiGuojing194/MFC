; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CConnectSocket
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Client.h"

ClassCount=5
Class1=CClientApp
Class2=CClientDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CConnectSocket
Resource2=IDD_CLIENT_DIALOG

[CLS:CClientApp]
Type=0
HeaderFile=Client.h
ImplementationFile=Client.cpp
Filter=N

[CLS:CClientDlg]
Type=0
HeaderFile=ClientDlg.h
ImplementationFile=ClientDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_CLIENT_DIALOG]
Type=1
Class=CClientDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_HIST,edit,1352730628
Control4=IDC_INPUT,edit,1350631552

[CLS:CConnectSocket]
Type=0
HeaderFile=ConnectSocket.h
ImplementationFile=ConnectSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq

