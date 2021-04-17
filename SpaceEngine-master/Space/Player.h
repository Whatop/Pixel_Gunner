#pragma once
class Player : public Object
{
private:
	Sprite* m_Player;
	Sprite* m_Hand;
	Sprite* m_Weapon;//�̰� ���θ���� ����� �ϴ� �����

	float m_Speed;
	
	int ButtonDown;
	Vec2 Dire;
	Vec2 Mouse;
public:
	Player();
	Player(Vec2 Pos);
	~Player();
	
	void Move();
	void WeaponRotate();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

