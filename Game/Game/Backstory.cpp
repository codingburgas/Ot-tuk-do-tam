#include "Precompile.hpp"
#include "Backstory.hpp"

// define a timer
namespace variablesV {
	int Lifetime = 9;
	string my;
	int i = 0;
}

using namespace variablesV;

//kogato lengtha na my e po golqm ot na text bugva i ne znam kak da go fixna
void typewriteEffect(string& text, int posX, int posY, int fontSize, Color color)
{
	Lifetime++;//increment for timer

	if (IsKeyPressed(KEY_ENTER)) {
		i = text.length();
		my = text;
		Lifetime = 16;
	}

	if (Lifetime == 15 && !IsKeyPressed(KEY_ENTER) && text[i] != text[text.length()]) {
		if(my.length() < text.length())
			i++;

		my += text[i - 1];
		Lifetime = 0;
	}

	DrawText(my.c_str(), posX, posY, fontSize, color);
}
	