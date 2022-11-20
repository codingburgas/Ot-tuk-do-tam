#pragma once
#include"Precompile.hpp"
class Bulls {
private:
	vector<Texture2D> bullsSpritesLeft;
	vector<Texture2D> bullsSpritesRight;
	vector<Texture2D> bullsSprites;
	vector<Rectangle> bullsRectangle;
	Texture2D black_bull_left;
	Texture2D black_bull_right;
	Texture2D brown_bull_left;
	Texture2D brown_bull_right;
	Texture2D white_bull_left;
	Texture2D white_bull_right;
	vector<Vector2> bullsPositions;
	vector<int> bullsSpeeds;
	vector<int>counterFrame;
	bool bullsBool;
	bool HaveToDraw;
public:
	vector<Rectangle> moveBulls;
	Bulls();
	void LoadSprites();
	void Draw(int xbg, int ybg);
	void Update();
	void IfDisplayed(bool draw);
	void CheckCollisionBulls(Rectangle move, Vector2&playrechords);

};