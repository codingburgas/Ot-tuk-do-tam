#pragma once
#include "Precompile.hpp"
#include "Background.hpp"
#include "Enemy.hpp"

class Player : public Bg, public Enemy
{
private:
	Texture2D playerSprite;
	Vector2 playerCords;

	Texture2D u;
	Texture2D d;
	Texture2D r;
	Texture2D l;

	vector<Texture2D> playerSprites;

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