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
	Texture2D itemForShowingTheMinigame;
	int counterFlip;
	int counterFrame;
	Rectangle position;
	int speed;
	bool isSeen;
	Rectangle itemRec;
public:
	vector<Rectangle> walls;
	Assassin();
	void LoadSprites();
	void Draw(int xBg, int yBg, bool check);
	void CheckMiniGame(bool&check, Rectangle heroRec);
	void Update(Vector2 posHero, int xBg, int yBg, Rectangle heroRec);
};