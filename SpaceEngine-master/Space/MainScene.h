#pragma once
class MainScene : public Scene
{
	Sprite* BackGround;

	Sprite* Start_Button;  //버튼 배열로 바꾸기
	Sprite* Option_Button;
	Sprite* Exit_Button;
	Sprite* Difficulty_Button;

	Sprite* Difficulty;

public:
	MainScene();
	~MainScene();

	void Init();
	void Release();

	void Update(float deltaTime,float time);
	void Render();
};

