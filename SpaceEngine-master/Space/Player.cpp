#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	m_Player = Sprite::Create(L"Painting/Player/Player.png");
	m_Player->SetParent(this);
	SetPosition(1920/2,1080);

	m_Hand = Sprite::Create(L"Painting/Player/Hand.png");
	m_Hand->SetPosition(500, 500);
	m_Speed = 500;
}

Player::Player(Vec2 Pos)
{
	m_Player = Sprite::Create(L"Painting/Player/Player.png");
	m_Player->SetParent(this);
	SetPosition(Pos);

	m_Hand = Sprite::Create(L"Painting/Player/Hand.png");
	m_Hand->SetPosition(Pos);
	m_Speed = 500;
}

Player::~Player()
{
}

void Player::Move()
{
	if (INPUT->GetKey('W') == KeyState::PRESS) {
		m_Position.y -= dt * m_Speed;
	}
	if(INPUT->GetKey('A') == KeyState::PRESS){
		m_Position.x -= dt * m_Speed;
	}
	if (INPUT->GetKey('S') == KeyState::PRESS) {
		m_Position.y += dt * m_Speed;
	}
	if (INPUT->GetKey('D') == KeyState::PRESS) {
		m_Position.x += dt * m_Speed;
	}
}

void Player::WeaponRotate()
{
}

void Player::Update(float deltaTime, float Time)
{
	m_Hand->SetPosition(m_Position.x, m_Position.y);
	Move();
}

void Player::Render()
{
	m_Player->Render();
	m_Hand->Render();
}

void Player::OnCollision(Object* obj)
{
}
