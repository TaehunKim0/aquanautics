#include "stdafx.h"
#include "ResourceMgr.h"
#include"Texture.h"

ResourceMgr::ResourceMgr()
{
}


ResourceMgr::~ResourceMgr()
{
}

Texture * ResourceMgr::CreateTextureFromFile(std::wstring fileName)
{
	if (!textureMap.count(fileName))
	{
		auto texture = new Texture();

		if (!texture->Initiallize(fileName))
			return nullptr;

		textureMap[fileName] = texture;
	}

	return textureMap[fileName];
}
