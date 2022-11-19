#include"Bulls.hpp"
Bulls::Bulls() 
{
	//bullsSpritesLeft.resize();
	bullsRectangle.resize(3);
	bullsSprites.resize(3);
	srand(time(0));
	bullsPositions = {
		{449, 344},
		{801, 444},
		{449, 544},
	};

	bullsSpeeds = {
		{rand() % 100 + 50},
		{rand() % 100 + 50},
		{rand() % 100 + 50},
	};

	bullsBool = 0;
	HaveToDraw = 0;
	counterFrame = {0,0,0};
}

void Bulls::LoadSprites()
{

	black_bull_left = LoadTexture("../src/sprites/inner country elements/spain/bulls sprites/blacê_bull_left.png");
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
		bullsSpritesLeft[i].width = 144;
		bullsSpritesRight[i].width = 144;
		
		bullsSpritesLeft[i].height = 47;
		bullsSpritesRight[i].height = 47;

		bullsRectangle[i] = { (float)bullsSpritesLeft[i].width / 3, 0, (float)bullsSpritesLeft[i].width / 3, (float)bullsSpritesLeft[i].height };
	}
}
void Bulls::Draw()
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
		
		DrawTextureRec(bullsSprites[i], bullsRectangle[i], bullsPositions[i], WHITE);
		
		//DrawTexture(bullsSpritesLeft[3], 1000, 500, WHITE);
	}
}
void Bulls::Update()
{
	for (size_t i = 0; i < bullsSpritesLeft.size(); i++)
	{
		if (bullsPositions[i].x > 800) {
			bullsSprites[i] = bullsSpritesLeft[i];
			bullsSpeeds[i] = -100;
		}
		else if (bullsPositions[i].x < 450) {
			bullsSprites[i] = bullsSpritesRight[i];
			
			bullsSpeeds[i] = 100;
		}
		bullsPositions[i].x += bullsSpeeds[i] * GetFrameTime();
	}
}