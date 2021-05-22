#include "stdafx.h"
#include "Player.h"
#include "Evasion.h"
#include "Weapon.h"

Player::Player(Vec2 Pos)
{
	m_Player = Sprite::Create(L"Painting/Player/Player.png");
	m_Layer = 0;

	m_Speed = 5.f;
	m_Dash = false;
	m_Timer = 0.f;
	m_DashCooltime = 0.f;
	m_DashTime = 0.f;
	Multiple = 1;

	Up = false;
	Down = false;
	Right = false;
	Left = false;
	Y[0] = false;
	Y[1] = false;
	X[0] = false;
	X[1] = false;

	m_Weapon_Tag.clear();
	m_Weapon_Tag.push_back("GUN1");
	m_Weapon_Tag.push_back("GUN2");
	m_Weapon_Tag.push_back("기본 무기");
	m_Weapon_Tag.push_back("근접 무기");
	m_Weapon_Tag.push_back("수류탄");

	m_ColBox[0] = Sprite::Create(L"Painting/Player/ColBox.png");
	m_ColBox[0]->SetParent(this);
	m_ColBox[1] = Sprite::Create(L"Painting/Player/Width.png");
	m_ColBox[2] = Sprite::Create(L"Painting/Player/Width.png");
	m_ColBox[3] = Sprite::Create(L"Painting/Player/Height.png");
	m_ColBox[4] = Sprite::Create(L"Painting/Player/Height.png");
	SetPosition(Pos);


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
		Y[0] = true;
		if (X[0] || X[1])
			Multiple = 0.75f;

		if (!Down)
			m_Position.y -= m_Speed * Multiple;
	}	
	if (INPUT->GetKey('S') == KeyState::PRESS) {
		Y[1] = true;
		if (X[0] || X[1])
			Multiple = 0.75f;
		else
			Multiple = 1;
		if (!Up)
			m_Position.y += m_Speed * Multiple;
	}
	if(INPUT->GetKey('A') == KeyState::PRESS){
		X[0] = true;
		if (Y[0] || Y[1])
			Multiple = 0.75f;
		else
			Multiple = 1;
		if (!Right)
			m_Position.x -= m_Speed * Multiple;
	}
	if (INPUT->GetKey('D') == KeyState::PRESS) {
		X[1] = true;
		if (Y[0] || Y[1])
			Multiple = 0.75f;
		else 
			Multiple = 1;
		if (!Left)
			m_Position.x +=  m_Speed * Multiple;
	}
	//std::cout << "Multiple : " << Multiple << std::endl;
}

void Player::Hand()
{
	/*if (GameMgr::GetInst()->m_Weapon_Type == Weapon_Type::BASICGUN) {
		if (INPUT->GetKey('1') == KeyState::DOWN) {
		}
	}
	if (GameMgr::GetInst()->m_Weapon_Type == Weapon_Type::GUN1) {
			if (INPUT->GetKey('1') == KeyState::DOWN) {
				ObjMgr->AddObject(new Weapon(Weapon_Case_Tag.at(0), m_Position), "Weapon1");
			}
			else if (INPUT->GetKey('2') == KeyState::DOWN) {
				ObjMgr->AddObject(new Weapon("Basicgun", m_Position), "Basic");
			}
	}*/
	
}

void Player::ColBox()
{
	m_Player->SetPosition(m_Position);
	m_ColBox[1]->SetPosition(m_Position.x, m_Position.y - m_ColBox[0]->m_Size.y / 2);//Down
	m_ColBox[2]->SetPosition(m_Position.x, m_Position.y + m_ColBox[0]->m_Size.y / 2);//Up
	m_ColBox[3]->SetPosition(m_Position.x - m_ColBox[0]->m_Size.x / 2, m_Position.y);//Right
	m_ColBox[4]->SetPosition(m_Position.x + m_ColBox[0]->m_Size.x / 2, m_Position.y);//Left
}
	
void Player::Buff() //탄창 수 증가,체력 증가, 스피드 증가 등등  
{
}

void Player::Dash()
{
	m_DashCooltime += dt;
	GameMgr::GetInst()->m_DashCooltime = m_DashCooltime;
	if (INPUT->GetRightButtonDown() && m_DashCooltime >=1.f)
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
	Left = false;
	Up = false;
	Right = false;
	Down = false;
	Y[0] = false;
	Y[1] = false;
	X[0] = false;
	X[1] = false;
	ObjMgr->CollisionCheak(this, "WeaponCase");
	ObjMgr->CollisionCheak(this, "Wall");
	Move();
	Dash();
	Camera::GetInst()->Follow(this);
	Buff(); 
	ColBox(); 
	GameMgr::GetInst()->Weapon_Holding();
	Hand();
	//Camera::GetInst()->Temp(this);
}

void Player::Render()
{
	m_Player->Render();
	for (int i = 0; i < 5; i++) {
		m_ColBox[i]->A = 0;
		m_ColBox[i]->Render();
	}
}

void Player::OnCollision(Object* obj)
{
	if (obj->m_Tag == "WeaponCase") {
		if (INPUT->GetKey('E') == KeyState::DOWN) {
			GameMgr::GetInst()->HaveGun++;
			m_Weapon_Tag.at(1) = obj->m_WeaponName;
			GameMgr::GetInst()->Weapon_Case_Tag.push_back(obj->m_WeaponName);
			std::cout << "첫번째 총 : " << m_Weapon_Tag.at(1) << std::endl;
			std::cout << "테스트 : " << GameMgr::GetInst()->Weapon_Case_Tag.at(0) << std::endl;
		}
	}
	if (obj->m_Tag == "Wall")
	{
		RECT rc;
			if (IntersectRect(&rc, &m_ColBox[1]->m_Collision, &obj->m_Collision))
			{
				Down = true;
			}
			if (IntersectRect(&rc, &m_ColBox[2]->m_Collision, &obj->m_Collision))
			{
				Up = true;
			}
			if (IntersectRect(&rc, &m_ColBox[3]->m_Collision, &obj->m_Collision))
			{
				Right = true;
			}
			if (IntersectRect(&rc, &m_ColBox[4]->m_Collision, &obj->m_Collision))
			{
				Left = true;
			}
	}
}
