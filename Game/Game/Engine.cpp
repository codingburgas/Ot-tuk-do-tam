#include "Precompile.hpp"
#include "Engine.hpp"

namespace variables {
	Image icon = LoadImage("../src/sprites/icon.png");

	Texture2D confirmationT;
	bool isQuitting;

	Color darkerScreen = { 0,0,0,120 };
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


void isUserQuitting()
{

}