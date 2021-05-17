#include "stdafx.h"
#include "GameMgr.h"
#include "UI.h"
#include "Player.h"
#include "Wall.h"
#include "Obstacle.h"
#include "Weapon.h"

GameMgr::GameMgr()
{
}

GameMgr::~GameMgr()
{
}

void GameMgr::Init()
{
	shape = 7;
	m_Hp = 100; 
	m_Max_Hp = 100;
	m_Max_Dash = 0.3f;
	m_DashCooltime= 0;
	menimap = 1;
	HaveGun = 0;
	Difficulty = 1;
	_UICreate = false;
	_PlayerCreate = false;
	GameMgr::GetInst()->m_MouseShape = MouseShape::none;
	GameMgr::GetInst()->m_Scene = CurrentScene::NONE;
}

void GameMgr::CreateUI()
{
	UI::GetInst()->Init();
	_UICreate = true;
}

void GameMgr::ReleaseUI()
{
	UI::GetInst()->Release();
	UI::GetInst()->ReleaseInst();
	_UICreate = false;
}

void GameMgr::CreateObstacle()
{
	if (GameMgr::GetInst()->m_Scene == CurrentScene::STAGE1) {
		for (int i = 1; i < 187; i++)
		{
			ObjMgr->AddObject(new Wall(Vec2(1920 - 40, 80 * -i + 1080 + 40)), "Wall");
			ObjMgr->AddObject(new Wall(Vec2(40, 80 * -i + 1080 + 40)), "Wall");

		}
		for (int i = 1; i < 24; i++)
		{
			ObjMgr->AddObject(new Wall(Vec2(80 * -i - 40 + 1920, -14920 + 1160)), "Wall");
			ObjMgr->AddObject(new Wall(Vec2(80 * -i - 40 + 1920, 1080 - 40)), "Wall");
		};
		for (int i = 2; i < 11; i++)
		{
			ObjMgr->AddObject(new Wall(Vec2(80 * -i - 40 + 1920, -400)), "Wall");
		} // 1�� ���� ������
		for (int i = 2; i < 11; i++)
		{
			ObjMgr->AddObject(new Wall(Vec2(80 * i - 40, -400)), "Wall");
		} // 1�� ���� ����
		ObjMgr->AddObject(new Obstacle(L"Painting/Stage1/Obstacle_1.png", Vec2(500, 300)), "Wall");
		ObjMgr->AddObject(new Obstacle(L"Painting/Stage1/Obstacle_2.png", Vec2(1500, 0)), "Wall");
		ObjMgr->AddObject(new Obstacle(L"Painting/Stage1/Obstacle_2.png", Vec2(400, 700)), "Wall");
		ObjMgr->AddObject(new Obstacle(L"Painting/Stage1/Obstacle_3.png", Vec2(1500, 650)), "Wall");
	}
	else if (GameMgr::GetInst()->m_Scene == CurrentScene::STAGE2) {

	}
}

void GameMgr::CreatePlayer()
{
	_PlayerCreate = true;	
	ObjMgr->AddObject(new Player(Vec2(500, 500)), "Player");

}

void GameMgr::CreateMonster()
{

}

void GameMgr::Shape(bool dir)//false ���� true �Ʒ���
{
	if (dir) {
		if (shape >= 7) {
			shape = 1;
		}
		else {
			shape++;
		}
	}
	else if(!dir){
		if (shape <= 1) {
			shape = 7;
		}
		else {
			shape--;
		}
	}
	if (shape == 1) {
		m_MouseShape = MouseShape::scope;
	}
	else if (shape == 2) {
		m_MouseShape = MouseShape::square;
	}
	else if (shape == 3) {
		m_MouseShape = MouseShape::circle;
	}
	else if (shape == 4) {
		m_MouseShape = MouseShape::bullet;
	}
	else if (shape == 5) {
		m_MouseShape = MouseShape::cross;
	}
	else if (shape == 6) {
		m_MouseShape = MouseShape::point;
	}
	else if (shape == 7) {
		m_MouseShape = MouseShape::none;
	}
}

void GameMgr::MeniMap(bool add)
{
	if (add) {
		if (menimap >= 3) {
			menimap = 1;
		}
		else {
			menimap++;
		}
	}
	else {
		if (menimap <= 1) {
			menimap = 3;
		}
		else {
			menimap--;
		}
	}
}


void GameMgr::AddDifficulty()
{
	if (Difficulty > 2) {
		Difficulty = 0;
	}
	if (Difficulty == 0) {
		GameDifficulty = Game_Difficulty::EASY;
	}
	if (Difficulty == 1) {
		GameDifficulty = Game_Difficulty::NOMAL;
	}
	if (Difficulty == 2) {
		GameDifficulty = Game_Difficulty::HARD;
	}
	Difficulty++;
}

void GameMgr::Weapon_Holding()
{
	// 1�� �⺻ ����, 2�� ��������, 3�� ����ź

	if (INPUT->GetKey('1') == KeyState::DOWN) {
		if (HaveGun == 1) {
			m_Weapon_Type = Weapon_Type::GUN1;
		}
		else if (HaveGun == 2) {
			m_Weapon_Type = Weapon_Type::GUN1;
		}
		else {
			m_Weapon_Type = Weapon_Type::BASICGUN;
		}
	}
	else if (INPUT->GetKey('2') == KeyState::DOWN) {
		if (HaveGun == 1) {
			m_Weapon_Type = Weapon_Type::BASICGUN;
		}
		else if (HaveGun == 2) {
			m_Weapon_Type = Weapon_Type::GUN2;
		}
		else {
			m_Weapon_Type = Weapon_Type::MELEE;
		}
	}
	else if (INPUT->GetKey('3') == KeyState::DOWN) {
		if (HaveGun == 1) {
			m_Weapon_Type = Weapon_Type::MELEE;
		}
		else if (HaveGun == 2) {
			m_Weapon_Type = Weapon_Type::BASICGUN;
		}
		else {
			m_Weapon_Type = Weapon_Type::GRENADE;
		}
	}
	if (HaveGun == 1) {
		if (INPUT->GetKey('4') == KeyState::DOWN) {
			if (HaveGun == 2) {
				m_Weapon_Type = Weapon_Type::MELEE;
			}
			else {
				m_Weapon_Type = Weapon_Type::GRENADE;
			}
		}
	}
	if (HaveGun == 2) {
		if (INPUT->GetKey('5') == KeyState::DOWN) {
			m_Weapon_Type = Weapon_Type::GRENADE;
		}
	}

	if (m_Weapon_Type == Weapon_Type::GUN1) {
		
	}
	else if (m_Weapon_Type == Weapon_Type::GUN2) {
	}
}
