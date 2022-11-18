#pragma once
#include "Precompile.hpp"
class Enemy {
protected:
	Texture2D chadFr;
public:
	int enemyPosX, enemyPosY;
	int enemyDistance;
	Enemy();
};