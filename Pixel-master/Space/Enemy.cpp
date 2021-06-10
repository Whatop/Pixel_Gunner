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

	m_Enemy->SetScale(3, 3);
	SetPosition(Pos);
	
}

Enemy::~Enemy()
{
}

void Enemy::Update(float deltaTime, float Time)
{
	ObjMgr->CollisionCheak(this, "Bullet");
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
		m_Hp -= GameMgr::GetInst()->Damage();
	}
}
