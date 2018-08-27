; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CClientSocket
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "s.h"

ClassCount=4
Class1=CSApp
Class2=CSDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class3=CListenSocket
Class4=CClientSocket
Resource2=IDD_S_DIALOG

[CLS:CSApp]
Type=0
HeaderFile=s.h
ImplementationFile=s.cpp
Filter=N

[CLS:CSDlg]
Type=0
HeaderFile=sDlg.h
ImplementationFile=sDlg.cpp
Filter=D



[DLG:IDD_S_DIALOG]
Type=1
Class=CSDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

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
LastObject=CClientSocket

