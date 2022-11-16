#include"Assassin.hpp"

Assassin::Assassin()
{
	counterFlip = 0;
	counterFrame = 0;
	speed = 100;
	position.x = 1000;
	position.y = 1000;
	isSeen = 0;
}
void Assassin::LoadSprites()
{
	l = LoadTexture("../src/sprites/heroSprite/left.png");
	r = LoadTexture("../src/sprites/heroSprite/right.png");
	TableDrink = LoadTexture("../src/sprites/inner country elements/TableDrink.png");
	SpasNPC = r;
	SpasNPCView = { (float)SpasNPC.width / 4, 0, (float)SpasNPC.width / 4, (float)SpasNPC.height };
}
void Assassin::Draw(int xBg, int yBg)
{
	if (counterFrame >= 20)
	{
		SpasNPCView.x += SpasNPC.width / 4;
		counterFrame = 0;
	}
	if (abs(SpasNPCView.x) > SpasNPC.width)
	{
		SpasNPCView.x = SpasNPC.width / 4;
	}
	counterFrame++;

	if (isSeen)
	{
		DrawTextureRec(SpasNPC, SpasNPCView, Vector2{ position.x, position.y}, WHITE);
	}
	else {
		DrawTextureRec(SpasNPC, SpasNPCView, Vector2{ position.x + xBg, position.y + yBg }, WHITE);
	}


}
void Assassin::Update(Vector2 posHero, int xBg, int yBg)
{
	if (speed < 0 && !isSeen){
		position = { position.x + xBg, position.y + yBg };
		isSeen = 1;
	}

	if (isSeen)
	{
		isSeen = 1;
		cout << "kude we" << endl;
		float rotation = atan2(posHero.y - position.y, posHero.x - position.x);
		position.x += cos(rotation) * 100 * GetFrameTime();
		position.y += sin(rotation) * 100 * GetFrameTime();
		cout << position.y << " " << position.x << endl;
	}
	else
	{
		isSeen = 0;
		if (position.x > 2000) {
			if (counterFlip > 60) {
				SpasNPC = l;
				speed = -100;
			}
			else {
				speed *= 0;
			}
			counterFlip++;
		}
		else if (position.x < 1000) {
			if (counterFlip > 60) {
				SpasNPC = r;
				speed = 100;
			}
			else {
				speed *= 0;
			}
			counterFlip++;
		}
		position.x += speed * GetFrameTime();

	}


}