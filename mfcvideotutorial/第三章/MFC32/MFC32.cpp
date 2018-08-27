// MFC32.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include"MyMain.h"
//MFC架构组成
//1.必须要有CWinApp的派生类
//2.必须在全局区定义一个派生类对象
//3.CWinApp派生类内必须要有虚函数InitInstance的重写函数
//今后在MFC工程中就以App类中的InitInstance函数作为主函数
//另外连接MFC的平台使用Static Library或Shared DLL都可以
//消息映射
//1.必须使用类向导建立一个窗口类（CWnd）的派生类
//2.必须使用派生类来定义对象,用来接收用户在界面操作时所产生的消息
//在窗口派生类中，每一个消息都与一个类成员函数相关联
//3.消息映射函数,必须通过类向导（classwizard）来建立
class CMyApp:public CWinApp//CwinApp的派生类，public表示公用继承方式
{
	virtual BOOL InitInstance()//启动回调，虚函数需要重写    作为MFC的主函数
	{
		CMyMain dlg;
		dlg.DoModal();//返回值用来判断按了哪个键
//	AfxMessageBox("由win32工程转换成MFC软件工程");
	return TRUE;
	};
	//virtual int ExitInstance(); // return app exit code退出回调


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
//MFC中不再使用winmain函数，它已经在MFC内部被接管了


