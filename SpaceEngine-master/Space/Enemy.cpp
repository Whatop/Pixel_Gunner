#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy(Vec2 Pos)
{
	m_Monster = Sprite::Create(L"Painting/Active_Item/Decoy.png");
	m_Monster->SetParent(this);
	SetPosition(Pos);
	SetScale(2, 2);
	
}

Enemy::~Enemy()
{
}

void Enemy::Update(float deltaTime, float Time)
{
	ObjMgr->CollisionCheak(this, "Bullet");
	Move();
	Shot();
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
		m_Hp -= GameMgr::GetInst()->Hit();
	}

}
