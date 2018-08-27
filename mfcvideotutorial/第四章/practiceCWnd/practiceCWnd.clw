; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyList
LastTemplate=CListCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "practiceCWnd.h"

ClassCount=4
Class1=CPracticeCWndApp
Class2=CPracticeCWndDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class3=mybutton
Class4=CMyList
Resource2=IDD_PRACTICECWND_DIALOG

[CLS:CPracticeCWndApp]
Type=0
HeaderFile=practiceCWnd.h
ImplementationFile=practiceCWnd.cpp
Filter=N

[CLS:CPracticeCWndDlg]
Type=0
HeaderFile=practiceCWndDlg.h
ImplementationFile=practiceCWndDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CPracticeCWndDlg



[DLG:IDD_PRACTICECWND_DIALOG]
Type=1
Class=CPracticeCWndDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816
Control5=IDC_BUTTON3,button,1342242816
Control6=IDC_BUTTON4,button,1342242816
Control7=IDC_BUTTON5,button,1342242816
Control8=IDC_EDIT1,edit,1350631552
Control9=IDC_BUTTON6,button,1342242816
Control10=IDC_BUTTON7,button,1342242816

[CLS:mybutton]
Type=0
HeaderFile=mybutton.h
ImplementationFile=mybutton.cpp
BaseClass=CWnd
Filter=W
LastObject=mybutton
VirtualFilter=WC

[CLS:CMyList]
Type=0
HeaderFile=MyList.h
ImplementationFile=MyList.cpp
BaseClass=CListCtrl
Filter=W
LastObject=CMyList

