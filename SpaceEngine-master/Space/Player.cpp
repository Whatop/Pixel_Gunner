#include "stdafx.h"
#include "Player.h"
#include "Evasion.h"
#include "Weapon.h"

Player::Player(Vec2 Pos)
{
	m_Player = Sprite::Create(L"Painting/Player/Player.png");
	m_Player->SetParent(this);
	SetPosition(Pos);
	m_Layer = 0;

	m_Hand_Left = Sprite::Create(L"Painting/Player/Hand.png");
	m_Hand_Left->SetPosition(Pos);
	m_Hand_Left->m_Layer = 1;

	m_Hand_Right = Sprite::Create(L"Painting/Player/Hand.png");
	m_Hand_Right->SetPosition(Pos);
	m_Hand_Right->m_Layer = 1;

	m_Speed = 5.f;
	m_Dash = false;
	m_Timer = 0.f;
	m_DashCooltime = 0.f;
	m_DashTime = 0.f;

	m_Weapon_Tag.clear();
	m_Weapon_Tag.push_back("GUN1");
	m_Weapon_Tag.push_back("GUN2");
	m_Weapon_Tag.push_back("기본 무기");
	m_Weapon_Tag.push_back("근접 무기");
	m_Weapon_Tag.push_back("수류탄");


	std::cout << "-0번째 : " << m_Weapon_Tag.at(0) << std::endl;
	std::cout << "-1번째 : " << m_Weapon_Tag.at(1) << std::endl;
	std::cout << "-2번째 : " << m_Weapon_Tag.at(2) << std::endl;
	std::cout << "-3번째 : " << m_Weapon_Tag.at(3) << std::endl;
	std::cout << "-4번째 : " << m_Weapon_Tag.at(4) << std::endl;
}

Player::~Player()
{
}

void Player::Move()
{
	if (INPUT->GetKey('W') == KeyState::PRESS) {
		m_Position.y -= m_Speed;
	}
	if(INPUT->GetKey('A') == KeyState::PRESS){
		m_Position.x -= m_Speed;
	}
	if (INPUT->GetKey('S') == KeyState::PRESS) {
		m_Position.y += m_Speed;
	}
	if (INPUT->GetKey('D') == KeyState::PRESS) {
		m_Position.x +=  m_Speed;
	}
}

void Player::Hand()
{
	m_Hand_Left->SetPosition(m_Position.x - 30, m_Position.y + 15);
	m_Hand_Right->SetPosition(m_Position.x + 30, m_Position.y + 15);

	if (m_Weapon_Type == Weapon_Type::GUN1) {
		if(INPUT->GetKey('1')==KeyState::DOWN)
		ObjMgr->AddObject(new Weapon("MK47", m_Position), "Weapon");
	}
}

void Player::Buff() //탄창 수 증가,체력 증가, 스피드 증가 등등  
{
}

void Player::Dash()
{
	m_DashCooltime += dt;
	if (INPUT->GetRightButtonDown() && m_DashCooltime >= 0.3f)
	{
		m_Dash = true;
	}
	if (m_Dash)
	{
		m_Timer += dt;
		ObjMgr->AddObject(new Evasion(m_Position), "Effect");
		m_Speed = 15.f;

		if (m_Timer >= 0.1f)
		{
			m_Timer = 0.f;
			m_Dash = false;
			m_DashCooltime = 0;
			m_Speed = 5;
		}
	}
}

void Player::Update(float deltaTime, float Time)
{
	ObjMgr->CollisionCheak(this, "WeaponCase");
	Move();
	Dash();
	Camera::GetInst()->Follow(this);
	Buff(); 
	Hand();
	GameMgr::GetInst()->Weapon_Holding();
	//Camera::GetInst()->Temp(this);
}

void Player::Render()
{
	m_Player->Render();
	m_Hand_Left->Render();
	m_Hand_Right->Render();
}

void Player::OnCollision(Object* obj)
{
	if (obj->m_Tag == "WeaponCase") {
		if (INPUT->GetKey('E') == KeyState::DOWN) {
			m_Weapon_Tag.at(1) = obj->m_WeaponName;
			std::cout << "첫번째 총 : " << m_Weapon_Tag.at(1) << std::endl;
		}
	}
}
