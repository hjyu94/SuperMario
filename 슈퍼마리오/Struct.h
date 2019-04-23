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

typedef struct tagLinePos
{
	tagLinePos()
	{
		ZeroMemory(this, sizeof(tagLinePos));
	}
	tagLinePos(float _fX, float _fY)
		:fX(_fX), fY(_fY)
	{}
	
	float fX;
	float fY;
} LINEPOS;

typedef struct tagLine
{
	tagLine()
	{
		ZeroMemory(this, sizeof(tagLine));
	}
	tagLine(LINEPOS& rLP, LINEPOS& rRP)
		: tLeftPoint(rLP)
		, tRightPoint(rRP)
	{}

	LINEPOS tLeftPoint;
	LINEPOS tRightPoint;
	
} LINEINFO;