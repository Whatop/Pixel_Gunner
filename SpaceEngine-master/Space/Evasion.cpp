#include "stdafx.h"
#include "Evasion.h"

Evasion::Evasion(Vec2 Pos)
{
	m_Obj = Sprite::Create(L"Painting/Player/Player.png");
	m_Obj->SetParent(this);
	m_Position = Pos;
	m_Obj->A = 80;
	timer = 0.f;
}

Evasion::~Evasion()
{
}

void Evasion::Update(float deltaTime, float Time)
{
	timer += dt;

	if (timer >= 0.1f)
		SetDestroy(true);
}

void Evasion::Render()
{
	m_Obj->Render();
}
