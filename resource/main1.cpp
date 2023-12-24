#include"Particle.h"
#include<math.h>
#include<iostream> 
#include <graphics.h>		// 引用图形库头文件




void main() {

	initeffeVen(10);
	initVenPartInf(1000,1000,1000,10,10,10);
	initPartHouse();
	FUpPInit();
	unsigned senwi = 640;
	unsigned senhi = 480;
	initgraph(senwi, senhi);
	setorigin(0,senhi);
	setaspectratio(1, -1);


	Point* ptgrp;
	VenInform pv = {NULL};
	LONGLONGThrArr cor;
	cor.Arr[2] = 200;
	cor.Arr[1] = cor.Arr[2];
	unsigned int tpitNum = 2;
	ptgrp = new Point[tpitNum];
	for (unsigned int i = 0; i < tpitNum; i++)
	{
		ptgrp[i].pointinf.Numbering = i;
		cor.Arr[0] = 200 + (i * 20);
		pv.Num = 1;
		pv.Ven = new float[ptgrp[i].pointinf.ven.Num];
		ptgrp[i].PointInit(cor, pv,i);
		ptgrp[i].pointinf.ven.Ven[0] = 5;
	}
	



	while (true)
	{
		
		setfillcolor(RED);
		for (unsigned i = 0; i < tpitNum; i++)
		{
			ptgrp[i].PointUp();
			//
			
			solidcircle(ptgrp[i].pointinf.coor.Arr[0], ptgrp[i].pointinf.coor.Arr[1], 5);
			//
			//FlushBatchDraw();
		}
		ThreadUp(ptgrp,tpitNum);
		BeginBatchDraw();
		for (size_t i = 0; i < tpitNum; i++)
		{
			solidcircle(ptgrp[i].pointinf.coor.Arr[0], ptgrp[i].pointinf.coor.Arr[1], 5);
		}
		EndBatchDraw();
		Sleep(WaitT);
		cleardevice();
		/*FlushBatchDraw();*/
		
	}
	
}
