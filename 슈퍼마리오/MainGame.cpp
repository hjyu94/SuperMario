// push test
/// 같은작업 testtttttt

// 효정: 같은 작업 테스트 2


// 같은 작업 test 2

#include "stdafx.h"
#include "MainGame.h"

#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "ObjMgr.h"

#include "Player.h"

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
	CObjMgr::Get_Instance()->AddObject(OBJID::PLAYER, CAbstractFactory<CPlayer>::Create());
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
	Rectangle (m_hDC, 0, 0, WINCX, WINCY);
	CObjMgr::Get_Instance()->Render(m_hDC);
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);

	CObjMgr::Get_Instance()->Release();
}

