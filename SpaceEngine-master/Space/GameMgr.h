#pragma once

enum class Game_Difficulty {
	EASY,
	NOMAL,
	HARD,
	NONE
};

class GameMgr : public Singleton<GameMgr> // UI 생성 및 삭제(UI관리함), 플레이어, 몬스터 스폰, 랭킹, 
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
public:
	int Difficulty;
	bool _UICreate;
	bool _PlayerCreate;
};

