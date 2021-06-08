#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy(Vec2 Pos)
{
	m_Monster = Sprite::Create(L"Painting/Active_Item/Decoy.png");
	m_Monster->SetParent(this);
	SetPosition(Pos);
	SetScale(3, 3);
	
}

Enemy::~Enemy()
{
}

void Enemy::Update(float deltaTime, float Time)
{
	ObjMgr->CollisionCheak(this, "Bullet");
	Move();
	Shot();
	GameMgr::GetInst()->MonsterPos = m_Position;
}

void Enemy::Move()
{
}

void Enemy::Shot()
{
}

void Enemy::Render()
{
	m_Monster->Render();
}

void Enemy::OnCollision(Object* obj)
{
	if (obj->m_Tag == "Bullet") {
		m_Hp -= GameMgr::GetInst()->Damage();
	}
}
