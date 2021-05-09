#include "stdafx.h"
#include "Stage1.h"
#include "Player.h"
#include "Obstacle.h"
#include "Weapon.h"

Stage1::Stage1()
{
}

Stage1::~Stage1()
{
}

void Stage1::Init() 
{
	GameMgr::GetInst()->m_Scene = CurrentScene::STAGE1;
	GameMgr::GetInst()->CreateObstacle();
	m_BG = Sprite::Create(L"Painting/Stage1/BG.png");
	m_BG->SetPosition(1920 / 2, 1080-m_BG->m_Size.y/2);

	

	ObjMgr->AddObject(new Player, "Player");
	ObjMgr->AddObject(new Weapon(L"Painting/Weapon/Test.png","MK47",Vec2(1920/2,-300)), "Weapon");
}

void Stage1::Update(float deltaTime, float Time)
{
	if (INPUT->GetKey(VK_F1) == KeyState::DOWN) {
		if (!m_Puase) {
			GameMgr::GetInst()->CreateUI();
			m_Puase = true;
		}
		else {
			GameMgr::GetInst()->ReleaseUI();
			m_Puase = false;
		}
	}
	if (INPUT->GetKey(VK_F2) == KeyState::DOWN) {
		GameMgr::GetInst()->Shape(false);
	}
	else if (INPUT->GetKey(VK_F3) == KeyState::DOWN) {
		GameMgr::GetInst()->Shape(true);
	}
}

void Stage1::Render()
{
	m_BG->Render();
}

void Stage1::Release()
{
}
