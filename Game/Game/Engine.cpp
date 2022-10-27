#include "Precompile.hpp"
#include "Engine.hpp"

namespace variables {
	Image icon = LoadImage("../src/sprites/icon.png");
}

using namespace variables;

void setIcon()
{
	SetWindowIcon(icon);
}

void setFullScreen(int& windowWidth, int& windowHeight)
{
	if (!IsWindowFullscreen())
	{
		SetWindowSize(1920, 1080);
	}
	else {

		SetWindowSize(windowWidth, windowHeight);
	}
}

bool isClicked()
{
	return IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

void darkEffect()
{
	//RectangleShape blackEffect(Vector2f(1920, 1080));
	//blackEffect.setFillColor(Color(0, 0, 0, 120));
}