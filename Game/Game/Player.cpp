#include "Precompile.hpp"
#include "Player.hpp"

Player::Player()
{

	d = LoadTexture("../src/down.png");
	u = LoadTexture("../src/up.png");
	l = LoadTexture("../src/left.png");
	r = LoadTexture("../src/right.png");
	lim = (float)d.width / 4;
	view = { lim, 0, (float)d.width / 4, (float)d.height };
}

void Player::CheckDir()
{
	if (IsKeyPressed(KEY_UP) or IsKeyPressed(KEY_W))
	{
		HeroDir = UP;
	}
	else if (IsKeyPressed(KEY_LEFT) or IsKeyPressed(KEY_D))
	{
		HeroDir = LEFT;
	}
	else if (IsKeyPressed(KEY_DOWN) or IsKeyPressed(KEY_S))
	{
		HeroDir = DOWN;
	}
	else if (IsKeyPressed(KEY_RIGHT) or IsKeyPressed(KEY_A))
	{
		HeroDir = RIGHT;
	}
}
void Player::Engine()
{
	switch (HeroDir)
	{
	case LEFT:
		sprite = l;
		lim *= 1;
		view.height = (float)sprite.height;
		break;

	case RIGHT:
		sprite = r;
		lim *= -1;
		view.height = (float)sprite.height;
		break;

	case UP:
		sprite = u;
		lim *= 1;
		view.height = (float)sprite.height;
		break;

	case DOWN:
		sprite = d;
		lim *= 1;
		view.height = (float)sprite.height;
		break;

	}
	if (counter == 10)
	{
		view.x += lim;
		counter = 0;
	}
	if (abs(view.x) > sprite.width)
	{
		view.x = lim;
	}
	counter++;
	DrawTexturePro(sprite, view, { (float)GetScreenWidth() / 2,(float)GetScreenHeight() / 2, (float)sprite.width / 4, (float)sprite.height }, Vector2{ (float)sprite.width / 2, (float)sprite.height / 2 }, 0, WHITE);
}
Player::~Player()
{
	UnloadTexture(d);
	UnloadTexture(l);
	UnloadTexture(r);
	UnloadTexture(u);
}

