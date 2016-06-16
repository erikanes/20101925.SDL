#ifndef _AUDIO_MANAGER_H_
#define _AUDIO_MANAGER_H_

#include <SDL_mixer.h>
#include <string>
#include <map>

class AudioManager {
public:
	static AudioManager* Instance() {
				if (mInstance == 0)
					mInstance = new AudioManager();
				return mInstance;
			}
	~AudioManager();

	bool init();
	bool openAudio(std::string _filename);
	void playBGM();
	void playEffect();

private:
	AudioManager() {}
	static AudioManager* mInstance;
	Mix_Music*	mAudio;
	Mix_Chunk*	mEffect;
};

#endif