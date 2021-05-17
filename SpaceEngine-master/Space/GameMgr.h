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

// 1�� �⺻����, 2�� ����, 3�� ��������, 4�� ����ź
class GameMgr : public Singleton<GameMgr> // UI ���� �� ����(UI������), �÷��̾�, ���� ����, ��ŷ, 
{
private:
	int m_Score;
	int shape;
	float TimeLmit;
	Game_Difficulty GameDifficulty;
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

	void Weapon_Holding();
	Game_Difficulty GetDifficulty() { return GameDifficulty; }
	CurrentScene GetScene() { return m_Scene; }
public:
	int m_Max_Hp;
	int m_Hp;
	float m_Max_Dash;
	float m_DashCooltime;
	int Difficulty;
	bool _UICreate;
	bool _PlayerCreate;
	int HaveGun;
	int menimap;
	Vec2 Pos;
	CurrentScene m_Scene;
	MouseShape m_MouseShape;
	MeniMap_Option m_MeniMap;
	Weapon_Type m_Weapon_Type;
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