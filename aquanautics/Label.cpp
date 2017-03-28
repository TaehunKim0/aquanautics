#include "stdafx.h"
#include "Label.h"
#include"Renderer.h"

Label::~Label()
{
}

void Label::Render()
{
}

void Label::Update(float deltaTime)
{
	Object::Update(deltaTime);
}

Label* Label::Create(const std::wstring& fontFace, int fontSize)
{
	return Label::Create(fontFace, fontSize, D3DCOLOR_XRGB(0, 0, 0));
}
Label* Label::Create(const std::wstring& fontFace, int fontSize, D3DCOLOR color)
{
	auto label = new (std::nothrow) Label();
	if (label && label->Init(fontFace, fontSize, color))
	{
		return label;
	}

	SAFE_DELETE(label);
	return nullptr;
}

Label::Label()
	: m_Font(nullptr)
	, m_Color(D3DCOLOR_XRGB(0, 0, 0))
	, m_Text(nullptr)
	, m_FontFace(nullptr)
	, m_FontSize(0)
{
}

bool Label::Init(const std::wstring& fontFace, int fontSize, D3DCOLOR fontColor)
{
	HRESULT hr = D3DXCreateFont(Renderer::GetInstance()->Device,
		fontSize, 0, FW_NORMAL, D3DX_DEFAULT, false, DEFAULT_CHARSET, OUT_TT_PRECIS,
		ANTIALIASED_QUALITY, NULL, fontFace.c_str(), &m_Font);

	// ÆùÆ® »ý¼º¿¡ ½ÇÆÐ
	if FAILED(hr)
		return false;

	m_FontFace = fontFace;
	m_FontSize = fontSize;

	return true;
}

