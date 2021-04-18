#include "stdafx.h"
#include "UI.h"

UI::UI()
{
}

UI::~UI()
{
}

void UI::Init() // �� ĭ + �Ѿ� ĭ + HP + ��� 
{
	m_Mouse = Sprite::Create(L"Painting/Mouse.png");
	m_Mouse->SetPosition(INPUT->GetMousePos());


	m_UI = new TextMgr();
	m_UI->Init(72, true, false, "����");
	m_UI->SetColor(255, 0, 0, 0);
}

void UI::Release()
{
}

void UI::Update(float deltaTime, float Time)
{
	SetCursor(NULL);
	m_Mouse->SetPosition(INPUT->GetMousePos());
}

void UI::Render()
{
	m_Mouse->Render();
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_UI->print("�ð� : " + std::to_string(gt) + "\n������ : " + std::to_string(dt), 100, 100);
	Renderer::GetInst()->GetSprite()->End();
}
