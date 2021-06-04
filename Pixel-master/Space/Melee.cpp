#include "stdafx.h"
#include "Melee.h"

Melee::Melee(Vec2 Pos)
{
	m_Melee = Sprite::Create(L"Painting/Weapon/Blasphemy.png");
	m_Melee->SetParent(this);
	SetPosition(Pos);
	SetScale(2.f, 2.f);
	Mouse = INPUT->GetMousePos() - m_Position;
	D3DXVec2Normalize(&Dire, &Mouse);
	m_Rotation = (std::atan2(Dire.y, Dire.x));
}

Melee::~Melee()
{
}

void Melee::MeleeRotato()
{
	Mouse = INPUT->GetMousePos() - m_Position;
	D3DXVec2Normalize(&Dire, &Mouse);
	m_Rotation = (std::atan2(Dire.y, Dire.x));
}

void Melee::Update(float deltaTime, float Time)
{
	SetPosition(GameMgr::GetInst()->PlayerPos);

	DelayTime += dt;
	if (INPUT->GetButtonDown() && DelayTime > 0.5f && !Reload_Please && !RDown) { // �Ѹ��� DelayTime �ٸ��� �ӵ� �ٸ��� �ϸ� �� 
		//�˱⳯����
		DelayTime = 0;
	}
	MeleeRotato();
}

void Melee::Render()
{
	m_Melee->Render();
}

void Melee::OnCollision(Object* obj)
{
}
