#pragma once

class LONGLONGThrArr
{
public:
	long double Arr[3];
};

class INTThrArr
{
public:
	int Arr[3];
};

class UNINTThrArr
{
public:
	unsigned int Arr[3];
};

class FLOATThrArr
{
public:
	float Arr[3];
};

class LongBudThrArr
{
public:
	long double Arr[3];
};


class VenInform
{
public:
	unsigned Num;
	float* Ven;
};


class PointInform
{
public:
	VenInform ven;
	FLOATThrArr a, F;
	FLOATThrArr v;
	LONGLONGThrArr coor;
	long long Numbering;
	long long tabNum;
	long long* tab;
};

class GroupIndex
{
public:
	unsigned int GroupNum;
	unsigned short InsideNum;
};

class DoubleSqrtAnndPow
{
public:
	float Sqrts;
	float Pows;
	
};

class PartcoorAndindex
{
public:
	unsigned int index;
	UNINTThrArr PtCoor;
};

typedef void (*FUPP)(PointInform* HostP, PointInform* GuestP, float distanPtoP);

class Point
{
public:
	//coor
	PointInform pointinf;
	GroupIndex ppinf; 
	PartcoorAndindex oldptinf, newptinf;
	Point();
	void PointInit(LONGLONGThrArr incoor, VenInform inven, long long Numbering);
	void PointPartUp();
	void PointFUp();
	void PointCoorUp();
	void PointUp();
};



