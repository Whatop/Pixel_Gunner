#include "stdafx.h"
#include "Weapon.h"
#include "Bullet.h"

Weapon::Weapon(std::string weapontag, Vec2 Pos)
{
	m_Trans.assign(weapontag.begin(), weapontag.end());
	m_Weapon = Sprite::Create(L"Painting/Weapon/"+m_Trans + L".png");
	m_Weapon->SetParent(this);
	SetPosition(Pos);
	m_WeaponName = weapontag;
	DelayTime = 0;
}

Weapon::~Weapon()
{
}

void Weapon::Fire()
{
	m_State.Damege = 10;
	m_State.Maxammo = 10;
	m_State.Speed = 10;
	

	if (m_WeaponName == "DP-28") {
	}
	if (m_WeaponName == "M249") {
	}

	if (m_WeaponName == "UZI") {
	}
	if (m_WeaponName == "Tommy Gun") {
	}
	if (m_WeaponName == "PP-19") {
	}
	if (m_WeaponName == "Vector") {
	}

	if (m_WeaponName == "M416") {
	}
	if (m_WeaponName == "AKM") {
	}
	if (m_WeaponName == "M16A5") {
	}
	if (m_WeaponName == "MK47") {
		DelayTime += dt;
		if (INPUT->GetButtonDown() && DelayTime > 0.5f) { // 총마다 DelayTime 다르고 속도 다르게 하면 됨 

			//if (m_Rotation > -1.5 && m_Rotation < 1.5) {
				ObjMgr->AddObject(new Bullet(L"Painting/Player/Bullet.png", Dire, m_Position, 1550), "Bullet");
			//}
			DelayTime = 0;
		}
	}

	if (m_WeaponName == "SCAR_L") {
	}
	if (m_WeaponName == "AUG") {
	}
	if (m_WeaponName == "Groza") {
	}

	if (m_WeaponName == "S1897") {
	}
	if (m_WeaponName == "S12K") {
	}
	if (m_WeaponName == "S686") {
	}

	if (m_WeaponName == "Win94") {
	}
	if (m_WeaponName == "SKS") {
	}
	if (m_WeaponName == "Kar98") {
	}
	if (m_WeaponName == "MINI14") {
	}
}

void Weapon::WeaponRotate()
{
	//   1.5
	//3 	  0
	//	 1.5
	Mouse = INPUT->GetMousePos() - m_Position;
	D3DXVec2Normalize(&Dire, &Mouse);
	m_Rotation = (std::atan2(Dire.y, Dire.x));
	
	std::cout << m_Rotation << std::endl;
}

void Weapon::Update(float delatTime, float Time)
{
	Fire();
	WeaponRotate();
}

void Weapon::Render()
{
	m_Weapon->Render();
}

void Weapon::OnCollision(Object* obj)
{
}
