// ӳ�����.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include"resource.h"
#include<stdio.h>
BOOL CALLBACK theProc(HWND hwndDlg,
					  UINT uMsg,
					  WPARAM wParam,
					  LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_INITDIALOG://�Ի���δ����ʱ��׼������ʼ
		MoveWindow(hwndDlg,100,80,400,300,FALSE);//���ϸ߿��Ƿ�ˢ��
		SetWindowText(hwndDlg,"���Դ��ڱ���");
		return TRUE;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDOK:
		case IDCANCEL:
			EndDialog(hwndDlg,LOWORD(wParam));
		return TRUE;
		}
		break;
    case WM_LBUTTONDOWN:
		{
		int x=LOWORD(lParam);
		int y=HIWORD(lParam);
		char s[100];
		sprintf(s,"x=%d,y=%d.",x,y);
		MessageBox(hwndDlg,s,"��ʾ",0);
		}
    return TRUE;
	case WM_MOUSEMOVE:
		{
		int x=LOWORD(lParam);
		int y=HIWORD(lParam);
		char s[100];
		sprintf(s,"x=%d,y=%d.",x,y);
		SetWindowText(hwndDlg,s);
		}
    return TRUE;
	case WM_PAINT://��ͼ��Ϣ
		{
		OutputDebugString("��ͼ��Ϣ����\n");//��ӡһЩ������Ϣ
		PAINTSTRUCT ps;
		HDC hdc=BeginPaint(hwndDlg,&ps);//��֮ǰ��������֮������ͷž��
       // Rectangle(hdc,0,0,250,250);//00�������Σ����
		Ellipse(hdc,0,0,300,200);//������Բ��
		EndPaint(hwndDlg,&ps);
		return TRUE;

		}
	}
	return FALSE;//��ʾȱʡ����ϵͳ����
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
    DialogBox(hInstance,(LPCTSTR)IDD_DIALOG1,NULL,theProc);
	return 0;
}



