#include"stdafx.h"
#include "Camera.h"
Camera::Camera()
{
	Init();
}

Camera::~Camera()
{
}

void Camera::Init()
{
	m_Rotation = 0;
	m_Position = Vec2(0, 0);
	m_TempPos = Vec2(0, 0);
	m_Scale = Vec2(1.f, 1.f);
	Follow(nullptr);
}

void Camera::Temp(Object* obj)
{
	if (obj != nullptr)
	{
		m_TempPos.x = obj->m_Position.x - App::GetInst()->m_Width / 2;
		m_TempPos.y = obj->m_Position.y - App::GetInst()->m_Height / 2;
	}
}

void Camera::Follow(Object* obj)
{
	if (obj != nullptr)
	{
		if (INPUT->GetMousePos().x > obj->m_Position.x) {
			Mouse = INPUT->GetMousePos().x - obj->m_Position.x;
		}
		else if (INPUT->GetMousePos().x < obj->m_Position.x) {
			Mouse =  INPUT->GetMousePos().x - obj->m_Position.x;
		}
		m_Position.x = obj->m_Position.x - App::GetInst()->m_Width / 2 + Mouse;
		m_Position.y = obj->m_Position.y - App::GetInst()->m_Height / 2;
	}
}

void Camera::Update(float deltaTime, float time)
{

	if (m_Rotation >= 360)
		m_Rotation = 0;
}

void Camera::Render()
{
	D3DXMatrixRotationZ(&mRot, D3DXToRadian(m_Rotation));
	D3DXMatrixTranslation(&mTrans, -m_Position.x, -m_Position.y, 1.f);
	D3DXMatrixScaling(&mScale, m_Scale.x, m_Scale.y, 1.f);

	mWorld = mScale * mRot * mTrans;
}
