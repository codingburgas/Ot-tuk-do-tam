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
		Lifetime = 11;
	}
	if (Lifetime == 10 && !IsKeyPressed(KEY_ENTER)) {
		my += text[i++];
		Lifetime = 0;
	}

	if (my[i] == text.length())
	{
		cout << "";
	}
	else {
		DrawText(my.c_str(), posX, posY, fontSize, color);
	}
}
	