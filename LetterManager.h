#ifndef _LETTER_MANAGER_H_
#define _LETTER_MANAGER_H_

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <map>

// 수정 필요
typedef struct __Letter {
	TTF_Font* font;
	SDL_Color color;
	std::string message;
}Letter;

class LetterManager {
public:
	static LetterManager* Instance() {
		if (mInstance == 0) {
			mInstance = new LetterManager();
		}
		return mInstance;
	}
	//bool createLetter(std::string _id, TTF_Font* _font, SDL_Color _color, std::string _message);
	bool createLetter(TTF_Font* _font, SDL_Color _color, int _message, SDL_Renderer* _renderer);
	bool createLetter(int _message, SDL_Renderer* _renderer);
	//SDL_Texture* createLetter(int _message, SDL_Renderer* _renderer);
	~LetterManager();
	void init();
	void changeMessage(int _message);
	SDL_Texture* getLetter();

private:
	static LetterManager* mInstance;
	LetterManager() {}
	Letter* mLetter;
	SDL_Texture*	mTexture;
};

#endif