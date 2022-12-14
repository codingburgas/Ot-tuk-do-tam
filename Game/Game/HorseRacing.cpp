#include"HorseRacing.hpp"
Racing::Racing()
{
	srand(time(0));
	counterHorse = { 0,0,0,0};
	horseIdle.resize(4);
	horseRun.resize(4);
	horseRectangleIdle.resize(4);
	horseRectangleRun.resize(4);

	horsePositions = {
		{144, 1144},
		{144, 1244},
		{144, 1344},
		{144, 1444}
	};

	horseSpeeds = {
		{rand() % 50 + 200},
		{rand() % 50 + 200},
		{rand() % 50 + 200},
		{rand() % 50 + 200}
	};
	for (size_t i = 0; i < horseSpeeds.size(); i++)
	{
		sort.insert(horseSpeeds[i]);
	}
	horseRunBool = 0;
	HaveToDraw = 0;
	counterPlace = 0;
	allFinished = {0,0,0,0};
	firstSpeed = 0;
	counterIndex = 0;
	HorseIndex = { 0,0,0,0 };
}
void Racing::LoadSprites()
{
	horseRacingBackground = LoadTexture("../src/sprites/backgrounds/field.png");

	for (int i = 0; i < horseRun.size(); i++)
	{
		horseIdle[i] = LoadTexture("../src/sprites/inner country elements/france/horseIdle.png");
		horseRun[i] = LoadTexture("../src/sprites/inner country elements/france/horse.png");
	}

	for (int i = 0; i < horseRun.size(); i++)
	{

		horseRectangleIdle[i] = { (float)horseIdle[i].width / 3, 0, (float)horseIdle[i].width / 3, (float)horseIdle[i].height };
		horseRectangleRun[i] = { (float)horseRun[i].width / 6, 0, (float)horseRun[i].width / 6, (float)horseRun[i].height };
	}
}
void Racing::DrawHorseAnimation(int xbg, int ybg)
{
	if (horseRunBool && HaveToDraw)
	{
		
		for (int i = 0; i < horseRun.size(); i++)
		{
			if (horsePositions[i].x < 2690)
			{
				allFinished[0] = 0;
				horsePositions[i].x += horseSpeeds[i] * GetFrameTime();
			}
			else
			{
				allFinished[i] = 1;
				for (size_t j = 0; j < allFinished.size(); j++)
				{
					if (allFinished[j])
					{
						counterForFinish++;
						
					}
				}
				if (counterForFinish == allFinished.size())
				{
					//finish horse
					for (auto rank : sort)
					{
						
						firstSpeed = rank;
						for (size_t j = 0; j < horseSpeeds.size(); j++)
						{
							if (firstSpeed == horseSpeeds[j] && counterIndex < 4) {
								HorseIndex[counterIndex] = j + 1;
								counterIndex++;
								break;
							}
						}
						
					}
					counterPlace = 0;
				}
				counterForFinish = 0;
			}
		}
		//frames to horse
		for (int i = 0; i < horseRun.size(); i++)
		{
			if (counterHorse[i] >= 6)
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
		for (int i = 0; i < horseRun.size(); i++)
		{

			DrawTextureRec(horseRun[i], horseRectangleRun[i], Vector2{ horsePositions[i].x + xbg, horsePositions[i].y + ybg}, WHITE);
		}
	}
	else if(HaveToDraw) {

		for (int i = 0; i < horseRun.size(); i++)
		{
			if (counterHorse[i] >= 13)
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
		for (int i = 0; i < horseRun.size(); i++)
		{

			DrawTextureRec(horseIdle[i], horseRectangleIdle[i], Vector2{ horsePositions[i].x + xbg, horsePositions[i].y + ybg }, WHITE);
		}
	}

}
void Racing::IfHorseRun(bool run, bool Draw)
{

	horseRunBool = run;
	HaveToDraw = Draw;

}