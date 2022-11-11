#pragma once
#include "Precompile.hpp"
#include "Background.hpp"
#include "Enemy.hpp"

class Player : public Bg, public Enemy
{
private:
	Texture2D playerSprite;

	Texture2D u;
	Texture2D d;
	Texture2D r;
	Texture2D l;

	Texture2D idleU;
	Texture2D idleD;
	Texture2D idleR;
	Texture2D idleL;
	//add this
	Texture2D dotsBubble;
	float limitFrameDots;
	Rectangle viewDots;
	//to this
	int counterDotsBubble;
	int changeDotsBubble;

	vector<Texture2D> playerSprites;
	vector<Texture2D> idleSprites;

	Rectangle view;
	Rectangle move;
	int counter = 0;
	float lim;
	bool HorizotnalOrVertical[2];
	float speed;
	int animationSpeed;
	int fps;
	enum Dir {
		LEFT,
		RIGHT,
		UP,
		DOWN
	}HeroDir;
	Texture2D exampleItem;
	Vector2 playerCords;
	friend bool findDistance(Player& player, int posX, int posY);
public:
	vector<Vector2> NPCPositions;
	Player();
	void LoadSprites(int fps);
	void Movement();
	void CheckDir();
	void DrawDotsAnimation();
	void UnLoadTextures();
};