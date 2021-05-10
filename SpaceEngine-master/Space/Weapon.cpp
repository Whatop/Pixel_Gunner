#include "stdafx.h"
#include "Weapon.h"

Weapon::Weapon(std::string weapontag, Vec2 Pos)
{
	m_Trans.assgin(weapontag.begin(), weapontag.end());
	m_Weapon = Sprite::Create(L"Painting/Weapon/"+m_Trans + ".png");
	m_Weapon->SetParent(this);
	SetPosition(Pos);
	m_WeaponName = weapontag;
}
