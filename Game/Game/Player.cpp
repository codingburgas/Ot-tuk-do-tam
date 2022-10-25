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
	if (IsKeyDown(KEY_UP) or IsKeyDown(KEY_W))
	{
		HeroDir = UP;
		HorizotnalOrVertical[1] = 1;
	}
	else if (IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S))
	{
		HeroDir = DOWN;
		HorizotnalOrVertical[1] = 1;
	}
	else {
		HorizotnalOrVertical[1] = 0;
	}

	if (IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A))
	{
		HeroDir = LEFT;
		HorizotnalOrVertical[0] = 1;
	}
	else if (IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D))
	{
		HeroDir = RIGHT;
		HorizotnalOrVertical[0] = 1;
	}
	else {
		HorizotnalOrVertical[0] = 0;
		switch (HeroDir)
		{
		case LEFT:
			//left idle
			break;

		case RIGHT:
			// right idle
			break;

		case UP:
			//up idle
			break;

		case DOWN:
			//down idle
			break;

		}
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