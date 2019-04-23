#include "stdafx.h"
#include "MainGame.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "ObjMgr.h"
#include "LineMgr.h"
///Obj
#include "Player.h"
///������ <-- ���� ���� ����
#include "Coin.h"
#include "FireFlower.h"
#include "GrowMushroom.h"
#include "LifeMushroom.h"
#include "Star.h"
#include "FlowerMon.h"
#include "PlantBlock.h"
#include "BreakBlock.h"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);

	///��ü ����
	CObjMgr::Get_Instance()->AddObject(OBJID::PLAYER, CAbstractFactory<CPlayer>::Create());
	

	//1) �÷��̾�
	CObj* pPlayer = CAbstractFactory<CPlayer>::Create();
	CObjMgr::Get_Instance()->AddObject(OBJID::PLAYER, pPlayer);
	CObjMgr::Get_Instance()->Set_Player((CPlayer*)pPlayer);
	
	//3) ����
	/*CPlantBlock* pPlant = CAbstractFactory<CPlantBlock>::Create(500, WINCY - PLANT_BLOCK_FCY / 2 - 100);
	CFlowerMon* pFlowerMon = CAbstractFactory<CFlowerMon>::Create(500, WINCY - PLANT_BLOCK_FCY / 2 - 100);
	CObjMgr::Get_Instance()->AddObject(OBJID::MONSTER, pFlowerMon);
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, pPlant);*/

	//4) ��, Obj, Ÿ�� ????
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(680, 400));

	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(850, 400));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(900, 400));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(950, 400));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(1000, 400));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(1050, 400));
	
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(950,220));

	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CPlantBlock>::Create(1200, 530));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CPlantBlock>::Create(1600, 510));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CPlantBlock>::Create(1940, 460));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CPlantBlock>::Create(2400, 460));

	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(3200, 400));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(3250, 400));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(3300, 400));

	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(3350, 220));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(3400, 220));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(3450, 220));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(3500, 220));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(3550, 220));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(3600, 220));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(3650, 220));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(3700, 220));

	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(3800, 220));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(3850, 220));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(3900, 220));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(3900, 400));

	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(4200, 400));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(4250, 400));

	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(4500, 400));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(4600, 400));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(4700, 400));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(4600, 400));

	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(5000, 400));

	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(5150, 220));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(5200, 220));

	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(5300, 220));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(5350, 220));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(5400, 220));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(5450, 220));

	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(5350, 400));
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CBreakBlock>::Create(5400, 400));




	//5) �� �׸���
	CLineMgr::Get_Instance()->Initialize();

}

void CMainGame::Update()
{
	CObjMgr::Get_Instance()->Update();
}

void CMainGame::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();
}

void CMainGame::Render()
{
	if (CObjMgr::Get_Instance()->Get_Player()->Get_iLife() < 0)
	{
		WCHAR lpOut[1024] = L"Game Over";
		TextOut(m_hDC, WINCX / 2, WINCY / 2, lpOut, lstrlen(lpOut));
	}
	else
	{
		Rectangle (m_hDC, 0, 0, WINCX, WINCY);
		CObjMgr::Get_Instance()->Render(m_hDC);
		CLineMgr::Get_Instance()->Render(m_hDC);
	}
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);

	CObjMgr::Get_Instance()->Release();
	CLineMgr::Get_Instance()->Release();
}

