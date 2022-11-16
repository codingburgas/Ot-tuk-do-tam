#pragma once
#include "Precompile.hpp"
#include "Background.hpp"
#include "NPC.hpp"

class Player : public Bg, public NPC
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
	Texture2D exampleItem;
	friend bool findDistance(Player& player, int posX, int posY);
	enum Dir {
		LEFT,
		RIGHT,
		UP,
		DOWN
	}HeroDir;
public:
	Vector2 playerCords;
	
	Player();
	void LoadSprites(int fps);
	void Movement();                                                                                                                                                                                                                                                                                 
	void CheckDir();
	void UnLoadTextures();
};