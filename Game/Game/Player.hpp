#include "Precompile.hpp"
#pragma once
class Player
{
private:
	Texture2D sprite;

	Texture2D u;
	Texture2D d;
	Texture2D r;
	Texture2D l;

	Rectangle view;
	int counter = 0;
	float lim;
	bool HorizotnalOrVertical[2] = { 0, 0 };
	enum Dir {
		LEFT,
		RIGHT,
		UP,
		DOWN
	} HeroDir = LEFT;

public:
	Player();
	void Engine();
	void CheckDir();
	~Player();
};

