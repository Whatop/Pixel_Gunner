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
	m_State.Range = 10;
	m_State.Reload= 10;
	m_State.Speed = 10;
	m_State.Ammo_Capacity = 10;



	if (m_WeaponName == "Heroine") {
		DelayTime += dt;
		if (INPUT->GetButtonDown() && DelayTime > 0.5f) { // 총마다 DelayTime 다르고 속도 다르게 하면 됨 
				ObjMgr->AddObject(new Bullet(L"Painting/Player/Bullet.png", Dire, m_Position, 1550), "Bullet");
			DelayTime = 0;
		}
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
	for (auto& iter : ObjMgr->m_Objects) {
		if(iter->m_Tag == "Player")
		m_Position = iter->m_Position;
	}
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
