#pragma once
#include "Precompile.hpp"
#include "Background.hpp"
#include "NPC.hpp"
#include "Assassin.hpp"

class Player : public Bg, public NPC, public Assassin
{
private:
	

	Texture2D u;
	Texture2D d;
	Texture2D r;
	Texture2D l;

	Texture2D idleU;
	Texture2D idleD;
	Texture2D idleR;
	Texture2D idleL;
	Texture2D TableDrink;


	vector<Texture2D> playerSprites;
	vector<Texture2D> idleSprites;

	
	int counter = 0;
	float lim;
	bool HorizotnalOrVertical[2];
	Vector2 speed;
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
	bool renameMe;
public:
	bool MoveBg;
	Vector2 playerCords;
	Rectangle move; 
	Texture2D playerSprite;
	Rectangle view;

	Player();
	void LoadSprites(int fps);
	void Movement();                                                                                                                                                                                                                                                                                 
	void CheckDir();
	void CheckWalls();
	void UnLoadTextures();
};