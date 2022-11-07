#pragma once
#include "Precompile.hpp"
class Enemy {
protected:
	Texture2D chadFr;
	Texture2D chadFrTwo;
	int enemyPosX, enemyPosY;
	int enemyDistance;
public:
	Enemy();
};