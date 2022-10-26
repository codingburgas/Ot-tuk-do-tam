#include "Precompile.hpp"
#include "Player.hpp"

void Player::LoadSprites()
{
	d = LoadTexture("../src/sprites/heroSprite/down.png");
	u = LoadTexture("../src/sprites/heroSprite/up.png");
	l = LoadTexture("../src/sprites/heroSprite/left.png");
	r = LoadTexture("../src/sprites/heroSprite/right.png");
	lim = (float)d.width / 4;
	view = { lim, 0, (float)d.width / 4, (float)d.height };
	PosX = GetScreenWidth() / 2;
	PosY = GetScreenHeight() / 2;
}
void Player::CheckDir()
{
	if (IsKeyDown(KEY_UP) or IsKeyDown(KEY_W))
	{
		PosY -= speed * GetFrameTime();
		HeroDir = UP;
		HorizotnalOrVertical[1] = 1;
	}
	else if (IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S))
	{
		PosY += speed * GetFrameTime();
		HeroDir = DOWN;
		HorizotnalOrVertical[1] = 1;
	}
	else {
		HorizotnalOrVertical[1] = 0;
	}

	if (IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A))
	{
		PosX -= speed * GetFrameTime();
		HeroDir = LEFT;
		HorizotnalOrVertical[0] = 1;
	}
	else if (IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D))
	{
		PosX += speed * GetFrameTime();
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
void Player::Movement()
{
	if (HorizotnalOrVertical[0] && HorizotnalOrVertical[1]) speed = 90;
	else speed = 150;

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


	move = Rectangle{ PosX, PosY, (float)sprite.width / 4, (float)sprite.height };
	//cout << move.x <<  " " << move.y << endl;
	DrawTexturePro(sprite, view, move, Vector2{ (float)sprite.width / 2, (float)sprite.height / 2 }, 0, WHITE);

}
void Player::UnLoadTextures()
{
	UnloadTexture(d);
	UnloadTexture(l);
	UnloadTexture(r);
	UnloadTexture(u);
}
