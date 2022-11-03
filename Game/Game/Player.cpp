#include "Player.hpp"

void Player::LoadSprites(int fps)
{
	d = LoadTexture("../src/sprites/heroSprite/down.png");
	u = LoadTexture("../src/sprites/heroSprite/up.png");
	l = LoadTexture("../src/sprites/heroSprite/left.png");
	r = LoadTexture("../src/sprites/heroSprite/right.png");
	background = LoadTexture("../src/sprites/backgrounds/bar.png");
	lim = (float)d.width / 4;
	view = { lim, 0, (float)d.width / 4, (float)d.height };
	this->fps = fps;
	PosX = GetScreenWidth() / 2;
	PosY = GetScreenHeight() / 2;
}
void Player::CheckDir()
{
	if ((IsKeyDown(KEY_UP) or IsKeyDown(KEY_W)) && !(PosY <= 20))
	{
		PosY -= speed * GetFrameTime();
		HeroDir = UP;
		HorizotnalOrVertical[1] = 1;
	}
	else if ((IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S)) && !(PosY >= GetScreenHeight() - sprite.height))
	{
		PosY += speed * GetFrameTime();
		HeroDir = DOWN;
		HorizotnalOrVertical[1] = 1;
	}
	else {
		HorizotnalOrVertical[1] = 0;
	}

	if ((IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)) && !(PosX <= 0))
	{
		PosX -= speed * GetFrameTime();
		HeroDir = LEFT;
		HorizotnalOrVertical[0] = 1;
	}
	else if ((IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)) && !(PosX >= GetScreenWidth() - sprite.width /5))
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
		view.height = (float)sprite.height;
		break;

	case RIGHT:
		sprite = r;
		view.height = (float)sprite.height;
		break;

	case UP:
		sprite = u;
		view.height = (float)sprite.height;
		break;

	case DOWN:
		sprite = d;
		view.height = (float)sprite.height;
		break;

	}
	//flames
	if (counter == fps / animationSpeed)
	{
		view.x += lim;
		counter = 0;
	}
	if (abs(view.x) > sprite.width)
	{
		view.x = lim;
	}
	counter++;
	//limits
	if (PosX > 200 && PosX < GetScreenWidth() - 200)
	{
		XBg = -PosX + 200;
	}
	if (PosY > 200 && PosY < GetScreenHeight() - 200)
	{
		YBg = -PosY + 200;
	}

	move = Rectangle{ PosX, PosY, (float)sprite.width / 4, (float)sprite.height };
	DrawTexture(background, XBg, YBg, WHITE);
	DrawTexturePro(sprite, view, move, Vector2{ 10, 10 }, 0, WHITE);

}
void Player::UnLoadTextures()
{
	UnloadTexture(d);
	UnloadTexture(l);
	UnloadTexture(r);
	UnloadTexture(u);
}
