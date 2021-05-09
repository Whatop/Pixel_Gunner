#include "stdafx.h"
#include "Weapon.h"

Weapon::Weapon(std::wstring fileName, std::string weapontag, Vec2 Pos)
{
	m_WeaponCase = Sprite::Create(fileName);
	m_WeaponCase->SetParent(this);
	SetPosition(Pos);
	m_WeaponName = weapontag;
}

Weapon::~Weapon()
{
}

void Weapon::Update(float delatTime, float Time)
{
}

void Weapon::Render()
{
	m_WeaponCase->Render();
}

void Weapon::OnCollision(Object* obj)
{
}
