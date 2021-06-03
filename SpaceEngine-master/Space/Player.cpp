#include "stdafx.h"
#include "Player.h"
#include "Evasion.h"
#include "Weapon.h"
#include "Option.h"

Player::Player(Vec2 Pos)
{
	m_Player = Sprite::Create(L"Painting/Player/Player.png",D3DCOLOR_XRGB(255,255,255));
	m_Layer = 0;

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

	m_ColBox[0] = Sprite::Create(L"Painting/Player/ColBox.png");
	m_ColBox[0]->SetParent(this);
	m_ColBox[1] = Sprite::Create(L"Painting/Player/Width.png");
	m_ColBox[2] = Sprite::Create(L"Painting/Player/Width.png");
	m_ColBox[3] = Sprite::Create(L"Painting/Player/Height.png");
	m_ColBox[4] = Sprite::Create(L"Painting/Player/Height.png");
	SetPosition(Pos);

	m_Max_Hp = 100;
	m_Hp = m_Max_Hp;
	m_Speed = 500.f;
	m_DashCool = 1;
	m_Def = 10; //방어력 10 공격 10만큼 만음  범위 : 무한
	m_Def_Percent = 90;//방어력 10% 공격 10만큼 막음  범위 : 0~100%
	GameMgr::GetInst()->UpdatePlayerStatus(m_Max_Hp, m_Speed, m_Def, m_Def_Percent, m_DashCool, m_Critical, 2);
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
			m_Position.y -= m_Speed * Multiple * dt;
	}	
	if (INPUT->GetKey('S') == KeyState::PRESS) {
		Y[1] = true;
		if (X[0] || X[1])
			Multiple = 0.75f;
		else
			Multiple = 1;
		if (!Up)
			m_Position.y += m_Speed * Multiple*dt;
	}
	if(INPUT->GetKey('A') == KeyState::PRESS){
		X[0] = true;
		if (Y[0] || Y[1])
			Multiple = 0.75f;
		else
			Multiple = 1;
		if (!Right)
			m_Position.x -= m_Speed * Multiple * dt;
	}
	if (INPUT->GetKey('D') == KeyState::PRESS) {
		X[1] = true;
		if (Y[0] || Y[1])
			Multiple = 0.75f;
		else 
			Multiple = 1;
		if (!Left)
			m_Position.x +=  m_Speed * Multiple * dt;
	}
}

void Player::State()
{
	GameMgr::GetInst()->m_Max_Hp = m_Max_Hp;//나중에 GameMgr에서 처리하도록 바꾸기 지금 Update로 struct에 자료집어넣으니 거기서 처리가능
	GameMgr::GetInst()->m_Hp = m_Hp;
	GameMgr::GetInst()->m_Def = m_Def;
	GameMgr::GetInst()->UpdatePlayerStatus(m_Max_Hp, m_Speed, m_Def,m_Def_Percent, m_DashCool, m_Critical, 2);
}

void Player::ColBox()
{
	m_Player->SetPosition(m_Position);
	m_ColBox[1]->SetPosition(m_Position.x, m_Position.y - m_ColBox[0]->m_Size.y / 2);//Down
	m_ColBox[2]->SetPosition(m_Position.x, m_Position.y + m_ColBox[0]->m_Size.y / 2);//Up
	m_ColBox[3]->SetPosition(m_Position.x - m_ColBox[0]->m_Size.x / 2, m_Position.y);//Right
	m_ColBox[4]->SetPosition(m_Position.x + m_ColBox[0]->m_Size.x / 2, m_Position.y);//Left
}
	
void Player::Buff() //탄창 수 증가, 체력 증가, 스피드 증가 등등  
{
}

void Player::Dash()
{
	m_DashCooltime += dt;
	GameMgr::GetInst()->m_DashCooltime = m_DashCooltime;
	if (INPUT->GetRightButtonDown() && m_DashCooltime >= m_DashCool)
	{
		m_Dash = true;
	}
	if (m_Dash)
	{
		m_Timer += dt;
		ObjMgr->AddObject(new Evasion(m_Position), "Effect");
		m_Speed = 2000.f;

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
	Left = false;
	Up = false;
	Right = false;
	Down = false;
	Y[0] = false;
	Y[1] = false;
	X[0] = false;
	X[1] = false;
	State();
	ObjMgr->CollisionCheak(this, "WeaponCase");
	ObjMgr->CollisionCheak(this, "Wall");
	ObjMgr->CollisionCheak(this, "Enemy");
	ObjMgr->CollisionCheak(this, "EBullet");
	if(!GameMgr::GetInst()->_QuarkOption)
		Move();
	
	Dash();
	Camera::GetInst()->Follow(this);
	Buff(); 
	ColBox(); 
	GameMgr::GetInst()->Weapon_Holding();
	GameMgr::GetInst()->Esc();
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
			m_Weapon_Tag.push_back(obj->m_WeaponName);
			GameMgr::GetInst()->Weapon_Case_Tag.push_back(obj->m_WeaponName);
			if (GameMgr::GetInst()->HaveGun == 1) {
				std::cout << "첫번째 총 : " << m_Weapon_Tag.at(0) << std::endl;
				std::cout << "테스트 : " << GameMgr::GetInst()->Weapon_Case_Tag.at(0) << std::endl;
			}
			else if (GameMgr::GetInst()->HaveGun == 2) {
				std::cout << "두번째 총 : " << m_Weapon_Tag.at(1) << std::endl;
				std::cout << "테스트 : " << GameMgr::GetInst()->Weapon_Case_Tag.at(1) << std::endl;
			}
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
	if (obj->m_Tag == "Enemy") {
		//
	}
	if (obj->m_Tag == "EBullet") {
		//m_Hp -= 
	}
}
