#include"HorseRacing.hpp"
Racing::Racing()
{
	srand(time(0));
	counterHorse = { 0,0,0,0,0,0 };
	horseIdle.resize(6);
	horseRun.resize(6);
	horseRectangleIdle.resize(6);
	horseRectangleRun.resize(6);
	horsePositions = {
		{144, 344},
		{144, 444},
		{144, 544},
		{144, 644},
		{144, 744},
		{144, 844}
	};//kon poziciq
	horseSpeeds = {
		{rand() % 100 + 50},
		{rand() % 100 + 50},
		{rand() % 100 + 50},
		{rand() % 100 + 50},
		{rand() % 100 + 50},
		{rand() % 100 + 50},
	};
	horseRunBool = 0;
	HaveToDraw = 0;
}
void Racing::LoadSprites()
{
	horseRacingBackground = LoadTexture("../src/sprites/backgrounds/field.png");

	for (int i = 0; i < 6; i++)
	{
		horseIdle[i] = LoadTexture("../src/sprites/inner country elements/france/horseIdle.png");
		horseRun[i] = LoadTexture("../src/sprites/inner country elements/france/horse.png");
	}

	for (int i = 0; i < 6; i++)
	{

		horseRectangleIdle[i] = { (float)horseIdle[i].width / 3, 0, (float)horseIdle[i].width / 3, (float)horseIdle[i].height };
		horseRectangleRun[i] = { (float)horseRun[i].width / 6, 0, (float)horseRun[i].width / 6, (float)horseRun[i].height };
	}
}
void Racing::DrawHorseAnimation()
{
	if (horseRunBool && HaveToDraw)
	{
		for (int i = 0; i < 6; i++)
		{
			horsePositions[i].x += horseSpeeds[i] * GetFrameTime();
		}

		for (int i = 0; i < 6; i++)
		{
			if (counterHorse[i] >= 15)
			{

				horseRectangleRun[i].x += horseRun[i].width / 6;
				counterHorse[i] = 0;
			}
			if (abs(horseRectangleRun[i].x) > horseRun[i].width)
			{
				horseRectangleRun[i].x = horseRun[i].width / 6;
			}
			counterHorse[i]++;
		}
		for (int i = 0; i < 6; i++)
		{

			DrawTextureRec(horseRun[i], horseRectangleRun[i], Vector2{ horsePositions[i].x, horsePositions[i].y }, WHITE);
		}
	}
	else if(HaveToDraw) {

		for (int i = 0; i < 6; i++)
		{
			if (counterHorse[i] >= 15)
			{

				horseRectangleIdle[i].x += horseIdle[i].width / 3;
				counterHorse[i] = 0;
			}
			if (abs(horseRectangleIdle[i].x) > horseIdle[i].width)
			{
				horseRectangleIdle[i].x = horseIdle[i].width / 3;
			}
			counterHorse[i]++;
		}
		for (int i = 0; i < 6; i++)
		{

			DrawTextureRec(horseIdle[i], horseRectangleIdle[i], Vector2{ horsePositions[i].x, horsePositions[i].y }, WHITE);
		}
	}

}
void Racing::IfHorseRun(bool run, bool Draw, bool&moveBg)
{

	horseRunBool = run;
	HaveToDraw = Draw;
	moveBg = !Draw;

}