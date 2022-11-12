#include"HorseRacing.hpp"
Racing::Racing()
{
	counterHorse = { 0,0,0,0,0,0 };
	horseTextures.resize(6);
	horseRectangle.resize(6);
	hourseFrameLimits.resize(6);
	horsePositions = {
		{144, 344},
		{144, 444},
		{144, 544},
		{144, 644},
		{144, 744},
		{144, 844}
	};//kon poziciq
}
void Racing::LoadSprites()
{
	horseRacingBackground = LoadTexture("../src/sprites/backgrounds/field.png");

	for (int i = 0; i < horseTextures.size(); i++)
	{
		horseTextures[i] = LoadTexture("../src/sprites/inner country elements/france/horseIdle.png");
	}

	for (int i = 0; i < horseRectangle.size(); i++)
	{
		hourseFrameLimits[i] = (float)horseTextures[i].width / 3;
		horseRectangle[i] = { (float)hourseFrameLimits[i], 0, (float)horseTextures[i].width / 3, (float)horseTextures[i].height };
	}
}
void Racing::DrawHorseAnimation()
{

	for (int i = 0; i < horseRectangle.size(); i++)
	{
		if (counterHorse[i] >= 15)
		{

			horseRectangle[i].x += hourseFrameLimits[i];
			counterHorse[i] = 0;
		}
		if (abs(horseRectangle[i].x) > horseTextures[i].width)
		{
			horseRectangle[i].x = hourseFrameLimits[i];
		}
		counterHorse[i]++;
	}
	for (int i = 0; i < horseRectangle.size(); i++)
	{

		DrawTextureRec(horseTextures[i], horseRectangle[i], Vector2{ horsePositions[i].x, horsePositions[i].y }, WHITE);
	}

}