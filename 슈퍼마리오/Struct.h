#pragma once
typedef struct tagInfo
{
	// ��ü�� ��ǥ. 
	float fX; 
	float fY; 

	// ��ü�� ũ�� 
	float fCX;
	float fCY;
}INFO;

typedef struct tagLinePoint
{
	tagLinePoint(float _fX, float _fY)
	{
		fX = _fX;
		fY = _fY;
	}

	float fX;
	float fY;
} LINEPOINT;

typedef struct tagLine
{
	tagLine(LINEPOINT& lPoint, LINEPOINT& rPoint)
	{
		lPoint = lPoint;
		rPoint = rPoint;
	}

	LINEPOINT lPoint;
	LINEPOINT rPoint;
	
} LINE;