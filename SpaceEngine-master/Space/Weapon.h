#pragma once
class Weapon : public Object
{
private:
	Sprite* m_WeaponCase;
public:
	Weapon(std::wstring fileName,std::string weapontag,Vec2 Pos);
	~Weapon();

	void Update(float delatTime, float Time);
	void Render();
	void OnCollision(Object* obj);
};

