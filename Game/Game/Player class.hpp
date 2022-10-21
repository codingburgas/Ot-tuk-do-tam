#pragma once
#include "Precompile.hpp"

/*class Player {
private:

	// build variables
	float totalTime;
	float switchTime;
	Vector2u imageCount;
	Vector2u currentImage;

	// movement variables
	unsigned int row;
	float speed;
	bool faceLeft;
	bool ramped;

public:
	IntRect uvRect;
	RectangleShape body;
	float jumpY = body.getPosition().y;
	Vector2f velocity;
	bool jumped = false;

	Player(Texture* texture, Vector2u imageCount, float switchTime, float speed);
	~Player();

	// build functions
	void update(int row, float deltaTime, bool faceLeft);

	//movement functions
	void updateMovement(float deltaTime, RenderWindow& window, Sprite& adventureBgImage, Sound& soundWalk, Sound& soundJump, bool& toggle, CollisionBlock blocks[], int blocksSize);
	void draw(RenderWindow& window);
	void jump(float deltaTime, float jumpHeight);
	void moveCameraFirstStage(Sprite& image, float& deltaTime);
	void moveCharacter(int& keyTime, RenderWindow& window, Sprite& adventureBgImage, float& deltaTime);
};*/