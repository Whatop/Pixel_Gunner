#pragma once

class UI : public Singleton<UI>
{
	Sprite* m_Interface[10];
	TextMgr* m_UI;
	//구르기 시간
	int m_Ammo[4];
	//시간 gt
	int MonsterCount;
	std::string Stage_Name;// + 난이도
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
	float m_HpGage;
	float m_RollGage;

	Sprite* m_Mouse;
};

