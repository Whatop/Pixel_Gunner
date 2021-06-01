#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(std::wstring filename, Vec2 arrival, Vec2 pos, float speed)
{
	m_Bullet = Sprite::Create(filename);
	m_Bullet->SetParent(this);
	
	m_Halo = Sprite::Create(L"Painting/Player/Halo.png");
	m_Halo->A = 50;
	
	SetPosition(pos);
	m_Layer = 0;
	Dire = arrival;
	m_Speed = speed;
	m_Timer = 0.f;
	GameMgr::GetInst()->BulletDir = Dire;
}

Bullet::~Bullet()
{
}

void Bullet::Update(float deltaTime, float Time)
{
	m_Timer += dt;
	Translate(Dire.x * m_Speed * dt, Dire.y * m_Speed * dt);
	m_Halo->SetPosition(m_Position);


	if (m_Timer >= 3.f)
		ObjMgr->RemoveObject(this);

	ObjMgr->CollisionCheak(this, "Wall");
}

void Bullet::Render()
{
	m_Halo->Render();
	m_Bullet->Render();	
}

void Bullet::OnCollision(Object* obj)
{
	if (obj->m_Tag == "Wall") {
		ObjMgr->RemoveObject(this);
	}
	if (obj->m_Tag == "Enemy") {
		ObjMgr->RemoveObject(this);
	}
}
