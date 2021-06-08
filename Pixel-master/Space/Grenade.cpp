#include "stdafx.h"
#include "Grenade.h"
#include "Missile.h"

Grenade::Grenade() 
{
	m_Grenade = Sprite::Create(L"Painting/Weapon/RC_Rocket.png");
	m_Grenade->SetParent(this);
	SetPosition(GameMgr::GetInst()->PlayerPos);
	SetScale(2.f, 2.f);

	Mouse = INPUT->GetMousePos() - m_Position;
	D3DXVec2Normalize(&Dire, &Mouse);
	m_Rotation = (std::atan2(Dire.y, Dire.x));
	Ammo = 2;

}

Grenade::~Grenade()
{
}

void Grenade::GrenadeRotato()
{
	Mouse = INPUT->GetMousePos() - m_Position;
	D3DXVec2Normalize(&Dire, &Mouse);
	m_Rotation = (std::atan2(Dire.y, Dire.x));
}

void Grenade::Update(float deltaTime, float Time)
{
	SetPosition(GameMgr::GetInst()->PlayerPos);
	GrenadeRotato();

		DelayTime += dt;
		AAddTime += dt;
		if (AAddTime > 10 && Ammo <= 2) { // 총마다 DelayTime 다르고 속도 다르게 하면 됨 
			Ammo++;
			AAddTime = 0;
		}
		if (INPUT->GetButtonDown() && DelayTime > 0.27f && Ammo > 0) { // 총마다 DelayTime 다르고 속도 다르게 하면 됨 
			ObjMgr->AddObject(new Missile(L"Painting/Player/Missile.png"), "Missile");
			INPUT->ButtonDown(false);
			DelayTime = 0;
		}
}

void Grenade::Render()
{
	m_Grenade->Render();
}

void Grenade::OnCollision(Object* obj)
{
}
