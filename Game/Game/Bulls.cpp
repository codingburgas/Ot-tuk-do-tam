#include"Bulls.hpp"
Bulls::Bulls()
{
	//bullsSpritesLeft.resize();
	bullsRectangle.resize(3);
	bullsSprites.resize(3);
	srand(time(0));
	bullsPositions = {
		{2349, 544},
		{2741, 744},
		{2349, 944},
	};
	bullsSpeeds = {
		{rand() % 100 + 50},
		{rand() % 100 + 50},
		{rand() % 100 + 50},
		{rand() % 100 + 50},
		{rand() % 100 + 50},
		{rand() % 100 + 50}
	};

	bullsBool = 0;
	HaveToDraw = 0;
	counterFrame = {0,0,0};
	moveBulls.resize(3);
}
void Bulls::CheckCollisionBulls(Rectangle move, Vector2& plyercords)
{
	for (size_t i = 0; i < moveBulls.size(); i++)
	{
		if (CheckCollisionRecs(move, moveBulls[i])) {

			plyercords.x = GetScreenWidth() / 2 - 200;
			plyercords.y = GetScreenHeight() / 2 - 200;

		}
	}
}
void Bulls::LoadSprites()
{

	black_bull_left = LoadTexture("../src/sprites/inner country elements/spain/bulls sprites/black_bull_left.png");
	black_bull_right = LoadTexture("../src/sprites/inner country elements/spain/bulls sprites/black_bull_right.png");
	brown_bull_left = LoadTexture("../src/sprites/inner country elements/spain/bulls sprites/brown_bull_left.png");
	brown_bull_right = LoadTexture("../src/sprites/inner country elements/spain/bulls sprites/brown_bull_right.png");
	white_bull_left = LoadTexture("../src/sprites/inner country elements/spain/bulls sprites/white_bull_left.png");
	white_bull_right = LoadTexture("../src/sprites/inner country elements/spain/bulls sprites/white_bull_right.png");

	bullsSpritesLeft = {
		 black_bull_left,
		 brown_bull_left,
		 white_bull_left
	};

	bullsSpritesRight = {
		 black_bull_right,
		 brown_bull_right,
		 white_bull_right
	};

	for (int i = 0; i < bullsRectangle.size(); i++)
	{
		bullsSpritesLeft[i].width = 344;
		bullsSpritesRight[i].width = 344;

		bullsSpritesLeft[i].height = 77;
		bullsSpritesRight[i].height = 77;

		bullsRectangle[i] = { (float)bullsSpritesLeft[i].width / 3, 0, (float)bullsSpritesLeft[i].width / 3, (float)bullsSpritesLeft[i].height };
	}
}
void Bulls::IfDisplayed(bool draw) {
	HaveToDraw = draw;
}
void Bulls::Draw(int xbg, int ybg)
{
	if (HaveToDraw)
	{
		for (size_t i = 0; i < bullsSpritesLeft.size(); i++)
		{

			if (counterFrame[i] >= 20)
			{
				bullsRectangle[i].x += bullsSpritesLeft[i].width / 3;
				counterFrame[i] = 0;
			}
			if (abs(bullsRectangle[i].x) > bullsSpritesLeft[i].width)
			{
				bullsRectangle[i].x = bullsSpritesLeft[i].width / 3;
			}
			counterFrame[i]++;

			moveBulls[i] = Rectangle{bullsPositions[i].x + xbg, bullsPositions[i].y + ybg, (float)bullsSpritesLeft[i].width / 3, (float)bullsSpritesLeft[i].height};

			DrawTexturePro(bullsSprites[i], bullsRectangle[i], moveBulls[i], Vector2{10, 10}, 0, WHITE);
		}
	}

}
void Bulls::Update()
{
	for (size_t i = 0; i < bullsSpritesLeft.size(); i++)
	{
		if (bullsPositions[i].x > 2740) {
			bullsSprites[i] = bullsSpritesLeft[i];
			bullsSpeeds[i] = -100;
		}
		else if (bullsPositions[i].x < 2350) {
			bullsSprites[i] = bullsSpritesRight[i];

			bullsSpeeds[i] = 100;
		}
		bullsPositions[i].x += bullsSpeeds[i] * GetFrameTime();
	}
}