#include "stdafx.h"
#include "Stage1.h"
#include "Player.h"
#include "Enemy.h"
#include "Obstacle.h"
#include "Weapon_case.h"

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
	GameMgr::GetInst()->CreatePlayer();
	GameMgr::GetInst()->ReleaseUI();
	GameMgr::GetInst()->CreateUI();
	ObjMgr->AddObject(new Enemy(Vec2(1920 / 2, 1080 / 2 - 1500)), "Enemy");
	m_BG = Sprite::Create(L"Painting/Stage1/BG.png");
	m_BG->SetPosition(1920 / 2, 1080-m_BG->m_Size.y/2);

	ObjMgr->AddObject(new Weapon_case(L"Painting/Weapon/Test.png","Heroine",Vec2(1920/2,-300)), "WeaponCase");
	ObjMgr->AddObject(new Weapon_case(L"Painting/Weapon/Test.png","Bullet_Bore",Vec2(1920/2,-400)), "WeaponCase");
	ObjMgr->AddObject(new Weapon_case(L"Painting/Weapon/Test.png","The_Scrambler",Vec2(1920/2,-500)), "WeaponCase");
	ObjMgr->AddObject(new Weapon_case(L"Painting/Weapon/Test.png","RC_Rocket",Vec2(1920/2,-600)), "WeaponCase");
	ObjMgr->AddObject(new Weapon_case(L"Painting/Weapon/Test.png","Vulcan_Cannon",Vec2(1920/2,-700)), "WeaponCase");
	ObjMgr->AddObject(new Weapon_case(L"Painting/Weapon/Test.png","Thumbnail",Vec2(1920/2,-800)), "WeaponCase");
	ObjMgr->AddObject(new Weapon_case(L"Painting/Weapon/Test.png","Marine_Sidearm",Vec2(1920/2,-900)), "WeaponCase");
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
