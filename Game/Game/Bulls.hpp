#pragma once
#include"Precompile.hpp"
class Bulls {
	private:
		vector<Texture2D> bullsSprites;
		vector<Rectangle> bullsRectangle;

		vector<Vector2> bullsPositions;
		vector<int> bullsSpeeds;

		bool bullsBool;
		bool HaveToDraw;
	public:
		Bulls();
		void LoadSprites();
		void Draw();

};