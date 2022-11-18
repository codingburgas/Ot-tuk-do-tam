#include"Assassin.hpp"

Assassin::Assassin()
{
	counterFlip = 0;
	counterFrame = 0;
	speed = 100;
	isSeen = 0;
	walls = {
		{0,500,500,35},//left
		{720,500,450,35},//right
		{1160,500,35,1000}//right nepitkings 
	};
	
	
} 
void Assassin::LoadSprites()
{
	l = LoadTexture("../src/sprites/rivalSprite/left.png");
	r = LoadTexture("../src/sprites/rivalSprite/right.png");
	
	itemForShowingTheMinigame = LoadTexture("../src/sprites/inner country elements/germany/poison.png");
	
	SpasNPC = r;
	SpasNPCView = { (float)SpasNPC.width / 4, 0, (float)SpasNPC.width / 4, (float)SpasNPC.height };
	position = { 500, 900, (float)SpasNPC.width / 4, (float)SpasNPC.height };

	itemForShowingTheMinigame.width = 50;
	itemForShowingTheMinigame.height = 100;

}
void Assassin::CheckMiniGame(bool&check, Rectangle heroRec)
{
	if (CheckCollisionRecs(heroRec, itemRec) && IsKeyPressed(KEY_Q))
	{
		cout << "konq cukna Q" << endl;
		check = 0;
	}
}
void Assassin::Draw(int xBg, int yBg, bool check)
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
	itemRec = { (float)1000 + xBg, (float)500 + yBg, 50, 100 };
	if (check){
		DrawRectangleRec(itemRec, PURPLE); 
		DrawTexture(itemForShowingTheMinigame, 1000 + xBg, 500 + yBg, WHITE);
	}
	else {
		DrawTexture(TableDrink,0,0,WHITE);
		DrawTexturePro(SpasNPC, SpasNPCView, position, Vector2{ 10, 10 }, 0, WHITE);
	}
	for (int i = 0; i < walls.size(); i++)
	{
		DrawRectangleRec(walls.at(i), BLACK);
	}
}

void Assassin::Update(Vector2 posHero, int xBg, int yBg, Rectangle heroRec, bool check)
{
	if (!check)
	{


		if (CheckCollisionCircleRec(posHero, 100, position) && !isSeen) {
			isSeen = 1;
			cout << "IsSeen" << endl;
		}

		if (isSeen)
		{
			(position.x > posHero.x) ? SpasNPC = l : SpasNPC = r;

			if (CheckCollisionRecs(position, heroRec))
			{
				cout << "exit the game" << endl;
			}
			else {
				isSeen = 1;
			}
			float rotation = atan2(posHero.y - position.y, posHero.x - position.x);
			position.x += cos(rotation) * 100 * GetFrameTime();
			position.y += sin(rotation) * 100 * GetFrameTime();
		}
		else
		{
			isSeen = 0;
			if (position.x > 800) {
				if (counterFlip > 60) {
					SpasNPC = l;
					speed = -100;
				}
				else {
					speed *= 0;
				}
				counterFlip++;
			}
			else if (position.x < 450) {
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


}