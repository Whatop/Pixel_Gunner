#pragma once

class UI : public Singleton<UI>
{
	Sprite* m_BlackUI[10];
	TextMgr* m_UI;
	int m_Hp;
	//������ �ð�
	int m_Ammo[4];
	//�ð� gt
	int MonsterCount;
	std::string Stage_Name;// + ���̵�
	int shape;
	float Timer;
	int m_Time[4];
public:
	UI();
	~UI();
	
	void Init();
	void Release();

	void Update(float deltaTime, float Time);
	void Render();
	
	Sprite* m_Mouse;
};

