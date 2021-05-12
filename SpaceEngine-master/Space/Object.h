#pragma once

struct Weapon_State {
public:
	int Damege, Speed, Reload, Range, Ammo_Capacity, Ammo;
	int Damege_Ratio, Ammo_Capacity_Ratio,Ammo_Ratio, Speed_Ratio, Reload_Ratio, Range_Ratio;
};


class Object
{
public:
	Object* m_Parent;
	Matrix m_wMat;
	Vec2 m_Position;
	Vec2 m_Scale;
	Vec2 m_Size;
	Vec2 m_RotationCenter;
	Vec2 m_ScaleCenter;

	float m_Radius;
	float m_Rotation;

	bool m_Destroy;
	RECT m_Collision;

	bool m_Visible;

	int m_Layer;
	std::string m_Tag;
	std::string m_WeaponName;//무기Class만들어서 이거 이름 만들면 되겠따
	std::vector<std::string>Weapon_Case_Tag;
public:
	Object();
	~Object();


protected:
	Matrix GetMatrix();

public:
	virtual void Update(float deltaTime, float time);
	virtual void Render();
	virtual void OnCollision(Object* other);

public:
	void Translate(float x, float y);
	void SetScale(float x, float y);
	void SetPosition(float x, float y);
	void SetPosition(Vec2 Pos) { m_Position = Pos; }
	void Rotate(float r);
	void SetDestroy(bool destroy) { m_Destroy = destroy; }
	void SetTag(const std::string tag);
	void SetParent(Object* obj);
public:
	bool GetDestroy() { return m_Destroy; }
};