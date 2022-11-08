#include "Precompile.hpp"
#include "Backstory.hpp"

// define a timer
namespace variables {
	int Lifetime = 9;
	string my;
	int i = 0;
}

using namespace variables;

void typewriteEffect(string& text, int posX, int posY, int fontSize, Color color)
{
	Lifetime++;//increment for timer

	if (IsKeyPressed(KEY_ENTER)) {
		i = text.length();
		my = text;
		Lifetime = 16;
	}

	if (Lifetime == 15 && text[i] != text[text.length()]) {
		if (my.length() < text.length())
			i++;

		my += text[i - 1];
		Lifetime = 0;
	}

	DrawText(my.c_str(), posX, posY, fontSize, color);
}