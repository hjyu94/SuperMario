#pragma once

class CLine;

class CLineMgr
{
private:
	CLineMgr();
	~CLineMgr();

public:
	static CLineMgr* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CLineMgr;

		return m_pInstance;
	}

	static void Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

	void ScrollToRight(float _fSpeed);

public:
	void AddLine(float x1, float y1, float x2, float y2);
	void Initialize();
	void Render(HDC hDC);
	void Release();

public:
	bool LineCollision(float fInX, float fInY, float * pOutY);

private:
	static CLineMgr* m_pInstance;
	list<CLine*> m_listLine;
};

