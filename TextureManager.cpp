//#include "TextureManager.h"
//#include <iostream>
//#include <Windows.h>
//
//TextureManager* TextureManager::mInstance = 0;
//
//TextureManager::~TextureManager() {
//	// 반복자를 통하여 map에 저장된 Texture 삭제
//	std::map<std::string, SDL_Texture*>::iterator iter = mTextureMap.begin();
//	while (iter != mTextureMap.end()) {
//		mTextureMap.erase(iter++);
//	}
//
//	mTextureMap.clear();
//	puts("Texture map 삭제");
//}
//
//bool TextureManager::load(std::string _fileName, std::string _id, SDL_Renderer* _pRenderer,
//	int _r, int _g, int _b) {
//	SDL_Surface* pTempSurface = IMG_Load(_fileName.c_str());
//
//	if (pTempSurface == NULL)
//		return false;
//
//	Uint32 colorkey = SDL_MapRGB(pTempSurface->format, _r, _g, _b);
//	SDL_SetColorKey(pTempSurface, SDL_RLEACCEL | SDL_TRUE, colorkey);
//
//	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(_pRenderer, pTempSurface);
//	SDL_FreeSurface(pTempSurface);
//
//	if (pTexture == NULL) {
//		return false;
//	}
//	mTextureMap[_id] = pTexture;
//
//	return true;
//}
//
//void TextureManager::draw(std::string _id, int _x, int _y, int _width, int _height,
//	SDL_Renderer* _pRenderer, SDL_RendererFlip _flip) {
//	SDL_Rect srcRect;
//	SDL_Rect destRect;
//
//	srcRect.x = 0;
//	srcRect.y = 0;
//	srcRect.w = destRect.w = _width;
//	srcRect.h = destRect.h = _height;
//	destRect.x = _x;
//	destRect.y = _y;
//
//	SDL_RenderCopyEx(_pRenderer, mTextureMap[_id], &srcRect, &destRect, 0, 0, _flip);
//}
//
//void TextureManager::draw(std::string _id, int _x, int _y, int _width, int _height,
//	SDL_Renderer* _pRenderer, SDL_Rect* _clip, SDL_RendererFlip _flip) {
//	SDL_Rect destRect;
//
//	destRect.x = _x;
//	destRect.y = _y;
//	destRect.w = _clip->w;
//	destRect.h = _clip->h;
//
//	SDL_RenderCopyEx(_pRenderer, mTextureMap[_id], _clip, &destRect, 0, 0, _flip);
//}
//
//void TextureManager::draw(SDL_Texture* _texture, int _x, int _y, int _width, int _height,
//	SDL_Renderer* _pRenderer, SDL_RendererFlip _flip) {
//	SDL_Rect srcRect;
//	SDL_Rect destRect;
//
//	srcRect.x = 0;
//	srcRect.y = 0;
//	srcRect.w = destRect.w = _width;
//	srcRect.h = destRect.h = _height;
//	destRect.x = _x;
//	destRect.y = _y;
//
//	SDL_RenderCopyEx(_pRenderer, _texture, &srcRect, &destRect, 0, 0, _flip);
//}
//
//void TextureManager::draw(SDL_Texture* _texture, int _x, int _y, int _width, int _height,
//	SDL_Renderer* _pRenderer, SDL_Rect* _clip, SDL_RendererFlip _flip) {
//	SDL_Rect destRect;
//
//	destRect.x = _x;
//	destRect.y = _y;
//	destRect.w = _clip->w;
//	destRect.h = _clip->h;
//
//	SDL_RenderCopyEx(_pRenderer, _texture, _clip, &destRect, 0, 0, _flip);
//}
//
//void TextureManager::setAlpha(SDL_Texture* _texture, int _alpha) {
//	SDL_SetTextureAlphaMod(_texture, _alpha);
//}

#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer, int r, int g, int b) {
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

	if (pTempSurface == NULL)
		return false;

		Uint32 colorkey = SDL_MapRGB(pTempSurface->format, r, g, b);
		SDL_SetColorKey(pTempSurface, SDL_RLEACCEL | SDL_TRUE, colorkey);

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	if (pTexture != NULL) {
		m_textureMap[id] = pTexture;
		return true;	
	}

	return false;
}

//bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer,
//	int _r, int _g, int _b) {
//	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
//
//	if (pTempSurface == NULL)
//		return false;
//
//	Uint32 colorkey = SDL_MapRGB(pTempSurface->format, _r, _g, _b);
//	SDL_SetColorKey(pTempSurface, SDL_RLEACCEL | SDL_TRUE, colorkey);
//
//	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
//	SDL_FreeSurface(pTempSurface);
//
//	if (pTexture == NULL) {
//		return false;
//	}
//	m_textureMap[id] = pTexture;
//
//	return true;
//}

void TextureManager::draw(SDL_Texture* texture, int x, int y, int width, int height,
	SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, texture, &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::draw(std::string id, int x, int y, int width, int height,
	SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height,
	int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::clearFromTextureMap(std::string id) {
	m_textureMap.erase(id);
}

void TextureManager::setAlpha(std::string _textureID, int _alpha) {
	SDL_SetTextureAlphaMod(m_textureMap[_textureID], _alpha);
}