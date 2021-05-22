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
	m_Max_Dash = 100;
	m_DashCooltime= 100;
	menimap = 1;
	HaveGun = 0;
	Difficulty = 1;
	_UICreate = false;
	_PlayerCreate = false;

	for (int i = 0; i < 5; i++) {
		Not_Overlap[i] = true;
	}
	GameMgr::GetInst()->m_MouseShape = MouseShape::none;
	GameMgr::GetInst()->m_Scene = CurrentScene::NONE;
	GameMgr::GetInst()->m_Weapon_Type = Weapon_Type::BASICGUN;
	
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
		} // 1차 성벽 오른쪽
		for (int i = 2; i < 11; i++)
		{
			ObjMgr->AddObject(new Wall(Vec2(80 * i - 40, -400)), "Wall");
		} // 1차 성벽 왼쪽
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

void GameMgr::Shape(bool dir)//false 위로 true 아래로
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
	// 1번 기본 무기, 2번 근접무기, 3번 슈류탄

	for (auto& iter : ObjMgr->m_Objects) {
	}
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
		if (INPUT->GetKey('4') == KeyState::DOWN) {
			if (HaveGun == 1) {
				m_Weapon_Type = Weapon_Type::GRENADE;
			}
			if (HaveGun == 2) {
				m_Weapon_Type = Weapon_Type::MELEE;
			}
		}
		if (INPUT->GetKey('5') == KeyState::DOWN) {
			if (HaveGun == 2) {
				m_Weapon_Type = Weapon_Type::GRENADE;
			}
		}

	if (m_Weapon_Type != Weapon_Type::GUN1) {
		ObjMgr->DeleteObject("Weapon1");
	}
	else {
		if (Not_Overlap[0]) {
			ObjMgr->AddObject(new Weapon("Heroine", PlayerPos), "Weapon1");
			Not_Overlap[0] = false;
		}
		for (int i = 0; i < 5; i++) {
			if(i!=0)
				Not_Overlap[i] = true;
		}
	}
	if (m_Weapon_Type != Weapon_Type::GUN2) {
		ObjMgr->DeleteObject("Weapon2");
	}
	else {
		if (Not_Overlap[1]) {
			ObjMgr->AddObject(new Weapon("Vulcan_Cannon", PlayerPos), "Weapon2");
			Not_Overlap[1] = false;
		}
		for (int i = 0; i < 5; i++) {
			if (i != 1)
				Not_Overlap[i] = true;
		}
	}
	if (m_Weapon_Type != Weapon_Type::BASICGUN) {
		ObjMgr->DeleteObject("Basic");
	}
	else {
		if (Not_Overlap[2]) {
			ObjMgr->AddObject(new Weapon("Basicgun", PlayerPos), "Basic");
			Not_Overlap[2] = false;
		}
		for (int i = 0; i < 5; i++) {
			if (i != 2)
				Not_Overlap[i] = true;
		}
	}
	if (m_Weapon_Type != Weapon_Type::MELEE) {
		ObjMgr->DeleteObject("Melee");
	}
	else {
		if (Not_Overlap[3]) {
			ObjMgr->AddObject(new Weapon("Blasphemy", PlayerPos), "Melee");
			Not_Overlap[3] = false;
		}
		for (int i = 0; i < 5; i++) {
			if (i != 3)
				Not_Overlap[i] = true;
		}
	}
	if (m_Weapon_Type != Weapon_Type::GRENADE) {
		ObjMgr->DeleteObject("Grenade");
	}
	else {
		if (Not_Overlap[4]) {
			ObjMgr->AddObject(new Weapon("RC_Rocket", PlayerPos), "Grenade");
			Not_Overlap[4] = false;
		}
		for (int i=0; i < 5; i++) {
			if (i != 4)
				Not_Overlap[i] = true;
		}
	}
}
