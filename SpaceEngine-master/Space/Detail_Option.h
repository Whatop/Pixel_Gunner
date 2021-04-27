#pragma once

#define _Start		1
#define _Control	2
#define _Vidio		3
#define _Audio		4

class Detail_Option : public Object //키 바꾸는 것, 볼륨, 창 크기, UI 크기, 마우스 모양 및 색깔
{
private:
	Sprite* m_BG;
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

	// 취소, 초기화, 확인 버튼
	Sprite* Choice_Button[3];


public:
	Detail_Option(int type);
	~Detail_Option();

	void Order();
	void Init();
	void Update(float deltaTime, float Time);
	void Render();

};

