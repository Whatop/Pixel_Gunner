#pragma once
class MainScene : public Scene
{
	Sprite* BackGround;

	Sprite* Start_Button;  //��ư �迭�� �ٲٱ�
	Sprite* Option_Button;
	Sprite* Exit_Button;
	Sprite* Difficulty_Button;

	Sprite* m_Button[4];

	Sprite* Difficulty;

	int Line;
public:
	MainScene();
	~MainScene();

	void Button();

	void Init();
	void Release();

	void Update(float deltaTime,float time);
	void Render();
};

