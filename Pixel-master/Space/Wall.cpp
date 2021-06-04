#include "stdafx.h"
#include "Wall.h"

Wall::Wall(Vec2 Pos)
{
	m_Wall = Sprite::Create(L"Painting/Stage1/Wall.png");
	m_Wall->SetParent(this);
	SetPosition(Pos);
}

Wall::~Wall()
{
}

void Wall::Update(float deltaTime, float Time)
{
}

void Wall::Render()
{
	m_Wall->Render();
}

void Wall::OnCollision(Object* obj)
{
}
