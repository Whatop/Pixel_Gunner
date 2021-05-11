#pragma once

class Weapon : public Object
{
private:
	Sprite* m_Weapon;
public:
	Weapon(std::string weapontag, Vec2 Pos);
	~Weapon();

	float DelayTime;

	Weapon_State m_State;
	std::wstring m_Trans;
	Vec2 Mouse;
	Vec2 Dire;
	void Fire();
	void WeaponRotate();

	void Update(float delatTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

