#pragma once
class Weapon_case : public Object
{
private:
	Sprite* m_WeaponCase;
public:
	Weapon_case(std::wstring fileName,std::string weapontag,Vec2 Pos);
	~Weapon_case();

	void Update(float delatTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

