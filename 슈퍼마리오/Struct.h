#pragma once
typedef struct tagInfo
{
	// °´Ã¼ÀÇ ÁÂÇ¥. 
	float fX; 
	float fY; 

	// °´Ã¼ÀÇ Å©±â 
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