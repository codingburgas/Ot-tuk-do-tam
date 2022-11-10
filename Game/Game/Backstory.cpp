#include "Precompile.hpp"
#include "Backstory.hpp"

// define a timer
namespace variables {
	int Lifetime = 4;
	int i = 0;
}

using namespace variables;

void typewriteEffect(string& text, int posX, int posY, int fontSize, Color color)
{
	Lifetime++;//increment for timer

	if (Lifetime == 5 && text[i] != text[text.length()]) {
		i++;
		Lifetime = 0;
	}

	DrawText(text.substr(0, i).c_str(), posX, posY, fontSize, color);
}