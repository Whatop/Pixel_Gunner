#pragma once
class Camera : public Singleton<Camera>
{
private:
	Matrix mRot;
	Matrix mTrans;
	Matrix mScale;
	Matrix mWorld;
public:
	Camera();
	~Camera();

	float Mouse;
	float m_Rotation;
	Vec2 m_Position;
	Vec2 m_TempPos;
	Vec2 m_Scale;


	Matrix GetWorld()
	{
		return mWorld;
	}

	void Init();
	void Follow(Object* obj);
	void Temp(Object* obj);
	void Update(float deltaTime, float time);
	void Render();
};
