#include "LetterManager.h"

LetterManager* LetterManager::mInstance = 0;

void LetterManager::init() {
	TTF_Init();

	mLetter = new Letter();

	mLetter->font = TTF_OpenFont("Resources/CONSOLAS.ttf", 70);
	mLetter->color.r = 255;
	mLetter->color.g = 255;
	mLetter->color.b = 255;
	mLetter->message = "";
}

LetterManager::~LetterManager() {
	if (mLetter != NULL) {		
		delete mLetter;
		mLetter = NULL;
	}
}

bool LetterManager::createLetter(TTF_Font* _font, SDL_Color _color, int _message, SDL_Renderer* _renderer) {
	char str[100];
	SDL_itoa(_message, str, 10);
	

	SDL_Surface* pTempSurface = TTF_RenderText_Solid(_font, str, _color);

	if (pTempSurface == NULL)
		return false;

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(_renderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	if (pTexture == NULL) {
		return false;
	}
	mTexture = pTexture;

	return true;
}

bool LetterManager::createLetter(int _message, SDL_Renderer* _renderer) {
	char str[100];
	SDL_itoa(_message, str, 10);

	SDL_Surface* pTempSurface = TTF_RenderText_Solid(mLetter->font, str, mLetter->color);

	if (pTempSurface == NULL)
		return false;

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(_renderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	if (pTexture == NULL) {
		return false;
	}
	mTexture = pTexture;

	return true;
}

//SDL_Texture* LetterManager::createLetter(int _message, SDL_Renderer* _renderer) {
//	char str[100];
//	SDL_itoa(_message, str, 10);
//
//	SDL_Surface* pTempSurface = TTF_RenderText_Solid(mLetter->font, str, mLetter->color);
//
//	if (pTempSurface == NULL) return false;
//
//	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(_renderer, pTempSurface);
//	SDL_FreeSurface(pTempSurface);
//
//	if (pTexture == NULL) return false;
//
//	return pTexture;
//}

SDL_Texture* LetterManager::getLetter() {
	return mTexture;
}

//bool LetterManager::createLetter(std::string _id, TTF_Font* _font, SDL_Color _color, std::string _message) {
//	Letter letter(_font, _color, _message);
//	mLetterMap[_id] = letter;
//
//	return true;
//}