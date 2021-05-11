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

	m_Speed = 5.f;
	m_Dash = false;
	m_Timer = 0.f;
	m_DashCooltime = 0.f;
	m_DashTime = 0.f;

	m_Weapon_Tag.clear();
	m_Weapon_Tag.push_back("GUN1");
	m_Weapon_Tag.push_back("GUN2");
	m_Weapon_Tag.push_back("�⺻ ����");
	m_Weapon_Tag.push_back("���� ����");
	m_Weapon_Tag.push_back("����ź");


	std::cout << "-0��° : " << m_Weapon_Tag.at(0) << std::endl;
	std::cout << "-1��° : " << m_Weapon_Tag.at(1) << std::endl;
	std::cout << "-2��° : " << m_Weapon_Tag.at(2) << std::endl;
	std::cout << "-3��° : " << m_Weapon_Tag.at(3) << std::endl;
	std::cout << "-4��° : " << m_Weapon_Tag.at(4) << std::endl;
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
	if (m_Weapon_Type == Weapon_Type::GUN1) {
		
	}
}

void Player::Buff() //źâ �� ����,ü�� ����, ���ǵ� ���� ���  
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
}

void Player::OnCollision(Object* obj)
{
	if (obj->m_Tag == "WeaponCase") {
		if (INPUT->GetKey('E') == KeyState::DOWN) {
			GameMgr::GetInst()->HaveGun++;
			m_Weapon_Tag.at(1) = obj->m_WeaponName;
			std::cout << "ù��° �� : " << m_Weapon_Tag.at(1) << std::endl;
		}
	}
}
