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
		Lifetime = 11;
	}

	if (Lifetime == 10 && !IsKeyPressed(KEY_ENTER)) {
		my += text[i++];
		Lifetime = 0;
	}

	if (my.length() > text.length())
	{

	}
	else {
		DrawText(my.c_str(), posX, posY, fontSize, color);
	}
}
	