#pragma once
#include"ParticleClass.h"
#include<stdlib.h>

extern  LONGLONGThrArr VenSize;
extern  UNINTThrArr partIndexUint;
extern  UNINTThrArr PartUint;
extern  unsigned* PartUintDevTwo;
extern  unsigned  puacc;
extern  unsigned  effeVen;
extern  unsigned  effeVenPow;

class CilUnit
{
public:
	unsigned sta = 0;
};

class Zsil
{
public:
	unsigned NumZ;
	CilUnit* cuGrp;

};

class Ysil
{
public:
	unsigned NumY;
	Zsil* GrpZsil;

};

class Xsil
{
public:
	unsigned NumX;
	Ysil* GrpYsil;
};

extern  Xsil xsilgrp;


class PartHouse
{
public:
	unsigned short ClaerNum;
	unsigned int GroupNumber;
	PointInform*** PInfGroupP;
	unsigned short* Number;
	PartHouse();
	void AddGroup();
	void SubGroup(unsigned int intGrpNuming);
	GroupIndex AddDate(PointInform* p);
	void SubDate(GroupIndex inf);
	void ClearGroup();
};

extern  PartHouse* PartHouseArr;

template <typename T>
T* ArrRel(T* p, unsigned char capacity) {
	return (T*)realloc(p, capacity * sizeof(T));
}
void FUpPInit();
void FUpPAdd(FUPP P);
void ThreadUp(Point* PointArr,long long num);



void initeffeVen(unsigned int effer);
void initVenPartInf(long long x, long long y, long long z, unsigned ptx, unsigned pty, unsigned ptz);
void initPartHouse();



void CilArrLoad(UNINTThrArr RaleCor);