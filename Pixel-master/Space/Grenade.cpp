#include "stdafx.h"
#include "Grenade.h"

Grenade::Grenade() 
{
	m_Grenade = Sprite::Create(L"Painting/Weapon/RC_Rocket.png");
	m_Grenade->SetParent(this);
	SetPosition(GameMgr::GetInst()->PlayerPos);
	SetScale(2.f, 2.f);

	Mouse = INPUT->GetMousePos() - m_Position;
	D3DXVec2Normalize(&Dire, &Mouse);
	m_Rotation = (std::atan2(Dire.y, Dire.x));
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

		DelayTime += dt;
		if (INPUT->GetButtonDown() && DelayTime > 0.5f && !Reload_Please && !RDown) { // 총마다 DelayTime 다르고 속도 다르게 하면 됨 
			//
			DelayTime = 0;
		}
	GrenadeRotato();
}

void Grenade::Render()
{
	m_Grenade->Render();
}

void Grenade::OnCollision(Object* obj)
{
}
