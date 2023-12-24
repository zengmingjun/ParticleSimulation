#include"Particle.h"
#include<math.h>
#include<iostream> 
#include <graphics.h>		// 引用图形库头文件

#define KE 100



void NewFUp(PointInform* HostP, PointInform* GuestP, float distanPtoPPow) {
	if (distanPtoPPow <= 25)
	{
		//碰撞添加
		distanPtoPPow = 25;
	}

	float F = (float)Kmf * HostP->ven.Ven[0] * GuestP->ven.Ven[0] / distanPtoPPow;
	float dertacor[VenDimension];
	for (unsigned i = 0; i < VenDimension; i++)
	{
		dertacor[i] = Distance(GuestP->coor.Arr[i], HostP->coor.Arr[i]) / sqrtf(distanPtoPPow);
	}
	for (unsigned i = 0; i < VenDimension; i++)
	{
		HostP->F.Arr[i] += F * dertacor[i];
		GuestP->F.Arr[i] += -F * dertacor[i];
	}

	 F = (float)KE * HostP->ven.Ven[1] * GuestP->ven.Ven[1] / distanPtoPPow;
	
	if (HostP->ven.Ven[1] + GuestP->ven.Ven[1] == 0)
	{
		for (unsigned i = 0; i < VenDimension; i++)
	    {
		HostP->F.Arr[i] += -F * dertacor[i];
		GuestP->F.Arr[i] += F * dertacor[i];
	    }
	}
	else
	{
		for (unsigned i = 0; i < VenDimension; i++)
		{
			HostP->F.Arr[i] += F * dertacor[i];
			GuestP->F.Arr[i] += -F * dertacor[i];
		}
	}
	/*for (unsigned i = 0; i < VenDimension; i++)
	{
		HostP->F.Arr[i] += -F * dertacor[i];
		GuestP->F.Arr[i] += F * dertacor[i];
	}
	return;*/
}


void main() {
	unsigned eff = 30;
	initeffeVen(eff);
	initVenPartInf(1000, 1000, 1000, 10, 10, 10);
	initPartHouse();
	FUpPInit();
	FUpPAdd(&NewFUp);
	unsigned senwi = 1000;
	unsigned senhi = 1000;
	initgraph(senwi, senhi);
	setorigin(0, senhi);
	setaspectratio(1, -1);
	unsigned cpnum = 200;
	Point* Pgrp = new Point[cpnum];
	VenInform initven;
	initven.Num = 1;
	initven.Ven = new float[initven.Num];
	initven.Ven[0] = 5;

	LONGLONGThrArr cor = { NULL };
	cor.Arr[0] = senwi/2;
	cor.Arr[1] = senhi/2;
	cor.Arr[2] = 1;
	double Pi = 3.1415926535897;
	double unit = Pi / cpnum;
	for (size_t i = 0; i < cpnum; i++)
	{

		Pgrp[i].pointinf.Numbering = i;
		cor.Arr[1] += sin(unit*i)*29;
		cor.Arr[0] += cos(unit * i)*29;

		initven.Num = 2;
		initven.Ven = new float[Pgrp[i].pointinf.ven.Num];

		Pgrp[i].PointInit(cor, initven, i);
		cor.Arr[0] = senwi / 2;
		cor.Arr[1] = senhi / 2;
		Pgrp[i].pointinf.ven.Ven[0] = 5;
		if (i%2==0)
		{
			Pgrp[i].pointinf.ven.Ven[1] = 5;
		}
		else
		{
			Pgrp[i].pointinf.ven.Ven[1] = -5;
		}
	}
	//Pgrp[0].pointinf.v.Arr[0] = 10;
	//Pgrp[0].pointinf.v.Arr[1] = -1;
	setlinecolor(RGB(0,255,0));
	while (true)
	{
		/*for (size_t i = 0; i < 10; i++)
		{
			Pgrp[i].newptinf.PtCoor;

		}*/
		
		
		for (size_t i = 0; i < cpnum; i++)
		{
			Pgrp[i].PointUp();
		}

		for (size_t i = 0; i < cpnum; i++)
		{
			Pgrp[i].PointCoorUp();
		}

		ThreadUp(Pgrp, cpnum);
		
		BeginBatchDraw();
		for (size_t i = 0; i < cpnum; i++) 
		{
			setfillcolor(RGB(i * 10 + 100, i * 20 + 50, i * i * 10 + 60));
			solidcircle(Pgrp[i].pointinf.coor.Arr[0], Pgrp[i].pointinf.coor.Arr[1], 5);
			//circle(Pgrp[i].pointinf.coor.Arr[0], Pgrp[i].pointinf.coor.Arr[1], eff);
			
			
		}
		
		EndBatchDraw();
		Sleep(WaitT);
		cleardevice();
	}

}