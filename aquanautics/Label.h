#pragma once
class Label : public Object
{
private:
	LPD3DXFONT m_Font;
	D3DCOLOR m_Color;

	std::wstring m_Text;
	std::wstring m_FontFace;
	int m_FontSize;

	RECT destRect1;

	std::wstring textt;

public:
	Label();
	bool Init(const std::wstring & fontFace, int fontSize, D3DCOLOR fontColor);
	~Label();

public:
	static Label*Create(const std::wstring& fontFace, int fontSize);
	static Label*Create(const std::wstring& fontFace, int fontSize, D3DCOLOR color);

	void Render();
	void Update(float deltaTime);

	void RenderText(const std::string &strText);
};

