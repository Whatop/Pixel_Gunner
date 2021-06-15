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
enum class Player_Situation {
	FIGHT, // 싸움
	REST, // 가만히 
	MOVE, // 움직임
	NONE
};
enum class MeniMap_Option { 
	ALWAYS,
	NOT_USED,
	NOT_BATTLE,
	NONE
};

enum class Weapon_Type {
	GUN1,
	GUN2,
	BASICGUN,
	MELEE,
	GRENADE,
	NONE
};

struct Player_State {
public:
	float Hp, Speed, Def, Def_Percent, Dash, Critical;
	int Bag;
};

struct Weapon_State {
public:
	int Atk, Speed, Reload, Range, MaxMag, Mag, MaxAmmo, Ammo, Rebound;
};

struct Player_Coefficient {
	float Hp, Speed, Def, Def_Percent, Dash, Critical;
	int Bag;
};

struct Weapon_Coefficient {
	float Atk, Speed, Reload, Range, MaxMag, MaxAmmo, Rebound;
};

// 1번 기본무기, 2번 무기, 3번 근접무기, 4번 슈류탄
class GameMgr : public Singleton<GameMgr> // UI 생성 및 삭제(UI관리함), 플레이어, 몬스터 스폰, 랭킹, 
{	
private:
	int shape;
	int m_Score;
	bool Not_Overlap[5];
	float TimeLmit;
	Game_Difficulty GameDifficulty;
	Vec2 Mouse, Dire;

	
public:
	GameMgr();
	~GameMgr();
	
	// 초기화
	void Init(); 

	//설정
	void Shape(bool dir); // 마우스 모양 바꾸는 기능
	void MeniMap(bool add);
	void AddDifficulty();

	//UI
	void CreateUI();
	void ReleaseUI();
	
	//맵 생성 or 이후
	void CreateObstacle();
	void CreatePlayer();
	void CreateMonster();

	void Esc();
	
	void Weapon_Holding();

	Game_Difficulty GetDifficulty() { return GameDifficulty; }
	CurrentScene GetScene() { return m_Scene; }

	void UpdatePlayerStatus(float hp, float speed, float def, float def_dercent, float dash, float critical, int bag) {
		m_PlayerStatus = { hp * pc.Hp ,speed * pc.Speed ,def * pc.Def,def_dercent * pc.Def_Percent
			,dash * pc.Dash, critical* pc.Critical, bag * pc.Bag };
	}
	void UpdateWeaponStatus(Weapon_State All) {
			m_WeaponStatus.Atk = All.Atk * wc.Atk;
			m_WeaponStatus.Speed = All.Speed * wc.Speed;
			m_WeaponStatus.Reload = All.Reload * wc.Reload;
			m_WeaponStatus.Range = All.Range * wc.Range;
			m_WeaponStatus.MaxMag = All.MaxMag * wc.MaxMag;
			m_WeaponStatus.MaxAmmo = All.MaxAmmo * wc.MaxAmmo;
			m_WeaponStatus.Rebound = All.Rebound * wc.Rebound;
	}

public:
	Weapon_State m_WeaponStatus;
	Player_State m_PlayerStatus;
	Weapon_Coefficient wc;
	Player_Coefficient pc;
	int m_Damage;
	bool m_Hit;
	int m_Max_Hp;
	int m_Hp;
	float m_Max_Dash;
	float m_DashCooltime;
	float m_Def;
	float Critical;

	//float //계수 %
	//	Hp_Ratio,
	//	Speed_Ratio,
	//	Def_Ratio,
	//	Heal_Ratio,
	//	Ammo_Ratio;
	//float
	//	Damage_Ratio,
	//	Speed_Ratio,
	//	Reload_Ratio,
	//	Range_Ratio,
	//	Mag_Ratio,
	//	Ammo_Capacity_Ratio;
public:
	
	int Difficulty;
	bool _UICreate;
	bool _PlayerCreate;
	bool _QuarkOption;
	int HaveGun;
	int menimap;

	Vec2 Pos;
	Vec2 BulletDir;
	Vec2 PlayerPos;
	Vec2 MonsterPos;
	Vec2 GrenDir;
	CurrentScene m_Scene;
	MouseShape m_MouseShape;
	MeniMap_Option m_MeniMap;
	Weapon_Type m_Weapon_Type;
	std::vector<std::string>Weapon_Case_Tag;
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