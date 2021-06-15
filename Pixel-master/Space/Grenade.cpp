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
	Ammo = 102;

}

Grenade::~Grenade()
{
}

void Grenade::GrenadeRotato()
{
	Mouse = INPUT->GetMousePos() - m_Position;
	D3DXVec2Normalize(&Dire, &Mouse);
	m_Rotation = (std::atan2(Dire.y, Dire.x));
	GameMgr::GetInst()->GrenDir = Dire;
	if (INPUT->GetButtonDown() && DelayTime > 0.27f && Ammo > 0) { // �Ѹ��� DelayTime �ٸ��� �ӵ� �ٸ��� �ϸ� �� 
		ObjMgr->AddObject(new Missile(L"Painting/Player/Missile.png"), "Missile");
		Ammo--;
		DelayTime = 0;
		INPUT->ButtonDown(false);
	}
}

void Grenade::Update(float deltaTime, float Time)
{
	SetPosition(GameMgr::GetInst()->PlayerPos);
	GrenadeRotato();
	DelayTime += dt;
	AAddTime += dt;
	
	if (AAddTime > 10 && Ammo < 3) { // �Ѹ��� DelayTime �ٸ��� �ӵ� �ٸ��� �ϸ� �� 
		Ammo++;
		AAddTime = 0;
	}
	
}

void Grenade::Render()
{
	m_Grenade->Render();
}

void Grenade::OnCollision(Object* obj)
{
}
