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

bool isClicked()
{
	return IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

void isUserQuitting(bool& isQuitting, bool& enable, Vector2& mousePoint, Texture2D& confirmationT, Color& darkerWindow, bool& isTransportMenuOn, vector<Texture2D> quitButtons)
{
	if (isQuitting)
	{
		DrawRectangle(0, 0, 1920, 1080, darkerWindow);
		DrawTexture(confirmationT, 518, 345, WHITE);
		DrawTexture(quitButtons.at(0), 795, 465, WHITE);
		DrawTexture(quitButtons.at(2), 1020, 465, WHITE);


		if ((mousePoint.y >= 465 && mousePoint.y <= 540))
		{
			if (mousePoint.x >= 795 && mousePoint.x <= 938)
			{
				DrawTexture(quitButtons.at(1), 795, 465, WHITE);

				if(isClicked())
					exit(0);
			}
			else if (mousePoint.x >= 1020 && mousePoint.x <= 1125)
			{
				DrawTexture(quitButtons.at(3), 1020, 465, WHITE);

				if (isClicked())
				{
					isQuitting = false;
					enable = true;
					isTransportMenuOn = false;
				}
			}
		}
	}
}