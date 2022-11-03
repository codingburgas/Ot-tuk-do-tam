#include "Precompile.hpp"
#include "Background.hpp"
#pragma once
class Player : public Bg
{
private:
	Texture2D sprite;

	Texture2D u;
	Texture2D d;
	Texture2D r;
	Texture2D l;
	

	Rectangle view;
	Rectangle move;
	int counter = 0;
	float lim;
	bool HorizotnalOrVertical[2] = { 0, 0 };
	float speed = 100;
	int animationSpeed = 6;
	int fps;
	float PosX, PosY;
	enum Dir {
		LEFT,
		RIGHT,
		UP,
		DOWN
	} HeroDir = LEFT;

public:
	void LoadSprites(int fps);
	void Movement();
	void CheckDir();
	void UnLoadTextures();
};