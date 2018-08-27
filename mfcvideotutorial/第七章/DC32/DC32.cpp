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
	{//����꿿�������л�����ͬ�Ŀؼ�ʱ�ص�
	case WM_SETCURSOR:
		{
		 HWND hwnd=(HWND)wParam;
		 if(hwnd!=GetDlgItem(hwndDlg,IDOK))
			 return TRUE;
		 RECT rect;
		 GetWindowRect(hwnd,&rect);//��ȡ��ť����Ļ����
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
		 //��һ��Բ��
		 Ellipse(hdc,x-10,y-10,x+10,y+10);
		 //�ͷŻ�ͼ����������GetDC�ɶ�ʹ��
		 ReleaseDC(hwndDlg,hdc);
         return TRUE;
		}
	case WM_NCPAINT:
		{//��ȡ�봰�ڹ����ķǿͻ�����ͼ���
			HDC hdc=GetWindowDC(hwndDlg);
			RECT rect;
			GetWindowRect(hwndDlg,&rect);//��ȡ�������ڵĿռ�����
			Rectangle(hdc,0,0,rect.right -rect.left ,rect.bottom -rect.top );
			char str[200];
			sprintf(str,"�ǿͻ����ռ�(%d,%d,%d,%d)",
				rect.left ,rect.top,rect.right ,rect.bottom);
			SetTextColor(hdc,RGB(255,0,0));
			TextOut(hdc,5,5,str,strlen(str));//�������
			//ReleaseDC�ͷŷǿͻ�����ͼ�����������GetWindowDC�ɶ�ʹ��
			
			ReleaseDC(hwndDlg,hdc);
			return TRUE;
			
		}
	case WM_MOVE:
		{
			SendMessage(hwndDlg,WM_NCPAINT,0,0);//ǿ��ˢ�·ǿͻ���
			InvalidateRect(hwndDlg,NULL,TRUE);//ǿ��ˢ�¿ͻ���
			return TRUE;
		}
	case WM_COMMAND://����ȡ����ťʱ�رնԻ���
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
				//��ȡ�봰�ڿͻ��������Ļ�ͼ���
				HDC hdc=BeginPaint(hwndDlg,&ps);
				//����������
				Rectangle(hdc,0,0,40,40);
				Rectangle(hdc,80,80,120,120);
				//��һ����
				MoveToEx(hdc,20,20,NULL);
				LineTo(hdc,100,100);
				//EndPaint�����ͻ����滭�������BeginPaint�ɶ�ʹ��
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



