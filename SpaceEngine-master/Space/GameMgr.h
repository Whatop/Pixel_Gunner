#pragma once
class GameMgr : public Singleton<GameMgr> // UI 생성 및 삭제(UI관리함), 플레이어, 몬스터 스폰, 랭킹, 
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

