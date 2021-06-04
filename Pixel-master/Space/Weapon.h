#pragma once

class Weapon : public Object
{
private:
	Sprite* m_Weapon;
	Sprite* m_Reload;
	Sprite* m_Stick;

public:
	Weapon(std::string weapontag, Vec2 Pos);
	~Weapon();

	float DelayTime;

	bool RDown;
	bool Reload_Please;
	float ReloadTime;


	Weapon_State m_State;
	std::wstring m_Trans;
	Vec2 Mouse;
	Vec2 Dire;	
	void Fire();
	void Reload();
	void WeaponRotate();

	void Update(float delatTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

