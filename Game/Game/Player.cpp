#include "Player.hpp"

void Player::LoadSprites(int fps)
{
	d = LoadTexture("../src/sprites/heroSprite/down.png");
	u = LoadTexture("../src/sprites/heroSprite/up.png");
	l = LoadTexture("../src/sprites/heroSprite/left.png");
	r = LoadTexture("../src/sprites/heroSprite/right.png");

	//idle source
	idleD = LoadTexture("../src/sprites/heroSprite/downIdle.png");
	idleU = LoadTexture("../src/sprites/heroSprite/upIdle.png");
	idleL = LoadTexture("../src/sprites/heroSprite/leftIdle.png");
	idleR = LoadTexture("../src/sprites/heroSprite/rightIdle.png");

	//background
	background = LoadTexture("../src/sprites/backgrounds/frBackground.png");

	playerSprites.push_back(l);
	playerSprites.push_back(r);
	playerSprites.push_back(u);
	playerSprites.push_back(d);
	
	idleSprites.push_back(idleL);
	idleSprites.push_back(idleR);
	idleSprites.push_back(idleU);
	idleSprites.push_back(idleD);

	lim = (float)idleD.width / 2;
	view = { lim, 0, (float)idleD.width / 2, (float)idleD.height };

	this->fps = fps;
}
Player::Player()
{
	playerCords.x = GetScreenWidth() / 2;
	playerCords.y = GetScreenHeight() / 2;
	HorizotnalOrVertical[0] = 0;
	HorizotnalOrVertical[1] = 0;
	speed = 100;
	animationSpeed = 6;
	HeroDir = LEFT;
}

bool findDistance(Player&player, int posX, int posY)
{
	
	if (abs(player.playerCords.x - (posX + player.XBg)) <= player.enemyDistance && abs(player.playerCords.y - (posY + player.YBg)) <= player.enemyDistance)
	{
		return 1;
	}
	else {
		return 0;
	}
}

void Player::CheckDir()
{
	
	if ((IsKeyDown(KEY_UP) or IsKeyDown(KEY_W)) && !(playerCords.y <= 20))
	{
		playerCords.y -= speed * GetFrameTime();

		HeroDir = UP;
		HorizotnalOrVertical[1] = 1;
	}
	else if ((IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S)) && !(playerCords.y >= GetScreenHeight() - playerSprite.height))
	{
		playerCords.y += speed * GetFrameTime();

		HeroDir = DOWN;
		HorizotnalOrVertical[1] = 1;
	}
	else {
		HorizotnalOrVertical[1] = 0;
	}

	if ((IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)) && !(playerCords.x <= 0))
	{
		playerCords.x -= speed * GetFrameTime();
		HeroDir = LEFT;
		HorizotnalOrVertical[0] = 1;
	}
	else if ((IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)) && !(playerCords.x >= GetScreenWidth() - 100))
	{
		playerCords.x += speed * GetFrameTime();
		HeroDir = RIGHT;
		HorizotnalOrVertical[0] = 1;
	}
	else {
		HorizotnalOrVertical[0] = 0;
	}

}

void Player::Movement()
{
	if (HorizotnalOrVertical[0] && HorizotnalOrVertical[1])
		speed = 90;
	else
		speed = 150;

	if (HorizotnalOrVertical[0] || HorizotnalOrVertical[1])
	{
		animationSpeed = 6;
		playerSprite = playerSprites.at(int(HeroDir));
	}
	else if (!HorizotnalOrVertical[0] && !HorizotnalOrVertical[1])
	{
		animationSpeed = 4;
		playerSprite = idleSprites.at(int(HeroDir));
	}

	//flames
	if (counter >= fps / animationSpeed)
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
	if (playerCords.x > limits.x && playerCords.x < GetScreenWidth() - limits.x)
	{
		XBg = -playerCords.x + speedBg;
	}
	if (playerCords.y > limits.y && playerCords.y < GetScreenHeight() - limits.y)
	{
		YBg = -playerCords.y + speedBg;
	}

	move = Rectangle{ playerCords.x, playerCords.y, lim, (float)playerSprite.height };
	DrawTexture(background, XBg, YBg, WHITE);
	DrawTexturePro(playerSprite, view, move, Vector2{ 10, 10 }, 0, WHITE);
}

void Player::UnLoadTextures()
{
	UnloadTexture(d);
	UnloadTexture(l);
	UnloadTexture(r);
	UnloadTexture(u);

	UnloadTexture(idleD);
	UnloadTexture(idleL);
	UnloadTexture(idleR);
	UnloadTexture(idleU);

	UnloadTexture(background);
}