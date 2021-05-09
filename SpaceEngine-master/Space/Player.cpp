#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "Evasion.h"

Player::Player()
{
	m_Player = Sprite::Create(L"Painting/Player/Player.png");
	m_Player->SetParent(this);
	SetPosition(1920/2,1080/2);

	m_Hand = Sprite::Create(L"Painting/Player/Hand.png");
	m_Hand->SetPosition(500, 500);

	m_Weapon = Sprite::Create(L"Painting/Player/Hand.png");
	m_Weapon->SetPosition(500, 500);

	m_Speed = 5.f;
	DelayTime = 0;
	m_Dash = false;
	m_Timer = 0;
	m_DashCooltime = 0;
	m_DashTime = 0;
	m_Type = 1;
	HaveGun = 0;
	m_Weapon_Type = Weapon_Type::GUN1;
	m_Weapon_Tag.clear();
	m_Weapon_Tag.push_back("GUN1");
	m_Weapon_Tag.push_back("GUN2");
	m_Weapon_Tag.push_back("기본 무기");
	m_Weapon_Tag.push_back("근접 무기");
	m_Weapon_Tag.push_back("수류탄");
}

Player::Player(Vec2 Pos)
{
	m_Player = Sprite::Create(L"Painting/Player/Player.png");
	m_Player->SetParent(this);
	SetPosition(Pos);

	m_Hand = Sprite::Create(L"Painting/Player/Hand.png");
	m_Hand->SetPosition(Pos);

	m_Weapon = Sprite::Create(L"Painting/Player/Hand.png");
	m_Weapon->SetPosition(Pos);

	m_Speed = 5.f;
	DelayTime = 0;
	m_Dash = false;
	m_Timer = 0.f;
	m_DashCooltime = 0.f;
	m_DashTime = 0.f;
	m_Type = 1;
	HaveGun = 0;
	m_Weapon_Type = Weapon_Type::NONE;
	m_Weapon_Tag.clear();
	m_Weapon_Tag.push_back("GUN1");
	m_Weapon_Tag.push_back("GUN2");
	m_Weapon_Tag.push_back("기본 무기");
	m_Weapon_Tag.push_back("근접 무기");
	m_Weapon_Tag.push_back("수류탄");
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

void Player::WeaponRotate()
{
	Mouse = INPUT->GetMousePos() - m_Hand->m_Position;
	D3DXVec2Normalize(&Dire, &Mouse);
	m_Hand->m_Rotation=(std::atan2(Dire.y, Dire.x));
	m_Hand->SetPosition(m_Position.x, m_Position.y);
}

void Player::Weapon_Type()
{
	
	ObjMgr->CollisionCheak(this, "Weapon");
	// 1번 기본 무기, 2번 근접무기, 3번 슈류탄
	
	if (INPUT->GetKey('1')==KeyState::DOWN) { 
		if (HaveGun == 1) {
			m_Weapon_Type = Weapon_Type::GUN1;
		}
		if (HaveGun == 2) {
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
	if (HaveGun == 0) {
		m_Weapon->m_Visible = false;
	}
	else {
		m_Weapon->m_Visible = true;
	}

	if (m_Weapon_Type == Weapon_Type::GUN1) {
		if (m_Weapon_Tag.at(1)=="MK47") {
			if (m_Weapon->m_Rotation > -1.5 && m_Weapon->m_Rotation < 1.5) {
				m_Weapon = Sprite::Create(L"Painting/Weapon/Weapon_1.png");
			}
			else {
				m_Weapon = Sprite::Create(L"Painting/Weapon/Weapon_2.png");
			}
			m_Weapon->m_Position = m_Hand->m_Position;
			m_Weapon->m_Rotation = m_Hand->m_Rotation;
			std::cout << m_Weapon->m_Rotation << std::endl;
		}
	}
	else if (m_Weapon_Type == Weapon_Type::GUN2) {
		m_Weapon_Tag.at(2);
	}
}

void Player::Shooting() 
{
	if (m_Type == 1) {
		DelayTime += dt;
		if (INPUT->GetButtonDown() && DelayTime > 0.5f) { // 총마다 DelayTime 다르고 속도 다르게 하면 됨 
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Bullet.png", Dire, m_Hand->m_Position, 1550), "Bullet");
			DelayTime = 0;
		}
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
	Move();
	Dash();
	Camera::GetInst()->Follow(this);
	WeaponRotate();
	Shooting();
	Buff();
	Weapon_Type();
	//Camera::GetInst()->Temp(this);
}

void Player::Render()
{
	m_Player->Render();
	m_Hand->Render();
	m_Weapon->Render();
}

void Player::OnCollision(Object* obj)
{
	if (obj->m_Tag == "Weapon") {
		if (INPUT->GetKey('E') == KeyState::DOWN) {
			HaveGun++;
			m_Weapon_Tag.at(1) = obj->m_WeaponName;
			std::cout << m_Weapon_Tag.at(1) << std::endl;
			std::cout <<"가지고있는 총 : " <<HaveGun << std::endl;
			std::cout <<"몇번 칸 : "<<(int)m_Weapon_Type << std::endl;
		}
	}
}
