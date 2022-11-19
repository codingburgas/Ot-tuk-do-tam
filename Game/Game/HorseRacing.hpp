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
	bool horseRunBool;
	bool HaveToDraw;
	unsigned counterPlace;
	vector<bool>allFinished;
	int counterForFinish = 0;

public:
	Racing();
	void LoadSprites();
	void DrawHorseAnimation();
	void IfHorseRun(bool run, bool HaveToDraw,bool& moveBg);
};