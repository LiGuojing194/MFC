// MFC32.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include"MyMain.h"
//MFC�ܹ����
//1.����Ҫ��CWinApp��������
//2.������ȫ��������һ�����������
//3.CWinApp�������ڱ���Ҫ���麯��InitInstance����д����
//�����MFC�����о���App���е�InitInstance������Ϊ������
//��������MFC��ƽ̨ʹ��Static Library��Shared DLL������
//��Ϣӳ��
//1.����ʹ�����򵼽���һ�������ࣨCWnd����������
//2.����ʹ�����������������,���������û��ڽ������ʱ����������Ϣ
//�ڴ����������У�ÿһ����Ϣ����һ�����Ա���������
//3.��Ϣӳ�亯��,����ͨ�����򵼣�classwizard��������
class CMyApp:public CWinApp//CwinApp�������࣬public��ʾ���ü̳з�ʽ
{
	virtual BOOL InitInstance()//�����ص����麯����Ҫ��д    ��ΪMFC��������
	{
		CMyMain dlg;
		dlg.DoModal();//����ֵ�����жϰ����ĸ���
//	AfxMessageBox("��win32����ת����MFC�������");
	return TRUE;
	};
	//virtual int ExitInstance(); // return app exit code�˳��ص�


};
CMyApp theApp;
/*int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.

	return 0;
}
*/
//MFC�в���ʹ��winmain���������Ѿ���MFC�ڲ����ӹ���


