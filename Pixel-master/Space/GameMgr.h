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
	DETAIL_OPTION,//���οɼ� Detail_Option
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
	FIGHT, // �ο�
	REST, // ������ 
	MOVE, // ������
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
// 1�� �⺻����, 2�� ����, 3�� ��������, 4�� ����ź
class GameMgr : public Singleton<GameMgr> // UI ���� �� ����(UI������), �÷��̾�, ���� ����, ��ŷ, 
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
	
	void Init(); 
	void Shape(bool dir); // ���콺 ��� �ٲٴ� ���
	void MeniMap(bool add);
	void CreateUI();
	void ReleaseUI();
	void CreateObstacle();
	void CreatePlayer();
	void CreateMonster();
	void AddDifficulty();	
	void Esc();

	int Damage(); // ������ �������� �־�����
	int Hit(); // ���� ������ �������� �Ծ�����
	
	int GetDamage() { return m_Damage; }
	void UpdatePlayerStatus(float hp, float speed, float def,float def_dercent, float dash, float critical, int bag) {
		m_PlayerStatus = { hp,speed,def,def_dercent,dash,critical,bag };
	}
	void UpdateWeaponStatus(Weapon_State All) {
		m_WeaponStatus = All;
	}

	void Weapon_Holding();

	Game_Difficulty GetDifficulty() { return GameDifficulty; }
	CurrentScene GetScene() { return m_Scene; }
public:
	Weapon_State m_WeaponStatus;
	Player_State m_PlayerStatus;
	int m_Damage;
	bool m_Hit;
	int m_Max_Hp;
	int m_Hp;
	float m_Max_Dash;
	float m_DashCooltime;
	float m_Def;
	float Critical;

	//float //��� %
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

	//else if (type == _Control) { // ��Ʈ�� : Ű�ٲٱ�(������,W,A,S,D,������), (�����۰����)

	//// ������, W, S, A, D,  
	//Sprite* KeyChange;
	//}
	//else if (type == _Vidio) { // ���� : ��üȭ��, �ػ�(1440:900,1920:1080), ����, ���ؾ�(��ü),ũ��
	//	//â ũ��
	//	Sprite* Window;
	//}
	//else {	// ����� : ���� ����(�����), ���� ����(������, ��..), UI ����(Ȯ�ι�ư�̳� �׷� �Ҹ�)
	//		//��������
	//		Sprite* Sound;
	//}