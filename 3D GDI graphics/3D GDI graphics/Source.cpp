﻿#include <Windows.h>
#include <stdlib.h>
#include "WindowManagement.h"
#include "3DComponents.h"
#include "Base3D.h"


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
	

	World mainWorld;

	camera mainCamera(mainWorld.createPoint(0,0,0),angle(false, 90));
	mainWorld.cameras.push_back(mainCamera);
	mainWorld.activeCamera = (mainWorld.cameras[mainWorld.cameras.size()-1]);

	Point p1 = Point(0,0,100);
	Point p2 = Point(30, 0, 100);
	Point p3 = Point(0, 30, 100);

	vector<UniversalPoint> points;
	points.push_back(mainWorld.createPoint(p1));
	points.push_back(mainWorld.createPoint(p2));
	points.push_back(mainWorld.createPoint(p3));

	Face face = Face(points);

	Object3D obj;
	obj.faces.push_back(face);
	
	mainWorld.objects.push_back(obj);

	while (1 != 0) {
		mainWorld.draw(sc);
	}

	while (GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}
