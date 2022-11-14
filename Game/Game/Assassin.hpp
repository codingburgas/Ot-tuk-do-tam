#pragma once
#include"Precompile.hpp"

class Assassin {
	private:
		Texture2D r;
		Texture2D l;
		Texture2D SpasNPC;
		Texture2D TableDrink;
		int counterFlip;
		int posX, posY;
	public:
		Assassin();
		void LoadSprites();
		void Draw();
};