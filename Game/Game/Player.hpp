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

