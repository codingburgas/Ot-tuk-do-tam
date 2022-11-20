#include"Assassin.hpp"

Assassin::Assassin()
{
	counterFlip = 0;
	counterFrame = 0;
	speed = 100;
	
	
} 
void Assassin::LoadSprites()
{
	l = LoadTexture("../src/sprites/rivalSprite/left.png");
	r = LoadTexture("../src/sprites/rivalSprite/right.png");
	SpasNPC = r;
	SpasNPCView = { (float)SpasNPC.width / 4, 0, (float)SpasNPC.width / 4, (float)SpasNPC.height };
	position = { 500, 900, (float)SpasNPC.width / 4, (float)SpasNPC.height };

}

//assassin moevement
void Assassin::CheckMiniGame(bool&check, Rectangle heroRec, bool talk)
{
	if (talk)
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
	if (!check){
		DrawTexturePro(SpasNPC, SpasNPCView, position, Vector2{ 10, 10 }, 0, WHITE);
	}
}

void Assassin::Update(Vector2 posHero, int xBg, int yBg, Rectangle heroRec, bool check)
{
	if (!check)
	{
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