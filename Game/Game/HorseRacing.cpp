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
	};
	for (size_t i = 0; i < horseSpeeds.size(); i++)
	{
		sort.insert(horseSpeeds[i]);
	}
	horseRunBool = 0;
	HaveToDraw = 0;
	counterPlace = 0;
	allFinished = {0,0,0,0};
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
void Racing::DrawHorseAnimation()
{
	if (horseRunBool && HaveToDraw)
	{
		
		for (int i = 0; i < horseRun.size(); i++)
		{
			if (horsePositions[i].x < 1500)
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
						//cout << counterForFinish << endl;
					}
				}
				if (counterForFinish == allFinished.size())
				{
					DrawRectangle(500, 500, 500, 500, RED);
					for (auto rank : sort)
					{
						counterPlace++;
						DrawText(("Horse with speed " + to_string(rank)).c_str(), 500, 480 + (20 * counterPlace), 20, BLACK);
						DrawText(("is " + to_string(counterPlace) + "th").c_str(), 800, 480 + (20 * counterPlace), 20, BLACK);
					}
					counterPlace = 0;
				}
				counterForFinish = 0;
			}
		}

		for (int i = 0; i < horseRun.size(); i++)
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
		for (int i = 0; i < horseRun.size(); i++)
		{

			DrawTextureRec(horseRun[i], horseRectangleRun[i], Vector2{ horsePositions[i].x, horsePositions[i].y }, WHITE);
		}
	}
	else if(HaveToDraw) {

		for (int i = 0; i < horseRun.size(); i++)
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
		for (int i = 0; i < horseRun.size(); i++)
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