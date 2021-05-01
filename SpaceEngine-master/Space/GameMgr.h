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
	DETAIL_OPTION,//세부옵션 Detail_Option
	STAGE1,
	STAGE2,
	NONE
};
enum class MouseShape {
	scope,
	square,
	circle,
	bullet,
	cross,
	point,
	none
};
class GameMgr : public Singleton<GameMgr> // UI 생성 및 삭제(UI관리함), 플레이어, 몬스터 스폰, 랭킹, 
{
private:
	int m_Score;
	int m_Hp;
	int shape;
	float TimeLmit;
	Game_Difficulty GameDifficulty;
public:
	GameMgr();
	~GameMgr();
	
	void Init(); 
	void Shape(bool dir); // 마우스 모양 바꾸는 기능
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
	MouseShape m_MouseShape;
};

	//else if (type == _Control) { // 컨트롤 : 키바꾸기(재장전,W,A,S,D,구르기), (아이템고민중)

	//// 구르기, W, S, A, D,  
	//Sprite* KeyChange;
	//}
	//else if (type == _Vidio) { // 비디오 : 전체화면, 해상도(1440:900,1920:1080), 감마, 잔해양(시체),크기
	//	//창 크기
	//	Sprite* Window;
	//}
	//else {	// 오디오 : 음악 볼륨(배경음), 음향 볼륨(구른다, 총..), UI 볼륨(확인버튼이나 그런 소리)
	//		//볼륨설정
	//		Sprite* Sound;
	//}