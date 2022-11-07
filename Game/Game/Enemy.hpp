#pragma once
#include "Precompile.hpp"
class Enemy {
protected:
	Texture2D chadFr;
	Texture2D chadFrTwo;
public:
	int enemyPosX, enemyPosY;
	int enemyDistance;
	Enemy();
};