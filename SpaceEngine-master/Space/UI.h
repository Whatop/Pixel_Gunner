#pragma once
class UI : public Singleton<UI>
{
	Sprite* m_Mouse;
	TextMgr* m_UI;
	int m_Hp;
	//������ �ð�
	int m_Ammo[4];
	//�ð� gt
	int MonsterCount;
	std::string Stage_Name;// + ���̵�
public:
	UI();
	~UI();

	void Init();
	void Release();

	void Update(float deltaTime, float Time);
	void Render();
	
};

