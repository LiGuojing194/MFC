// DC32.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include"resource.h"
#include<stdio.h>
void ScreenToClient(HWND hwndParent,RECT &rect)
{
	POINT lt={rect.left ,rect.top };
	POINT rb={rect.right ,rect.bottom };
	ScreenToClient(hwndParent,&lt);
	ScreenToClient(hwndParent,&lt);
	rect.left=lt.x;
	rect.top =lt.y;
	rect.right =rb.x;
	rect.bottom =rb.y ;
}
BOOL CALLBACK dlgFunc(HWND hwndDlg,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	switch(uMsg)
	{//当鼠标靠近或者切换到不同的控件时回调
	case WM_SETCURSOR:
		{
		 HWND hwnd=(HWND)wParam;
		 if(hwnd!=GetDlgItem(hwndDlg,IDOK))
			 return TRUE;
		 RECT rect;
		 GetWindowRect(hwnd,&rect);//获取按钮的屏幕坐标
         ScreenToClient(hwndDlg,rect);
		 rect.left -=100;
		 rect.right +=100;
		 MoveWindow(hwnd,rect.left ,rect.top,rect.right -rect.left,rect.bottom -rect.top ,TRUE);
		 return TRUE;
		}
	case WM_LBUTTONDOWN:
		{
		 HDC hdc=GetDC(hwndDlg);
		 int x=LOWORD(lParam);
		 int y=HIWORD(lParam);
		 //画一个圆形
		 Ellipse(hdc,x-10,y-10,x+10,y+10);
		 //释放绘图句柄，必须跟GetDC成对使用
		 ReleaseDC(hwndDlg,hdc);
         return TRUE;
		}
	case WM_NCPAINT:
		{//获取与窗口关联的非客户区绘图句柄
			HDC hdc=GetWindowDC(hwndDlg);
			RECT rect;
			GetWindowRect(hwndDlg,&rect);//获取整个窗口的空间区域
			Rectangle(hdc,0,0,rect.right -rect.left ,rect.bottom -rect.top );
			char str[200];
			sprintf(str,"非客户区空间(%d,%d,%d,%d)",
				rect.left ,rect.top,rect.right ,rect.bottom);
			SetTextColor(hdc,RGB(255,0,0));
			TextOut(hdc,5,5,str,strlen(str));//输出文字
			//ReleaseDC释放非客户区绘图句柄，必须与GetWindowDC成对使用
			
			ReleaseDC(hwndDlg,hdc);
			return TRUE;
			
		}
	case WM_MOVE:
		{
			SendMessage(hwndDlg,WM_NCPAINT,0,0);//强制刷新非客户区
			InvalidateRect(hwndDlg,NULL,TRUE);//强制刷新客户区
			return TRUE;
		}
	case WM_COMMAND://单击取消按钮时关闭对话框
		switch(wParam)
		{
		case IDCANCEL:
			EndDialog(hwndDlg,IDCANCEL);
			break;
		}
		break;
		case WM_PAINT:
			{
				PAINTSTRUCT ps;
				//获取与窗口客户区关联的绘图句柄
				HDC hdc=BeginPaint(hwndDlg,&ps);
				//画两个矩形
				Rectangle(hdc,0,0,40,40);
				Rectangle(hdc,80,80,120,120);
				//画一条线
				MoveToEx(hdc,20,20,NULL);
				LineTo(hdc,100,100);
				//EndPaint结束客户区绘画，必须和BeginPaint成对使用
				EndPaint(hwndDlg,&ps);
			}
			break;
	}
	return FALSE;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// TODO: Place code here.
	DialogBox(hInstance,(LPCTSTR)IDD_PAINT_DLG,NULL,dlgFunc);
	return 0;
}



