#include "AudioManager.h"

AudioManager* AudioManager::mInstance = 0;

AudioManager::~AudioManager() {
	if (mAudio != NULL) {
		Mix_PauseMusic();
		Mix_FreeMusic(mAudio);
		mAudio = NULL;
	}
	if (mEffect != NULL) {
		Mix_FreeChunk(mEffect);
		mEffect = NULL;
	}
	puts("AudioManager 삭제");
}

bool AudioManager::init() {
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		return false;

	mAudio = NULL;
	mEffect = NULL;
	mEffect = Mix_LoadWAV("Resources/effect.wav");

	puts("AudioManager 생성");
	return true;
}

bool AudioManager::openAudio(std::string _filename) {
	mAudio = Mix_LoadMUS(_filename.c_str());

	if (mAudio == NULL)
		return false;

	return true;
}

void AudioManager::playBGM() {
	Mix_PlayingMusic();
	Mix_PlayMusic(mAudio, -1);
}

void AudioManager::playEffect() {
	Mix_PlayChannel(-1, mEffect, 0);
}