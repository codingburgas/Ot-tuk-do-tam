#pragma once
#include "Precompile.hpp"
class Enemy {
protected:
	int enemyPosX, enemyPosY;
	int enemyDistance;
	Texture2D chadFr;
	Texture2D chadFrTwo;
public:
	Enemy();
};