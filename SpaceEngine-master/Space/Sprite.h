#pragma once
#define COLORKEY_BALCK D3DCOLOR_XRGB(0,0,0)
#define COLORKEY_PINK D3DCOLOR_XRGB(255, 0, 255)
class Texture;
class Sprite : public Object
{
	LPD3DXSPRITE m_pSp;
	Texture* m_Texture;


public:
	Sprite();
	~Sprite();

	RECT m_Rect;
public:
	bool Init(std::wstring fileName, D3DCOLOR color);

public:

	static Sprite* Create(std::wstring fileName, D3DCOLOR color = COLORKEY_PINK);
	void Render() override;

public:
	int A, R, G, B;
};