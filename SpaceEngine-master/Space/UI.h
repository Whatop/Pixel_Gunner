#pragma once

enum class MouseShape {
	scope,
	square,
	circle,
	bullet,
	cross,
	point,
	none
};

class UI : public Singleton<UI>
{
	MouseShape m_MouseShape;
	Sprite* m_Mouse;
	TextMgr* m_UI;
	int m_Hp;
	//������ �ð�
	int m_Ammo[4];
	//�ð� gt
	int MonsterCount;
	std::string Stage_Name;// + ���̵�
	
	int shape;
public:
	UI();
	~UI();

	void Shape(bool dir);

	void Init();
	void Release();

	void Update(float deltaTime, float Time);
	void Render();
	
};

