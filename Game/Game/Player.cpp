#include "Player.hpp"
#include "Assassin.hpp"

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

	TableDrink = LoadTexture("../src/sprites/backgrounds/grBackground.png");

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

//player load
Player::Player()
{
	playerCords.x = GetScreenWidth() / 2;
	playerCords.y = GetScreenHeight() / 2;
	HorizotnalOrVertical[0] = 0;
	HorizotnalOrVertical[1] = 0;
	speed.x = 100;
	speed.y = 100;
	MoveBg = 1;
	animationSpeed = 6;
	renameMe = 0;
	HeroDir = LEFT;
}

//find if the player is colliding item
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

//switch sprite when button is clicked
void Player::CheckDir()
{
	
	CheckWalls();
	if ((IsKeyDown(KEY_UP) or IsKeyDown(KEY_W)) && !(playerCords.y <= 20))
	{
		playerCords.y -= speed.y * GetFrameTime();
		HeroDir = UP;

		HorizotnalOrVertical[1] = 1;
		

	}
	else if ((IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S)) && !(playerCords.y >= GetScreenHeight() - playerSprite.height))
	{
		playerCords.y += speed.y * GetFrameTime();

		HeroDir = DOWN;
		HorizotnalOrVertical[1] = 1;
		
	}
	else {
		
		HorizotnalOrVertical[1] = 0;
	}

	if ((IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)) && !(playerCords.x <= 0))
	{
		playerCords.x -= speed.x * GetFrameTime();
		HeroDir = LEFT; 
		HorizotnalOrVertical[0] = 1;
		
	}
	else if ((IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)) && !(playerCords.x >= GetScreenWidth() - 100))
	{
		playerCords.x += speed.x * GetFrameTime();
		HeroDir = RIGHT;
		HorizotnalOrVertical[0] = 1;
		
	}
	else {
		HorizotnalOrVertical[0] = 0;
		
	}
	
}

void Player::Movement()
{
	if (HorizotnalOrVertical[0] || HorizotnalOrVertical[1])
	{
		//cout << renameMe << "Jungle" << endl;
		animationSpeed = 6;
		//cout << speed.x << endl;
		playerSprite = playerSprites.at(int(HeroDir));
	}
	else if (!HorizotnalOrVertical[0] && !HorizotnalOrVertical[1] )
	{
		//cout << renameMe << "Forest" << endl;
		animationSpeed = 4;
		playerSprite = idleSprites.at(int(HeroDir));
	}

	if (HorizotnalOrVertical[0] && HorizotnalOrVertical[1]) {

		speed.x = 90;
		speed.y = 90;
	}
	else
	{
		speed.x = 150;

		speed.y = 150;
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
	if (playerCords.x > limits.x && playerCords.x < GetScreenWidth() - 800)
	{
		//for (size_t i = 0; i < length; i++)
		//{

		
		if (MoveBg/*[i]*/)
		{
			XBg = (-playerCords.x + speedBg);
		}
		else {
			background = TableDrink;
			XBg = 0;
		}
		//}
	}
	if (playerCords.y > 200 && playerCords.y < GetScreenHeight() - limits.y)
	{
		if (MoveBg)
		{
			YBg = (-playerCords.y + speedBg);
		}
		else {
			background = TableDrink;
			YBg = -(1605 - 1080);
		}
		//YBg = (- playerCords.y + speedBg) * MoveBg;
	}

	move = Rectangle{ playerCords.x, playerCords.y, lim, (float)playerSprite.height };	
}
void Player::CheckWalls()
{
	/*for (int i = 0; i < walls.size(); i++) {
		if (CheckCollisionRecs(move, walls.at(i))) {
			if(i == 2)
			{ 
				if ((HorizotnalOrVertical[0] || HorizotnalOrVertical[1]) || (HorizotnalOrVertical[0] && HorizotnalOrVertical[1])){
					speed.x = 0;
					speed.y = 200;
				}
				else {
					speed.x = 200;
					speed.y = 0;
				}
			}
			else {
				if (HorizotnalOrVertical[0] || HorizotnalOrVertical[1]){
					speed.x = 200;
					speed.y = 0;
				}
				else {
					speed.x = 0;
					speed.y = 200;
				}
			}
		}
	}*/
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

	//UnloadTexture(background);
}