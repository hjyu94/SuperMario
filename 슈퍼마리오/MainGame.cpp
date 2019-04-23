//Ŀ���׽�Ʈ�Դϴ� 4:16
#include "stdafx.h"
#include "MainGame.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "ObjMgr.h"
///Obj
#include "Player.h"
#include "TileBlock.h"
#include "NomalBlock.h"
///������ <-- ���� ���� ����
#include "Coin.h"
#include "FireFlower.h"
#include "GrowMushroom.h"
#include "LifeMushroom.h"
#include "Star.h"
#include "TileBlock.h"
#include "FlowerMon.h"
#include "PlantBlock.h"

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
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CNomalBlock>::Create());

	///������ ���� <-- ���� ���� ����
	CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CCoin>::Create());
	CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CFireFlower>::Create());
	//1) �÷��̾�
	CObj* pPlayer = CAbstractFactory<CPlayer>::Create();
	CObjMgr::Get_Instance()->AddObject(OBJID::PLAYER, pPlayer);
	CObjMgr::Get_Instance()->Set_Player((CPlayer*)pPlayer);
	
	//2) ������
	CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CGrowMushroom>::Create());

	//3) ����
	CPlantBlock* pPlant = CAbstractFactory<CPlantBlock>::Create(500, WINCY - PLANT_BLOCK_FCY / 2 - 100);
	CFlowerMon* pFlowerMon = CAbstractFactory<CFlowerMon>::Create(500, WINCY - PLANT_BLOCK_FCY / 2 - 100);
	CObjMgr::Get_Instance()->AddObject(OBJID::MONSTER, pFlowerMon);
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, pPlant);

	//4) ��, Obj, Ÿ�� ????
	CObjMgr::Get_Instance()->AddObject(OBJID::BLOCK, CAbstractFactory<CPlantBlock>::Create(300, WINCY-PLANT_BLOCK_FCY/2-100));

	CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CLifeMushroom>::Create());
	CObjMgr::Get_Instance()->AddObject(OBJID::ITEM, CAbstractFactory<CStar>::Create());
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
	}
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);

	CObjMgr::Get_Instance()->Release();
}

