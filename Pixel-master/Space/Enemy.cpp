#include "stdafx.h"
#include "Enemy.h"
//
Enemy::Enemy(Vec2 Pos)
{
	m_Enemy = Sprite::Create(L"Painting/Active_Item/Decoy.png");
	m_ColBox[0] = Sprite::Create(L"Painting/Player/ColBox.png");
	m_ColBox[0]->SetParent(this);
	m_ColBox[1] = Sprite::Create(L"Painting/Player/Width.png");
	m_ColBox[2] = Sprite::Create(L"Painting/Player/Width.png");
	m_ColBox[3] = Sprite::Create(L"Painting/Player/Height.png");
	m_ColBox[4] = Sprite::Create(L"Painting/Player/Height.png");

	for (int i = 0; i < 5; i++) {
		m_ColBox[i]->m_Visible = false;
	}
	m_Enemy->SetScale(3, 3);
	SetPosition(Pos);
	m_Hit = false;

	EnemyState.Hp = 100;
	EnemyState.Speed = 10;
	EnemyState.Def = 10;
	EnemyState.Def_Percent = 0;
	EnemyState.Dash = 0;
	EnemyState.Critical = 0;
}

Enemy::~Enemy()
{
}

void Enemy::Update(float deltaTime, float Time)
{
	m_Hit = false;
	
	DelayTime += dt;
	if (DelayTime > 0.1f) {
		m_Enemy->R = 255;
		m_Enemy->G = 255;
		m_Enemy->B = 255;
		DelayTime = 0;
	}
	
	ObjMgr->CollisionCheak(this, "Bullet");
	ObjMgr->CollisionCheak(this, "Missile");
	Hit();
	Move();
	Shot();
	ColBox();
	GameMgr::GetInst()->MonsterPos = m_Position;
}

void Enemy::Move()
{
}

void Enemy::Shot()
{
}

void Enemy::ColBox()
{
		m_Enemy->SetPosition(m_Position);
		m_ColBox[1]->SetPosition(m_Position.x, m_Position.y - m_ColBox[0]->m_Size.y / 2);//Down
		m_ColBox[2]->SetPosition(m_Position.x, m_Position.y + m_ColBox[0]->m_Size.y / 2);//Up
		m_ColBox[3]->SetPosition(m_Position.x - m_ColBox[0]->m_Size.x / 2, m_Position.y);//Right
		m_ColBox[4]->SetPosition(m_Position.x + m_ColBox[0]->m_Size.x / 2, m_Position.y);//Left
}

void Enemy::Hit()
{
	if (m_Hit) {
		m_Enemy->R = 255;
		m_Enemy->G = 50;
		m_Enemy->B = 50;
		m_Hp -= (GameMgr::GetInst()->m_WeaponStatus.Atk - EnemyState.Def) * EnemyState.Def_Percent;
		std::cout << "데미지 : " << (GameMgr::GetInst()->m_WeaponStatus.Atk - EnemyState.Def) * EnemyState.Def_Percent << std::endl;
		std::cout << "남은 체력 : " << m_Hp << std::endl;
		DelayTime = 0;
	}
}

void Enemy::Render()
{
	m_Enemy->Render();
	for (int i = 0; i < 5; i++) {
		m_ColBox[i]->Render();
	}
}

void Enemy::OnCollision(Object* obj)
{
	if (obj->m_Tag == "Bullet") {
		m_Hit = true;
	}
	if (obj->m_Tag == "Missile") {
		m_Hit = true;
	}
}
