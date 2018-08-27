// 映射测试.cpp : Defines the entry point for the application.
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
	case WM_INITDIALOG://对话框还未出来时的准备、初始
		MoveWindow(hwndDlg,100,80,400,300,FALSE);//左上高宽，是否刷新
		SetWindowText(hwndDlg,"测试窗口标题");
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
		MessageBox(hwndDlg,s,"提示",0);
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
	case WM_PAINT://绘图消息
		{
		OutputDebugString("绘图消息来临\n");//打印一些调制信息
		PAINTSTRUCT ps;
		HDC hdc=BeginPaint(hwndDlg,&ps);//画之前求句柄，画之后必须释放句柄
       // Rectangle(hdc,0,0,250,250);//00处画矩形，宽高
		Ellipse(hdc,0,0,300,200);//绘制椭圆。
		EndPaint(hwndDlg,&ps);
		return TRUE;

		}
	}
	return FALSE;//表示缺省交由系统处理
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



