#include "stdafx.h"
#include "Weapon_case.h"

Weapon_case::Weapon_case(std::wstring fileName, std::string weapontag, Vec2 Pos)
{
	//weapontag »©°í ·£´ý
	m_WeaponCase = Sprite::Create(fileName);
	m_WeaponCase->SetParent(this);
	SetPosition(Pos);
	m_WeaponName = weapontag;
}

Weapon_case::~Weapon_case()
{
}

void Weapon_case::Update(float delatTime, float Time)
{
}

void Weapon_case::Render()
{
	m_WeaponCase->Render();
}

void Weapon_case::OnCollision(Object* obj)
{
}
