#pragma once
class Option : public Object //키 바꾸는 것, 볼륨, 창 크기, UI 크기, 마우스 모양 및 색깔
{
private:
	Sprite* m_BG;

	Sprite* Button[2];
	//볼륨설정
	Sprite* Sound;

	//마우스 모양
	Sprite* Mouse_Shape;

	//창 크기
	Sprite* Window;

	//마우스 색
	Sprite* MouseColor;

	// 구르기, W, S, A, D,  
	Sprite* KeyChange;



	//Sprite* m_

public:
	Option();
	~Option();

	void Update(float deltaTime, float Time);
	void Render();

};

