#pragma once

#include <vector>
#include "Singleton.h"

class SceneManager : public Singleton<SceneManager>
{
public:
	void init();
	void nextScene();
	void push(Ascene *scene);
	void update(SDL_Event &ev);
private:
	typedef std::vector<AScene*> t_iter;
	t_iter active_;

	std::vector<Ascene*> list_;
	SceneManager(void);
	~SceneManager(void);
};

