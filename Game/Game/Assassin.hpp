#pragma once
#include"Precompile.hpp"

class Assassin{
private:
	Texture2D r;
	Texture2D l;
	Texture2D u;
	Texture2D d;
	Texture2D SpasNPC;
	Rectangle SpasNPCView;
	Texture2D TableDrink;
	int counterFlip;
	int counterFrame;
	Vector2 position;
	int speed;
	bool isSeen;
public:
	Assassin();
	void LoadSprites();
	void Draw(int xBg, int yBg);
	void Update(Vector2 posHero, int xBg, int yBg);
};