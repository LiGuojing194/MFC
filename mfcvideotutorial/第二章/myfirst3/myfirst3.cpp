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
	int id=MessageBox(NULL,"好久不见，你好吗？。","亲爱的：",MB_YESNO|MB_ICONQUESTION);
    if(id==IDYES)     MessageBox(NULL,"I miss you,but i missed you.\n只愿你好!\n","my buddy:",MB_OK);   
    else       MessageBox(NULL,"一定要开心！我一直都很在乎你。","my buddy:",MB_OK);

	return 0;
}



