// myfirst3.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include"resource.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	int id=MessageBox(NULL,"�þò���������𣿡�","�װ��ģ�",MB_YESNO|MB_ICONQUESTION);
    if(id==IDYES)     MessageBox(NULL,"I miss you,but i missed you.\nֻԸ���!\n","my buddy:",MB_OK);   
    else       MessageBox(NULL,"һ��Ҫ���ģ���һֱ�����ں��㡣","my buddy:",MB_OK);

	return 0;
}



