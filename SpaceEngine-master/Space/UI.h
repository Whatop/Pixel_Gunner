#pragma once

class UI : public Singleton<UI>
{
	Sprite* m_BlackUI[10];
	TextMgr* m_UI;
	int m_Hp;
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
	
	Sprite* m_Mouse;
};

