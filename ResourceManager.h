#include <SDL.h>

#ifndef _RESOURCE_MANAGER_H_
#define _RESOURCE_MANAGER_H_

class ResourceManager {
public:
	static ResourceManager* instance() {
		if (mInstance == 0)
			mInstance = new ResourceManager();
		return mInstance;
	}
	bool init() {}
	bool clear() {}

private:
	static ResourceManager* mInstance;
	ResourceManager() {}
};

#endif