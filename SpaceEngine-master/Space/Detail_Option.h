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

	// 구르기, W, S, A, D,  
	Sprite* KeyChange;


	// 미니맵 표시 : 항상, 전투 중 제외, 사용 안 함 
	Sprite* MineMap;
	
	// 화살표
	Sprite* Arrow_Button[4];

	// 감마
	Sprite* Gamma;

	//풀스크린
	Sprite* FullScreen;

	// 체크박스
	Sprite* CheckBox[10];

	// 이름 : 커서, 미니맵, 
	Sprite* m_Name[10];

	// 취소, 초기화, 확인 버튼
	Sprite* Choice_Button[3];

	int Line;
	bool ColBox;
	int m_Type;
	int Minemap_Option;
public:
	Detail_Option(int type);
	~Detail_Option();

	void Order();
	void Name();
	void Shape();
	void Direction();


	void Reset();

	void Update(float deltaTime, float Time);
	void Render();

};

