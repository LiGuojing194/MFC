; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyDlg
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "自绘按钮.h"

ClassCount=3
Class1=CMyApp
Class2=CMyDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class3=CHotButton
Resource2=IDD_MY_DIALOG

[CLS:CMyApp]
Type=0
HeaderFile=自绘按钮.h
ImplementationFile=自绘按钮.cpp
Filter=N

[CLS:CMyDlg]
Type=0
HeaderFile=自绘按钮Dlg.h
ImplementationFile=自绘按钮Dlg.cpp
Filter=D
LastObject=IDC_TRANSFORM_BTN
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_MY_DIALOG]
Type=1
Class=CMyDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TRANSFORM_BTN,button,1342242827
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_COMBO1,combobox,1344340258
Control6=IDC_STATIC,static,1342308352

[CLS:CHotButton]
Type=0
HeaderFile=HotButton.h
ImplementationFile=HotButton.cpp
BaseClass=CButton
Filter=W
LastObject=CHotButton
VirtualFilter=BWC

