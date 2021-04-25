#pragma once

enum class Game_Difficulty {
	EASY,
	NOMAL,
	HARD,
	NONE
};

enum class CurrentScene {
	MAINSCENE,
	OPTION,
	Detail_Option,//���οɼ�
	STAGE1,
	STAGE2,
	
	NONE
};

class GameMgr : public Singleton<GameMgr> // UI ���� �� ����(UI������), �÷��̾�, ���� ����, ��ŷ, 
{
private:
	int m_Score;
	int m_Hp;
	float TimeLmit;
	Game_Difficulty GameDifficulty;
public:
	GameMgr();
	~GameMgr();
	
	void Init();
	void CreateUI();
	void ReleaseUI();
	void CreatePlayer();
	void CreateMonster();
	void AddDifficulty();
	Game_Difficulty GetDifficulty() { return GameDifficulty; }
	CurrentScene GetScene() { return m_Scene; }
public:
	int Difficulty;
	bool _UICreate;
	bool _PlayerCreate;
	CurrentScene m_Scene;
};

