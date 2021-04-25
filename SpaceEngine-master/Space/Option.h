#pragma once
class Option : public Object //키 바꾸는 것, 볼륨, 창 크기, UI 크기, 마우스 모양 및 색깔
{
private:
	Sprite* m_BG;

	//왼쪽 오른쪽 
	Sprite* Control[2];

	//게임 플레이, 컨트롤, 비디오, 오디오 설정
	Sprite* Button[4];

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

	bool ColBox;
	float Delay;
	//Sprite* m_
	
public:
	Option();
	~Option();

	void Init();
	void Update(float deltaTime, float Time);
	void Render();

};

