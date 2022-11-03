#pragma once
void setIcon();

void setFullScreen(int& windowWidth, int& windowHeight);

bool isClicked();

void isUserQuitting(bool& isQuitting, Vector2& mousePoint, Texture2D& confirmationT, Color& darkerWindow, bool& isTransportMenuOn);