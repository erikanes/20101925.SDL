//#ifndef _TEXTURE_MANAGER_H_
//#define _TEXTURE_MANAGER_H_
//
//#include <SDL.h>
//#include <SDL_image.h>
//#include <string>
//#include <map>
//
//class TextureManager {
//public:
//	static TextureManager* Instance() {
//		if (mInstance == 0)
//			mInstance = new TextureManager();
//		return mInstance;
//	}
//
//	~TextureManager();
//	bool load(std::string _fileName, std::string _id, SDL_Renderer* _pRenderer,
//		int _r = 0, int _g = 0, int _b = 0);
//
//	/* draw overloading */
//	void draw(std::string _id, int _x, int _y, int _width, int _height,
//		SDL_Renderer* _pRenderer, SDL_RendererFlip _flip = SDL_FLIP_NONE);
//
//	void draw(std::string _id, int _x, int _y, int _width, int _height,
//		SDL_Renderer* _pRenderer, SDL_Rect* _clip, SDL_RendererFlip _flip = SDL_FLIP_NONE);
//
//	void draw(SDL_Texture* _texture, int _x, int _y, int _width, int _height,
//		SDL_Renderer* _pRenderer, SDL_RendererFlip _flip = SDL_FLIP_NONE);
//
//	void draw(SDL_Texture* _texture, int _x, int _y, int _width, int _height,
//		SDL_Renderer* _pRenderer, SDL_Rect* _clip, SDL_RendererFlip _flip = SDL_FLIP_NONE);
//
//	void setAlpha(SDL_Texture* _texture, int _alpha);
//
//
//
//	SDL_Texture* get(std::string _id) { return mTextureMap[_id]; }
//
//
//private:
//	static TextureManager* mInstance;
//	std::map<std::string, SDL_Texture*> mTextureMap;
//
//	TextureManager() { puts("TextureManager »ý¼º"); }
//};
//
//#endif

#ifndef _TEXTUREMANAGER_H_
#define _TEXTUREMANAGER_H_

#include <SDL_image.h>
#include <string>
#include <map>

class TextureManager {
public:
	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer, int r=0, int g=0, int b=0);
	//bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer, int r, int g, int b);
	void draw(SDL_Texture* texture, int x, int y, int width, int height,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void draw(std::string id, int x, int y, int width, int height,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width, int height,
		int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void clearFromTextureMap(std::string id);
	void setAlpha(std::string _textureID, int _alpha);

	static TextureManager* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new TextureManager();
		}
		return s_pInstance;
	}

private:
	std::map<std::string, SDL_Texture*> m_textureMap;
	static TextureManager* s_pInstance;
	TextureManager() {}
};

typedef TextureManager TheTextureManager;

#endif