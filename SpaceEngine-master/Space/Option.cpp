#include "stdafx.h"
#include "Option.h"

Option::Option()
{
	m_BG = Sprite::Create(L"Painting/Option/BackGround.png");
	m_BG->SetPosition(1920 / 2, 1080 / 2);

	Button[0] = Sprite::Create(L"Painting/Option/right.png");
	Button[0]->SetPosition(1920 / 2 + 300, 400);

	Button[1] = Sprite::Create(L"Painting/Option/left.png");
	Button[1]->SetPosition(1920 / 2 - 300, 400);

	Sound = Sprite::Create(L"Painting/Option/Sound.png");
	Sound->SetPosition(1920 / 2, 400);

	Mouse_Shape = Sprite::Create(L"Painting/Player.png");
	Mouse_Shape->SetPosition(100,100);

	Window = Sprite::Create(L"Painting/Player.png");
	Window->SetPosition(100, 100);

	MouseColor = Sprite::Create(L"Painting/Player.png");
	MouseColor->SetPosition(100, 100);

	KeyChange = Sprite::Create(L"Painting/Player.png"); // ±¸¸£±â
	KeyChange->SetPosition(100, 100);
}

Option::~Option()
{
}

void Option::Update(float deltaTime, float Time)
{
}

void Option::Render()
{
	m_BG->Render();

	Button[0]->Render();
	Button[1]->Render();
	Sound->Render();

	Mouse_Shape->Render();

	Window->Render();

	MouseColor->Render();

	KeyChange->Render();
}
