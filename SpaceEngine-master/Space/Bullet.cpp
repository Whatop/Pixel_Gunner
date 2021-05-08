#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(std::wstring filename, Vec2 arrival, Vec2 pos, float speed)
{
	m_Bullet = Sprite::Create(filename);
	m_Bullet->SetParent(this);

	SetPosition(pos);
	Dire = arrival;
	m_Speed = speed;
	m_Timer = 0.f;
}

Bullet::~Bullet()
{
}

void Bullet::Update(float deltaTime, float Time)
{
	m_Timer += dt;
	Translate(Dire.x * m_Speed * dt, Dire.y * m_Speed * dt);


	if (m_Timer >= 3.f)
		ObjMgr->RemoveObject(this);

	ObjMgr->CollisionCheak(this, "Wall");
}

void Bullet::Render()
{
	m_Bullet->Render();
}

void Bullet::OnCollision(Object* obj)
{
	if (obj->m_Tag == "Wall") {
		std::cout <<"X : " <<m_Position.x << std::endl;
		std::cout <<"Y : " << m_Position.y << std::endl;
		ObjMgr->RemoveObject(this);
	}
}
