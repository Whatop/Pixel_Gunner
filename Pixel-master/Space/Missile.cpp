#include "stdafx.h"
#include "Missile.h"

Missile::Missile(std::wstring fileName)
{
	m_Missile = Sprite::Create(fileName);
	m_Missile->SetParent(this);
	SetPosition(GameMgr::GetInst()->PlayerPos);

	std::cout << "생성" << std::endl;

	Rad = GameMgr::GetInst()->GrenDir;
	turnRadian = std::atan2(Rad.y, Rad.x);
	vrad = 0.001f;
}

Missile::~Missile()
{
}

void Missile::Update(float deltaTime, float Time)
{
	Monster = GameMgr::GetInst()->MonsterPos - m_Position;
	D3DXVec2Normalize(&Dire, &Monster);
	vrad += dt* 0.1;

	float pi2 = D3DX_PI * 2;
	float diff = std::atan2f(Dire.y, Dire.x) - turnRadian;
	while (diff < -D3DX_PI) diff += pi2;
	while (diff >= D3DX_PI) diff -= pi2;

//	if (turnRadian < 0)   // 외적 값이 음수이면 시계방향으로 회전
//		vrad *= -1;
	if (abs(diff) < vrad)
		turnRadian += diff;
	else {
		turnRadian += (diff < 0 ? -vrad : vrad);
	}
	
	Dire.y = sin(turnRadian);
	Dire.x = cos(turnRadian);
	m_Rotation = std::atan2f(Dire.y, Dire.x);
	Translate(Dire.x  * 700 * dt, Dire.y * 700 * dt);
}

void Missile::Render()
{
	m_Missile->Render();
}

void Missile::OnCollision(Object* obj)
{
}
