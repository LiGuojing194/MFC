; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNotePadDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NotePad.h"

ClassCount=2
Class1=CNotePadApp
Class2=CNotePadDlg

ResourceCount=4
Resource2=IDR_MAINFRAME
Resource3=IDD_NOTEPAD_DIALOG
Resource4=IDR_MENU1

[CLS:CNotePadApp]
Type=0
HeaderFile=NotePad.h
ImplementationFile=NotePad.cpp
Filter=N

[CLS:CNotePadDlg]
Type=0
HeaderFile=NotePadDlg.h
ImplementationFile=NotePadDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_FILE_SAVE



[DLG:IDD_NOTEPAD_DIALOG]
Type=1
Class=CNotePadDlg
ControlCount=1
Control1=IDC_EDIT1,edit,1352733700

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_FILE_OPEN
Command2=ID_FILE_SAVE
Command3=ID_FILE_EXIT
CommandCount=3

