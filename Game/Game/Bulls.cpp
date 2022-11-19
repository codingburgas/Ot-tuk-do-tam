#include"Bulls.hpp"
Bulls::Bulls() 
{
	bullsSprites.resize(6);
	bullsRectangle.resize(6);

	bullsPositions = {
		{144, 344},
		{144, 444},
		{144, 544},
		{144, 644},
		{144, 744},
		{144, 844}
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
	counterFrame = {0,0,0,0,0,0};
}

void Bulls::LoadSprites()
{
	bullsSprites[0] = LoadTexture("../src/sprites/inner country elements/spain/bulls sprites/black_bull_left.png");
	bullsSprites[1] = LoadTexture("../src/sprites/inner country elements/spain/bulls sprites/black_bull_right.png");
	bullsSprites[2] = LoadTexture("../src/sprites/inner country elements/spain/bulls sprites/brown_bull_left.png");
	bullsSprites[3] = LoadTexture("../src/sprites/inner country elements/spain/bulls sprites/brown_bull_right.png");
	bullsSprites[4] = LoadTexture("../src/sprites/inner country elements/spain/bulls sprites/white_bull_left.png");
	bullsSprites[5] = LoadTexture("../src/sprites/inner country elements/spain/bulls sprites/white_bull_right.png");

	for (int i = 0; i < 6; i++)
	{
		bullsRectangle[i] = { (float)bullsSprites[i].width / 3, 0, (float)bullsSprites[i].width / 3, (float)bullsSprites[i].height };
	}
}
void Bulls::Draw()
{
	for (size_t i = 0; i < bullsSprites.size(); i++)
	{

		if (counterFrame[i] >= 20)
		{
			bullsRectangle[i].x += bullsSprites[i].width / 3;
			counterFrame[i] = 0;
		}
		if (abs(bullsRectangle[i].x) > bullsSprites[i].width)
		{
			bullsRectangle[i].x = bullsSprites[i].width / 3;
		}
		counterFrame[i]++;
		DrawTextureRec(bullsSprites[i], bullsRectangle[i], bullsPositions[i], WHITE);
		
	}
}
void Bulls::Update()
{
	for (size_t i = 0; i < bullsPositions.size(); i++)
	{
		if (bullsPositions[i].x > 800) {
			if (i % 2 != 0){
			bullsSprites[i] = bullsSprites[i - 1];
			}
			bullsSpeeds[i] = -100;
		}
		else if (bullsPositions[i].x < 450) {
		
			if (i % 2 ==0) {
				bullsSprites[i] = bullsSprites[i + 1];
			}
			bullsSpeeds[i] = 100;
		}
		bullsPositions[i].x += bullsSpeeds[i] * GetFrameTime();
	}
}