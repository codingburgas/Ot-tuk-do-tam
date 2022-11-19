#pragma once
#include"Precompile.hpp"

class Racing {
private:
	Texture2D horseRacingBackground;

	vector<Texture2D> horseIdle;
	vector<Texture2D> horseRun;
	vector<Rectangle> horseRectangleIdle;
	vector<Rectangle> horseRectangleRun;

	vector<Vector2> horsePositions;

	vector<int> horseSpeeds;
	set<int> sort;
	vector<int>counterHorse;

	vector<bool>allFinished;
	bool horseRunBool;
	bool HaveToDraw;

	unsigned counterPlace;
	int counterForFinish = 0;

public:
	int firstSpeed;
	int firstHorseIndex;

	Racing();
	void LoadSprites();
	void DrawHorseAnimation(int xbg, int ybg);
	void IfHorseRun(bool run, bool HaveToDraw);
};