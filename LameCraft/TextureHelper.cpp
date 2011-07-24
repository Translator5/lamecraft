#include "TextureHelper.h"
#include <Aurora/Graphics/RenderManager.h>

TextureHelper::TextureHelper()
{
	defaulPatch = "Assets/";
	defaultFolder = "Lamecraft/";
	texturePatch = "Assets/Lamecraft/";
}

TextureHelper::~TextureHelper()
{

}

int TextureHelper::GetTexture(Textures texture)
{
	switch(texture)
	{
		case Genesis:
		{
			fileName = texturePatch + "genesis.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case PspTeam:
		{
			fileName = texturePatch + "pspteam.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Logo:
		{
			fileName = texturePatch + "logo.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Utils:
		{
			fileName = texturePatch + "utils.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Dirt:
		{
			fileName = texturePatch + "dirt.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Glass:
		{
			fileName = texturePatch + "glass.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Terrain:
		{
			fileName = texturePatch + "terrain_medium.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Blue:
		{
			fileName = texturePatch + "blue.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Sky:
		{
			fileName = texturePatch + "sky.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Sun:
		{
			fileName = texturePatch + "sun.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
		case Moon:
		{
			fileName = texturePatch + "moon.png";
			TextureManager::Instance()->LoadTexture(fileName);
			return TextureManager::Instance()->GetTextureNumber(fileName);
		}
		break;
	}

	return 0;
}

void TextureHelper::SetTextureFolderName(std::string name)
{
	defaultFolder = name;
	texturePatch = defaulPatch + defaultFolder;
}

TextureHelper TextureHelper::m_TextureHelper;

TextureHelper* TextureHelper::Instance()
{
	return &m_TextureHelper;
}