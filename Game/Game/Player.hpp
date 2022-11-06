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

	Texture2D dotsBubbleOne, dotsBubbleTwo, dotsBubblThree, dotsBubbleFour;
	vector<Texture2D> dotsBubble;
	int counterDotsBubble;
	int changeDotsBubble;

	vector<Texture2D> playerSprites;

	Rectangle view;
	Rectangle move;
	int counter = 0;
	float lim;
	bool HorizotnalOrVertical[2];
	float speed;
	int animationSpeed;
	int fps;
	float PosX, PosY;
	enum Dir {
		LEFT,
		RIGHT,
		UP,
		DOWN
	}HeroDir;

public:
	Player();
	void LoadSprites(int fps);
	void Movement();
	void CheckDir();
	void DrawDotsAnimation(int dotsBubbleX, int dotsBubbleY);
	void UnLoadTextures();
};