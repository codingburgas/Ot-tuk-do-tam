#include "Precompile.hpp"
#include "Engine.hpp"

namespace variablesB {
	Image icon = LoadImage("../src/sprites/icon.png");
}

using namespace variablesB;

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

void isUserQuitting(bool& isQuitting, Vector2& mousePoint, Texture2D& confirmationT, Color& darkerWindow, bool& isTransportMenuOn)
{
	if (isQuitting)
	{
		DrawRectangle(0, 0, 1920, 1080, darkerWindow);
		DrawTexture(confirmationT, 0, 0, WHITE);

		if (isClicked() && (mousePoint.y >= 580 && mousePoint.y <= 640))
		{
			if (mousePoint.x >= 790 && mousePoint.x <= 920)
			{
				exit(0);
			}
			else if (mousePoint.x >= 990 && mousePoint.x <= 1110)
			{
				isQuitting = false;
				isTransportMenuOn = false;
			}
		}
	}
}