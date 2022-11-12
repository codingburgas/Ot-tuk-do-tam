#pragma once
#include"Precompile.hpp"

class Racing {
private:
	Texture2D horseRacingBackground;
	vector<Texture2D> horseTextures;
	vector<Rectangle> horseRectangle;
	vector<Vector2> horsePositions;
	vector<int> hourseFrameLimits;
	vector<int>counterHorse;

public:
	Racing();
	void LoadSprites();
	void DrawHorseAnimation();
};