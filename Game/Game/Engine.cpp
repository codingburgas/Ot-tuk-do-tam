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
		ToggleFullscreen();
	}
	else {
		ToggleFullscreen();
		SetWindowSize(windowWidth, windowHeight);
	}
}