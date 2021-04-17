#pragma once
class GameMgr : public Singleton<GameMgr> // UI ���� �� ����(UI������), �÷��̾�, ���� ����, ��ŷ, 
{
private:
	int m_Score;
	int m_Hp;
	float TimeLmit;
public:
	GameMgr();
	~GameMgr();
	
	void CreateUI();
	void ReleaseUI();
	void CreatePlayer();
	void CreateMonster();

public:
	bool _UICreate;
	bool _PlayerCreate;
};

