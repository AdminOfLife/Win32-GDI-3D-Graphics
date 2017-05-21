﻿#include <Windows.h>
#include <stdlib.h>
#include "WindowManagement.h"

const int tester = 2;


int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {


	createWindowClass(hinstance);
	HWND hwnd = getHwnd(hinstance);
	if (windowSuccess(hwnd) == false) {
		return 0;
	}
	SetWindowPos(hwnd, NULL,10,10,512,512,SWP_NOMOVE);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	//create a class for easier window handling or something

	MSG Msg;

	
	screen sc(512, 512, hwnd);
	MessageBox(hwnd, L"💗 ", L"tesg", NULL);
	int i = 0;
	int j = 0;
	while (i < 512) {
		j = 0;
		while (j < 512) {
			sc.drawPx(i, j, 0x0000FF00);
			j++;
		}
		i++;
	}
	MessageBox(hwnd, L"💗 ", L"tesg", NULL);
	sc.refresh();

	while (GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}