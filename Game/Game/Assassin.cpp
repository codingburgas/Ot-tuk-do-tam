#include"Assassin.hpp"

Assassin::Assassin()
{
	posX = 500;
	posY = 250;
	counterFlip = 0;
}
void Assassin::LoadSprites()
{
	l = LoadTexture("../src/sprites/heroSprite/left.png");
	r = LoadTexture("../src/sprites/heroSprite/right.png");
	TableDrink = LoadTexture("../src/sprites/inner country elements/TableDrink.png");
}
void Assassin::Draw()
{
	if (counterFlip > rand() % 20)
	{
		DrawTexture(r, posX, posY, WHITE);
		posX++;
	}
	else
	{
		DrawTexture(l, posX, posY, WHITE);
		posX--;
	}
}