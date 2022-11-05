#include "Player.hpp"

void Player::LoadSprites(int fps)
{
	d = LoadTexture("../src/sprites/heroSprite/down.png");
	u = LoadTexture("../src/sprites/heroSprite/up.png");
	l = LoadTexture("../src/sprites/heroSprite/left.png");
	r = LoadTexture("../src/sprites/heroSprite/right.png");
	background = LoadTexture("../src/sprites/inner country elements/france/frBackground.png");
	chadFr = LoadTexture("../src/sprites/inner country elements/france/frChad1.png");
	chadFrTwo = LoadTexture("../src/sprites/inner country elements/france/frChad2.png");

	playerSprites.push_back(l);
	playerSprites.push_back(r);
	playerSprites.push_back(u);
	playerSprites.push_back(d);

	lim = (float)d.width / 4;
	view = { lim, 0, (float)d.width / 4, (float)d.height };
	this->fps = fps;

	playerCords.x = GetScreenWidth() / 2;
	playerCords.y = GetScreenHeight() / 2;

	PosX = GetScreenWidth() / 2;
	PosY = GetScreenHeight() / 2;
}

void Player::CheckDir()
{
	if ((IsKeyDown(KEY_UP) or IsKeyDown(KEY_W)) && !(PosY <= 20))
	{
		PosY -= speed * GetFrameTime();
		playerCords.y -= speed * GetFrameTime();

		HeroDir = UP;
		HorizotnalOrVertical[1] = 1;
		
	}
	else if ((IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S)) && !(PosY >= GetScreenHeight() - playerSprite.height))
	{
		PosY += speed * GetFrameTime();
		playerCords.y += speed * GetFrameTime();

		HeroDir = DOWN;
		HorizotnalOrVertical[1] = 1;
	}
	else {
		HorizotnalOrVertical[1] = 0;
	}

	if ((IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)) && !(PosX <= 0))
	{
		PosX -= speed * GetFrameTime();
		playerCords.x -= speed * GetFrameTime();

		HeroDir = LEFT;
		HorizotnalOrVertical[0] = 1;
	}
	else if ((IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)) && !(PosX >= GetScreenWidth() - playerSprite.width /5))
	{
		PosX += speed * GetFrameTime();
		playerCords.x += speed * GetFrameTime();

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
	if (HorizotnalOrVertical[0] && HorizotnalOrVertical[1]) 
		speed = 90;
	else 
		speed = 150;

	
	playerSprite = playerSprites.at(int(HeroDir));
	view.height = (float)playerSprite.height;

	//flames
	if (counter == fps / animationSpeed)
	{
		view.x += lim;
		counter = 0;
	}
	if (abs(view.x) > playerSprite.width)
	{
		view.x = lim;
	}

	counter++;

	//limits
	if (PosX > speedBg && PosX < GetScreenWidth() - speedBg)
	{
		XBg = -PosX + speedBg;
	}
	if (PosY > speedBg && PosY < GetScreenHeight() - speedBg)
	{
		YBg = -PosY + speedBg;
	}

	move = Rectangle{ PosX, PosY, (float)playerSprite.width / 4, (float)playerSprite.height };
	DrawTexture(background, XBg, YBg, WHITE);
	DrawTexturePro(playerSprite, view, move, Vector2{ 10, 10 }, 0, WHITE);
	DrawTexture(chadFr, 800 + XBg, 500 + YBg, WHITE);
}
void Player::UnLoadTextures()
{
	UnloadTexture(d);
	UnloadTexture(l);
	UnloadTexture(r);
	UnloadTexture(u);
	UnloadTexture(background);
}
