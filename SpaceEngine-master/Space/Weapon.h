#pragma once

struct Weapon_State {
public:
	int damege, ammo, speed;
	int Damege_Coefficient; // ¹è¼ö
};

class Weapon : public Object
{
private:
	Sprite* m_Weapon;
public:
	Weapon(std::string weapontag, Vec2 Pos);
	~Weapon();

	std::wstring m_Trans;

	void Update(float delatTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

