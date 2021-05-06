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
	m_Speed = 500.f;
	DelayTime = 0;
	m_Dash = false;
	m_Timer = 0;
	m_DashCooltime = 0;
	m_DashTime = 0;
}

Player::Player(Vec2 Pos)
{
	m_Player = Sprite::Create(L"Painting/Player/Player.png");
	m_Player->SetParent(this);
	SetPosition(Pos);

	m_Hand = Sprite::Create(L"Painting/Player/Hand.png");
	m_Hand->SetPosition(Pos);
	m_Speed = 500.f;
	DelayTime = 0;
	m_Dash = false;
	m_Timer = 0.f;
	m_DashCooltime = 0.f;
	m_DashTime = 0.f;
}

Player::~Player()
{
}

void Player::Move()
{
	if (INPUT->GetKey('W') == KeyState::PRESS) {
		m_Position.y -= m_Speed * dt;
	}
	if(INPUT->GetKey('A') == KeyState::PRESS){
		m_Position.x -= m_Speed * dt;
	}
	if (INPUT->GetKey('S') == KeyState::PRESS) {
		m_Position.y += m_Speed * dt;
	}
	if (INPUT->GetKey('D') == KeyState::PRESS) {
		m_Position.x +=  m_Speed * dt;
	}
}

void Player::WeaponRotate()
{
	Mouse = INPUT->GetMousePos() - m_Hand->m_Position;
	D3DXVec2Normalize(&Dire, &Mouse);
	m_Hand->m_Rotation=(std::atan2(Dire.y, Dire.x));
	m_Hand->SetPosition(m_Position.x, m_Position.y);
}

void Player::Shooting() 
{
	DelayTime += dt;
	if (INPUT->GetButtonDown() && DelayTime > 0.5f) { // 총마다 DelayTime 다르고 속도 다르게 하면 됨 
		ObjMgr->AddObject(new Bullet(L"Painting/Player/Bullet.png", Dire, m_Hand->m_Position, 1350),"Bullet");
		DelayTime = 0;
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
		m_Speed = 1500.f;

		if (m_Timer >= 0.1f)
		{
			m_Timer = 0.f;
			m_Dash = false;
			m_DashCooltime = 0;
			m_Speed = 500.f;
		}
	}
}

void Player::Update(float deltaTime, float Time)
{
	Camera::GetInst()->Follow(this);
	Move();
	Dash();
	WeaponRotate();
	Shooting();
	Buff();
}

void Player::Render()
{
	m_Player->Render();
	m_Hand->Render();
}

void Player::OnCollision(Object* obj)
{
}
