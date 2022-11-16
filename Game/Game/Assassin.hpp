#pragma once
#include"Precompile.hpp"
#include"Player.hpp"

class Assassin : public Player{
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
	vector<Texture2D> AssassinSprites;
public:
	Assassin();
	void LoadSprites();
	void Draw(int xBg, int yBg);
	void Update(Vector2 posHero, int xBg, int yBg, Dir dir);
};