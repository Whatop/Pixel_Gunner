#pragma once
class Stage1 : public Scene
{
	bool m_Puase;
public:
	Stage1();
	~Stage1();

	void Init();
	void Update(float deltaTime, float Time);
	void Render();
	void Release();
};

